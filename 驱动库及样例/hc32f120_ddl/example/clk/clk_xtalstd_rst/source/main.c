/**
 *******************************************************************************
 * @file  clk/clk_xtalstd_rst/source/main.c
 * @brief Main program of CLK for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-26       chengy          First version
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
 * @addtogroup CLK_Xtalstd_rst
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/


/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* LED0 Port/Pin definition */
#define LED_PORT        GPIO_PORT_2
#define LED0_PORT       GPIO_PORT_2
#define LED0_PIN        GPIO_PIN_5

/* LED1 Port/Pin definition */
#define LED1_PORT       GPIO_PORT_2
#define LED1_PIN        GPIO_PIN_6

/* LED0~1 definition */
#define LED0_ON()       GPIO_ResetPins(LED0_PORT, LED0_PIN)
#define LED0_OFF()      GPIO_SetPins(LED0_PORT, LED0_PIN)

#define LED1_ON()       GPIO_ResetPins(LED1_PORT, LED1_PIN)
#define LED1_OFF()      GPIO_SetPins(LED1_PORT, LED1_PIN)

#define LED_ON()        GPIO_ResetPins(LED_PORT, LED0_PIN | LED1_PIN)
#define LED_OFF()       GPIO_SetPins(LED_PORT, LED0_PIN | LED1_PIN)

#define DELAY_TIME      5000
/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/


/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

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
    stc_clk_xtal_init_t    stcXtalInit;
    stc_clk_xtalstd_init_t stcXtalstdInit;
    stc_rmu_rstcause_t     stcRstCause;

    /* Initialize LED */
    Led_Init();

    RMU_GetResetCause(&stcRstCause);
    if(Set == stcRstCause.XtalErrRst)
    {
        RMU_ClrResetFlag();
        while(1)
        {
            LED0_ON();
            LED1_OFF();
        }
    }


    /* Config XTAL and Enable */
    stcXtalInit.u8XtalState = CLK_XTAL_ON;
    stcXtalInit.u8XtalMode = CLK_XTALMODE_OSC;
    stcXtalInit.u8XtalDrv = CLK_XTALDRV_HIGH;
    stcXtalInit.u8XtalSupDrv = CLK_XTAL_SUPDRV_OFF;
    stcXtalInit.u8XtalStb = CLK_XTALSTB_8;

    CLK_XTALInit(&stcXtalInit);

    /* Enable xtal fault dectect and occur reset. */
    stcXtalstdInit.u8XtalStdState = CLK_XTALSTD_ON;
    stcXtalstdInit.u8XtalStdMode = CLK_XTALSTD_MODE_RST;
    stcXtalstdInit.u8XtalStdInt = CLK_XTALSTD_INT_OFF;
    stcXtalstdInit.u8XtalStdRst = CLK_XTALSTD_RST_ON;

    CLK_XTALStdInit(&stcXtalstdInit);

    while(1)
    {
        LED1_ON();
        LED0_OFF();
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
