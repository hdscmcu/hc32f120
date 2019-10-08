/**
 *******************************************************************************
 * @file  rtc/rtc_calibration_output/source/main.c
 * @brief Main program of RTC Calibration Output for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-23       Yangjp          First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2016, Huada Semiconductor Co., Ltd. All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co., Ltd. ("HDSC").
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 *
 * This software contains source code for use with HDSC
 * components. This software is licensed by HDSC to be adapted only
 * for use in systems utilizing HDSC components. HDSC shall not be
 * responsible for misuse or illegal use of this software for devices not
 * supported herein. HDSC is providing this software "AS IS" and will
 * not be responsible for issues arising from incorrect user implementation
 * of the software.
 *
 * Disclaimer:
 * HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACCOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 *******************************************************************************
 */

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ddl.h"

/**
 * @addtogroup HC32F120_DDL_Examples
 * @{
 */

/**
 * @addtogroup RTC_Calibration_Output
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* LED_R Port/Pin definition */
#define LED_R_PORT                      (GPIO_PORT_2)
#define LED_R_PIN                       (GPIO_PIN_5)

#define LED_R_ON()                      (GPIO_ResetPins(LED_R_PORT, LED_R_PIN))
#define LED_R_OFF()                     (GPIO_SetPins(LED_R_PORT, LED_R_PIN))
#define LED_R_TOGGLE()                  (GPIO_TogglePins(LED_R_PORT, LED_R_PIN))

/* RTC 1Hz output Port/Pin definition */
#define RTC_ONEHZ_OUTPUT_PORT           (GPIO_PORT_3)
#define RTC_ONEHZ_OUTPUT_PIN            (GPIO_PIN_0)

/* SW1 Port/Pin definition */
#define SW1_PORT                        (GPIO_PORT_6)
#define SW1_PIN                         (GPIO_PIN_2)

/* SW2 Port/Pin definition */
#define SW2_PORT                        (GPIO_PORT_7)
#define SW2_PIN                         (GPIO_PIN_0)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static uint8_t u8SecIntFlag = 0u;
static uint8_t u8ExIntFlag = 0u;
static int16_t u16CompenVal = 0x20;

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  SW1 interrupt callback function.
 * @param  None
 * @retval None
 */
void EXINT06_Handler(void)
{
    if (Set == EXINT_GetExIntSrc(EXINT_CH06))
    {
        u8ExIntFlag = 1u;
        if (u16CompenVal < 255)
        {
            u16CompenVal++;
        }
        EXINT_ClrExIntSrc(EXINT_CH06);
    }
}

/**
 * @brief  SW2 interrupt callback function.
 * @param  None
 * @retval None
 */
void EXINT00_Handler(void)
{
    if (Set == EXINT_GetExIntSrc(EXINT_CH00))
    {
        u8ExIntFlag = 1u;
        if (u16CompenVal > -256)
        {
            u16CompenVal--;
        }
        EXINT_ClrExIntSrc(EXINT_CH00);
    }
}

/**
 * @brief  RTC period interrupt callback function.
 * @param  None
 * @retval None
 */
static void RtcPeriod_IrqCallback(void)
{
    u8SecIntFlag = 1u;
    RTC_ClearIntFlag(RTC_FLAG_PERIOD);
}

/**
 * @brief  RTC configuration.
 * @param  None
 * @retval None
 */
static void RTC_Config(void)
{
    uint8_t u8Ret;
    stc_rtc_init_t stcRtcInit;
    stc_irq_regi_config_t stcIrqRegister;

    /* Enable peripheral clock */
    CLK_FcgPeriphClockCmd(CLK_FCG_RTC, Enable);

    /* Configuration RTC output pin */
    GPIO_SetFunc(RTC_ONEHZ_OUTPUT_PORT, RTC_ONEHZ_OUTPUT_PIN, GPIO_FUNC_1_RTC1HZ);

    /* Reset RTC counter */
    if (ErrorTimeout == RTC_DeInit())
    {
        printf("Reset RTC failed!\r\n");
    }
    else
    {
        /* Configuration RTC structure */
        stcRtcInit.u8ClockSource = RTC_CLOCK_SOURCE_XTAL32;
        stcRtcInit.u8HourFormat = RTC_HOUR_FORMAT_24;
        stcRtcInit.u8PeriodInterrupt = RTC_PERIOD_INT_ONE_SECOND;
        RTC_Init(&stcRtcInit);

        /* Configuration RTC 1HZ output */
        RTC_SetClkCompenValue((uint16_t)u16CompenVal);
        RTC_ClkCompenCmd(Enable);
        RTC_OneHzOutputCmd(Enable);

        /* Configure interrupt of RTC period */
        stcIrqRegister.enIntSrc = INT_RTC_PRD;
        stcIrqRegister.enIRQn = Int022_IRQn;
        stcIrqRegister.pfnCallback = &RtcPeriod_IrqCallback;
        u8Ret = INTC_IrqRegistration(&stcIrqRegister);
        if (Ok != u8Ret)
        {
            /* check parameter */
            while (1)
            {
            }
        }

        /* Clear pending */
        NVIC_ClearPendingIRQ(stcIrqRegister.enIRQn);
        /* Set priority */
        NVIC_SetPriority(stcIrqRegister.enIRQn, DDL_IRQ_PRIORITY_DEFAULT);
        /* Enable NVIC */
        NVIC_EnableIRQ(stcIrqRegister.enIRQn);

        /* Enable period interrupt */
        RTC_IntCmd(RTC_INT_PERIOD, Enable);
        /* Startup RTC count */
        RTC_Cmd(Enable);
    }
}

/**
 * @brief  System clock configuration.
 * @param  None
 * @retval None
 */
static void SystemClockConfig(void)
{
    stc_clk_xtal_init_t   stcXTALInit;
    stc_clk_xtal32_init_t stcXTAL32Init;

    /* Configure XTAL */
    stcXTALInit.u8XtalState = CLK_XTAL_ON;
    stcXTALInit.u8XtalMode = CLK_XTALMODE_OSC;
    stcXTALInit.u8XtalDrv = CLK_XTALDRV_HIGH;
    stcXTALInit.u8XtalSupDrv = CLK_XTAL_SUPDRV_OFF;
    stcXTALInit.u8XtalStb = CLK_XTALSTB_8;
    CLK_XTALInit(&stcXTALInit);
    /* Switch system clock from HRC(default) to XTAL */
    CLK_SetSysclkSrc(CLK_SYSCLKSOURCE_XTAL);

    /* Configure XTAL32 */
    stcXTAL32Init.u8Xtal32State = CLK_XTAL32_ON;
    stcXTAL32Init.u8Xtal32Drv = CLK_XTAL32DRV_HIGH;
    stcXTAL32Init.u8Xtal32SupDrv = CLK_XTAL32_SUPDRV_OFF;
    stcXTAL32Init.u8Xtal32NF = CLK_XTAL32NF_FULL;
    CLK_XTAL32Init(&stcXTAL32Init);
    /* Wait for xtal32 running */
    DDL_Delay1ms(3000u);
}

/**
 * @brief  SW1 configuration.
 * @param  None
 * @retval None
 */
static void SW1_Config(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_exint_config_t stcExIntInit;

    /* configure structure initialization */
    GPIO_StructInit(&stcGpioInit);
    EXINT_StructInit(&stcExIntInit);

    /* External interrupt Ch.6 initialize */
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(SW1_PORT, SW1_PIN, &stcGpioInit);

    /* EXINT Channel 6 (SW1) configure */
    stcExIntInit.u16ExIntCh = EXINT_CH06;
    stcExIntInit.u8ExIntFE = EXINT_FILTER_OFF;
    stcExIntInit.u8ExIntLvl = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* Clear pending */
    NVIC_ClearPendingIRQ(EXINT06_IRQn);
    /* Set priority */
    NVIC_SetPriority(EXINT06_IRQn, DDL_IRQ_PRIORITY_DEFAULT);
    /* Enable NVIC */
    NVIC_EnableIRQ(EXINT06_IRQn);
}

/**
 * @brief  SW2 configuration.
 * @param  None
 * @retval None
 */
static void SW2_Config(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_exint_config_t stcExIntInit;

    /* configure structure initialization */
    GPIO_StructInit(&stcGpioInit);
    EXINT_StructInit(&stcExIntInit);

    /* External interrupt Ch.0 initialize */
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(SW2_PORT, SW2_PIN, &stcGpioInit);

    /* EXINT Channel 0 (SW2) configure */
    stcExIntInit.u16ExIntCh = EXINT_CH00;
    stcExIntInit.u8ExIntFE = EXINT_FILTER_OFF;
    stcExIntInit.u8ExIntLvl = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* Clear pending */
    NVIC_ClearPendingIRQ(EXINT00_IRQn);
    /* Set priority */
    NVIC_SetPriority(EXINT00_IRQn, DDL_IRQ_PRIORITY_DEFAULT);
    /* Enable NVIC */
    NVIC_EnableIRQ(EXINT00_IRQn);
}

/**
 * @brief  Main function of RTC calibration output.
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_gpio_init_t stcGpioInit;

    /* Configure clock */
    SystemClockConfig();

    /* Configure structure initialization */
    GPIO_StructInit(&stcGpioInit);

    /* LED Port/Pin initialization */
    stcGpioInit.u16PinMode = PIN_MODE_OUT;
    GPIO_Init(LED_R_PORT, LED_R_PIN, &stcGpioInit);
    LED_R_OFF();

    /* Configure UART */
    DDL_UartInit();
    /* Configure RTC */
    RTC_Config();
    /* SW1 configuration */
    SW1_Config();
    /* SW2 configuration */
    SW2_Config();

    while (1)
    {
        if (1u == u8SecIntFlag)
        {
            u8SecIntFlag = 0u;
            LED_R_TOGGLE();
        }

        if (1u == u8ExIntFlag)
        {
            u8ExIntFlag = 0u;
            RTC_SetClkCompenValue((uint16_t)u16CompenVal & 0x1FFu);
        }
    }
}

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
