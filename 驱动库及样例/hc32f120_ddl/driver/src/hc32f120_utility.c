/**
 *******************************************************************************
 * @file  hc32f120_utility.c
 * @brief This file provides utility functions for DDL.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-20       Yangjp          First version
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
#include "hc32f120_utility.h"

/**
 * @addtogroup HC32F120_DDL_Driver
 * @{
 */

/**
 * @defgroup DDL_UTILITY UTILITY
 * @brief DDL Utility Driver
 * @{
 */

#if (DDL_UTILITY_ENABLE == DDL_ON)

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
#if (DDL_PRINT_ENABLE == DDL_ON)
static en_result_t SetUartBaudrate(M0P_USART_TypeDef *USARTx,
                                        uint32_t u32Baudrate);
#endif

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
/**
 * @defgroup UTILITY_Local_Variables UTILITY Local Variables
 * @{
 */

static uint32_t u32TickStep = 0u;
__IO static uint32_t u32TickCount = 0u;

/**
 * @}
 */

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @defgroup UTILITY_Global_Functions UTILITY Global Functions
 * @{
 */

/**
 * @brief Delay function, delay 1ms approximately
 * @param [in] u32Cnt                   ms
 * @retval None
 */
void DDL_Delay1ms(uint32_t u32Cnt)
{
    volatile uint32_t i = 0;
    uint32_t u32Cyc = 0;

    u32Cyc = SystemCoreClock;
    u32Cyc = u32Cyc / 10000;
    while (u32Cnt-- > 0)
    {
        i = u32Cyc;
        while (i-- > 0)
        {
            ;
        }
    }
}

/**
 * @brief This function Initializes the interrupt frequency of the SysTick.
 * @param [in] u32Freq                  SysTick interrupt frequency.Value range 1 to 1000.
 * @retval An en_result_t enumeration value:
 *           - Ok: SysTick Initializes succeed
 *           - Error: SysTick Initializes failed
 */
__WEAKDEF en_result_t SysTick_Init(uint32_t u32Freq)
{
    en_result_t enRet = Ok;

    u32TickStep = 1000u / u32Freq;
    /* Configure the SysTick interrupt */
    if (SysTick_Config(SystemCoreClock / u32Freq) > 0u)
    {
        enRet = Error;
    }

    return enRet;
}

/**
 * @brief This function provides minimum delay (in milliseconds).
 * @param [in] u32Delay                 Delay specifies the delay time.
 * @retval None
 */
__WEAKDEF void SysTick_Delay(uint32_t u32Delay)
{
    uint32_t tickStart = SysTick_GetTick();
    uint32_t tickEnd = u32Delay;

    /* Add a freq to guarantee minimum wait */
    if (tickEnd < 0xFFFFFFFFu)
    {
        tickEnd += u32TickStep;
    }

    while ((SysTick_GetTick() - tickStart) < tickEnd)
    {
    }
}

/**
 * @brief This function is called to increment a global variable "u32TickCount".
 * @note  This variable is incremented in SysTick ISR.
 * @param None
 * @retval None
 */
__WEAKDEF void SysTick_IncTick(void)
{
    u32TickCount += u32TickStep;
}

/**
 * @brief Provides a tick value in millisecond.
 * @param None
 * @retval Tick value
 */
__WEAKDEF uint32_t SysTick_GetTick(void)
{
    return u32TickCount;
}

/**
 * @brief Suspend SysTick increment.
 * @param None
 * @retval None
 */
__WEAKDEF void SysTick_Suspend(void)
{
    /* Disable SysTick Interrupt */
    SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

/**
 * @brief Resume SysTick increment.
 * @param None
 * @retval None
 */
__WEAKDEF void SysTick_Resume(void)
{
    /* Enable SysTick Interrupt */
    SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}

#ifdef __DEBUG
/**
 * @brief DDL assert error handle function
 * @param [in] file                     Point to the current assert the wrong file.
 * @param [in] line                     Point line assert the wrong file in the current.
 * @retval None
 */
__WEAKDEF void DDL_AssertHandler(uint8_t *file, uint32_t line)
{
    /* Users can re-implement this function to print information */
//    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
    while (1);
}
#endif /* __DEBUG */

#if (DDL_PRINT_ENABLE == DDL_ON)
/**
 * @brief  Re-target fputc function.
 * @param  [in] ch
 * @param  [in] f
 * @retval int32_t
 */
int32_t fputc(int32_t ch, FILE *f)
{
    /* Wait TX data register empty */
    while (!READ_BIT(M0P_USART1->SR, USART_SR_TXE));

    WRITE_REG(M0P_USART1->DR,  (ch & (uint16_t)0x01FF));

    return (ch);
}

/**
 * @brief  Initialize UART for debug printf function
 * @param  None
 * @retval An en_result_t enumeration value:
 *           - Ok: Initialize successfully
 *           - Error: Initialize unsuccessfully
 */
en_result_t DDL_UartInit(void)
{
    /* Configure USART TX pin. */
    WRITE_REG(M0P_PORT->PWPR, 0xA501UL);  /* Unlock */
    MODIFY_REG(M0P_PORT->PCR12, PORT_PCR_FSEL, (0x03UL << PORT_PCR_FSEL_POS));  /* P12: USART1_TX_A */
    WRITE_REG(M0P_PORT->PWPR, 0xA500UL);  /* Lock */

    /* Enable USART1 function clock gate */
    WRITE_REG(M0P_PWC->FPRC, 0xA501UL);  /* Unlock */
    CLEAR_BIT(M0P_CMU->FCG, CMU_FCG_UART1);
    WRITE_REG(M0P_PWC->FPRC, 0xA500UL);  /* Lock */

    /* Disbale TX/RX && clear interrupt flag */
    CLEAR_BIT(M0P_USART1->CR1, (USART_CR1_TE | USART_CR1_RE));

    /***************************************************************************
     * Configure UART
     ***************************************************************************
     * Baud rate: 115200
     * Bit direction: LSB
     * Data bits: 8
     * Stop bits: 1
     * Parity: None
     * Sampling bits: 8
     **************************************************************************/

    /* Set CR1 */
    MODIFY_REG(M0P_USART1->CR1,
               (USART_CR1_SLME | USART_CR1_PS | USART_CR1_PCE |                \
                USART_CR1_M | USART_CR1_OVER8 | USART_CR1_MS  |                \
                USART_CR1_ML | USART_CR1_NFE | USART_CR1_SBS),                 \
               USART_CR1_OVER8);

    /* Set CR2: reset value */
    WRITE_REG(M0P_USART1->CR2, 0x00UL);

    /* Set CR3: reset value */
    WRITE_REG(M0P_USART1->CR3, 0x00UL);

    /* Set baudrate */
    if (Ok != SetUartBaudrate(M0P_USART1, 115200))
    {
        return Error;
    }

    /* Enable TX function */
    SET_BIT(M0P_USART1->CR1, USART_CR1_TE);

    return Ok;
}

/**
 * @brief  Set USART baudrate.
 * @param  [in] USARTx                  Pointer to USART instance register base
 *         This parameter can be one of the following values:
 *           @arg M0P_USART1:           USART unit 1 instance register base
 *           @arg M0P_USART2:           USART unit 2 instance register base
 *           @arg M0P_USART3:           USART unit 3 instance register base
 *           @arg M0P_USART4:           USART unit 4 instance register base
 * @param  [in] u32Baudrate             UART baudrate
 * @retval An en_result_t enumeration value:
 *           - Ok: Set successfully
 *           - ErrorInvalidMode: USART instance mode is not UART
 *           - ErrorInvalidParameter: u32Baudrate is invalid or USARTx is valid USART instance
 */
static en_result_t SetUartBaudrate(M0P_USART_TypeDef *USARTx,
                                        uint32_t u32Baudrate)
{
    uint32_t B;
    uint32_t C;
    uint32_t OVER8;
    uint32_t DIV_Integer;
    uint32_t u32Prescaler;
    uint32_t u32CR1 = READ_REG(USARTx->CR1);

    if ((0UL == u32Baudrate) ||
        ((M0P_USART1 != USARTx) && (M0P_USART2 != USARTx) && 
         (M0P_USART3 != USARTx) && (M0P_USART4 != USARTx)))
    {
        return ErrorInvalidParameter;
    }

    if (u32CR1 & USART_CR1_MS)
    {
        return ErrorInvalidMode;
    }

    B = u32Baudrate;
    OVER8 = (u32CR1 & USART_CR1_OVER8) ? 1u : 0u;

    for (u32Prescaler = 0; u32Prescaler <= USART_PR_PSC; u32Prescaler++)
    {
        C = (SystemCoreClock / (1 << (u32Prescaler * 2)));

        /* UART Mode Calculation Formula */
        /* B = C / (8 * (2 - OVER8) * (DIV_Integer + 1)) */
        DIV_Integer = (C * 10) / (B * 8 * (2 - OVER8));

        /* Calibrate rounding error */
        if (DIV_Integer % 10 < 5)
        {
            DIV_Integer -= 10;
        }

        if (DIV_Integer <= 2550)    /* 2550 = 0xFF * 10 */
        {
            break;
        }
    }

    /* Check validation : DIV_Integer */
    if (DIV_Integer > 2550)         /* 2550 = 0xFF * 10 */
    {
        DDL_ASSERT(NULL);
        return ErrorInvalidParameter;
    }
    else
    {
        DIV_Integer /= 10;
    }

    /* Set clock prescaler */
    WRITE_REG(USARTx->PR, u32Prescaler);

    /* Set USART_BRR register bits:DIV_Integer */
    WRITE_REG(USARTx->BRR, (DIV_Integer << USART_BRR_DIV_INTEGER_POS));

    return Ok;
}

#endif /* DDL_PRINT_ENABLE */

/**
 * @}
 */

#endif /* DDL_UTILITY_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
