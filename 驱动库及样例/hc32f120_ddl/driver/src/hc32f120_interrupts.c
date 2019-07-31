/**
 *******************************************************************************
 * @file  hc32f120_interrupts.c
 * @brief This file provides firmware functions to manage the Interrupt Controller
 *        (INTC).
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-22       Zhangxl         First version
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
#include "hc32f120_interrupts.h"
#include "hc32f120_utility.h"

/**
 * @addtogroup HC32F120_DDL_Driver
 * @{
 */

/**
 * @defgroup DDL_INTERRUPTS INTERRUPTS
 * @brief INTC Driver Library
 * @{
 */

#if (DDL_INTERRUPTS_ENABLE == DDL_ON) || (DDL_EXINT_NMI_ENABLE == DDL_ON) ||    \
    (DDL_EKEY_ENABLE == DDL_ON)

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup INTC_Local_Macros INTC Local Macros
 * @{
 */
/**
 * @brief   Maximum IRQ handler number
 */
#define IRQ_NUM_MAX         16u

/**
 * @defgroup INTC_Check_Parameters_Validity INTC Check Parameters Validity
 * @{
 */
/*  Parameter validity check for wakeup source from stop mode. */
#define IS_INTC_WKUP_SRC(SOURCE)                                                \
(   ((SOURCE) & (INTC_WUPENR_EIRQWUEN       | INTC_WUPENR_SWDTWUEN      |       \
                 INTC_WUPENR_EKEYWUEN       | INTC_WUPENR_TMR0CMPWUEN   |       \
                 INTC_WUPENR_PVDWUEN        | INTC_WUPENR_RTCALMWUEN    |       \
                 INTC_WUPENR_RTCPRDWUEN))   != (uint32_t)0x00000000)

/*  Parameter validity check for event number. */
#define IS_INTC_EVENT(EVENT)                                                    \
(   ((EVENT) & (INTC_EVTER_EVTEN0   | INTC_EVTER_EVTEN1                 |       \
                INTC_EVTER_EVTEN2   | INTC_EVTER_EVTEN3                 |       \
                INTC_EVTER_EVTEN4   | INTC_EVTER_EVTEN5                 |       \
                INTC_EVTER_EVTEN6   | INTC_EVTER_EVTEN7)) != (uint8_t)0x00)

/*  Parameter validity check for NMI pin filter function. */
#define IS_NMI_FE(FE)                                                           \
(   ((FE) == NMI_FILTER_OFF)                    ||                              \
    ((FE) == NMI_FILTER_ON))

/*  Parameter validity check for MNI pin filter clock division. */
#define IS_NMI_FCLK(FCLK)                                                       \
(   ((FCLK) == NMI_FCLK_HCLK_DIV1)              ||                              \
    ((FCLK) == NMI_FCLK_HCLK_DIV8)              ||                              \
    ((FCLK) == NMI_FCLK_HCLK_DIV32)             ||                              \
    ((FCLK) == NMI_FCLK_HCLK_DIV64))

/*  Parameter validity check for NMI pin trigger edge. */
#define IS_NMI_TRIGGER(TRIGGER)                                                 \
(   ((TRIGGER) == NMI_TRIGGER_FALLING)          ||                              \
    ((TRIGGER) == NMI_TRIGGER_RISING))

/*  Parameter validity check for NMI trigger souce. */
#define IS_NMI_SRC(SRC) (((SRC) & NMI_SRC_MASK) != (uint8_t)0x00)

/*  Parameter validity check for get NMI trigger source. */
#define IS_GET_NMI_SRC(SRC)                                                     \
(   ((SRC) == NMI_SRC_NMI_PIN)                  ||                              \
    ((SRC) == NMI_SRC_XTAL_STP)                 ||                              \
    ((SRC) == NMI_SRC_SWDT)                     ||                              \
    ((SRC) == NMI_SRC_LVD))

/*  Parameter validity check for EXINT filter function. */
#define IS_EXINT_FE(FE)                                                         \
(   ((FE) == EXINT_FILTER_OFF)                  ||                              \
    ((FE) == EXINT_FILTER_ON))

/*  Parameter validity check for EXINT filter clock division. */
#define IS_EXINT_FCLK(FCLK)                                                     \
(   ((FCLK) == EXINT_FCLK_HCLK_DIV1)            ||                              \
    ((FCLK) == EXINT_FCLK_HCLK_DIV8)            ||                              \
    ((FCLK) == EXINT_FCLK_HCLK_DIV32)           ||                              \
    ((FCLK) == EXINT_FCLK_HCLK_DIV64))

/*  Parameter validity check for EXINT trigger edge. */
#define IS_EXINT_TRIGGER(TRIGGER)                                               \
(   ((TRIGGER) == EXINT_TRIGGER_LOW)            ||                              \
    ((TRIGGER) == EXINT_TRIGGER_RISING)         ||                              \
    ((TRIGGER) == EXINT_TRIGGER_FALLING)        ||                              \
    ((TRIGGER) == EXINT_TRIGGER_BOTH))

/*  Parameter validity check for EXINT channel. */
#define IS_EXINT_CH(CH)     (((CH) & EXINT_CH_MASK) != (uint16_t)0x0000)

/*  Parameter validity check for get EXINT channel. */
#define IS_GET_EXINT_CH(CH)                                                     \
(   ((CH) == EXINT_CH00)                        ||                              \
    ((CH) == EXINT_CH01)                        ||                              \
    ((CH) == EXINT_CH02)                        ||                              \
    ((CH) == EXINT_CH03)                        ||                              \
    ((CH) == EXINT_CH04)                        ||                              \
    ((CH) == EXINT_CH05)                        ||                              \
    ((CH) == EXINT_CH06)                        ||                              \
    ((CH) == EXINT_CH07)                        ||                              \
    ((CH) == EXINT_CH08)                        ||                              \
    ((CH) == EXINT_CH09))

/*  Parameter validity check for EKEY. */
#define IS_INTC_EKEY(EKEY)  (((EKEY) & INTC_EKEY_MASK) != (uint8_t)0x00)

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
/**
 * @defgroup INTC_Local_Variable INTC Local Variable
 * @{
 */
static func_ptr_t pfnIrqHandler[IRQ_NUM_MAX] = {NULL};
static func_ptr_t pfnNmiCallback;
/**
 * @}
 */

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @defgroup INTC_Global_Functions INTC Global Functions
 * @{
 */
/**
 * @brief  IRQ registration function
 * @param  [in] pstcIrqRegiConfig: pointer of IRQ registration structure
 *   @arg  enIntSrc: can be any value except INT_PORT_EIRQ0~7 @ref en_int_src_t
 *   @arg  enIRQn: can be any value from Int008~Int023 @ref IRQn_Type
 *   @arg  pfnCallback: Callback function
 * @retval Ok: IRQ register successfully
 *         ErrorInvalidParameter: IRQ No. and Peripheral Int source are not match;
 *                                Input peripheral Int source cannot be configure;
 *                                NULL pointer.
 */
en_result_t INTC_IrqRegistration(const stc_irq_regi_config_t *pstcIrqRegiConfig)
{
    __IO stc_intc_iselar_field_t *stcIntSel;

    /* Check if pointer is NULL */
    if (NULL == pstcIrqRegiConfig)
    {
        return ErrorInvalidParameter;
    }

    INTC_Unlock();

    /* Checking validity for Interrupt source of Group 0~7 and IRQ No. */
    if (((pstcIrqRegiConfig->enIntSrc / 0x10)*2 + 8 != pstcIrqRegiConfig->enIRQn) &&    \
        ((pstcIrqRegiConfig->enIntSrc / 0x10)*2 + 9 != pstcIrqRegiConfig->enIRQn))
    {
        return ErrorInvalidParameter;
    }

    /* EIRQ0~7 are fixed allocation of IRQ handler 0~7 */
    if ((0 == pstcIrqRegiConfig->enIntSrc % 0x10) || (pstcIrqRegiConfig->enIRQn < 8))
    {
        return ErrorInvalidParameter;
    }

    stcIntSel = (stc_intc_iselar_field_t *)((uint32_t)(&M0P_INTC->ISELAR8) +    \
                                         (4 * (pstcIrqRegiConfig->enIRQn - 8)));
    stcIntSel->ISEL = (pstcIrqRegiConfig->enIntSrc) % 0x10;

    /* Callback function */
    pfnIrqHandler[pstcIrqRegiConfig->enIRQn-8] = pstcIrqRegiConfig->pfnCallback;

    INTC_Lock();
    return Ok;
}

/**
 * @brief  Share IRQ configure
 * @param  [in] enIntSrc: Peripheral interrupt source @ref en_int_src_t
 * @param  [in] enNewState:
 *   @arg  Enable: Enable corresponding peripheral interrupt in share IRQ handler
 *   @arg  Disable: Disable corresponding peripheral interrupt in share IRQ handler
 * @retval Ok: Share IRQ configure successfully
 *         ErrorInvalidParameter: EXINT00~07 cannot be configured into share IRQ handler
 */
en_result_t INTC_ShareIrqCmd(en_int_src_t enIntSrc, en_functional_state_t enNewState)
{
    __IO uint32_t *ISELRx;

    /* EXINT0~7 cannot be configured into share IRQ */
    if (0 == enIntSrc%0x10)
    {
        return ErrorInvalidParameter;
    }
    else
    {
        INTC_Unlock();
        ISELRx = (uint32_t *)(((uint32_t)&M0P_INTC->ISELBR24) + (4 * (enIntSrc / 16)));
        if (Enable == enNewState)
        {
            SET_BIT(*ISELRx, (1u << (enIntSrc % 16)));
        }
        else
        {
            CLEAR_BIT(*ISELRx, (1u << (enIntSrc % 16)));
        }
        INTC_Lock();
        return Ok;
    }
}

/**
 * @brief  Stop mode wake-up source configure
 * @param  [in] u32WakeupSrc: Wake-up source
 *   @arg  INTC_WUPENR_EIRQWUEN
 *   @arg  INTC_WUPENR_EIRQWUEN_0
 *   @arg  INTC_WUPENR_EIRQWUEN_1
 *   @arg  INTC_WUPENR_EIRQWUEN_2
 *   @arg  INTC_WUPENR_EIRQWUEN_3
 *   @arg  INTC_WUPENR_EIRQWUEN_4
 *   @arg  INTC_WUPENR_EIRQWUEN_5
 *   @arg  INTC_WUPENR_EIRQWUEN_6
 *   @arg  INTC_WUPENR_EIRQWUEN_7
 *   @arg  INTC_WUPENR_EIRQWUEN_8
 *   @arg  INTC_WUPENR_EIRQWUEN_9
 *   @arg  INTC_WUPENR_SWDTWUEN
 *   @arg  INTC_WUPENR_EKEYWUEN
 *   @arg  INTC_WUPENR_TMR0CMPWUEN
 *   @arg  INTC_WUPENR_PVDWUEN
 *   @arg  INTC_WUPENR_RTCALMWUEN
 *   @arg  INTC_WUPENR_RTCPRDWUEN
 * @param  [in] enNewState
 *   @arg  Enable: Enable corresponding wake up source
 *   @arg  Disable: Disable corresponding wake up source
 * @retval None
 */
void INTC_WakeupSrcCmd(uint32_t u32WakeupSrc, en_functional_state_t enNewState)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_INTC_WKUP_SRC(u32WakeupSrc));
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewState));

    INTC_Unlock();
    if (Enable == enNewState)
    {
        SET_BIT(M0P_INTC->WUPENR, u32WakeupSrc);
    }
    else
    {
        CLEAR_BIT(M0P_INTC->WUPENR, u32WakeupSrc);
    }
    INTC_Lock();
}

/**
 * @brief  Event or Interrupt output configure
 * @param  [in] u8Event: Event index
 *   @arg  INTC_EVTER_EVTEN0
 *   @arg  INTC_EVTER_EVTEN1
 *   @arg  INTC_EVTER_EVTEN2
 *   @arg  INTC_EVTER_EVTEN3
 *   @arg  INTC_EVTER_EVTEN4
 *   @arg  INTC_EVTER_EVTEN5
 *   @arg  INTC_EVTER_EVTEN6
 *   @arg  INTC_EVTER_EVTEN7
 * @param  [in] enNewState
 *   @arg  Enable: Enable corresponding event to NVIC
 *   @arg  Disable: Disable corresponding event but interrupt to NVIC
 * @retval None
 */
void INTC_EventCmd(uint8_t u8Event, en_functional_state_t enNewState)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_INTC_EVENT(u8Event));

    INTC_Unlock();
    if (Enable == enNewState)
    {
        SET_BIT(M0P_INTC->EVTER, u8Event);
    }
    else
    {
        CLEAR_BIT(M0P_INTC->EVTER, u8Event);
    }
    INTC_Lock();
}

/**
 * @brief  Initialize NMI. Fill each pstcNmiConfig with default value
 * @param  [in] pstcNmiConfig: Pointer to a stc_nmi_config_t structure that
 *                             contains configuration information.
 * @retval Ok: NMI structure initialize successful
 *         ErrorInvalidParameter: NULL pointer
 */
en_result_t NMI_StructInit(stc_nmi_config_t *pstcNmiConfig)
{
    /* Check if pointer is NULL */
    if (NULL == pstcNmiConfig)
    {
        return ErrorInvalidParameter;
    }
    /* Configure to default value */
    pstcNmiConfig->u8NmiFE          = NMI_FILTER_OFF;
    pstcNmiConfig->u8NmiFClk        = NMI_FCLK_HCLK_DIV1;
    pstcNmiConfig->u8NmiTigger      = NMI_TRIGGER_FALLING;
    pstcNmiConfig->u8NmiSrc         = NMI_SRC_NMI_PIN;
    pstcNmiConfig->pfnNmiCallback   = NULL;

    return Ok;
}

/**
 * @brief  Initialize NMI.
 * @param  [in] pstcNmiConfig: Pointer to a pstcNmiConfig structure that
 *                             contains configuration information.
 * @retval Ok: NMI initialize successful
 *         ErrorInvalidParameter: NULL pointer
 */
en_result_t NMI_Init(const stc_nmi_config_t *pstcNmiConfig)
{
    /* Check if pointer is NULL */
    if ((NULL == pstcNmiConfig->pfnNmiCallback) || (NULL == pstcNmiConfig))
    {
        return ErrorInvalidParameter;
    }

    /* Parameter validity checking */
    DDL_ASSERT(IS_NMI_FCLK(pstcNmiConfig->u8NmiFClk));
    DDL_ASSERT(IS_NMI_FE(pstcNmiConfig->u8NmiFE));
    DDL_ASSERT(IS_NMI_TRIGGER(pstcNmiConfig->u8NmiTigger));
    DDL_ASSERT(IS_NMI_SRC(pstcNmiConfig->u8NmiSrc));

    INTC_Unlock();

    /* NMI pin interrupt configure */
    WRITE_REG(M0P_INTC->NMICR,                                                  \
              (pstcNmiConfig->u8NmiFE | pstcNmiConfig->u8NmiFClk |              \
               pstcNmiConfig->u8NmiTigger));

    /* Clear all NMI trigger source before set */
    WRITE_REG(M0P_INTC->NMICLR, INTC_NMICLR_MASK);

    /* NMI trigger source configure */
    WRITE_REG(M0P_INTC->NMIER, pstcNmiConfig->u8NmiSrc);

    /* NMI callback function configure */
    pfnNmiCallback = pstcNmiConfig->pfnNmiCallback;

    INTC_Lock();
    return Ok;
}

/**
 * @brief  Get NMI trigger source
 * @param  [in] u8NmiSrc: NMI trigger source, @ref NMI_TriggerSrc_Sel for details
 *   @arg  NMI_SRC_NMI_PIN
 *   @arg  NMI_SRC_XTAL_STP
 *   @arg  NMI_SRC_SWDT
 *   @arg  NMI_SRC_LVD
 * @retval Set: NMI is triggered by corresponding source
 *         Reset: NMI is not triggered by corresponding source
 */
en_flag_status_t NMI_GetNmiSrc(uint8_t u8NmiSrc)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_GET_NMI_SRC(u8NmiSrc));

    return (en_flag_status_t)!!(READ_REG(M0P_INTC->NMIFR) & u8NmiSrc);
}

/**
 * @brief  Clear specified NMI trigger source
 * @param  [in] u8NmiSrc: NMI trigger source, @ref NMI_TriggerSrc_Sel for details
 *   @arg  NMI_SRC_NMI_PIN
 *   @arg  NMI_SRC_XTAL_STP
 *   @arg  NMI_SRC_SWDT
 *   @arg  NMI_SRC_LVD
 * @retval None
 */
void NMI_ClrNmiSrc(uint8_t u8NmiSrc)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_NMI_SRC(u8NmiSrc));

    INTC_Unlock();
    MODIFY_REG(M0P_INTC->NMICLR, INTC_NMICLR_MASK, u8NmiSrc);
    INTC_Lock();
}

/**
 * @brief  NMI IRQ handler
 * @param  None
 * @retval None
 */
void NMI_IrqHandler(void)
{
    if (NULL != pfnNmiCallback)
    {
        pfnNmiCallback();
    }
}

/**
 * @brief  Initialize External interrupt.
 * @param  [in] pstcExIntConfig: Pointer to a pstcExIntConfig structure that
 *                             contains configuration information.
 * @retval Ok:  EXINT initialize successful
 *         ErrorInvalidParameter: NULL pointer
 */
en_result_t EXINT_Init(const stc_exint_config_t *pstcExIntConfig)
{
    uint8_t u8ExIntPos = 0;

    /* Check if pointer is NULL */
    if (NULL == pstcExIntConfig)
    {
        return ErrorInvalidParameter;
    }

    /* Parameter validity checking */
    DDL_ASSERT(IS_EXINT_FE(pstcExIntConfig->u8ExIntFE));
    DDL_ASSERT(IS_EXINT_FCLK(pstcExIntConfig->u8ExIntFClk));
    DDL_ASSERT(IS_EXINT_TRIGGER(pstcExIntConfig->u8ExIntLvl));
    DDL_ASSERT(IS_EXINT_CH(pstcExIntConfig->u16ExIntCh));

    INTC_Unlock();
    for (u8ExIntPos = 0; u8ExIntPos < 10; u8ExIntPos++)
    {
        if (pstcExIntConfig->u16ExIntCh & (1<<u8ExIntPos))
        {
            WRITE_REG(*(uint32_t *)(&M0P_INTC->EIRQCR0 + u8ExIntPos),           \
                      (pstcExIntConfig->u8ExIntFE   |                           \
                       pstcExIntConfig->u8ExIntFClk |                           \
                       pstcExIntConfig->u8ExIntLvl));
        }
    }
    INTC_Lock();

    return Ok;
}

/**
 * @brief  Initialize ExInt. Fill each pstcExintConfig with default value
 * @param  [in] pstcExintConfig: Pointer to a pstcExintConfig structure
 *                              that contains configuration information.
 * @retval Ok: EXINT structure initialize successful
 *         ErrorInvalidParameter: NULL pointer
 */
en_result_t EXINT_StructInit(stc_exint_config_t *pstcExintConfig)
{
    /* Check if pointer is NULL */
    if (NULL == pstcExintConfig)
    {
        return ErrorInvalidParameter;
    }
    /* Configure to default value */
    pstcExintConfig->u16ExIntCh     = NULL;
    pstcExintConfig->u8ExIntFE      = EXINT_FILTER_OFF;
    pstcExintConfig->u8ExIntFClk    = EXINT_FCLK_HCLK_DIV1;
    pstcExintConfig->u8ExIntLvl     = EXINT_TRIGGER_FALLING;

    return Ok;
}

/**
 * @brief  Clear specified External interrupt trigger source
 * @param  [in] u16ExIntCh: External interrupt channel, @ref EXINT_Channel_Sel for details
 *   @arg  EXINT_CH00
 *   @arg  EXINT_CH01
 *   @arg  EXINT_CH02
 *   @arg  EXINT_CH03
 *   @arg  EXINT_CH04
 *   @arg  EXINT_CH05
 *   @arg  EXINT_CH06
 *   @arg  EXINT_CH07
 *   @arg  EXINT_CH08
 *   @arg  EXINT_CH09
 * @retval None
 */
void EXINT_ClrSrc(uint16_t u16ExIntCh)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_EXINT_CH(u16ExIntCh));

    INTC_Unlock();
    SET_BIT(M0P_INTC->EIRQCLR, u16ExIntCh);
    INTC_Lock();
}

/**
 * @brief  Get specified External interrupt trigger source
 * @param  [in] u16ExIntCh: External interrupt channel, @ref EXINT_Channel_Sel for details
 *   @arg  EXINT_CH00
 *   @arg  EXINT_CH01
 *   @arg  EXINT_CH02
 *   @arg  EXINT_CH03
 *   @arg  EXINT_CH04
 *   @arg  EXINT_CH05
 *   @arg  EXINT_CH06
 *   @arg  EXINT_CH07
 *   @arg  EXINT_CH08
 *   @arg  EXINT_CH09
 * @retval Set: Specified channel of external interrupt is triggered
 *         Reset: Specified channel of external interrupt is not triggered
 */
en_flag_status_t EXINT_GetExIntSrc(uint16_t u16ExIntCh)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_EXINT_CH(u16ExIntCh));

    return (en_flag_status_t)!!(READ_REG(M0P_INTC->EIRQFR) & u16ExIntCh);
}

/**
 * @brief  Configure the specified EKEY
 * @param  [in] u8EKey: EKEY channel, @ref INTC_EKEY_Channel for details
 *   @arg  INTC_EKEY0
 *   @arg  INTC_EKEY1
 *   @arg  INTC_EKEY2
 *   @arg  INTC_EKEY3
 *   @arg  INTC_EKEY4
 *   @arg  INTC_EKEY5
 * @param  [in] enNewState
 *   @arg  Enable: Enable corresponding EKEY
 *   @arg  Disable: Disable corresponding EKEY
 * @retval None
 */
void INTC_EKeyCmd(uint8_t u8EKey, en_functional_state_t enNewState)
{
    /* Parameter validity checking */
    DDL_ASSERT(IS_INTC_EKEY(u8EKey));
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewState));

    INTC_Unlock();
    if (Enable == enNewState)
    {
        SET_BIT(M0P_INTC->EKEYCR, u8EKey);
    }
    else
    {
        CLEAR_BIT(M0P_INTC->EKEYCR, u8EKey);
    }
    INTC_Lock();
}

/**
 * @brief  NMI IRQ handler
 * @param  None
 * @retval None
 */
void NMI_Handler(void)
{
    NMI_IrqHandler();
}

/**
 * @brief  Hard Fault IRQ handler
 * @param  None
 * @retval None
 */
void HardFault_Handler(void)
{
    HardFault_IrqHandler();
}

/**
 * @brief  SVCall IRQ handler
 * @param  None
 * @retval None
 */
void SVC_Handler(void)
{
    SVC_IrqHandler();
}

/**
 * @brief  PendSV IRQ handler
 * @param  None
 * @retval None
 */
void PendSV_Handler(void)
{
    PendSV_IrqHandler();
}

/**
 * @brief  SysTick IRQ handler
 * @param  None
 * @retval None
 */
void SysTick_Handler(void)
{
    SysTick_IrqHandler();
}

/**
 * @brief  Interrupt No.008 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ008_Handler(void)
{
    pfnIrqHandler[Int008_IRQn-8]();
}

/**
 * @brief  Interrupt No.009 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ009_Handler(void)
{
    pfnIrqHandler[Int009_IRQn-8]();
}

/**
 * @brief  Interrupt No.010 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ010_Handler(void)
{
    pfnIrqHandler[Int010_IRQn-8]();
}


/**
 * @brief  Interrupt No.011 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ011_Handler(void)
{
    pfnIrqHandler[Int011_IRQn-8]();
}

/**
 * @brief  Interrupt No.012 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ012_Handler(void)
{
    pfnIrqHandler[Int012_IRQn-8]();
}

/**
 * @brief  Interrupt No.013 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ013_Handler(void)
{
    pfnIrqHandler[Int013_IRQn-8]();
}

/**
 * @brief  Interrupt No.014 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ014_Handler(void)
{
    pfnIrqHandler[Int014_IRQn-8]();
}

/**
 * @brief  Interrupt No.015 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ015_Handler(void)
{
    pfnIrqHandler[Int015_IRQn-8]();
}

/**
 * @brief  Interrupt No.016 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ016_Handler(void)
{
    pfnIrqHandler[Int016_IRQn-8]();
}

/**
 * @brief  Interrupt No.017 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ017_Handler(void)
{
    pfnIrqHandler[Int017_IRQn-8]();
}

/**
 * @brief  Interrupt No.018 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ018_Handler(void)
{
    pfnIrqHandler[Int018_IRQn-8]();
}

/**
 * @brief  Interrupt No.019 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ019_Handler(void)
{
    pfnIrqHandler[Int019_IRQn-8]();
}

/**
 * @brief  Interrupt No.020 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ020_Handler(void)
{
    pfnIrqHandler[Int020_IRQn-8]();
}

/**
 * @brief  Interrupt No.021 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ021_Handler(void)
{
    pfnIrqHandler[Int021_IRQn-8]();
}

/**
 * @brief  Interrupt No.022 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ022_Handler(void)
{
    pfnIrqHandler[Int022_IRQn-8]();
}

/**
 * @brief  Interrupt No.023 IRQ handler
 * @param  None
 * @retval None
 */
void IRQ023_Handler(void)
{
    pfnIrqHandler[Int023_IRQn-8]();
}

/**
 * @brief  Interrupt No.024 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ024_Handler(void)
{
    /* External interrupt 08 */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL1) && (Set == bM0P_INTC->EIRQFR_b.EIRQF8))
    {
        Extint08_IrqHandler();
    }
    /* EFM program/erase error */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL4) &&                                 \
        (Set == !!(M0P_EFM->FSR & (EFM_FSR_PEWERR | EFM_FSR_PEPRTERR | EFM_FSR_PGMISMTCH))))
    {
        EfmPgmEraseErr_IrqHandler();
    }
    /* EFM read collision */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL5) && (Set == bM0P_EFM->FSR_b.RDCOLERR))
    {
        EfmColErr_IrqHandler();
    }
    /* XTAL stop */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL6) && (Set == bM0P_CMU->XTALSTDSR_b.XTALSTDF))
    {
        XtalStop_IrqHandler();
    }
    /* SWDT underflow or fresh error */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL7) &&                                 \
        (Set == !!(M0P_SWDT->SR & (SWDT_SR_UDF | SWDT_SR_REF))))
    {
        Swdt_IrqHandler();
    }
    /* TimerB7 overflow */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL8) && (Set == bM0P_TMRB7->BCSTR_b.OVFF))
    {
        TimerB7OF_IrqHandler();
    }
    /* TimerB7 underflow */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL9) && (Set == bM0P_TMRB7->BCSTR_b.UDFF))
    {
        TimerB7UF_IrqHandler();
    }
    /* TimerB8 compare match */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL10) && (Set == bM0P_TMRB8->STFLR_b.CMPF1))
    {
        TimerB8Cmp_IrqHandler();
    }
    /* USART1 Rx ORE/FE/PE error */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL12) &&                                \
        (Set == !!(M0P_USART1->SR & (USART_SR_PE | USART_SR_FE | USART_SR_ORE))))
    {
        Usart1RxErr_IrqHandler();
    }
    /* I2c error */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL13) &&                                \
        (Set == !!(M0P_I2C->SR & (I2C_SR_STARTF   | I2C_SR_SLADDR0F     |       \
                                  I2C_SR_SLADDR1F | I2C_SR_STOPF        |       \
                                  I2C_SR_ARLOF    | I2C_SR_NACKF        |       \
                                  I2C_SR_GENCALLF | I2C_SR_SMBDEFAULTF  |       \
                                  I2C_SR_SMBHOSTF | I2C_SR_SMBALRTF))))
    {
        I2cErr_IrqHandler();
    }
    /* SPI parity/overflow/underflow/mode error */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL14) &&                                \
        (Set == !!(M0P_SWDT->SR & (SPI_SR_UDRERF | SPI_SR_PERF |                \
                                   SPI_SR_MODFERF | SPI_SR_OVRERF))))
    {
        SpiErr_IrqHandler();
    }
    /* USART4 Rx ORE/FE/PE error */
    if ((Set == bM0P_INTC->ISELBR24_b.ISEL15) &&                                \
        (Set == !!(M0P_USART4->SR & (USART_SR_PE | USART_SR_FE | USART_SR_ORE))))
    {
        Usart4RxErr_IrqHandler();
    }
}

/**
 * @brief  Interrupt No.025 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ025_Handler(void)
{
    /* External interrupt 09 */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL1) && (Set == bM0P_INTC->EIRQFR_b.EIRQF9))
    {
        Extint09_IrqHandler();
    }
    /* Clock trimming error */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL4) &&                                 \
        (Set == !!(M0P_CTC->STR & (CTC_STR_TRMOVF | CTC_STR_TRMUDF))))
    {
        ClockTrimErr_IrqHandler();
    }
    /* TimerB8 overflow */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL8) && (Set == bM0P_TMRB8->BCSTR_b.OVFF))
    {
        TimerB8OF_IrqHandler();
    }
    /* TimerB8 underflow */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL9) && (Set == bM0P_TMRB8->BCSTR_b.UDFF))
    {
        TimerB8UF_IrqHandler();
    }
    /* TimerB7 compare match */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL10) && (Set == bM0P_TMRB7->STFLR_b.CMPF1))
    {
        TimerB7Cmp_IrqHandler();
    }
    /* USART1 Rx end */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL11) && (Set == bM0P_USART1->SR_b.RXNE))
    {
        Usart1RxEnd_IrqHandler();
    }
    /* USART4 Rx end */
    if ((Set == bM0P_INTC->ISELBR25_b.ISEL15) && (Set == bM0P_USART4->SR_b.RXNE))
    {
        Usart4RxEnd_IrqHandler();
    }
}

/**
 * @brief  Interrupt No.026 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ026_Handler(void)
{
    /* TimerB5 overflow */
    if ((Set == bM0P_INTC->ISELBR26_b.ISEL8) && (Set == bM0P_TMRB5->BCSTR_b.OVFF))
    {
        TimerB5OF_IrqHandler();
    }
    /* TimerB5 underflow */
    if ((Set == bM0P_INTC->ISELBR26_b.ISEL9) && (Set == bM0P_TMRB5->BCSTR_b.UDFF))
    {
        TimerB5UF_IrqHandler();
    }
    /* TimerB6 compare match */
    if ((Set == bM0P_INTC->ISELBR26_b.ISEL10) && (Set == bM0P_TMRB6->STFLR_b.CMPF1))
    {
        TimerB6Cmp_IrqHandler();
    }
    /* USART1 Tx buffer empty */
    if ((Set == bM0P_INTC->ISELBR26_b.ISEL12) && (Set == bM0P_USART1->SR_b.TXE))
    {
        Usart1TxEmpt_IrqHandler();
    }
    /* USART3 Rx ORE/FE/PE error */
    if ((Set == bM0P_INTC->ISELBR26_b.ISEL13) &&                                \
        (Set == !!(M0P_USART3->SR & (USART_SR_PE | USART_SR_FE | USART_SR_ORE))))
    {
        Usart3RxErr_IrqHandler();
    }
}

/**
 * @brief  Interrupt No.027 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ027_Handler(void)
{
    /* EKEY and other Interrupt source are exclusive */
    if ((INTC_ISELBR_ISEL_1) == M0P_INTC->ISELBR27)
    {
        EKey_IrqHandler();
    }
    else
    {
        /* Timer 0 compare match */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL2) && (Set == bM0P_TMR0->STFLR_b.CMFA))
        {
            Timer0GCmp_IrqHandler();
        }
        /* TimerB6 overflow */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL8) && (Set == bM0P_TMRB6->BCSTR_b.OVFF))
        {
            TimerB6OF_IrqHandler();
        }
        /* TimerB6 underflow */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL9) && (Set == bM0P_TMRB6->BCSTR_b.UDFF))
        {
            TimerB6UF_IrqHandler();
        }
        /* TimerB5 compare match */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL10) && (Set == bM0P_TMRB5->STFLR_b.CMPF1))
        {
            TimerB5Cmp_IrqHandler();
        }
        /* USART1 Tx end */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL12) && (Set == bM0P_USART1->SR_b.TC))
        {
            Usart1TxEnd_IrqHandler();
        }
        /* USART3 Rx end */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL13) && (Set == bM0P_USART1->SR_b.RXNE))
        {
            Usart3RxEnd_IrqHandler();
        }
        /* SPI Rx end */
        if ((Set == bM0P_INTC->ISELBR27_b.ISEL14) && (Set == bM0P_SPI->SR_b.RDFF))
        {
            SpiRxEnd_IrqHandler();
        }
    }
}

/**
 * @brief  Interrupt No.028 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ028_Handler(void)
{
    /* TimerB3 overflow */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL8) && (Set == bM0P_TMRB3->BCSTR_b.OVFF))
    {
        TimerB3OF_IrqHandler();
    }
    /* TimerB3 underflow */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL9) && (Set == bM0P_TMRB3->BCSTR_b.UDFF))
    {
        TimerB3UF_IrqHandler();
    }
    /* TimerB4 compare match */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL10) && (Set == bM0P_TMRB4->STFLR_b.CMPF1))
    {
        TimerB4Cmp_IrqHandler();
    }
    /* ADC seq.A convert complete */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL11) && (Set == bM0P_ADC->ISR_b.EOCAF))
    {
        AdcSeqA_IrqHandler();
    }
    /* USART2 Rx ORE/FE/PE error */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL12) &&                                 \
        (Set == !!(M0P_USART2->SR & (USART_SR_PE | USART_SR_FE | USART_SR_ORE))))
    {
        Usart2RxErr_IrqHandler();
    }
    /* USART3 Tx buffer empty */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL13) && (Set == bM0P_USART3->SR_b.TXE))
    {
        Usart3TxEmpt_IrqHandler();
    }
    /* I2c Tx buffer empty */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL14) && (Set == bM0P_I2C->SR_b.TEMPTYF))
    {
        I2cTxEmpt_IrqHandler();
    }
    /* SPI bus idle */
    if ((Set == bM0P_INTC->ISELBR28_b.ISEL15) && (Set == bM0P_SPI->SR_b.IDLNF))
    {
        SpiIdle_IrqHandler();
    }
}

/**
 * @brief  Interrupt No.029 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ029_Handler(void)
{
    /* TimerB4 overflow */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL8) && (Set == bM0P_TMRB4->BCSTR_b.OVFF))
    {
        TimerB4OF_IrqHandler();
    }
    /* TimerB4 underflow */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL9) && (Set == bM0P_TMRB4->BCSTR_b.UDFF))
    {
        TimerB4UF_IrqHandler();
    }
    /* TimerB3 compare match */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL10) && (Set == bM0P_TMRB3->STFLR_b.CMPF1))
    {
        TimerB3Cmp_IrqHandler();
    }
    /* ADC seq.B convert complete */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL11) && (Set == bM0P_ADC->ISR_b.EOCBF))
    {
        AdcSeqB_IrqHandler();
    }
    /* USART2 Rx end */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL12) && (Set == bM0P_USART3->SR_b.RXNE))
    {
        Usart2RxEnd_IrqHandler();
    }
    /* USART3 Tx end */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL13) && (Set == bM0P_USART3->SR_b.TC))
    {
        Usart3TxEnd_IrqHandler();
    }
    /* I2c Rx end */
    if ((Set == bM0P_INTC->ISELBR29_b.ISEL14) && (Set == bM0P_I2C->SR_b.RFULLF))
    {
        I2cRxEnd_IrqHandler();
    }
}

/**
 * @brief  Interrupt No.030 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ030_Handler(void)
{
    /* TimerB1 overflow */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL8) && (Set == bM0P_TMRB1->BCSTR_b.OVFF))
    {
        TimerB1OF_IrqHandler();
    }
    /* TimerB1 underflow */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL9) && (Set == bM0P_TMRB1->BCSTR_b.UDFF))
    {
        TimerB1UF_IrqHandler();
    }
    /* TimerB2 compare match */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL10) && (Set == bM0P_TMRB2->STFLR_b.CMPF1))
    {
        TimerB2Cmp_IrqHandler();
    }
    /* ADC convert result in range of window 0 setting */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL11) && (Set == bM0P_ADC->AWDSR_b.AWD0F))
    {
        AdcCmp0_IrqHandler();
    }
    /* USART2 Tx buffer empty */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL12) && (Set == bM0P_USART2->SR_b.TXE))
    {
        Usart2TxEmpt_IrqHandler();
    }
    /* I2c Tx end */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL13) && (Set == bM0P_I2C->SR_b.TENDF))
    {
        I2cTxEnd_IrqHandler();
    }
    /* USART4 Tx buffer empty */
    if ((Set == bM0P_INTC->ISELBR30_b.ISEL15) && (Set == bM0P_USART4->SR_b.TXE))
    {
        Usart4TxEmpt_IrqHandler();
    }
}

/**
 * @brief  Interrupt No.031 share IRQ handler
 * @param  None
 * @retval None
 */
void IRQ031_Handler(void)
{
    /* LVD detected */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL2) && (Set == bM0P_PWC->LVDCSR_b.DETF))
    {
        Lvd_IrqHandler();
    }
    /* EFM operate end */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL4) && (Set == bM0P_EFM->FSR_b.OPTEND))
    {
        EfmOpEnd_IrqHandler();
    }
    /* RTC alarm */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL5) && (Set == bM0P_RTC->CR2_b.ALMF))
    {
        RtcAlarm_IrqHandler();
    }
    /* RTC period */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL6) && (Set == bM0P_RTC->CR2_b.PRDF))
    {
        RtcPeriod_IrqHandler();
    }
    /* TimerB2 overflow */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL8) && (Set == bM0P_TMRB2->BCSTR_b.OVFF))
    {
        TimerB2OF_IrqHandler();
    }
    /* TimerB2 underflow */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL9) && (Set == bM0P_TMRB2->BCSTR_b.UDFF))
    {
        TimerB2UF_IrqHandler();
    }
    /* TimerB1 compare match */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL10) && (Set == bM0P_TMRB1->STFLR_b.CMPF1))
    {
        TimerB1Cmp_IrqHandler();
    }
    /* ADC convert result in range of window 1 if dependence use */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL11) && (Set == bM0P_ADC->AWDSR_b.AWD1F) && (0 == M0P_ADC->AWDCR_f.AWDCM))
    {
        AdcCmp1_IrqHandler();
    }
    /* ADC convert result combination use of window 0 & 1 */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL11) && (Set == bM0P_ADC->AWDSR_b.AWDCMF) && (0 != M0P_ADC->AWDCR_f.AWDCM))
    {
        AdcCmp1_IrqHandler();
    }
    /* USART2 Tx end */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL12) && (Set == bM0P_USART2->SR_b.TC))
    {
        Usart2TxEnd_IrqHandler();
    }
        /* SPI Tx buffer empty */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL13) && (Set == bM0P_SPI->SR_b.TDEF))
    {
        SpiTxEmpt_IrqHandler();
    }
    /* USART4 Tx end */
    if ((Set == bM0P_INTC->ISELBR31_b.ISEL15) && (Set == bM0P_USART4->SR_b.TC))
    {
        Usart4TxEnd_IrqHandler();
    }
}

/**
 * @}
 */

#endif /* DDL_INTERRUPTS_ENABLE */  

/**
 * @}
 */

/**
* @}
*/

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/
