/**
 *******************************************************************************
 * @file  exint_nmi/source/main.c
 * @brief Main program EXINT_NMI for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-30       Zhangxl         First version
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
 * @addtogroup EXINT_NMI
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define EXINT0_PORT     (GPIO_PORT_7)
#define EXINT0_PIN      (GPIO_PIN_0)
#define EXINT6_PORT     (GPIO_PORT_6)
#define EXINT6_PIN      (GPIO_PIN_2)
#define EXINT8_PORT     (GPIO_PORT_6)
#define EXINT8_PIN      (GPIO_PIN_0)

#define LED_RGB_PORT    (GPIO_PORT_2)
#define LED_R_PORT      (GPIO_PORT_2)
#define LED_G_PORT      (GPIO_PORT_2)
#define LED_B_PORT      (GPIO_PORT_2)

#define LED_R_PIN       (GPIO_PIN_5)
#define LED_G_PIN       (GPIO_PIN_6)
#define LED_B_PIN       (GPIO_PIN_7)

#define LED_R_ON()      (GPIO_ResetPins(LED_R_PORT, LED_R_PIN))
#define LED_G_ON()      (GPIO_ResetPins(LED_G_PORT, LED_G_PIN))
#define LED_B_ON()      (GPIO_ResetPins(LED_B_PORT, LED_B_PIN))

#define LED_R_OFF()     (GPIO_SetPins(LED_R_PORT, LED_R_PIN))
#define LED_G_OFF()     (GPIO_SetPins(LED_G_PORT, LED_G_PIN))
#define LED_B_OFF()     (GPIO_SetPins(LED_B_PORT, LED_B_PIN))

#define LED_R_TOGGLE()  (GPIO_TogglePins(LED_R_PORT, LED_R_PIN))
#define LED_G_TOGGLE()  (GPIO_TogglePins(LED_G_PORT, LED_G_PIN))
#define LED_B_TOGGLE()  (GPIO_TogglePins(LED_B_PORT, LED_B_PIN))
#define LED_RGB_TOGGLE()                                                        \
        (GPIO_TogglePins(LED_RGB_PORT, LED_R_PIN | LED_G_PIN | LED_B_PIN))

#define LED_RGB_ON()    (GPIO_ResetPins(LED_RGB_PORT, LED_R_PIN | LED_G_PIN | LED_B_PIN))
#define LED_RGB_OFF()   (GPIO_SetPins(LED_RGB_PORT, LED_R_PIN | LED_G_PIN | LED_B_PIN))

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
 * @brief  External interrupt Ch.0 ISR
 * @param  None
 * @retval None
 */
void EXINT00_Handler(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH00))
   {
        EXINT_ClrExIntSrc(EXINT_CH00);
        LED_R_TOGGLE();
   }
}

/**
 * @brief  External interrupt Ch.6 ISR
 * @param  None
 * @retval None
 */
void EXINT06_Handler(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH06))
   {
        EXINT_ClrExIntSrc(EXINT_CH06);
        LED_G_TOGGLE();
   }
}

/**
 * @brief  External interrupt Ch.8 callback function
 * @param  None
 * @retval None
 */
void EXINT08_IrqCallback(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH08))
   {
        EXINT_ClrExIntSrc(EXINT_CH08);
        LED_G_OFF();
        LED_B_TOGGLE();
   }
}

/**
 * @brief  NMI IRQ callback function
 * @param  None
 * @retval None
 */
void NMI_IrqCallback(void)
{
    if (Set == NMI_GetNmiSrc((uint8_t)INTC_NMIFR_NMIF))
    {
        NMI_ClrNmiSrc((uint8_t)INTC_NMIFR_NMIF);
        LED_RGB_TOGGLE();
    }
    if (Set == NMI_GetNmiSrc((uint8_t)INTC_NMIFR_XTALSTPF))
    {
        NMI_ClrNmiSrc((uint8_t)INTC_NMIFR_XTALSTPF);
    }
    if (Set == NMI_GetNmiSrc((uint8_t)INTC_NMIFR_SWDTF))
    {
        NMI_ClrNmiSrc((uint8_t)INTC_NMIFR_SWDTF);
    }
    if (Set == NMI_GetNmiSrc((uint8_t)INTC_NMIFR_PVDF))
    {
        NMI_ClrNmiSrc((uint8_t)INTC_NMIFR_PVDF);
    }
}

/**
 * @brief  Main function of EXINT_NMI project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    uint8_t u8Ret;
    stc_irq_regi_config_t stcIrqRegister;
    stc_gpio_init_t stcGpioInit;
    stc_nmi_config_t stcNmiInit;
    stc_exint_config_t stcExIntInit;

    /* RGB LED initialize */
    GPIO_StructInit(&stcGpioInit);
    GPIO_Init(LED_RGB_PORT, (LED_R_PIN | LED_G_PIN | LED_B_PIN), &stcGpioInit);
    LED_RGB_OFF();
    GPIO_OE(LED_RGB_PORT, (LED_R_PIN | LED_G_PIN | LED_B_PIN), Enable);

    /* External interrupt Ch.0 & Ch.6 & Ch.8 initialize */
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(EXINT0_PORT, EXINT0_PIN, &stcGpioInit);
    GPIO_Init(EXINT6_PORT, EXINT6_PIN, &stcGpioInit);
    GPIO_Init(EXINT8_PORT, EXINT8_PIN, &stcGpioInit);

    EXINT_StructInit(&stcExIntInit);

    /* EXINT Channel 0 (SW2) configure */
    stcExIntInit.u16ExIntCh     = (uint16_t)EXINT_CH00;
    stcExIntInit.u8ExIntFE      = EXINT_FILTER_ON;
    stcExIntInit.u8ExIntFClk    = EXINT_FCLK_HCLK_DIV8;
    stcExIntInit.u8ExIntLvl     = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* EXINT Channel 6 (SW1) and Channel 8 (P60) configure */
    stcExIntInit.u16ExIntCh     = (uint16_t)EXINT_CH06 | (uint16_t)EXINT_CH08;
    stcExIntInit.u8ExIntFE      = EXINT_FILTER_ON;
    stcExIntInit.u8ExIntFClk    = EXINT_FCLK_HCLK_DIV32;
    stcExIntInit.u8ExIntLvl     = EXINT_TRIGGER_RISING;
    EXINT_Init(&stcExIntInit);

    /* Set IRQ handler 9 as the external interrupt channel 8 entry */
    stcIrqRegister.enIRQn       = Int009_IRQn;
    stcIrqRegister.enIntSrc     = INT_PORT_EIRQ8;
    stcIrqRegister.pfnCallback  = &EXINT08_IrqCallback;
    u8Ret = INTC_IrqRegistration(&stcIrqRegister);
    if (Ok != u8Ret)
    {
        // check parameter
        while(1)
        {
            ;
        }
    }
    /* NVIC configure */
    /* EXINT0, fixed entry */
    NVIC_ClearPendingIRQ(EXINT00_IRQn);
    NVIC_SetPriority(EXINT00_IRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(EXINT00_IRQn);

    /* EXINT6, fixed entry */
    NVIC_ClearPendingIRQ(EXINT06_IRQn);
    NVIC_SetPriority(EXINT06_IRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(EXINT06_IRQn);

    /* IRQ009 for EXINT8 */
    NVIC_ClearPendingIRQ(Int009_IRQn);
    NVIC_SetPriority(Int009_IRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(Int009_IRQn);

    /* NMI Pin interrupt configure */
    NMI_StructInit(&stcNmiInit);
    stcNmiInit.u8NmiFE          = NMI_FILTER_ON;
    stcNmiInit.u8NmiFClk        = NMI_FCLK_HCLK_DIV64;
    stcNmiInit.u8NmiTigger      = NMI_TRIGGER_RISING;
    stcNmiInit.u8NmiSrc         = NMI_SRC_NMI_PIN;
    stcNmiInit.pfnNmiCallback   = &NMI_IrqCallback;
    NMI_Init(&stcNmiInit);

    while (1)
    {
        ;// wait SW1/2 pressed
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
