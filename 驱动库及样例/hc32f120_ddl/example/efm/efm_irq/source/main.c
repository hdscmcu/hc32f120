/**
 *******************************************************************************
 * @file  efm/efm_irq/source/main.c
 * @brief Main program of EFM for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-05-7        chengy          First version
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
 * @addtogroup EFM_Irq
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/


/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define EFM_IRQn                Int024_IRQn

#define EFM_WIN_START_ADDR      0x000002810
#define EFM_WIN_END_ADDR        0x000002910

/* LED0 Port/Pin definition */
#define LED_PORT                GPIO_PORT_2
#define LED0_PORT               GPIO_PORT_2
#define LED0_PIN                GPIO_PIN_5

/* LED1 Port/Pin definition */
#define LED1_PORT               GPIO_PORT_2
#define LED1_PIN                GPIO_PIN_6

/* LED0~1 definition */
#define LED0_ON()               GPIO_ResetPins(LED0_PORT, LED0_PIN)
#define LED0_OFF()              GPIO_SetPins(LED0_PORT, LED0_PIN)

#define LED1_ON()               GPIO_ResetPins(LED1_PORT, LED1_PIN)
#define LED1_OFF()              GPIO_SetPins(LED1_PORT, LED1_PIN)

#define LED_ON()                GPIO_ResetPins(LED_PORT, LED0_PIN | LED1_PIN)
#define LED_OFF()               GPIO_SetPins(LED_PORT, LED0_PIN | LED1_PIN)

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
void EfmPgmEraseErr_IrqHandler(void)
{
    LED1_OFF();
    LED0_ON();

    EFM_Unlock();
    EFM_ClearFlag(EFM_FLAG_CLR_PEPRTERRCLR);
    EFM_Lock();
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
 * @brief  Main function of EFM project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_efm_win_protect_addr_t  stcWinAddr;
    const uint32_t u32TestData = 0x5A5A5A5A;
    uint32_t u32Addr;

    /* Led Init */
    Led_Init();
    LED1_ON();

    /* Unlock EFM. */
    EFM_Unlock();

    /* Enable EFM. */
    EFM_Cmd(Enable);
    /* Wait flash ready. */
    while(Set != EFM_GetFlagStatus(EFM_FLAG_RDY));

    /* Set windows protect address. */
    stcWinAddr.u32StartAddr = EFM_WIN_START_ADDR;
    stcWinAddr.u32EndAddr = EFM_WIN_END_ADDR;
    EFM_SetWinProtectAddr(stcWinAddr);

    /* Enable program & erase err interrupt. */
    EFM_InterruptCmd(EFM_INT_PEERR, Enable);

    /* Erase sector 20. */
    EFM_SectorErase(EFM_SECTOR20_ADRR);

    /* Set EFM_PEERR interrupt. */
    INTC_ShareIrqCmd(INT_EFM_PEERR, Enable);

    /* Enable interrupt. */
    NVIC_ClearPendingIRQ(EFM_IRQn);
    NVIC_SetPriority(EFM_IRQn,DDL_IRQ_PRIORITY_DEFAULT);
    NVIC_EnableIRQ(EFM_IRQn);

     /* program between windows address. */
    u32Addr = EFM_WIN_START_ADDR + 4;
    EFM_ProgramWord(u32Addr,u32TestData);

    /* SW2 */
    while(Pin_Reset != GPIO_ReadInputPortPin(GPIO_PORT_7, GPIO_PIN_0));

    /* program out of windows address. */
    u32Addr = EFM_WIN_START_ADDR - 4;
    EFM_ProgramWord(u32Addr,u32TestData);

    /* Lock EFM. */
    EFM_Lock();

    while(1);
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
