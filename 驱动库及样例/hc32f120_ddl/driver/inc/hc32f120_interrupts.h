/**
 *******************************************************************************
 * @file  hc32f120_interrupts.h
 * @brief This file contains all the functions prototypes of the interrupt driver
 *        library.
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
#ifndef __HC32F120_INTERRUPTS_H__
#define __HC32F120_INTERRUPTS_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_common.h"
#include "ddl_config.h"

/**
 * @addtogroup HC32F120_DDL_Driver
 * @{
 */

/**
 * @addtogroup DDL_INTERRUPTS
 * @{
 */

#if (DDL_INTERRUPTS_ENABLE == DDL_ON) || (DDL_EXINT_NMI_ENABLE == DDL_ON) ||    \
    (DDL_EKEY_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup INTC_Global_Types INTC Global Types
 * @{
 */
/**
 * @brief  Interrupt registration structure definition
 */
typedef struct
{
    en_int_src_t    enIntSrc;   /*!< Peripheral interrupt number,
                                     can be any value except INT_PORT_EIRQ0~7 @ref en_int_src_t         */
    IRQn_Type       enIRQn;     /*!< Peripheral IRQ type, can be Int008_IRQn~Int023_IRQn @ref IRQn_Type */
    func_ptr_t      pfnCallback;/*!< Callback function for corresponding peripheral IRQ                 */
}stc_irq_regi_config_t;

/**
 * @brief  NMI initialize configuration structure definition
 */
typedef struct
{
    uint8_t     u8NmiFE;        /*!< NMI pin filter function, @ref NMI_FilterClock_Sel for details          */
    uint8_t     u8NmiFClk;      /*!< NMI pin filter clock  division, @ref NMI_FilterClock_Div for details   */
    uint8_t     u8NmiTigger;    /*!< NMI pin trigger edge, @ref NMI_Trigger_Sel for details                 */
    uint8_t     u8NmiSrc;       /*!< NMI trigger source, @ref NMI_TriggerSrc_Sel for details                */
    func_ptr_t  pfnNmiCallback; /*!< NMI Callback function pointers                                         */
}stc_nmi_config_t;

/**
 * @brief  EXINT initialize configuration structure definition
 */
typedef struct
{
    uint16_t    u16ExIntCh;     /*!< ExInt CH.0~9 @ref EXINT_Channel_Sel                                */
    uint8_t     u8ExIntFE;      /*!< ExInt filter clock, @ref EXINT_FilterClock_Sel for details         */
    uint8_t     u8ExIntFClk;    /*!< ExInt filter clock division, @ref EXINT_FilterClock_Div for details*/
    uint8_t     u8ExIntLvl;     /*!< ExInt trigger edge, @ref EXINT_Trigger_Sel for details             */
}stc_exint_config_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup INTC_Global_Macros INTC Global Macros
 * @{
 */
/**
 * @defgroup INTC_DefaultPriority_Sel Interrupt default priority level
 * Possible values are 0 (high priority) to 3 (low priority)
 * @{
 */
#define DDL_IRQ_PRIORITY_DEFAULT    3u
/**
 * @}
 */

/**
 * @defgroup INTC_Priority_Sel Interrupt priority level 00 ~ 03
 * @{
 */
#define DDL_IRQ_PRIORITY_00         0u
#define DDL_IRQ_PRIORITY_01         1u
#define DDL_IRQ_PRIORITY_02         2u
#define DDL_IRQ_PRIORITY_03         3u
/**
 * @}
 */

/**
 * @defgroup INTC_Register_Protect INTC Registers Protect Code
 * @{
 */
#define INTC_REG_UNPROTECT          ((uint8_t)0xA5)
#define INTC_REG_PROTECT            ((uint8_t)0x00)
/**
 * @}
 */

/**
 * @defgroup NMI_FilterClock_Sel NMI pin filter selection
 * @{
 */
#define NMI_FILTER_OFF              (0u << INTC_NMICR_NMIFEN_POS)
#define NMI_FILTER_ON               (1u << INTC_NMICR_NMIFEN_POS)
/**
 * @}
 */

/**
 * @defgroup NMI_FilterClock_Div NMI pin filter sampling clock division selection
 * @{
 */
#define NMI_FCLK_HCLK_DIV1          (0u << INTC_NMICR_NMIFCLK_POS)
#define NMI_FCLK_HCLK_DIV8          (1u << INTC_NMICR_NMIFCLK_POS)
#define NMI_FCLK_HCLK_DIV32         (2u << INTC_NMICR_NMIFCLK_POS)
#define NMI_FCLK_HCLK_DIV64         (3u << INTC_NMICR_NMIFCLK_POS)
/**
 * @}
 */

/**
 * @defgroup NMI_Trigger_Sel NMI pin trigger method selection
 * @{
 */
#define NMI_TRIGGER_FALLING         (0u << INTC_NMICR_NMITRG_POS)
#define NMI_TRIGGER_RISING          (1u << INTC_NMICR_NMITRG_POS)
/**
 * @}
 */

/**
 * @defgroup NMI_TriggerSrc_Sel NMI trigger source selection
 * @{
 */
#define NMI_SRC_NMI_PIN             (1u << INTC_NMIER_NMIEN_POS)
#define NMI_SRC_XTAL_STP            (1u << INTC_NMIER_XTALSTPEN_POS)
#define NMI_SRC_SWDT                (1u << INTC_NMIER_SWDTEN_POS)
#define NMI_SRC_LVD                 (1u << INTC_NMIER_PVDEN_POS)
#define NMI_SRC_MASK                (NMI_SRC_NMI_PIN | NMI_SRC_XTAL_STP |       \
                                    NMI_SRC_SWDT | NMI_SRC_LVD)
/**
 * @}
 */

/**
 * @defgroup MNI_Register_Msk NMI register mask
 * @{
 */
#define INTC_NMICR_MASK     (INTC_NMICR_NMITRG | INTC_NMICR_NMIFCLK     |       \
                            INTC_NMICR_NMIFEN)
#define INTC_NMIER_MASK     (INTC_NMIER_NMIEN  | INTC_NMIER_XTALSTPEN   |       \
                            INTC_NMIER_SWDTEN  | INTC_NMIER_PVDEN)
#define INTC_NMIFR_MASK     (INTC_NMIFR_NMIF   | INTC_NMIFR_XTALSTPF    |       \
                            INTC_NMIFR_SWDTF   | INTC_NMIFR_PVDF)
#define INTC_NMICLR_MASK    (INTC_NMICLR_NMICL | INTC_NMICLR_XTALSTPCL  |       \
                            INTC_NMICLR_SWDTCL | INTC_NMICLR_PVDCL)
/**
 * @}
 */

/**
 * @defgroup EXINT_Channel_Sel External interrupt channel selection
 * @{
 */
#define EXINT_CH00                  (1u << 0)
#define EXINT_CH01                  (1u << 1)
#define EXINT_CH02                  (1u << 2)
#define EXINT_CH03                  (1u << 3)
#define EXINT_CH04                  (1u << 4)
#define EXINT_CH05                  (1u << 5)
#define EXINT_CH06                  (1u << 6)
#define EXINT_CH07                  (1u << 7)
#define EXINT_CH08                  (1u << 8)
#define EXINT_CH09                  (1u << 9)
#define EXINT_CH_MASK   (EXINT_CH00 | EXINT_CH01 | EXINT_CH02 | EXINT_CH03 |    \
                         EXINT_CH04 | EXINT_CH05 | EXINT_CH06 | EXINT_CH07 |    \
                         EXINT_CH08 | EXINT_CH09)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterClock_Sel External interrupt filter function selection
 * @{
 */
#define EXINT_FILTER_OFF            (0u << INTC_EIRQCR_EIRQFEN_POS)
#define EXINT_FILTER_ON             (1u << INTC_EIRQCR_EIRQFEN_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterClock_Div External interrupt filtersampling  clock division selection
 * @{
 */
#define EXINT_FCLK_HCLK_DIV1        (0u << INTC_EIRQCR_EIRQFCLK_POS)
#define EXINT_FCLK_HCLK_DIV8        (1u << INTC_EIRQCR_EIRQFCLK_POS)
#define EXINT_FCLK_HCLK_DIV32       (2u << INTC_EIRQCR_EIRQFCLK_POS)
#define EXINT_FCLK_HCLK_DIV64       (3u << INTC_EIRQCR_EIRQFCLK_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_Trigger_Sel External interrupt trigger method selection
 * @{
 */
#define EXINT_TRIGGER_LOW           (0u << INTC_EIRQCR_EIRQTRG_POS)
#define EXINT_TRIGGER_RISING        (1u << INTC_EIRQCR_EIRQTRG_POS)
#define EXINT_TRIGGER_FALLING       (2u << INTC_EIRQCR_EIRQTRG_POS)
#define EXINT_TRIGGER_BOTH          (3u << INTC_EIRQCR_EIRQTRG_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_Register_Msk EXINT register mask
 * @{
 */
#define INTC_EIRQF_MASK             (INTC_EIRQFR_EIRQF)
#define INTC_EIRQCLR_MASK           (INTC_EIRQCLR_EIRQCL)
/**
 * @}
 */

/**
 * @defgroup INTC_EKEY_Channel INTC EKEY channel selection
 * @{
 */
#define INTC_EKEY0                  (1u << INTC_EKEYCR_EKEY0EN_POS)
#define INTC_EKEY1                  (1u << INTC_EKEYCR_EKEY1EN_POS)
#define INTC_EKEY2                  (1u << INTC_EKEYCR_EKEY2EN_POS)
#define INTC_EKEY3                  (1u << INTC_EKEYCR_EKEY3EN_POS)
#define INTC_EKEY4                  (1u << INTC_EKEYCR_EKEY4EN_POS)
#define INTC_EKEY5                  (1u << INTC_EKEYCR_EKEY5EN_POS)
#define INTC_EKEY_MASK              (INTC_EKEY0 | INTC_EKEY1 | INTC_EKEY2 |     \
                                     INTC_EKEY3 | INTC_EKEY4 | INTC_EKEY5)
/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup INTC_Global_Functions
 * @{
 */

/**
 * @brief  AOS software trigger.
 * @param  None
 * @retval None
 */
__STATIC_INLINE void AOS_SW_Trigger(void)
{
    WRITE_REG(bM0P_AOS->INTC_STRGCR_b.STRG, Set);
}

/**
 * @brief  INTC lock, register write disable
 * @param  None
 * @retval None
 */
__STATIC_INLINE void INTC_Lock(void)
{
    WRITE_REG(M0P_INTC->FPRCR, INTC_REG_PROTECT);
}

/**
 * @brief  INTC unlock, register write enable
 * @param  None
 * @retval None
 */
__STATIC_INLINE void INTC_Unlock(void)
{
    WRITE_REG(M0P_INTC->FPRCR, INTC_REG_UNPROTECT);
}

en_result_t INTC_IrqRegistration(const stc_irq_regi_config_t *pstcIrqRegiConfig);
void INTC_IrqResign(IRQn_Type enIRQn);
en_result_t INTC_ShareIrqCmd(en_int_src_t enIntSrc, en_functional_state_t enNewState);
void INTC_WakeupSrcCmd(uint32_t u32WakeupSrc, en_functional_state_t enNewState);
void INTC_EventCmd(uint8_t u8Event, en_functional_state_t enNewState);

en_result_t NMI_Init(const stc_nmi_config_t *pstcNmiConfig);
en_result_t NMI_StructInit(stc_nmi_config_t *pstcNmiConfig);
en_flag_status_t NMI_GetNmiSrc(uint8_t u8NmiSrc);
void NMI_ClrNmiSrc(uint8_t u8NmiSrc);

en_result_t EXINT_Init(const stc_exint_config_t *pstcExintConfig);
en_result_t EXINT_StructInit(stc_exint_config_t *pstcExintConfig);
en_flag_status_t EXINT_GetExIntSrc(uint16_t u16ExIntCh);
void EXINT_ClrSrc(uint16_t u16ExIntCh);

void INTC_EKeyCmd(uint8_t u8EKey, en_functional_state_t enNewState);

__WEAKDEF void NMI_IrqHandler(void);
__WEAKDEF void HardFault_IrqHandler(void);
__WEAKDEF void SVC_IrqHandler(void);
__WEAKDEF void PendSV_IrqHandler(void);
__WEAKDEF void SysTick_IrqHandler(void);

__WEAKDEF void Extint08_IrqHandler(void);
__WEAKDEF void Extint09_IrqHandler(void);

__WEAKDEF void EfmPgmEraseErr_IrqHandler(void);
__WEAKDEF void EfmColErr_IrqHandler(void);
__WEAKDEF void EfmOpEnd_IrqHandler(void);

__WEAKDEF void XtalStop_IrqHandler(void);

__WEAKDEF void Swdt_IrqHandler(void);

__WEAKDEF void TimerB1OF_IrqHandler(void);
__WEAKDEF void TimerB1UF_IrqHandler(void);
__WEAKDEF void TimerB1Cmp_IrqHandler(void);
__WEAKDEF void TimerB2OF_IrqHandler(void);
__WEAKDEF void TimerB2UF_IrqHandler(void);
__WEAKDEF void TimerB2Cmp_IrqHandler(void);
__WEAKDEF void TimerB3OF_IrqHandler(void);
__WEAKDEF void TimerB3UF_IrqHandler(void);
__WEAKDEF void TimerB3Cmp_IrqHandler(void);
__WEAKDEF void TimerB4OF_IrqHandler(void);
__WEAKDEF void TimerB4UF_IrqHandler(void);
__WEAKDEF void TimerB4Cmp_IrqHandler(void);
__WEAKDEF void TimerB5OF_IrqHandler(void);
__WEAKDEF void TimerB5UF_IrqHandler(void);
__WEAKDEF void TimerB5Cmp_IrqHandler(void);
__WEAKDEF void TimerB6OF_IrqHandler(void);
__WEAKDEF void TimerB6UF_IrqHandler(void);
__WEAKDEF void TimerB6Cmp_IrqHandler(void);
__WEAKDEF void TimerB7OF_IrqHandler(void);
__WEAKDEF void TimerB7UF_IrqHandler(void);
__WEAKDEF void TimerB7Cmp_IrqHandler(void);
__WEAKDEF void TimerB8OF_IrqHandler(void);
__WEAKDEF void TimerB8UF_IrqHandler(void);
__WEAKDEF void TimerB8Cmp_IrqHandler(void);

__WEAKDEF void Usart1RxErr_IrqHandler(void);
__WEAKDEF void Usart1RxEnd_IrqHandler(void);
__WEAKDEF void Usart1TxEmpt_IrqHandler(void);
__WEAKDEF void Usart1TxEnd_IrqHandler(void);
__WEAKDEF void Usart2RxErr_IrqHandler(void);
__WEAKDEF void Usart2RxEnd_IrqHandler(void);
__WEAKDEF void Usart2TxEmpt_IrqHandler(void);
__WEAKDEF void Usart2TxEnd_IrqHandler(void);
__WEAKDEF void Usart3RxErr_IrqHandler(void);
__WEAKDEF void Usart3RxEnd_IrqHandler(void);
__WEAKDEF void Usart3TxEmpt_IrqHandler(void);
__WEAKDEF void Usart3TxEnd_IrqHandler(void);
__WEAKDEF void Usart4RxErr_IrqHandler(void);
__WEAKDEF void Usart4RxEnd_IrqHandler(void);
__WEAKDEF void Usart4TxEmpt_IrqHandler(void);
__WEAKDEF void Usart4TxEnd_IrqHandler(void);

__WEAKDEF void I2cRxEnd_IrqHandler(void);
__WEAKDEF void I2cTxEnd_IrqHandler(void);
__WEAKDEF void I2cTxEmpt_IrqHandler(void);
__WEAKDEF void I2cErr_IrqHandler(void);

__WEAKDEF void SpiRxEnd_IrqHandler(void);
__WEAKDEF void SpiTxEmpt_IrqHandler(void);
__WEAKDEF void SpiErr_IrqHandler(void);
__WEAKDEF void SpiIdle_IrqHandler(void);

__WEAKDEF void ClockTrimErr_IrqHandler(void);

__WEAKDEF void EKey_IrqHandler(void);

__WEAKDEF void Timer0GCmp_IrqHandler(void);

__WEAKDEF void AdcSeqA_IrqHandler(void);
__WEAKDEF void AdcSeqB_IrqHandler(void);
__WEAKDEF void AdcCmp0_IrqHandler(void);
__WEAKDEF void AdcCmp1_IrqHandler(void);

__WEAKDEF void Lvd_IrqHandler(void);

__WEAKDEF void RtcAlarm_IrqHandler(void);
__WEAKDEF void RtcPeriod_IrqHandler(void);

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

#ifdef __cplusplus
}
#endif

#endif /* __HC32F120_INTERRUPTS_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
