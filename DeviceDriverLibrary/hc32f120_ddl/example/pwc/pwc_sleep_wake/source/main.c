/**
 *******************************************************************************
 * @file  pwc/pwc_sleep_wake/source/main.c
 * @brief Main program of PWC for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-05-15      chengy          First version
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
 * @addtogroup PWC_Sleep_wake
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/


/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* LED0 Port/Pin definition */
#define LED_PORT        (GPIO_PORT_2)
#define LED0_PORT       (GPIO_PORT_2)
#define LED0_PIN        (GPIO_PIN_5)

/* LED1 Port/Pin definition */
#define LED1_PORT       (GPIO_PORT_2)
#define LED1_PIN        (GPIO_PIN_6)

/* LED0~1 definition */
#define LED0_ON()       (GPIO_ResetPins(LED0_PORT, LED0_PIN))
#define LED0_OFF()      (GPIO_SetPins(LED0_PORT, LED0_PIN))

#define LED1_ON()       (GPIO_ResetPins(LED1_PORT, LED1_PIN))
#define LED1_OFF()      (GPIO_SetPins(LED1_PORT, LED1_PIN))

#define LED_ON()        (GPIO_ResetPins(LED_PORT, LED0_PIN | LED1_PIN))
#define LED_OFF()       (GPIO_SetPins(LED_PORT, LED0_PIN | LED1_PIN))

#define DELAY_TIME      (5000u)
/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
uint8_t u8IntCnt = 0u;

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  External interrupt Ch.0 ISR
 * @param  None
 *
 * @retval None
 */
void EXINT00_Handler(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH00))
   {
        EXINT_ClrExIntSrc(EXINT_CH00);
        u8IntCnt++;
   }
}

/**
 * @brief  SW2 Init
 * @param  None
 * @retval None
 */
void SW2_Init(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_exint_config_t stcExIntInit;

    /* External interrupt Ch.0 initialize */
    GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(GPIO_PORT_7, GPIO_PIN_0, &stcGpioInit);

    EXINT_StructInit(&stcExIntInit);

    /* EXINT Channel 0 (SW2) configure */
    stcExIntInit.u16ExIntCh     = EXINT_CH00;
    stcExIntInit.u8ExIntFE      = EXINT_FILTER_ON;
    stcExIntInit.u8ExIntFClk    = EXINT_FCLK_HCLK_DIV8;
    stcExIntInit.u8ExIntLvl     = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* NVIC configure */
    /* EXINT0, fixed entry */
    NVIC_ClearPendingIRQ(EXINT00_IRQn);
    NVIC_SetPriority(EXINT00_IRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(EXINT00_IRQn);
}

/**
 * @brief  Led Init
 * @param  None
 * @retval None
 */
void Led_Init(void)
{
    stc_gpio_init_t stcGpioInit;

    /* LED initialize */
    GPIO_StructInit(&stcGpioInit);
    GPIO_Init(LED_PORT, (LED0_PIN | LED1_PIN), &stcGpioInit);

    LED_OFF();
    GPIO_OE(LED_PORT, (LED0_PIN | LED1_PIN), Enable);
}

/**
 * @brief  Main function of CLK project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    Led_Init();
    SW2_Init();

    /* SW1 */
    while(Pin_Reset != GPIO_ReadInputPortPin(GPIO_PORT_6, GPIO_PIN_2))
    {
        ;
    }

    LED0_ON();

    PWC_EnterSleepMode();

    while(1)
    {
        if(u8IntCnt % 2u)
        {
            LED1_ON();
            LED0_OFF();
        }
        else
        {
            LED1_OFF();
            LED0_ON();
            PWC_EnterSleepMode();
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
