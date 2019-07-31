/**
 *******************************************************************************
 * @file  rtc/rtc_calendar/source/main.c
 * @brief Main program of RTC Calendar for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-18       Yangjp          First version
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
 * @addtogroup RTC_Calendar
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* LED_R Port/Pin definition */
#define LED_R_PORT                      GPIO_PORT_2
#define LED_R_PIN                       GPIO_PIN_5

#define LED_R_ON()                      GPIO_ResetPins(LED_R_PORT, LED_R_PIN)
#define LED_R_OFF()                     GPIO_SetPins(LED_R_PORT, LED_R_PIN)
#define LED_R_TOGGLE()                  GPIO_TogglePins(LED_R_PORT, LED_R_PIN)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static uint8_t u8SecIntFlag = 0;

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  RTC period interrupt callback function.
 * @param  None
 * @retval None
 */
void RtcPeriod_IrqCallback(void)
{
    u8SecIntFlag = 1u;
    RTC_ClearIntFlag(RTC_FLAG_PERIOD);
}

/**
 * @brief  RTC calendar configuration.
 * @param  None
 * @retval None
 */
void RTC_CalendarConfig(void)
{
    stc_rtc_date_t stcRtcDateCfg;
    stc_rtc_time_t stcRtcTimeCfg;

    /* Configure structure initialization */
    RTC_TimeStructInit(&stcRtcTimeCfg);

    /* Date configuration */
    stcRtcDateCfg.u8Year = 18;
    stcRtcDateCfg.u8Month = 10;
    stcRtcDateCfg.u8Day = 10;
    stcRtcDateCfg.u8Weekday = RTC_WEEKDAY_WEDNESDAY;

    /* Time configuration */
    stcRtcTimeCfg.u8Hour = 23;
    stcRtcTimeCfg.u8Minute = 59;
    stcRtcTimeCfg.u8Second = 55;

    if (RTC_SetDate(RTC_DATA_FORMAT_DEC, &stcRtcDateCfg) != Ok)
    {
        printf("Set Date failed!\r\n");
    }

    if (RTC_SetTime(RTC_DATA_FORMAT_DEC, &stcRtcTimeCfg) != Ok)
    {
        printf("Set Time failed!\r\n");
    }
}

/**
 * @brief  RTC display weekday.
 * @param  [in] u8Weekday               This parameter can be one of the following values:
 *   @arg  RTC_WEEKDAY_SUNDAY           Sunday
 *   @arg  RTC_WEEKDAY_MONDAY           Monday
 *   @arg  RTC_WEEKDAY_TUESDAY          Tuesday
 *   @arg  RTC_WEEKDAY_WEDNESDAY        Wednesday
 *   @arg  RTC_WEEKDAY_THURSDAY         Thursday
 *   @arg  RTC_WEEKDAY_FRIDAY           Friday
 *   @arg  RTC_WEEKDAY_SATURDAY         Saturday
 * @retval None
 */
void RTC_DisplayWeekday(uint8_t u8Weekday)
{
    switch (u8Weekday)
    {
        case RTC_WEEKDAY_SUNDAY:
            printf("Sunday\r\n");
            break;
        case RTC_WEEKDAY_MONDAY:
            printf("Monday\r\n");
            break;
        case RTC_WEEKDAY_TUESDAY:
            printf("Tuesday\r\n");
            break;
        case RTC_WEEKDAY_WEDNESDAY:
            printf("Wednesday\r\n");
            break;
        case RTC_WEEKDAY_THURSDAY:
            printf("Thursday\r\n");
            break;
        case RTC_WEEKDAY_FRIDAY:
            printf("Friday\r\n");
            break;
        case RTC_WEEKDAY_SATURDAY:
            printf("Saturday\r\n");
            break;
        default:
            break;
    }
}

/**
 * @brief  RTC configuration.
 * @param  None
 * @retval None
 */
void RTC_Config(void)
{
    uint8_t u8Ret;
    stc_rtc_init_t stcRtcInit;
    stc_irq_regi_config_t stcIrqRegister;

    /* Enable peripheral clock */
    CLK_FcgPeriphClockCmd(CLK_FCG_RTC, Enable);

    /* Configure interrupt of RTC period */
    stcIrqRegister.enIntSrc = INT_RTC_PRD;
    stcIrqRegister.enIRQn = Int022_IRQn;
    stcIrqRegister.pfnCallback = RtcPeriod_IrqCallback;
    u8Ret = INTC_IrqRegistration(&stcIrqRegister);
    if (Ok != u8Ret)
    {
        // check parameter
        while (1);
    }

    /* Clear pending */
    NVIC_ClearPendingIRQ(stcIrqRegister.enIRQn);
    /* Set priority */
    NVIC_SetPriority(stcIrqRegister.enIRQn, DDL_IRQ_PRIORITY_DEFAULT);
    /* Enable NVIC */
    NVIC_EnableIRQ(stcIrqRegister.enIRQn);

    /* RTC stopped */
    if (0u == bM0P_RTC->CR1_b.START)
    {
        /* Reset RTC counter */
        if (ErrorTimeout == RTC_DeInit())
        {
            printf("Reset RTC failed!\r\n");
            return;
        }

        /* Configuration RTC structure */
        stcRtcInit.u8ClockSource = RTC_CLOCK_SOURCE_XTAL32;
        stcRtcInit.u8HourFormat = RTC_HOUR_FORMAT_24;
        stcRtcInit.u8PeriodInterrupt = RTC_PERIOD_INT_ONE_SECOND;
        RTC_Init(&stcRtcInit);

        /* Update date and time */
        RTC_CalendarConfig();
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
    DDL_Delay1ms(3000);
}

/**
 * @brief  Main function of RTC Calendar.
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_rtc_date_t stcCurrentDate;
    stc_rtc_time_t stcCurrentTime;

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

    while (1)
    {
        if (1u == u8SecIntFlag)
        {
            u8SecIntFlag = 0;
            LED_R_TOGGLE();
            /* Get current date */
            if (Ok == RTC_GetDate(RTC_DATA_FORMAT_DEC, &stcCurrentDate))
            {
                /* Get current time */
                if (Ok == RTC_GetTime(RTC_DATA_FORMAT_DEC, &stcCurrentTime))
                {
                    /* Print current date and time */
                    printf("20%02d/%02d/%02d %02d:%02d:%02d ", stcCurrentDate.u8Year,
                           stcCurrentDate.u8Month, stcCurrentDate.u8Day,
                           stcCurrentTime.u8Hour, stcCurrentTime.u8Minute,
                           stcCurrentTime.u8Second);
                    RTC_DisplayWeekday(stcCurrentDate.u8Weekday);
                }
                else
                {
                    printf("Get time failed!\r\n");
                }
            }
            else
            {
                printf("Get date failed!\r\n");
            }
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
