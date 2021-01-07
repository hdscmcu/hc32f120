/**
 *******************************************************************************
 * @file  HC32F120.h
 * @brief Headerfile for HC32F120 series MCU
 @verbatim
   Change Logs:
   Date             Author          Notes
   2020-11-19       chengy          First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2017, Huada Semiconductor Co.,Ltd All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co.,Ltd. ("HDSC").
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
 */
/******************************************************************************/
/** \file HC32F120.h
 **
 ** Auto generate.
 ** Headerfile for HC32F120 series MCU
 **
 ** History:
 **
 **   - 2020-11-19  1.0   First version for Device Driver Library of HC32F120 series MCU.
 **
 ******************************************************************************/

#ifndef __HC32F120_H__
#define __HC32F120_H__

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Configuration of the Cortex-M0+ Processor and Core Peripherals
 ******************************************************************************/
#define __MPU_PRESENT             0       /*!< HC32F120 provides an MPU                             */
#define __VTOR_PRESENT            1       /*!< HC32F120 supported vector table registers            */
#define __NVIC_PRIO_BITS          2       /*!< HC32F120 uses 2 Bits for the Priority Levels         */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used         */

/*******************************************************************************
 * Interrupt Number Definition
 ******************************************************************************/
typedef enum IRQn
{
    NMI_IRQn            = -14, /*  2 Non Maskable                            */
    HardFault_IRQn      = -13, /*  3 Hard Fault                              */
    SVC_IRQn            = -5,  /* 11 SV Call                                 */
    PendSV_IRQn         = -2,  /* 14 Pend SV                                 */
    SysTick_IRQn        = -1,  /* 15 System Tick                             */
    EXINT00_IRQn        = 0,
    EXINT01_IRQn        = 1,
    EXINT02_IRQn        = 2,
    EXINT03_IRQn        = 3,
    EXINT04_IRQn        = 4,
    EXINT05_IRQn        = 5,
    EXINT06_IRQn        = 6,
    EXINT07_IRQn        = 7,
    Int008_IRQn         = 8,
    Int009_IRQn         = 9,
    Int010_IRQn         = 10,
    Int011_IRQn         = 11,
    Int012_IRQn         = 12,
    Int013_IRQn         = 13,
    Int014_IRQn         = 14,
    Int015_IRQn         = 15,
    Int016_IRQn         = 16,
    Int017_IRQn         = 17,
    Int018_IRQn         = 18,
    Int019_IRQn         = 19,
    Int020_IRQn         = 20,
    Int021_IRQn         = 21,
    Int022_IRQn         = 22,
    Int023_IRQn         = 23,
    Int024_IRQn         = 24,
    Int025_IRQn         = 25,
    Int026_IRQn         = 26,
    Int027_IRQn         = 27,
    Int028_IRQn         = 28,
    Int029_IRQn         = 29,
    Int030_IRQn         = 30,
    Int031_IRQn         = 31,

} IRQn_Type;

#include <core_cm0plus.h>
#include <stdint.h>

/**
 *******************************************************************************
 ** \brief Event number enumeration
 ******************************************************************************/
typedef enum en_event_src
{
    EVT_PORT_EIRQ0          = 0u,
    EVT_PORT_EIRQ8          = 1u,
    EVT_TMRB_7_OVF          = 8u,
    EVT_TMRB_7_UDF          = 9u,
    EVT_TMRB_8_CMP          = 10u,
    EVT_PORT_EIRQ1          = 16u,
    EVT_PORT_EIRQ9          = 17u,
    EVT_TMRB_8_OVF          = 24u,
    EVT_TMRB_8_UDF          = 25u,
    EVT_TMRB_7_CMP          = 26u,
    EVT_PORT_EIRQ2          = 32u,
    EVT_TMRB_5_OVF          = 40u,
    EVT_TMRB_5_UDF          = 41u,
    EVT_TMRB_6_CMP          = 42u,
    EVT_PORT_EIRQ3          = 48u,
    EVT_TMR0_GCMP           = 50u,
    EVT_TMRB_6_OVF          = 56u,
    EVT_TMRB_6_UDF          = 57u,
    EVT_TMRB_5_CMP          = 58u,
    EVT_AOS_STRG            = 59u,
    EVT_PORT_EIRQ4          = 64u,
    EVT_TMRB_3_OVF          = 72u,
    EVT_TMRB_3_UDF          = 73u,
    EVT_TMRB_4_CMP          = 74u,
    EVT_ADC_EOCA            = 75u,
    EVT_PORT_EIRQ5          = 80u,
    EVT_TMRB_4_OVF          = 88u,
    EVT_TMRB_4_UDF          = 89u,
    EVT_TMRB_3_CMP          = 90u,
    EVT_ADC_EOCB            = 91u,
    EVT_PORT_EIRQ6          = 96u,
    EVT_TMRB_1_OVF          = 104u,
    EVT_TMRB_1_UDF          = 105u,
    EVT_TMRB_2_CMP          = 106u,
    EVT_ADC_CMP0            = 107u,
    EVT_PORT_EIRQ7          = 112u,
    EVT_FMC_OPTEND          = 116u,
    EVT_RTC_ALM             = 117u,
    EVT_RTC_PRD             = 118u,
    EVT_TMRB_2_OVF          = 120u,
    EVT_TMRB_2_UDF          = 121u,
    EVT_TMRB_1_CMP          = 122u,
    EVT_ADC_CMP1            = 123u,
} en_event_src_t;

/**
 *******************************************************************************
 ** \brief Interrupt number enumeration
 ******************************************************************************/
typedef enum en_int_src
{
    INT_PORT_EIRQ0          = 0u,
    INT_PORT_EIRQ8          = 1u,
    INT_EFM_PEERR           = 4u,
    INT_EFM_RDCOL           = 5u,
    INT_XTAL_STOP           = 6u,
    INT_SWDT_NMIUNDF        = 7u,
    INT_TMRB_7_OVF          = 8u,
    INT_TMRB_7_UDF          = 9u,
    INT_TMRB_8_CMP          = 10u,
    INT_USART_1_EI          = 12u,
    INT_IIC_EEI             = 13u,
    INT_SPI_SPEI            = 14u,
    INT_USART_4_EI          = 15u,
    INT_PORT_EIRQ1          = 16u,
    INT_PORT_EIRQ9          = 17u,
    INT_CTC_ERR             = 20u,
    INT_TMRB_8_OVF          = 24u,
    INT_TMRB_8_UDF          = 25u,
    INT_TMRB_7_CMP          = 26u,
    INT_USART_1_RI          = 28u,
    INT_USART_4_RI          = 31u,
    INT_PORT_EIRQ2          = 32u,
    INT_TMRB_5_OVF          = 40u,
    INT_TMRB_5_UDF          = 41u,
    INT_TMRB_6_CMP          = 42u,
    INT_USART_1_TI          = 44u,
    INT_USART_3_EI          = 45u,
    INT_PORT_EIRQ3          = 48u,
    INT_PORT_EKEY           = 49u,
    INT_TMR0_GCMP           = 50u,
    INT_TMRB_6_OVF          = 56u,
    INT_TMRB_6_UDF          = 57u,
    INT_TMRB_5_CMP          = 58u,
    INT_USART_1_TCI         = 60u,
    INT_USART_3_RI          = 61u,
    INT_SPI_SPRI            = 62u,
    INT_PORT_EIRQ4          = 64u,
    INT_TMRB_3_OVF          = 72u,
    INT_TMRB_3_UDF          = 73u,
    INT_TMRB_4_CMP          = 74u,
    INT_ADC_EOCA            = 75u,
    INT_USART_2_EI          = 76u,
    INT_USART_3_TI          = 77u,
    INT_IIC_TEI             = 78u,
    INT_SPI_SPII            = 79u,
    INT_PORT_EIRQ5          = 80u,
    INT_TMRB_4_OVF          = 88u,
    INT_TMRB_4_UDF          = 89u,
    INT_TMRB_3_CMP          = 90u,
    INT_ADC_EOCB            = 91u,
    INT_USART_2_RI          = 92u,
    INT_USART_3_TCI         = 93u,
    INT_IIC_RXI             = 94u,
    INT_PORT_EIRQ6          = 96u,
    INT_TMRB_1_OVF          = 104u,
    INT_TMRB_1_UDF          = 105u,
    INT_TMRB_2_CMP          = 106u,
    INT_ADC_CMP0            = 107u,
    INT_USART_2_TI          = 108u,
    INT_IIC_TXI             = 109u,
    INT_USART_4_TI          = 111u,
    INT_PORT_EIRQ7          = 112u,
    INT_PVD_DET             = 114u,
    INT_FMC_OPTEND          = 116u,
    INT_RTC_ALM             = 117u,
    INT_RTC_PRD             = 118u,
    INT_RTC_IT              = 119u,
    INT_TMRB_2_OVF          = 120u,
    INT_TMRB_2_UDF          = 121u,
    INT_TMRB_1_CMP          = 122u,
    INT_ADC_CMP1            = 123u,
    INT_USART_2_TCI         = 124u,
    INT_SPI_SPTI            = 125u,
    INT_USART_4_TCI         = 127u,
} en_int_src_t;

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

typedef struct
{
    __IO uint8_t STRT                       : 1;
    uint8_t RESERVED1                       : 7;
} stc_adc_str_field_t;

typedef struct
{
    __IO uint16_t MS                        : 2;
    uint16_t RESERVED2                      : 2;
    __IO uint16_t ACCSEL                    : 2;
    __IO uint16_t CLREN                     : 1;
    __IO uint16_t DFMT                      : 1;
    uint16_t RESERVED8                      : 8;
} stc_adc_cr0_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 2;
    __IO uint16_t RSCHSEL                   : 1;
    uint16_t RESERVED3                      :13;
} stc_adc_cr1_field_t;

typedef struct
{
    __IO uint16_t TRGSELA                   : 2;
    uint16_t RESERVED2                      : 5;
    __IO uint16_t TRGENA                    : 1;
    __IO uint16_t TRGSELB                   : 2;
    uint16_t RESERVED10                     : 5;
    __IO uint16_t TRGENB                    : 1;
} stc_adc_trgsr_field_t;

typedef struct
{
    __IO uint16_t CHSELA                    :12;
    uint16_t RESERVED12                     : 4;
} stc_adc_chselra0_field_t;

typedef struct
{
    __IO uint16_t CHSELB                    :12;
    uint16_t RESERVED12                     : 4;
} stc_adc_chselrb0_field_t;

typedef struct
{
    __IO uint8_t EXCHSEL                    : 1;
    uint8_t RESERVED1                       : 7;
} stc_adc_exchselr_field_t;

typedef struct
{
    __IO uint8_t EOCAF                      : 1;
    __IO uint8_t EOCBF                      : 1;
    uint8_t RESERVED2                       : 6;
} stc_adc_isr_field_t;

typedef struct
{
    __IO uint8_t EOCAIEN                    : 1;
    __IO uint8_t EOCBIEN                    : 1;
    uint8_t RESERVED2                       : 6;
} stc_adc_icr_field_t;

typedef struct
{
    __IO uint8_t CLREOCAF                   : 1;
    __IO uint8_t CLREOCBF                   : 1;
    uint8_t RESERVED2                       : 6;
} stc_adc_isclrr_field_t;

typedef struct
{
    __IO uint16_t AWD0EN                    : 1;
    __IO uint16_t AWD0IEN                   : 1;
    __IO uint16_t AWD0MD                    : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t AWD1EN                    : 1;
    __IO uint16_t AWD1IEN                   : 1;
    __IO uint16_t AWD1MD                    : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t AWDCM                     : 2;
    uint16_t RESERVED10                     : 6;
} stc_adc_awdcr_field_t;

typedef struct
{
    __IO uint8_t AWD0F                      : 1;
    __IO uint8_t AWD1F                      : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t AWDCMF                     : 1;
    uint8_t RESERVED5                       : 3;
} stc_adc_awdsr_field_t;

typedef struct
{
    __IO uint8_t CLRAWD0F                   : 1;
    __IO uint8_t CLRAWD1F                   : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t CLRAWDCMF                  : 1;
    uint8_t RESERVED5                       : 3;
} stc_adc_awdsclrr_field_t;

typedef struct
{
    __IO uint8_t AWDCH                      : 5;
    uint8_t RESERVED5                       : 3;
} stc_adc_awd0chsr_field_t;

typedef struct
{
    __IO uint8_t AWDCH                      : 5;
    uint8_t RESERVED5                       : 3;
} stc_adc_awd1chsr_field_t;

typedef struct
{
    __IO uint32_t STRG                      : 1;
    uint32_t RESERVED1                      :31;
} stc_aos_intc_strgcr_field_t;

typedef struct
{
    __IO uint32_t TRGSEL                    : 7;
    uint32_t RESERVED7                      :25;
} stc_aos_tmr0_htssr_field_t;

typedef struct
{
    __IO uint32_t TRGSEL                    : 7;
    uint32_t RESERVED7                      :25;
} stc_aos_tmrb_htssr_field_t;

typedef struct
{
    __IO uint32_t TRGSEL                    : 7;
    uint32_t RESERVED7                      :25;
} stc_aos_adc_itrgselr0_field_t;

typedef struct
{
    __IO uint32_t TRGSEL                    : 7;
    uint32_t RESERVED7                      :25;
} stc_aos_adc_itrgselr1_field_t;

typedef struct
{
    __IO uint8_t PERICKSEL                  : 3;
    uint8_t RESERVED3                       : 5;
} stc_cmu_pericksel_field_t;

typedef struct
{
    __IO uint8_t XTALSTDF                   : 1;
    uint8_t RESERVED1                       : 7;
} stc_cmu_xtalstdsr_field_t;

typedef struct
{
    __IO uint8_t SCKDIV                     : 3;
    uint8_t RESERVED3                       : 5;
} stc_cmu_sckdivr_field_t;

typedef struct
{
    __IO uint8_t CKSW                       : 2;
    uint8_t RESERVED2                       : 6;
} stc_cmu_ckswr_field_t;

typedef struct
{
    __IO uint8_t XTALSTP                    : 1;
    uint8_t RESERVED1                       : 7;
} stc_cmu_xtalcr_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 4;
    __IO uint8_t XTALDRV                    : 2;
    __IO uint8_t XTALMS                     : 1;
    __IO uint8_t SUPDRV                     : 1;
} stc_cmu_xtalcfgr_field_t;

typedef struct
{
    __IO uint8_t XTALSTB                    : 3;
    uint8_t RESERVED3                       : 5;
} stc_cmu_xtalstbcr_field_t;

typedef struct
{
    __IO uint8_t HRCSTP                     : 1;
    uint8_t RESERVED1                       : 7;
} stc_cmu_hrccr_field_t;

typedef struct
{
    __IO uint8_t HRCSTBF                    : 1;
    uint8_t RESERVED1                       : 2;
    __IO uint8_t XTALSTBF                   : 1;
    __IO uint8_t XTAL32STBF                 : 1;
    uint8_t RESERVED5                       : 3;
} stc_cmu_oscstbsr_field_t;

typedef struct
{
    __IO uint8_t MCO1SEL                    : 4;
    __IO uint8_t MCO1DIV                    : 3;
    __IO uint8_t MCO1EN                     : 1;
} stc_cmu_mco1cfgr_field_t;

typedef struct
{
    __IO uint8_t XTALSTDIE                  : 1;
    __IO uint8_t XTALSTDRE                  : 1;
    __IO uint8_t XTALSTDRIS                 : 1;
    uint8_t RESERVED3                       : 4;
    __IO uint8_t XTALSTDE                   : 1;
} stc_cmu_xtalstdcr_field_t;

typedef struct
{
    __IO uint32_t ADC                       : 1;
    __IO uint32_t CTC                       : 1;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t AOS                       : 1;
    uint32_t RESERVED5                      : 2;
    __IO uint32_t CRC                       : 1;
    __IO uint32_t TIMB1                     : 1;
    __IO uint32_t TIMB2                     : 1;
    __IO uint32_t TIMB3                     : 1;
    __IO uint32_t TIMB4                     : 1;
    __IO uint32_t TIMB5                     : 1;
    __IO uint32_t TIMB6                     : 1;
    __IO uint32_t TIMB7                     : 1;
    __IO uint32_t TIMB8                     : 1;
    __IO uint32_t TIM0                      : 1;
    uint32_t RESERVED17                     : 6;
    __IO uint32_t RTC                       : 1;
    __IO uint32_t UART1                     : 1;
    __IO uint32_t UART2                     : 1;
    __IO uint32_t UART3                     : 1;
    __IO uint32_t UART4                     : 1;
    __IO uint32_t IIC                       : 1;
    __IO uint32_t SPI                       : 1;
    uint32_t RESERVED30                     : 2;
} stc_cmu_fcg_field_t;

typedef struct
{
    __IO uint8_t XTAL32STP                  : 1;
    uint8_t RESERVED1                       : 7;
} stc_cmu_xtal32cr_field_t;

typedef struct
{
    __IO uint8_t XTAL32DRV                  : 2;
    __IO uint8_t XTAL32SUPDRV               : 1;
    uint8_t RESERVED3                       : 5;
} stc_cmu_xtal32cfgr_field_t;

typedef struct
{
    __IO uint8_t XTAL32NF                   : 2;
    uint8_t RESERVED2                       : 6;
} stc_cmu_xtal32nfr_field_t;

typedef struct
{
    __IO uint8_t LRCSTP                     : 1;
    uint8_t RESERVED1                       : 7;
} stc_cmu_lrccr_field_t;

typedef struct
{
    __IO uint32_t CR                        : 1;
    __IO uint32_t FLAG                      : 1;
    uint32_t RESERVED2                      :30;
} stc_crc_cr_field_t;

typedef struct
{
    __IO uint32_t REFPSC                    : 3;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t REFCKS                    : 2;
    __IO uint32_t ERRIE                     : 1;
    __IO uint32_t CTCEN                     : 1;
    uint32_t RESERVED8                      : 8;
    __IO uint32_t TRMVAL                    : 6;
    uint32_t RESERVED22                     :10;
} stc_ctc_cr1_field_t;

typedef struct
{
    __IO uint32_t OFSVAL                    : 8;
    uint32_t RESERVED8                      : 8;
    __IO uint32_t RLDVAL                    :16;
} stc_ctc_cr2_field_t;

typedef struct
{
    __IO uint32_t TRIMOK                    : 1;
    __IO uint32_t TRMOVF                    : 1;
    __IO uint32_t TRMUDF                    : 1;
    __IO uint32_t CTCBSY                    : 1;
    uint32_t RESERVED4                      :28;
} stc_ctc_str_field_t;

typedef struct
{
    __IO uint32_t CDBGPWRUPREQ              : 1;
    __IO uint32_t CDBGPWRUPACK              : 1;
    uint32_t RESERVED2                      :30;
} stc_dbgc_mcudbgstat_field_t;

typedef struct
{
    __IO uint32_t SWDTSTP                   : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t RTCSTP                    : 1;
    __IO uint32_t PVDSTP                    : 1;
    uint32_t RESERVED4                      :10;
    __IO uint32_t TMR01STP                  : 1;
    uint32_t RESERVED15                     : 2;
    __IO uint32_t TMR21STP                  : 1;
    uint32_t RESERVED18                     : 2;
    __IO uint32_t TMR41STP                  : 1;
    uint32_t RESERVED21                     : 2;
    __IO uint32_t TMRA1STP                  : 1;
    __IO uint32_t TMRB1STP                  : 1;
    __IO uint32_t TMRB2STP                  : 1;
    __IO uint32_t TMRB3STP                  : 1;
    __IO uint32_t TMRB4STP                  : 1;
    __IO uint32_t TMRB5STP                  : 1;
    __IO uint32_t TMRB6STP                  : 1;
    __IO uint32_t TMRB7STP                  : 1;
    __IO uint32_t TMRB8STP                  : 1;
} stc_dbgc_mcustpctl_field_t;

typedef struct
{
    __IO uint32_t FAPRT                     :16;
    uint32_t RESERVED16                     :16;
} stc_efm_faprt_field_t;

typedef struct
{
    __IO uint32_t FSTP                      : 1;
    uint32_t RESERVED1                      :31;
} stc_efm_fstp_field_t;

typedef struct
{
    __IO uint32_t FLWT                      : 1;
    uint32_t RESERVED1                      :16;
    __IO uint32_t PREFETE                   : 1;
    uint32_t RESERVED18                     :14;
} stc_efm_frmc_field_t;

typedef struct
{
    __IO uint32_t PEMODE                    : 1;
    uint32_t RESERVED1                      : 3;
    __IO uint32_t PEMOD                     : 3;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t BUSHLDCTL                 : 1;
    uint32_t RESERVED9                      :23;
} stc_efm_fwmc_field_t;

typedef struct
{
    __IO uint32_t PEWERR                    : 1;
    __IO uint32_t PEPRTERR                  : 1;
    uint32_t RESERVED2                      : 1;
    __IO uint32_t PGMISMTCH                 : 1;
    __IO uint32_t OPTEND                    : 1;
    __IO uint32_t RDCOLERR                  : 1;
    uint32_t RESERVED6                      : 2;
    __IO uint32_t RDY                       : 1;
    uint32_t RESERVED9                      :23;
} stc_efm_fsr_field_t;

typedef struct
{
    __IO uint32_t PEWERRCLR                 : 1;
    __IO uint32_t PEPRTERRCLR               : 1;
    uint32_t RESERVED2                      : 1;
    __IO uint32_t PGMISMTCHCLR              : 1;
    __IO uint32_t OPTENDCLR                 : 1;
    __IO uint32_t RDCOLERRCLR               : 1;
    uint32_t RESERVED6                      :26;
} stc_efm_fsclr_field_t;

typedef struct
{
    __IO uint32_t PEERRITE                  : 1;
    __IO uint32_t OPTENDITE                 : 1;
    __IO uint32_t RDCOLERRITE               : 1;
    uint32_t RESERVED3                      :29;
} stc_efm_fite_field_t;

typedef struct
{
    __IO uint32_t FPMTSW                    :16;
    uint32_t RESERVED16                     :16;
} stc_efm_fpmtsw_field_t;

typedef struct
{
    __IO uint32_t FPMTEW                    :16;
    uint32_t RESERVED16                     :16;
} stc_efm_fpmtew_field_t;

typedef struct
{
    __IO uint8_t HRCFREQS                   : 4;
    uint8_t RESERVED4                       : 4;
} stc_efm_hrccfgr_field_t;

typedef struct
{
    __IO uint16_t DFS                       : 2;
    __IO uint16_t DFDIS                     : 1;
    uint16_t RESERVED3                      : 5;
    __IO uint16_t LVDLVL                    : 4;
    __IO uint16_t NMIS                      : 1;
    __IO uint16_t IRS                       : 1;
    __IO uint16_t IRDIS                     : 1;
    __IO uint16_t LVDDIS                    : 1;
} stc_efm_lvdicgcr_field_t;

typedef struct
{
    __IO uint32_t PE                        : 1;
    __IO uint32_t SMBUS                     : 1;
    __IO uint32_t SMBALRTEN                 : 1;
    __IO uint32_t SMBDEFAULTEN              : 1;
    __IO uint32_t SMBHOSTEN                 : 1;
    __IO uint32_t FACKEN                    : 1;
    __IO uint32_t GCEN                      : 1;
    __IO uint32_t RESTART                   : 1;
    __IO uint32_t START                     : 1;
    __IO uint32_t STOP                      : 1;
    __IO uint32_t ACK                       : 1;
    uint32_t RESERVED11                     : 4;
    __IO uint32_t SWRST                     : 1;
    uint32_t RESERVED16                     :16;
} stc_i2c_cr1_field_t;

typedef struct
{
    __IO uint32_t STARTIE                   : 1;
    __IO uint32_t SLADDR0IE                 : 1;
    __IO uint32_t SLADDR1IE                 : 1;
    __IO uint32_t TENDIE                    : 1;
    __IO uint32_t STOPIE                    : 1;
    uint32_t RESERVED5                      : 1;
    __IO uint32_t RFULLIE                   : 1;
    __IO uint32_t TEMPTYIE                  : 1;
    uint32_t RESERVED8                      : 1;
    __IO uint32_t ARLOIE                    : 1;
    uint32_t RESERVED10                     : 2;
    __IO uint32_t NACKIE                    : 1;
    uint32_t RESERVED13                     : 7;
    __IO uint32_t GENCALLIE                 : 1;
    __IO uint32_t SMBDEFAULTIE              : 1;
    __IO uint32_t SMBHOSTIE                 : 1;
    __IO uint32_t SMBALRTIE                 : 1;
    uint32_t RESERVED24                     : 8;
} stc_i2c_cr2_field_t;

typedef struct
{
    __IO uint32_t SLADDR0                   :10;
    uint32_t RESERVED10                     : 2;
    __IO uint32_t SLADDR0EN                 : 1;
    uint32_t RESERVED13                     : 2;
    __IO uint32_t ADDRMOD0                  : 1;
    uint32_t RESERVED16                     :16;
} stc_i2c_slr0_field_t;

typedef struct
{
    __IO uint32_t SLADDR1                   :10;
    uint32_t RESERVED10                     : 2;
    __IO uint32_t SLADDR1EN                 : 1;
    uint32_t RESERVED13                     : 2;
    __IO uint32_t ADDRMOD1                  : 1;
    uint32_t RESERVED16                     :16;
} stc_i2c_slr1_field_t;

typedef struct
{
    __IO uint32_t STARTF                    : 1;
    __IO uint32_t SLADDR0F                  : 1;
    __IO uint32_t SLADDR1F                  : 1;
    __IO uint32_t TENDF                     : 1;
    __IO uint32_t STOPF                     : 1;
    uint32_t RESERVED5                      : 1;
    __IO uint32_t RFULLF                    : 1;
    __IO uint32_t TEMPTYF                   : 1;
    uint32_t RESERVED8                      : 1;
    __IO uint32_t ARLOF                     : 1;
    __IO uint32_t ACKRF                     : 1;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t NACKF                     : 1;
    uint32_t RESERVED13                     : 3;
    __IO uint32_t MSL                       : 1;
    __IO uint32_t BUSY                      : 1;
    __IO uint32_t TRA                       : 1;
    uint32_t RESERVED19                     : 1;
    __IO uint32_t GENCALLF                  : 1;
    __IO uint32_t SMBDEFAULTF               : 1;
    __IO uint32_t SMBHOSTF                  : 1;
    __IO uint32_t SMBALRTF                  : 1;
    uint32_t RESERVED24                     : 8;
} stc_i2c_sr_field_t;

typedef struct
{
    __IO uint32_t STARTFCLR                 : 1;
    __IO uint32_t SLADDR0FCLR               : 1;
    __IO uint32_t SLADDR1FCLR               : 1;
    __IO uint32_t TENDFCLR                  : 1;
    __IO uint32_t STOPFCLR                  : 1;
    uint32_t RESERVED5                      : 1;
    __IO uint32_t RFULLFCLR                 : 1;
    __IO uint32_t TEMPTYFCLR                : 1;
    uint32_t RESERVED8                      : 1;
    __IO uint32_t ARLOFCLR                  : 1;
    uint32_t RESERVED10                     : 2;
    __IO uint32_t NACKFCLR                  : 1;
    uint32_t RESERVED13                     : 7;
    __IO uint32_t GENCALLFCLR               : 1;
    __IO uint32_t SMBDEFAULTFCLR            : 1;
    __IO uint32_t SMBHOSTFCLR               : 1;
    __IO uint32_t SMBALRTFCLR               : 1;
    uint32_t RESERVED24                     : 8;
} stc_i2c_clr_field_t;

typedef struct
{
    __IO uint8_t DT                         : 8;
} stc_i2c_dtr_field_t;

typedef struct
{
    __IO uint8_t DR                         : 8;
} stc_i2c_drr_field_t;

typedef struct
{
    __IO uint32_t SLOWW                     : 5;
    uint32_t RESERVED5                      : 3;
    __IO uint32_t SHIGHW                    : 5;
    uint32_t RESERVED13                     : 3;
    __IO uint32_t CKDIV                     : 3;
    uint32_t RESERVED19                     :13;
} stc_i2c_ccr_field_t;

typedef struct
{
    __IO uint32_t DNF                       : 2;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t DNFEN                     : 1;
    __IO uint32_t ANFEN                     : 1;
    uint32_t RESERVED6                      :26;
} stc_i2c_fltr_field_t;

typedef struct
{
    __IO uint32_t SWDTAUTS                  : 1;
    __IO uint32_t SWDTITS                   : 1;
    __IO uint32_t SWDTPERI                  : 2;
    __IO uint32_t SWDTCKS                   : 4;
    __IO uint32_t SWDTWDPT                  : 4;
    __IO uint32_t SWDTSLPOFF                : 1;
    uint32_t RESERVED13                     : 3;
    __IO uint32_t HRCREQS                   : 4;
    uint32_t RESERVED20                     : 6;
    __IO uint32_t NMIFCLK                   : 2;
    __IO uint32_t NMIFEN                    : 1;
    __IO uint32_t NMITRG                    : 1;
    __IO uint32_t NMIEN                     : 1;
    __IO uint32_t NMIICGENA                 : 1;
} stc_icg_icg0_field_t;

typedef struct
{
    __IO uint32_t DFS                       : 2;
    __IO uint32_t DFDIS                     : 1;
    uint32_t RESERVED3                      : 5;
    __IO uint32_t LVDLVL                    : 4;
    __IO uint32_t NMIS                      : 1;
    __IO uint32_t IRS                       : 1;
    __IO uint32_t IRDIS                     : 1;
    __IO uint32_t LVDDIS                    : 1;
    uint32_t RESERVED16                     :16;
} stc_icg_icg1_field_t;

typedef struct
{
    __IO uint32_t NMITRG                    : 1;
    uint32_t RESERVED1                      : 3;
    __IO uint32_t NMIFCLK                   : 2;
    uint32_t RESERVED6                      : 1;
    __IO uint32_t NMIFEN                    : 1;
    uint32_t RESERVED8                      :24;
} stc_intc_nmicr_field_t;

typedef struct
{
    __IO uint32_t NMIEN                     : 1;
    __IO uint32_t XTALSTPEN                 : 1;
    __IO uint32_t SWDTEN                    : 1;
    __IO uint32_t PVDEN                     : 1;
    uint32_t RESERVED4                      :28;
} stc_intc_nmier_field_t;

typedef struct
{
    __IO uint32_t NMIF                      : 1;
    __IO uint32_t XTALSTPF                  : 1;
    __IO uint32_t SWDTF                     : 1;
    __IO uint32_t PVDF                      : 1;
    uint32_t RESERVED4                      :28;
} stc_intc_nmifr_field_t;

typedef struct
{
    __IO uint32_t NMICL                     : 1;
    __IO uint32_t XTALSTPCL                 : 1;
    __IO uint32_t SWDTCL                    : 1;
    __IO uint32_t PVDCL                     : 1;
    uint32_t RESERVED4                      :28;
} stc_intc_nmiclr_field_t;

typedef struct
{
    __IO uint32_t EVTEN0                    : 1;
    __IO uint32_t EVTEN1                    : 1;
    __IO uint32_t EVTEN2                    : 1;
    __IO uint32_t EVTEN3                    : 1;
    __IO uint32_t EVTEN4                    : 1;
    __IO uint32_t EVTEN5                    : 1;
    __IO uint32_t EVTEN6                    : 1;
    __IO uint32_t EVTEN7                    : 1;
    uint32_t RESERVED8                      :24;
} stc_intc_evter_field_t;

typedef struct
{
    __IO uint32_t EKEY0EN                   : 1;
    __IO uint32_t EKEY1EN                   : 1;
    __IO uint32_t EKEY2EN                   : 1;
    __IO uint32_t EKEY3EN                   : 1;
    __IO uint32_t EKEY4EN                   : 1;
    __IO uint32_t EKEY5EN                   : 1;
    uint32_t RESERVED6                      :26;
} stc_intc_ekeycr_field_t;

typedef struct
{
    __IO uint32_t FPRC                      : 8;
    uint32_t RESERVED8                      :24;
} stc_intc_fprcr_field_t;

typedef struct
{
    __IO uint32_t EIRQTRG                   : 2;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t EIRQFCLK                  : 2;
    uint32_t RESERVED6                      : 1;
    __IO uint32_t EIRQFEN                   : 1;
    uint32_t RESERVED8                      :24;
} stc_intc_eirqcr_field_t;

typedef struct
{
    __IO uint32_t EIRQWUEN                  :10;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t SWDTWUEN                  : 1;
    __IO uint32_t EKEYWUEN                  : 1;
    __IO uint32_t TMR0CMPWUEN               : 1;
    uint32_t RESERVED19                     : 3;
    __IO uint32_t PVDWUEN                   : 1;
    __IO uint32_t RTCALMWUEN                : 1;
    __IO uint32_t RTCPRDWUEN                : 1;
    uint32_t RESERVED25                     : 7;
} stc_intc_wupenr_field_t;

typedef struct
{
    __IO uint32_t EIRQF                     :10;
    uint32_t RESERVED10                     :22;
} stc_intc_eirqfr_field_t;

typedef struct
{
    __IO uint32_t EIRQCL                    :10;
    uint32_t RESERVED10                     :22;
} stc_intc_eirqclr_field_t;

typedef struct
{
    __IO uint32_t ISEL                      : 4;
    uint32_t RESERVED4                      :28;
} stc_intc_iselar_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 1;
    __IO uint32_t ISEL                      :15;
    uint32_t RESERVED16                     :16;
} stc_intc_iselbr_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_pidr0_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    __IO uint8_t PIN2                       : 1;
    __IO uint8_t PIN3                       : 1;
    __IO uint8_t PIN4                       : 1;
    __IO uint8_t PIN5                       : 1;
    __IO uint8_t PIN6                       : 1;
    __IO uint8_t PIN7                       : 1;
} stc_port_pidr1_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    __IO uint8_t PIN2                       : 1;
    __IO uint8_t PIN3                       : 1;
    __IO uint8_t PIN4                       : 1;
    __IO uint8_t PIN5                       : 1;
    __IO uint8_t PIN6                       : 1;
    __IO uint8_t PIN7                       : 1;
} stc_port_pidr2_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_pidr3_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_pidr4_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_pidr5_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    __IO uint8_t PIN2                       : 1;
    __IO uint8_t PIN3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_pidr6_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    __IO uint8_t PIN2                       : 1;
    __IO uint8_t PIN3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_pidr7_field_t;

typedef struct
{
    __IO uint8_t PIN0                       : 1;
    __IO uint8_t PIN1                       : 1;
    __IO uint8_t PIN2                       : 1;
    __IO uint8_t PIN3                       : 1;
    __IO uint8_t PIN4                       : 1;
    uint8_t RESERVED5                       : 3;
} stc_port_pidr12_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 7;
    __IO uint8_t PIN7                       : 1;
} stc_port_pidr13_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 6;
    __IO uint8_t PIN6                       : 1;
    __IO uint8_t PIN7                       : 1;
} stc_port_pidr14_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_podr0_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    __IO uint8_t POUT2                      : 1;
    __IO uint8_t POUT3                      : 1;
    __IO uint8_t POUT4                      : 1;
    __IO uint8_t POUT5                      : 1;
    __IO uint8_t POUT6                      : 1;
    __IO uint8_t POUT7                      : 1;
} stc_port_podr1_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    __IO uint8_t POUT2                      : 1;
    __IO uint8_t POUT3                      : 1;
    __IO uint8_t POUT4                      : 1;
    __IO uint8_t POUT5                      : 1;
    __IO uint8_t POUT6                      : 1;
    __IO uint8_t POUT7                      : 1;
} stc_port_podr2_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_podr3_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_podr4_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_podr5_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    __IO uint8_t POUT2                      : 1;
    __IO uint8_t POUT3                      : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_podr6_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    __IO uint8_t POUT2                      : 1;
    __IO uint8_t POUT3                      : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_podr7_field_t;

typedef struct
{
    __IO uint8_t POUT0                      : 1;
    __IO uint8_t POUT1                      : 1;
    __IO uint8_t POUT2                      : 1;
    __IO uint8_t POUT3                      : 1;
    __IO uint8_t POUT4                      : 1;
    uint8_t RESERVED5                       : 3;
} stc_port_podr12_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 7;
    __IO uint8_t POUT7                      : 1;
} stc_port_podr13_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 6;
    __IO uint8_t POUT6                      : 1;
    __IO uint8_t POUT7                      : 1;
} stc_port_podr14_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_poer0_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    __IO uint8_t POUTE2                     : 1;
    __IO uint8_t POUTE3                     : 1;
    __IO uint8_t POUTE4                     : 1;
    __IO uint8_t POUTE5                     : 1;
    __IO uint8_t POUTE6                     : 1;
    __IO uint8_t POUTE7                     : 1;
} stc_port_poer1_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    __IO uint8_t POUTE2                     : 1;
    __IO uint8_t POUTE3                     : 1;
    __IO uint8_t POUTE4                     : 1;
    __IO uint8_t POUTE5                     : 1;
    __IO uint8_t POUTE6                     : 1;
    __IO uint8_t POUTE7                     : 1;
} stc_port_poer2_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_poer3_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_poer4_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_poer5_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    __IO uint8_t POUTE2                     : 1;
    __IO uint8_t POUTE3                     : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_poer6_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    __IO uint8_t POUTE2                     : 1;
    __IO uint8_t POUTE3                     : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_poer7_field_t;

typedef struct
{
    __IO uint8_t POUTE0                     : 1;
    __IO uint8_t POUTE1                     : 1;
    __IO uint8_t POUTE2                     : 1;
    __IO uint8_t POUTE3                     : 1;
    __IO uint8_t POUTE4                     : 1;
    uint8_t RESERVED5                       : 3;
} stc_port_poer12_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 7;
    __IO uint8_t POUTE7                     : 1;
} stc_port_poer13_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 6;
    __IO uint8_t POUTE6                     : 1;
    __IO uint8_t POUTE7                     : 1;
} stc_port_poer14_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_posr0_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    __IO uint8_t POS2                       : 1;
    __IO uint8_t POS3                       : 1;
    __IO uint8_t POS4                       : 1;
    __IO uint8_t POS5                       : 1;
    __IO uint8_t POS6                       : 1;
    __IO uint8_t POS7                       : 1;
} stc_port_posr1_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    __IO uint8_t POS2                       : 1;
    __IO uint8_t POS3                       : 1;
    __IO uint8_t POS4                       : 1;
    __IO uint8_t POS5                       : 1;
    __IO uint8_t POS6                       : 1;
    __IO uint8_t POS7                       : 1;
} stc_port_posr2_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_posr3_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_posr4_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_posr5_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    __IO uint8_t POS2                       : 1;
    __IO uint8_t POS3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_posr6_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    __IO uint8_t POS2                       : 1;
    __IO uint8_t POS3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_posr7_field_t;

typedef struct
{
    __IO uint8_t POS0                       : 1;
    __IO uint8_t POS1                       : 1;
    __IO uint8_t POS2                       : 1;
    __IO uint8_t POS3                       : 1;
    __IO uint8_t POS4                       : 1;
    uint8_t RESERVED5                       : 3;
} stc_port_posr12_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 7;
    __IO uint8_t POS7                       : 1;
} stc_port_posr13_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 6;
    __IO uint8_t POS6                       : 1;
    __IO uint8_t POS7                       : 1;
} stc_port_posr14_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_porr0_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    __IO uint8_t POR2                       : 1;
    __IO uint8_t POR3                       : 1;
    __IO uint8_t POR4                       : 1;
    __IO uint8_t POR5                       : 1;
    __IO uint8_t POR6                       : 1;
    __IO uint8_t POR7                       : 1;
} stc_port_porr1_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    __IO uint8_t POR2                       : 1;
    __IO uint8_t POR3                       : 1;
    __IO uint8_t POR4                       : 1;
    __IO uint8_t POR5                       : 1;
    __IO uint8_t POR6                       : 1;
    __IO uint8_t POR7                       : 1;
} stc_port_porr2_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_porr3_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_porr4_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_porr5_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    __IO uint8_t POR2                       : 1;
    __IO uint8_t POR3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_porr6_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    __IO uint8_t POR2                       : 1;
    __IO uint8_t POR3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_porr7_field_t;

typedef struct
{
    __IO uint8_t POR0                       : 1;
    __IO uint8_t POR1                       : 1;
    __IO uint8_t POR2                       : 1;
    __IO uint8_t POR3                       : 1;
    __IO uint8_t POR4                       : 1;
    uint8_t RESERVED5                       : 3;
} stc_port_porr12_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 7;
    __IO uint8_t POR7                       : 1;
} stc_port_porr13_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 6;
    __IO uint8_t POR6                       : 1;
    __IO uint8_t POR7                       : 1;
} stc_port_porr14_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_potr0_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    __IO uint8_t POT2                       : 1;
    __IO uint8_t POT3                       : 1;
    __IO uint8_t POT4                       : 1;
    __IO uint8_t POT5                       : 1;
    __IO uint8_t POT6                       : 1;
    __IO uint8_t POT7                       : 1;
} stc_port_potr1_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    __IO uint8_t POT2                       : 1;
    __IO uint8_t POT3                       : 1;
    __IO uint8_t POT4                       : 1;
    __IO uint8_t POT5                       : 1;
    __IO uint8_t POT6                       : 1;
    __IO uint8_t POT7                       : 1;
} stc_port_potr2_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_potr3_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_potr4_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    uint8_t RESERVED2                       : 6;
} stc_port_potr5_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    __IO uint8_t POT2                       : 1;
    __IO uint8_t POT3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_potr6_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    __IO uint8_t POT2                       : 1;
    __IO uint8_t POT3                       : 1;
    uint8_t RESERVED4                       : 4;
} stc_port_potr7_field_t;

typedef struct
{
    __IO uint8_t POT0                       : 1;
    __IO uint8_t POT1                       : 1;
    __IO uint8_t POT2                       : 1;
    __IO uint8_t POT3                       : 1;
    __IO uint8_t POT4                       : 1;
    uint8_t RESERVED5                       : 3;
} stc_port_potr12_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 7;
    __IO uint8_t POT7                       : 1;
} stc_port_potr13_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 6;
    __IO uint8_t POT6                       : 1;
    __IO uint8_t POT7                       : 1;
} stc_port_potr14_field_t;

typedef struct
{
    __IO uint16_t POUT                      : 1;
    __IO uint16_t POUTE                     : 1;
    __IO uint16_t NOD                       : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t DRV                       : 1;
    __IO uint16_t LTE                       : 1;
    __IO uint16_t PUU                       : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t PIN                       : 1;
    __IO uint16_t INVE                      : 1;
    __IO uint16_t CINSEL                    : 1;
    __IO uint16_t INTE                      : 1;
    __IO uint16_t FSEL                      : 3;
    uint16_t RESERVED15                     : 1;
} stc_port_pcr_field_t;

typedef struct
{
    __IO uint16_t SPFE                      : 2;
    uint16_t RESERVED2                      :14;
} stc_port_pspcr_field_t;

typedef struct
{
    uint16_t RESERVED0                      :14;
    __IO uint16_t RDWT                      : 2;
} stc_port_pccr_field_t;

typedef struct
{
    __IO uint16_t PINAE0                    : 1;
    __IO uint16_t PINAE1                    : 1;
    __IO uint16_t PINAE2                    : 1;
    __IO uint16_t PINAE3                    : 1;
    __IO uint16_t PINAE4                    : 1;
    __IO uint16_t PINAE5                    : 1;
    __IO uint16_t PINAE6                    : 1;
    __IO uint16_t PINAE7                    : 1;
    uint16_t RESERVED8                      : 4;
    __IO uint16_t PINAE12                   : 1;
    __IO uint16_t PINAE13                   : 1;
    __IO uint16_t PINAE14                   : 1;
    uint16_t RESERVED15                     : 1;
} stc_port_pinaer_field_t;

typedef struct
{
    __IO uint16_t WE                        : 1;
    uint16_t RESERVED1                      : 7;
    __IO uint16_t WP                        : 8;
} stc_port_pwpr_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 1;
    __IO uint8_t CKSHRC                     : 1;
    uint8_t RESERVED2                       : 1;
    __IO uint8_t HAPORDIS                   : 1;
    uint8_t RESERVED4                       : 3;
    __IO uint8_t STOP                       : 1;
} stc_pwc_stpmcr_field_t;

typedef struct
{
    __IO uint8_t PWDRV                      : 3;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t PWMONSEL                   : 1;
    __IO uint8_t PWMONE                     : 1;
    uint8_t RESERVED6                       : 2;
} stc_pwc_pwrc_field_t;

typedef struct
{
    __IO uint8_t RPRTA                      : 2;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t RPERDIS                    : 1;
    __IO uint8_t RPEF                       : 1;
    uint8_t RESERVED6                       : 2;
} stc_pwc_ramcr_field_t;

typedef struct
{
    __IO uint8_t EXVCCINEN                  : 1;
    uint8_t RESERVED1                       : 2;
    __IO uint8_t LVIF                       : 1;
    __IO uint8_t DETF                       : 1;
    uint8_t RESERVED5                       : 2;
    __IO uint8_t CMPOE                      : 1;
} stc_pwc_lvdcsr_field_t;

typedef struct
{
    __IO uint16_t CKRWE                     : 1;
    __IO uint16_t PWRWE                     : 1;
    __IO uint16_t FPRCB2                    : 1;
    __IO uint16_t LVRWE                     : 1;
    __IO uint16_t FPRCB4                    : 1;
    __IO uint16_t FPRCB5                    : 1;
    __IO uint16_t FPRCB6                    : 1;
    __IO uint16_t FPRCB7                    : 1;
    __IO uint16_t FPRCWE                    : 8;
} stc_pwc_fprc_field_t;

typedef struct
{
    __IO uint8_t DBGEN                      : 1;
    uint8_t RESERVED1                       : 7;
} stc_pwc_dbgc_field_t;

typedef struct
{
    __IO uint16_t PORF                      : 1;
    __IO uint16_t PINRF                     : 1;
    __IO uint16_t LVRF                      : 1;
    uint16_t RESERVED3                      : 2;
    __IO uint16_t WDRF                      : 1;
    uint16_t RESERVED6                      : 2;
    __IO uint16_t SWRF                      : 1;
    uint16_t RESERVED9                      : 1;
    __IO uint16_t RAMPERF                   : 1;
    uint16_t RESERVED11                     : 1;
    __IO uint16_t CPULKUPRF                 : 1;
    __IO uint16_t XTALERF                   : 1;
    __IO uint16_t MULTIRF                   : 1;
    __IO uint16_t CLRF                      : 1;
} stc_rmu_rstf0_field_t;

typedef struct
{
    __IO uint8_t RESET                      : 1;
    uint8_t RESERVED1                       : 7;
} stc_rtc_cr0_field_t;

typedef struct
{
    __IO uint8_t PRDS                       : 3;
    __IO uint8_t AMPM                       : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t ONEHZOE                    : 1;
    uint8_t RESERVED6                       : 1;
    __IO uint8_t START                      : 1;
} stc_rtc_cr1_field_t;

typedef struct
{
    __IO uint8_t WAIT                       : 1;
    __IO uint8_t WAITF                      : 1;
    __IO uint8_t PRDF                       : 1;
    __IO uint8_t ALMF                       : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t PRDIE                      : 1;
    __IO uint8_t ALMIE                      : 1;
    __IO uint8_t ALME                       : 1;
} stc_rtc_cr2_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 4;
    __IO uint8_t LRCEN                      : 1;
    uint8_t RESERVED5                       : 2;
    __IO uint8_t RCKSEL                     : 1;
} stc_rtc_cr3_field_t;

typedef struct
{
    __IO uint8_t SECU                       : 4;
    __IO uint8_t SECD                       : 3;
    uint8_t RESERVED7                       : 1;
} stc_rtc_sec_field_t;

typedef struct
{
    __IO uint8_t MINU                       : 4;
    __IO uint8_t MIND                       : 3;
    uint8_t RESERVED7                       : 1;
} stc_rtc_min_field_t;

typedef struct
{
    __IO uint8_t HOURU                      : 4;
    __IO uint8_t HOURD                      : 2;
    uint8_t RESERVED6                       : 2;
} stc_rtc_hour_field_t;

typedef struct
{
    __IO uint8_t WEEK                       : 3;
    uint8_t RESERVED3                       : 5;
} stc_rtc_week_field_t;

typedef struct
{
    __IO uint8_t DAYU                       : 4;
    __IO uint8_t DAYD                       : 2;
    uint8_t RESERVED6                       : 2;
} stc_rtc_day_field_t;

typedef struct
{
    __IO uint8_t MON                        : 5;
    uint8_t RESERVED5                       : 3;
} stc_rtc_mon_field_t;

typedef struct
{
    __IO uint8_t YEARU                      : 4;
    __IO uint8_t YEARD                      : 4;
} stc_rtc_year_field_t;

typedef struct
{
    __IO uint8_t ALMMINU                    : 4;
    __IO uint8_t ALMMIND                    : 3;
    uint8_t RESERVED7                       : 1;
} stc_rtc_almmin_field_t;

typedef struct
{
    __IO uint8_t ALMHOURU                   : 4;
    __IO uint8_t ALMHOURD                   : 2;
    uint8_t RESERVED6                       : 2;
} stc_rtc_almhour_field_t;

typedef struct
{
    __IO uint8_t ALMWEEK                    : 7;
    uint8_t RESERVED7                       : 1;
} stc_rtc_almweek_field_t;

typedef struct
{
    __IO uint8_t COMP8                      : 1;
    uint8_t RESERVED1                       : 6;
    __IO uint8_t COMPEN                     : 1;
} stc_rtc_errcrh_field_t;

typedef struct
{
    __IO uint8_t COMP                       : 8;
} stc_rtc_errcrl_field_t;

typedef struct
{
    __IO uint32_t SPD                       :16;
    uint32_t RESERVED16                     :16;
} stc_spi_dr_field_t;

typedef struct
{
    __IO uint32_t SPIMDS                    : 1;
    __IO uint32_t TXMDS                     : 1;
    uint32_t RESERVED2                      : 1;
    __IO uint32_t MSTR                      : 1;
    __IO uint32_t SPLPBK                    : 1;
    __IO uint32_t SPLPBK2                   : 1;
    __IO uint32_t SPE                       : 1;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t EIE                       : 1;
    __IO uint32_t TXIE                      : 1;
    __IO uint32_t RXIE                      : 1;
    __IO uint32_t IDIE                      : 1;
    __IO uint32_t MODFE                     : 1;
    __IO uint32_t PATE                      : 1;
    __IO uint32_t PAOE                      : 1;
    __IO uint32_t PAE                       : 1;
    uint32_t RESERVED16                     :16;
} stc_spi_cr1_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 8;
    __IO uint32_t SS0PV                     : 1;
    uint32_t RESERVED9                      :23;
} stc_spi_cfg1_field_t;

typedef struct
{
    __IO uint32_t OVRERF                    : 1;
    __IO uint32_t IDLNF                     : 1;
    __IO uint32_t MODFERF                   : 1;
    __IO uint32_t PERF                      : 1;
    __IO uint32_t UDRERF                    : 1;
    __IO uint32_t TDEF                      : 1;
    uint32_t RESERVED6                      : 1;
    __IO uint32_t RDFF                      : 1;
    uint32_t RESERVED8                      :24;
} stc_spi_sr_field_t;

typedef struct
{
    __IO uint32_t CPHA                      : 1;
    __IO uint32_t CPOL                      : 1;
    __IO uint32_t MBR                       : 3;
    uint32_t RESERVED5                      : 3;
    __IO uint32_t DSIZE                     : 1;
    uint32_t RESERVED9                      : 2;
    __IO uint32_t LSBF                      : 1;
    uint32_t RESERVED12                     :20;
} stc_spi_cfg2_field_t;

typedef struct
{
    __IO uint32_t PERI                      : 2;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t CKS                       : 4;
    __IO uint32_t WDPT                      : 4;
    uint32_t RESERVED12                     : 4;
    __IO uint32_t SLPOFF                    : 1;
    uint32_t RESERVED17                     :14;
    __IO uint32_t ITS                       : 1;
} stc_swdt_cr_field_t;

typedef struct
{
    __IO uint32_t CNT                       :16;
    __IO uint32_t UDF                       : 1;
    __IO uint32_t REF                       : 1;
    uint32_t RESERVED18                     :14;
} stc_swdt_sr_field_t;

typedef struct
{
    __IO uint32_t RF                        :16;
    uint32_t RESERVED16                     :16;
} stc_swdt_rr_field_t;

typedef struct
{
    __IO uint32_t CNTA                      :16;
    uint32_t RESERVED16                     :16;
} stc_tmr0_cntar_field_t;

typedef struct
{
    __IO uint32_t CMPA                      :16;
    uint32_t RESERVED16                     :16;
} stc_tmr0_cmpar_field_t;

typedef struct
{
    __IO uint32_t CSTA                      : 1;
    __IO uint32_t CAPMDA                    : 1;
    __IO uint32_t INTENA                    : 1;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t CKDIVA                    : 4;
    __IO uint32_t SYNSA                     : 1;
    __IO uint32_t SYNCLKA                   : 1;
    __IO uint32_t ASYNCLKA                  : 1;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t HSTAA                     : 1;
    __IO uint32_t HSTPA                     : 1;
    __IO uint32_t HCLEA                     : 1;
    __IO uint32_t HICPA                     : 1;
    uint32_t RESERVED16                     :16;
} stc_tmr0_bconr_field_t;

typedef struct
{
    __IO uint32_t CMFA                      : 1;
    uint32_t RESERVED1                      :31;
} stc_tmr0_stflr_field_t;

typedef struct
{
    __IO uint16_t CNT                       :16;
} stc_tmrb_cnter_field_t;

typedef struct
{
    __IO uint16_t PER                       :16;
} stc_tmrb_perar_field_t;

typedef struct
{
    __IO uint16_t CMP                       :16;
} stc_tmrb_cmpar_field_t;

typedef struct
{
    __IO uint16_t START                     : 1;
    __IO uint16_t DIR                       : 1;
    __IO uint16_t MODE                      : 1;
    __IO uint16_t SYNST                     : 1;
    __IO uint16_t CKDIV                     : 4;
    __IO uint16_t OVSTP                     : 1;
    uint16_t RESERVED9                      : 3;
    __IO uint16_t INENOVF                   : 1;
    __IO uint16_t INENUDF                   : 1;
    __IO uint16_t OVFF                      : 1;
    __IO uint16_t UDFF                      : 1;
} stc_tmrb_bcstr_field_t;

typedef struct
{
    __IO uint16_t HSTA0                     : 1;
    __IO uint16_t HSTA1                     : 1;
    __IO uint16_t HSTA2                     : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t HSTP0                     : 1;
    __IO uint16_t HSTP1                     : 1;
    __IO uint16_t HSTP2                     : 1;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t HCLE0                     : 1;
    __IO uint16_t HCLE1                     : 1;
    __IO uint16_t HCLE2                     : 1;
    uint16_t RESERVED11                     : 1;
    __IO uint16_t HCLE3                     : 1;
    __IO uint16_t HCLE4                     : 1;
    uint16_t RESERVED14                     : 2;
} stc_tmrb_hconr_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 8;
    __IO uint16_t HCUP8                     : 1;
    __IO uint16_t HCUP9                     : 1;
    __IO uint16_t HCUP10                    : 1;
    __IO uint16_t HCUP11                    : 1;
    __IO uint16_t HCUP12                    : 1;
    uint16_t RESERVED13                     : 3;
} stc_tmrb_hcupr_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 8;
    __IO uint16_t HCDO8                     : 1;
    __IO uint16_t HCDO9                     : 1;
    __IO uint16_t HCDO10                    : 1;
    __IO uint16_t HCDO11                    : 1;
    __IO uint16_t HCDO12                    : 1;
    uint16_t RESERVED13                     : 3;
} stc_tmrb_hcdor_field_t;

typedef struct
{
    __IO uint16_t ITEN1                     : 1;
    uint16_t RESERVED1                      :15;
} stc_tmrb_iconr_field_t;

typedef struct
{
    __IO uint16_t ETEN1                     : 1;
    uint16_t RESERVED1                      :15;
} stc_tmrb_econr_field_t;

typedef struct
{
    __IO uint16_t CMPF1                     : 1;
    uint16_t RESERVED1                      :15;
} stc_tmrb_stflr_field_t;

typedef struct
{
    __IO uint16_t CAPMDA                    : 1;
    uint16_t RESERVED1                      : 3;
    __IO uint16_t HICP0                     : 1;
    __IO uint16_t HICP1                     : 1;
    __IO uint16_t HICP2                     : 1;
    uint16_t RESERVED7                      : 5;
    __IO uint16_t NOFIENCP                  : 1;
    __IO uint16_t NOFICKCP                  : 2;
    uint16_t RESERVED15                     : 1;
} stc_tmrb_cconr_field_t;

typedef struct
{
    __IO uint16_t STAC                      : 2;
    __IO uint16_t STPC                      : 2;
    __IO uint16_t CMPC                      : 2;
    __IO uint16_t PERC                      : 2;
    __IO uint16_t FORC                      : 2;
    uint16_t RESERVED10                     : 2;
    __IO uint16_t OUTEN                     : 1;
    uint16_t RESERVED13                     : 3;
} stc_tmrb_pconr_field_t;

typedef struct
{
    __IO uint32_t PE                        : 1;
    __IO uint32_t FE                        : 1;
    uint32_t RESERVED2                      : 1;
    __IO uint32_t ORE                       : 1;
    uint32_t RESERVED4                      : 1;
    __IO uint32_t RXNE                      : 1;
    __IO uint32_t TC                        : 1;
    __IO uint32_t TXE                       : 1;
    uint32_t RESERVED8                      : 8;
    __IO uint32_t MPB                       : 1;
    uint32_t RESERVED17                     :15;
} stc_usart_sr_field_t;

typedef struct
{
    __IO uint32_t TDR                       : 9;
    __IO uint32_t MPID                      : 1;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t RDR                       : 9;
    uint32_t RESERVED25                     : 7;
} stc_usart_dr_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 8;
    __IO uint32_t DIV_INTEGER               : 8;
    uint32_t RESERVED16                     :16;
} stc_usart_brr_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 2;
    __IO uint32_t RE                        : 1;
    __IO uint32_t TE                        : 1;
    __IO uint32_t SLME                      : 1;
    __IO uint32_t RIE                       : 1;
    __IO uint32_t TCIE                      : 1;
    __IO uint32_t TXEIE                     : 1;
    uint32_t RESERVED8                      : 1;
    __IO uint32_t PS                        : 1;
    __IO uint32_t PCE                       : 1;
    uint32_t RESERVED11                     : 1;
    __IO uint32_t M                         : 1;
    uint32_t RESERVED13                     : 2;
    __IO uint32_t OVER8                     : 1;
    __IO uint32_t CPE                       : 1;
    __IO uint32_t CFE                       : 1;
    uint32_t RESERVED18                     : 1;
    __IO uint32_t CORE                      : 1;
    uint32_t RESERVED20                     : 4;
    __IO uint32_t MS                        : 1;
    uint32_t RESERVED25                     : 3;
    __IO uint32_t ML                        : 1;
    uint32_t RESERVED29                     : 1;
    __IO uint32_t NFE                       : 1;
    __IO uint32_t SBS                       : 1;
} stc_usart_cr1_field_t;

typedef struct
{
    __IO uint32_t MPE                       : 1;
    uint32_t RESERVED1                      :10;
    __IO uint32_t CLKC                      : 2;
    __IO uint32_t STOP                      : 1;
    __IO uint32_t LINEN                     : 1;
    uint32_t RESERVED15                     :17;
} stc_usart_cr2_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 3;
    __IO uint32_t HDSEL                     : 1;
    uint32_t RESERVED4                      : 5;
    __IO uint32_t CTSE                      : 1;
    uint32_t RESERVED10                     :22;
} stc_usart_cr3_field_t;

typedef struct
{
    __IO uint32_t PSC                       : 2;
    uint32_t RESERVED2                      :30;
} stc_usart_pr_field_t;


/**
 * @brief ADC
 */
typedef struct
{
    union
    {
        __IO uint8_t STR;
        stc_adc_str_field_t STR_f;
    };
    uint8_t RESERVED0[1];
    union
    {
        __IO uint16_t CR0;
        stc_adc_cr0_field_t CR0_f;
    };
    union
    {
        __IO uint16_t CR1;
        stc_adc_cr1_field_t CR1_f;
    };
    uint8_t RESERVED1[4];
    union
    {
        __IO uint16_t TRGSR;
        stc_adc_trgsr_field_t TRGSR_f;
    };
    union
    {
        __IO uint16_t CHSELRA0;
        stc_adc_chselra0_field_t CHSELRA0_f;
    };
    uint8_t RESERVED2[2];
    union
    {
        __IO uint16_t CHSELRB0;
        stc_adc_chselrb0_field_t CHSELRB0_f;
    };
    uint8_t RESERVED3[6];
    union
    {
        __IO uint8_t EXCHSELR;
        stc_adc_exchselr_field_t EXCHSELR_f;
    };
    uint8_t RESERVED4[7];
    __IO uint8_t SSTR;
    uint8_t RESERVED5[35];
    union
    {
        __IO uint8_t ISR;
        stc_adc_isr_field_t ISR_f;
    };
    union
    {
        __IO uint8_t ICR;
        stc_adc_icr_field_t ICR_f;
    };
    union
    {
        __IO uint8_t ISCLRR;
        stc_adc_isclrr_field_t ISCLRR_f;
    };
    uint8_t RESERVED6[9];
    __IO uint16_t DR0;
    __IO uint16_t DR1;
    __IO uint16_t DR2;
    __IO uint16_t DR3;
    __IO uint16_t DR4;
    __IO uint16_t DR5;
    __IO uint16_t DR6;
    __IO uint16_t DR7;
    __IO uint16_t DR8;
    __IO uint16_t DR9;
    __IO uint16_t DR10;
    __IO uint16_t DR11;
    uint8_t RESERVED7[56];
    union
    {
        __IO uint16_t AWDCR;
        stc_adc_awdcr_field_t AWDCR_f;
    };
    union
    {
        __IO uint8_t AWDSR;
        stc_adc_awdsr_field_t AWDSR_f;
    };
    union
    {
        __IO uint8_t AWDSCLRR;
        stc_adc_awdsclrr_field_t AWDSCLRR_f;
    };
    __IO uint16_t AWD0DR0;
    __IO uint16_t AWD0DR1;
    union
    {
        __IO uint8_t AWD0CHSR;
        stc_adc_awd0chsr_field_t AWD0CHSR_f;
    };
    uint8_t RESERVED8[3];
    __IO uint16_t AWD1DR0;
    __IO uint16_t AWD1DR1;
    union
    {
        __IO uint8_t AWD1CHSR;
        stc_adc_awd1chsr_field_t AWD1CHSR_f;
    };
} M0P_ADC_TypeDef;

/**
 * @brief AOS
 */
typedef struct
{
    union
    {
        __IO uint32_t INTC_STRGCR;
        stc_aos_intc_strgcr_field_t INTC_STRGCR_f;
    };
    uint8_t RESERVED0[28];
    union
    {
        __IO uint32_t TMR0_HTSSR;
        stc_aos_tmr0_htssr_field_t TMR0_HTSSR_f;
    };
    uint8_t RESERVED1[44];
    union
    {
        __IO uint32_t TMRB_HTSSR;
        stc_aos_tmrb_htssr_field_t TMRB_HTSSR_f;
    };
    uint8_t RESERVED2[12];
    union
    {
        __IO uint32_t ADC_ITRGSELR0;
        stc_aos_adc_itrgselr0_field_t ADC_ITRGSELR0_f;
    };
    union
    {
        __IO uint32_t ADC_ITRGSELR1;
        stc_aos_adc_itrgselr1_field_t ADC_ITRGSELR1_f;
    };
} M0P_AOS_TypeDef;

/**
 * @brief CMU
 */
typedef struct
{
    union
    {
        __IO uint8_t PERICKSEL;
        stc_cmu_pericksel_field_t PERICKSEL_f;
    };
    uint8_t RESERVED0[3];
    union
    {
        __IO uint8_t XTALSTDSR;
        stc_cmu_xtalstdsr_field_t XTALSTDSR_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t SCKDIVR;
        stc_cmu_sckdivr_field_t SCKDIVR_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t CKSWR;
        stc_cmu_ckswr_field_t CKSWR_f;
    };
    uint8_t RESERVED3[3];
    union
    {
        __IO uint8_t XTALCR;
        stc_cmu_xtalcr_field_t XTALCR_f;
    };
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t XTALCFGR;
        stc_cmu_xtalcfgr_field_t XTALCFGR_f;
    };
    union
    {
        __IO uint8_t XTALSTBCR;
        stc_cmu_xtalstbcr_field_t XTALSTBCR_f;
    };
    uint8_t RESERVED5[2];
    union
    {
        __IO uint8_t HRCCR;
        stc_cmu_hrccr_field_t HRCCR_f;
    };
    uint8_t RESERVED6[7];
    union
    {
        __IO uint8_t OSCSTBSR;
        stc_cmu_oscstbsr_field_t OSCSTBSR_f;
    };
    uint8_t RESERVED7[3];
    union
    {
        __IO uint8_t MCO1CFGR;
        stc_cmu_mco1cfgr_field_t MCO1CFGR_f;
    };
    uint8_t RESERVED8[3];
    union
    {
        __IO uint8_t XTALSTDCR;
        stc_cmu_xtalstdcr_field_t XTALSTDCR_f;
    };
    uint8_t RESERVED9[7];
    union
    {
        __IO uint32_t FCG;
        stc_cmu_fcg_field_t FCG_f;
    };
    union
    {
        __IO uint8_t XTAL32CR;
        stc_cmu_xtal32cr_field_t XTAL32CR_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t XTAL32CFGR;
        stc_cmu_xtal32cfgr_field_t XTAL32CFGR_f;
    };
    union
    {
        __IO uint8_t XTAL32NFR;
        stc_cmu_xtal32nfr_field_t XTAL32NFR_f;
    };
    uint8_t RESERVED11[2];
    union
    {
        __IO uint8_t LRCCR;
        stc_cmu_lrccr_field_t LRCCR_f;
    };
} M0P_CMU_TypeDef;

/**
 * @brief CRC
 */
typedef struct
{
    union
    {
        __IO uint32_t CR;
        stc_crc_cr_field_t CR_f;
    };
    __IO uint32_t RESLT;
    uint8_t RESERVED0[120];
    __IO uint32_t DAT0;
    __IO uint32_t DAT1;
    __IO uint32_t DAT2;
    __IO uint32_t DAT3;
    __IO uint32_t DAT4;
    __IO uint32_t DAT5;
    __IO uint32_t DAT6;
    __IO uint32_t DAT7;
    __IO uint32_t DAT8;
    __IO uint32_t DAT9;
    __IO uint32_t DAT10;
    __IO uint32_t DAT11;
    __IO uint32_t DAT12;
    __IO uint32_t DAT13;
    __IO uint32_t DAT14;
    __IO uint32_t DAT15;
    __IO uint32_t DAT16;
    __IO uint32_t DAT17;
    __IO uint32_t DAT18;
    __IO uint32_t DAT19;
    __IO uint32_t DAT20;
    __IO uint32_t DAT21;
    __IO uint32_t DAT22;
    __IO uint32_t DAT23;
    __IO uint32_t DAT24;
    __IO uint32_t DAT25;
    __IO uint32_t DAT26;
    __IO uint32_t DAT27;
    __IO uint32_t DAT28;
    __IO uint32_t DAT29;
    __IO uint32_t DAT30;
    __IO uint32_t DAT31;
} M0P_CRC_TypeDef;

/**
 * @brief CTC
 */
typedef struct
{
    union
    {
        __IO uint32_t CR1;
        stc_ctc_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t CR2;
        stc_ctc_cr2_field_t CR2_f;
    };
    union
    {
        __IO uint32_t STR;
        stc_ctc_str_field_t STR_f;
    };
} M0P_CTC_TypeDef;

/**
 * @brief DBGC
 */
typedef struct
{
    union
    {
        __IO uint32_t MCUDBGSTAT;
        stc_dbgc_mcudbgstat_field_t MCUDBGSTAT_f;
    };
    union
    {
        __IO uint32_t MCUSTPCTL;
        stc_dbgc_mcustpctl_field_t MCUSTPCTL_f;
    };
} M0P_DBGC_TypeDef;

/**
 * @brief EFM
 */
typedef struct
{
    union
    {
        __IO uint32_t FAPRT;
        stc_efm_faprt_field_t FAPRT_f;
    };
    union
    {
        __IO uint32_t FSTP;
        stc_efm_fstp_field_t FSTP_f;
    };
    union
    {
        __IO uint32_t FRMC;
        stc_efm_frmc_field_t FRMC_f;
    };
    union
    {
        __IO uint32_t FWMC;
        stc_efm_fwmc_field_t FWMC_f;
    };
    union
    {
        __IO uint32_t FSR;
        stc_efm_fsr_field_t FSR_f;
    };
    union
    {
        __IO uint32_t FSCLR;
        stc_efm_fsclr_field_t FSCLR_f;
    };
    union
    {
        __IO uint32_t FITE;
        stc_efm_fite_field_t FITE_f;
    };
    uint8_t RESERVED0[4];
    union
    {
        __IO uint32_t FPMTSW;
        stc_efm_fpmtsw_field_t FPMTSW_f;
    };
    union
    {
        __IO uint32_t FPMTEW;
        stc_efm_fpmtew_field_t FPMTEW_f;
    };
    uint8_t RESERVED1[40];
    __IO uint32_t UQID0;
    __IO uint32_t UQID1;
    __IO uint32_t UQID2;
    uint8_t RESERVED2[550];
    union
    {
        __IO uint8_t HRCCFGR;
        stc_efm_hrccfgr_field_t HRCCFGR_f;
    };
    uint8_t RESERVED3[1];
    union
    {
        __IO uint16_t LVDICGCR;
        stc_efm_lvdicgcr_field_t LVDICGCR_f;
    };
} M0P_EFM_TypeDef;

/**
 * @brief I2C
 */
typedef struct
{
    union
    {
        __IO uint32_t CR1;
        stc_i2c_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t CR2;
        stc_i2c_cr2_field_t CR2_f;
    };
    uint8_t RESERVED0[8];
    union
    {
        __IO uint32_t SLR0;
        stc_i2c_slr0_field_t SLR0_f;
    };
    union
    {
        __IO uint32_t SLR1;
        stc_i2c_slr1_field_t SLR1_f;
    };
    uint8_t RESERVED1[4];
    union
    {
        __IO uint32_t SR;
        stc_i2c_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t CLR;
        stc_i2c_clr_field_t CLR_f;
    };
    union
    {
        __IO uint8_t DTR;
        stc_i2c_dtr_field_t DTR_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t DRR;
        stc_i2c_drr_field_t DRR_f;
    };
    uint8_t RESERVED3[3];
    union
    {
        __IO uint32_t CCR;
        stc_i2c_ccr_field_t CCR_f;
    };
    union
    {
        __IO uint32_t FLTR;
        stc_i2c_fltr_field_t FLTR_f;
    };
} M0P_I2C_TypeDef;

/**
 * @brief ICG
 */
typedef struct
{
    union
    {
        __IO uint32_t ICG0;
        stc_icg_icg0_field_t ICG0_f;
    };
    union
    {
        __IO uint32_t ICG1;
        stc_icg_icg1_field_t ICG1_f;
    };
    __IO uint32_t ICG2;
    __IO uint32_t ICG3;
    __IO uint32_t ICG4;
    __IO uint32_t ICG5;
    __IO uint32_t ICG6;
} M0P_ICG_TypeDef;

/**
 * @brief INTC
 */
typedef struct
{
    union
    {
        __IO uint32_t NMICR;
        stc_intc_nmicr_field_t NMICR_f;
    };
    union
    {
        __IO uint32_t NMIER;
        stc_intc_nmier_field_t NMIER_f;
    };
    union
    {
        __IO uint32_t NMIFR;
        stc_intc_nmifr_field_t NMIFR_f;
    };
    union
    {
        __IO uint32_t NMICLR;
        stc_intc_nmiclr_field_t NMICLR_f;
    };
    uint8_t RESERVED0[16];
    union
    {
        __IO uint32_t EVTER;
        stc_intc_evter_field_t EVTER_f;
    };
    union
    {
        __IO uint32_t EKEYCR;
        stc_intc_ekeycr_field_t EKEYCR_f;
    };
    uint8_t RESERVED1[20];
    union
    {
        __IO uint32_t FPRCR;
        stc_intc_fprcr_field_t FPRCR_f;
    };
    union
    {
        __IO uint32_t EIRQCR0;
        stc_intc_eirqcr_field_t EIRQCR0_f;
    };
    union
    {
        __IO uint32_t EIRQCR1;
        stc_intc_eirqcr_field_t EIRQCR1_f;
    };
    union
    {
        __IO uint32_t EIRQCR2;
        stc_intc_eirqcr_field_t EIRQCR2_f;
    };
    union
    {
        __IO uint32_t EIRQCR3;
        stc_intc_eirqcr_field_t EIRQCR3_f;
    };
    union
    {
        __IO uint32_t EIRQCR4;
        stc_intc_eirqcr_field_t EIRQCR4_f;
    };
    union
    {
        __IO uint32_t EIRQCR5;
        stc_intc_eirqcr_field_t EIRQCR5_f;
    };
    union
    {
        __IO uint32_t EIRQCR6;
        stc_intc_eirqcr_field_t EIRQCR6_f;
    };
    union
    {
        __IO uint32_t EIRQCR7;
        stc_intc_eirqcr_field_t EIRQCR7_f;
    };
    union
    {
        __IO uint32_t EIRQCR8;
        stc_intc_eirqcr_field_t EIRQCR8_f;
    };
    union
    {
        __IO uint32_t EIRQCR9;
        stc_intc_eirqcr_field_t EIRQCR9_f;
    };
    uint8_t RESERVED2[8];
    union
    {
        __IO uint32_t WUPENR;
        stc_intc_wupenr_field_t WUPENR_f;
    };
    union
    {
        __IO uint32_t EIRQFR;
        stc_intc_eirqfr_field_t EIRQFR_f;
    };
    union
    {
        __IO uint32_t EIRQCLR;
        stc_intc_eirqclr_field_t EIRQCLR_f;
    };
    uint8_t RESERVED3[36];
    union
    {
        __IO uint32_t ISELAR8;
        stc_intc_iselar_field_t ISELAR8_f;
    };
    union
    {
        __IO uint32_t ISELAR9;
        stc_intc_iselar_field_t ISELAR9_f;
    };
    union
    {
        __IO uint32_t ISELAR10;
        stc_intc_iselar_field_t ISELAR10_f;
    };
    union
    {
        __IO uint32_t ISELAR11;
        stc_intc_iselar_field_t ISELAR11_f;
    };
    union
    {
        __IO uint32_t ISELAR12;
        stc_intc_iselar_field_t ISELAR12_f;
    };
    union
    {
        __IO uint32_t ISELAR13;
        stc_intc_iselar_field_t ISELAR13_f;
    };
    union
    {
        __IO uint32_t ISELAR14;
        stc_intc_iselar_field_t ISELAR14_f;
    };
    union
    {
        __IO uint32_t ISELAR15;
        stc_intc_iselar_field_t ISELAR15_f;
    };
    union
    {
        __IO uint32_t ISELAR16;
        stc_intc_iselar_field_t ISELAR16_f;
    };
    union
    {
        __IO uint32_t ISELAR17;
        stc_intc_iselar_field_t ISELAR17_f;
    };
    union
    {
        __IO uint32_t ISELAR18;
        stc_intc_iselar_field_t ISELAR18_f;
    };
    union
    {
        __IO uint32_t ISELAR19;
        stc_intc_iselar_field_t ISELAR19_f;
    };
    union
    {
        __IO uint32_t ISELAR20;
        stc_intc_iselar_field_t ISELAR20_f;
    };
    union
    {
        __IO uint32_t ISELAR21;
        stc_intc_iselar_field_t ISELAR21_f;
    };
    union
    {
        __IO uint32_t ISELAR22;
        stc_intc_iselar_field_t ISELAR22_f;
    };
    union
    {
        __IO uint32_t ISELAR23;
        stc_intc_iselar_field_t ISELAR23_f;
    };
    union
    {
        __IO uint32_t ISELBR24;
        stc_intc_iselbr_field_t ISELBR24_f;
    };
    union
    {
        __IO uint32_t ISELBR25;
        stc_intc_iselbr_field_t ISELBR25_f;
    };
    union
    {
        __IO uint32_t ISELBR26;
        stc_intc_iselbr_field_t ISELBR26_f;
    };
    union
    {
        __IO uint32_t ISELBR27;
        stc_intc_iselbr_field_t ISELBR27_f;
    };
    union
    {
        __IO uint32_t ISELBR28;
        stc_intc_iselbr_field_t ISELBR28_f;
    };
    union
    {
        __IO uint32_t ISELBR29;
        stc_intc_iselbr_field_t ISELBR29_f;
    };
    union
    {
        __IO uint32_t ISELBR30;
        stc_intc_iselbr_field_t ISELBR30_f;
    };
    union
    {
        __IO uint32_t ISELBR31;
        stc_intc_iselbr_field_t ISELBR31_f;
    };
} M0P_INTC_TypeDef;

/**
 * @brief PORT
 */
typedef struct
{
    union
    {
        __IO uint8_t PIDR0;
        stc_port_pidr0_field_t PIDR0_f;
    };
    union
    {
        __IO uint8_t PIDR1;
        stc_port_pidr1_field_t PIDR1_f;
    };
    union
    {
        __IO uint8_t PIDR2;
        stc_port_pidr2_field_t PIDR2_f;
    };
    union
    {
        __IO uint8_t PIDR3;
        stc_port_pidr3_field_t PIDR3_f;
    };
    union
    {
        __IO uint8_t PIDR4;
        stc_port_pidr4_field_t PIDR4_f;
    };
    union
    {
        __IO uint8_t PIDR5;
        stc_port_pidr5_field_t PIDR5_f;
    };
    union
    {
        __IO uint8_t PIDR6;
        stc_port_pidr6_field_t PIDR6_f;
    };
    union
    {
        __IO uint8_t PIDR7;
        stc_port_pidr7_field_t PIDR7_f;
    };
    uint8_t RESERVED0[4];
    union
    {
        __IO uint8_t PIDR12;
        stc_port_pidr12_field_t PIDR12_f;
    };
    union
    {
        __IO uint8_t PIDR13;
        stc_port_pidr13_field_t PIDR13_f;
    };
    union
    {
        __IO uint8_t PIDR14;
        stc_port_pidr14_field_t PIDR14_f;
    };
    uint8_t RESERVED1[1];
    union
    {
        __IO uint8_t PODR0;
        stc_port_podr0_field_t PODR0_f;
    };
    union
    {
        __IO uint8_t PODR1;
        stc_port_podr1_field_t PODR1_f;
    };
    union
    {
        __IO uint8_t PODR2;
        stc_port_podr2_field_t PODR2_f;
    };
    union
    {
        __IO uint8_t PODR3;
        stc_port_podr3_field_t PODR3_f;
    };
    union
    {
        __IO uint8_t PODR4;
        stc_port_podr4_field_t PODR4_f;
    };
    union
    {
        __IO uint8_t PODR5;
        stc_port_podr5_field_t PODR5_f;
    };
    union
    {
        __IO uint8_t PODR6;
        stc_port_podr6_field_t PODR6_f;
    };
    union
    {
        __IO uint8_t PODR7;
        stc_port_podr7_field_t PODR7_f;
    };
    uint8_t RESERVED2[4];
    union
    {
        __IO uint8_t PODR12;
        stc_port_podr12_field_t PODR12_f;
    };
    union
    {
        __IO uint8_t PODR13;
        stc_port_podr13_field_t PODR13_f;
    };
    union
    {
        __IO uint8_t PODR14;
        stc_port_podr14_field_t PODR14_f;
    };
    uint8_t RESERVED3[1];
    union
    {
        __IO uint8_t POER0;
        stc_port_poer0_field_t POER0_f;
    };
    union
    {
        __IO uint8_t POER1;
        stc_port_poer1_field_t POER1_f;
    };
    union
    {
        __IO uint8_t POER2;
        stc_port_poer2_field_t POER2_f;
    };
    union
    {
        __IO uint8_t POER3;
        stc_port_poer3_field_t POER3_f;
    };
    union
    {
        __IO uint8_t POER4;
        stc_port_poer4_field_t POER4_f;
    };
    union
    {
        __IO uint8_t POER5;
        stc_port_poer5_field_t POER5_f;
    };
    union
    {
        __IO uint8_t POER6;
        stc_port_poer6_field_t POER6_f;
    };
    union
    {
        __IO uint8_t POER7;
        stc_port_poer7_field_t POER7_f;
    };
    uint8_t RESERVED4[4];
    union
    {
        __IO uint8_t POER12;
        stc_port_poer12_field_t POER12_f;
    };
    union
    {
        __IO uint8_t POER13;
        stc_port_poer13_field_t POER13_f;
    };
    union
    {
        __IO uint8_t POER14;
        stc_port_poer14_field_t POER14_f;
    };
    uint8_t RESERVED5[1];
    union
    {
        __IO uint8_t POSR0;
        stc_port_posr0_field_t POSR0_f;
    };
    union
    {
        __IO uint8_t POSR1;
        stc_port_posr1_field_t POSR1_f;
    };
    union
    {
        __IO uint8_t POSR2;
        stc_port_posr2_field_t POSR2_f;
    };
    union
    {
        __IO uint8_t POSR3;
        stc_port_posr3_field_t POSR3_f;
    };
    union
    {
        __IO uint8_t POSR4;
        stc_port_posr4_field_t POSR4_f;
    };
    union
    {
        __IO uint8_t POSR5;
        stc_port_posr5_field_t POSR5_f;
    };
    union
    {
        __IO uint8_t POSR6;
        stc_port_posr6_field_t POSR6_f;
    };
    union
    {
        __IO uint8_t POSR7;
        stc_port_posr7_field_t POSR7_f;
    };
    uint8_t RESERVED6[4];
    union
    {
        __IO uint8_t POSR12;
        stc_port_posr12_field_t POSR12_f;
    };
    union
    {
        __IO uint8_t POSR13;
        stc_port_posr13_field_t POSR13_f;
    };
    union
    {
        __IO uint8_t POSR14;
        stc_port_posr14_field_t POSR14_f;
    };
    uint8_t RESERVED7[1];
    union
    {
        __IO uint8_t PORR0;
        stc_port_porr0_field_t PORR0_f;
    };
    union
    {
        __IO uint8_t PORR1;
        stc_port_porr1_field_t PORR1_f;
    };
    union
    {
        __IO uint8_t PORR2;
        stc_port_porr2_field_t PORR2_f;
    };
    union
    {
        __IO uint8_t PORR3;
        stc_port_porr3_field_t PORR3_f;
    };
    union
    {
        __IO uint8_t PORR4;
        stc_port_porr4_field_t PORR4_f;
    };
    union
    {
        __IO uint8_t PORR5;
        stc_port_porr5_field_t PORR5_f;
    };
    union
    {
        __IO uint8_t PORR6;
        stc_port_porr6_field_t PORR6_f;
    };
    union
    {
        __IO uint8_t PORR7;
        stc_port_porr7_field_t PORR7_f;
    };
    uint8_t RESERVED8[4];
    union
    {
        __IO uint8_t PORR12;
        stc_port_porr12_field_t PORR12_f;
    };
    union
    {
        __IO uint8_t PORR13;
        stc_port_porr13_field_t PORR13_f;
    };
    union
    {
        __IO uint8_t PORR14;
        stc_port_porr14_field_t PORR14_f;
    };
    uint8_t RESERVED9[1];
    union
    {
        __IO uint8_t POTR0;
        stc_port_potr0_field_t POTR0_f;
    };
    union
    {
        __IO uint8_t POTR1;
        stc_port_potr1_field_t POTR1_f;
    };
    union
    {
        __IO uint8_t POTR2;
        stc_port_potr2_field_t POTR2_f;
    };
    union
    {
        __IO uint8_t POTR3;
        stc_port_potr3_field_t POTR3_f;
    };
    union
    {
        __IO uint8_t POTR4;
        stc_port_potr4_field_t POTR4_f;
    };
    union
    {
        __IO uint8_t POTR5;
        stc_port_potr5_field_t POTR5_f;
    };
    union
    {
        __IO uint8_t POTR6;
        stc_port_potr6_field_t POTR6_f;
    };
    union
    {
        __IO uint8_t POTR7;
        stc_port_potr7_field_t POTR7_f;
    };
    uint8_t RESERVED10[4];
    union
    {
        __IO uint8_t POTR12;
        stc_port_potr12_field_t POTR12_f;
    };
    union
    {
        __IO uint8_t POTR13;
        stc_port_potr13_field_t POTR13_f;
    };
    union
    {
        __IO uint8_t POTR14;
        stc_port_potr14_field_t POTR14_f;
    };
    uint8_t RESERVED11[929];
    union
    {
        __IO uint16_t PCR00;
        stc_port_pcr_field_t PCR00_f;
    };
    union
    {
        __IO uint16_t PCR01;
        stc_port_pcr_field_t PCR01_f;
    };
    uint8_t RESERVED12[12];
    union
    {
        __IO uint16_t PCR10;
        stc_port_pcr_field_t PCR10_f;
    };
    union
    {
        __IO uint16_t PCR11;
        stc_port_pcr_field_t PCR11_f;
    };
    union
    {
        __IO uint16_t PCR12;
        stc_port_pcr_field_t PCR12_f;
    };
    union
    {
        __IO uint16_t PCR13;
        stc_port_pcr_field_t PCR13_f;
    };
    union
    {
        __IO uint16_t PCR14;
        stc_port_pcr_field_t PCR14_f;
    };
    union
    {
        __IO uint16_t PCR15;
        stc_port_pcr_field_t PCR15_f;
    };
    union
    {
        __IO uint16_t PCR16;
        stc_port_pcr_field_t PCR16_f;
    };
    union
    {
        __IO uint16_t PCR17;
        stc_port_pcr_field_t PCR17_f;
    };
    union
    {
        __IO uint16_t PCR20;
        stc_port_pcr_field_t PCR20_f;
    };
    union
    {
        __IO uint16_t PCR21;
        stc_port_pcr_field_t PCR21_f;
    };
    union
    {
        __IO uint16_t PCR22;
        stc_port_pcr_field_t PCR22_f;
    };
    union
    {
        __IO uint16_t PCR23;
        stc_port_pcr_field_t PCR23_f;
    };
    union
    {
        __IO uint16_t PCR24;
        stc_port_pcr_field_t PCR24_f;
    };
    union
    {
        __IO uint16_t PCR25;
        stc_port_pcr_field_t PCR25_f;
    };
    union
    {
        __IO uint16_t PCR26;
        stc_port_pcr_field_t PCR26_f;
    };
    union
    {
        __IO uint16_t PCR27;
        stc_port_pcr_field_t PCR27_f;
    };
    union
    {
        __IO uint16_t PCR30;
        stc_port_pcr_field_t PCR30_f;
    };
    union
    {
        __IO uint16_t PCR31;
        stc_port_pcr_field_t PCR31_f;
    };
    uint8_t RESERVED13[12];
    union
    {
        __IO uint16_t PCR40;
        stc_port_pcr_field_t PCR40_f;
    };
    union
    {
        __IO uint16_t PCR41;
        stc_port_pcr_field_t PCR41_f;
    };
    uint8_t RESERVED14[12];
    union
    {
        __IO uint16_t PCR50;
        stc_port_pcr_field_t PCR50_f;
    };
    union
    {
        __IO uint16_t PCR51;
        stc_port_pcr_field_t PCR51_f;
    };
    uint8_t RESERVED15[12];
    union
    {
        __IO uint16_t PCR60;
        stc_port_pcr_field_t PCR60_f;
    };
    union
    {
        __IO uint16_t PCR61;
        stc_port_pcr_field_t PCR61_f;
    };
    union
    {
        __IO uint16_t PCR62;
        stc_port_pcr_field_t PCR62_f;
    };
    union
    {
        __IO uint16_t PCR63;
        stc_port_pcr_field_t PCR63_f;
    };
    uint8_t RESERVED16[8];
    union
    {
        __IO uint16_t PCR70;
        stc_port_pcr_field_t PCR70_f;
    };
    union
    {
        __IO uint16_t PCR71;
        stc_port_pcr_field_t PCR71_f;
    };
    union
    {
        __IO uint16_t PCR72;
        stc_port_pcr_field_t PCR72_f;
    };
    union
    {
        __IO uint16_t PCR73;
        stc_port_pcr_field_t PCR73_f;
    };
    uint8_t RESERVED17[72];
    union
    {
        __IO uint16_t PCR120;
        stc_port_pcr_field_t PCR120_f;
    };
    union
    {
        __IO uint16_t PCR121;
        stc_port_pcr_field_t PCR121_f;
    };
    union
    {
        __IO uint16_t PCR122;
        stc_port_pcr_field_t PCR122_f;
    };
    union
    {
        __IO uint16_t PCR123;
        stc_port_pcr_field_t PCR123_f;
    };
    union
    {
        __IO uint16_t PCR124;
        stc_port_pcr_field_t PCR124_f;
    };
    uint8_t RESERVED18[20];
    union
    {
        __IO uint16_t PCR137;
        stc_port_pcr_field_t PCR137_f;
    };
    uint8_t RESERVED19[12];
    union
    {
        __IO uint16_t PCR146;
        stc_port_pcr_field_t PCR146_f;
    };
    union
    {
        __IO uint16_t PCR147;
        stc_port_pcr_field_t PCR147_f;
    };
    uint8_t RESERVED20[16];
    union
    {
        __IO uint16_t PSPCR;
        stc_port_pspcr_field_t PSPCR_f;
    };
    uint8_t RESERVED21[2];
    union
    {
        __IO uint16_t PCCR;
        stc_port_pccr_field_t PCCR_f;
    };
    union
    {
        __IO uint16_t PINAER;
        stc_port_pinaer_field_t PINAER_f;
    };
    union
    {
        __IO uint16_t PWPR;
        stc_port_pwpr_field_t PWPR_f;
    };
} M0P_PORT_TypeDef;

/**
 * @brief PWC
 */
typedef struct
{
    union
    {
        __IO uint8_t STPMCR;
        stc_pwc_stpmcr_field_t STPMCR_f;
    };
    uint8_t RESERVED0[3];
    union
    {
        __IO uint8_t PWRC;
        stc_pwc_pwrc_field_t PWRC_f;
    };
    uint8_t RESERVED1[7];
    union
    {
        __IO uint8_t RAMCR;
        stc_pwc_ramcr_field_t RAMCR_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t LVDCSR;
        stc_pwc_lvdcsr_field_t LVDCSR_f;
    };
    uint8_t RESERVED3[15];
    union
    {
        __IO uint16_t FPRC;
        stc_pwc_fprc_field_t FPRC_f;
    };
    uint8_t RESERVED4[30];
    union
    {
        __IO uint8_t DBGC;
        stc_pwc_dbgc_field_t DBGC_f;
    };
} M0P_PWC_TypeDef;

/**
 * @brief RMU
 */
typedef struct
{
    union
    {
        __IO uint16_t RSTF0;
        stc_rmu_rstf0_field_t RSTF0_f;
    };
} M0P_RMU_TypeDef;

/**
 * @brief RTC
 */
typedef struct
{
    union
    {
        __IO uint8_t CR0;
        stc_rtc_cr0_field_t CR0_f;
    };
    uint8_t RESERVED0[3];
    union
    {
        __IO uint8_t CR1;
        stc_rtc_cr1_field_t CR1_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t CR2;
        stc_rtc_cr2_field_t CR2_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t CR3;
        stc_rtc_cr3_field_t CR3_f;
    };
    uint8_t RESERVED3[3];
    union
    {
        __IO uint8_t SEC;
        stc_rtc_sec_field_t SEC_f;
    };
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t MIN;
        stc_rtc_min_field_t MIN_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint8_t HOUR;
        stc_rtc_hour_field_t HOUR_f;
    };
    uint8_t RESERVED6[3];
    union
    {
        __IO uint8_t WEEK;
        stc_rtc_week_field_t WEEK_f;
    };
    uint8_t RESERVED7[3];
    union
    {
        __IO uint8_t DAY;
        stc_rtc_day_field_t DAY_f;
    };
    uint8_t RESERVED8[3];
    union
    {
        __IO uint8_t MON;
        stc_rtc_mon_field_t MON_f;
    };
    uint8_t RESERVED9[3];
    union
    {
        __IO uint8_t YEAR;
        stc_rtc_year_field_t YEAR_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t ALMMIN;
        stc_rtc_almmin_field_t ALMMIN_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint8_t ALMHOUR;
        stc_rtc_almhour_field_t ALMHOUR_f;
    };
    uint8_t RESERVED12[3];
    union
    {
        __IO uint8_t ALMWEEK;
        stc_rtc_almweek_field_t ALMWEEK_f;
    };
    uint8_t RESERVED13[3];
    union
    {
        __IO uint8_t ERRCRH;
        stc_rtc_errcrh_field_t ERRCRH_f;
    };
    uint8_t RESERVED14[3];
    union
    {
        __IO uint8_t ERRCRL;
        stc_rtc_errcrl_field_t ERRCRL_f;
    };
} M0P_RTC_TypeDef;

/**
 * @brief SPI
 */
typedef struct
{
    union
    {
        __IO uint32_t DR;
        stc_spi_dr_field_t DR_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_spi_cr1_field_t CR1_f;
    };
    uint8_t RESERVED0[4];
    union
    {
        __IO uint32_t CFG1;
        stc_spi_cfg1_field_t CFG1_f;
    };
    uint8_t RESERVED1[4];
    union
    {
        __IO uint32_t SR;
        stc_spi_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t CFG2;
        stc_spi_cfg2_field_t CFG2_f;
    };
} M0P_SPI_TypeDef;

/**
 * @brief SWDT
 */
typedef struct
{
    union
    {
        __IO uint32_t CR;
        stc_swdt_cr_field_t CR_f;
    };
    union
    {
        __IO uint32_t SR;
        stc_swdt_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t RR;
        stc_swdt_rr_field_t RR_f;
    };
} M0P_SWDT_TypeDef;

/**
 * @brief TMR0
 */
typedef struct
{
    union
    {
        __IO uint32_t CNTAR;
        stc_tmr0_cntar_field_t CNTAR_f;
    };
    uint8_t RESERVED0[4];
    union
    {
        __IO uint32_t CMPAR;
        stc_tmr0_cmpar_field_t CMPAR_f;
    };
    uint8_t RESERVED1[4];
    union
    {
        __IO uint32_t BCONR;
        stc_tmr0_bconr_field_t BCONR_f;
    };
    union
    {
        __IO uint32_t STFLR;
        stc_tmr0_stflr_field_t STFLR_f;
    };
} M0P_TMR0_TypeDef;

/**
 * @brief TMRB
 */
typedef struct
{
    union
    {
        __IO uint16_t CNTER;
        stc_tmrb_cnter_field_t CNTER_f;
    };
    uint8_t RESERVED0[2];
    union
    {
        __IO uint16_t PERAR;
        stc_tmrb_perar_field_t PERAR_f;
    };
    uint8_t RESERVED1[58];
    union
    {
        __IO uint16_t CMPAR;
        stc_tmrb_cmpar_field_t CMPAR_f;
    };
    uint8_t RESERVED2[62];
    union
    {
        __IO uint16_t BCSTR;
        stc_tmrb_bcstr_field_t BCSTR_f;
    };
    uint8_t RESERVED3[2];
    union
    {
        __IO uint16_t HCONR;
        stc_tmrb_hconr_field_t HCONR_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint16_t HCUPR;
        stc_tmrb_hcupr_field_t HCUPR_f;
    };
    uint8_t RESERVED5[2];
    union
    {
        __IO uint16_t HCDOR;
        stc_tmrb_hcdor_field_t HCDOR_f;
    };
    uint8_t RESERVED6[2];
    union
    {
        __IO uint16_t ICONR;
        stc_tmrb_iconr_field_t ICONR_f;
    };
    uint8_t RESERVED7[2];
    union
    {
        __IO uint16_t ECONR;
        stc_tmrb_econr_field_t ECONR_f;
    };
    uint8_t RESERVED8[6];
    union
    {
        __IO uint16_t STFLR;
        stc_tmrb_stflr_field_t STFLR_f;
    };
    uint8_t RESERVED9[98];
    union
    {
        __IO uint16_t CCONR;
        stc_tmrb_cconr_field_t CCONR_f;
    };
    uint8_t RESERVED10[62];
    union
    {
        __IO uint16_t PCONR;
        stc_tmrb_pconr_field_t PCONR_f;
    };
} M0P_TMRB_TypeDef;

/**
 * @brief USART
 */
typedef struct
{
    union
    {
        __IO uint32_t SR;
        stc_usart_sr_field_t SR_f;
    };
    union
    {
        __IO uint32_t DR;
        stc_usart_dr_field_t DR_f;
    };
    union
    {
        __IO uint32_t BRR;
        stc_usart_brr_field_t BRR_f;
    };
    union
    {
        __IO uint32_t CR1;
        stc_usart_cr1_field_t CR1_f;
    };
    union
    {
        __IO uint32_t CR2;
        stc_usart_cr2_field_t CR2_f;
    };
    union
    {
        __IO uint32_t CR3;
        stc_usart_cr3_field_t CR3_f;
    };
    union
    {
        __IO uint32_t PR;
        stc_usart_pr_field_t PR_f;
    };
} M0P_USART_TypeDef;



/******************************************************************************/
/*           Device Specific Peripheral declaration & memory map              */
/******************************************************************************/

#define M0P_ADC                              ((M0P_ADC_TypeDef *)0x4000B800UL)
#define M0P_AOS                              ((M0P_AOS_TypeDef *)0x40000C00UL)
#define M0P_CMU                              ((M0P_CMU_TypeDef *)0x40014400UL)
#define M0P_CRC                              ((M0P_CRC_TypeDef *)0x40015400UL)
#define M0P_CTC                              ((M0P_CTC_TypeDef *)0x40000000UL)
#define M0P_DBGC                             ((M0P_DBGC_TypeDef *)0x40015000UL)
#define M0P_EFM                              ((M0P_EFM_TypeDef *)0x40000800UL)
#define M0P_I2C                              ((M0P_I2C_TypeDef *)0x40004800UL)
#define M0P_ICG                              ((M0P_ICG_TypeDef *)0x000000C0UL)
#define M0P_INTC                             ((M0P_INTC_TypeDef *)0x40011000UL)
#define M0P_PORT                             ((M0P_PORT_TypeDef *)0x40013800UL)
#define M0P_PWC                              ((M0P_PWC_TypeDef *)0x40014000UL)
#define M0P_RMU                              ((M0P_RMU_TypeDef *)0x40014100UL)
#define M0P_RTC                              ((M0P_RTC_TypeDef *)0x4000D400UL)
#define M0P_SPI                              ((M0P_SPI_TypeDef *)0x40003800UL)
#define M0P_SWDT                             ((M0P_SWDT_TypeDef *)0x4000CC00UL)
#define M0P_TMR0                             ((M0P_TMR0_TypeDef *)0x40005800UL)
#define M0P_TMRB1                            ((M0P_TMRB_TypeDef *)0x40007800UL)
#define M0P_TMRB2                            ((M0P_TMRB_TypeDef *)0x40007C00UL)
#define M0P_TMRB3                            ((M0P_TMRB_TypeDef *)0x40008000UL)
#define M0P_TMRB4                            ((M0P_TMRB_TypeDef *)0x40008400UL)
#define M0P_TMRB5                            ((M0P_TMRB_TypeDef *)0x40008800UL)
#define M0P_TMRB6                            ((M0P_TMRB_TypeDef *)0x40008C00UL)
#define M0P_TMRB7                            ((M0P_TMRB_TypeDef *)0x40009000UL)
#define M0P_TMRB8                            ((M0P_TMRB_TypeDef *)0x40009400UL)
#define M0P_USART1                           ((M0P_USART_TypeDef *)0x40001800UL)
#define M0P_USART2                           ((M0P_USART_TypeDef *)0x40001C00UL)
#define M0P_USART3                           ((M0P_USART_TypeDef *)0x40002000UL)
#define M0P_USART4                           ((M0P_USART_TypeDef *)0x40002400UL)


/******************************************************************************/
/*                   Peripheral Registers Bits Definition                     */
/******************************************************************************/

/*******************************************************************************
                Bit definition for Peripheral ADC
*******************************************************************************/
/*  Bit definition for ADC_STR register  */
#define ADC_STR_STRT_POS                     (0U)
#define ADC_STR_STRT                         ((uint8_t)0x01U)

/*  Bit definition for ADC_CR0 register  */
#define ADC_CR0_MS_POS                       (0U)
#define ADC_CR0_MS                           ((uint16_t)0x0003U)
#define ADC_CR0_MS_0                         ((uint16_t)0x0001U)
#define ADC_CR0_MS_1                         ((uint16_t)0x0002U)
#define ADC_CR0_ACCSEL_POS                   (4U)
#define ADC_CR0_ACCSEL                       ((uint16_t)0x0030U)
#define ADC_CR0_ACCSEL_0                     ((uint16_t)0x0010U)
#define ADC_CR0_ACCSEL_1                     ((uint16_t)0x0020U)
#define ADC_CR0_CLREN_POS                    (6U)
#define ADC_CR0_CLREN                        ((uint16_t)0x0040U)
#define ADC_CR0_DFMT_POS                     (7U)
#define ADC_CR0_DFMT                         ((uint16_t)0x0080U)

/*  Bit definition for ADC_CR1 register  */
#define ADC_CR1_RSCHSEL_POS                  (2U)
#define ADC_CR1_RSCHSEL                      ((uint16_t)0x0004U)

/*  Bit definition for ADC_TRGSR register  */
#define ADC_TRGSR_TRGSELA_POS                (0U)
#define ADC_TRGSR_TRGSELA                    ((uint16_t)0x0003U)
#define ADC_TRGSR_TRGSELA_0                  ((uint16_t)0x0001U)
#define ADC_TRGSR_TRGSELA_1                  ((uint16_t)0x0002U)
#define ADC_TRGSR_TRGENA_POS                 (7U)
#define ADC_TRGSR_TRGENA                     ((uint16_t)0x0080U)
#define ADC_TRGSR_TRGSELB_POS                (8U)
#define ADC_TRGSR_TRGSELB                    ((uint16_t)0x0300U)
#define ADC_TRGSR_TRGSELB_0                  ((uint16_t)0x0100U)
#define ADC_TRGSR_TRGSELB_1                  ((uint16_t)0x0200U)
#define ADC_TRGSR_TRGENB_POS                 (15U)
#define ADC_TRGSR_TRGENB                     ((uint16_t)0x8000U)

/*  Bit definition for ADC_CHSELRA0 register  */
#define ADC_CHSELRA0_CHSELA_POS              (0U)
#define ADC_CHSELRA0_CHSELA                  ((uint16_t)0x0FFFU)
#define ADC_CHSELRA0_CHSELA_0                ((uint16_t)0x0001U)
#define ADC_CHSELRA0_CHSELA_1                ((uint16_t)0x0002U)
#define ADC_CHSELRA0_CHSELA_2                ((uint16_t)0x0004U)
#define ADC_CHSELRA0_CHSELA_3                ((uint16_t)0x0008U)
#define ADC_CHSELRA0_CHSELA_4                ((uint16_t)0x0010U)
#define ADC_CHSELRA0_CHSELA_5                ((uint16_t)0x0020U)
#define ADC_CHSELRA0_CHSELA_6                ((uint16_t)0x0040U)
#define ADC_CHSELRA0_CHSELA_7                ((uint16_t)0x0080U)
#define ADC_CHSELRA0_CHSELA_8                ((uint16_t)0x0100U)
#define ADC_CHSELRA0_CHSELA_9                ((uint16_t)0x0200U)
#define ADC_CHSELRA0_CHSELA_10               ((uint16_t)0x0400U)
#define ADC_CHSELRA0_CHSELA_11               ((uint16_t)0x0800U)

/*  Bit definition for ADC_CHSELRB0 register  */
#define ADC_CHSELRB0_CHSELB_POS              (0U)
#define ADC_CHSELRB0_CHSELB                  ((uint16_t)0x0FFFU)
#define ADC_CHSELRB0_CHSELB_0                ((uint16_t)0x0001U)
#define ADC_CHSELRB0_CHSELB_1                ((uint16_t)0x0002U)
#define ADC_CHSELRB0_CHSELB_2                ((uint16_t)0x0004U)
#define ADC_CHSELRB0_CHSELB_3                ((uint16_t)0x0008U)
#define ADC_CHSELRB0_CHSELB_4                ((uint16_t)0x0010U)
#define ADC_CHSELRB0_CHSELB_5                ((uint16_t)0x0020U)
#define ADC_CHSELRB0_CHSELB_6                ((uint16_t)0x0040U)
#define ADC_CHSELRB0_CHSELB_7                ((uint16_t)0x0080U)
#define ADC_CHSELRB0_CHSELB_8                ((uint16_t)0x0100U)
#define ADC_CHSELRB0_CHSELB_9                ((uint16_t)0x0200U)
#define ADC_CHSELRB0_CHSELB_10               ((uint16_t)0x0400U)
#define ADC_CHSELRB0_CHSELB_11               ((uint16_t)0x0800U)

/*  Bit definition for ADC_EXCHSELR register  */
#define ADC_EXCHSELR_EXCHSEL_POS             (0U)
#define ADC_EXCHSELR_EXCHSEL                 ((uint8_t)0x01U)

/*  Bit definition for ADC_SSTR register  */
#define ADC_SSTR_SSTR                        ((uint8_t)0xFFU)

/*  Bit definition for ADC_ISR register  */
#define ADC_ISR_EOCAF_POS                    (0U)
#define ADC_ISR_EOCAF                        ((uint8_t)0x01U)
#define ADC_ISR_EOCBF_POS                    (1U)
#define ADC_ISR_EOCBF                        ((uint8_t)0x02U)

/*  Bit definition for ADC_ICR register  */
#define ADC_ICR_EOCAIEN_POS                  (0U)
#define ADC_ICR_EOCAIEN                      ((uint8_t)0x01U)
#define ADC_ICR_EOCBIEN_POS                  (1U)
#define ADC_ICR_EOCBIEN                      ((uint8_t)0x02U)

/*  Bit definition for ADC_ISCLRR register  */
#define ADC_ISCLRR_CLREOCAF_POS              (0U)
#define ADC_ISCLRR_CLREOCAF                  ((uint8_t)0x01U)
#define ADC_ISCLRR_CLREOCBF_POS              (1U)
#define ADC_ISCLRR_CLREOCBF                  ((uint8_t)0x02U)

/*  Bit definition for ADC_DR0 register  */
#define ADC_DR0_DR0                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR1 register  */
#define ADC_DR1_DR1                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR2 register  */
#define ADC_DR2_DR2                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR3 register  */
#define ADC_DR3_DR3                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR4 register  */
#define ADC_DR4_DR4                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR5 register  */
#define ADC_DR5_DR5                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR6 register  */
#define ADC_DR6_DR6                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR7 register  */
#define ADC_DR7_DR7                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR8 register  */
#define ADC_DR8_DR8                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR9 register  */
#define ADC_DR9_DR9                          ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR10 register  */
#define ADC_DR10_DR10                        ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_DR11 register  */
#define ADC_DR11_DR11                        ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_AWDCR register  */
#define ADC_AWDCR_AWD0EN_POS                 (0U)
#define ADC_AWDCR_AWD0EN                     ((uint16_t)0x0001U)
#define ADC_AWDCR_AWD0IEN_POS                (1U)
#define ADC_AWDCR_AWD0IEN                    ((uint16_t)0x0002U)
#define ADC_AWDCR_AWD0MD_POS                 (2U)
#define ADC_AWDCR_AWD0MD                     ((uint16_t)0x0004U)
#define ADC_AWDCR_AWD1EN_POS                 (4U)
#define ADC_AWDCR_AWD1EN                     ((uint16_t)0x0010U)
#define ADC_AWDCR_AWD1IEN_POS                (5U)
#define ADC_AWDCR_AWD1IEN                    ((uint16_t)0x0020U)
#define ADC_AWDCR_AWD1MD_POS                 (6U)
#define ADC_AWDCR_AWD1MD                     ((uint16_t)0x0040U)
#define ADC_AWDCR_AWDCM_POS                  (8U)
#define ADC_AWDCR_AWDCM                      ((uint16_t)0x0300U)
#define ADC_AWDCR_AWDCM_0                    ((uint16_t)0x0100U)
#define ADC_AWDCR_AWDCM_1                    ((uint16_t)0x0200U)

/*  Bit definition for ADC_AWDSR register  */
#define ADC_AWDSR_AWD0F_POS                  (0U)
#define ADC_AWDSR_AWD0F                      ((uint8_t)0x01U)
#define ADC_AWDSR_AWD1F_POS                  (1U)
#define ADC_AWDSR_AWD1F                      ((uint8_t)0x02U)
#define ADC_AWDSR_AWDCMF_POS                 (4U)
#define ADC_AWDSR_AWDCMF                     ((uint8_t)0x10U)

/*  Bit definition for ADC_AWDSCLRR register  */
#define ADC_AWDSCLRR_CLRAWD0F_POS            (0U)
#define ADC_AWDSCLRR_CLRAWD0F                ((uint8_t)0x01U)
#define ADC_AWDSCLRR_CLRAWD1F_POS            (1U)
#define ADC_AWDSCLRR_CLRAWD1F                ((uint8_t)0x02U)
#define ADC_AWDSCLRR_CLRAWDCMF_POS           (4U)
#define ADC_AWDSCLRR_CLRAWDCMF               ((uint8_t)0x10U)

/*  Bit definition for ADC_AWD0DR0 register  */
#define ADC_AWD0DR0_AWD0DR0                  ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_AWD0DR1 register  */
#define ADC_AWD0DR1_AWD0DR1                  ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_AWD0CHSR register  */
#define ADC_AWD0CHSR_AWDCH_POS               (0U)
#define ADC_AWD0CHSR_AWDCH                   ((uint8_t)0x1FU)
#define ADC_AWD0CHSR_AWDCH_0                 ((uint8_t)0x01U)
#define ADC_AWD0CHSR_AWDCH_1                 ((uint8_t)0x02U)
#define ADC_AWD0CHSR_AWDCH_2                 ((uint8_t)0x04U)
#define ADC_AWD0CHSR_AWDCH_3                 ((uint8_t)0x08U)
#define ADC_AWD0CHSR_AWDCH_4                 ((uint8_t)0x10U)

/*  Bit definition for ADC_AWD1DR0 register  */
#define ADC_AWD1DR0_AWD1DR0                  ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_AWD1DR1 register  */
#define ADC_AWD1DR1_AWD1DR1                  ((uint16_t)0xFFFFU)

/*  Bit definition for ADC_AWD1CHSR register  */
#define ADC_AWD1CHSR_AWDCH_POS               (0U)
#define ADC_AWD1CHSR_AWDCH                   ((uint8_t)0x1FU)
#define ADC_AWD1CHSR_AWDCH_0                 ((uint8_t)0x01U)
#define ADC_AWD1CHSR_AWDCH_1                 ((uint8_t)0x02U)
#define ADC_AWD1CHSR_AWDCH_2                 ((uint8_t)0x04U)
#define ADC_AWD1CHSR_AWDCH_3                 ((uint8_t)0x08U)
#define ADC_AWD1CHSR_AWDCH_4                 ((uint8_t)0x10U)


/*******************************************************************************
                Bit definition for Peripheral AOS
*******************************************************************************/
/*  Bit definition for AOS_INTC_STRGCR register  */
#define AOS_INTC_STRGCR_STRG_POS             (0U)
#define AOS_INTC_STRGCR_STRG                 ((uint32_t)0x00000001U)

/*  Bit definition for AOS_TMR0_HTSSR register  */
#define AOS_TMR0_HTSSR_TRGSEL_POS            (0U)
#define AOS_TMR0_HTSSR_TRGSEL                ((uint32_t)0x0000007FU)
#define AOS_TMR0_HTSSR_TRGSEL_0              ((uint32_t)0x00000001U)
#define AOS_TMR0_HTSSR_TRGSEL_1              ((uint32_t)0x00000002U)
#define AOS_TMR0_HTSSR_TRGSEL_2              ((uint32_t)0x00000004U)
#define AOS_TMR0_HTSSR_TRGSEL_3              ((uint32_t)0x00000008U)
#define AOS_TMR0_HTSSR_TRGSEL_4              ((uint32_t)0x00000010U)
#define AOS_TMR0_HTSSR_TRGSEL_5              ((uint32_t)0x00000020U)
#define AOS_TMR0_HTSSR_TRGSEL_6              ((uint32_t)0x00000040U)

/*  Bit definition for AOS_TMRB_HTSSR register  */
#define AOS_TMRB_HTSSR_TRGSEL_POS            (0U)
#define AOS_TMRB_HTSSR_TRGSEL                ((uint32_t)0x0000007FU)
#define AOS_TMRB_HTSSR_TRGSEL_0              ((uint32_t)0x00000001U)
#define AOS_TMRB_HTSSR_TRGSEL_1              ((uint32_t)0x00000002U)
#define AOS_TMRB_HTSSR_TRGSEL_2              ((uint32_t)0x00000004U)
#define AOS_TMRB_HTSSR_TRGSEL_3              ((uint32_t)0x00000008U)
#define AOS_TMRB_HTSSR_TRGSEL_4              ((uint32_t)0x00000010U)
#define AOS_TMRB_HTSSR_TRGSEL_5              ((uint32_t)0x00000020U)
#define AOS_TMRB_HTSSR_TRGSEL_6              ((uint32_t)0x00000040U)

/*  Bit definition for AOS_ADC_ITRGSELR0 register  */
#define AOS_ADC_ITRGSELR0_TRGSEL_POS         (0U)
#define AOS_ADC_ITRGSELR0_TRGSEL             ((uint32_t)0x0000007FU)
#define AOS_ADC_ITRGSELR0_TRGSEL_0           ((uint32_t)0x00000001U)
#define AOS_ADC_ITRGSELR0_TRGSEL_1           ((uint32_t)0x00000002U)
#define AOS_ADC_ITRGSELR0_TRGSEL_2           ((uint32_t)0x00000004U)
#define AOS_ADC_ITRGSELR0_TRGSEL_3           ((uint32_t)0x00000008U)
#define AOS_ADC_ITRGSELR0_TRGSEL_4           ((uint32_t)0x00000010U)
#define AOS_ADC_ITRGSELR0_TRGSEL_5           ((uint32_t)0x00000020U)
#define AOS_ADC_ITRGSELR0_TRGSEL_6           ((uint32_t)0x00000040U)

/*  Bit definition for AOS_ADC_ITRGSELR1 register  */
#define AOS_ADC_ITRGSELR1_TRGSEL_POS         (0U)
#define AOS_ADC_ITRGSELR1_TRGSEL             ((uint32_t)0x0000007FU)
#define AOS_ADC_ITRGSELR1_TRGSEL_0           ((uint32_t)0x00000001U)
#define AOS_ADC_ITRGSELR1_TRGSEL_1           ((uint32_t)0x00000002U)
#define AOS_ADC_ITRGSELR1_TRGSEL_2           ((uint32_t)0x00000004U)
#define AOS_ADC_ITRGSELR1_TRGSEL_3           ((uint32_t)0x00000008U)
#define AOS_ADC_ITRGSELR1_TRGSEL_4           ((uint32_t)0x00000010U)
#define AOS_ADC_ITRGSELR1_TRGSEL_5           ((uint32_t)0x00000020U)
#define AOS_ADC_ITRGSELR1_TRGSEL_6           ((uint32_t)0x00000040U)


/*******************************************************************************
                Bit definition for Peripheral CMU
*******************************************************************************/
/*  Bit definition for CMU_PERICKSEL register  */
#define CMU_PERICKSEL_PERICKSEL_POS          (0U)
#define CMU_PERICKSEL_PERICKSEL              ((uint8_t)0x07U)
#define CMU_PERICKSEL_PERICKSEL_0            ((uint8_t)0x01U)
#define CMU_PERICKSEL_PERICKSEL_1            ((uint8_t)0x02U)
#define CMU_PERICKSEL_PERICKSEL_2            ((uint8_t)0x04U)

/*  Bit definition for CMU_XTALSTDSR register  */
#define CMU_XTALSTDSR_XTALSTDF_POS           (0U)
#define CMU_XTALSTDSR_XTALSTDF               ((uint8_t)0x01U)

/*  Bit definition for CMU_SCKDIVR register  */
#define CMU_SCKDIVR_SCKDIV_POS               (0U)
#define CMU_SCKDIVR_SCKDIV                   ((uint8_t)0x07U)
#define CMU_SCKDIVR_SCKDIV_0                 ((uint8_t)0x01U)
#define CMU_SCKDIVR_SCKDIV_1                 ((uint8_t)0x02U)
#define CMU_SCKDIVR_SCKDIV_2                 ((uint8_t)0x04U)

/*  Bit definition for CMU_CKSWR register  */
#define CMU_CKSWR_CKSW_POS                   (0U)
#define CMU_CKSWR_CKSW                       ((uint8_t)0x03U)
#define CMU_CKSWR_CKSW_0                     ((uint8_t)0x01U)
#define CMU_CKSWR_CKSW_1                     ((uint8_t)0x02U)

/*  Bit definition for CMU_XTALCR register  */
#define CMU_XTALCR_XTALSTP_POS               (0U)
#define CMU_XTALCR_XTALSTP                   ((uint8_t)0x01U)

/*  Bit definition for CMU_XTALCFGR register  */
#define CMU_XTALCFGR_XTALDRV_POS             (4U)
#define CMU_XTALCFGR_XTALDRV                 ((uint8_t)0x30U)
#define CMU_XTALCFGR_XTALDRV_0               ((uint8_t)0x10U)
#define CMU_XTALCFGR_XTALDRV_1               ((uint8_t)0x20U)
#define CMU_XTALCFGR_XTALMS_POS              (6U)
#define CMU_XTALCFGR_XTALMS                  ((uint8_t)0x40U)
#define CMU_XTALCFGR_SUPDRV_POS              (7U)
#define CMU_XTALCFGR_SUPDRV                  ((uint8_t)0x80U)

/*  Bit definition for CMU_XTALSTBCR register  */
#define CMU_XTALSTBCR_XTALSTB_POS            (0U)
#define CMU_XTALSTBCR_XTALSTB                ((uint8_t)0x07U)
#define CMU_XTALSTBCR_XTALSTB_0              ((uint8_t)0x01U)
#define CMU_XTALSTBCR_XTALSTB_1              ((uint8_t)0x02U)
#define CMU_XTALSTBCR_XTALSTB_2              ((uint8_t)0x04U)

/*  Bit definition for CMU_HRCCR register  */
#define CMU_HRCCR_HRCSTP_POS                 (0U)
#define CMU_HRCCR_HRCSTP                     ((uint8_t)0x01U)

/*  Bit definition for CMU_OSCSTBSR register  */
#define CMU_OSCSTBSR_HRCSTBF_POS             (0U)
#define CMU_OSCSTBSR_HRCSTBF                 ((uint8_t)0x01U)
#define CMU_OSCSTBSR_XTALSTBF_POS            (3U)
#define CMU_OSCSTBSR_XTALSTBF                ((uint8_t)0x08U)
#define CMU_OSCSTBSR_XTAL32STBF_POS          (4U)
#define CMU_OSCSTBSR_XTAL32STBF              ((uint8_t)0x10U)

/*  Bit definition for CMU_MCO1CFGR register  */
#define CMU_MCO1CFGR_MCO1SEL_POS             (0U)
#define CMU_MCO1CFGR_MCO1SEL                 ((uint8_t)0x0FU)
#define CMU_MCO1CFGR_MCO1SEL_0               ((uint8_t)0x01U)
#define CMU_MCO1CFGR_MCO1SEL_1               ((uint8_t)0x02U)
#define CMU_MCO1CFGR_MCO1SEL_2               ((uint8_t)0x04U)
#define CMU_MCO1CFGR_MCO1SEL_3               ((uint8_t)0x08U)
#define CMU_MCO1CFGR_MCO1DIV_POS             (4U)
#define CMU_MCO1CFGR_MCO1DIV                 ((uint8_t)0x70U)
#define CMU_MCO1CFGR_MCO1DIV_0               ((uint8_t)0x10U)
#define CMU_MCO1CFGR_MCO1DIV_1               ((uint8_t)0x20U)
#define CMU_MCO1CFGR_MCO1DIV_2               ((uint8_t)0x40U)
#define CMU_MCO1CFGR_MCO1EN_POS              (7U)
#define CMU_MCO1CFGR_MCO1EN                  ((uint8_t)0x80U)

/*  Bit definition for CMU_XTALSTDCR register  */
#define CMU_XTALSTDCR_XTALSTDIE_POS          (0U)
#define CMU_XTALSTDCR_XTALSTDIE              ((uint8_t)0x01U)
#define CMU_XTALSTDCR_XTALSTDRE_POS          (1U)
#define CMU_XTALSTDCR_XTALSTDRE              ((uint8_t)0x02U)
#define CMU_XTALSTDCR_XTALSTDRIS_POS         (2U)
#define CMU_XTALSTDCR_XTALSTDRIS             ((uint8_t)0x04U)
#define CMU_XTALSTDCR_XTALSTDE_POS           (7U)
#define CMU_XTALSTDCR_XTALSTDE               ((uint8_t)0x80U)

/*  Bit definition for CMU_FCG register  */
#define CMU_FCG_ADC_POS                      (0U)
#define CMU_FCG_ADC                          ((uint32_t)0x00000001U)
#define CMU_FCG_CTC_POS                      (1U)
#define CMU_FCG_CTC                          ((uint32_t)0x00000002U)
#define CMU_FCG_AOS_POS                      (4U)
#define CMU_FCG_AOS                          ((uint32_t)0x00000010U)
#define CMU_FCG_CRC_POS                      (7U)
#define CMU_FCG_CRC                          ((uint32_t)0x00000080U)
#define CMU_FCG_TIMB1_POS                    (8U)
#define CMU_FCG_TIMB1                        ((uint32_t)0x00000100U)
#define CMU_FCG_TIMB2_POS                    (9U)
#define CMU_FCG_TIMB2                        ((uint32_t)0x00000200U)
#define CMU_FCG_TIMB3_POS                    (10U)
#define CMU_FCG_TIMB3                        ((uint32_t)0x00000400U)
#define CMU_FCG_TIMB4_POS                    (11U)
#define CMU_FCG_TIMB4                        ((uint32_t)0x00000800U)
#define CMU_FCG_TIMB5_POS                    (12U)
#define CMU_FCG_TIMB5                        ((uint32_t)0x00001000U)
#define CMU_FCG_TIMB6_POS                    (13U)
#define CMU_FCG_TIMB6                        ((uint32_t)0x00002000U)
#define CMU_FCG_TIMB7_POS                    (14U)
#define CMU_FCG_TIMB7                        ((uint32_t)0x00004000U)
#define CMU_FCG_TIMB8_POS                    (15U)
#define CMU_FCG_TIMB8                        ((uint32_t)0x00008000U)
#define CMU_FCG_TIM0_POS                     (16U)
#define CMU_FCG_TIM0                         ((uint32_t)0x00010000U)
#define CMU_FCG_RTC_POS                      (23U)
#define CMU_FCG_RTC                          ((uint32_t)0x00800000U)
#define CMU_FCG_UART1_POS                    (24U)
#define CMU_FCG_UART1                        ((uint32_t)0x01000000U)
#define CMU_FCG_UART2_POS                    (25U)
#define CMU_FCG_UART2                        ((uint32_t)0x02000000U)
#define CMU_FCG_UART3_POS                    (26U)
#define CMU_FCG_UART3                        ((uint32_t)0x04000000U)
#define CMU_FCG_UART4_POS                    (27U)
#define CMU_FCG_UART4                        ((uint32_t)0x08000000U)
#define CMU_FCG_IIC_POS                      (28U)
#define CMU_FCG_IIC                          ((uint32_t)0x10000000U)
#define CMU_FCG_SPI_POS                      (29U)
#define CMU_FCG_SPI                          ((uint32_t)0x20000000U)

/*  Bit definition for CMU_XTAL32CR register  */
#define CMU_XTAL32CR_XTAL32STP_POS           (0U)
#define CMU_XTAL32CR_XTAL32STP               ((uint8_t)0x01U)

/*  Bit definition for CMU_XTAL32CFGR register  */
#define CMU_XTAL32CFGR_XTAL32DRV_POS         (0U)
#define CMU_XTAL32CFGR_XTAL32DRV             ((uint8_t)0x03U)
#define CMU_XTAL32CFGR_XTAL32DRV_0           ((uint8_t)0x01U)
#define CMU_XTAL32CFGR_XTAL32DRV_1           ((uint8_t)0x02U)
#define CMU_XTAL32CFGR_XTAL32SUPDRV_POS      (2U)
#define CMU_XTAL32CFGR_XTAL32SUPDRV          ((uint8_t)0x04U)

/*  Bit definition for CMU_XTAL32NFR register  */
#define CMU_XTAL32NFR_XTAL32NF_POS           (0U)
#define CMU_XTAL32NFR_XTAL32NF               ((uint8_t)0x03U)
#define CMU_XTAL32NFR_XTAL32NF_0             ((uint8_t)0x01U)
#define CMU_XTAL32NFR_XTAL32NF_1             ((uint8_t)0x02U)

/*  Bit definition for CMU_LRCCR register  */
#define CMU_LRCCR_LRCSTP_POS                 (0U)
#define CMU_LRCCR_LRCSTP                     ((uint8_t)0x01U)


/*******************************************************************************
                Bit definition for Peripheral CRC
*******************************************************************************/
/*  Bit definition for CRC_CR register  */
#define CRC_CR_CR_POS                        (0U)
#define CRC_CR_CR                            ((uint32_t)0x00000001U)
#define CRC_CR_FLAG_POS                      (1U)
#define CRC_CR_FLAG                          ((uint32_t)0x00000002U)

/*  Bit definition for CRC_RESLT register  */
#define CRC_RESLT_RESLT                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT0 register  */
#define CRC_DAT0_DAT0                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT1 register  */
#define CRC_DAT1_DAT1                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT2 register  */
#define CRC_DAT2_DAT2                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT3 register  */
#define CRC_DAT3_DAT3                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT4 register  */
#define CRC_DAT4_DAT4                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT5 register  */
#define CRC_DAT5_DAT5                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT6 register  */
#define CRC_DAT6_DAT6                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT7 register  */
#define CRC_DAT7_DAT7                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT8 register  */
#define CRC_DAT8_DAT8                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT9 register  */
#define CRC_DAT9_DAT9                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT10 register  */
#define CRC_DAT10_DAT10                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT11 register  */
#define CRC_DAT11_DAT11                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT12 register  */
#define CRC_DAT12_DAT12                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT13 register  */
#define CRC_DAT13_DAT13                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT14 register  */
#define CRC_DAT14_DAT14                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT15 register  */
#define CRC_DAT15_DAT15                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT16 register  */
#define CRC_DAT16_DAT16                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT17 register  */
#define CRC_DAT17_DAT17                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT18 register  */
#define CRC_DAT18_DAT18                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT19 register  */
#define CRC_DAT19_DAT19                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT20 register  */
#define CRC_DAT20_DAT20                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT21 register  */
#define CRC_DAT21_DAT21                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT22 register  */
#define CRC_DAT22_DAT22                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT23 register  */
#define CRC_DAT23_DAT23                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT24 register  */
#define CRC_DAT24_DAT24                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT25 register  */
#define CRC_DAT25_DAT25                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT26 register  */
#define CRC_DAT26_DAT26                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT27 register  */
#define CRC_DAT27_DAT27                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT28 register  */
#define CRC_DAT28_DAT28                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT29 register  */
#define CRC_DAT29_DAT29                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT30 register  */
#define CRC_DAT30_DAT30                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for CRC_DAT31 register  */
#define CRC_DAT31_DAT31                      ((uint32_t)0xFFFFFFFFU)


/*******************************************************************************
                Bit definition for Peripheral CTC
*******************************************************************************/
/*  Bit definition for CTC_CR1 register  */
#define CTC_CR1_REFPSC_POS                   (0U)
#define CTC_CR1_REFPSC                       ((uint32_t)0x00000007U)
#define CTC_CR1_REFPSC_0                     ((uint32_t)0x00000001U)
#define CTC_CR1_REFPSC_1                     ((uint32_t)0x00000002U)
#define CTC_CR1_REFPSC_2                     ((uint32_t)0x00000004U)
#define CTC_CR1_REFCKS_POS                   (4U)
#define CTC_CR1_REFCKS                       ((uint32_t)0x00000030U)
#define CTC_CR1_REFCKS_0                     ((uint32_t)0x00000010U)
#define CTC_CR1_REFCKS_1                     ((uint32_t)0x00000020U)
#define CTC_CR1_ERRIE_POS                    (6U)
#define CTC_CR1_ERRIE                        ((uint32_t)0x00000040U)
#define CTC_CR1_CTCEN_POS                    (7U)
#define CTC_CR1_CTCEN                        ((uint32_t)0x00000080U)
#define CTC_CR1_TRMVAL_POS                   (16U)
#define CTC_CR1_TRMVAL                       ((uint32_t)0x003F0000U)
#define CTC_CR1_TRMVAL_0                     ((uint32_t)0x00010000U)
#define CTC_CR1_TRMVAL_1                     ((uint32_t)0x00020000U)
#define CTC_CR1_TRMVAL_2                     ((uint32_t)0x00040000U)
#define CTC_CR1_TRMVAL_3                     ((uint32_t)0x00080000U)
#define CTC_CR1_TRMVAL_4                     ((uint32_t)0x00100000U)
#define CTC_CR1_TRMVAL_5                     ((uint32_t)0x00200000U)

/*  Bit definition for CTC_CR2 register  */
#define CTC_CR2_OFSVAL_POS                   (0U)
#define CTC_CR2_OFSVAL                       ((uint32_t)0x000000FFU)
#define CTC_CR2_OFSVAL_0                     ((uint32_t)0x00000001U)
#define CTC_CR2_OFSVAL_1                     ((uint32_t)0x00000002U)
#define CTC_CR2_OFSVAL_2                     ((uint32_t)0x00000004U)
#define CTC_CR2_OFSVAL_3                     ((uint32_t)0x00000008U)
#define CTC_CR2_OFSVAL_4                     ((uint32_t)0x00000010U)
#define CTC_CR2_OFSVAL_5                     ((uint32_t)0x00000020U)
#define CTC_CR2_OFSVAL_6                     ((uint32_t)0x00000040U)
#define CTC_CR2_OFSVAL_7                     ((uint32_t)0x00000080U)
#define CTC_CR2_RLDVAL_POS                   (16U)
#define CTC_CR2_RLDVAL                       ((uint32_t)0xFFFF0000U)
#define CTC_CR2_RLDVAL_0                     ((uint32_t)0x00010000U)
#define CTC_CR2_RLDVAL_1                     ((uint32_t)0x00020000U)
#define CTC_CR2_RLDVAL_2                     ((uint32_t)0x00040000U)
#define CTC_CR2_RLDVAL_3                     ((uint32_t)0x00080000U)
#define CTC_CR2_RLDVAL_4                     ((uint32_t)0x00100000U)
#define CTC_CR2_RLDVAL_5                     ((uint32_t)0x00200000U)
#define CTC_CR2_RLDVAL_6                     ((uint32_t)0x00400000U)
#define CTC_CR2_RLDVAL_7                     ((uint32_t)0x00800000U)
#define CTC_CR2_RLDVAL_8                     ((uint32_t)0x01000000U)
#define CTC_CR2_RLDVAL_9                     ((uint32_t)0x02000000U)
#define CTC_CR2_RLDVAL_10                    ((uint32_t)0x04000000U)
#define CTC_CR2_RLDVAL_11                    ((uint32_t)0x08000000U)
#define CTC_CR2_RLDVAL_12                    ((uint32_t)0x10000000U)
#define CTC_CR2_RLDVAL_13                    ((uint32_t)0x20000000U)
#define CTC_CR2_RLDVAL_14                    ((uint32_t)0x40000000U)
#define CTC_CR2_RLDVAL_15                    ((uint32_t)0x80000000U)

/*  Bit definition for CTC_STR register  */
#define CTC_STR_TRIMOK_POS                   (0U)
#define CTC_STR_TRIMOK                       ((uint32_t)0x00000001U)
#define CTC_STR_TRMOVF_POS                   (1U)
#define CTC_STR_TRMOVF                       ((uint32_t)0x00000002U)
#define CTC_STR_TRMUDF_POS                   (2U)
#define CTC_STR_TRMUDF                       ((uint32_t)0x00000004U)
#define CTC_STR_CTCBSY_POS                   (3U)
#define CTC_STR_CTCBSY                       ((uint32_t)0x00000008U)


/*******************************************************************************
                Bit definition for Peripheral DBGC
*******************************************************************************/
/*  Bit definition for DBGC_MCUDBGSTAT register  */
#define DBGC_MCUDBGSTAT_CDBGPWRUPREQ_POS     (0U)
#define DBGC_MCUDBGSTAT_CDBGPWRUPREQ         ((uint32_t)0x00000001U)
#define DBGC_MCUDBGSTAT_CDBGPWRUPACK_POS     (1U)
#define DBGC_MCUDBGSTAT_CDBGPWRUPACK         ((uint32_t)0x00000002U)

/*  Bit definition for DBGC_MCUSTPCTL register  */
#define DBGC_MCUSTPCTL_SWDTSTP_POS           (0U)
#define DBGC_MCUSTPCTL_SWDTSTP               ((uint32_t)0x00000001U)
#define DBGC_MCUSTPCTL_RTCSTP_POS            (2U)
#define DBGC_MCUSTPCTL_RTCSTP                ((uint32_t)0x00000004U)
#define DBGC_MCUSTPCTL_PVDSTP_POS            (3U)
#define DBGC_MCUSTPCTL_PVDSTP                ((uint32_t)0x00000008U)
#define DBGC_MCUSTPCTL_TMR01STP_POS          (14U)
#define DBGC_MCUSTPCTL_TMR01STP              ((uint32_t)0x00004000U)
#define DBGC_MCUSTPCTL_TMR21STP_POS          (17U)
#define DBGC_MCUSTPCTL_TMR21STP              ((uint32_t)0x00020000U)
#define DBGC_MCUSTPCTL_TMR41STP_POS          (20U)
#define DBGC_MCUSTPCTL_TMR41STP              ((uint32_t)0x00100000U)
#define DBGC_MCUSTPCTL_TMRA1STP_POS          (23U)
#define DBGC_MCUSTPCTL_TMRA1STP              ((uint32_t)0x00800000U)
#define DBGC_MCUSTPCTL_TMRB1STP_POS          (24U)
#define DBGC_MCUSTPCTL_TMRB1STP              ((uint32_t)0x01000000U)
#define DBGC_MCUSTPCTL_TMRB2STP_POS          (25U)
#define DBGC_MCUSTPCTL_TMRB2STP              ((uint32_t)0x02000000U)
#define DBGC_MCUSTPCTL_TMRB3STP_POS          (26U)
#define DBGC_MCUSTPCTL_TMRB3STP              ((uint32_t)0x04000000U)
#define DBGC_MCUSTPCTL_TMRB4STP_POS          (27U)
#define DBGC_MCUSTPCTL_TMRB4STP              ((uint32_t)0x08000000U)
#define DBGC_MCUSTPCTL_TMRB5STP_POS          (28U)
#define DBGC_MCUSTPCTL_TMRB5STP              ((uint32_t)0x10000000U)
#define DBGC_MCUSTPCTL_TMRB6STP_POS          (29U)
#define DBGC_MCUSTPCTL_TMRB6STP              ((uint32_t)0x20000000U)
#define DBGC_MCUSTPCTL_TMRB7STP_POS          (30U)
#define DBGC_MCUSTPCTL_TMRB7STP              ((uint32_t)0x40000000U)
#define DBGC_MCUSTPCTL_TMRB8STP_POS          (31U)
#define DBGC_MCUSTPCTL_TMRB8STP              ((uint32_t)0x80000000U)


/*******************************************************************************
                Bit definition for Peripheral EFM
*******************************************************************************/
/*  Bit definition for EFM_FAPRT register  */
#define EFM_FAPRT_FAPRT_POS                  (0U)
#define EFM_FAPRT_FAPRT                      ((uint32_t)0x0000FFFFU)
#define EFM_FAPRT_FAPRT_0                    ((uint32_t)0x00000001U)
#define EFM_FAPRT_FAPRT_1                    ((uint32_t)0x00000002U)
#define EFM_FAPRT_FAPRT_2                    ((uint32_t)0x00000004U)
#define EFM_FAPRT_FAPRT_3                    ((uint32_t)0x00000008U)
#define EFM_FAPRT_FAPRT_4                    ((uint32_t)0x00000010U)
#define EFM_FAPRT_FAPRT_5                    ((uint32_t)0x00000020U)
#define EFM_FAPRT_FAPRT_6                    ((uint32_t)0x00000040U)
#define EFM_FAPRT_FAPRT_7                    ((uint32_t)0x00000080U)
#define EFM_FAPRT_FAPRT_8                    ((uint32_t)0x00000100U)
#define EFM_FAPRT_FAPRT_9                    ((uint32_t)0x00000200U)
#define EFM_FAPRT_FAPRT_10                   ((uint32_t)0x00000400U)
#define EFM_FAPRT_FAPRT_11                   ((uint32_t)0x00000800U)
#define EFM_FAPRT_FAPRT_12                   ((uint32_t)0x00001000U)
#define EFM_FAPRT_FAPRT_13                   ((uint32_t)0x00002000U)
#define EFM_FAPRT_FAPRT_14                   ((uint32_t)0x00004000U)
#define EFM_FAPRT_FAPRT_15                   ((uint32_t)0x00008000U)

/*  Bit definition for EFM_FSTP register  */
#define EFM_FSTP_FSTP_POS                    (0U)
#define EFM_FSTP_FSTP                        ((uint32_t)0x00000001U)

/*  Bit definition for EFM_FRMC register  */
#define EFM_FRMC_FLWT_POS                    (0U)
#define EFM_FRMC_FLWT                        ((uint32_t)0x00000001U)
#define EFM_FRMC_PREFETE_POS                 (17U)
#define EFM_FRMC_PREFETE                     ((uint32_t)0x00020000U)

/*  Bit definition for EFM_FWMC register  */
#define EFM_FWMC_PEMODE_POS                  (0U)
#define EFM_FWMC_PEMODE                      ((uint32_t)0x00000001U)
#define EFM_FWMC_PEMOD_POS                   (4U)
#define EFM_FWMC_PEMOD                       ((uint32_t)0x00000070U)
#define EFM_FWMC_PEMOD_0                     ((uint32_t)0x00000010U)
#define EFM_FWMC_PEMOD_1                     ((uint32_t)0x00000020U)
#define EFM_FWMC_PEMOD_2                     ((uint32_t)0x00000040U)
#define EFM_FWMC_BUSHLDCTL_POS               (8U)
#define EFM_FWMC_BUSHLDCTL                   ((uint32_t)0x00000100U)

/*  Bit definition for EFM_FSR register  */
#define EFM_FSR_PEWERR_POS                   (0U)
#define EFM_FSR_PEWERR                       ((uint32_t)0x00000001U)
#define EFM_FSR_PEPRTERR_POS                 (1U)
#define EFM_FSR_PEPRTERR                     ((uint32_t)0x00000002U)
#define EFM_FSR_PGMISMTCH_POS                (3U)
#define EFM_FSR_PGMISMTCH                    ((uint32_t)0x00000008U)
#define EFM_FSR_OPTEND_POS                   (4U)
#define EFM_FSR_OPTEND                       ((uint32_t)0x00000010U)
#define EFM_FSR_RDCOLERR_POS                 (5U)
#define EFM_FSR_RDCOLERR                     ((uint32_t)0x00000020U)
#define EFM_FSR_RDY_POS                      (8U)
#define EFM_FSR_RDY                          ((uint32_t)0x00000100U)

/*  Bit definition for EFM_FSCLR register  */
#define EFM_FSCLR_PEWERRCLR_POS              (0U)
#define EFM_FSCLR_PEWERRCLR                  ((uint32_t)0x00000001U)
#define EFM_FSCLR_PEPRTERRCLR_POS            (1U)
#define EFM_FSCLR_PEPRTERRCLR                ((uint32_t)0x00000002U)
#define EFM_FSCLR_PGMISMTCHCLR_POS           (3U)
#define EFM_FSCLR_PGMISMTCHCLR               ((uint32_t)0x00000008U)
#define EFM_FSCLR_OPTENDCLR_POS              (4U)
#define EFM_FSCLR_OPTENDCLR                  ((uint32_t)0x00000010U)
#define EFM_FSCLR_RDCOLERRCLR_POS            (5U)
#define EFM_FSCLR_RDCOLERRCLR                ((uint32_t)0x00000020U)

/*  Bit definition for EFM_FITE register  */
#define EFM_FITE_PEERRITE_POS                (0U)
#define EFM_FITE_PEERRITE                    ((uint32_t)0x00000001U)
#define EFM_FITE_OPTENDITE_POS               (1U)
#define EFM_FITE_OPTENDITE                   ((uint32_t)0x00000002U)
#define EFM_FITE_RDCOLERRITE_POS             (2U)
#define EFM_FITE_RDCOLERRITE                 ((uint32_t)0x00000004U)

/*  Bit definition for EFM_FPMTSW register  */
#define EFM_FPMTSW_FPMTSW_POS                (0U)
#define EFM_FPMTSW_FPMTSW                    ((uint32_t)0x0000FFFFU)
#define EFM_FPMTSW_FPMTSW_0                  ((uint32_t)0x00000001U)
#define EFM_FPMTSW_FPMTSW_1                  ((uint32_t)0x00000002U)
#define EFM_FPMTSW_FPMTSW_2                  ((uint32_t)0x00000004U)
#define EFM_FPMTSW_FPMTSW_3                  ((uint32_t)0x00000008U)
#define EFM_FPMTSW_FPMTSW_4                  ((uint32_t)0x00000010U)
#define EFM_FPMTSW_FPMTSW_5                  ((uint32_t)0x00000020U)
#define EFM_FPMTSW_FPMTSW_6                  ((uint32_t)0x00000040U)
#define EFM_FPMTSW_FPMTSW_7                  ((uint32_t)0x00000080U)
#define EFM_FPMTSW_FPMTSW_8                  ((uint32_t)0x00000100U)
#define EFM_FPMTSW_FPMTSW_9                  ((uint32_t)0x00000200U)
#define EFM_FPMTSW_FPMTSW_10                 ((uint32_t)0x00000400U)
#define EFM_FPMTSW_FPMTSW_11                 ((uint32_t)0x00000800U)
#define EFM_FPMTSW_FPMTSW_12                 ((uint32_t)0x00001000U)
#define EFM_FPMTSW_FPMTSW_13                 ((uint32_t)0x00002000U)
#define EFM_FPMTSW_FPMTSW_14                 ((uint32_t)0x00004000U)
#define EFM_FPMTSW_FPMTSW_15                 ((uint32_t)0x00008000U)

/*  Bit definition for EFM_FPMTEW register  */
#define EFM_FPMTEW_FPMTEW_POS                (0U)
#define EFM_FPMTEW_FPMTEW                    ((uint32_t)0x0000FFFFU)
#define EFM_FPMTEW_FPMTEW_0                  ((uint32_t)0x00000001U)
#define EFM_FPMTEW_FPMTEW_1                  ((uint32_t)0x00000002U)
#define EFM_FPMTEW_FPMTEW_2                  ((uint32_t)0x00000004U)
#define EFM_FPMTEW_FPMTEW_3                  ((uint32_t)0x00000008U)
#define EFM_FPMTEW_FPMTEW_4                  ((uint32_t)0x00000010U)
#define EFM_FPMTEW_FPMTEW_5                  ((uint32_t)0x00000020U)
#define EFM_FPMTEW_FPMTEW_6                  ((uint32_t)0x00000040U)
#define EFM_FPMTEW_FPMTEW_7                  ((uint32_t)0x00000080U)
#define EFM_FPMTEW_FPMTEW_8                  ((uint32_t)0x00000100U)
#define EFM_FPMTEW_FPMTEW_9                  ((uint32_t)0x00000200U)
#define EFM_FPMTEW_FPMTEW_10                 ((uint32_t)0x00000400U)
#define EFM_FPMTEW_FPMTEW_11                 ((uint32_t)0x00000800U)
#define EFM_FPMTEW_FPMTEW_12                 ((uint32_t)0x00001000U)
#define EFM_FPMTEW_FPMTEW_13                 ((uint32_t)0x00002000U)
#define EFM_FPMTEW_FPMTEW_14                 ((uint32_t)0x00004000U)
#define EFM_FPMTEW_FPMTEW_15                 ((uint32_t)0x00008000U)

/*  Bit definition for EFM_UQID0 register  */
#define EFM_UQID0_UQID0                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for EFM_UQID1 register  */
#define EFM_UQID1_UQID1                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for EFM_UQID2 register  */
#define EFM_UQID2_UQID2                      ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for EFM_HRCCFGR register  */
#define EFM_HRCCFGR_HRCFREQS_POS             (0U)
#define EFM_HRCCFGR_HRCFREQS                 ((uint8_t)0x0FU)
#define EFM_HRCCFGR_HRCFREQS_0               ((uint8_t)0x01U)
#define EFM_HRCCFGR_HRCFREQS_1               ((uint8_t)0x02U)
#define EFM_HRCCFGR_HRCFREQS_2               ((uint8_t)0x04U)
#define EFM_HRCCFGR_HRCFREQS_3               ((uint8_t)0x08U)

/*  Bit definition for EFM_LVDICGCR register  */
#define EFM_LVDICGCR_DFS_POS                 (0U)
#define EFM_LVDICGCR_DFS                     ((uint16_t)0x0003U)
#define EFM_LVDICGCR_DFS_0                   ((uint16_t)0x0001U)
#define EFM_LVDICGCR_DFS_1                   ((uint16_t)0x0002U)
#define EFM_LVDICGCR_DFDIS_POS               (2U)
#define EFM_LVDICGCR_DFDIS                   ((uint16_t)0x0004U)
#define EFM_LVDICGCR_LVDLVL_POS              (8U)
#define EFM_LVDICGCR_LVDLVL                  ((uint16_t)0x0F00U)
#define EFM_LVDICGCR_LVDLVL_0                ((uint16_t)0x0100U)
#define EFM_LVDICGCR_LVDLVL_1                ((uint16_t)0x0200U)
#define EFM_LVDICGCR_LVDLVL_2                ((uint16_t)0x0400U)
#define EFM_LVDICGCR_LVDLVL_3                ((uint16_t)0x0800U)
#define EFM_LVDICGCR_NMIS_POS                (12U)
#define EFM_LVDICGCR_NMIS                    ((uint16_t)0x1000U)
#define EFM_LVDICGCR_IRS_POS                 (13U)
#define EFM_LVDICGCR_IRS                     ((uint16_t)0x2000U)
#define EFM_LVDICGCR_IRDIS_POS               (14U)
#define EFM_LVDICGCR_IRDIS                   ((uint16_t)0x4000U)
#define EFM_LVDICGCR_LVDDIS_POS              (15U)
#define EFM_LVDICGCR_LVDDIS                  ((uint16_t)0x8000U)


/*******************************************************************************
                Bit definition for Peripheral I2C
*******************************************************************************/
/*  Bit definition for I2C_CR1 register  */
#define I2C_CR1_PE_POS                       (0U)
#define I2C_CR1_PE                           ((uint32_t)0x00000001U)
#define I2C_CR1_SMBUS_POS                    (1U)
#define I2C_CR1_SMBUS                        ((uint32_t)0x00000002U)
#define I2C_CR1_SMBALRTEN_POS                (2U)
#define I2C_CR1_SMBALRTEN                    ((uint32_t)0x00000004U)
#define I2C_CR1_SMBDEFAULTEN_POS             (3U)
#define I2C_CR1_SMBDEFAULTEN                 ((uint32_t)0x00000008U)
#define I2C_CR1_SMBHOSTEN_POS                (4U)
#define I2C_CR1_SMBHOSTEN                    ((uint32_t)0x00000010U)
#define I2C_CR1_FACKEN_POS                   (5U)
#define I2C_CR1_FACKEN                       ((uint32_t)0x00000020U)
#define I2C_CR1_GCEN_POS                     (6U)
#define I2C_CR1_GCEN                         ((uint32_t)0x00000040U)
#define I2C_CR1_RESTART_POS                  (7U)
#define I2C_CR1_RESTART                      ((uint32_t)0x00000080U)
#define I2C_CR1_START_POS                    (8U)
#define I2C_CR1_START                        ((uint32_t)0x00000100U)
#define I2C_CR1_STOP_POS                     (9U)
#define I2C_CR1_STOP                         ((uint32_t)0x00000200U)
#define I2C_CR1_ACK_POS                      (10U)
#define I2C_CR1_ACK                          ((uint32_t)0x00000400U)
#define I2C_CR1_SWRST_POS                    (15U)
#define I2C_CR1_SWRST                        ((uint32_t)0x00008000U)

/*  Bit definition for I2C_CR2 register  */
#define I2C_CR2_STARTIE_POS                  (0U)
#define I2C_CR2_STARTIE                      ((uint32_t)0x00000001U)
#define I2C_CR2_SLADDR0IE_POS                (1U)
#define I2C_CR2_SLADDR0IE                    ((uint32_t)0x00000002U)
#define I2C_CR2_SLADDR1IE_POS                (2U)
#define I2C_CR2_SLADDR1IE                    ((uint32_t)0x00000004U)
#define I2C_CR2_TENDIE_POS                   (3U)
#define I2C_CR2_TENDIE                       ((uint32_t)0x00000008U)
#define I2C_CR2_STOPIE_POS                   (4U)
#define I2C_CR2_STOPIE                       ((uint32_t)0x00000010U)
#define I2C_CR2_RFULLIE_POS                  (6U)
#define I2C_CR2_RFULLIE                      ((uint32_t)0x00000040U)
#define I2C_CR2_TEMPTYIE_POS                 (7U)
#define I2C_CR2_TEMPTYIE                     ((uint32_t)0x00000080U)
#define I2C_CR2_ARLOIE_POS                   (9U)
#define I2C_CR2_ARLOIE                       ((uint32_t)0x00000200U)
#define I2C_CR2_NACKIE_POS                   (12U)
#define I2C_CR2_NACKIE                       ((uint32_t)0x00001000U)
#define I2C_CR2_GENCALLIE_POS                (20U)
#define I2C_CR2_GENCALLIE                    ((uint32_t)0x00100000U)
#define I2C_CR2_SMBDEFAULTIE_POS             (21U)
#define I2C_CR2_SMBDEFAULTIE                 ((uint32_t)0x00200000U)
#define I2C_CR2_SMBHOSTIE_POS                (22U)
#define I2C_CR2_SMBHOSTIE                    ((uint32_t)0x00400000U)
#define I2C_CR2_SMBALRTIE_POS                (23U)
#define I2C_CR2_SMBALRTIE                    ((uint32_t)0x00800000U)

/*  Bit definition for I2C_SLR0 register  */
#define I2C_SLR0_SLADDR0_POS                 (0U)
#define I2C_SLR0_SLADDR0                     ((uint32_t)0x000003FFU)
#define I2C_SLR0_SLADDR0_0                   ((uint32_t)0x00000001U)
#define I2C_SLR0_SLADDR0_1                   ((uint32_t)0x00000002U)
#define I2C_SLR0_SLADDR0_2                   ((uint32_t)0x00000004U)
#define I2C_SLR0_SLADDR0_3                   ((uint32_t)0x00000008U)
#define I2C_SLR0_SLADDR0_4                   ((uint32_t)0x00000010U)
#define I2C_SLR0_SLADDR0_5                   ((uint32_t)0x00000020U)
#define I2C_SLR0_SLADDR0_6                   ((uint32_t)0x00000040U)
#define I2C_SLR0_SLADDR0_7                   ((uint32_t)0x00000080U)
#define I2C_SLR0_SLADDR0_8                   ((uint32_t)0x00000100U)
#define I2C_SLR0_SLADDR0_9                   ((uint32_t)0x00000200U)
#define I2C_SLR0_SLADDR0EN_POS               (12U)
#define I2C_SLR0_SLADDR0EN                   ((uint32_t)0x00001000U)
#define I2C_SLR0_ADDRMOD0_POS                (15U)
#define I2C_SLR0_ADDRMOD0                    ((uint32_t)0x00008000U)

/*  Bit definition for I2C_SLR1 register  */
#define I2C_SLR1_SLADDR1_POS                 (0U)
#define I2C_SLR1_SLADDR1                     ((uint32_t)0x000003FFU)
#define I2C_SLR1_SLADDR1_0                   ((uint32_t)0x00000001U)
#define I2C_SLR1_SLADDR1_1                   ((uint32_t)0x00000002U)
#define I2C_SLR1_SLADDR1_2                   ((uint32_t)0x00000004U)
#define I2C_SLR1_SLADDR1_3                   ((uint32_t)0x00000008U)
#define I2C_SLR1_SLADDR1_4                   ((uint32_t)0x00000010U)
#define I2C_SLR1_SLADDR1_5                   ((uint32_t)0x00000020U)
#define I2C_SLR1_SLADDR1_6                   ((uint32_t)0x00000040U)
#define I2C_SLR1_SLADDR1_7                   ((uint32_t)0x00000080U)
#define I2C_SLR1_SLADDR1_8                   ((uint32_t)0x00000100U)
#define I2C_SLR1_SLADDR1_9                   ((uint32_t)0x00000200U)
#define I2C_SLR1_SLADDR1EN_POS               (12U)
#define I2C_SLR1_SLADDR1EN                   ((uint32_t)0x00001000U)
#define I2C_SLR1_ADDRMOD1_POS                (15U)
#define I2C_SLR1_ADDRMOD1                    ((uint32_t)0x00008000U)

/*  Bit definition for I2C_SR register  */
#define I2C_SR_STARTF_POS                    (0U)
#define I2C_SR_STARTF                        ((uint32_t)0x00000001U)
#define I2C_SR_SLADDR0F_POS                  (1U)
#define I2C_SR_SLADDR0F                      ((uint32_t)0x00000002U)
#define I2C_SR_SLADDR1F_POS                  (2U)
#define I2C_SR_SLADDR1F                      ((uint32_t)0x00000004U)
#define I2C_SR_TENDF_POS                     (3U)
#define I2C_SR_TENDF                         ((uint32_t)0x00000008U)
#define I2C_SR_STOPF_POS                     (4U)
#define I2C_SR_STOPF                         ((uint32_t)0x00000010U)
#define I2C_SR_RFULLF_POS                    (6U)
#define I2C_SR_RFULLF                        ((uint32_t)0x00000040U)
#define I2C_SR_TEMPTYF_POS                   (7U)
#define I2C_SR_TEMPTYF                       ((uint32_t)0x00000080U)
#define I2C_SR_ARLOF_POS                     (9U)
#define I2C_SR_ARLOF                         ((uint32_t)0x00000200U)
#define I2C_SR_ACKRF_POS                     (10U)
#define I2C_SR_ACKRF                         ((uint32_t)0x00000400U)
#define I2C_SR_NACKF_POS                     (12U)
#define I2C_SR_NACKF                         ((uint32_t)0x00001000U)
#define I2C_SR_MSL_POS                       (16U)
#define I2C_SR_MSL                           ((uint32_t)0x00010000U)
#define I2C_SR_BUSY_POS                      (17U)
#define I2C_SR_BUSY                          ((uint32_t)0x00020000U)
#define I2C_SR_TRA_POS                       (18U)
#define I2C_SR_TRA                           ((uint32_t)0x00040000U)
#define I2C_SR_GENCALLF_POS                  (20U)
#define I2C_SR_GENCALLF                      ((uint32_t)0x00100000U)
#define I2C_SR_SMBDEFAULTF_POS               (21U)
#define I2C_SR_SMBDEFAULTF                   ((uint32_t)0x00200000U)
#define I2C_SR_SMBHOSTF_POS                  (22U)
#define I2C_SR_SMBHOSTF                      ((uint32_t)0x00400000U)
#define I2C_SR_SMBALRTF_POS                  (23U)
#define I2C_SR_SMBALRTF                      ((uint32_t)0x00800000U)

/*  Bit definition for I2C_CLR register  */
#define I2C_CLR_STARTFCLR_POS                (0U)
#define I2C_CLR_STARTFCLR                    ((uint32_t)0x00000001U)
#define I2C_CLR_SLADDR0FCLR_POS              (1U)
#define I2C_CLR_SLADDR0FCLR                  ((uint32_t)0x00000002U)
#define I2C_CLR_SLADDR1FCLR_POS              (2U)
#define I2C_CLR_SLADDR1FCLR                  ((uint32_t)0x00000004U)
#define I2C_CLR_TENDFCLR_POS                 (3U)
#define I2C_CLR_TENDFCLR                     ((uint32_t)0x00000008U)
#define I2C_CLR_STOPFCLR_POS                 (4U)
#define I2C_CLR_STOPFCLR                     ((uint32_t)0x00000010U)
#define I2C_CLR_RFULLFCLR_POS                (6U)
#define I2C_CLR_RFULLFCLR                    ((uint32_t)0x00000040U)
#define I2C_CLR_TEMPTYFCLR_POS               (7U)
#define I2C_CLR_TEMPTYFCLR                   ((uint32_t)0x00000080U)
#define I2C_CLR_ARLOFCLR_POS                 (9U)
#define I2C_CLR_ARLOFCLR                     ((uint32_t)0x00000200U)
#define I2C_CLR_NACKFCLR_POS                 (12U)
#define I2C_CLR_NACKFCLR                     ((uint32_t)0x00001000U)
#define I2C_CLR_GENCALLFCLR_POS              (20U)
#define I2C_CLR_GENCALLFCLR                  ((uint32_t)0x00100000U)
#define I2C_CLR_SMBDEFAULTFCLR_POS           (21U)
#define I2C_CLR_SMBDEFAULTFCLR               ((uint32_t)0x00200000U)
#define I2C_CLR_SMBHOSTFCLR_POS              (22U)
#define I2C_CLR_SMBHOSTFCLR                  ((uint32_t)0x00400000U)
#define I2C_CLR_SMBALRTFCLR_POS              (23U)
#define I2C_CLR_SMBALRTFCLR                  ((uint32_t)0x00800000U)

/*  Bit definition for I2C_DTR register  */
#define I2C_DTR_DT_POS                       (0U)
#define I2C_DTR_DT                           ((uint8_t)0xFFU)
#define I2C_DTR_DT_0                         ((uint8_t)0x01U)
#define I2C_DTR_DT_1                         ((uint8_t)0x02U)
#define I2C_DTR_DT_2                         ((uint8_t)0x04U)
#define I2C_DTR_DT_3                         ((uint8_t)0x08U)
#define I2C_DTR_DT_4                         ((uint8_t)0x10U)
#define I2C_DTR_DT_5                         ((uint8_t)0x20U)
#define I2C_DTR_DT_6                         ((uint8_t)0x40U)
#define I2C_DTR_DT_7                         ((uint8_t)0x80U)

/*  Bit definition for I2C_DRR register  */
#define I2C_DRR_DR_POS                       (0U)
#define I2C_DRR_DR                           ((uint8_t)0xFFU)
#define I2C_DRR_DR_0                         ((uint8_t)0x01U)
#define I2C_DRR_DR_1                         ((uint8_t)0x02U)
#define I2C_DRR_DR_2                         ((uint8_t)0x04U)
#define I2C_DRR_DR_3                         ((uint8_t)0x08U)
#define I2C_DRR_DR_4                         ((uint8_t)0x10U)
#define I2C_DRR_DR_5                         ((uint8_t)0x20U)
#define I2C_DRR_DR_6                         ((uint8_t)0x40U)
#define I2C_DRR_DR_7                         ((uint8_t)0x80U)

/*  Bit definition for I2C_CCR register  */
#define I2C_CCR_SLOWW_POS                    (0U)
#define I2C_CCR_SLOWW                        ((uint32_t)0x0000001FU)
#define I2C_CCR_SLOWW_0                      ((uint32_t)0x00000001U)
#define I2C_CCR_SLOWW_1                      ((uint32_t)0x00000002U)
#define I2C_CCR_SLOWW_2                      ((uint32_t)0x00000004U)
#define I2C_CCR_SLOWW_3                      ((uint32_t)0x00000008U)
#define I2C_CCR_SLOWW_4                      ((uint32_t)0x00000010U)
#define I2C_CCR_SHIGHW_POS                   (8U)
#define I2C_CCR_SHIGHW                       ((uint32_t)0x00001F00U)
#define I2C_CCR_SHIGHW_0                     ((uint32_t)0x00000100U)
#define I2C_CCR_SHIGHW_1                     ((uint32_t)0x00000200U)
#define I2C_CCR_SHIGHW_2                     ((uint32_t)0x00000400U)
#define I2C_CCR_SHIGHW_3                     ((uint32_t)0x00000800U)
#define I2C_CCR_SHIGHW_4                     ((uint32_t)0x00001000U)
#define I2C_CCR_CKDIV_POS                    (16U)
#define I2C_CCR_CKDIV                        ((uint32_t)0x00070000U)
#define I2C_CCR_CKDIV_0                      ((uint32_t)0x00010000U)
#define I2C_CCR_CKDIV_1                      ((uint32_t)0x00020000U)
#define I2C_CCR_CKDIV_2                      ((uint32_t)0x00040000U)

/*  Bit definition for I2C_FLTR register  */
#define I2C_FLTR_DNF_POS                     (0U)
#define I2C_FLTR_DNF                         ((uint32_t)0x00000003U)
#define I2C_FLTR_DNF_0                       ((uint32_t)0x00000001U)
#define I2C_FLTR_DNF_1                       ((uint32_t)0x00000002U)
#define I2C_FLTR_DNFEN_POS                   (4U)
#define I2C_FLTR_DNFEN                       ((uint32_t)0x00000010U)
#define I2C_FLTR_ANFEN_POS                   (5U)
#define I2C_FLTR_ANFEN                       ((uint32_t)0x00000020U)


/*******************************************************************************
                Bit definition for Peripheral ICG
*******************************************************************************/
/*  Bit definition for ICG_ICG0 register  */
#define ICG_ICG0_SWDTAUTS_POS                (0U)
#define ICG_ICG0_SWDTAUTS                    ((uint32_t)0x00000001U)
#define ICG_ICG0_SWDTITS_POS                 (1U)
#define ICG_ICG0_SWDTITS                     ((uint32_t)0x00000002U)
#define ICG_ICG0_SWDTPERI_POS                (2U)
#define ICG_ICG0_SWDTPERI                    ((uint32_t)0x0000000CU)
#define ICG_ICG0_SWDTPERI_0                  ((uint32_t)0x00000004U)
#define ICG_ICG0_SWDTPERI_1                  ((uint32_t)0x00000008U)
#define ICG_ICG0_SWDTCKS_POS                 (4U)
#define ICG_ICG0_SWDTCKS                     ((uint32_t)0x000000F0U)
#define ICG_ICG0_SWDTCKS_0                   ((uint32_t)0x00000010U)
#define ICG_ICG0_SWDTCKS_1                   ((uint32_t)0x00000020U)
#define ICG_ICG0_SWDTCKS_2                   ((uint32_t)0x00000040U)
#define ICG_ICG0_SWDTCKS_3                   ((uint32_t)0x00000080U)
#define ICG_ICG0_SWDTWDPT_POS                (8U)
#define ICG_ICG0_SWDTWDPT                    ((uint32_t)0x00000F00U)
#define ICG_ICG0_SWDTWDPT_0                  ((uint32_t)0x00000100U)
#define ICG_ICG0_SWDTWDPT_1                  ((uint32_t)0x00000200U)
#define ICG_ICG0_SWDTWDPT_2                  ((uint32_t)0x00000400U)
#define ICG_ICG0_SWDTWDPT_3                  ((uint32_t)0x00000800U)
#define ICG_ICG0_SWDTSLPOFF_POS              (12U)
#define ICG_ICG0_SWDTSLPOFF                  ((uint32_t)0x00001000U)
#define ICG_ICG0_HRCREQS_POS                 (16U)
#define ICG_ICG0_HRCREQS                     ((uint32_t)0x000F0000U)
#define ICG_ICG0_HRCREQS_0                   ((uint32_t)0x00010000U)
#define ICG_ICG0_HRCREQS_1                   ((uint32_t)0x00020000U)
#define ICG_ICG0_HRCREQS_2                   ((uint32_t)0x00040000U)
#define ICG_ICG0_HRCREQS_3                   ((uint32_t)0x00080000U)
#define ICG_ICG0_NMIFCLK_POS                 (26U)
#define ICG_ICG0_NMIFCLK                     ((uint32_t)0x0C000000U)
#define ICG_ICG0_NMIFCLK_0                   ((uint32_t)0x04000000U)
#define ICG_ICG0_NMIFCLK_1                   ((uint32_t)0x08000000U)
#define ICG_ICG0_NMIFEN_POS                  (28U)
#define ICG_ICG0_NMIFEN                      ((uint32_t)0x10000000U)
#define ICG_ICG0_NMITRG_POS                  (29U)
#define ICG_ICG0_NMITRG                      ((uint32_t)0x20000000U)
#define ICG_ICG0_NMIEN_POS                   (30U)
#define ICG_ICG0_NMIEN                       ((uint32_t)0x40000000U)
#define ICG_ICG0_NMIICGENA_POS               (31U)
#define ICG_ICG0_NMIICGENA                   ((uint32_t)0x80000000U)

/*  Bit definition for ICG_ICG1 register  */
#define ICG_ICG1_DFS_POS                     (0U)
#define ICG_ICG1_DFS                         ((uint32_t)0x00000003U)
#define ICG_ICG1_DFS_0                       ((uint32_t)0x00000001U)
#define ICG_ICG1_DFS_1                       ((uint32_t)0x00000002U)
#define ICG_ICG1_DFDIS_POS                   (2U)
#define ICG_ICG1_DFDIS                       ((uint32_t)0x00000004U)
#define ICG_ICG1_LVDLVL_POS                  (8U)
#define ICG_ICG1_LVDLVL                      ((uint32_t)0x00000F00U)
#define ICG_ICG1_LVDLVL_0                    ((uint32_t)0x00000100U)
#define ICG_ICG1_LVDLVL_1                    ((uint32_t)0x00000200U)
#define ICG_ICG1_LVDLVL_2                    ((uint32_t)0x00000400U)
#define ICG_ICG1_LVDLVL_3                    ((uint32_t)0x00000800U)
#define ICG_ICG1_NMIS_POS                    (12U)
#define ICG_ICG1_NMIS                        ((uint32_t)0x00001000U)
#define ICG_ICG1_IRS_POS                     (13U)
#define ICG_ICG1_IRS                         ((uint32_t)0x00002000U)
#define ICG_ICG1_IRDIS_POS                   (14U)
#define ICG_ICG1_IRDIS                       ((uint32_t)0x00004000U)
#define ICG_ICG1_LVDDIS_POS                  (15U)
#define ICG_ICG1_LVDDIS                      ((uint32_t)0x00008000U)

/*  Bit definition for ICG_ICG2 register  */
#define ICG_ICG2_ICG2                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for ICG_ICG3 register  */
#define ICG_ICG3_ICG3                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for ICG_ICG4 register  */
#define ICG_ICG4_ICG4                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for ICG_ICG5 register  */
#define ICG_ICG5_ICG5                        ((uint32_t)0xFFFFFFFFU)

/*  Bit definition for ICG_ICG6 register  */
#define ICG_ICG6_ICG6                        ((uint32_t)0xFFFFFFFFU)


/*******************************************************************************
                Bit definition for Peripheral INTC
*******************************************************************************/
/*  Bit definition for INTC_NMICR register  */
#define INTC_NMICR_NMITRG_POS                (0U)
#define INTC_NMICR_NMITRG                    ((uint32_t)0x00000001U)
#define INTC_NMICR_NMIFCLK_POS               (4U)
#define INTC_NMICR_NMIFCLK                   ((uint32_t)0x00000030U)
#define INTC_NMICR_NMIFCLK_0                 ((uint32_t)0x00000010U)
#define INTC_NMICR_NMIFCLK_1                 ((uint32_t)0x00000020U)
#define INTC_NMICR_NMIFEN_POS                (7U)
#define INTC_NMICR_NMIFEN                    ((uint32_t)0x00000080U)

/*  Bit definition for INTC_NMIER register  */
#define INTC_NMIER_NMIEN_POS                 (0U)
#define INTC_NMIER_NMIEN                     ((uint32_t)0x00000001U)
#define INTC_NMIER_XTALSTPEN_POS             (1U)
#define INTC_NMIER_XTALSTPEN                 ((uint32_t)0x00000002U)
#define INTC_NMIER_SWDTEN_POS                (2U)
#define INTC_NMIER_SWDTEN                    ((uint32_t)0x00000004U)
#define INTC_NMIER_PVDEN_POS                 (3U)
#define INTC_NMIER_PVDEN                     ((uint32_t)0x00000008U)

/*  Bit definition for INTC_NMIFR register  */
#define INTC_NMIFR_NMIF_POS                  (0U)
#define INTC_NMIFR_NMIF                      ((uint32_t)0x00000001U)
#define INTC_NMIFR_XTALSTPF_POS              (1U)
#define INTC_NMIFR_XTALSTPF                  ((uint32_t)0x00000002U)
#define INTC_NMIFR_SWDTF_POS                 (2U)
#define INTC_NMIFR_SWDTF                     ((uint32_t)0x00000004U)
#define INTC_NMIFR_PVDF_POS                  (3U)
#define INTC_NMIFR_PVDF                      ((uint32_t)0x00000008U)

/*  Bit definition for INTC_NMICLR register  */
#define INTC_NMICLR_NMICL_POS                (0U)
#define INTC_NMICLR_NMICL                    ((uint32_t)0x00000001U)
#define INTC_NMICLR_XTALSTPCL_POS            (1U)
#define INTC_NMICLR_XTALSTPCL                ((uint32_t)0x00000002U)
#define INTC_NMICLR_SWDTCL_POS               (2U)
#define INTC_NMICLR_SWDTCL                   ((uint32_t)0x00000004U)
#define INTC_NMICLR_PVDCL_POS                (3U)
#define INTC_NMICLR_PVDCL                    ((uint32_t)0x00000008U)

/*  Bit definition for INTC_EVTER register  */
#define INTC_EVTER_EVTEN0_POS                (0U)
#define INTC_EVTER_EVTEN0                    ((uint32_t)0x00000001U)
#define INTC_EVTER_EVTEN1_POS                (1U)
#define INTC_EVTER_EVTEN1                    ((uint32_t)0x00000002U)
#define INTC_EVTER_EVTEN2_POS                (2U)
#define INTC_EVTER_EVTEN2                    ((uint32_t)0x00000004U)
#define INTC_EVTER_EVTEN3_POS                (3U)
#define INTC_EVTER_EVTEN3                    ((uint32_t)0x00000008U)
#define INTC_EVTER_EVTEN4_POS                (4U)
#define INTC_EVTER_EVTEN4                    ((uint32_t)0x00000010U)
#define INTC_EVTER_EVTEN5_POS                (5U)
#define INTC_EVTER_EVTEN5                    ((uint32_t)0x00000020U)
#define INTC_EVTER_EVTEN6_POS                (6U)
#define INTC_EVTER_EVTEN6                    ((uint32_t)0x00000040U)
#define INTC_EVTER_EVTEN7_POS                (7U)
#define INTC_EVTER_EVTEN7                    ((uint32_t)0x00000080U)

/*  Bit definition for INTC_EKEYCR register  */
#define INTC_EKEYCR_EKEY0EN_POS              (0U)
#define INTC_EKEYCR_EKEY0EN                  ((uint32_t)0x00000001U)
#define INTC_EKEYCR_EKEY1EN_POS              (1U)
#define INTC_EKEYCR_EKEY1EN                  ((uint32_t)0x00000002U)
#define INTC_EKEYCR_EKEY2EN_POS              (2U)
#define INTC_EKEYCR_EKEY2EN                  ((uint32_t)0x00000004U)
#define INTC_EKEYCR_EKEY3EN_POS              (3U)
#define INTC_EKEYCR_EKEY3EN                  ((uint32_t)0x00000008U)
#define INTC_EKEYCR_EKEY4EN_POS              (4U)
#define INTC_EKEYCR_EKEY4EN                  ((uint32_t)0x00000010U)
#define INTC_EKEYCR_EKEY5EN_POS              (5U)
#define INTC_EKEYCR_EKEY5EN                  ((uint32_t)0x00000020U)

/*  Bit definition for INTC_FPRCR register  */
#define INTC_FPRCR_FPRC_POS                  (0U)
#define INTC_FPRCR_FPRC                      ((uint32_t)0x000000FFU)
#define INTC_FPRCR_FPRC_0                    ((uint32_t)0x00000001U)
#define INTC_FPRCR_FPRC_1                    ((uint32_t)0x00000002U)
#define INTC_FPRCR_FPRC_2                    ((uint32_t)0x00000004U)
#define INTC_FPRCR_FPRC_3                    ((uint32_t)0x00000008U)
#define INTC_FPRCR_FPRC_4                    ((uint32_t)0x00000010U)
#define INTC_FPRCR_FPRC_5                    ((uint32_t)0x00000020U)
#define INTC_FPRCR_FPRC_6                    ((uint32_t)0x00000040U)
#define INTC_FPRCR_FPRC_7                    ((uint32_t)0x00000080U)

/*  Bit definition for INTC_EIRQCR register  */
#define INTC_EIRQCR_EIRQTRG_POS              (0U)
#define INTC_EIRQCR_EIRQTRG                  ((uint32_t)0x00000003U)
#define INTC_EIRQCR_EIRQTRG_0                ((uint32_t)0x00000001U)
#define INTC_EIRQCR_EIRQTRG_1                ((uint32_t)0x00000002U)
#define INTC_EIRQCR_EIRQFCLK_POS             (4U)
#define INTC_EIRQCR_EIRQFCLK                 ((uint32_t)0x00000030U)
#define INTC_EIRQCR_EIRQFCLK_0               ((uint32_t)0x00000010U)
#define INTC_EIRQCR_EIRQFCLK_1               ((uint32_t)0x00000020U)
#define INTC_EIRQCR_EIRQFEN_POS              (7U)
#define INTC_EIRQCR_EIRQFEN                  ((uint32_t)0x00000080U)

/*  Bit definition for INTC_WUPENR register  */
#define INTC_WUPENR_EIRQWUEN_POS             (0U)
#define INTC_WUPENR_EIRQWUEN                 ((uint32_t)0x000003FFU)
#define INTC_WUPENR_EIRQWUEN_0               ((uint32_t)0x00000001U)
#define INTC_WUPENR_EIRQWUEN_1               ((uint32_t)0x00000002U)
#define INTC_WUPENR_EIRQWUEN_2               ((uint32_t)0x00000004U)
#define INTC_WUPENR_EIRQWUEN_3               ((uint32_t)0x00000008U)
#define INTC_WUPENR_EIRQWUEN_4               ((uint32_t)0x00000010U)
#define INTC_WUPENR_EIRQWUEN_5               ((uint32_t)0x00000020U)
#define INTC_WUPENR_EIRQWUEN_6               ((uint32_t)0x00000040U)
#define INTC_WUPENR_EIRQWUEN_7               ((uint32_t)0x00000080U)
#define INTC_WUPENR_EIRQWUEN_8               ((uint32_t)0x00000100U)
#define INTC_WUPENR_EIRQWUEN_9               ((uint32_t)0x00000200U)
#define INTC_WUPENR_SWDTWUEN_POS             (16U)
#define INTC_WUPENR_SWDTWUEN                 ((uint32_t)0x00010000U)
#define INTC_WUPENR_EKEYWUEN_POS             (17U)
#define INTC_WUPENR_EKEYWUEN                 ((uint32_t)0x00020000U)
#define INTC_WUPENR_TMR0CMPWUEN_POS          (18U)
#define INTC_WUPENR_TMR0CMPWUEN              ((uint32_t)0x00040000U)
#define INTC_WUPENR_PVDWUEN_POS              (22U)
#define INTC_WUPENR_PVDWUEN                  ((uint32_t)0x00400000U)
#define INTC_WUPENR_RTCALMWUEN_POS           (23U)
#define INTC_WUPENR_RTCALMWUEN               ((uint32_t)0x00800000U)
#define INTC_WUPENR_RTCPRDWUEN_POS           (24U)
#define INTC_WUPENR_RTCPRDWUEN               ((uint32_t)0x01000000U)

/*  Bit definition for INTC_EIRQFR register  */
#define INTC_EIRQFR_EIRQF_POS                (0U)
#define INTC_EIRQFR_EIRQF                    ((uint32_t)0x000003FFU)
#define INTC_EIRQFR_EIRQF_0                  ((uint32_t)0x00000001U)
#define INTC_EIRQFR_EIRQF_1                  ((uint32_t)0x00000002U)
#define INTC_EIRQFR_EIRQF_2                  ((uint32_t)0x00000004U)
#define INTC_EIRQFR_EIRQF_3                  ((uint32_t)0x00000008U)
#define INTC_EIRQFR_EIRQF_4                  ((uint32_t)0x00000010U)
#define INTC_EIRQFR_EIRQF_5                  ((uint32_t)0x00000020U)
#define INTC_EIRQFR_EIRQF_6                  ((uint32_t)0x00000040U)
#define INTC_EIRQFR_EIRQF_7                  ((uint32_t)0x00000080U)
#define INTC_EIRQFR_EIRQF_8                  ((uint32_t)0x00000100U)
#define INTC_EIRQFR_EIRQF_9                  ((uint32_t)0x00000200U)

/*  Bit definition for INTC_EIRQCLR register  */
#define INTC_EIRQCLR_EIRQCL_POS              (0U)
#define INTC_EIRQCLR_EIRQCL                  ((uint32_t)0x000003FFU)
#define INTC_EIRQCLR_EIRQCL_0                ((uint32_t)0x00000001U)
#define INTC_EIRQCLR_EIRQCL_1                ((uint32_t)0x00000002U)
#define INTC_EIRQCLR_EIRQCL_2                ((uint32_t)0x00000004U)
#define INTC_EIRQCLR_EIRQCL_3                ((uint32_t)0x00000008U)
#define INTC_EIRQCLR_EIRQCL_4                ((uint32_t)0x00000010U)
#define INTC_EIRQCLR_EIRQCL_5                ((uint32_t)0x00000020U)
#define INTC_EIRQCLR_EIRQCL_6                ((uint32_t)0x00000040U)
#define INTC_EIRQCLR_EIRQCL_7                ((uint32_t)0x00000080U)
#define INTC_EIRQCLR_EIRQCL_8                ((uint32_t)0x00000100U)
#define INTC_EIRQCLR_EIRQCL_9                ((uint32_t)0x00000200U)

/*  Bit definition for INTC_ISELAR register  */
#define INTC_ISELAR_ISEL_POS                 (0U)
#define INTC_ISELAR_ISEL                     ((uint32_t)0x0000000FU)
#define INTC_ISELAR_ISEL_0                   ((uint32_t)0x00000001U)
#define INTC_ISELAR_ISEL_1                   ((uint32_t)0x00000002U)
#define INTC_ISELAR_ISEL_2                   ((uint32_t)0x00000004U)
#define INTC_ISELAR_ISEL_3                   ((uint32_t)0x00000008U)

/*  Bit definition for INTC_ISELBR register  */
#define INTC_ISELBR_ISEL_POS                 (1U)
#define INTC_ISELBR_ISEL                     ((uint32_t)0x0000FFFEU)
#define INTC_ISELBR_ISEL_1                   ((uint32_t)0x00000002U)
#define INTC_ISELBR_ISEL_2                   ((uint32_t)0x00000004U)
#define INTC_ISELBR_ISEL_3                   ((uint32_t)0x00000008U)
#define INTC_ISELBR_ISEL_4                   ((uint32_t)0x00000010U)
#define INTC_ISELBR_ISEL_5                   ((uint32_t)0x00000020U)
#define INTC_ISELBR_ISEL_6                   ((uint32_t)0x00000040U)
#define INTC_ISELBR_ISEL_7                   ((uint32_t)0x00000080U)
#define INTC_ISELBR_ISEL_8                   ((uint32_t)0x00000100U)
#define INTC_ISELBR_ISEL_9                   ((uint32_t)0x00000200U)
#define INTC_ISELBR_ISEL_10                  ((uint32_t)0x00000400U)
#define INTC_ISELBR_ISEL_11                  ((uint32_t)0x00000800U)
#define INTC_ISELBR_ISEL_12                  ((uint32_t)0x00001000U)
#define INTC_ISELBR_ISEL_13                  ((uint32_t)0x00002000U)
#define INTC_ISELBR_ISEL_14                  ((uint32_t)0x00004000U)
#define INTC_ISELBR_ISEL_15                  ((uint32_t)0x00008000U)


/*******************************************************************************
                Bit definition for Peripheral PORT
*******************************************************************************/
/*  Bit definition for PORT_PIDR0 register  */
#define PORT_PIDR0_PIN0_POS                  (0U)
#define PORT_PIDR0_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR0_PIN1_POS                  (1U)
#define PORT_PIDR0_PIN1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PIDR1 register  */
#define PORT_PIDR1_PIN0_POS                  (0U)
#define PORT_PIDR1_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR1_PIN1_POS                  (1U)
#define PORT_PIDR1_PIN1                      ((uint8_t)0x02U)
#define PORT_PIDR1_PIN2_POS                  (2U)
#define PORT_PIDR1_PIN2                      ((uint8_t)0x04U)
#define PORT_PIDR1_PIN3_POS                  (3U)
#define PORT_PIDR1_PIN3                      ((uint8_t)0x08U)
#define PORT_PIDR1_PIN4_POS                  (4U)
#define PORT_PIDR1_PIN4                      ((uint8_t)0x10U)
#define PORT_PIDR1_PIN5_POS                  (5U)
#define PORT_PIDR1_PIN5                      ((uint8_t)0x20U)
#define PORT_PIDR1_PIN6_POS                  (6U)
#define PORT_PIDR1_PIN6                      ((uint8_t)0x40U)
#define PORT_PIDR1_PIN7_POS                  (7U)
#define PORT_PIDR1_PIN7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_PIDR2 register  */
#define PORT_PIDR2_PIN0_POS                  (0U)
#define PORT_PIDR2_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR2_PIN1_POS                  (1U)
#define PORT_PIDR2_PIN1                      ((uint8_t)0x02U)
#define PORT_PIDR2_PIN2_POS                  (2U)
#define PORT_PIDR2_PIN2                      ((uint8_t)0x04U)
#define PORT_PIDR2_PIN3_POS                  (3U)
#define PORT_PIDR2_PIN3                      ((uint8_t)0x08U)
#define PORT_PIDR2_PIN4_POS                  (4U)
#define PORT_PIDR2_PIN4                      ((uint8_t)0x10U)
#define PORT_PIDR2_PIN5_POS                  (5U)
#define PORT_PIDR2_PIN5                      ((uint8_t)0x20U)
#define PORT_PIDR2_PIN6_POS                  (6U)
#define PORT_PIDR2_PIN6                      ((uint8_t)0x40U)
#define PORT_PIDR2_PIN7_POS                  (7U)
#define PORT_PIDR2_PIN7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_PIDR3 register  */
#define PORT_PIDR3_PIN0_POS                  (0U)
#define PORT_PIDR3_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR3_PIN1_POS                  (1U)
#define PORT_PIDR3_PIN1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PIDR4 register  */
#define PORT_PIDR4_PIN0_POS                  (0U)
#define PORT_PIDR4_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR4_PIN1_POS                  (1U)
#define PORT_PIDR4_PIN1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PIDR5 register  */
#define PORT_PIDR5_PIN0_POS                  (0U)
#define PORT_PIDR5_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR5_PIN1_POS                  (1U)
#define PORT_PIDR5_PIN1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PIDR6 register  */
#define PORT_PIDR6_PIN0_POS                  (0U)
#define PORT_PIDR6_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR6_PIN1_POS                  (1U)
#define PORT_PIDR6_PIN1                      ((uint8_t)0x02U)
#define PORT_PIDR6_PIN2_POS                  (2U)
#define PORT_PIDR6_PIN2                      ((uint8_t)0x04U)
#define PORT_PIDR6_PIN3_POS                  (3U)
#define PORT_PIDR6_PIN3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_PIDR7 register  */
#define PORT_PIDR7_PIN0_POS                  (0U)
#define PORT_PIDR7_PIN0                      ((uint8_t)0x01U)
#define PORT_PIDR7_PIN1_POS                  (1U)
#define PORT_PIDR7_PIN1                      ((uint8_t)0x02U)
#define PORT_PIDR7_PIN2_POS                  (2U)
#define PORT_PIDR7_PIN2                      ((uint8_t)0x04U)
#define PORT_PIDR7_PIN3_POS                  (3U)
#define PORT_PIDR7_PIN3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_PIDR12 register  */
#define PORT_PIDR12_PIN0_POS                 (0U)
#define PORT_PIDR12_PIN0                     ((uint8_t)0x01U)
#define PORT_PIDR12_PIN1_POS                 (1U)
#define PORT_PIDR12_PIN1                     ((uint8_t)0x02U)
#define PORT_PIDR12_PIN2_POS                 (2U)
#define PORT_PIDR12_PIN2                     ((uint8_t)0x04U)
#define PORT_PIDR12_PIN3_POS                 (3U)
#define PORT_PIDR12_PIN3                     ((uint8_t)0x08U)
#define PORT_PIDR12_PIN4_POS                 (4U)
#define PORT_PIDR12_PIN4                     ((uint8_t)0x10U)

/*  Bit definition for PORT_PIDR13 register  */
#define PORT_PIDR13_PIN7_POS                 (7U)
#define PORT_PIDR13_PIN7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PIDR14 register  */
#define PORT_PIDR14_PIN6_POS                 (6U)
#define PORT_PIDR14_PIN6                     ((uint8_t)0x40U)
#define PORT_PIDR14_PIN7_POS                 (7U)
#define PORT_PIDR14_PIN7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PODR0 register  */
#define PORT_PODR0_POUT0_POS                 (0U)
#define PORT_PODR0_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR0_POUT1_POS                 (1U)
#define PORT_PODR0_POUT1                     ((uint8_t)0x02U)

/*  Bit definition for PORT_PODR1 register  */
#define PORT_PODR1_POUT0_POS                 (0U)
#define PORT_PODR1_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR1_POUT1_POS                 (1U)
#define PORT_PODR1_POUT1                     ((uint8_t)0x02U)
#define PORT_PODR1_POUT2_POS                 (2U)
#define PORT_PODR1_POUT2                     ((uint8_t)0x04U)
#define PORT_PODR1_POUT3_POS                 (3U)
#define PORT_PODR1_POUT3                     ((uint8_t)0x08U)
#define PORT_PODR1_POUT4_POS                 (4U)
#define PORT_PODR1_POUT4                     ((uint8_t)0x10U)
#define PORT_PODR1_POUT5_POS                 (5U)
#define PORT_PODR1_POUT5                     ((uint8_t)0x20U)
#define PORT_PODR1_POUT6_POS                 (6U)
#define PORT_PODR1_POUT6                     ((uint8_t)0x40U)
#define PORT_PODR1_POUT7_POS                 (7U)
#define PORT_PODR1_POUT7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PODR2 register  */
#define PORT_PODR2_POUT0_POS                 (0U)
#define PORT_PODR2_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR2_POUT1_POS                 (1U)
#define PORT_PODR2_POUT1                     ((uint8_t)0x02U)
#define PORT_PODR2_POUT2_POS                 (2U)
#define PORT_PODR2_POUT2                     ((uint8_t)0x04U)
#define PORT_PODR2_POUT3_POS                 (3U)
#define PORT_PODR2_POUT3                     ((uint8_t)0x08U)
#define PORT_PODR2_POUT4_POS                 (4U)
#define PORT_PODR2_POUT4                     ((uint8_t)0x10U)
#define PORT_PODR2_POUT5_POS                 (5U)
#define PORT_PODR2_POUT5                     ((uint8_t)0x20U)
#define PORT_PODR2_POUT6_POS                 (6U)
#define PORT_PODR2_POUT6                     ((uint8_t)0x40U)
#define PORT_PODR2_POUT7_POS                 (7U)
#define PORT_PODR2_POUT7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PODR3 register  */
#define PORT_PODR3_POUT0_POS                 (0U)
#define PORT_PODR3_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR3_POUT1_POS                 (1U)
#define PORT_PODR3_POUT1                     ((uint8_t)0x02U)

/*  Bit definition for PORT_PODR4 register  */
#define PORT_PODR4_POUT0_POS                 (0U)
#define PORT_PODR4_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR4_POUT1_POS                 (1U)
#define PORT_PODR4_POUT1                     ((uint8_t)0x02U)

/*  Bit definition for PORT_PODR5 register  */
#define PORT_PODR5_POUT0_POS                 (0U)
#define PORT_PODR5_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR5_POUT1_POS                 (1U)
#define PORT_PODR5_POUT1                     ((uint8_t)0x02U)

/*  Bit definition for PORT_PODR6 register  */
#define PORT_PODR6_POUT0_POS                 (0U)
#define PORT_PODR6_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR6_POUT1_POS                 (1U)
#define PORT_PODR6_POUT1                     ((uint8_t)0x02U)
#define PORT_PODR6_POUT2_POS                 (2U)
#define PORT_PODR6_POUT2                     ((uint8_t)0x04U)
#define PORT_PODR6_POUT3_POS                 (3U)
#define PORT_PODR6_POUT3                     ((uint8_t)0x08U)

/*  Bit definition for PORT_PODR7 register  */
#define PORT_PODR7_POUT0_POS                 (0U)
#define PORT_PODR7_POUT0                     ((uint8_t)0x01U)
#define PORT_PODR7_POUT1_POS                 (1U)
#define PORT_PODR7_POUT1                     ((uint8_t)0x02U)
#define PORT_PODR7_POUT2_POS                 (2U)
#define PORT_PODR7_POUT2                     ((uint8_t)0x04U)
#define PORT_PODR7_POUT3_POS                 (3U)
#define PORT_PODR7_POUT3                     ((uint8_t)0x08U)

/*  Bit definition for PORT_PODR12 register  */
#define PORT_PODR12_POUT0_POS                (0U)
#define PORT_PODR12_POUT0                    ((uint8_t)0x01U)
#define PORT_PODR12_POUT1_POS                (1U)
#define PORT_PODR12_POUT1                    ((uint8_t)0x02U)
#define PORT_PODR12_POUT2_POS                (2U)
#define PORT_PODR12_POUT2                    ((uint8_t)0x04U)
#define PORT_PODR12_POUT3_POS                (3U)
#define PORT_PODR12_POUT3                    ((uint8_t)0x08U)
#define PORT_PODR12_POUT4_POS                (4U)
#define PORT_PODR12_POUT4                    ((uint8_t)0x10U)

/*  Bit definition for PORT_PODR13 register  */
#define PORT_PODR13_POUT7_POS                (7U)
#define PORT_PODR13_POUT7                    ((uint8_t)0x80U)

/*  Bit definition for PORT_PODR14 register  */
#define PORT_PODR14_POUT6_POS                (6U)
#define PORT_PODR14_POUT6                    ((uint8_t)0x40U)
#define PORT_PODR14_POUT7_POS                (7U)
#define PORT_PODR14_POUT7                    ((uint8_t)0x80U)

/*  Bit definition for PORT_POER0 register  */
#define PORT_POER0_POUTE0_POS                (0U)
#define PORT_POER0_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER0_POUTE1_POS                (1U)
#define PORT_POER0_POUTE1                    ((uint8_t)0x02U)

/*  Bit definition for PORT_POER1 register  */
#define PORT_POER1_POUTE0_POS                (0U)
#define PORT_POER1_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER1_POUTE1_POS                (1U)
#define PORT_POER1_POUTE1                    ((uint8_t)0x02U)
#define PORT_POER1_POUTE2_POS                (2U)
#define PORT_POER1_POUTE2                    ((uint8_t)0x04U)
#define PORT_POER1_POUTE3_POS                (3U)
#define PORT_POER1_POUTE3                    ((uint8_t)0x08U)
#define PORT_POER1_POUTE4_POS                (4U)
#define PORT_POER1_POUTE4                    ((uint8_t)0x10U)
#define PORT_POER1_POUTE5_POS                (5U)
#define PORT_POER1_POUTE5                    ((uint8_t)0x20U)
#define PORT_POER1_POUTE6_POS                (6U)
#define PORT_POER1_POUTE6                    ((uint8_t)0x40U)
#define PORT_POER1_POUTE7_POS                (7U)
#define PORT_POER1_POUTE7                    ((uint8_t)0x80U)

/*  Bit definition for PORT_POER2 register  */
#define PORT_POER2_POUTE0_POS                (0U)
#define PORT_POER2_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER2_POUTE1_POS                (1U)
#define PORT_POER2_POUTE1                    ((uint8_t)0x02U)
#define PORT_POER2_POUTE2_POS                (2U)
#define PORT_POER2_POUTE2                    ((uint8_t)0x04U)
#define PORT_POER2_POUTE3_POS                (3U)
#define PORT_POER2_POUTE3                    ((uint8_t)0x08U)
#define PORT_POER2_POUTE4_POS                (4U)
#define PORT_POER2_POUTE4                    ((uint8_t)0x10U)
#define PORT_POER2_POUTE5_POS                (5U)
#define PORT_POER2_POUTE5                    ((uint8_t)0x20U)
#define PORT_POER2_POUTE6_POS                (6U)
#define PORT_POER2_POUTE6                    ((uint8_t)0x40U)
#define PORT_POER2_POUTE7_POS                (7U)
#define PORT_POER2_POUTE7                    ((uint8_t)0x80U)

/*  Bit definition for PORT_POER3 register  */
#define PORT_POER3_POUTE0_POS                (0U)
#define PORT_POER3_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER3_POUTE1_POS                (1U)
#define PORT_POER3_POUTE1                    ((uint8_t)0x02U)

/*  Bit definition for PORT_POER4 register  */
#define PORT_POER4_POUTE0_POS                (0U)
#define PORT_POER4_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER4_POUTE1_POS                (1U)
#define PORT_POER4_POUTE1                    ((uint8_t)0x02U)

/*  Bit definition for PORT_POER5 register  */
#define PORT_POER5_POUTE0_POS                (0U)
#define PORT_POER5_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER5_POUTE1_POS                (1U)
#define PORT_POER5_POUTE1                    ((uint8_t)0x02U)

/*  Bit definition for PORT_POER6 register  */
#define PORT_POER6_POUTE0_POS                (0U)
#define PORT_POER6_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER6_POUTE1_POS                (1U)
#define PORT_POER6_POUTE1                    ((uint8_t)0x02U)
#define PORT_POER6_POUTE2_POS                (2U)
#define PORT_POER6_POUTE2                    ((uint8_t)0x04U)
#define PORT_POER6_POUTE3_POS                (3U)
#define PORT_POER6_POUTE3                    ((uint8_t)0x08U)

/*  Bit definition for PORT_POER7 register  */
#define PORT_POER7_POUTE0_POS                (0U)
#define PORT_POER7_POUTE0                    ((uint8_t)0x01U)
#define PORT_POER7_POUTE1_POS                (1U)
#define PORT_POER7_POUTE1                    ((uint8_t)0x02U)
#define PORT_POER7_POUTE2_POS                (2U)
#define PORT_POER7_POUTE2                    ((uint8_t)0x04U)
#define PORT_POER7_POUTE3_POS                (3U)
#define PORT_POER7_POUTE3                    ((uint8_t)0x08U)

/*  Bit definition for PORT_POER12 register  */
#define PORT_POER12_POUTE0_POS               (0U)
#define PORT_POER12_POUTE0                   ((uint8_t)0x01U)
#define PORT_POER12_POUTE1_POS               (1U)
#define PORT_POER12_POUTE1                   ((uint8_t)0x02U)
#define PORT_POER12_POUTE2_POS               (2U)
#define PORT_POER12_POUTE2                   ((uint8_t)0x04U)
#define PORT_POER12_POUTE3_POS               (3U)
#define PORT_POER12_POUTE3                   ((uint8_t)0x08U)
#define PORT_POER12_POUTE4_POS               (4U)
#define PORT_POER12_POUTE4                   ((uint8_t)0x10U)

/*  Bit definition for PORT_POER13 register  */
#define PORT_POER13_POUTE7_POS               (7U)
#define PORT_POER13_POUTE7                   ((uint8_t)0x80U)

/*  Bit definition for PORT_POER14 register  */
#define PORT_POER14_POUTE6_POS               (6U)
#define PORT_POER14_POUTE6                   ((uint8_t)0x40U)
#define PORT_POER14_POUTE7_POS               (7U)
#define PORT_POER14_POUTE7                   ((uint8_t)0x80U)

/*  Bit definition for PORT_POSR0 register  */
#define PORT_POSR0_POS0_POS                  (0U)
#define PORT_POSR0_POS0                      ((uint8_t)0x01U)
#define PORT_POSR0_POS1_POS                  (1U)
#define PORT_POSR0_POS1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POSR1 register  */
#define PORT_POSR1_POS0_POS                  (0U)
#define PORT_POSR1_POS0                      ((uint8_t)0x01U)
#define PORT_POSR1_POS1_POS                  (1U)
#define PORT_POSR1_POS1                      ((uint8_t)0x02U)
#define PORT_POSR1_POS2_POS                  (2U)
#define PORT_POSR1_POS2                      ((uint8_t)0x04U)
#define PORT_POSR1_POS3_POS                  (3U)
#define PORT_POSR1_POS3                      ((uint8_t)0x08U)
#define PORT_POSR1_POS4_POS                  (4U)
#define PORT_POSR1_POS4                      ((uint8_t)0x10U)
#define PORT_POSR1_POS5_POS                  (5U)
#define PORT_POSR1_POS5                      ((uint8_t)0x20U)
#define PORT_POSR1_POS6_POS                  (6U)
#define PORT_POSR1_POS6                      ((uint8_t)0x40U)
#define PORT_POSR1_POS7_POS                  (7U)
#define PORT_POSR1_POS7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_POSR2 register  */
#define PORT_POSR2_POS0_POS                  (0U)
#define PORT_POSR2_POS0                      ((uint8_t)0x01U)
#define PORT_POSR2_POS1_POS                  (1U)
#define PORT_POSR2_POS1                      ((uint8_t)0x02U)
#define PORT_POSR2_POS2_POS                  (2U)
#define PORT_POSR2_POS2                      ((uint8_t)0x04U)
#define PORT_POSR2_POS3_POS                  (3U)
#define PORT_POSR2_POS3                      ((uint8_t)0x08U)
#define PORT_POSR2_POS4_POS                  (4U)
#define PORT_POSR2_POS4                      ((uint8_t)0x10U)
#define PORT_POSR2_POS5_POS                  (5U)
#define PORT_POSR2_POS5                      ((uint8_t)0x20U)
#define PORT_POSR2_POS6_POS                  (6U)
#define PORT_POSR2_POS6                      ((uint8_t)0x40U)
#define PORT_POSR2_POS7_POS                  (7U)
#define PORT_POSR2_POS7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_POSR3 register  */
#define PORT_POSR3_POS0_POS                  (0U)
#define PORT_POSR3_POS0                      ((uint8_t)0x01U)
#define PORT_POSR3_POS1_POS                  (1U)
#define PORT_POSR3_POS1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POSR4 register  */
#define PORT_POSR4_POS0_POS                  (0U)
#define PORT_POSR4_POS0                      ((uint8_t)0x01U)
#define PORT_POSR4_POS1_POS                  (1U)
#define PORT_POSR4_POS1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POSR5 register  */
#define PORT_POSR5_POS0_POS                  (0U)
#define PORT_POSR5_POS0                      ((uint8_t)0x01U)
#define PORT_POSR5_POS1_POS                  (1U)
#define PORT_POSR5_POS1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POSR6 register  */
#define PORT_POSR6_POS0_POS                  (0U)
#define PORT_POSR6_POS0                      ((uint8_t)0x01U)
#define PORT_POSR6_POS1_POS                  (1U)
#define PORT_POSR6_POS1                      ((uint8_t)0x02U)
#define PORT_POSR6_POS2_POS                  (2U)
#define PORT_POSR6_POS2                      ((uint8_t)0x04U)
#define PORT_POSR6_POS3_POS                  (3U)
#define PORT_POSR6_POS3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_POSR7 register  */
#define PORT_POSR7_POS0_POS                  (0U)
#define PORT_POSR7_POS0                      ((uint8_t)0x01U)
#define PORT_POSR7_POS1_POS                  (1U)
#define PORT_POSR7_POS1                      ((uint8_t)0x02U)
#define PORT_POSR7_POS2_POS                  (2U)
#define PORT_POSR7_POS2                      ((uint8_t)0x04U)
#define PORT_POSR7_POS3_POS                  (3U)
#define PORT_POSR7_POS3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_POSR12 register  */
#define PORT_POSR12_POS0_POS                 (0U)
#define PORT_POSR12_POS0                     ((uint8_t)0x01U)
#define PORT_POSR12_POS1_POS                 (1U)
#define PORT_POSR12_POS1                     ((uint8_t)0x02U)
#define PORT_POSR12_POS2_POS                 (2U)
#define PORT_POSR12_POS2                     ((uint8_t)0x04U)
#define PORT_POSR12_POS3_POS                 (3U)
#define PORT_POSR12_POS3                     ((uint8_t)0x08U)
#define PORT_POSR12_POS4_POS                 (4U)
#define PORT_POSR12_POS4                     ((uint8_t)0x10U)

/*  Bit definition for PORT_POSR13 register  */
#define PORT_POSR13_POS7_POS                 (7U)
#define PORT_POSR13_POS7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_POSR14 register  */
#define PORT_POSR14_POS6_POS                 (6U)
#define PORT_POSR14_POS6                     ((uint8_t)0x40U)
#define PORT_POSR14_POS7_POS                 (7U)
#define PORT_POSR14_POS7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PORR0 register  */
#define PORT_PORR0_POR0_POS                  (0U)
#define PORT_PORR0_POR0                      ((uint8_t)0x01U)
#define PORT_PORR0_POR1_POS                  (1U)
#define PORT_PORR0_POR1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PORR1 register  */
#define PORT_PORR1_POR0_POS                  (0U)
#define PORT_PORR1_POR0                      ((uint8_t)0x01U)
#define PORT_PORR1_POR1_POS                  (1U)
#define PORT_PORR1_POR1                      ((uint8_t)0x02U)
#define PORT_PORR1_POR2_POS                  (2U)
#define PORT_PORR1_POR2                      ((uint8_t)0x04U)
#define PORT_PORR1_POR3_POS                  (3U)
#define PORT_PORR1_POR3                      ((uint8_t)0x08U)
#define PORT_PORR1_POR4_POS                  (4U)
#define PORT_PORR1_POR4                      ((uint8_t)0x10U)
#define PORT_PORR1_POR5_POS                  (5U)
#define PORT_PORR1_POR5                      ((uint8_t)0x20U)
#define PORT_PORR1_POR6_POS                  (6U)
#define PORT_PORR1_POR6                      ((uint8_t)0x40U)
#define PORT_PORR1_POR7_POS                  (7U)
#define PORT_PORR1_POR7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_PORR2 register  */
#define PORT_PORR2_POR0_POS                  (0U)
#define PORT_PORR2_POR0                      ((uint8_t)0x01U)
#define PORT_PORR2_POR1_POS                  (1U)
#define PORT_PORR2_POR1                      ((uint8_t)0x02U)
#define PORT_PORR2_POR2_POS                  (2U)
#define PORT_PORR2_POR2                      ((uint8_t)0x04U)
#define PORT_PORR2_POR3_POS                  (3U)
#define PORT_PORR2_POR3                      ((uint8_t)0x08U)
#define PORT_PORR2_POR4_POS                  (4U)
#define PORT_PORR2_POR4                      ((uint8_t)0x10U)
#define PORT_PORR2_POR5_POS                  (5U)
#define PORT_PORR2_POR5                      ((uint8_t)0x20U)
#define PORT_PORR2_POR6_POS                  (6U)
#define PORT_PORR2_POR6                      ((uint8_t)0x40U)
#define PORT_PORR2_POR7_POS                  (7U)
#define PORT_PORR2_POR7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_PORR3 register  */
#define PORT_PORR3_POR0_POS                  (0U)
#define PORT_PORR3_POR0                      ((uint8_t)0x01U)
#define PORT_PORR3_POR1_POS                  (1U)
#define PORT_PORR3_POR1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PORR4 register  */
#define PORT_PORR4_POR0_POS                  (0U)
#define PORT_PORR4_POR0                      ((uint8_t)0x01U)
#define PORT_PORR4_POR1_POS                  (1U)
#define PORT_PORR4_POR1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PORR5 register  */
#define PORT_PORR5_POR0_POS                  (0U)
#define PORT_PORR5_POR0                      ((uint8_t)0x01U)
#define PORT_PORR5_POR1_POS                  (1U)
#define PORT_PORR5_POR1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_PORR6 register  */
#define PORT_PORR6_POR0_POS                  (0U)
#define PORT_PORR6_POR0                      ((uint8_t)0x01U)
#define PORT_PORR6_POR1_POS                  (1U)
#define PORT_PORR6_POR1                      ((uint8_t)0x02U)
#define PORT_PORR6_POR2_POS                  (2U)
#define PORT_PORR6_POR2                      ((uint8_t)0x04U)
#define PORT_PORR6_POR3_POS                  (3U)
#define PORT_PORR6_POR3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_PORR7 register  */
#define PORT_PORR7_POR0_POS                  (0U)
#define PORT_PORR7_POR0                      ((uint8_t)0x01U)
#define PORT_PORR7_POR1_POS                  (1U)
#define PORT_PORR7_POR1                      ((uint8_t)0x02U)
#define PORT_PORR7_POR2_POS                  (2U)
#define PORT_PORR7_POR2                      ((uint8_t)0x04U)
#define PORT_PORR7_POR3_POS                  (3U)
#define PORT_PORR7_POR3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_PORR12 register  */
#define PORT_PORR12_POR0_POS                 (0U)
#define PORT_PORR12_POR0                     ((uint8_t)0x01U)
#define PORT_PORR12_POR1_POS                 (1U)
#define PORT_PORR12_POR1                     ((uint8_t)0x02U)
#define PORT_PORR12_POR2_POS                 (2U)
#define PORT_PORR12_POR2                     ((uint8_t)0x04U)
#define PORT_PORR12_POR3_POS                 (3U)
#define PORT_PORR12_POR3                     ((uint8_t)0x08U)
#define PORT_PORR12_POR4_POS                 (4U)
#define PORT_PORR12_POR4                     ((uint8_t)0x10U)

/*  Bit definition for PORT_PORR13 register  */
#define PORT_PORR13_POR7_POS                 (7U)
#define PORT_PORR13_POR7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PORR14 register  */
#define PORT_PORR14_POR6_POS                 (6U)
#define PORT_PORR14_POR6                     ((uint8_t)0x40U)
#define PORT_PORR14_POR7_POS                 (7U)
#define PORT_PORR14_POR7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_POTR0 register  */
#define PORT_POTR0_POT0_POS                  (0U)
#define PORT_POTR0_POT0                      ((uint8_t)0x01U)
#define PORT_POTR0_POT1_POS                  (1U)
#define PORT_POTR0_POT1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POTR1 register  */
#define PORT_POTR1_POT0_POS                  (0U)
#define PORT_POTR1_POT0                      ((uint8_t)0x01U)
#define PORT_POTR1_POT1_POS                  (1U)
#define PORT_POTR1_POT1                      ((uint8_t)0x02U)
#define PORT_POTR1_POT2_POS                  (2U)
#define PORT_POTR1_POT2                      ((uint8_t)0x04U)
#define PORT_POTR1_POT3_POS                  (3U)
#define PORT_POTR1_POT3                      ((uint8_t)0x08U)
#define PORT_POTR1_POT4_POS                  (4U)
#define PORT_POTR1_POT4                      ((uint8_t)0x10U)
#define PORT_POTR1_POT5_POS                  (5U)
#define PORT_POTR1_POT5                      ((uint8_t)0x20U)
#define PORT_POTR1_POT6_POS                  (6U)
#define PORT_POTR1_POT6                      ((uint8_t)0x40U)
#define PORT_POTR1_POT7_POS                  (7U)
#define PORT_POTR1_POT7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_POTR2 register  */
#define PORT_POTR2_POT0_POS                  (0U)
#define PORT_POTR2_POT0                      ((uint8_t)0x01U)
#define PORT_POTR2_POT1_POS                  (1U)
#define PORT_POTR2_POT1                      ((uint8_t)0x02U)
#define PORT_POTR2_POT2_POS                  (2U)
#define PORT_POTR2_POT2                      ((uint8_t)0x04U)
#define PORT_POTR2_POT3_POS                  (3U)
#define PORT_POTR2_POT3                      ((uint8_t)0x08U)
#define PORT_POTR2_POT4_POS                  (4U)
#define PORT_POTR2_POT4                      ((uint8_t)0x10U)
#define PORT_POTR2_POT5_POS                  (5U)
#define PORT_POTR2_POT5                      ((uint8_t)0x20U)
#define PORT_POTR2_POT6_POS                  (6U)
#define PORT_POTR2_POT6                      ((uint8_t)0x40U)
#define PORT_POTR2_POT7_POS                  (7U)
#define PORT_POTR2_POT7                      ((uint8_t)0x80U)

/*  Bit definition for PORT_POTR3 register  */
#define PORT_POTR3_POT0_POS                  (0U)
#define PORT_POTR3_POT0                      ((uint8_t)0x01U)
#define PORT_POTR3_POT1_POS                  (1U)
#define PORT_POTR3_POT1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POTR4 register  */
#define PORT_POTR4_POT0_POS                  (0U)
#define PORT_POTR4_POT0                      ((uint8_t)0x01U)
#define PORT_POTR4_POT1_POS                  (1U)
#define PORT_POTR4_POT1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POTR5 register  */
#define PORT_POTR5_POT0_POS                  (0U)
#define PORT_POTR5_POT0                      ((uint8_t)0x01U)
#define PORT_POTR5_POT1_POS                  (1U)
#define PORT_POTR5_POT1                      ((uint8_t)0x02U)

/*  Bit definition for PORT_POTR6 register  */
#define PORT_POTR6_POT0_POS                  (0U)
#define PORT_POTR6_POT0                      ((uint8_t)0x01U)
#define PORT_POTR6_POT1_POS                  (1U)
#define PORT_POTR6_POT1                      ((uint8_t)0x02U)
#define PORT_POTR6_POT2_POS                  (2U)
#define PORT_POTR6_POT2                      ((uint8_t)0x04U)
#define PORT_POTR6_POT3_POS                  (3U)
#define PORT_POTR6_POT3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_POTR7 register  */
#define PORT_POTR7_POT0_POS                  (0U)
#define PORT_POTR7_POT0                      ((uint8_t)0x01U)
#define PORT_POTR7_POT1_POS                  (1U)
#define PORT_POTR7_POT1                      ((uint8_t)0x02U)
#define PORT_POTR7_POT2_POS                  (2U)
#define PORT_POTR7_POT2                      ((uint8_t)0x04U)
#define PORT_POTR7_POT3_POS                  (3U)
#define PORT_POTR7_POT3                      ((uint8_t)0x08U)

/*  Bit definition for PORT_POTR12 register  */
#define PORT_POTR12_POT0_POS                 (0U)
#define PORT_POTR12_POT0                     ((uint8_t)0x01U)
#define PORT_POTR12_POT1_POS                 (1U)
#define PORT_POTR12_POT1                     ((uint8_t)0x02U)
#define PORT_POTR12_POT2_POS                 (2U)
#define PORT_POTR12_POT2                     ((uint8_t)0x04U)
#define PORT_POTR12_POT3_POS                 (3U)
#define PORT_POTR12_POT3                     ((uint8_t)0x08U)
#define PORT_POTR12_POT4_POS                 (4U)
#define PORT_POTR12_POT4                     ((uint8_t)0x10U)

/*  Bit definition for PORT_POTR13 register  */
#define PORT_POTR13_POT7_POS                 (7U)
#define PORT_POTR13_POT7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_POTR14 register  */
#define PORT_POTR14_POT6_POS                 (6U)
#define PORT_POTR14_POT6                     ((uint8_t)0x40U)
#define PORT_POTR14_POT7_POS                 (7U)
#define PORT_POTR14_POT7                     ((uint8_t)0x80U)

/*  Bit definition for PORT_PCR register  */
#define PORT_PCR_POUT_POS                    (0U)
#define PORT_PCR_POUT                        ((uint16_t)0x0001U)
#define PORT_PCR_POUTE_POS                   (1U)
#define PORT_PCR_POUTE                       ((uint16_t)0x0002U)
#define PORT_PCR_NOD_POS                     (2U)
#define PORT_PCR_NOD                         ((uint16_t)0x0004U)
#define PORT_PCR_DRV_POS                     (4U)
#define PORT_PCR_DRV                         ((uint16_t)0x0010U)
#define PORT_PCR_LTE_POS                     (5U)
#define PORT_PCR_LTE                         ((uint16_t)0x0020U)
#define PORT_PCR_PUU_POS                     (6U)
#define PORT_PCR_PUU                         ((uint16_t)0x0040U)
#define PORT_PCR_PIN_POS                     (8U)
#define PORT_PCR_PIN                         ((uint16_t)0x0100U)
#define PORT_PCR_INVE_POS                    (9U)
#define PORT_PCR_INVE                        ((uint16_t)0x0200U)
#define PORT_PCR_CINSEL_POS                  (10U)
#define PORT_PCR_CINSEL                      ((uint16_t)0x0400U)
#define PORT_PCR_INTE_POS                    (11U)
#define PORT_PCR_INTE                        ((uint16_t)0x0800U)
#define PORT_PCR_FSEL_POS                    (12U)
#define PORT_PCR_FSEL                        ((uint16_t)0x7000U)
#define PORT_PCR_FSEL_0                      ((uint16_t)0x1000U)
#define PORT_PCR_FSEL_1                      ((uint16_t)0x2000U)
#define PORT_PCR_FSEL_2                      ((uint16_t)0x4000U)

/*  Bit definition for PORT_PSPCR register  */
#define PORT_PSPCR_SPFE_POS                  (0U)
#define PORT_PSPCR_SPFE                      ((uint16_t)0x0003U)
#define PORT_PSPCR_SPFE_0                    ((uint16_t)0x0001U)
#define PORT_PSPCR_SPFE_1                    ((uint16_t)0x0002U)

/*  Bit definition for PORT_PCCR register  */
#define PORT_PCCR_RDWT_POS                   (14U)
#define PORT_PCCR_RDWT                       ((uint16_t)0xC000U)
#define PORT_PCCR_RDWT_0                     ((uint16_t)0x4000U)
#define PORT_PCCR_RDWT_1                     ((uint16_t)0x8000U)

/*  Bit definition for PORT_PINAER register  */
#define PORT_PINAER_PINAE0_POS               (0U)
#define PORT_PINAER_PINAE0                   ((uint16_t)0x0001U)
#define PORT_PINAER_PINAE1_POS               (1U)
#define PORT_PINAER_PINAE1                   ((uint16_t)0x0002U)
#define PORT_PINAER_PINAE2_POS               (2U)
#define PORT_PINAER_PINAE2                   ((uint16_t)0x0004U)
#define PORT_PINAER_PINAE3_POS               (3U)
#define PORT_PINAER_PINAE3                   ((uint16_t)0x0008U)
#define PORT_PINAER_PINAE4_POS               (4U)
#define PORT_PINAER_PINAE4                   ((uint16_t)0x0010U)
#define PORT_PINAER_PINAE5_POS               (5U)
#define PORT_PINAER_PINAE5                   ((uint16_t)0x0020U)
#define PORT_PINAER_PINAE6_POS               (6U)
#define PORT_PINAER_PINAE6                   ((uint16_t)0x0040U)
#define PORT_PINAER_PINAE7_POS               (7U)
#define PORT_PINAER_PINAE7                   ((uint16_t)0x0080U)
#define PORT_PINAER_PINAE12_POS              (12U)
#define PORT_PINAER_PINAE12                  ((uint16_t)0x1000U)
#define PORT_PINAER_PINAE13_POS              (13U)
#define PORT_PINAER_PINAE13                  ((uint16_t)0x2000U)
#define PORT_PINAER_PINAE14_POS              (14U)
#define PORT_PINAER_PINAE14                  ((uint16_t)0x4000U)

/*  Bit definition for PORT_PWPR register  */
#define PORT_PWPR_WE_POS                     (0U)
#define PORT_PWPR_WE                         ((uint16_t)0x0001U)
#define PORT_PWPR_WP_POS                     (8U)
#define PORT_PWPR_WP                         ((uint16_t)0xFF00U)
#define PORT_PWPR_WP_0                       ((uint16_t)0x0100U)
#define PORT_PWPR_WP_1                       ((uint16_t)0x0200U)
#define PORT_PWPR_WP_2                       ((uint16_t)0x0400U)
#define PORT_PWPR_WP_3                       ((uint16_t)0x0800U)
#define PORT_PWPR_WP_4                       ((uint16_t)0x1000U)
#define PORT_PWPR_WP_5                       ((uint16_t)0x2000U)
#define PORT_PWPR_WP_6                       ((uint16_t)0x4000U)
#define PORT_PWPR_WP_7                       ((uint16_t)0x8000U)


/*******************************************************************************
                Bit definition for Peripheral PWC
*******************************************************************************/
/*  Bit definition for PWC_STPMCR register  */
#define PWC_STPMCR_CKSHRC_POS                (1U)
#define PWC_STPMCR_CKSHRC                    ((uint8_t)0x02U)
#define PWC_STPMCR_HAPORDIS_POS              (3U)
#define PWC_STPMCR_HAPORDIS                  ((uint8_t)0x08U)
#define PWC_STPMCR_STOP_POS                  (7U)
#define PWC_STPMCR_STOP                      ((uint8_t)0x80U)

/*  Bit definition for PWC_PWRC register  */
#define PWC_PWRC_PWDRV_POS                   (0U)
#define PWC_PWRC_PWDRV                       ((uint8_t)0x07U)
#define PWC_PWRC_PWDRV_0                     ((uint8_t)0x01U)
#define PWC_PWRC_PWDRV_1                     ((uint8_t)0x02U)
#define PWC_PWRC_PWDRV_2                     ((uint8_t)0x04U)
#define PWC_PWRC_PWMONSEL_POS                (4U)
#define PWC_PWRC_PWMONSEL                    ((uint8_t)0x10U)
#define PWC_PWRC_PWMONE_POS                  (5U)
#define PWC_PWRC_PWMONE                      ((uint8_t)0x20U)

/*  Bit definition for PWC_RAMCR register  */
#define PWC_RAMCR_RPRTA_POS                  (0U)
#define PWC_RAMCR_RPRTA                      ((uint8_t)0x03U)
#define PWC_RAMCR_RPRTA_0                    ((uint8_t)0x01U)
#define PWC_RAMCR_RPRTA_1                    ((uint8_t)0x02U)
#define PWC_RAMCR_RPERDIS_POS                (4U)
#define PWC_RAMCR_RPERDIS                    ((uint8_t)0x10U)
#define PWC_RAMCR_RPEF_POS                   (5U)
#define PWC_RAMCR_RPEF                       ((uint8_t)0x20U)

/*  Bit definition for PWC_LVDCSR register  */
#define PWC_LVDCSR_EXVCCINEN_POS             (0U)
#define PWC_LVDCSR_EXVCCINEN                 ((uint8_t)0x01U)
#define PWC_LVDCSR_LVIF_POS                  (3U)
#define PWC_LVDCSR_LVIF                      ((uint8_t)0x08U)
#define PWC_LVDCSR_DETF_POS                  (4U)
#define PWC_LVDCSR_DETF                      ((uint8_t)0x10U)
#define PWC_LVDCSR_CMPOE_POS                 (7U)
#define PWC_LVDCSR_CMPOE                     ((uint8_t)0x80U)

/*  Bit definition for PWC_FPRC register  */
#define PWC_FPRC_CKRWE_POS                   (0U)
#define PWC_FPRC_CKRWE                       ((uint16_t)0x0001U)
#define PWC_FPRC_PWRWE_POS                   (1U)
#define PWC_FPRC_PWRWE                       ((uint16_t)0x0002U)
#define PWC_FPRC_FPRCB2_POS                  (2U)
#define PWC_FPRC_FPRCB2                      ((uint16_t)0x0004U)
#define PWC_FPRC_LVRWE_POS                   (3U)
#define PWC_FPRC_LVRWE                       ((uint16_t)0x0008U)
#define PWC_FPRC_FPRCB4_POS                  (4U)
#define PWC_FPRC_FPRCB4                      ((uint16_t)0x0010U)
#define PWC_FPRC_FPRCB5_POS                  (5U)
#define PWC_FPRC_FPRCB5                      ((uint16_t)0x0020U)
#define PWC_FPRC_FPRCB6_POS                  (6U)
#define PWC_FPRC_FPRCB6                      ((uint16_t)0x0040U)
#define PWC_FPRC_FPRCB7_POS                  (7U)
#define PWC_FPRC_FPRCB7                      ((uint16_t)0x0080U)
#define PWC_FPRC_FPRCWE_POS                  (8U)
#define PWC_FPRC_FPRCWE                      ((uint16_t)0xFF00U)
#define PWC_FPRC_FPRCWE_0                    ((uint16_t)0x0100U)
#define PWC_FPRC_FPRCWE_1                    ((uint16_t)0x0200U)
#define PWC_FPRC_FPRCWE_2                    ((uint16_t)0x0400U)
#define PWC_FPRC_FPRCWE_3                    ((uint16_t)0x0800U)
#define PWC_FPRC_FPRCWE_4                    ((uint16_t)0x1000U)
#define PWC_FPRC_FPRCWE_5                    ((uint16_t)0x2000U)
#define PWC_FPRC_FPRCWE_6                    ((uint16_t)0x4000U)
#define PWC_FPRC_FPRCWE_7                    ((uint16_t)0x8000U)

/*  Bit definition for PWC_DBGC register  */
#define PWC_DBGC_DBGEN_POS                   (0U)
#define PWC_DBGC_DBGEN                       ((uint8_t)0x01U)


/*******************************************************************************
                Bit definition for Peripheral RMU
*******************************************************************************/
/*  Bit definition for RMU_RSTF0 register  */
#define RMU_RSTF0_PORF_POS                   (0U)
#define RMU_RSTF0_PORF                       ((uint16_t)0x0001U)
#define RMU_RSTF0_PINRF_POS                  (1U)
#define RMU_RSTF0_PINRF                      ((uint16_t)0x0002U)
#define RMU_RSTF0_LVRF_POS                   (2U)
#define RMU_RSTF0_LVRF                       ((uint16_t)0x0004U)
#define RMU_RSTF0_WDRF_POS                   (5U)
#define RMU_RSTF0_WDRF                       ((uint16_t)0x0020U)
#define RMU_RSTF0_SWRF_POS                   (8U)
#define RMU_RSTF0_SWRF                       ((uint16_t)0x0100U)
#define RMU_RSTF0_RAMPERF_POS                (10U)
#define RMU_RSTF0_RAMPERF                    ((uint16_t)0x0400U)
#define RMU_RSTF0_CPULKUPRF_POS              (12U)
#define RMU_RSTF0_CPULKUPRF                  ((uint16_t)0x1000U)
#define RMU_RSTF0_XTALERF_POS                (13U)
#define RMU_RSTF0_XTALERF                    ((uint16_t)0x2000U)
#define RMU_RSTF0_MULTIRF_POS                (14U)
#define RMU_RSTF0_MULTIRF                    ((uint16_t)0x4000U)
#define RMU_RSTF0_CLRF_POS                   (15U)
#define RMU_RSTF0_CLRF                       ((uint16_t)0x8000U)


/*******************************************************************************
                Bit definition for Peripheral RTC
*******************************************************************************/
/*  Bit definition for RTC_CR0 register  */
#define RTC_CR0_RESET_POS                    (0U)
#define RTC_CR0_RESET                        ((uint8_t)0x01U)

/*  Bit definition for RTC_CR1 register  */
#define RTC_CR1_PRDS_POS                     (0U)
#define RTC_CR1_PRDS                         ((uint8_t)0x07U)
#define RTC_CR1_PRDS_0                       ((uint8_t)0x01U)
#define RTC_CR1_PRDS_1                       ((uint8_t)0x02U)
#define RTC_CR1_PRDS_2                       ((uint8_t)0x04U)
#define RTC_CR1_AMPM_POS                     (3U)
#define RTC_CR1_AMPM                         ((uint8_t)0x08U)
#define RTC_CR1_ONEHZOE_POS                  (5U)
#define RTC_CR1_ONEHZOE                      ((uint8_t)0x20U)
#define RTC_CR1_START_POS                    (7U)
#define RTC_CR1_START                        ((uint8_t)0x80U)

/*  Bit definition for RTC_CR2 register  */
#define RTC_CR2_WAIT_POS                     (0U)
#define RTC_CR2_WAIT                         ((uint8_t)0x01U)
#define RTC_CR2_WAITF_POS                    (1U)
#define RTC_CR2_WAITF                        ((uint8_t)0x02U)
#define RTC_CR2_PRDF_POS                     (2U)
#define RTC_CR2_PRDF                         ((uint8_t)0x04U)
#define RTC_CR2_ALMF_POS                     (3U)
#define RTC_CR2_ALMF                         ((uint8_t)0x08U)
#define RTC_CR2_PRDIE_POS                    (5U)
#define RTC_CR2_PRDIE                        ((uint8_t)0x20U)
#define RTC_CR2_ALMIE_POS                    (6U)
#define RTC_CR2_ALMIE                        ((uint8_t)0x40U)
#define RTC_CR2_ALME_POS                     (7U)
#define RTC_CR2_ALME                         ((uint8_t)0x80U)

/*  Bit definition for RTC_CR3 register  */
#define RTC_CR3_LRCEN_POS                    (4U)
#define RTC_CR3_LRCEN                        ((uint8_t)0x10U)
#define RTC_CR3_RCKSEL_POS                   (7U)
#define RTC_CR3_RCKSEL                       ((uint8_t)0x80U)

/*  Bit definition for RTC_SEC register  */
#define RTC_SEC_SECU_POS                     (0U)
#define RTC_SEC_SECU                         ((uint8_t)0x0FU)
#define RTC_SEC_SECU_0                       ((uint8_t)0x01U)
#define RTC_SEC_SECU_1                       ((uint8_t)0x02U)
#define RTC_SEC_SECU_2                       ((uint8_t)0x04U)
#define RTC_SEC_SECU_3                       ((uint8_t)0x08U)
#define RTC_SEC_SECD_POS                     (4U)
#define RTC_SEC_SECD                         ((uint8_t)0x70U)
#define RTC_SEC_SECD_0                       ((uint8_t)0x10U)
#define RTC_SEC_SECD_1                       ((uint8_t)0x20U)
#define RTC_SEC_SECD_2                       ((uint8_t)0x40U)

/*  Bit definition for RTC_MIN register  */
#define RTC_MIN_MINU_POS                     (0U)
#define RTC_MIN_MINU                         ((uint8_t)0x0FU)
#define RTC_MIN_MINU_0                       ((uint8_t)0x01U)
#define RTC_MIN_MINU_1                       ((uint8_t)0x02U)
#define RTC_MIN_MINU_2                       ((uint8_t)0x04U)
#define RTC_MIN_MINU_3                       ((uint8_t)0x08U)
#define RTC_MIN_MIND_POS                     (4U)
#define RTC_MIN_MIND                         ((uint8_t)0x70U)
#define RTC_MIN_MIND_0                       ((uint8_t)0x10U)
#define RTC_MIN_MIND_1                       ((uint8_t)0x20U)
#define RTC_MIN_MIND_2                       ((uint8_t)0x40U)

/*  Bit definition for RTC_HOUR register  */
#define RTC_HOUR_HOURU_POS                   (0U)
#define RTC_HOUR_HOURU                       ((uint8_t)0x0FU)
#define RTC_HOUR_HOURU_0                     ((uint8_t)0x01U)
#define RTC_HOUR_HOURU_1                     ((uint8_t)0x02U)
#define RTC_HOUR_HOURU_2                     ((uint8_t)0x04U)
#define RTC_HOUR_HOURU_3                     ((uint8_t)0x08U)
#define RTC_HOUR_HOURD_POS                   (4U)
#define RTC_HOUR_HOURD                       ((uint8_t)0x30U)
#define RTC_HOUR_HOURD_0                     ((uint8_t)0x10U)
#define RTC_HOUR_HOURD_1                     ((uint8_t)0x20U)

/*  Bit definition for RTC_WEEK register  */
#define RTC_WEEK_WEEK_POS                    (0U)
#define RTC_WEEK_WEEK                        ((uint8_t)0x07U)
#define RTC_WEEK_WEEK_0                      ((uint8_t)0x01U)
#define RTC_WEEK_WEEK_1                      ((uint8_t)0x02U)
#define RTC_WEEK_WEEK_2                      ((uint8_t)0x04U)

/*  Bit definition for RTC_DAY register  */
#define RTC_DAY_DAYU_POS                     (0U)
#define RTC_DAY_DAYU                         ((uint8_t)0x0FU)
#define RTC_DAY_DAYU_0                       ((uint8_t)0x01U)
#define RTC_DAY_DAYU_1                       ((uint8_t)0x02U)
#define RTC_DAY_DAYU_2                       ((uint8_t)0x04U)
#define RTC_DAY_DAYU_3                       ((uint8_t)0x08U)
#define RTC_DAY_DAYD_POS                     (4U)
#define RTC_DAY_DAYD                         ((uint8_t)0x30U)
#define RTC_DAY_DAYD_0                       ((uint8_t)0x10U)
#define RTC_DAY_DAYD_1                       ((uint8_t)0x20U)

/*  Bit definition for RTC_MON register  */
#define RTC_MON_MON_POS                      (0U)
#define RTC_MON_MON                          ((uint8_t)0x1FU)
#define RTC_MON_MON_0                        ((uint8_t)0x01U)
#define RTC_MON_MON_1                        ((uint8_t)0x02U)
#define RTC_MON_MON_2                        ((uint8_t)0x04U)
#define RTC_MON_MON_3                        ((uint8_t)0x08U)
#define RTC_MON_MON_4                        ((uint8_t)0x10U)

/*  Bit definition for RTC_YEAR register  */
#define RTC_YEAR_YEARU_POS                   (0U)
#define RTC_YEAR_YEARU                       ((uint8_t)0x0FU)
#define RTC_YEAR_YEARU_0                     ((uint8_t)0x01U)
#define RTC_YEAR_YEARU_1                     ((uint8_t)0x02U)
#define RTC_YEAR_YEARU_2                     ((uint8_t)0x04U)
#define RTC_YEAR_YEARU_3                     ((uint8_t)0x08U)
#define RTC_YEAR_YEARD_POS                   (4U)
#define RTC_YEAR_YEARD                       ((uint8_t)0xF0U)
#define RTC_YEAR_YEARD_0                     ((uint8_t)0x10U)
#define RTC_YEAR_YEARD_1                     ((uint8_t)0x20U)
#define RTC_YEAR_YEARD_2                     ((uint8_t)0x40U)
#define RTC_YEAR_YEARD_3                     ((uint8_t)0x80U)

/*  Bit definition for RTC_ALMMIN register  */
#define RTC_ALMMIN_ALMMINU_POS               (0U)
#define RTC_ALMMIN_ALMMINU                   ((uint8_t)0x0FU)
#define RTC_ALMMIN_ALMMINU_0                 ((uint8_t)0x01U)
#define RTC_ALMMIN_ALMMINU_1                 ((uint8_t)0x02U)
#define RTC_ALMMIN_ALMMINU_2                 ((uint8_t)0x04U)
#define RTC_ALMMIN_ALMMINU_3                 ((uint8_t)0x08U)
#define RTC_ALMMIN_ALMMIND_POS               (4U)
#define RTC_ALMMIN_ALMMIND                   ((uint8_t)0x70U)
#define RTC_ALMMIN_ALMMIND_0                 ((uint8_t)0x10U)
#define RTC_ALMMIN_ALMMIND_1                 ((uint8_t)0x20U)
#define RTC_ALMMIN_ALMMIND_2                 ((uint8_t)0x40U)

/*  Bit definition for RTC_ALMHOUR register  */
#define RTC_ALMHOUR_ALMHOURU_POS             (0U)
#define RTC_ALMHOUR_ALMHOURU                 ((uint8_t)0x0FU)
#define RTC_ALMHOUR_ALMHOURU_0               ((uint8_t)0x01U)
#define RTC_ALMHOUR_ALMHOURU_1               ((uint8_t)0x02U)
#define RTC_ALMHOUR_ALMHOURU_2               ((uint8_t)0x04U)
#define RTC_ALMHOUR_ALMHOURU_3               ((uint8_t)0x08U)
#define RTC_ALMHOUR_ALMHOURD_POS             (4U)
#define RTC_ALMHOUR_ALMHOURD                 ((uint8_t)0x30U)
#define RTC_ALMHOUR_ALMHOURD_0               ((uint8_t)0x10U)
#define RTC_ALMHOUR_ALMHOURD_1               ((uint8_t)0x20U)

/*  Bit definition for RTC_ALMWEEK register  */
#define RTC_ALMWEEK_ALMWEEK_POS              (0U)
#define RTC_ALMWEEK_ALMWEEK                  ((uint8_t)0x7FU)
#define RTC_ALMWEEK_ALMWEEK_0                ((uint8_t)0x01U)
#define RTC_ALMWEEK_ALMWEEK_1                ((uint8_t)0x02U)
#define RTC_ALMWEEK_ALMWEEK_2                ((uint8_t)0x04U)
#define RTC_ALMWEEK_ALMWEEK_3                ((uint8_t)0x08U)
#define RTC_ALMWEEK_ALMWEEK_4                ((uint8_t)0x10U)
#define RTC_ALMWEEK_ALMWEEK_5                ((uint8_t)0x20U)
#define RTC_ALMWEEK_ALMWEEK_6                ((uint8_t)0x40U)

/*  Bit definition for RTC_ERRCRH register  */
#define RTC_ERRCRH_COMP8_POS                 (0U)
#define RTC_ERRCRH_COMP8                     ((uint8_t)0x01U)
#define RTC_ERRCRH_COMPEN_POS                (7U)
#define RTC_ERRCRH_COMPEN                    ((uint8_t)0x80U)

/*  Bit definition for RTC_ERRCRL register  */
#define RTC_ERRCRL_COMP_POS                  (0U)
#define RTC_ERRCRL_COMP                      ((uint8_t)0xFFU)
#define RTC_ERRCRL_COMP_0                    ((uint8_t)0x01U)
#define RTC_ERRCRL_COMP_1                    ((uint8_t)0x02U)
#define RTC_ERRCRL_COMP_2                    ((uint8_t)0x04U)
#define RTC_ERRCRL_COMP_3                    ((uint8_t)0x08U)
#define RTC_ERRCRL_COMP_4                    ((uint8_t)0x10U)
#define RTC_ERRCRL_COMP_5                    ((uint8_t)0x20U)
#define RTC_ERRCRL_COMP_6                    ((uint8_t)0x40U)
#define RTC_ERRCRL_COMP_7                    ((uint8_t)0x80U)


/*******************************************************************************
                Bit definition for Peripheral SPI
*******************************************************************************/
/*  Bit definition for SPI_DR register  */
#define SPI_DR_SPD_POS                       (0U)
#define SPI_DR_SPD                           ((uint32_t)0x0000FFFFU)
#define SPI_DR_SPD_0                         ((uint32_t)0x00000001U)
#define SPI_DR_SPD_1                         ((uint32_t)0x00000002U)
#define SPI_DR_SPD_2                         ((uint32_t)0x00000004U)
#define SPI_DR_SPD_3                         ((uint32_t)0x00000008U)
#define SPI_DR_SPD_4                         ((uint32_t)0x00000010U)
#define SPI_DR_SPD_5                         ((uint32_t)0x00000020U)
#define SPI_DR_SPD_6                         ((uint32_t)0x00000040U)
#define SPI_DR_SPD_7                         ((uint32_t)0x00000080U)
#define SPI_DR_SPD_8                         ((uint32_t)0x00000100U)
#define SPI_DR_SPD_9                         ((uint32_t)0x00000200U)
#define SPI_DR_SPD_10                        ((uint32_t)0x00000400U)
#define SPI_DR_SPD_11                        ((uint32_t)0x00000800U)
#define SPI_DR_SPD_12                        ((uint32_t)0x00001000U)
#define SPI_DR_SPD_13                        ((uint32_t)0x00002000U)
#define SPI_DR_SPD_14                        ((uint32_t)0x00004000U)
#define SPI_DR_SPD_15                        ((uint32_t)0x00008000U)

/*  Bit definition for SPI_CR1 register  */
#define SPI_CR1_SPIMDS_POS                   (0U)
#define SPI_CR1_SPIMDS                       ((uint32_t)0x00000001U)
#define SPI_CR1_TXMDS_POS                    (1U)
#define SPI_CR1_TXMDS                        ((uint32_t)0x00000002U)
#define SPI_CR1_MSTR_POS                     (3U)
#define SPI_CR1_MSTR                         ((uint32_t)0x00000008U)
#define SPI_CR1_SPLPBK_POS                   (4U)
#define SPI_CR1_SPLPBK                       ((uint32_t)0x00000010U)
#define SPI_CR1_SPLPBK2_POS                  (5U)
#define SPI_CR1_SPLPBK2                      ((uint32_t)0x00000020U)
#define SPI_CR1_SPE_POS                      (6U)
#define SPI_CR1_SPE                          ((uint32_t)0x00000040U)
#define SPI_CR1_EIE_POS                      (8U)
#define SPI_CR1_EIE                          ((uint32_t)0x00000100U)
#define SPI_CR1_TXIE_POS                     (9U)
#define SPI_CR1_TXIE                         ((uint32_t)0x00000200U)
#define SPI_CR1_RXIE_POS                     (10U)
#define SPI_CR1_RXIE                         ((uint32_t)0x00000400U)
#define SPI_CR1_IDIE_POS                     (11U)
#define SPI_CR1_IDIE                         ((uint32_t)0x00000800U)
#define SPI_CR1_MODFE_POS                    (12U)
#define SPI_CR1_MODFE                        ((uint32_t)0x00001000U)
#define SPI_CR1_PATE_POS                     (13U)
#define SPI_CR1_PATE                         ((uint32_t)0x00002000U)
#define SPI_CR1_PAOE_POS                     (14U)
#define SPI_CR1_PAOE                         ((uint32_t)0x00004000U)
#define SPI_CR1_PAE_POS                      (15U)
#define SPI_CR1_PAE                          ((uint32_t)0x00008000U)

/*  Bit definition for SPI_CFG1 register  */
#define SPI_CFG1_SS0PV_POS                   (8U)
#define SPI_CFG1_SS0PV                       ((uint32_t)0x00000100U)

/*  Bit definition for SPI_SR register  */
#define SPI_SR_OVRERF_POS                    (0U)
#define SPI_SR_OVRERF                        ((uint32_t)0x00000001U)
#define SPI_SR_IDLNF_POS                     (1U)
#define SPI_SR_IDLNF                         ((uint32_t)0x00000002U)
#define SPI_SR_MODFERF_POS                   (2U)
#define SPI_SR_MODFERF                       ((uint32_t)0x00000004U)
#define SPI_SR_PERF_POS                      (3U)
#define SPI_SR_PERF                          ((uint32_t)0x00000008U)
#define SPI_SR_UDRERF_POS                    (4U)
#define SPI_SR_UDRERF                        ((uint32_t)0x00000010U)
#define SPI_SR_TDEF_POS                      (5U)
#define SPI_SR_TDEF                          ((uint32_t)0x00000020U)
#define SPI_SR_RDFF_POS                      (7U)
#define SPI_SR_RDFF                          ((uint32_t)0x00000080U)

/*  Bit definition for SPI_CFG2 register  */
#define SPI_CFG2_CPHA_POS                    (0U)
#define SPI_CFG2_CPHA                        ((uint32_t)0x00000001U)
#define SPI_CFG2_CPOL_POS                    (1U)
#define SPI_CFG2_CPOL                        ((uint32_t)0x00000002U)
#define SPI_CFG2_MBR_POS                     (2U)
#define SPI_CFG2_MBR                         ((uint32_t)0x0000001CU)
#define SPI_CFG2_MBR_0                       ((uint32_t)0x00000004U)
#define SPI_CFG2_MBR_1                       ((uint32_t)0x00000008U)
#define SPI_CFG2_MBR_2                       ((uint32_t)0x00000010U)
#define SPI_CFG2_DSIZE_POS                   (8U)
#define SPI_CFG2_DSIZE                       ((uint32_t)0x00000100U)
#define SPI_CFG2_LSBF_POS                    (11U)
#define SPI_CFG2_LSBF                        ((uint32_t)0x00000800U)


/*******************************************************************************
                Bit definition for Peripheral SWDT
*******************************************************************************/
/*  Bit definition for SWDT_CR register  */
#define SWDT_CR_PERI_POS                     (0U)
#define SWDT_CR_PERI                         ((uint32_t)0x00000003U)
#define SWDT_CR_PERI_0                       ((uint32_t)0x00000001U)
#define SWDT_CR_PERI_1                       ((uint32_t)0x00000002U)
#define SWDT_CR_CKS_POS                      (4U)
#define SWDT_CR_CKS                          ((uint32_t)0x000000F0U)
#define SWDT_CR_CKS_0                        ((uint32_t)0x00000010U)
#define SWDT_CR_CKS_1                        ((uint32_t)0x00000020U)
#define SWDT_CR_CKS_2                        ((uint32_t)0x00000040U)
#define SWDT_CR_CKS_3                        ((uint32_t)0x00000080U)
#define SWDT_CR_WDPT_POS                     (8U)
#define SWDT_CR_WDPT                         ((uint32_t)0x00000F00U)
#define SWDT_CR_WDPT_0                       ((uint32_t)0x00000100U)
#define SWDT_CR_WDPT_1                       ((uint32_t)0x00000200U)
#define SWDT_CR_WDPT_2                       ((uint32_t)0x00000400U)
#define SWDT_CR_WDPT_3                       ((uint32_t)0x00000800U)
#define SWDT_CR_SLPOFF_POS                   (16U)
#define SWDT_CR_SLPOFF                       ((uint32_t)0x00010000U)
#define SWDT_CR_ITS_POS                      (31U)
#define SWDT_CR_ITS                          ((uint32_t)0x80000000U)

/*  Bit definition for SWDT_SR register  */
#define SWDT_SR_CNT_POS                      (0U)
#define SWDT_SR_CNT                          ((uint32_t)0x0000FFFFU)
#define SWDT_SR_CNT_0                        ((uint32_t)0x00000001U)
#define SWDT_SR_CNT_1                        ((uint32_t)0x00000002U)
#define SWDT_SR_CNT_2                        ((uint32_t)0x00000004U)
#define SWDT_SR_CNT_3                        ((uint32_t)0x00000008U)
#define SWDT_SR_CNT_4                        ((uint32_t)0x00000010U)
#define SWDT_SR_CNT_5                        ((uint32_t)0x00000020U)
#define SWDT_SR_CNT_6                        ((uint32_t)0x00000040U)
#define SWDT_SR_CNT_7                        ((uint32_t)0x00000080U)
#define SWDT_SR_CNT_8                        ((uint32_t)0x00000100U)
#define SWDT_SR_CNT_9                        ((uint32_t)0x00000200U)
#define SWDT_SR_CNT_10                       ((uint32_t)0x00000400U)
#define SWDT_SR_CNT_11                       ((uint32_t)0x00000800U)
#define SWDT_SR_CNT_12                       ((uint32_t)0x00001000U)
#define SWDT_SR_CNT_13                       ((uint32_t)0x00002000U)
#define SWDT_SR_CNT_14                       ((uint32_t)0x00004000U)
#define SWDT_SR_CNT_15                       ((uint32_t)0x00008000U)
#define SWDT_SR_UDF_POS                      (16U)
#define SWDT_SR_UDF                          ((uint32_t)0x00010000U)
#define SWDT_SR_REF_POS                      (17U)
#define SWDT_SR_REF                          ((uint32_t)0x00020000U)

/*  Bit definition for SWDT_RR register  */
#define SWDT_RR_RF_POS                       (0U)
#define SWDT_RR_RF                           ((uint32_t)0x0000FFFFU)
#define SWDT_RR_RF_0                         ((uint32_t)0x00000001U)
#define SWDT_RR_RF_1                         ((uint32_t)0x00000002U)
#define SWDT_RR_RF_2                         ((uint32_t)0x00000004U)
#define SWDT_RR_RF_3                         ((uint32_t)0x00000008U)
#define SWDT_RR_RF_4                         ((uint32_t)0x00000010U)
#define SWDT_RR_RF_5                         ((uint32_t)0x00000020U)
#define SWDT_RR_RF_6                         ((uint32_t)0x00000040U)
#define SWDT_RR_RF_7                         ((uint32_t)0x00000080U)
#define SWDT_RR_RF_8                         ((uint32_t)0x00000100U)
#define SWDT_RR_RF_9                         ((uint32_t)0x00000200U)
#define SWDT_RR_RF_10                        ((uint32_t)0x00000400U)
#define SWDT_RR_RF_11                        ((uint32_t)0x00000800U)
#define SWDT_RR_RF_12                        ((uint32_t)0x00001000U)
#define SWDT_RR_RF_13                        ((uint32_t)0x00002000U)
#define SWDT_RR_RF_14                        ((uint32_t)0x00004000U)
#define SWDT_RR_RF_15                        ((uint32_t)0x00008000U)


/*******************************************************************************
                Bit definition for Peripheral TMR0
*******************************************************************************/
/*  Bit definition for TMR0_CNTAR register  */
#define TMR0_CNTAR_CNTA_POS                  (0U)
#define TMR0_CNTAR_CNTA                      ((uint32_t)0x0000FFFFU)
#define TMR0_CNTAR_CNTA_0                    ((uint32_t)0x00000001U)
#define TMR0_CNTAR_CNTA_1                    ((uint32_t)0x00000002U)
#define TMR0_CNTAR_CNTA_2                    ((uint32_t)0x00000004U)
#define TMR0_CNTAR_CNTA_3                    ((uint32_t)0x00000008U)
#define TMR0_CNTAR_CNTA_4                    ((uint32_t)0x00000010U)
#define TMR0_CNTAR_CNTA_5                    ((uint32_t)0x00000020U)
#define TMR0_CNTAR_CNTA_6                    ((uint32_t)0x00000040U)
#define TMR0_CNTAR_CNTA_7                    ((uint32_t)0x00000080U)
#define TMR0_CNTAR_CNTA_8                    ((uint32_t)0x00000100U)
#define TMR0_CNTAR_CNTA_9                    ((uint32_t)0x00000200U)
#define TMR0_CNTAR_CNTA_10                   ((uint32_t)0x00000400U)
#define TMR0_CNTAR_CNTA_11                   ((uint32_t)0x00000800U)
#define TMR0_CNTAR_CNTA_12                   ((uint32_t)0x00001000U)
#define TMR0_CNTAR_CNTA_13                   ((uint32_t)0x00002000U)
#define TMR0_CNTAR_CNTA_14                   ((uint32_t)0x00004000U)
#define TMR0_CNTAR_CNTA_15                   ((uint32_t)0x00008000U)

/*  Bit definition for TMR0_CMPAR register  */
#define TMR0_CMPAR_CMPA_POS                  (0U)
#define TMR0_CMPAR_CMPA                      ((uint32_t)0x0000FFFFU)
#define TMR0_CMPAR_CMPA_0                    ((uint32_t)0x00000001U)
#define TMR0_CMPAR_CMPA_1                    ((uint32_t)0x00000002U)
#define TMR0_CMPAR_CMPA_2                    ((uint32_t)0x00000004U)
#define TMR0_CMPAR_CMPA_3                    ((uint32_t)0x00000008U)
#define TMR0_CMPAR_CMPA_4                    ((uint32_t)0x00000010U)
#define TMR0_CMPAR_CMPA_5                    ((uint32_t)0x00000020U)
#define TMR0_CMPAR_CMPA_6                    ((uint32_t)0x00000040U)
#define TMR0_CMPAR_CMPA_7                    ((uint32_t)0x00000080U)
#define TMR0_CMPAR_CMPA_8                    ((uint32_t)0x00000100U)
#define TMR0_CMPAR_CMPA_9                    ((uint32_t)0x00000200U)
#define TMR0_CMPAR_CMPA_10                   ((uint32_t)0x00000400U)
#define TMR0_CMPAR_CMPA_11                   ((uint32_t)0x00000800U)
#define TMR0_CMPAR_CMPA_12                   ((uint32_t)0x00001000U)
#define TMR0_CMPAR_CMPA_13                   ((uint32_t)0x00002000U)
#define TMR0_CMPAR_CMPA_14                   ((uint32_t)0x00004000U)
#define TMR0_CMPAR_CMPA_15                   ((uint32_t)0x00008000U)

/*  Bit definition for TMR0_BCONR register  */
#define TMR0_BCONR_CSTA_POS                  (0U)
#define TMR0_BCONR_CSTA                      ((uint32_t)0x00000001U)
#define TMR0_BCONR_CAPMDA_POS                (1U)
#define TMR0_BCONR_CAPMDA                    ((uint32_t)0x00000002U)
#define TMR0_BCONR_INTENA_POS                (2U)
#define TMR0_BCONR_INTENA                    ((uint32_t)0x00000004U)
#define TMR0_BCONR_CKDIVA_POS                (4U)
#define TMR0_BCONR_CKDIVA                    ((uint32_t)0x000000F0U)
#define TMR0_BCONR_CKDIVA_0                  ((uint32_t)0x00000010U)
#define TMR0_BCONR_CKDIVA_1                  ((uint32_t)0x00000020U)
#define TMR0_BCONR_CKDIVA_2                  ((uint32_t)0x00000040U)
#define TMR0_BCONR_CKDIVA_3                  ((uint32_t)0x00000080U)
#define TMR0_BCONR_SYNSA_POS                 (8U)
#define TMR0_BCONR_SYNSA                     ((uint32_t)0x00000100U)
#define TMR0_BCONR_SYNCLKA_POS               (9U)
#define TMR0_BCONR_SYNCLKA                   ((uint32_t)0x00000200U)
#define TMR0_BCONR_ASYNCLKA_POS              (10U)
#define TMR0_BCONR_ASYNCLKA                  ((uint32_t)0x00000400U)
#define TMR0_BCONR_HSTAA_POS                 (12U)
#define TMR0_BCONR_HSTAA                     ((uint32_t)0x00001000U)
#define TMR0_BCONR_HSTPA_POS                 (13U)
#define TMR0_BCONR_HSTPA                     ((uint32_t)0x00002000U)
#define TMR0_BCONR_HCLEA_POS                 (14U)
#define TMR0_BCONR_HCLEA                     ((uint32_t)0x00004000U)
#define TMR0_BCONR_HICPA_POS                 (15U)
#define TMR0_BCONR_HICPA                     ((uint32_t)0x00008000U)

/*  Bit definition for TMR0_STFLR register  */
#define TMR0_STFLR_CMFA_POS                  (0U)
#define TMR0_STFLR_CMFA                      ((uint32_t)0x00000001U)


/*******************************************************************************
                Bit definition for Peripheral TMRB
*******************************************************************************/
/*  Bit definition for TMRB_CNTER register  */
#define TMRB_CNTER_CNT_POS                   (0U)
#define TMRB_CNTER_CNT                       ((uint16_t)0xFFFFU)
#define TMRB_CNTER_CNT_0                     ((uint16_t)0x0001U)
#define TMRB_CNTER_CNT_1                     ((uint16_t)0x0002U)
#define TMRB_CNTER_CNT_2                     ((uint16_t)0x0004U)
#define TMRB_CNTER_CNT_3                     ((uint16_t)0x0008U)
#define TMRB_CNTER_CNT_4                     ((uint16_t)0x0010U)
#define TMRB_CNTER_CNT_5                     ((uint16_t)0x0020U)
#define TMRB_CNTER_CNT_6                     ((uint16_t)0x0040U)
#define TMRB_CNTER_CNT_7                     ((uint16_t)0x0080U)
#define TMRB_CNTER_CNT_8                     ((uint16_t)0x0100U)
#define TMRB_CNTER_CNT_9                     ((uint16_t)0x0200U)
#define TMRB_CNTER_CNT_10                    ((uint16_t)0x0400U)
#define TMRB_CNTER_CNT_11                    ((uint16_t)0x0800U)
#define TMRB_CNTER_CNT_12                    ((uint16_t)0x1000U)
#define TMRB_CNTER_CNT_13                    ((uint16_t)0x2000U)
#define TMRB_CNTER_CNT_14                    ((uint16_t)0x4000U)
#define TMRB_CNTER_CNT_15                    ((uint16_t)0x8000U)

/*  Bit definition for TMRB_PERAR register  */
#define TMRB_PERAR_PER_POS                   (0U)
#define TMRB_PERAR_PER                       ((uint16_t)0xFFFFU)
#define TMRB_PERAR_PER_0                     ((uint16_t)0x0001U)
#define TMRB_PERAR_PER_1                     ((uint16_t)0x0002U)
#define TMRB_PERAR_PER_2                     ((uint16_t)0x0004U)
#define TMRB_PERAR_PER_3                     ((uint16_t)0x0008U)
#define TMRB_PERAR_PER_4                     ((uint16_t)0x0010U)
#define TMRB_PERAR_PER_5                     ((uint16_t)0x0020U)
#define TMRB_PERAR_PER_6                     ((uint16_t)0x0040U)
#define TMRB_PERAR_PER_7                     ((uint16_t)0x0080U)
#define TMRB_PERAR_PER_8                     ((uint16_t)0x0100U)
#define TMRB_PERAR_PER_9                     ((uint16_t)0x0200U)
#define TMRB_PERAR_PER_10                    ((uint16_t)0x0400U)
#define TMRB_PERAR_PER_11                    ((uint16_t)0x0800U)
#define TMRB_PERAR_PER_12                    ((uint16_t)0x1000U)
#define TMRB_PERAR_PER_13                    ((uint16_t)0x2000U)
#define TMRB_PERAR_PER_14                    ((uint16_t)0x4000U)
#define TMRB_PERAR_PER_15                    ((uint16_t)0x8000U)

/*  Bit definition for TMRB_CMPAR register  */
#define TMRB_CMPAR_CMP_POS                   (0U)
#define TMRB_CMPAR_CMP                       ((uint16_t)0xFFFFU)
#define TMRB_CMPAR_CMP_0                     ((uint16_t)0x0001U)
#define TMRB_CMPAR_CMP_1                     ((uint16_t)0x0002U)
#define TMRB_CMPAR_CMP_2                     ((uint16_t)0x0004U)
#define TMRB_CMPAR_CMP_3                     ((uint16_t)0x0008U)
#define TMRB_CMPAR_CMP_4                     ((uint16_t)0x0010U)
#define TMRB_CMPAR_CMP_5                     ((uint16_t)0x0020U)
#define TMRB_CMPAR_CMP_6                     ((uint16_t)0x0040U)
#define TMRB_CMPAR_CMP_7                     ((uint16_t)0x0080U)
#define TMRB_CMPAR_CMP_8                     ((uint16_t)0x0100U)
#define TMRB_CMPAR_CMP_9                     ((uint16_t)0x0200U)
#define TMRB_CMPAR_CMP_10                    ((uint16_t)0x0400U)
#define TMRB_CMPAR_CMP_11                    ((uint16_t)0x0800U)
#define TMRB_CMPAR_CMP_12                    ((uint16_t)0x1000U)
#define TMRB_CMPAR_CMP_13                    ((uint16_t)0x2000U)
#define TMRB_CMPAR_CMP_14                    ((uint16_t)0x4000U)
#define TMRB_CMPAR_CMP_15                    ((uint16_t)0x8000U)

/*  Bit definition for TMRB_BCSTR register  */
#define TMRB_BCSTR_START_POS                 (0U)
#define TMRB_BCSTR_START                     ((uint16_t)0x0001U)
#define TMRB_BCSTR_DIR_POS                   (1U)
#define TMRB_BCSTR_DIR                       ((uint16_t)0x0002U)
#define TMRB_BCSTR_MODE_POS                  (2U)
#define TMRB_BCSTR_MODE                      ((uint16_t)0x0004U)
#define TMRB_BCSTR_SYNST_POS                 (3U)
#define TMRB_BCSTR_SYNST                     ((uint16_t)0x0008U)
#define TMRB_BCSTR_CKDIV_POS                 (4U)
#define TMRB_BCSTR_CKDIV                     ((uint16_t)0x00F0U)
#define TMRB_BCSTR_CKDIV_0                   ((uint16_t)0x0010U)
#define TMRB_BCSTR_CKDIV_1                   ((uint16_t)0x0020U)
#define TMRB_BCSTR_CKDIV_2                   ((uint16_t)0x0040U)
#define TMRB_BCSTR_CKDIV_3                   ((uint16_t)0x0080U)
#define TMRB_BCSTR_OVSTP_POS                 (8U)
#define TMRB_BCSTR_OVSTP                     ((uint16_t)0x0100U)
#define TMRB_BCSTR_INENOVF_POS               (12U)
#define TMRB_BCSTR_INENOVF                   ((uint16_t)0x1000U)
#define TMRB_BCSTR_INENUDF_POS               (13U)
#define TMRB_BCSTR_INENUDF                   ((uint16_t)0x2000U)
#define TMRB_BCSTR_OVFF_POS                  (14U)
#define TMRB_BCSTR_OVFF                      ((uint16_t)0x4000U)
#define TMRB_BCSTR_UDFF_POS                  (15U)
#define TMRB_BCSTR_UDFF                      ((uint16_t)0x8000U)

/*  Bit definition for TMRB_HCONR register  */
#define TMRB_HCONR_HSTA0_POS                 (0U)
#define TMRB_HCONR_HSTA0                     ((uint16_t)0x0001U)
#define TMRB_HCONR_HSTA1_POS                 (1U)
#define TMRB_HCONR_HSTA1                     ((uint16_t)0x0002U)
#define TMRB_HCONR_HSTA2_POS                 (2U)
#define TMRB_HCONR_HSTA2                     ((uint16_t)0x0004U)
#define TMRB_HCONR_HSTP0_POS                 (4U)
#define TMRB_HCONR_HSTP0                     ((uint16_t)0x0010U)
#define TMRB_HCONR_HSTP1_POS                 (5U)
#define TMRB_HCONR_HSTP1                     ((uint16_t)0x0020U)
#define TMRB_HCONR_HSTP2_POS                 (6U)
#define TMRB_HCONR_HSTP2                     ((uint16_t)0x0040U)
#define TMRB_HCONR_HCLE0_POS                 (8U)
#define TMRB_HCONR_HCLE0                     ((uint16_t)0x0100U)
#define TMRB_HCONR_HCLE1_POS                 (9U)
#define TMRB_HCONR_HCLE1                     ((uint16_t)0x0200U)
#define TMRB_HCONR_HCLE2_POS                 (10U)
#define TMRB_HCONR_HCLE2                     ((uint16_t)0x0400U)
#define TMRB_HCONR_HCLE3_POS                 (12U)
#define TMRB_HCONR_HCLE3                     ((uint16_t)0x1000U)
#define TMRB_HCONR_HCLE4_POS                 (13U)
#define TMRB_HCONR_HCLE4                     ((uint16_t)0x2000U)

/*  Bit definition for TMRB_HCUPR register  */
#define TMRB_HCUPR_HCUP8_POS                 (8U)
#define TMRB_HCUPR_HCUP8                     ((uint16_t)0x0100U)
#define TMRB_HCUPR_HCUP9_POS                 (9U)
#define TMRB_HCUPR_HCUP9                     ((uint16_t)0x0200U)
#define TMRB_HCUPR_HCUP10_POS                (10U)
#define TMRB_HCUPR_HCUP10                    ((uint16_t)0x0400U)
#define TMRB_HCUPR_HCUP11_POS                (11U)
#define TMRB_HCUPR_HCUP11                    ((uint16_t)0x0800U)
#define TMRB_HCUPR_HCUP12_POS                (12U)
#define TMRB_HCUPR_HCUP12                    ((uint16_t)0x1000U)

/*  Bit definition for TMRB_HCDOR register  */
#define TMRB_HCDOR_HCDO8_POS                 (8U)
#define TMRB_HCDOR_HCDO8                     ((uint16_t)0x0100U)
#define TMRB_HCDOR_HCDO9_POS                 (9U)
#define TMRB_HCDOR_HCDO9                     ((uint16_t)0x0200U)
#define TMRB_HCDOR_HCDO10_POS                (10U)
#define TMRB_HCDOR_HCDO10                    ((uint16_t)0x0400U)
#define TMRB_HCDOR_HCDO11_POS                (11U)
#define TMRB_HCDOR_HCDO11                    ((uint16_t)0x0800U)
#define TMRB_HCDOR_HCDO12_POS                (12U)
#define TMRB_HCDOR_HCDO12                    ((uint16_t)0x1000U)

/*  Bit definition for TMRB_ICONR register  */
#define TMRB_ICONR_ITEN1_POS                 (0U)
#define TMRB_ICONR_ITEN1                     ((uint16_t)0x0001U)

/*  Bit definition for TMRB_ECONR register  */
#define TMRB_ECONR_ETEN1_POS                 (0U)
#define TMRB_ECONR_ETEN1                     ((uint16_t)0x0001U)

/*  Bit definition for TMRB_STFLR register  */
#define TMRB_STFLR_CMPF1_POS                 (0U)
#define TMRB_STFLR_CMPF1                     ((uint16_t)0x0001U)

/*  Bit definition for TMRB_CCONR register  */
#define TMRB_CCONR_CAPMDA_POS                (0U)
#define TMRB_CCONR_CAPMDA                    ((uint16_t)0x0001U)
#define TMRB_CCONR_HICP0_POS                 (4U)
#define TMRB_CCONR_HICP0                     ((uint16_t)0x0010U)
#define TMRB_CCONR_HICP1_POS                 (5U)
#define TMRB_CCONR_HICP1                     ((uint16_t)0x0020U)
#define TMRB_CCONR_HICP2_POS                 (6U)
#define TMRB_CCONR_HICP2                     ((uint16_t)0x0040U)
#define TMRB_CCONR_NOFIENCP_POS              (12U)
#define TMRB_CCONR_NOFIENCP                  ((uint16_t)0x1000U)
#define TMRB_CCONR_NOFICKCP_POS              (13U)
#define TMRB_CCONR_NOFICKCP                  ((uint16_t)0x6000U)
#define TMRB_CCONR_NOFICKCP_0                ((uint16_t)0x2000U)
#define TMRB_CCONR_NOFICKCP_1                ((uint16_t)0x4000U)

/*  Bit definition for TMRB_PCONR register  */
#define TMRB_PCONR_STAC_POS                  (0U)
#define TMRB_PCONR_STAC                      ((uint16_t)0x0003U)
#define TMRB_PCONR_STAC_0                    ((uint16_t)0x0001U)
#define TMRB_PCONR_STAC_1                    ((uint16_t)0x0002U)
#define TMRB_PCONR_STPC_POS                  (2U)
#define TMRB_PCONR_STPC                      ((uint16_t)0x000CU)
#define TMRB_PCONR_STPC_0                    ((uint16_t)0x0004U)
#define TMRB_PCONR_STPC_1                    ((uint16_t)0x0008U)
#define TMRB_PCONR_CMPC_POS                  (4U)
#define TMRB_PCONR_CMPC                      ((uint16_t)0x0030U)
#define TMRB_PCONR_CMPC_0                    ((uint16_t)0x0010U)
#define TMRB_PCONR_CMPC_1                    ((uint16_t)0x0020U)
#define TMRB_PCONR_PERC_POS                  (6U)
#define TMRB_PCONR_PERC                      ((uint16_t)0x00C0U)
#define TMRB_PCONR_PERC_0                    ((uint16_t)0x0040U)
#define TMRB_PCONR_PERC_1                    ((uint16_t)0x0080U)
#define TMRB_PCONR_FORC_POS                  (8U)
#define TMRB_PCONR_FORC                      ((uint16_t)0x0300U)
#define TMRB_PCONR_FORC_0                    ((uint16_t)0x0100U)
#define TMRB_PCONR_FORC_1                    ((uint16_t)0x0200U)
#define TMRB_PCONR_OUTEN_POS                 (12U)
#define TMRB_PCONR_OUTEN                     ((uint16_t)0x1000U)


/*******************************************************************************
                Bit definition for Peripheral USART
*******************************************************************************/
/*  Bit definition for USART_SR register  */
#define USART_SR_PE_POS                      (0U)
#define USART_SR_PE                          ((uint32_t)0x00000001U)
#define USART_SR_FE_POS                      (1U)
#define USART_SR_FE                          ((uint32_t)0x00000002U)
#define USART_SR_ORE_POS                     (3U)
#define USART_SR_ORE                         ((uint32_t)0x00000008U)
#define USART_SR_RXNE_POS                    (5U)
#define USART_SR_RXNE                        ((uint32_t)0x00000020U)
#define USART_SR_TC_POS                      (6U)
#define USART_SR_TC                          ((uint32_t)0x00000040U)
#define USART_SR_TXE_POS                     (7U)
#define USART_SR_TXE                         ((uint32_t)0x00000080U)
#define USART_SR_MPB_POS                     (16U)
#define USART_SR_MPB                         ((uint32_t)0x00010000U)

/*  Bit definition for USART_DR register  */
#define USART_DR_TDR_POS                     (0U)
#define USART_DR_TDR                         ((uint32_t)0x000001FFU)
#define USART_DR_TDR_0                       ((uint32_t)0x00000001U)
#define USART_DR_TDR_1                       ((uint32_t)0x00000002U)
#define USART_DR_TDR_2                       ((uint32_t)0x00000004U)
#define USART_DR_TDR_3                       ((uint32_t)0x00000008U)
#define USART_DR_TDR_4                       ((uint32_t)0x00000010U)
#define USART_DR_TDR_5                       ((uint32_t)0x00000020U)
#define USART_DR_TDR_6                       ((uint32_t)0x00000040U)
#define USART_DR_TDR_7                       ((uint32_t)0x00000080U)
#define USART_DR_TDR_8                       ((uint32_t)0x00000100U)
#define USART_DR_MPID_POS                    (9U)
#define USART_DR_MPID                        ((uint32_t)0x00000200U)
#define USART_DR_RDR_POS                     (16U)
#define USART_DR_RDR                         ((uint32_t)0x01FF0000U)
#define USART_DR_RDR_0                       ((uint32_t)0x00010000U)
#define USART_DR_RDR_1                       ((uint32_t)0x00020000U)
#define USART_DR_RDR_2                       ((uint32_t)0x00040000U)
#define USART_DR_RDR_3                       ((uint32_t)0x00080000U)
#define USART_DR_RDR_4                       ((uint32_t)0x00100000U)
#define USART_DR_RDR_5                       ((uint32_t)0x00200000U)
#define USART_DR_RDR_6                       ((uint32_t)0x00400000U)
#define USART_DR_RDR_7                       ((uint32_t)0x00800000U)
#define USART_DR_RDR_8                       ((uint32_t)0x01000000U)

/*  Bit definition for USART_BRR register  */
#define USART_BRR_DIV_INTEGER_POS            (8U)
#define USART_BRR_DIV_INTEGER                ((uint32_t)0x0000FF00U)
#define USART_BRR_DIV_INTEGER_0              ((uint32_t)0x00000100U)
#define USART_BRR_DIV_INTEGER_1              ((uint32_t)0x00000200U)
#define USART_BRR_DIV_INTEGER_2              ((uint32_t)0x00000400U)
#define USART_BRR_DIV_INTEGER_3              ((uint32_t)0x00000800U)
#define USART_BRR_DIV_INTEGER_4              ((uint32_t)0x00001000U)
#define USART_BRR_DIV_INTEGER_5              ((uint32_t)0x00002000U)
#define USART_BRR_DIV_INTEGER_6              ((uint32_t)0x00004000U)
#define USART_BRR_DIV_INTEGER_7              ((uint32_t)0x00008000U)

/*  Bit definition for USART_CR1 register  */
#define USART_CR1_RE_POS                     (2U)
#define USART_CR1_RE                         ((uint32_t)0x00000004U)
#define USART_CR1_TE_POS                     (3U)
#define USART_CR1_TE                         ((uint32_t)0x00000008U)
#define USART_CR1_SLME_POS                   (4U)
#define USART_CR1_SLME                       ((uint32_t)0x00000010U)
#define USART_CR1_RIE_POS                    (5U)
#define USART_CR1_RIE                        ((uint32_t)0x00000020U)
#define USART_CR1_TCIE_POS                   (6U)
#define USART_CR1_TCIE                       ((uint32_t)0x00000040U)
#define USART_CR1_TXEIE_POS                  (7U)
#define USART_CR1_TXEIE                      ((uint32_t)0x00000080U)
#define USART_CR1_PS_POS                     (9U)
#define USART_CR1_PS                         ((uint32_t)0x00000200U)
#define USART_CR1_PCE_POS                    (10U)
#define USART_CR1_PCE                        ((uint32_t)0x00000400U)
#define USART_CR1_M_POS                      (12U)
#define USART_CR1_M                          ((uint32_t)0x00001000U)
#define USART_CR1_OVER8_POS                  (15U)
#define USART_CR1_OVER8                      ((uint32_t)0x00008000U)
#define USART_CR1_CPE_POS                    (16U)
#define USART_CR1_CPE                        ((uint32_t)0x00010000U)
#define USART_CR1_CFE_POS                    (17U)
#define USART_CR1_CFE                        ((uint32_t)0x00020000U)
#define USART_CR1_CORE_POS                   (19U)
#define USART_CR1_CORE                       ((uint32_t)0x00080000U)
#define USART_CR1_MS_POS                     (24U)
#define USART_CR1_MS                         ((uint32_t)0x01000000U)
#define USART_CR1_ML_POS                     (28U)
#define USART_CR1_ML                         ((uint32_t)0x10000000U)
#define USART_CR1_NFE_POS                    (30U)
#define USART_CR1_NFE                        ((uint32_t)0x40000000U)
#define USART_CR1_SBS_POS                    (31U)
#define USART_CR1_SBS                        ((uint32_t)0x80000000U)

/*  Bit definition for USART_CR2 register  */
#define USART_CR2_MPE_POS                    (0U)
#define USART_CR2_MPE                        ((uint32_t)0x00000001U)
#define USART_CR2_CLKC_POS                   (11U)
#define USART_CR2_CLKC                       ((uint32_t)0x00001800U)
#define USART_CR2_CLKC_0                     ((uint32_t)0x00000800U)
#define USART_CR2_CLKC_1                     ((uint32_t)0x00001000U)
#define USART_CR2_STOP_POS                   (13U)
#define USART_CR2_STOP                       ((uint32_t)0x00002000U)
#define USART_CR2_LINEN_POS                  (14U)
#define USART_CR2_LINEN                      ((uint32_t)0x00004000U)

/*  Bit definition for USART_CR3 register  */
#define USART_CR3_HDSEL_POS                  (3U)
#define USART_CR3_HDSEL                      ((uint32_t)0x00000008U)
#define USART_CR3_CTSE_POS                   (9U)
#define USART_CR3_CTSE                       ((uint32_t)0x00000200U)

/*  Bit definition for USART_PR register  */
#define USART_PR_PSC_POS                     (0U)
#define USART_PR_PSC                         ((uint32_t)0x00000003U)
#define USART_PR_PSC_0                       ((uint32_t)0x00000001U)
#define USART_PR_PSC_1                       ((uint32_t)0x00000002U)




/******************************************************************************/
/*             Device Specific Registers bit_band structure                   */
/******************************************************************************/

typedef struct
{
    __IO uint32_t STRT;
    uint32_t RESERVED0[7];
} stc_adc_str_bit_t;

typedef struct
{
    __IO uint32_t MS0;
    __IO uint32_t MS1;
    uint32_t RESERVED0[2];
    __IO uint32_t ACCSEL0;
    __IO uint32_t ACCSEL1;
    __IO uint32_t CLREN;
    __IO uint32_t DFMT;
    uint32_t RESERVED1[8];
} stc_adc_cr0_bit_t;

typedef struct
{
    uint32_t RESERVED0[2];
    __IO uint32_t RSCHSEL;
    uint32_t RESERVED1[13];
} stc_adc_cr1_bit_t;

typedef struct
{
    __IO uint32_t TRGSELA0;
    __IO uint32_t TRGSELA1;
    uint32_t RESERVED0[5];
    __IO uint32_t TRGENA;
    __IO uint32_t TRGSELB0;
    __IO uint32_t TRGSELB1;
    uint32_t RESERVED1[5];
    __IO uint32_t TRGENB;
} stc_adc_trgsr_bit_t;

typedef struct
{
    __IO uint32_t CHSELA0;
    __IO uint32_t CHSELA1;
    __IO uint32_t CHSELA2;
    __IO uint32_t CHSELA3;
    __IO uint32_t CHSELA4;
    __IO uint32_t CHSELA5;
    __IO uint32_t CHSELA6;
    __IO uint32_t CHSELA7;
    __IO uint32_t CHSELA8;
    __IO uint32_t CHSELA9;
    __IO uint32_t CHSELA10;
    __IO uint32_t CHSELA11;
    uint32_t RESERVED0[4];
} stc_adc_chselra0_bit_t;

typedef struct
{
    __IO uint32_t CHSELB0;
    __IO uint32_t CHSELB1;
    __IO uint32_t CHSELB2;
    __IO uint32_t CHSELB3;
    __IO uint32_t CHSELB4;
    __IO uint32_t CHSELB5;
    __IO uint32_t CHSELB6;
    __IO uint32_t CHSELB7;
    __IO uint32_t CHSELB8;
    __IO uint32_t CHSELB9;
    __IO uint32_t CHSELB10;
    __IO uint32_t CHSELB11;
    uint32_t RESERVED0[4];
} stc_adc_chselrb0_bit_t;

typedef struct
{
    __IO uint32_t EXCHSEL;
    uint32_t RESERVED0[7];
} stc_adc_exchselr_bit_t;

typedef struct
{
    uint32_t SSTR_0;
    uint32_t SSTR_1;
    uint32_t SSTR_2;
    uint32_t SSTR_3;
    uint32_t SSTR_4;
    uint32_t SSTR_5;
    uint32_t SSTR_6;
    uint32_t SSTR_7;
} stc_adc_sstr_bit_t;

typedef struct
{
    __IO uint32_t EOCAF;
    __IO uint32_t EOCBF;
    uint32_t RESERVED0[6];
} stc_adc_isr_bit_t;

typedef struct
{
    __IO uint32_t EOCAIEN;
    __IO uint32_t EOCBIEN;
    uint32_t RESERVED0[6];
} stc_adc_icr_bit_t;

typedef struct
{
    __IO uint32_t CLREOCAF;
    __IO uint32_t CLREOCBF;
    uint32_t RESERVED0[6];
} stc_adc_isclrr_bit_t;

typedef struct
{
    uint32_t DR0_0;
    uint32_t DR0_1;
    uint32_t DR0_2;
    uint32_t DR0_3;
    uint32_t DR0_4;
    uint32_t DR0_5;
    uint32_t DR0_6;
    uint32_t DR0_7;
    uint32_t DR0_8;
    uint32_t DR0_9;
    uint32_t DR0_10;
    uint32_t DR0_11;
    uint32_t DR0_12;
    uint32_t DR0_13;
    uint32_t DR0_14;
    uint32_t DR0_15;
} stc_adc_dr0_bit_t;

typedef struct
{
    uint32_t DR1_0;
    uint32_t DR1_1;
    uint32_t DR1_2;
    uint32_t DR1_3;
    uint32_t DR1_4;
    uint32_t DR1_5;
    uint32_t DR1_6;
    uint32_t DR1_7;
    uint32_t DR1_8;
    uint32_t DR1_9;
    uint32_t DR1_10;
    uint32_t DR1_11;
    uint32_t DR1_12;
    uint32_t DR1_13;
    uint32_t DR1_14;
    uint32_t DR1_15;
} stc_adc_dr1_bit_t;

typedef struct
{
    uint32_t DR2_0;
    uint32_t DR2_1;
    uint32_t DR2_2;
    uint32_t DR2_3;
    uint32_t DR2_4;
    uint32_t DR2_5;
    uint32_t DR2_6;
    uint32_t DR2_7;
    uint32_t DR2_8;
    uint32_t DR2_9;
    uint32_t DR2_10;
    uint32_t DR2_11;
    uint32_t DR2_12;
    uint32_t DR2_13;
    uint32_t DR2_14;
    uint32_t DR2_15;
} stc_adc_dr2_bit_t;

typedef struct
{
    uint32_t DR3_0;
    uint32_t DR3_1;
    uint32_t DR3_2;
    uint32_t DR3_3;
    uint32_t DR3_4;
    uint32_t DR3_5;
    uint32_t DR3_6;
    uint32_t DR3_7;
    uint32_t DR3_8;
    uint32_t DR3_9;
    uint32_t DR3_10;
    uint32_t DR3_11;
    uint32_t DR3_12;
    uint32_t DR3_13;
    uint32_t DR3_14;
    uint32_t DR3_15;
} stc_adc_dr3_bit_t;

typedef struct
{
    uint32_t DR4_0;
    uint32_t DR4_1;
    uint32_t DR4_2;
    uint32_t DR4_3;
    uint32_t DR4_4;
    uint32_t DR4_5;
    uint32_t DR4_6;
    uint32_t DR4_7;
    uint32_t DR4_8;
    uint32_t DR4_9;
    uint32_t DR4_10;
    uint32_t DR4_11;
    uint32_t DR4_12;
    uint32_t DR4_13;
    uint32_t DR4_14;
    uint32_t DR4_15;
} stc_adc_dr4_bit_t;

typedef struct
{
    uint32_t DR5_0;
    uint32_t DR5_1;
    uint32_t DR5_2;
    uint32_t DR5_3;
    uint32_t DR5_4;
    uint32_t DR5_5;
    uint32_t DR5_6;
    uint32_t DR5_7;
    uint32_t DR5_8;
    uint32_t DR5_9;
    uint32_t DR5_10;
    uint32_t DR5_11;
    uint32_t DR5_12;
    uint32_t DR5_13;
    uint32_t DR5_14;
    uint32_t DR5_15;
} stc_adc_dr5_bit_t;

typedef struct
{
    uint32_t DR6_0;
    uint32_t DR6_1;
    uint32_t DR6_2;
    uint32_t DR6_3;
    uint32_t DR6_4;
    uint32_t DR6_5;
    uint32_t DR6_6;
    uint32_t DR6_7;
    uint32_t DR6_8;
    uint32_t DR6_9;
    uint32_t DR6_10;
    uint32_t DR6_11;
    uint32_t DR6_12;
    uint32_t DR6_13;
    uint32_t DR6_14;
    uint32_t DR6_15;
} stc_adc_dr6_bit_t;

typedef struct
{
    uint32_t DR7_0;
    uint32_t DR7_1;
    uint32_t DR7_2;
    uint32_t DR7_3;
    uint32_t DR7_4;
    uint32_t DR7_5;
    uint32_t DR7_6;
    uint32_t DR7_7;
    uint32_t DR7_8;
    uint32_t DR7_9;
    uint32_t DR7_10;
    uint32_t DR7_11;
    uint32_t DR7_12;
    uint32_t DR7_13;
    uint32_t DR7_14;
    uint32_t DR7_15;
} stc_adc_dr7_bit_t;

typedef struct
{
    uint32_t DR8_0;
    uint32_t DR8_1;
    uint32_t DR8_2;
    uint32_t DR8_3;
    uint32_t DR8_4;
    uint32_t DR8_5;
    uint32_t DR8_6;
    uint32_t DR8_7;
    uint32_t DR8_8;
    uint32_t DR8_9;
    uint32_t DR8_10;
    uint32_t DR8_11;
    uint32_t DR8_12;
    uint32_t DR8_13;
    uint32_t DR8_14;
    uint32_t DR8_15;
} stc_adc_dr8_bit_t;

typedef struct
{
    uint32_t DR9_0;
    uint32_t DR9_1;
    uint32_t DR9_2;
    uint32_t DR9_3;
    uint32_t DR9_4;
    uint32_t DR9_5;
    uint32_t DR9_6;
    uint32_t DR9_7;
    uint32_t DR9_8;
    uint32_t DR9_9;
    uint32_t DR9_10;
    uint32_t DR9_11;
    uint32_t DR9_12;
    uint32_t DR9_13;
    uint32_t DR9_14;
    uint32_t DR9_15;
} stc_adc_dr9_bit_t;

typedef struct
{
    uint32_t DR10_0;
    uint32_t DR10_1;
    uint32_t DR10_2;
    uint32_t DR10_3;
    uint32_t DR10_4;
    uint32_t DR10_5;
    uint32_t DR10_6;
    uint32_t DR10_7;
    uint32_t DR10_8;
    uint32_t DR10_9;
    uint32_t DR10_10;
    uint32_t DR10_11;
    uint32_t DR10_12;
    uint32_t DR10_13;
    uint32_t DR10_14;
    uint32_t DR10_15;
} stc_adc_dr10_bit_t;

typedef struct
{
    uint32_t DR11_0;
    uint32_t DR11_1;
    uint32_t DR11_2;
    uint32_t DR11_3;
    uint32_t DR11_4;
    uint32_t DR11_5;
    uint32_t DR11_6;
    uint32_t DR11_7;
    uint32_t DR11_8;
    uint32_t DR11_9;
    uint32_t DR11_10;
    uint32_t DR11_11;
    uint32_t DR11_12;
    uint32_t DR11_13;
    uint32_t DR11_14;
    uint32_t DR11_15;
} stc_adc_dr11_bit_t;

typedef struct
{
    __IO uint32_t AWD0EN;
    __IO uint32_t AWD0IEN;
    __IO uint32_t AWD0MD;
    uint32_t RESERVED0[1];
    __IO uint32_t AWD1EN;
    __IO uint32_t AWD1IEN;
    __IO uint32_t AWD1MD;
    uint32_t RESERVED1[1];
    __IO uint32_t AWDCM0;
    __IO uint32_t AWDCM1;
    uint32_t RESERVED2[6];
} stc_adc_awdcr_bit_t;

typedef struct
{
    __IO uint32_t AWD0F;
    __IO uint32_t AWD1F;
    uint32_t RESERVED0[2];
    __IO uint32_t AWDCMF;
    uint32_t RESERVED1[3];
} stc_adc_awdsr_bit_t;

typedef struct
{
    __IO uint32_t CLRAWD0F;
    __IO uint32_t CLRAWD1F;
    uint32_t RESERVED0[2];
    __IO uint32_t CLRAWDCMF;
    uint32_t RESERVED1[3];
} stc_adc_awdsclrr_bit_t;

typedef struct
{
    uint32_t AWD0DR0_0;
    uint32_t AWD0DR0_1;
    uint32_t AWD0DR0_2;
    uint32_t AWD0DR0_3;
    uint32_t AWD0DR0_4;
    uint32_t AWD0DR0_5;
    uint32_t AWD0DR0_6;
    uint32_t AWD0DR0_7;
    uint32_t AWD0DR0_8;
    uint32_t AWD0DR0_9;
    uint32_t AWD0DR0_10;
    uint32_t AWD0DR0_11;
    uint32_t AWD0DR0_12;
    uint32_t AWD0DR0_13;
    uint32_t AWD0DR0_14;
    uint32_t AWD0DR0_15;
} stc_adc_awd0dr0_bit_t;

typedef struct
{
    uint32_t AWD0DR1_0;
    uint32_t AWD0DR1_1;
    uint32_t AWD0DR1_2;
    uint32_t AWD0DR1_3;
    uint32_t AWD0DR1_4;
    uint32_t AWD0DR1_5;
    uint32_t AWD0DR1_6;
    uint32_t AWD0DR1_7;
    uint32_t AWD0DR1_8;
    uint32_t AWD0DR1_9;
    uint32_t AWD0DR1_10;
    uint32_t AWD0DR1_11;
    uint32_t AWD0DR1_12;
    uint32_t AWD0DR1_13;
    uint32_t AWD0DR1_14;
    uint32_t AWD0DR1_15;
} stc_adc_awd0dr1_bit_t;

typedef struct
{
    __IO uint32_t AWDCH0;
    __IO uint32_t AWDCH1;
    __IO uint32_t AWDCH2;
    __IO uint32_t AWDCH3;
    __IO uint32_t AWDCH4;
    uint32_t RESERVED0[3];
} stc_adc_awd0chsr_bit_t;

typedef struct
{
    uint32_t AWD1DR0_0;
    uint32_t AWD1DR0_1;
    uint32_t AWD1DR0_2;
    uint32_t AWD1DR0_3;
    uint32_t AWD1DR0_4;
    uint32_t AWD1DR0_5;
    uint32_t AWD1DR0_6;
    uint32_t AWD1DR0_7;
    uint32_t AWD1DR0_8;
    uint32_t AWD1DR0_9;
    uint32_t AWD1DR0_10;
    uint32_t AWD1DR0_11;
    uint32_t AWD1DR0_12;
    uint32_t AWD1DR0_13;
    uint32_t AWD1DR0_14;
    uint32_t AWD1DR0_15;
} stc_adc_awd1dr0_bit_t;

typedef struct
{
    uint32_t AWD1DR1_0;
    uint32_t AWD1DR1_1;
    uint32_t AWD1DR1_2;
    uint32_t AWD1DR1_3;
    uint32_t AWD1DR1_4;
    uint32_t AWD1DR1_5;
    uint32_t AWD1DR1_6;
    uint32_t AWD1DR1_7;
    uint32_t AWD1DR1_8;
    uint32_t AWD1DR1_9;
    uint32_t AWD1DR1_10;
    uint32_t AWD1DR1_11;
    uint32_t AWD1DR1_12;
    uint32_t AWD1DR1_13;
    uint32_t AWD1DR1_14;
    uint32_t AWD1DR1_15;
} stc_adc_awd1dr1_bit_t;

typedef struct
{
    __IO uint32_t AWDCH0;
    __IO uint32_t AWDCH1;
    __IO uint32_t AWDCH2;
    __IO uint32_t AWDCH3;
    __IO uint32_t AWDCH4;
    uint32_t RESERVED0[3];
} stc_adc_awd1chsr_bit_t;

typedef struct
{
    __IO uint32_t STRG;
    uint32_t RESERVED0[31];
} stc_aos_intc_strgcr_bit_t;

typedef struct
{
    __IO uint32_t TRGSEL0;
    __IO uint32_t TRGSEL1;
    __IO uint32_t TRGSEL2;
    __IO uint32_t TRGSEL3;
    __IO uint32_t TRGSEL4;
    __IO uint32_t TRGSEL5;
    __IO uint32_t TRGSEL6;
    uint32_t RESERVED0[25];
} stc_aos_tmr0_htssr_bit_t;

typedef struct
{
    __IO uint32_t TRGSEL0;
    __IO uint32_t TRGSEL1;
    __IO uint32_t TRGSEL2;
    __IO uint32_t TRGSEL3;
    __IO uint32_t TRGSEL4;
    __IO uint32_t TRGSEL5;
    __IO uint32_t TRGSEL6;
    uint32_t RESERVED0[25];
} stc_aos_tmrb_htssr_bit_t;

typedef struct
{
    __IO uint32_t TRGSEL0;
    __IO uint32_t TRGSEL1;
    __IO uint32_t TRGSEL2;
    __IO uint32_t TRGSEL3;
    __IO uint32_t TRGSEL4;
    __IO uint32_t TRGSEL5;
    __IO uint32_t TRGSEL6;
    uint32_t RESERVED0[25];
} stc_aos_adc_itrgselr0_bit_t;

typedef struct
{
    __IO uint32_t TRGSEL0;
    __IO uint32_t TRGSEL1;
    __IO uint32_t TRGSEL2;
    __IO uint32_t TRGSEL3;
    __IO uint32_t TRGSEL4;
    __IO uint32_t TRGSEL5;
    __IO uint32_t TRGSEL6;
    uint32_t RESERVED0[25];
} stc_aos_adc_itrgselr1_bit_t;

typedef struct
{
    __IO uint32_t PERICKSEL0;
    __IO uint32_t PERICKSEL1;
    __IO uint32_t PERICKSEL2;
    uint32_t RESERVED0[5];
} stc_cmu_pericksel_bit_t;

typedef struct
{
    __IO uint32_t XTALSTDF;
    uint32_t RESERVED0[7];
} stc_cmu_xtalstdsr_bit_t;

typedef struct
{
    __IO uint32_t SCKDIV0;
    __IO uint32_t SCKDIV1;
    __IO uint32_t SCKDIV2;
    uint32_t RESERVED0[5];
} stc_cmu_sckdivr_bit_t;

typedef struct
{
    __IO uint32_t CKSW0;
    __IO uint32_t CKSW1;
    uint32_t RESERVED0[6];
} stc_cmu_ckswr_bit_t;

typedef struct
{
    __IO uint32_t XTALSTP;
    uint32_t RESERVED0[7];
} stc_cmu_xtalcr_bit_t;

typedef struct
{
    uint32_t RESERVED0[4];
    __IO uint32_t XTALDRV0;
    __IO uint32_t XTALDRV1;
    __IO uint32_t XTALMS;
    __IO uint32_t SUPDRV;
} stc_cmu_xtalcfgr_bit_t;

typedef struct
{
    __IO uint32_t XTALSTB0;
    __IO uint32_t XTALSTB1;
    __IO uint32_t XTALSTB2;
    uint32_t RESERVED0[5];
} stc_cmu_xtalstbcr_bit_t;

typedef struct
{
    __IO uint32_t HRCSTP;
    uint32_t RESERVED0[7];
} stc_cmu_hrccr_bit_t;

typedef struct
{
    __IO uint32_t HRCSTBF;
    uint32_t RESERVED0[2];
    __IO uint32_t XTALSTBF;
    __IO uint32_t XTAL32STBF;
    uint32_t RESERVED1[3];
} stc_cmu_oscstbsr_bit_t;

typedef struct
{
    __IO uint32_t MCO1SEL0;
    __IO uint32_t MCO1SEL1;
    __IO uint32_t MCO1SEL2;
    __IO uint32_t MCO1SEL3;
    __IO uint32_t MCO1DIV0;
    __IO uint32_t MCO1DIV1;
    __IO uint32_t MCO1DIV2;
    __IO uint32_t MCO1EN;
} stc_cmu_mco1cfgr_bit_t;

typedef struct
{
    __IO uint32_t XTALSTDIE;
    __IO uint32_t XTALSTDRE;
    __IO uint32_t XTALSTDRIS;
    uint32_t RESERVED0[4];
    __IO uint32_t XTALSTDE;
} stc_cmu_xtalstdcr_bit_t;

typedef struct
{
    __IO uint32_t ADC;
    __IO uint32_t CTC;
    uint32_t RESERVED0[2];
    __IO uint32_t AOS;
    uint32_t RESERVED1[2];
    __IO uint32_t CRC;
    __IO uint32_t TIMB1;
    __IO uint32_t TIMB2;
    __IO uint32_t TIMB3;
    __IO uint32_t TIMB4;
    __IO uint32_t TIMB5;
    __IO uint32_t TIMB6;
    __IO uint32_t TIMB7;
    __IO uint32_t TIMB8;
    __IO uint32_t TIM0;
    uint32_t RESERVED2[6];
    __IO uint32_t RTC;
    __IO uint32_t UART1;
    __IO uint32_t UART2;
    __IO uint32_t UART3;
    __IO uint32_t UART4;
    __IO uint32_t IIC;
    __IO uint32_t SPI;
    uint32_t RESERVED3[2];
} stc_cmu_fcg_bit_t;

typedef struct
{
    __IO uint32_t XTAL32STP;
    uint32_t RESERVED0[7];
} stc_cmu_xtal32cr_bit_t;

typedef struct
{
    __IO uint32_t XTAL32DRV0;
    __IO uint32_t XTAL32DRV1;
    __IO uint32_t XTAL32SUPDRV;
    uint32_t RESERVED0[5];
} stc_cmu_xtal32cfgr_bit_t;

typedef struct
{
    __IO uint32_t XTAL32NF0;
    __IO uint32_t XTAL32NF1;
    uint32_t RESERVED0[6];
} stc_cmu_xtal32nfr_bit_t;

typedef struct
{
    __IO uint32_t LRCSTP;
    uint32_t RESERVED0[7];
} stc_cmu_lrccr_bit_t;

typedef struct
{
    __IO uint32_t CR;
    __IO uint32_t FLAG;
    uint32_t RESERVED0[30];
} stc_crc_cr_bit_t;

typedef struct
{
    uint32_t RESLT_0;
    uint32_t RESLT_1;
    uint32_t RESLT_2;
    uint32_t RESLT_3;
    uint32_t RESLT_4;
    uint32_t RESLT_5;
    uint32_t RESLT_6;
    uint32_t RESLT_7;
    uint32_t RESLT_8;
    uint32_t RESLT_9;
    uint32_t RESLT_10;
    uint32_t RESLT_11;
    uint32_t RESLT_12;
    uint32_t RESLT_13;
    uint32_t RESLT_14;
    uint32_t RESLT_15;
    uint32_t RESLT_16;
    uint32_t RESLT_17;
    uint32_t RESLT_18;
    uint32_t RESLT_19;
    uint32_t RESLT_20;
    uint32_t RESLT_21;
    uint32_t RESLT_22;
    uint32_t RESLT_23;
    uint32_t RESLT_24;
    uint32_t RESLT_25;
    uint32_t RESLT_26;
    uint32_t RESLT_27;
    uint32_t RESLT_28;
    uint32_t RESLT_29;
    uint32_t RESLT_30;
    uint32_t RESLT_31;
} stc_crc_reslt_bit_t;

typedef struct
{
    uint32_t DAT0_0;
    uint32_t DAT0_1;
    uint32_t DAT0_2;
    uint32_t DAT0_3;
    uint32_t DAT0_4;
    uint32_t DAT0_5;
    uint32_t DAT0_6;
    uint32_t DAT0_7;
    uint32_t DAT0_8;
    uint32_t DAT0_9;
    uint32_t DAT0_10;
    uint32_t DAT0_11;
    uint32_t DAT0_12;
    uint32_t DAT0_13;
    uint32_t DAT0_14;
    uint32_t DAT0_15;
    uint32_t DAT0_16;
    uint32_t DAT0_17;
    uint32_t DAT0_18;
    uint32_t DAT0_19;
    uint32_t DAT0_20;
    uint32_t DAT0_21;
    uint32_t DAT0_22;
    uint32_t DAT0_23;
    uint32_t DAT0_24;
    uint32_t DAT0_25;
    uint32_t DAT0_26;
    uint32_t DAT0_27;
    uint32_t DAT0_28;
    uint32_t DAT0_29;
    uint32_t DAT0_30;
    uint32_t DAT0_31;
} stc_crc_dat0_bit_t;

typedef struct
{
    uint32_t DAT1_0;
    uint32_t DAT1_1;
    uint32_t DAT1_2;
    uint32_t DAT1_3;
    uint32_t DAT1_4;
    uint32_t DAT1_5;
    uint32_t DAT1_6;
    uint32_t DAT1_7;
    uint32_t DAT1_8;
    uint32_t DAT1_9;
    uint32_t DAT1_10;
    uint32_t DAT1_11;
    uint32_t DAT1_12;
    uint32_t DAT1_13;
    uint32_t DAT1_14;
    uint32_t DAT1_15;
    uint32_t DAT1_16;
    uint32_t DAT1_17;
    uint32_t DAT1_18;
    uint32_t DAT1_19;
    uint32_t DAT1_20;
    uint32_t DAT1_21;
    uint32_t DAT1_22;
    uint32_t DAT1_23;
    uint32_t DAT1_24;
    uint32_t DAT1_25;
    uint32_t DAT1_26;
    uint32_t DAT1_27;
    uint32_t DAT1_28;
    uint32_t DAT1_29;
    uint32_t DAT1_30;
    uint32_t DAT1_31;
} stc_crc_dat1_bit_t;

typedef struct
{
    uint32_t DAT2_0;
    uint32_t DAT2_1;
    uint32_t DAT2_2;
    uint32_t DAT2_3;
    uint32_t DAT2_4;
    uint32_t DAT2_5;
    uint32_t DAT2_6;
    uint32_t DAT2_7;
    uint32_t DAT2_8;
    uint32_t DAT2_9;
    uint32_t DAT2_10;
    uint32_t DAT2_11;
    uint32_t DAT2_12;
    uint32_t DAT2_13;
    uint32_t DAT2_14;
    uint32_t DAT2_15;
    uint32_t DAT2_16;
    uint32_t DAT2_17;
    uint32_t DAT2_18;
    uint32_t DAT2_19;
    uint32_t DAT2_20;
    uint32_t DAT2_21;
    uint32_t DAT2_22;
    uint32_t DAT2_23;
    uint32_t DAT2_24;
    uint32_t DAT2_25;
    uint32_t DAT2_26;
    uint32_t DAT2_27;
    uint32_t DAT2_28;
    uint32_t DAT2_29;
    uint32_t DAT2_30;
    uint32_t DAT2_31;
} stc_crc_dat2_bit_t;

typedef struct
{
    uint32_t DAT3_0;
    uint32_t DAT3_1;
    uint32_t DAT3_2;
    uint32_t DAT3_3;
    uint32_t DAT3_4;
    uint32_t DAT3_5;
    uint32_t DAT3_6;
    uint32_t DAT3_7;
    uint32_t DAT3_8;
    uint32_t DAT3_9;
    uint32_t DAT3_10;
    uint32_t DAT3_11;
    uint32_t DAT3_12;
    uint32_t DAT3_13;
    uint32_t DAT3_14;
    uint32_t DAT3_15;
    uint32_t DAT3_16;
    uint32_t DAT3_17;
    uint32_t DAT3_18;
    uint32_t DAT3_19;
    uint32_t DAT3_20;
    uint32_t DAT3_21;
    uint32_t DAT3_22;
    uint32_t DAT3_23;
    uint32_t DAT3_24;
    uint32_t DAT3_25;
    uint32_t DAT3_26;
    uint32_t DAT3_27;
    uint32_t DAT3_28;
    uint32_t DAT3_29;
    uint32_t DAT3_30;
    uint32_t DAT3_31;
} stc_crc_dat3_bit_t;

typedef struct
{
    uint32_t DAT4_0;
    uint32_t DAT4_1;
    uint32_t DAT4_2;
    uint32_t DAT4_3;
    uint32_t DAT4_4;
    uint32_t DAT4_5;
    uint32_t DAT4_6;
    uint32_t DAT4_7;
    uint32_t DAT4_8;
    uint32_t DAT4_9;
    uint32_t DAT4_10;
    uint32_t DAT4_11;
    uint32_t DAT4_12;
    uint32_t DAT4_13;
    uint32_t DAT4_14;
    uint32_t DAT4_15;
    uint32_t DAT4_16;
    uint32_t DAT4_17;
    uint32_t DAT4_18;
    uint32_t DAT4_19;
    uint32_t DAT4_20;
    uint32_t DAT4_21;
    uint32_t DAT4_22;
    uint32_t DAT4_23;
    uint32_t DAT4_24;
    uint32_t DAT4_25;
    uint32_t DAT4_26;
    uint32_t DAT4_27;
    uint32_t DAT4_28;
    uint32_t DAT4_29;
    uint32_t DAT4_30;
    uint32_t DAT4_31;
} stc_crc_dat4_bit_t;

typedef struct
{
    uint32_t DAT5_0;
    uint32_t DAT5_1;
    uint32_t DAT5_2;
    uint32_t DAT5_3;
    uint32_t DAT5_4;
    uint32_t DAT5_5;
    uint32_t DAT5_6;
    uint32_t DAT5_7;
    uint32_t DAT5_8;
    uint32_t DAT5_9;
    uint32_t DAT5_10;
    uint32_t DAT5_11;
    uint32_t DAT5_12;
    uint32_t DAT5_13;
    uint32_t DAT5_14;
    uint32_t DAT5_15;
    uint32_t DAT5_16;
    uint32_t DAT5_17;
    uint32_t DAT5_18;
    uint32_t DAT5_19;
    uint32_t DAT5_20;
    uint32_t DAT5_21;
    uint32_t DAT5_22;
    uint32_t DAT5_23;
    uint32_t DAT5_24;
    uint32_t DAT5_25;
    uint32_t DAT5_26;
    uint32_t DAT5_27;
    uint32_t DAT5_28;
    uint32_t DAT5_29;
    uint32_t DAT5_30;
    uint32_t DAT5_31;
} stc_crc_dat5_bit_t;

typedef struct
{
    uint32_t DAT6_0;
    uint32_t DAT6_1;
    uint32_t DAT6_2;
    uint32_t DAT6_3;
    uint32_t DAT6_4;
    uint32_t DAT6_5;
    uint32_t DAT6_6;
    uint32_t DAT6_7;
    uint32_t DAT6_8;
    uint32_t DAT6_9;
    uint32_t DAT6_10;
    uint32_t DAT6_11;
    uint32_t DAT6_12;
    uint32_t DAT6_13;
    uint32_t DAT6_14;
    uint32_t DAT6_15;
    uint32_t DAT6_16;
    uint32_t DAT6_17;
    uint32_t DAT6_18;
    uint32_t DAT6_19;
    uint32_t DAT6_20;
    uint32_t DAT6_21;
    uint32_t DAT6_22;
    uint32_t DAT6_23;
    uint32_t DAT6_24;
    uint32_t DAT6_25;
    uint32_t DAT6_26;
    uint32_t DAT6_27;
    uint32_t DAT6_28;
    uint32_t DAT6_29;
    uint32_t DAT6_30;
    uint32_t DAT6_31;
} stc_crc_dat6_bit_t;

typedef struct
{
    uint32_t DAT7_0;
    uint32_t DAT7_1;
    uint32_t DAT7_2;
    uint32_t DAT7_3;
    uint32_t DAT7_4;
    uint32_t DAT7_5;
    uint32_t DAT7_6;
    uint32_t DAT7_7;
    uint32_t DAT7_8;
    uint32_t DAT7_9;
    uint32_t DAT7_10;
    uint32_t DAT7_11;
    uint32_t DAT7_12;
    uint32_t DAT7_13;
    uint32_t DAT7_14;
    uint32_t DAT7_15;
    uint32_t DAT7_16;
    uint32_t DAT7_17;
    uint32_t DAT7_18;
    uint32_t DAT7_19;
    uint32_t DAT7_20;
    uint32_t DAT7_21;
    uint32_t DAT7_22;
    uint32_t DAT7_23;
    uint32_t DAT7_24;
    uint32_t DAT7_25;
    uint32_t DAT7_26;
    uint32_t DAT7_27;
    uint32_t DAT7_28;
    uint32_t DAT7_29;
    uint32_t DAT7_30;
    uint32_t DAT7_31;
} stc_crc_dat7_bit_t;

typedef struct
{
    uint32_t DAT8_0;
    uint32_t DAT8_1;
    uint32_t DAT8_2;
    uint32_t DAT8_3;
    uint32_t DAT8_4;
    uint32_t DAT8_5;
    uint32_t DAT8_6;
    uint32_t DAT8_7;
    uint32_t DAT8_8;
    uint32_t DAT8_9;
    uint32_t DAT8_10;
    uint32_t DAT8_11;
    uint32_t DAT8_12;
    uint32_t DAT8_13;
    uint32_t DAT8_14;
    uint32_t DAT8_15;
    uint32_t DAT8_16;
    uint32_t DAT8_17;
    uint32_t DAT8_18;
    uint32_t DAT8_19;
    uint32_t DAT8_20;
    uint32_t DAT8_21;
    uint32_t DAT8_22;
    uint32_t DAT8_23;
    uint32_t DAT8_24;
    uint32_t DAT8_25;
    uint32_t DAT8_26;
    uint32_t DAT8_27;
    uint32_t DAT8_28;
    uint32_t DAT8_29;
    uint32_t DAT8_30;
    uint32_t DAT8_31;
} stc_crc_dat8_bit_t;

typedef struct
{
    uint32_t DAT9_0;
    uint32_t DAT9_1;
    uint32_t DAT9_2;
    uint32_t DAT9_3;
    uint32_t DAT9_4;
    uint32_t DAT9_5;
    uint32_t DAT9_6;
    uint32_t DAT9_7;
    uint32_t DAT9_8;
    uint32_t DAT9_9;
    uint32_t DAT9_10;
    uint32_t DAT9_11;
    uint32_t DAT9_12;
    uint32_t DAT9_13;
    uint32_t DAT9_14;
    uint32_t DAT9_15;
    uint32_t DAT9_16;
    uint32_t DAT9_17;
    uint32_t DAT9_18;
    uint32_t DAT9_19;
    uint32_t DAT9_20;
    uint32_t DAT9_21;
    uint32_t DAT9_22;
    uint32_t DAT9_23;
    uint32_t DAT9_24;
    uint32_t DAT9_25;
    uint32_t DAT9_26;
    uint32_t DAT9_27;
    uint32_t DAT9_28;
    uint32_t DAT9_29;
    uint32_t DAT9_30;
    uint32_t DAT9_31;
} stc_crc_dat9_bit_t;

typedef struct
{
    uint32_t DAT10_0;
    uint32_t DAT10_1;
    uint32_t DAT10_2;
    uint32_t DAT10_3;
    uint32_t DAT10_4;
    uint32_t DAT10_5;
    uint32_t DAT10_6;
    uint32_t DAT10_7;
    uint32_t DAT10_8;
    uint32_t DAT10_9;
    uint32_t DAT10_10;
    uint32_t DAT10_11;
    uint32_t DAT10_12;
    uint32_t DAT10_13;
    uint32_t DAT10_14;
    uint32_t DAT10_15;
    uint32_t DAT10_16;
    uint32_t DAT10_17;
    uint32_t DAT10_18;
    uint32_t DAT10_19;
    uint32_t DAT10_20;
    uint32_t DAT10_21;
    uint32_t DAT10_22;
    uint32_t DAT10_23;
    uint32_t DAT10_24;
    uint32_t DAT10_25;
    uint32_t DAT10_26;
    uint32_t DAT10_27;
    uint32_t DAT10_28;
    uint32_t DAT10_29;
    uint32_t DAT10_30;
    uint32_t DAT10_31;
} stc_crc_dat10_bit_t;

typedef struct
{
    uint32_t DAT11_0;
    uint32_t DAT11_1;
    uint32_t DAT11_2;
    uint32_t DAT11_3;
    uint32_t DAT11_4;
    uint32_t DAT11_5;
    uint32_t DAT11_6;
    uint32_t DAT11_7;
    uint32_t DAT11_8;
    uint32_t DAT11_9;
    uint32_t DAT11_10;
    uint32_t DAT11_11;
    uint32_t DAT11_12;
    uint32_t DAT11_13;
    uint32_t DAT11_14;
    uint32_t DAT11_15;
    uint32_t DAT11_16;
    uint32_t DAT11_17;
    uint32_t DAT11_18;
    uint32_t DAT11_19;
    uint32_t DAT11_20;
    uint32_t DAT11_21;
    uint32_t DAT11_22;
    uint32_t DAT11_23;
    uint32_t DAT11_24;
    uint32_t DAT11_25;
    uint32_t DAT11_26;
    uint32_t DAT11_27;
    uint32_t DAT11_28;
    uint32_t DAT11_29;
    uint32_t DAT11_30;
    uint32_t DAT11_31;
} stc_crc_dat11_bit_t;

typedef struct
{
    uint32_t DAT12_0;
    uint32_t DAT12_1;
    uint32_t DAT12_2;
    uint32_t DAT12_3;
    uint32_t DAT12_4;
    uint32_t DAT12_5;
    uint32_t DAT12_6;
    uint32_t DAT12_7;
    uint32_t DAT12_8;
    uint32_t DAT12_9;
    uint32_t DAT12_10;
    uint32_t DAT12_11;
    uint32_t DAT12_12;
    uint32_t DAT12_13;
    uint32_t DAT12_14;
    uint32_t DAT12_15;
    uint32_t DAT12_16;
    uint32_t DAT12_17;
    uint32_t DAT12_18;
    uint32_t DAT12_19;
    uint32_t DAT12_20;
    uint32_t DAT12_21;
    uint32_t DAT12_22;
    uint32_t DAT12_23;
    uint32_t DAT12_24;
    uint32_t DAT12_25;
    uint32_t DAT12_26;
    uint32_t DAT12_27;
    uint32_t DAT12_28;
    uint32_t DAT12_29;
    uint32_t DAT12_30;
    uint32_t DAT12_31;
} stc_crc_dat12_bit_t;

typedef struct
{
    uint32_t DAT13_0;
    uint32_t DAT13_1;
    uint32_t DAT13_2;
    uint32_t DAT13_3;
    uint32_t DAT13_4;
    uint32_t DAT13_5;
    uint32_t DAT13_6;
    uint32_t DAT13_7;
    uint32_t DAT13_8;
    uint32_t DAT13_9;
    uint32_t DAT13_10;
    uint32_t DAT13_11;
    uint32_t DAT13_12;
    uint32_t DAT13_13;
    uint32_t DAT13_14;
    uint32_t DAT13_15;
    uint32_t DAT13_16;
    uint32_t DAT13_17;
    uint32_t DAT13_18;
    uint32_t DAT13_19;
    uint32_t DAT13_20;
    uint32_t DAT13_21;
    uint32_t DAT13_22;
    uint32_t DAT13_23;
    uint32_t DAT13_24;
    uint32_t DAT13_25;
    uint32_t DAT13_26;
    uint32_t DAT13_27;
    uint32_t DAT13_28;
    uint32_t DAT13_29;
    uint32_t DAT13_30;
    uint32_t DAT13_31;
} stc_crc_dat13_bit_t;

typedef struct
{
    uint32_t DAT14_0;
    uint32_t DAT14_1;
    uint32_t DAT14_2;
    uint32_t DAT14_3;
    uint32_t DAT14_4;
    uint32_t DAT14_5;
    uint32_t DAT14_6;
    uint32_t DAT14_7;
    uint32_t DAT14_8;
    uint32_t DAT14_9;
    uint32_t DAT14_10;
    uint32_t DAT14_11;
    uint32_t DAT14_12;
    uint32_t DAT14_13;
    uint32_t DAT14_14;
    uint32_t DAT14_15;
    uint32_t DAT14_16;
    uint32_t DAT14_17;
    uint32_t DAT14_18;
    uint32_t DAT14_19;
    uint32_t DAT14_20;
    uint32_t DAT14_21;
    uint32_t DAT14_22;
    uint32_t DAT14_23;
    uint32_t DAT14_24;
    uint32_t DAT14_25;
    uint32_t DAT14_26;
    uint32_t DAT14_27;
    uint32_t DAT14_28;
    uint32_t DAT14_29;
    uint32_t DAT14_30;
    uint32_t DAT14_31;
} stc_crc_dat14_bit_t;

typedef struct
{
    uint32_t DAT15_0;
    uint32_t DAT15_1;
    uint32_t DAT15_2;
    uint32_t DAT15_3;
    uint32_t DAT15_4;
    uint32_t DAT15_5;
    uint32_t DAT15_6;
    uint32_t DAT15_7;
    uint32_t DAT15_8;
    uint32_t DAT15_9;
    uint32_t DAT15_10;
    uint32_t DAT15_11;
    uint32_t DAT15_12;
    uint32_t DAT15_13;
    uint32_t DAT15_14;
    uint32_t DAT15_15;
    uint32_t DAT15_16;
    uint32_t DAT15_17;
    uint32_t DAT15_18;
    uint32_t DAT15_19;
    uint32_t DAT15_20;
    uint32_t DAT15_21;
    uint32_t DAT15_22;
    uint32_t DAT15_23;
    uint32_t DAT15_24;
    uint32_t DAT15_25;
    uint32_t DAT15_26;
    uint32_t DAT15_27;
    uint32_t DAT15_28;
    uint32_t DAT15_29;
    uint32_t DAT15_30;
    uint32_t DAT15_31;
} stc_crc_dat15_bit_t;

typedef struct
{
    uint32_t DAT16_0;
    uint32_t DAT16_1;
    uint32_t DAT16_2;
    uint32_t DAT16_3;
    uint32_t DAT16_4;
    uint32_t DAT16_5;
    uint32_t DAT16_6;
    uint32_t DAT16_7;
    uint32_t DAT16_8;
    uint32_t DAT16_9;
    uint32_t DAT16_10;
    uint32_t DAT16_11;
    uint32_t DAT16_12;
    uint32_t DAT16_13;
    uint32_t DAT16_14;
    uint32_t DAT16_15;
    uint32_t DAT16_16;
    uint32_t DAT16_17;
    uint32_t DAT16_18;
    uint32_t DAT16_19;
    uint32_t DAT16_20;
    uint32_t DAT16_21;
    uint32_t DAT16_22;
    uint32_t DAT16_23;
    uint32_t DAT16_24;
    uint32_t DAT16_25;
    uint32_t DAT16_26;
    uint32_t DAT16_27;
    uint32_t DAT16_28;
    uint32_t DAT16_29;
    uint32_t DAT16_30;
    uint32_t DAT16_31;
} stc_crc_dat16_bit_t;

typedef struct
{
    uint32_t DAT17_0;
    uint32_t DAT17_1;
    uint32_t DAT17_2;
    uint32_t DAT17_3;
    uint32_t DAT17_4;
    uint32_t DAT17_5;
    uint32_t DAT17_6;
    uint32_t DAT17_7;
    uint32_t DAT17_8;
    uint32_t DAT17_9;
    uint32_t DAT17_10;
    uint32_t DAT17_11;
    uint32_t DAT17_12;
    uint32_t DAT17_13;
    uint32_t DAT17_14;
    uint32_t DAT17_15;
    uint32_t DAT17_16;
    uint32_t DAT17_17;
    uint32_t DAT17_18;
    uint32_t DAT17_19;
    uint32_t DAT17_20;
    uint32_t DAT17_21;
    uint32_t DAT17_22;
    uint32_t DAT17_23;
    uint32_t DAT17_24;
    uint32_t DAT17_25;
    uint32_t DAT17_26;
    uint32_t DAT17_27;
    uint32_t DAT17_28;
    uint32_t DAT17_29;
    uint32_t DAT17_30;
    uint32_t DAT17_31;
} stc_crc_dat17_bit_t;

typedef struct
{
    uint32_t DAT18_0;
    uint32_t DAT18_1;
    uint32_t DAT18_2;
    uint32_t DAT18_3;
    uint32_t DAT18_4;
    uint32_t DAT18_5;
    uint32_t DAT18_6;
    uint32_t DAT18_7;
    uint32_t DAT18_8;
    uint32_t DAT18_9;
    uint32_t DAT18_10;
    uint32_t DAT18_11;
    uint32_t DAT18_12;
    uint32_t DAT18_13;
    uint32_t DAT18_14;
    uint32_t DAT18_15;
    uint32_t DAT18_16;
    uint32_t DAT18_17;
    uint32_t DAT18_18;
    uint32_t DAT18_19;
    uint32_t DAT18_20;
    uint32_t DAT18_21;
    uint32_t DAT18_22;
    uint32_t DAT18_23;
    uint32_t DAT18_24;
    uint32_t DAT18_25;
    uint32_t DAT18_26;
    uint32_t DAT18_27;
    uint32_t DAT18_28;
    uint32_t DAT18_29;
    uint32_t DAT18_30;
    uint32_t DAT18_31;
} stc_crc_dat18_bit_t;

typedef struct
{
    uint32_t DAT19_0;
    uint32_t DAT19_1;
    uint32_t DAT19_2;
    uint32_t DAT19_3;
    uint32_t DAT19_4;
    uint32_t DAT19_5;
    uint32_t DAT19_6;
    uint32_t DAT19_7;
    uint32_t DAT19_8;
    uint32_t DAT19_9;
    uint32_t DAT19_10;
    uint32_t DAT19_11;
    uint32_t DAT19_12;
    uint32_t DAT19_13;
    uint32_t DAT19_14;
    uint32_t DAT19_15;
    uint32_t DAT19_16;
    uint32_t DAT19_17;
    uint32_t DAT19_18;
    uint32_t DAT19_19;
    uint32_t DAT19_20;
    uint32_t DAT19_21;
    uint32_t DAT19_22;
    uint32_t DAT19_23;
    uint32_t DAT19_24;
    uint32_t DAT19_25;
    uint32_t DAT19_26;
    uint32_t DAT19_27;
    uint32_t DAT19_28;
    uint32_t DAT19_29;
    uint32_t DAT19_30;
    uint32_t DAT19_31;
} stc_crc_dat19_bit_t;

typedef struct
{
    uint32_t DAT20_0;
    uint32_t DAT20_1;
    uint32_t DAT20_2;
    uint32_t DAT20_3;
    uint32_t DAT20_4;
    uint32_t DAT20_5;
    uint32_t DAT20_6;
    uint32_t DAT20_7;
    uint32_t DAT20_8;
    uint32_t DAT20_9;
    uint32_t DAT20_10;
    uint32_t DAT20_11;
    uint32_t DAT20_12;
    uint32_t DAT20_13;
    uint32_t DAT20_14;
    uint32_t DAT20_15;
    uint32_t DAT20_16;
    uint32_t DAT20_17;
    uint32_t DAT20_18;
    uint32_t DAT20_19;
    uint32_t DAT20_20;
    uint32_t DAT20_21;
    uint32_t DAT20_22;
    uint32_t DAT20_23;
    uint32_t DAT20_24;
    uint32_t DAT20_25;
    uint32_t DAT20_26;
    uint32_t DAT20_27;
    uint32_t DAT20_28;
    uint32_t DAT20_29;
    uint32_t DAT20_30;
    uint32_t DAT20_31;
} stc_crc_dat20_bit_t;

typedef struct
{
    uint32_t DAT21_0;
    uint32_t DAT21_1;
    uint32_t DAT21_2;
    uint32_t DAT21_3;
    uint32_t DAT21_4;
    uint32_t DAT21_5;
    uint32_t DAT21_6;
    uint32_t DAT21_7;
    uint32_t DAT21_8;
    uint32_t DAT21_9;
    uint32_t DAT21_10;
    uint32_t DAT21_11;
    uint32_t DAT21_12;
    uint32_t DAT21_13;
    uint32_t DAT21_14;
    uint32_t DAT21_15;
    uint32_t DAT21_16;
    uint32_t DAT21_17;
    uint32_t DAT21_18;
    uint32_t DAT21_19;
    uint32_t DAT21_20;
    uint32_t DAT21_21;
    uint32_t DAT21_22;
    uint32_t DAT21_23;
    uint32_t DAT21_24;
    uint32_t DAT21_25;
    uint32_t DAT21_26;
    uint32_t DAT21_27;
    uint32_t DAT21_28;
    uint32_t DAT21_29;
    uint32_t DAT21_30;
    uint32_t DAT21_31;
} stc_crc_dat21_bit_t;

typedef struct
{
    uint32_t DAT22_0;
    uint32_t DAT22_1;
    uint32_t DAT22_2;
    uint32_t DAT22_3;
    uint32_t DAT22_4;
    uint32_t DAT22_5;
    uint32_t DAT22_6;
    uint32_t DAT22_7;
    uint32_t DAT22_8;
    uint32_t DAT22_9;
    uint32_t DAT22_10;
    uint32_t DAT22_11;
    uint32_t DAT22_12;
    uint32_t DAT22_13;
    uint32_t DAT22_14;
    uint32_t DAT22_15;
    uint32_t DAT22_16;
    uint32_t DAT22_17;
    uint32_t DAT22_18;
    uint32_t DAT22_19;
    uint32_t DAT22_20;
    uint32_t DAT22_21;
    uint32_t DAT22_22;
    uint32_t DAT22_23;
    uint32_t DAT22_24;
    uint32_t DAT22_25;
    uint32_t DAT22_26;
    uint32_t DAT22_27;
    uint32_t DAT22_28;
    uint32_t DAT22_29;
    uint32_t DAT22_30;
    uint32_t DAT22_31;
} stc_crc_dat22_bit_t;

typedef struct
{
    uint32_t DAT23_0;
    uint32_t DAT23_1;
    uint32_t DAT23_2;
    uint32_t DAT23_3;
    uint32_t DAT23_4;
    uint32_t DAT23_5;
    uint32_t DAT23_6;
    uint32_t DAT23_7;
    uint32_t DAT23_8;
    uint32_t DAT23_9;
    uint32_t DAT23_10;
    uint32_t DAT23_11;
    uint32_t DAT23_12;
    uint32_t DAT23_13;
    uint32_t DAT23_14;
    uint32_t DAT23_15;
    uint32_t DAT23_16;
    uint32_t DAT23_17;
    uint32_t DAT23_18;
    uint32_t DAT23_19;
    uint32_t DAT23_20;
    uint32_t DAT23_21;
    uint32_t DAT23_22;
    uint32_t DAT23_23;
    uint32_t DAT23_24;
    uint32_t DAT23_25;
    uint32_t DAT23_26;
    uint32_t DAT23_27;
    uint32_t DAT23_28;
    uint32_t DAT23_29;
    uint32_t DAT23_30;
    uint32_t DAT23_31;
} stc_crc_dat23_bit_t;

typedef struct
{
    uint32_t DAT24_0;
    uint32_t DAT24_1;
    uint32_t DAT24_2;
    uint32_t DAT24_3;
    uint32_t DAT24_4;
    uint32_t DAT24_5;
    uint32_t DAT24_6;
    uint32_t DAT24_7;
    uint32_t DAT24_8;
    uint32_t DAT24_9;
    uint32_t DAT24_10;
    uint32_t DAT24_11;
    uint32_t DAT24_12;
    uint32_t DAT24_13;
    uint32_t DAT24_14;
    uint32_t DAT24_15;
    uint32_t DAT24_16;
    uint32_t DAT24_17;
    uint32_t DAT24_18;
    uint32_t DAT24_19;
    uint32_t DAT24_20;
    uint32_t DAT24_21;
    uint32_t DAT24_22;
    uint32_t DAT24_23;
    uint32_t DAT24_24;
    uint32_t DAT24_25;
    uint32_t DAT24_26;
    uint32_t DAT24_27;
    uint32_t DAT24_28;
    uint32_t DAT24_29;
    uint32_t DAT24_30;
    uint32_t DAT24_31;
} stc_crc_dat24_bit_t;

typedef struct
{
    uint32_t DAT25_0;
    uint32_t DAT25_1;
    uint32_t DAT25_2;
    uint32_t DAT25_3;
    uint32_t DAT25_4;
    uint32_t DAT25_5;
    uint32_t DAT25_6;
    uint32_t DAT25_7;
    uint32_t DAT25_8;
    uint32_t DAT25_9;
    uint32_t DAT25_10;
    uint32_t DAT25_11;
    uint32_t DAT25_12;
    uint32_t DAT25_13;
    uint32_t DAT25_14;
    uint32_t DAT25_15;
    uint32_t DAT25_16;
    uint32_t DAT25_17;
    uint32_t DAT25_18;
    uint32_t DAT25_19;
    uint32_t DAT25_20;
    uint32_t DAT25_21;
    uint32_t DAT25_22;
    uint32_t DAT25_23;
    uint32_t DAT25_24;
    uint32_t DAT25_25;
    uint32_t DAT25_26;
    uint32_t DAT25_27;
    uint32_t DAT25_28;
    uint32_t DAT25_29;
    uint32_t DAT25_30;
    uint32_t DAT25_31;
} stc_crc_dat25_bit_t;

typedef struct
{
    uint32_t DAT26_0;
    uint32_t DAT26_1;
    uint32_t DAT26_2;
    uint32_t DAT26_3;
    uint32_t DAT26_4;
    uint32_t DAT26_5;
    uint32_t DAT26_6;
    uint32_t DAT26_7;
    uint32_t DAT26_8;
    uint32_t DAT26_9;
    uint32_t DAT26_10;
    uint32_t DAT26_11;
    uint32_t DAT26_12;
    uint32_t DAT26_13;
    uint32_t DAT26_14;
    uint32_t DAT26_15;
    uint32_t DAT26_16;
    uint32_t DAT26_17;
    uint32_t DAT26_18;
    uint32_t DAT26_19;
    uint32_t DAT26_20;
    uint32_t DAT26_21;
    uint32_t DAT26_22;
    uint32_t DAT26_23;
    uint32_t DAT26_24;
    uint32_t DAT26_25;
    uint32_t DAT26_26;
    uint32_t DAT26_27;
    uint32_t DAT26_28;
    uint32_t DAT26_29;
    uint32_t DAT26_30;
    uint32_t DAT26_31;
} stc_crc_dat26_bit_t;

typedef struct
{
    uint32_t DAT27_0;
    uint32_t DAT27_1;
    uint32_t DAT27_2;
    uint32_t DAT27_3;
    uint32_t DAT27_4;
    uint32_t DAT27_5;
    uint32_t DAT27_6;
    uint32_t DAT27_7;
    uint32_t DAT27_8;
    uint32_t DAT27_9;
    uint32_t DAT27_10;
    uint32_t DAT27_11;
    uint32_t DAT27_12;
    uint32_t DAT27_13;
    uint32_t DAT27_14;
    uint32_t DAT27_15;
    uint32_t DAT27_16;
    uint32_t DAT27_17;
    uint32_t DAT27_18;
    uint32_t DAT27_19;
    uint32_t DAT27_20;
    uint32_t DAT27_21;
    uint32_t DAT27_22;
    uint32_t DAT27_23;
    uint32_t DAT27_24;
    uint32_t DAT27_25;
    uint32_t DAT27_26;
    uint32_t DAT27_27;
    uint32_t DAT27_28;
    uint32_t DAT27_29;
    uint32_t DAT27_30;
    uint32_t DAT27_31;
} stc_crc_dat27_bit_t;

typedef struct
{
    uint32_t DAT28_0;
    uint32_t DAT28_1;
    uint32_t DAT28_2;
    uint32_t DAT28_3;
    uint32_t DAT28_4;
    uint32_t DAT28_5;
    uint32_t DAT28_6;
    uint32_t DAT28_7;
    uint32_t DAT28_8;
    uint32_t DAT28_9;
    uint32_t DAT28_10;
    uint32_t DAT28_11;
    uint32_t DAT28_12;
    uint32_t DAT28_13;
    uint32_t DAT28_14;
    uint32_t DAT28_15;
    uint32_t DAT28_16;
    uint32_t DAT28_17;
    uint32_t DAT28_18;
    uint32_t DAT28_19;
    uint32_t DAT28_20;
    uint32_t DAT28_21;
    uint32_t DAT28_22;
    uint32_t DAT28_23;
    uint32_t DAT28_24;
    uint32_t DAT28_25;
    uint32_t DAT28_26;
    uint32_t DAT28_27;
    uint32_t DAT28_28;
    uint32_t DAT28_29;
    uint32_t DAT28_30;
    uint32_t DAT28_31;
} stc_crc_dat28_bit_t;

typedef struct
{
    uint32_t DAT29_0;
    uint32_t DAT29_1;
    uint32_t DAT29_2;
    uint32_t DAT29_3;
    uint32_t DAT29_4;
    uint32_t DAT29_5;
    uint32_t DAT29_6;
    uint32_t DAT29_7;
    uint32_t DAT29_8;
    uint32_t DAT29_9;
    uint32_t DAT29_10;
    uint32_t DAT29_11;
    uint32_t DAT29_12;
    uint32_t DAT29_13;
    uint32_t DAT29_14;
    uint32_t DAT29_15;
    uint32_t DAT29_16;
    uint32_t DAT29_17;
    uint32_t DAT29_18;
    uint32_t DAT29_19;
    uint32_t DAT29_20;
    uint32_t DAT29_21;
    uint32_t DAT29_22;
    uint32_t DAT29_23;
    uint32_t DAT29_24;
    uint32_t DAT29_25;
    uint32_t DAT29_26;
    uint32_t DAT29_27;
    uint32_t DAT29_28;
    uint32_t DAT29_29;
    uint32_t DAT29_30;
    uint32_t DAT29_31;
} stc_crc_dat29_bit_t;

typedef struct
{
    uint32_t DAT30_0;
    uint32_t DAT30_1;
    uint32_t DAT30_2;
    uint32_t DAT30_3;
    uint32_t DAT30_4;
    uint32_t DAT30_5;
    uint32_t DAT30_6;
    uint32_t DAT30_7;
    uint32_t DAT30_8;
    uint32_t DAT30_9;
    uint32_t DAT30_10;
    uint32_t DAT30_11;
    uint32_t DAT30_12;
    uint32_t DAT30_13;
    uint32_t DAT30_14;
    uint32_t DAT30_15;
    uint32_t DAT30_16;
    uint32_t DAT30_17;
    uint32_t DAT30_18;
    uint32_t DAT30_19;
    uint32_t DAT30_20;
    uint32_t DAT30_21;
    uint32_t DAT30_22;
    uint32_t DAT30_23;
    uint32_t DAT30_24;
    uint32_t DAT30_25;
    uint32_t DAT30_26;
    uint32_t DAT30_27;
    uint32_t DAT30_28;
    uint32_t DAT30_29;
    uint32_t DAT30_30;
    uint32_t DAT30_31;
} stc_crc_dat30_bit_t;

typedef struct
{
    uint32_t DAT31_0;
    uint32_t DAT31_1;
    uint32_t DAT31_2;
    uint32_t DAT31_3;
    uint32_t DAT31_4;
    uint32_t DAT31_5;
    uint32_t DAT31_6;
    uint32_t DAT31_7;
    uint32_t DAT31_8;
    uint32_t DAT31_9;
    uint32_t DAT31_10;
    uint32_t DAT31_11;
    uint32_t DAT31_12;
    uint32_t DAT31_13;
    uint32_t DAT31_14;
    uint32_t DAT31_15;
    uint32_t DAT31_16;
    uint32_t DAT31_17;
    uint32_t DAT31_18;
    uint32_t DAT31_19;
    uint32_t DAT31_20;
    uint32_t DAT31_21;
    uint32_t DAT31_22;
    uint32_t DAT31_23;
    uint32_t DAT31_24;
    uint32_t DAT31_25;
    uint32_t DAT31_26;
    uint32_t DAT31_27;
    uint32_t DAT31_28;
    uint32_t DAT31_29;
    uint32_t DAT31_30;
    uint32_t DAT31_31;
} stc_crc_dat31_bit_t;

typedef struct
{
    __IO uint32_t REFPSC0;
    __IO uint32_t REFPSC1;
    __IO uint32_t REFPSC2;
    uint32_t RESERVED0[1];
    __IO uint32_t REFCKS0;
    __IO uint32_t REFCKS1;
    __IO uint32_t ERRIE;
    __IO uint32_t CTCEN;
    uint32_t RESERVED1[8];
    __IO uint32_t TRMVAL0;
    __IO uint32_t TRMVAL1;
    __IO uint32_t TRMVAL2;
    __IO uint32_t TRMVAL3;
    __IO uint32_t TRMVAL4;
    __IO uint32_t TRMVAL5;
    uint32_t RESERVED2[10];
} stc_ctc_cr1_bit_t;

typedef struct
{
    __IO uint32_t OFSVAL0;
    __IO uint32_t OFSVAL1;
    __IO uint32_t OFSVAL2;
    __IO uint32_t OFSVAL3;
    __IO uint32_t OFSVAL4;
    __IO uint32_t OFSVAL5;
    __IO uint32_t OFSVAL6;
    __IO uint32_t OFSVAL7;
    uint32_t RESERVED0[8];
    __IO uint32_t RLDVAL0;
    __IO uint32_t RLDVAL1;
    __IO uint32_t RLDVAL2;
    __IO uint32_t RLDVAL3;
    __IO uint32_t RLDVAL4;
    __IO uint32_t RLDVAL5;
    __IO uint32_t RLDVAL6;
    __IO uint32_t RLDVAL7;
    __IO uint32_t RLDVAL8;
    __IO uint32_t RLDVAL9;
    __IO uint32_t RLDVAL10;
    __IO uint32_t RLDVAL11;
    __IO uint32_t RLDVAL12;
    __IO uint32_t RLDVAL13;
    __IO uint32_t RLDVAL14;
    __IO uint32_t RLDVAL15;
} stc_ctc_cr2_bit_t;

typedef struct
{
    __IO uint32_t TRIMOK;
    __IO uint32_t TRMOVF;
    __IO uint32_t TRMUDF;
    __IO uint32_t CTCBSY;
    uint32_t RESERVED0[28];
} stc_ctc_str_bit_t;

typedef struct
{
    __IO uint32_t CDBGPWRUPREQ;
    __IO uint32_t CDBGPWRUPACK;
    uint32_t RESERVED0[30];
} stc_dbgc_mcudbgstat_bit_t;

typedef struct
{
    __IO uint32_t SWDTSTP;
    uint32_t RESERVED0[1];
    __IO uint32_t RTCSTP;
    __IO uint32_t PVDSTP;
    uint32_t RESERVED1[10];
    __IO uint32_t TMR01STP;
    uint32_t RESERVED2[2];
    __IO uint32_t TMR21STP;
    uint32_t RESERVED3[2];
    __IO uint32_t TMR41STP;
    uint32_t RESERVED4[2];
    __IO uint32_t TMRA1STP;
    __IO uint32_t TMRB1STP;
    __IO uint32_t TMRB2STP;
    __IO uint32_t TMRB3STP;
    __IO uint32_t TMRB4STP;
    __IO uint32_t TMRB5STP;
    __IO uint32_t TMRB6STP;
    __IO uint32_t TMRB7STP;
    __IO uint32_t TMRB8STP;
} stc_dbgc_mcustpctl_bit_t;

typedef struct
{
    __IO uint32_t FAPRT0;
    __IO uint32_t FAPRT1;
    __IO uint32_t FAPRT2;
    __IO uint32_t FAPRT3;
    __IO uint32_t FAPRT4;
    __IO uint32_t FAPRT5;
    __IO uint32_t FAPRT6;
    __IO uint32_t FAPRT7;
    __IO uint32_t FAPRT8;
    __IO uint32_t FAPRT9;
    __IO uint32_t FAPRT10;
    __IO uint32_t FAPRT11;
    __IO uint32_t FAPRT12;
    __IO uint32_t FAPRT13;
    __IO uint32_t FAPRT14;
    __IO uint32_t FAPRT15;
    uint32_t RESERVED0[16];
} stc_efm_faprt_bit_t;

typedef struct
{
    __IO uint32_t FSTP;
    uint32_t RESERVED0[31];
} stc_efm_fstp_bit_t;

typedef struct
{
    __IO uint32_t FLWT;
    uint32_t RESERVED0[16];
    __IO uint32_t PREFETE;
    uint32_t RESERVED1[14];
} stc_efm_frmc_bit_t;

typedef struct
{
    __IO uint32_t PEMODE;
    uint32_t RESERVED0[3];
    __IO uint32_t PEMOD0;
    __IO uint32_t PEMOD1;
    __IO uint32_t PEMOD2;
    uint32_t RESERVED1[1];
    __IO uint32_t BUSHLDCTL;
    uint32_t RESERVED2[23];
} stc_efm_fwmc_bit_t;

typedef struct
{
    __IO uint32_t PEWERR;
    __IO uint32_t PEPRTERR;
    uint32_t RESERVED0[1];
    __IO uint32_t PGMISMTCH;
    __IO uint32_t OPTEND;
    __IO uint32_t RDCOLERR;
    uint32_t RESERVED1[2];
    __IO uint32_t RDY;
    uint32_t RESERVED2[23];
} stc_efm_fsr_bit_t;

typedef struct
{
    __IO uint32_t PEWERRCLR;
    __IO uint32_t PEPRTERRCLR;
    uint32_t RESERVED0[1];
    __IO uint32_t PGMISMTCHCLR;
    __IO uint32_t OPTENDCLR;
    __IO uint32_t RDCOLERRCLR;
    uint32_t RESERVED1[26];
} stc_efm_fsclr_bit_t;

typedef struct
{
    __IO uint32_t PEERRITE;
    __IO uint32_t OPTENDITE;
    __IO uint32_t RDCOLERRITE;
    uint32_t RESERVED0[29];
} stc_efm_fite_bit_t;

typedef struct
{
    __IO uint32_t FPMTSW0;
    __IO uint32_t FPMTSW1;
    __IO uint32_t FPMTSW2;
    __IO uint32_t FPMTSW3;
    __IO uint32_t FPMTSW4;
    __IO uint32_t FPMTSW5;
    __IO uint32_t FPMTSW6;
    __IO uint32_t FPMTSW7;
    __IO uint32_t FPMTSW8;
    __IO uint32_t FPMTSW9;
    __IO uint32_t FPMTSW10;
    __IO uint32_t FPMTSW11;
    __IO uint32_t FPMTSW12;
    __IO uint32_t FPMTSW13;
    __IO uint32_t FPMTSW14;
    __IO uint32_t FPMTSW15;
    uint32_t RESERVED0[16];
} stc_efm_fpmtsw_bit_t;

typedef struct
{
    __IO uint32_t FPMTEW0;
    __IO uint32_t FPMTEW1;
    __IO uint32_t FPMTEW2;
    __IO uint32_t FPMTEW3;
    __IO uint32_t FPMTEW4;
    __IO uint32_t FPMTEW5;
    __IO uint32_t FPMTEW6;
    __IO uint32_t FPMTEW7;
    __IO uint32_t FPMTEW8;
    __IO uint32_t FPMTEW9;
    __IO uint32_t FPMTEW10;
    __IO uint32_t FPMTEW11;
    __IO uint32_t FPMTEW12;
    __IO uint32_t FPMTEW13;
    __IO uint32_t FPMTEW14;
    __IO uint32_t FPMTEW15;
    uint32_t RESERVED0[16];
} stc_efm_fpmtew_bit_t;

typedef struct
{
    uint32_t UQID0_0;
    uint32_t UQID0_1;
    uint32_t UQID0_2;
    uint32_t UQID0_3;
    uint32_t UQID0_4;
    uint32_t UQID0_5;
    uint32_t UQID0_6;
    uint32_t UQID0_7;
    uint32_t UQID0_8;
    uint32_t UQID0_9;
    uint32_t UQID0_10;
    uint32_t UQID0_11;
    uint32_t UQID0_12;
    uint32_t UQID0_13;
    uint32_t UQID0_14;
    uint32_t UQID0_15;
    uint32_t UQID0_16;
    uint32_t UQID0_17;
    uint32_t UQID0_18;
    uint32_t UQID0_19;
    uint32_t UQID0_20;
    uint32_t UQID0_21;
    uint32_t UQID0_22;
    uint32_t UQID0_23;
    uint32_t UQID0_24;
    uint32_t UQID0_25;
    uint32_t UQID0_26;
    uint32_t UQID0_27;
    uint32_t UQID0_28;
    uint32_t UQID0_29;
    uint32_t UQID0_30;
    uint32_t UQID0_31;
} stc_efm_uqid0_bit_t;

typedef struct
{
    uint32_t UQID1_0;
    uint32_t UQID1_1;
    uint32_t UQID1_2;
    uint32_t UQID1_3;
    uint32_t UQID1_4;
    uint32_t UQID1_5;
    uint32_t UQID1_6;
    uint32_t UQID1_7;
    uint32_t UQID1_8;
    uint32_t UQID1_9;
    uint32_t UQID1_10;
    uint32_t UQID1_11;
    uint32_t UQID1_12;
    uint32_t UQID1_13;
    uint32_t UQID1_14;
    uint32_t UQID1_15;
    uint32_t UQID1_16;
    uint32_t UQID1_17;
    uint32_t UQID1_18;
    uint32_t UQID1_19;
    uint32_t UQID1_20;
    uint32_t UQID1_21;
    uint32_t UQID1_22;
    uint32_t UQID1_23;
    uint32_t UQID1_24;
    uint32_t UQID1_25;
    uint32_t UQID1_26;
    uint32_t UQID1_27;
    uint32_t UQID1_28;
    uint32_t UQID1_29;
    uint32_t UQID1_30;
    uint32_t UQID1_31;
} stc_efm_uqid1_bit_t;

typedef struct
{
    uint32_t UQID2_0;
    uint32_t UQID2_1;
    uint32_t UQID2_2;
    uint32_t UQID2_3;
    uint32_t UQID2_4;
    uint32_t UQID2_5;
    uint32_t UQID2_6;
    uint32_t UQID2_7;
    uint32_t UQID2_8;
    uint32_t UQID2_9;
    uint32_t UQID2_10;
    uint32_t UQID2_11;
    uint32_t UQID2_12;
    uint32_t UQID2_13;
    uint32_t UQID2_14;
    uint32_t UQID2_15;
    uint32_t UQID2_16;
    uint32_t UQID2_17;
    uint32_t UQID2_18;
    uint32_t UQID2_19;
    uint32_t UQID2_20;
    uint32_t UQID2_21;
    uint32_t UQID2_22;
    uint32_t UQID2_23;
    uint32_t UQID2_24;
    uint32_t UQID2_25;
    uint32_t UQID2_26;
    uint32_t UQID2_27;
    uint32_t UQID2_28;
    uint32_t UQID2_29;
    uint32_t UQID2_30;
    uint32_t UQID2_31;
} stc_efm_uqid2_bit_t;

typedef struct
{
    __IO uint32_t HRCFREQS0;
    __IO uint32_t HRCFREQS1;
    __IO uint32_t HRCFREQS2;
    __IO uint32_t HRCFREQS3;
    uint32_t RESERVED0[4];
} stc_efm_hrccfgr_bit_t;

typedef struct
{
    __IO uint32_t DFS0;
    __IO uint32_t DFS1;
    __IO uint32_t DFDIS;
    uint32_t RESERVED0[5];
    __IO uint32_t LVDLVL0;
    __IO uint32_t LVDLVL1;
    __IO uint32_t LVDLVL2;
    __IO uint32_t LVDLVL3;
    __IO uint32_t NMIS;
    __IO uint32_t IRS;
    __IO uint32_t IRDIS;
    __IO uint32_t LVDDIS;
} stc_efm_lvdicgcr_bit_t;

typedef struct
{
    __IO uint32_t PE;
    __IO uint32_t SMBUS;
    __IO uint32_t SMBALRTEN;
    __IO uint32_t SMBDEFAULTEN;
    __IO uint32_t SMBHOSTEN;
    __IO uint32_t FACKEN;
    __IO uint32_t GCEN;
    __IO uint32_t RESTART;
    __IO uint32_t START;
    __IO uint32_t STOP;
    __IO uint32_t ACK;
    uint32_t RESERVED0[4];
    __IO uint32_t SWRST;
    uint32_t RESERVED1[16];
} stc_i2c_cr1_bit_t;

typedef struct
{
    __IO uint32_t STARTIE;
    __IO uint32_t SLADDR0IE;
    __IO uint32_t SLADDR1IE;
    __IO uint32_t TENDIE;
    __IO uint32_t STOPIE;
    uint32_t RESERVED0[1];
    __IO uint32_t RFULLIE;
    __IO uint32_t TEMPTYIE;
    uint32_t RESERVED1[1];
    __IO uint32_t ARLOIE;
    uint32_t RESERVED2[2];
    __IO uint32_t NACKIE;
    uint32_t RESERVED3[7];
    __IO uint32_t GENCALLIE;
    __IO uint32_t SMBDEFAULTIE;
    __IO uint32_t SMBHOSTIE;
    __IO uint32_t SMBALRTIE;
    uint32_t RESERVED4[8];
} stc_i2c_cr2_bit_t;

typedef struct
{
    __IO uint32_t SLADDR00;
    __IO uint32_t SLADDR01;
    __IO uint32_t SLADDR02;
    __IO uint32_t SLADDR03;
    __IO uint32_t SLADDR04;
    __IO uint32_t SLADDR05;
    __IO uint32_t SLADDR06;
    __IO uint32_t SLADDR07;
    __IO uint32_t SLADDR08;
    __IO uint32_t SLADDR09;
    uint32_t RESERVED0[2];
    __IO uint32_t SLADDR0EN;
    uint32_t RESERVED1[2];
    __IO uint32_t ADDRMOD0;
    uint32_t RESERVED2[16];
} stc_i2c_slr0_bit_t;

typedef struct
{
    __IO uint32_t SLADDR10;
    __IO uint32_t SLADDR11;
    __IO uint32_t SLADDR12;
    __IO uint32_t SLADDR13;
    __IO uint32_t SLADDR14;
    __IO uint32_t SLADDR15;
    __IO uint32_t SLADDR16;
    __IO uint32_t SLADDR17;
    __IO uint32_t SLADDR18;
    __IO uint32_t SLADDR19;
    uint32_t RESERVED0[2];
    __IO uint32_t SLADDR1EN;
    uint32_t RESERVED1[2];
    __IO uint32_t ADDRMOD1;
    uint32_t RESERVED2[16];
} stc_i2c_slr1_bit_t;

typedef struct
{
    __IO uint32_t STARTF;
    __IO uint32_t SLADDR0F;
    __IO uint32_t SLADDR1F;
    __IO uint32_t TENDF;
    __IO uint32_t STOPF;
    uint32_t RESERVED0[1];
    __IO uint32_t RFULLF;
    __IO uint32_t TEMPTYF;
    uint32_t RESERVED1[1];
    __IO uint32_t ARLOF;
    __IO uint32_t ACKRF;
    uint32_t RESERVED2[1];
    __IO uint32_t NACKF;
    uint32_t RESERVED3[3];
    __IO uint32_t MSL;
    __IO uint32_t BUSY;
    __IO uint32_t TRA;
    uint32_t RESERVED4[1];
    __IO uint32_t GENCALLF;
    __IO uint32_t SMBDEFAULTF;
    __IO uint32_t SMBHOSTF;
    __IO uint32_t SMBALRTF;
    uint32_t RESERVED5[8];
} stc_i2c_sr_bit_t;

typedef struct
{
    __IO uint32_t STARTFCLR;
    __IO uint32_t SLADDR0FCLR;
    __IO uint32_t SLADDR1FCLR;
    __IO uint32_t TENDFCLR;
    __IO uint32_t STOPFCLR;
    uint32_t RESERVED0[1];
    __IO uint32_t RFULLFCLR;
    __IO uint32_t TEMPTYFCLR;
    uint32_t RESERVED1[1];
    __IO uint32_t ARLOFCLR;
    uint32_t RESERVED2[2];
    __IO uint32_t NACKFCLR;
    uint32_t RESERVED3[7];
    __IO uint32_t GENCALLFCLR;
    __IO uint32_t SMBDEFAULTFCLR;
    __IO uint32_t SMBHOSTFCLR;
    __IO uint32_t SMBALRTFCLR;
    uint32_t RESERVED4[8];
} stc_i2c_clr_bit_t;

typedef struct
{
    __IO uint32_t DT0;
    __IO uint32_t DT1;
    __IO uint32_t DT2;
    __IO uint32_t DT3;
    __IO uint32_t DT4;
    __IO uint32_t DT5;
    __IO uint32_t DT6;
    __IO uint32_t DT7;
} stc_i2c_dtr_bit_t;

typedef struct
{
    __IO uint32_t DR0;
    __IO uint32_t DR1;
    __IO uint32_t DR2;
    __IO uint32_t DR3;
    __IO uint32_t DR4;
    __IO uint32_t DR5;
    __IO uint32_t DR6;
    __IO uint32_t DR7;
} stc_i2c_drr_bit_t;

typedef struct
{
    __IO uint32_t SLOWW0;
    __IO uint32_t SLOWW1;
    __IO uint32_t SLOWW2;
    __IO uint32_t SLOWW3;
    __IO uint32_t SLOWW4;
    uint32_t RESERVED0[3];
    __IO uint32_t SHIGHW0;
    __IO uint32_t SHIGHW1;
    __IO uint32_t SHIGHW2;
    __IO uint32_t SHIGHW3;
    __IO uint32_t SHIGHW4;
    uint32_t RESERVED1[3];
    __IO uint32_t CKDIV0;
    __IO uint32_t CKDIV1;
    __IO uint32_t CKDIV2;
    uint32_t RESERVED2[13];
} stc_i2c_ccr_bit_t;

typedef struct
{
    __IO uint32_t DNF0;
    __IO uint32_t DNF1;
    uint32_t RESERVED0[2];
    __IO uint32_t DNFEN;
    __IO uint32_t ANFEN;
    uint32_t RESERVED1[26];
} stc_i2c_fltr_bit_t;

typedef struct
{
    __IO uint32_t SWDTAUTS;
    __IO uint32_t SWDTITS;
    __IO uint32_t SWDTPERI0;
    __IO uint32_t SWDTPERI1;
    __IO uint32_t SWDTCKS0;
    __IO uint32_t SWDTCKS1;
    __IO uint32_t SWDTCKS2;
    __IO uint32_t SWDTCKS3;
    __IO uint32_t SWDTWDPT0;
    __IO uint32_t SWDTWDPT1;
    __IO uint32_t SWDTWDPT2;
    __IO uint32_t SWDTWDPT3;
    __IO uint32_t SWDTSLPOFF;
    uint32_t RESERVED0[3];
    __IO uint32_t HRCREQS0;
    __IO uint32_t HRCREQS1;
    __IO uint32_t HRCREQS2;
    __IO uint32_t HRCREQS3;
    uint32_t RESERVED1[6];
    __IO uint32_t NMIFCLK0;
    __IO uint32_t NMIFCLK1;
    __IO uint32_t NMIFEN;
    __IO uint32_t NMITRG;
    __IO uint32_t NMIEN;
    __IO uint32_t NMIICGENA;
} stc_icg_icg0_bit_t;

typedef struct
{
    __IO uint32_t DFS0;
    __IO uint32_t DFS1;
    __IO uint32_t DFDIS;
    uint32_t RESERVED0[5];
    __IO uint32_t LVDLVL0;
    __IO uint32_t LVDLVL1;
    __IO uint32_t LVDLVL2;
    __IO uint32_t LVDLVL3;
    __IO uint32_t NMIS;
    __IO uint32_t IRS;
    __IO uint32_t IRDIS;
    __IO uint32_t LVDDIS;
    uint32_t RESERVED1[16];
} stc_icg_icg1_bit_t;

typedef struct
{
    uint32_t ICG2_0;
    uint32_t ICG2_1;
    uint32_t ICG2_2;
    uint32_t ICG2_3;
    uint32_t ICG2_4;
    uint32_t ICG2_5;
    uint32_t ICG2_6;
    uint32_t ICG2_7;
    uint32_t ICG2_8;
    uint32_t ICG2_9;
    uint32_t ICG2_10;
    uint32_t ICG2_11;
    uint32_t ICG2_12;
    uint32_t ICG2_13;
    uint32_t ICG2_14;
    uint32_t ICG2_15;
    uint32_t ICG2_16;
    uint32_t ICG2_17;
    uint32_t ICG2_18;
    uint32_t ICG2_19;
    uint32_t ICG2_20;
    uint32_t ICG2_21;
    uint32_t ICG2_22;
    uint32_t ICG2_23;
    uint32_t ICG2_24;
    uint32_t ICG2_25;
    uint32_t ICG2_26;
    uint32_t ICG2_27;
    uint32_t ICG2_28;
    uint32_t ICG2_29;
    uint32_t ICG2_30;
    uint32_t ICG2_31;
} stc_icg_icg2_bit_t;

typedef struct
{
    uint32_t ICG3_0;
    uint32_t ICG3_1;
    uint32_t ICG3_2;
    uint32_t ICG3_3;
    uint32_t ICG3_4;
    uint32_t ICG3_5;
    uint32_t ICG3_6;
    uint32_t ICG3_7;
    uint32_t ICG3_8;
    uint32_t ICG3_9;
    uint32_t ICG3_10;
    uint32_t ICG3_11;
    uint32_t ICG3_12;
    uint32_t ICG3_13;
    uint32_t ICG3_14;
    uint32_t ICG3_15;
    uint32_t ICG3_16;
    uint32_t ICG3_17;
    uint32_t ICG3_18;
    uint32_t ICG3_19;
    uint32_t ICG3_20;
    uint32_t ICG3_21;
    uint32_t ICG3_22;
    uint32_t ICG3_23;
    uint32_t ICG3_24;
    uint32_t ICG3_25;
    uint32_t ICG3_26;
    uint32_t ICG3_27;
    uint32_t ICG3_28;
    uint32_t ICG3_29;
    uint32_t ICG3_30;
    uint32_t ICG3_31;
} stc_icg_icg3_bit_t;

typedef struct
{
    uint32_t ICG4_0;
    uint32_t ICG4_1;
    uint32_t ICG4_2;
    uint32_t ICG4_3;
    uint32_t ICG4_4;
    uint32_t ICG4_5;
    uint32_t ICG4_6;
    uint32_t ICG4_7;
    uint32_t ICG4_8;
    uint32_t ICG4_9;
    uint32_t ICG4_10;
    uint32_t ICG4_11;
    uint32_t ICG4_12;
    uint32_t ICG4_13;
    uint32_t ICG4_14;
    uint32_t ICG4_15;
    uint32_t ICG4_16;
    uint32_t ICG4_17;
    uint32_t ICG4_18;
    uint32_t ICG4_19;
    uint32_t ICG4_20;
    uint32_t ICG4_21;
    uint32_t ICG4_22;
    uint32_t ICG4_23;
    uint32_t ICG4_24;
    uint32_t ICG4_25;
    uint32_t ICG4_26;
    uint32_t ICG4_27;
    uint32_t ICG4_28;
    uint32_t ICG4_29;
    uint32_t ICG4_30;
    uint32_t ICG4_31;
} stc_icg_icg4_bit_t;

typedef struct
{
    uint32_t ICG5_0;
    uint32_t ICG5_1;
    uint32_t ICG5_2;
    uint32_t ICG5_3;
    uint32_t ICG5_4;
    uint32_t ICG5_5;
    uint32_t ICG5_6;
    uint32_t ICG5_7;
    uint32_t ICG5_8;
    uint32_t ICG5_9;
    uint32_t ICG5_10;
    uint32_t ICG5_11;
    uint32_t ICG5_12;
    uint32_t ICG5_13;
    uint32_t ICG5_14;
    uint32_t ICG5_15;
    uint32_t ICG5_16;
    uint32_t ICG5_17;
    uint32_t ICG5_18;
    uint32_t ICG5_19;
    uint32_t ICG5_20;
    uint32_t ICG5_21;
    uint32_t ICG5_22;
    uint32_t ICG5_23;
    uint32_t ICG5_24;
    uint32_t ICG5_25;
    uint32_t ICG5_26;
    uint32_t ICG5_27;
    uint32_t ICG5_28;
    uint32_t ICG5_29;
    uint32_t ICG5_30;
    uint32_t ICG5_31;
} stc_icg_icg5_bit_t;

typedef struct
{
    uint32_t ICG6_0;
    uint32_t ICG6_1;
    uint32_t ICG6_2;
    uint32_t ICG6_3;
    uint32_t ICG6_4;
    uint32_t ICG6_5;
    uint32_t ICG6_6;
    uint32_t ICG6_7;
    uint32_t ICG6_8;
    uint32_t ICG6_9;
    uint32_t ICG6_10;
    uint32_t ICG6_11;
    uint32_t ICG6_12;
    uint32_t ICG6_13;
    uint32_t ICG6_14;
    uint32_t ICG6_15;
    uint32_t ICG6_16;
    uint32_t ICG6_17;
    uint32_t ICG6_18;
    uint32_t ICG6_19;
    uint32_t ICG6_20;
    uint32_t ICG6_21;
    uint32_t ICG6_22;
    uint32_t ICG6_23;
    uint32_t ICG6_24;
    uint32_t ICG6_25;
    uint32_t ICG6_26;
    uint32_t ICG6_27;
    uint32_t ICG6_28;
    uint32_t ICG6_29;
    uint32_t ICG6_30;
    uint32_t ICG6_31;
} stc_icg_icg6_bit_t;

typedef struct
{
    __IO uint32_t NMITRG;
    uint32_t RESERVED0[3];
    __IO uint32_t NMIFCLK0;
    __IO uint32_t NMIFCLK1;
    uint32_t RESERVED1[1];
    __IO uint32_t NMIFEN;
    uint32_t RESERVED2[24];
} stc_intc_nmicr_bit_t;

typedef struct
{
    __IO uint32_t NMIEN;
    __IO uint32_t XTALSTPEN;
    __IO uint32_t SWDTEN;
    __IO uint32_t PVDEN;
    uint32_t RESERVED0[28];
} stc_intc_nmier_bit_t;

typedef struct
{
    __IO uint32_t NMIF;
    __IO uint32_t XTALSTPF;
    __IO uint32_t SWDTF;
    __IO uint32_t PVDF;
    uint32_t RESERVED0[28];
} stc_intc_nmifr_bit_t;

typedef struct
{
    __IO uint32_t NMICL;
    __IO uint32_t XTALSTPCL;
    __IO uint32_t SWDTCL;
    __IO uint32_t PVDCL;
    uint32_t RESERVED0[28];
} stc_intc_nmiclr_bit_t;

typedef struct
{
    __IO uint32_t EVTEN0;
    __IO uint32_t EVTEN1;
    __IO uint32_t EVTEN2;
    __IO uint32_t EVTEN3;
    __IO uint32_t EVTEN4;
    __IO uint32_t EVTEN5;
    __IO uint32_t EVTEN6;
    __IO uint32_t EVTEN7;
    uint32_t RESERVED0[24];
} stc_intc_evter_bit_t;

typedef struct
{
    __IO uint32_t EKEY0EN;
    __IO uint32_t EKEY1EN;
    __IO uint32_t EKEY2EN;
    __IO uint32_t EKEY3EN;
    __IO uint32_t EKEY4EN;
    __IO uint32_t EKEY5EN;
    uint32_t RESERVED0[26];
} stc_intc_ekeycr_bit_t;

typedef struct
{
    __IO uint32_t FPRC0;
    __IO uint32_t FPRC1;
    __IO uint32_t FPRC2;
    __IO uint32_t FPRC3;
    __IO uint32_t FPRC4;
    __IO uint32_t FPRC5;
    __IO uint32_t FPRC6;
    __IO uint32_t FPRC7;
    uint32_t RESERVED0[24];
} stc_intc_fprcr_bit_t;

typedef struct
{
    __IO uint32_t EIRQTRG0;
    __IO uint32_t EIRQTRG1;
    uint32_t RESERVED0[2];
    __IO uint32_t EIRQFCLK0;
    __IO uint32_t EIRQFCLK1;
    uint32_t RESERVED1[1];
    __IO uint32_t EIRQFEN;
    uint32_t RESERVED2[24];
} stc_intc_eirqcr_bit_t;

typedef struct
{
    __IO uint32_t EIRQWUEN0;
    __IO uint32_t EIRQWUEN1;
    __IO uint32_t EIRQWUEN2;
    __IO uint32_t EIRQWUEN3;
    __IO uint32_t EIRQWUEN4;
    __IO uint32_t EIRQWUEN5;
    __IO uint32_t EIRQWUEN6;
    __IO uint32_t EIRQWUEN7;
    __IO uint32_t EIRQWUEN8;
    __IO uint32_t EIRQWUEN9;
    uint32_t RESERVED0[6];
    __IO uint32_t SWDTWUEN;
    __IO uint32_t EKEYWUEN;
    __IO uint32_t TMR0CMPWUEN;
    uint32_t RESERVED1[3];
    __IO uint32_t PVDWUEN;
    __IO uint32_t RTCALMWUEN;
    __IO uint32_t RTCPRDWUEN;
    uint32_t RESERVED2[7];
} stc_intc_wupenr_bit_t;

typedef struct
{
    __IO uint32_t EIRQF0;
    __IO uint32_t EIRQF1;
    __IO uint32_t EIRQF2;
    __IO uint32_t EIRQF3;
    __IO uint32_t EIRQF4;
    __IO uint32_t EIRQF5;
    __IO uint32_t EIRQF6;
    __IO uint32_t EIRQF7;
    __IO uint32_t EIRQF8;
    __IO uint32_t EIRQF9;
    uint32_t RESERVED0[22];
} stc_intc_eirqfr_bit_t;

typedef struct
{
    __IO uint32_t EIRQCL0;
    __IO uint32_t EIRQCL1;
    __IO uint32_t EIRQCL2;
    __IO uint32_t EIRQCL3;
    __IO uint32_t EIRQCL4;
    __IO uint32_t EIRQCL5;
    __IO uint32_t EIRQCL6;
    __IO uint32_t EIRQCL7;
    __IO uint32_t EIRQCL8;
    __IO uint32_t EIRQCL9;
    uint32_t RESERVED0[22];
} stc_intc_eirqclr_bit_t;

typedef struct
{
    __IO uint32_t ISEL0;
    __IO uint32_t ISEL1;
    __IO uint32_t ISEL2;
    __IO uint32_t ISEL3;
    uint32_t RESERVED0[28];
} stc_intc_iselar_bit_t;

typedef struct
{
    uint32_t RESERVED0[1];
    __IO uint32_t ISEL1;
    __IO uint32_t ISEL2;
    __IO uint32_t ISEL3;
    __IO uint32_t ISEL4;
    __IO uint32_t ISEL5;
    __IO uint32_t ISEL6;
    __IO uint32_t ISEL7;
    __IO uint32_t ISEL8;
    __IO uint32_t ISEL9;
    __IO uint32_t ISEL10;
    __IO uint32_t ISEL11;
    __IO uint32_t ISEL12;
    __IO uint32_t ISEL13;
    __IO uint32_t ISEL14;
    __IO uint32_t ISEL15;
    uint32_t RESERVED1[16];
} stc_intc_iselbr_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    uint32_t RESERVED0[6];
} stc_port_pidr0_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    __IO uint32_t PIN2;
    __IO uint32_t PIN3;
    __IO uint32_t PIN4;
    __IO uint32_t PIN5;
    __IO uint32_t PIN6;
    __IO uint32_t PIN7;
} stc_port_pidr1_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    __IO uint32_t PIN2;
    __IO uint32_t PIN3;
    __IO uint32_t PIN4;
    __IO uint32_t PIN5;
    __IO uint32_t PIN6;
    __IO uint32_t PIN7;
} stc_port_pidr2_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    uint32_t RESERVED0[6];
} stc_port_pidr3_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    uint32_t RESERVED0[6];
} stc_port_pidr4_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    uint32_t RESERVED0[6];
} stc_port_pidr5_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    __IO uint32_t PIN2;
    __IO uint32_t PIN3;
    uint32_t RESERVED0[4];
} stc_port_pidr6_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    __IO uint32_t PIN2;
    __IO uint32_t PIN3;
    uint32_t RESERVED0[4];
} stc_port_pidr7_bit_t;

typedef struct
{
    __IO uint32_t PIN0;
    __IO uint32_t PIN1;
    __IO uint32_t PIN2;
    __IO uint32_t PIN3;
    __IO uint32_t PIN4;
    uint32_t RESERVED0[3];
} stc_port_pidr12_bit_t;

typedef struct
{
    uint32_t RESERVED0[7];
    __IO uint32_t PIN7;
} stc_port_pidr13_bit_t;

typedef struct
{
    uint32_t RESERVED0[6];
    __IO uint32_t PIN6;
    __IO uint32_t PIN7;
} stc_port_pidr14_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    uint32_t RESERVED0[6];
} stc_port_podr0_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    __IO uint32_t POUT2;
    __IO uint32_t POUT3;
    __IO uint32_t POUT4;
    __IO uint32_t POUT5;
    __IO uint32_t POUT6;
    __IO uint32_t POUT7;
} stc_port_podr1_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    __IO uint32_t POUT2;
    __IO uint32_t POUT3;
    __IO uint32_t POUT4;
    __IO uint32_t POUT5;
    __IO uint32_t POUT6;
    __IO uint32_t POUT7;
} stc_port_podr2_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    uint32_t RESERVED0[6];
} stc_port_podr3_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    uint32_t RESERVED0[6];
} stc_port_podr4_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    uint32_t RESERVED0[6];
} stc_port_podr5_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    __IO uint32_t POUT2;
    __IO uint32_t POUT3;
    uint32_t RESERVED0[4];
} stc_port_podr6_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    __IO uint32_t POUT2;
    __IO uint32_t POUT3;
    uint32_t RESERVED0[4];
} stc_port_podr7_bit_t;

typedef struct
{
    __IO uint32_t POUT0;
    __IO uint32_t POUT1;
    __IO uint32_t POUT2;
    __IO uint32_t POUT3;
    __IO uint32_t POUT4;
    uint32_t RESERVED0[3];
} stc_port_podr12_bit_t;

typedef struct
{
    uint32_t RESERVED0[7];
    __IO uint32_t POUT7;
} stc_port_podr13_bit_t;

typedef struct
{
    uint32_t RESERVED0[6];
    __IO uint32_t POUT6;
    __IO uint32_t POUT7;
} stc_port_podr14_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    uint32_t RESERVED0[6];
} stc_port_poer0_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    __IO uint32_t POUTE2;
    __IO uint32_t POUTE3;
    __IO uint32_t POUTE4;
    __IO uint32_t POUTE5;
    __IO uint32_t POUTE6;
    __IO uint32_t POUTE7;
} stc_port_poer1_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    __IO uint32_t POUTE2;
    __IO uint32_t POUTE3;
    __IO uint32_t POUTE4;
    __IO uint32_t POUTE5;
    __IO uint32_t POUTE6;
    __IO uint32_t POUTE7;
} stc_port_poer2_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    uint32_t RESERVED0[6];
} stc_port_poer3_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    uint32_t RESERVED0[6];
} stc_port_poer4_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    uint32_t RESERVED0[6];
} stc_port_poer5_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    __IO uint32_t POUTE2;
    __IO uint32_t POUTE3;
    uint32_t RESERVED0[4];
} stc_port_poer6_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    __IO uint32_t POUTE2;
    __IO uint32_t POUTE3;
    uint32_t RESERVED0[4];
} stc_port_poer7_bit_t;

typedef struct
{
    __IO uint32_t POUTE0;
    __IO uint32_t POUTE1;
    __IO uint32_t POUTE2;
    __IO uint32_t POUTE3;
    __IO uint32_t POUTE4;
    uint32_t RESERVED0[3];
} stc_port_poer12_bit_t;

typedef struct
{
    uint32_t RESERVED0[7];
    __IO uint32_t POUTE7;
} stc_port_poer13_bit_t;

typedef struct
{
    uint32_t RESERVED0[6];
    __IO uint32_t POUTE6;
    __IO uint32_t POUTE7;
} stc_port_poer14_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    uint32_t RESERVED0[6];
} stc_port_posr0_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    __IO uint32_t POS2;
    __IO uint32_t POS3;
    __IO uint32_t POS4;
    __IO uint32_t POS5;
    __IO uint32_t POS6;
    __IO uint32_t POS7;
} stc_port_posr1_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    __IO uint32_t POS2;
    __IO uint32_t POS3;
    __IO uint32_t POS4;
    __IO uint32_t POS5;
    __IO uint32_t POS6;
    __IO uint32_t POS7;
} stc_port_posr2_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    uint32_t RESERVED0[6];
} stc_port_posr3_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    uint32_t RESERVED0[6];
} stc_port_posr4_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    uint32_t RESERVED0[6];
} stc_port_posr5_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    __IO uint32_t POS2;
    __IO uint32_t POS3;
    uint32_t RESERVED0[4];
} stc_port_posr6_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    __IO uint32_t POS2;
    __IO uint32_t POS3;
    uint32_t RESERVED0[4];
} stc_port_posr7_bit_t;

typedef struct
{
    __IO uint32_t POS0;
    __IO uint32_t POS1;
    __IO uint32_t POS2;
    __IO uint32_t POS3;
    __IO uint32_t POS4;
    uint32_t RESERVED0[3];
} stc_port_posr12_bit_t;

typedef struct
{
    uint32_t RESERVED0[7];
    __IO uint32_t POS7;
} stc_port_posr13_bit_t;

typedef struct
{
    uint32_t RESERVED0[6];
    __IO uint32_t POS6;
    __IO uint32_t POS7;
} stc_port_posr14_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    uint32_t RESERVED0[6];
} stc_port_porr0_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    __IO uint32_t POR2;
    __IO uint32_t POR3;
    __IO uint32_t POR4;
    __IO uint32_t POR5;
    __IO uint32_t POR6;
    __IO uint32_t POR7;
} stc_port_porr1_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    __IO uint32_t POR2;
    __IO uint32_t POR3;
    __IO uint32_t POR4;
    __IO uint32_t POR5;
    __IO uint32_t POR6;
    __IO uint32_t POR7;
} stc_port_porr2_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    uint32_t RESERVED0[6];
} stc_port_porr3_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    uint32_t RESERVED0[6];
} stc_port_porr4_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    uint32_t RESERVED0[6];
} stc_port_porr5_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    __IO uint32_t POR2;
    __IO uint32_t POR3;
    uint32_t RESERVED0[4];
} stc_port_porr6_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    __IO uint32_t POR2;
    __IO uint32_t POR3;
    uint32_t RESERVED0[4];
} stc_port_porr7_bit_t;

typedef struct
{
    __IO uint32_t POR0;
    __IO uint32_t POR1;
    __IO uint32_t POR2;
    __IO uint32_t POR3;
    __IO uint32_t POR4;
    uint32_t RESERVED0[3];
} stc_port_porr12_bit_t;

typedef struct
{
    uint32_t RESERVED0[7];
    __IO uint32_t POR7;
} stc_port_porr13_bit_t;

typedef struct
{
    uint32_t RESERVED0[6];
    __IO uint32_t POR6;
    __IO uint32_t POR7;
} stc_port_porr14_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    uint32_t RESERVED0[6];
} stc_port_potr0_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    __IO uint32_t POT2;
    __IO uint32_t POT3;
    __IO uint32_t POT4;
    __IO uint32_t POT5;
    __IO uint32_t POT6;
    __IO uint32_t POT7;
} stc_port_potr1_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    __IO uint32_t POT2;
    __IO uint32_t POT3;
    __IO uint32_t POT4;
    __IO uint32_t POT5;
    __IO uint32_t POT6;
    __IO uint32_t POT7;
} stc_port_potr2_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    uint32_t RESERVED0[6];
} stc_port_potr3_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    uint32_t RESERVED0[6];
} stc_port_potr4_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    uint32_t RESERVED0[6];
} stc_port_potr5_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    __IO uint32_t POT2;
    __IO uint32_t POT3;
    uint32_t RESERVED0[4];
} stc_port_potr6_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    __IO uint32_t POT2;
    __IO uint32_t POT3;
    uint32_t RESERVED0[4];
} stc_port_potr7_bit_t;

typedef struct
{
    __IO uint32_t POT0;
    __IO uint32_t POT1;
    __IO uint32_t POT2;
    __IO uint32_t POT3;
    __IO uint32_t POT4;
    uint32_t RESERVED0[3];
} stc_port_potr12_bit_t;

typedef struct
{
    uint32_t RESERVED0[7];
    __IO uint32_t POT7;
} stc_port_potr13_bit_t;

typedef struct
{
    uint32_t RESERVED0[6];
    __IO uint32_t POT6;
    __IO uint32_t POT7;
} stc_port_potr14_bit_t;

typedef struct
{
    __IO uint32_t SPFE0;
    __IO uint32_t SPFE1;
    uint32_t RESERVED0[14];
} stc_port_pspcr_bit_t;

typedef struct
{
    uint32_t RESERVED0[14];
    __IO uint32_t RDWT0;
    __IO uint32_t RDWT1;
} stc_port_pccr_bit_t;

typedef struct
{
    __IO uint32_t PINAE0;
    __IO uint32_t PINAE1;
    __IO uint32_t PINAE2;
    __IO uint32_t PINAE3;
    __IO uint32_t PINAE4;
    __IO uint32_t PINAE5;
    __IO uint32_t PINAE6;
    __IO uint32_t PINAE7;
    uint32_t RESERVED0[4];
    __IO uint32_t PINAE12;
    __IO uint32_t PINAE13;
    __IO uint32_t PINAE14;
    uint32_t RESERVED1[1];
} stc_port_pinaer_bit_t;

typedef struct
{
    __IO uint32_t WE;
    uint32_t RESERVED0[7];
    __IO uint32_t WP0;
    __IO uint32_t WP1;
    __IO uint32_t WP2;
    __IO uint32_t WP3;
    __IO uint32_t WP4;
    __IO uint32_t WP5;
    __IO uint32_t WP6;
    __IO uint32_t WP7;
} stc_port_pwpr_bit_t;

typedef struct
{
    uint32_t RESERVED0[1];
    __IO uint32_t CKSHRC;
    uint32_t RESERVED1[1];
    __IO uint32_t HAPORDIS;
    uint32_t RESERVED2[3];
    __IO uint32_t STOP;
} stc_pwc_stpmcr_bit_t;

typedef struct
{
    __IO uint32_t PWDRV0;
    __IO uint32_t PWDRV1;
    __IO uint32_t PWDRV2;
    uint32_t RESERVED0[1];
    __IO uint32_t PWMONSEL;
    __IO uint32_t PWMONE;
    uint32_t RESERVED1[2];
} stc_pwc_pwrc_bit_t;

typedef struct
{
    __IO uint32_t RPRTA0;
    __IO uint32_t RPRTA1;
    uint32_t RESERVED0[2];
    __IO uint32_t RPERDIS;
    __IO uint32_t RPEF;
    uint32_t RESERVED1[2];
} stc_pwc_ramcr_bit_t;

typedef struct
{
    __IO uint32_t EXVCCINEN;
    uint32_t RESERVED0[2];
    __IO uint32_t LVIF;
    __IO uint32_t DETF;
    uint32_t RESERVED1[2];
    __IO uint32_t CMPOE;
} stc_pwc_lvdcsr_bit_t;

typedef struct
{
    __IO uint32_t CKRWE;
    __IO uint32_t PWRWE;
    __IO uint32_t FPRCB2;
    __IO uint32_t LVRWE;
    __IO uint32_t FPRCB4;
    __IO uint32_t FPRCB5;
    __IO uint32_t FPRCB6;
    __IO uint32_t FPRCB7;
    __IO uint32_t FPRCWE0;
    __IO uint32_t FPRCWE1;
    __IO uint32_t FPRCWE2;
    __IO uint32_t FPRCWE3;
    __IO uint32_t FPRCWE4;
    __IO uint32_t FPRCWE5;
    __IO uint32_t FPRCWE6;
    __IO uint32_t FPRCWE7;
} stc_pwc_fprc_bit_t;

typedef struct
{
    __IO uint32_t DBGEN;
    uint32_t RESERVED0[7];
} stc_pwc_dbgc_bit_t;

typedef struct
{
    __IO uint32_t PORF;
    __IO uint32_t PINRF;
    __IO uint32_t LVRF;
    uint32_t RESERVED0[2];
    __IO uint32_t WDRF;
    uint32_t RESERVED1[2];
    __IO uint32_t SWRF;
    uint32_t RESERVED2[1];
    __IO uint32_t RAMPERF;
    uint32_t RESERVED3[1];
    __IO uint32_t CPULKUPRF;
    __IO uint32_t XTALERF;
    __IO uint32_t MULTIRF;
    __IO uint32_t CLRF;
} stc_rmu_rstf0_bit_t;

typedef struct
{
    __IO uint32_t RESET;
    uint32_t RESERVED0[7];
} stc_rtc_cr0_bit_t;

typedef struct
{
    __IO uint32_t PRDS0;
    __IO uint32_t PRDS1;
    __IO uint32_t PRDS2;
    __IO uint32_t AMPM;
    uint32_t RESERVED0[1];
    __IO uint32_t ONEHZOE;
    uint32_t RESERVED1[1];
    __IO uint32_t START;
} stc_rtc_cr1_bit_t;

typedef struct
{
    __IO uint32_t WAIT;
    __IO uint32_t WAITF;
    __IO uint32_t PRDF;
    __IO uint32_t ALMF;
    uint32_t RESERVED0[1];
    __IO uint32_t PRDIE;
    __IO uint32_t ALMIE;
    __IO uint32_t ALME;
} stc_rtc_cr2_bit_t;

typedef struct
{
    uint32_t RESERVED0[4];
    __IO uint32_t LRCEN;
    uint32_t RESERVED1[2];
    __IO uint32_t RCKSEL;
} stc_rtc_cr3_bit_t;

typedef struct
{
    __IO uint32_t SECU0;
    __IO uint32_t SECU1;
    __IO uint32_t SECU2;
    __IO uint32_t SECU3;
    __IO uint32_t SECD0;
    __IO uint32_t SECD1;
    __IO uint32_t SECD2;
    uint32_t RESERVED0[1];
} stc_rtc_sec_bit_t;

typedef struct
{
    __IO uint32_t MINU0;
    __IO uint32_t MINU1;
    __IO uint32_t MINU2;
    __IO uint32_t MINU3;
    __IO uint32_t MIND0;
    __IO uint32_t MIND1;
    __IO uint32_t MIND2;
    uint32_t RESERVED0[1];
} stc_rtc_min_bit_t;

typedef struct
{
    __IO uint32_t HOURU0;
    __IO uint32_t HOURU1;
    __IO uint32_t HOURU2;
    __IO uint32_t HOURU3;
    __IO uint32_t HOURD0;
    __IO uint32_t HOURD1;
    uint32_t RESERVED0[2];
} stc_rtc_hour_bit_t;

typedef struct
{
    __IO uint32_t WEEK0;
    __IO uint32_t WEEK1;
    __IO uint32_t WEEK2;
    uint32_t RESERVED0[5];
} stc_rtc_week_bit_t;

typedef struct
{
    __IO uint32_t DAYU0;
    __IO uint32_t DAYU1;
    __IO uint32_t DAYU2;
    __IO uint32_t DAYU3;
    __IO uint32_t DAYD0;
    __IO uint32_t DAYD1;
    uint32_t RESERVED0[2];
} stc_rtc_day_bit_t;

typedef struct
{
    __IO uint32_t MON0;
    __IO uint32_t MON1;
    __IO uint32_t MON2;
    __IO uint32_t MON3;
    __IO uint32_t MON4;
    uint32_t RESERVED0[3];
} stc_rtc_mon_bit_t;

typedef struct
{
    __IO uint32_t YEARU0;
    __IO uint32_t YEARU1;
    __IO uint32_t YEARU2;
    __IO uint32_t YEARU3;
    __IO uint32_t YEARD0;
    __IO uint32_t YEARD1;
    __IO uint32_t YEARD2;
    __IO uint32_t YEARD3;
} stc_rtc_year_bit_t;

typedef struct
{
    __IO uint32_t ALMMINU0;
    __IO uint32_t ALMMINU1;
    __IO uint32_t ALMMINU2;
    __IO uint32_t ALMMINU3;
    __IO uint32_t ALMMIND0;
    __IO uint32_t ALMMIND1;
    __IO uint32_t ALMMIND2;
    uint32_t RESERVED0[1];
} stc_rtc_almmin_bit_t;

typedef struct
{
    __IO uint32_t ALMHOURU0;
    __IO uint32_t ALMHOURU1;
    __IO uint32_t ALMHOURU2;
    __IO uint32_t ALMHOURU3;
    __IO uint32_t ALMHOURD0;
    __IO uint32_t ALMHOURD1;
    uint32_t RESERVED0[2];
} stc_rtc_almhour_bit_t;

typedef struct
{
    __IO uint32_t ALMWEEK0;
    __IO uint32_t ALMWEEK1;
    __IO uint32_t ALMWEEK2;
    __IO uint32_t ALMWEEK3;
    __IO uint32_t ALMWEEK4;
    __IO uint32_t ALMWEEK5;
    __IO uint32_t ALMWEEK6;
    uint32_t RESERVED0[1];
} stc_rtc_almweek_bit_t;

typedef struct
{
    __IO uint32_t COMP8;
    uint32_t RESERVED0[6];
    __IO uint32_t COMPEN;
} stc_rtc_errcrh_bit_t;

typedef struct
{
    __IO uint32_t COMP0;
    __IO uint32_t COMP1;
    __IO uint32_t COMP2;
    __IO uint32_t COMP3;
    __IO uint32_t COMP4;
    __IO uint32_t COMP5;
    __IO uint32_t COMP6;
    __IO uint32_t COMP7;
} stc_rtc_errcrl_bit_t;

typedef struct
{
    __IO uint32_t SPD0;
    __IO uint32_t SPD1;
    __IO uint32_t SPD2;
    __IO uint32_t SPD3;
    __IO uint32_t SPD4;
    __IO uint32_t SPD5;
    __IO uint32_t SPD6;
    __IO uint32_t SPD7;
    __IO uint32_t SPD8;
    __IO uint32_t SPD9;
    __IO uint32_t SPD10;
    __IO uint32_t SPD11;
    __IO uint32_t SPD12;
    __IO uint32_t SPD13;
    __IO uint32_t SPD14;
    __IO uint32_t SPD15;
    uint32_t RESERVED0[16];
} stc_spi_dr_bit_t;

typedef struct
{
    __IO uint32_t SPIMDS;
    __IO uint32_t TXMDS;
    uint32_t RESERVED0[1];
    __IO uint32_t MSTR;
    __IO uint32_t SPLPBK;
    __IO uint32_t SPLPBK2;
    __IO uint32_t SPE;
    uint32_t RESERVED1[1];
    __IO uint32_t EIE;
    __IO uint32_t TXIE;
    __IO uint32_t RXIE;
    __IO uint32_t IDIE;
    __IO uint32_t MODFE;
    __IO uint32_t PATE;
    __IO uint32_t PAOE;
    __IO uint32_t PAE;
    uint32_t RESERVED2[16];
} stc_spi_cr1_bit_t;

typedef struct
{
    uint32_t RESERVED0[8];
    __IO uint32_t SS0PV;
    uint32_t RESERVED1[23];
} stc_spi_cfg1_bit_t;

typedef struct
{
    __IO uint32_t OVRERF;
    __IO uint32_t IDLNF;
    __IO uint32_t MODFERF;
    __IO uint32_t PERF;
    __IO uint32_t UDRERF;
    __IO uint32_t TDEF;
    uint32_t RESERVED0[1];
    __IO uint32_t RDFF;
    uint32_t RESERVED1[24];
} stc_spi_sr_bit_t;

typedef struct
{
    __IO uint32_t CPHA;
    __IO uint32_t CPOL;
    __IO uint32_t MBR0;
    __IO uint32_t MBR1;
    __IO uint32_t MBR2;
    uint32_t RESERVED0[3];
    __IO uint32_t DSIZE;
    uint32_t RESERVED1[2];
    __IO uint32_t LSBF;
    uint32_t RESERVED2[20];
} stc_spi_cfg2_bit_t;

typedef struct
{
    __IO uint32_t PERI0;
    __IO uint32_t PERI1;
    uint32_t RESERVED0[2];
    __IO uint32_t CKS0;
    __IO uint32_t CKS1;
    __IO uint32_t CKS2;
    __IO uint32_t CKS3;
    __IO uint32_t WDPT0;
    __IO uint32_t WDPT1;
    __IO uint32_t WDPT2;
    __IO uint32_t WDPT3;
    uint32_t RESERVED1[4];
    __IO uint32_t SLPOFF;
    uint32_t RESERVED2[14];
    __IO uint32_t ITS;
} stc_swdt_cr_bit_t;

typedef struct
{
    __IO uint32_t CNT0;
    __IO uint32_t CNT1;
    __IO uint32_t CNT2;
    __IO uint32_t CNT3;
    __IO uint32_t CNT4;
    __IO uint32_t CNT5;
    __IO uint32_t CNT6;
    __IO uint32_t CNT7;
    __IO uint32_t CNT8;
    __IO uint32_t CNT9;
    __IO uint32_t CNT10;
    __IO uint32_t CNT11;
    __IO uint32_t CNT12;
    __IO uint32_t CNT13;
    __IO uint32_t CNT14;
    __IO uint32_t CNT15;
    __IO uint32_t UDF;
    __IO uint32_t REF;
    uint32_t RESERVED0[14];
} stc_swdt_sr_bit_t;

typedef struct
{
    __IO uint32_t RF0;
    __IO uint32_t RF1;
    __IO uint32_t RF2;
    __IO uint32_t RF3;
    __IO uint32_t RF4;
    __IO uint32_t RF5;
    __IO uint32_t RF6;
    __IO uint32_t RF7;
    __IO uint32_t RF8;
    __IO uint32_t RF9;
    __IO uint32_t RF10;
    __IO uint32_t RF11;
    __IO uint32_t RF12;
    __IO uint32_t RF13;
    __IO uint32_t RF14;
    __IO uint32_t RF15;
    uint32_t RESERVED0[16];
} stc_swdt_rr_bit_t;

typedef struct
{
    __IO uint32_t CNTA0;
    __IO uint32_t CNTA1;
    __IO uint32_t CNTA2;
    __IO uint32_t CNTA3;
    __IO uint32_t CNTA4;
    __IO uint32_t CNTA5;
    __IO uint32_t CNTA6;
    __IO uint32_t CNTA7;
    __IO uint32_t CNTA8;
    __IO uint32_t CNTA9;
    __IO uint32_t CNTA10;
    __IO uint32_t CNTA11;
    __IO uint32_t CNTA12;
    __IO uint32_t CNTA13;
    __IO uint32_t CNTA14;
    __IO uint32_t CNTA15;
    uint32_t RESERVED0[16];
} stc_tmr0_cntar_bit_t;

typedef struct
{
    __IO uint32_t CMPA0;
    __IO uint32_t CMPA1;
    __IO uint32_t CMPA2;
    __IO uint32_t CMPA3;
    __IO uint32_t CMPA4;
    __IO uint32_t CMPA5;
    __IO uint32_t CMPA6;
    __IO uint32_t CMPA7;
    __IO uint32_t CMPA8;
    __IO uint32_t CMPA9;
    __IO uint32_t CMPA10;
    __IO uint32_t CMPA11;
    __IO uint32_t CMPA12;
    __IO uint32_t CMPA13;
    __IO uint32_t CMPA14;
    __IO uint32_t CMPA15;
    uint32_t RESERVED0[16];
} stc_tmr0_cmpar_bit_t;

typedef struct
{
    __IO uint32_t CSTA;
    __IO uint32_t CAPMDA;
    __IO uint32_t INTENA;
    uint32_t RESERVED0[1];
    __IO uint32_t CKDIVA0;
    __IO uint32_t CKDIVA1;
    __IO uint32_t CKDIVA2;
    __IO uint32_t CKDIVA3;
    __IO uint32_t SYNSA;
    __IO uint32_t SYNCLKA;
    __IO uint32_t ASYNCLKA;
    uint32_t RESERVED1[1];
    __IO uint32_t HSTAA;
    __IO uint32_t HSTPA;
    __IO uint32_t HCLEA;
    __IO uint32_t HICPA;
    uint32_t RESERVED2[16];
} stc_tmr0_bconr_bit_t;

typedef struct
{
    __IO uint32_t CMFA;
    uint32_t RESERVED0[31];
} stc_tmr0_stflr_bit_t;

typedef struct
{
    __IO uint32_t CNT0;
    __IO uint32_t CNT1;
    __IO uint32_t CNT2;
    __IO uint32_t CNT3;
    __IO uint32_t CNT4;
    __IO uint32_t CNT5;
    __IO uint32_t CNT6;
    __IO uint32_t CNT7;
    __IO uint32_t CNT8;
    __IO uint32_t CNT9;
    __IO uint32_t CNT10;
    __IO uint32_t CNT11;
    __IO uint32_t CNT12;
    __IO uint32_t CNT13;
    __IO uint32_t CNT14;
    __IO uint32_t CNT15;
} stc_tmrb_cnter_bit_t;

typedef struct
{
    __IO uint32_t PER0;
    __IO uint32_t PER1;
    __IO uint32_t PER2;
    __IO uint32_t PER3;
    __IO uint32_t PER4;
    __IO uint32_t PER5;
    __IO uint32_t PER6;
    __IO uint32_t PER7;
    __IO uint32_t PER8;
    __IO uint32_t PER9;
    __IO uint32_t PER10;
    __IO uint32_t PER11;
    __IO uint32_t PER12;
    __IO uint32_t PER13;
    __IO uint32_t PER14;
    __IO uint32_t PER15;
} stc_tmrb_perar_bit_t;

typedef struct
{
    __IO uint32_t CMP0;
    __IO uint32_t CMP1;
    __IO uint32_t CMP2;
    __IO uint32_t CMP3;
    __IO uint32_t CMP4;
    __IO uint32_t CMP5;
    __IO uint32_t CMP6;
    __IO uint32_t CMP7;
    __IO uint32_t CMP8;
    __IO uint32_t CMP9;
    __IO uint32_t CMP10;
    __IO uint32_t CMP11;
    __IO uint32_t CMP12;
    __IO uint32_t CMP13;
    __IO uint32_t CMP14;
    __IO uint32_t CMP15;
} stc_tmrb_cmpar_bit_t;

typedef struct
{
    __IO uint32_t START;
    __IO uint32_t DIR;
    __IO uint32_t MODE;
    __IO uint32_t SYNST;
    __IO uint32_t CKDIV0;
    __IO uint32_t CKDIV1;
    __IO uint32_t CKDIV2;
    __IO uint32_t CKDIV3;
    __IO uint32_t OVSTP;
    uint32_t RESERVED0[3];
    __IO uint32_t INENOVF;
    __IO uint32_t INENUDF;
    __IO uint32_t OVFF;
    __IO uint32_t UDFF;
} stc_tmrb_bcstr_bit_t;

typedef struct
{
    __IO uint32_t HSTA0;
    __IO uint32_t HSTA1;
    __IO uint32_t HSTA2;
    uint32_t RESERVED0[1];
    __IO uint32_t HSTP0;
    __IO uint32_t HSTP1;
    __IO uint32_t HSTP2;
    uint32_t RESERVED1[1];
    __IO uint32_t HCLE0;
    __IO uint32_t HCLE1;
    __IO uint32_t HCLE2;
    uint32_t RESERVED2[1];
    __IO uint32_t HCLE3;
    __IO uint32_t HCLE4;
    uint32_t RESERVED3[2];
} stc_tmrb_hconr_bit_t;

typedef struct
{
    uint32_t RESERVED0[8];
    __IO uint32_t HCUP8;
    __IO uint32_t HCUP9;
    __IO uint32_t HCUP10;
    __IO uint32_t HCUP11;
    __IO uint32_t HCUP12;
    uint32_t RESERVED1[3];
} stc_tmrb_hcupr_bit_t;

typedef struct
{
    uint32_t RESERVED0[8];
    __IO uint32_t HCDO8;
    __IO uint32_t HCDO9;
    __IO uint32_t HCDO10;
    __IO uint32_t HCDO11;
    __IO uint32_t HCDO12;
    uint32_t RESERVED1[3];
} stc_tmrb_hcdor_bit_t;

typedef struct
{
    __IO uint32_t ITEN1;
    uint32_t RESERVED0[15];
} stc_tmrb_iconr_bit_t;

typedef struct
{
    __IO uint32_t ETEN1;
    uint32_t RESERVED0[15];
} stc_tmrb_econr_bit_t;

typedef struct
{
    __IO uint32_t CMPF1;
    uint32_t RESERVED0[15];
} stc_tmrb_stflr_bit_t;

typedef struct
{
    __IO uint32_t CAPMDA;
    uint32_t RESERVED0[3];
    __IO uint32_t HICP0;
    __IO uint32_t HICP1;
    __IO uint32_t HICP2;
    uint32_t RESERVED1[5];
    __IO uint32_t NOFIENCP;
    __IO uint32_t NOFICKCP0;
    __IO uint32_t NOFICKCP1;
    uint32_t RESERVED2[1];
} stc_tmrb_cconr_bit_t;

typedef struct
{
    __IO uint32_t STAC0;
    __IO uint32_t STAC1;
    __IO uint32_t STPC0;
    __IO uint32_t STPC1;
    __IO uint32_t CMPC0;
    __IO uint32_t CMPC1;
    __IO uint32_t PERC0;
    __IO uint32_t PERC1;
    __IO uint32_t FORC0;
    __IO uint32_t FORC1;
    uint32_t RESERVED0[2];
    __IO uint32_t OUTEN;
    uint32_t RESERVED1[3];
} stc_tmrb_pconr_bit_t;

typedef struct
{
    __IO uint32_t PE;
    __IO uint32_t FE;
    uint32_t RESERVED0[1];
    __IO uint32_t ORE;
    uint32_t RESERVED1[1];
    __IO uint32_t RXNE;
    __IO uint32_t TC;
    __IO uint32_t TXE;
    uint32_t RESERVED2[8];
    __IO uint32_t MPB;
    uint32_t RESERVED3[15];
} stc_usart_sr_bit_t;

typedef struct
{
    __IO uint32_t TDR0;
    __IO uint32_t TDR1;
    __IO uint32_t TDR2;
    __IO uint32_t TDR3;
    __IO uint32_t TDR4;
    __IO uint32_t TDR5;
    __IO uint32_t TDR6;
    __IO uint32_t TDR7;
    __IO uint32_t TDR8;
    __IO uint32_t MPID;
    uint32_t RESERVED0[6];
    __IO uint32_t RDR0;
    __IO uint32_t RDR1;
    __IO uint32_t RDR2;
    __IO uint32_t RDR3;
    __IO uint32_t RDR4;
    __IO uint32_t RDR5;
    __IO uint32_t RDR6;
    __IO uint32_t RDR7;
    __IO uint32_t RDR8;
    uint32_t RESERVED1[7];
} stc_usart_dr_bit_t;

typedef struct
{
    uint32_t RESERVED0[8];
    __IO uint32_t DIV_INTEGER0;
    __IO uint32_t DIV_INTEGER1;
    __IO uint32_t DIV_INTEGER2;
    __IO uint32_t DIV_INTEGER3;
    __IO uint32_t DIV_INTEGER4;
    __IO uint32_t DIV_INTEGER5;
    __IO uint32_t DIV_INTEGER6;
    __IO uint32_t DIV_INTEGER7;
    uint32_t RESERVED1[16];
} stc_usart_brr_bit_t;

typedef struct
{
    uint32_t RESERVED0[2];
    __IO uint32_t RE;
    __IO uint32_t TE;
    __IO uint32_t SLME;
    __IO uint32_t RIE;
    __IO uint32_t TCIE;
    __IO uint32_t TXEIE;
    uint32_t RESERVED1[1];
    __IO uint32_t PS;
    __IO uint32_t PCE;
    uint32_t RESERVED2[1];
    __IO uint32_t M;
    uint32_t RESERVED3[2];
    __IO uint32_t OVER8;
    __IO uint32_t CPE;
    __IO uint32_t CFE;
    uint32_t RESERVED4[1];
    __IO uint32_t CORE;
    uint32_t RESERVED5[4];
    __IO uint32_t MS;
    uint32_t RESERVED6[3];
    __IO uint32_t ML;
    uint32_t RESERVED7[1];
    __IO uint32_t NFE;
    __IO uint32_t SBS;
} stc_usart_cr1_bit_t;

typedef struct
{
    __IO uint32_t MPE;
    uint32_t RESERVED0[10];
    __IO uint32_t CLKC0;
    __IO uint32_t CLKC1;
    __IO uint32_t STOP;
    __IO uint32_t LINEN;
    uint32_t RESERVED1[17];
} stc_usart_cr2_bit_t;

typedef struct
{
    uint32_t RESERVED0[3];
    __IO uint32_t HDSEL;
    uint32_t RESERVED1[5];
    __IO uint32_t CTSE;
    uint32_t RESERVED2[22];
} stc_usart_cr3_bit_t;

typedef struct
{
    __IO uint32_t PSC0;
    __IO uint32_t PSC1;
    uint32_t RESERVED0[30];
} stc_usart_pr_bit_t;


typedef struct
{
    stc_adc_str_bit_t                        STR_b;
    uint32_t                                 RESERVED0[8];
    stc_adc_cr0_bit_t                        CR0_b;
    stc_adc_cr1_bit_t                        CR1_b;
    uint32_t                                 RESERVED1[32];
    stc_adc_trgsr_bit_t                      TRGSR_b;
    stc_adc_chselra0_bit_t                   CHSELRA0_b;
    uint32_t                                 RESERVED2[16];
    stc_adc_chselrb0_bit_t                   CHSELRB0_b;
    uint32_t                                 RESERVED3[48];
    stc_adc_exchselr_bit_t                   EXCHSELR_b;
    uint32_t                                 RESERVED4[56];
    stc_adc_sstr_bit_t                       SSTR_b;
    uint32_t                                 RESERVED5[280];
    stc_adc_isr_bit_t                        ISR_b;
    stc_adc_icr_bit_t                        ICR_b;
    stc_adc_isclrr_bit_t                     ISCLRR_b;
    uint32_t                                 RESERVED6[72];
    stc_adc_dr0_bit_t                        DR0_b;
    stc_adc_dr1_bit_t                        DR1_b;
    stc_adc_dr2_bit_t                        DR2_b;
    stc_adc_dr3_bit_t                        DR3_b;
    stc_adc_dr4_bit_t                        DR4_b;
    stc_adc_dr5_bit_t                        DR5_b;
    stc_adc_dr6_bit_t                        DR6_b;
    stc_adc_dr7_bit_t                        DR7_b;
    stc_adc_dr8_bit_t                        DR8_b;
    stc_adc_dr9_bit_t                        DR9_b;
    stc_adc_dr10_bit_t                       DR10_b;
    stc_adc_dr11_bit_t                       DR11_b;
    uint32_t                                 RESERVED7[448];
    stc_adc_awdcr_bit_t                      AWDCR_b;
    stc_adc_awdsr_bit_t                      AWDSR_b;
    stc_adc_awdsclrr_bit_t                   AWDSCLRR_b;
    stc_adc_awd0dr0_bit_t                    AWD0DR0_b;
    stc_adc_awd0dr1_bit_t                    AWD0DR1_b;
    stc_adc_awd0chsr_bit_t                   AWD0CHSR_b;
    uint32_t                                 RESERVED8[24];
    stc_adc_awd1dr0_bit_t                    AWD1DR0_b;
    stc_adc_awd1dr1_bit_t                    AWD1DR1_b;
    stc_adc_awd1chsr_bit_t                   AWD1CHSR_b;
} bM0P_ADC_TypeDef;

typedef struct
{
    stc_aos_intc_strgcr_bit_t                INTC_STRGCR_b;
    uint32_t                                 RESERVED0[224];
    stc_aos_tmr0_htssr_bit_t                 TMR0_HTSSR_b;
    uint32_t                                 RESERVED1[352];
    stc_aos_tmrb_htssr_bit_t                 TMRB_HTSSR_b;
    uint32_t                                 RESERVED2[96];
    stc_aos_adc_itrgselr0_bit_t              ADC_ITRGSELR0_b;
    stc_aos_adc_itrgselr1_bit_t              ADC_ITRGSELR1_b;
} bM0P_AOS_TypeDef;

typedef struct
{
    stc_cmu_pericksel_bit_t                  PERICKSEL_b;
    uint32_t                                 RESERVED0[24];
    stc_cmu_xtalstdsr_bit_t                  XTALSTDSR_b;
    uint32_t                                 RESERVED1[24];
    stc_cmu_sckdivr_bit_t                    SCKDIVR_b;
    uint32_t                                 RESERVED2[24];
    stc_cmu_ckswr_bit_t                      CKSWR_b;
    uint32_t                                 RESERVED3[24];
    stc_cmu_xtalcr_bit_t                     XTALCR_b;
    uint32_t                                 RESERVED4[24];
    stc_cmu_xtalcfgr_bit_t                   XTALCFGR_b;
    stc_cmu_xtalstbcr_bit_t                  XTALSTBCR_b;
    uint32_t                                 RESERVED5[16];
    stc_cmu_hrccr_bit_t                      HRCCR_b;
    uint32_t                                 RESERVED6[56];
    stc_cmu_oscstbsr_bit_t                   OSCSTBSR_b;
    uint32_t                                 RESERVED7[24];
    stc_cmu_mco1cfgr_bit_t                   MCO1CFGR_b;
    uint32_t                                 RESERVED8[24];
    stc_cmu_xtalstdcr_bit_t                  XTALSTDCR_b;
    uint32_t                                 RESERVED9[56];
    stc_cmu_fcg_bit_t                        FCG_b;
    stc_cmu_xtal32cr_bit_t                   XTAL32CR_b;
    uint32_t                                 RESERVED10[24];
    stc_cmu_xtal32cfgr_bit_t                 XTAL32CFGR_b;
    stc_cmu_xtal32nfr_bit_t                  XTAL32NFR_b;
    uint32_t                                 RESERVED11[16];
    stc_cmu_lrccr_bit_t                      LRCCR_b;
} bM0P_CMU_TypeDef;

typedef struct
{
    stc_crc_cr_bit_t                         CR_b;
    stc_crc_reslt_bit_t                      RESLT_b;
    uint32_t                                 RESERVED0[960];
    stc_crc_dat0_bit_t                       DAT0_b;
    stc_crc_dat1_bit_t                       DAT1_b;
    stc_crc_dat2_bit_t                       DAT2_b;
    stc_crc_dat3_bit_t                       DAT3_b;
    stc_crc_dat4_bit_t                       DAT4_b;
    stc_crc_dat5_bit_t                       DAT5_b;
    stc_crc_dat6_bit_t                       DAT6_b;
    stc_crc_dat7_bit_t                       DAT7_b;
    stc_crc_dat8_bit_t                       DAT8_b;
    stc_crc_dat9_bit_t                       DAT9_b;
    stc_crc_dat10_bit_t                      DAT10_b;
    stc_crc_dat11_bit_t                      DAT11_b;
    stc_crc_dat12_bit_t                      DAT12_b;
    stc_crc_dat13_bit_t                      DAT13_b;
    stc_crc_dat14_bit_t                      DAT14_b;
    stc_crc_dat15_bit_t                      DAT15_b;
    stc_crc_dat16_bit_t                      DAT16_b;
    stc_crc_dat17_bit_t                      DAT17_b;
    stc_crc_dat18_bit_t                      DAT18_b;
    stc_crc_dat19_bit_t                      DAT19_b;
    stc_crc_dat20_bit_t                      DAT20_b;
    stc_crc_dat21_bit_t                      DAT21_b;
    stc_crc_dat22_bit_t                      DAT22_b;
    stc_crc_dat23_bit_t                      DAT23_b;
    stc_crc_dat24_bit_t                      DAT24_b;
    stc_crc_dat25_bit_t                      DAT25_b;
    stc_crc_dat26_bit_t                      DAT26_b;
    stc_crc_dat27_bit_t                      DAT27_b;
    stc_crc_dat28_bit_t                      DAT28_b;
    stc_crc_dat29_bit_t                      DAT29_b;
    stc_crc_dat30_bit_t                      DAT30_b;
    stc_crc_dat31_bit_t                      DAT31_b;
} bM0P_CRC_TypeDef;

typedef struct
{
    stc_ctc_cr1_bit_t                        CR1_b;
    stc_ctc_cr2_bit_t                        CR2_b;
    stc_ctc_str_bit_t                        STR_b;
} bM0P_CTC_TypeDef;

typedef struct
{
    stc_dbgc_mcudbgstat_bit_t                MCUDBGSTAT_b;
    stc_dbgc_mcustpctl_bit_t                 MCUSTPCTL_b;
} bM0P_DBGC_TypeDef;

typedef struct
{
    stc_efm_faprt_bit_t                      FAPRT_b;
    stc_efm_fstp_bit_t                       FSTP_b;
    stc_efm_frmc_bit_t                       FRMC_b;
    stc_efm_fwmc_bit_t                       FWMC_b;
    stc_efm_fsr_bit_t                        FSR_b;
    stc_efm_fsclr_bit_t                      FSCLR_b;
    stc_efm_fite_bit_t                       FITE_b;
    uint32_t                                 RESERVED0[32];
    stc_efm_fpmtsw_bit_t                     FPMTSW_b;
    stc_efm_fpmtew_bit_t                     FPMTEW_b;
    uint32_t                                 RESERVED1[320];
    stc_efm_uqid0_bit_t                      UQID0_b;
    stc_efm_uqid1_bit_t                      UQID1_b;
    stc_efm_uqid2_bit_t                      UQID2_b;
    uint32_t                                 RESERVED2[4400];
    stc_efm_hrccfgr_bit_t                    HRCCFGR_b;
    uint32_t                                 RESERVED3[8];
    stc_efm_lvdicgcr_bit_t                   LVDICGCR_b;
} bM0P_EFM_TypeDef;

typedef struct
{
    stc_i2c_cr1_bit_t                        CR1_b;
    stc_i2c_cr2_bit_t                        CR2_b;
    uint32_t                                 RESERVED0[64];
    stc_i2c_slr0_bit_t                       SLR0_b;
    stc_i2c_slr1_bit_t                       SLR1_b;
    uint32_t                                 RESERVED1[32];
    stc_i2c_sr_bit_t                         SR_b;
    stc_i2c_clr_bit_t                        CLR_b;
    stc_i2c_dtr_bit_t                        DTR_b;
    uint32_t                                 RESERVED2[24];
    stc_i2c_drr_bit_t                        DRR_b;
    uint32_t                                 RESERVED3[24];
    stc_i2c_ccr_bit_t                        CCR_b;
    stc_i2c_fltr_bit_t                       FLTR_b;
} bM0P_I2C_TypeDef;

typedef struct
{
    stc_icg_icg0_bit_t                       ICG0_b;
    stc_icg_icg1_bit_t                       ICG1_b;
    stc_icg_icg2_bit_t                       ICG2_b;
    stc_icg_icg3_bit_t                       ICG3_b;
    stc_icg_icg4_bit_t                       ICG4_b;
    stc_icg_icg5_bit_t                       ICG5_b;
    stc_icg_icg6_bit_t                       ICG6_b;
} bM0P_ICG_TypeDef;

typedef struct
{
    stc_intc_nmicr_bit_t                     NMICR_b;
    stc_intc_nmier_bit_t                     NMIER_b;
    stc_intc_nmifr_bit_t                     NMIFR_b;
    stc_intc_nmiclr_bit_t                    NMICLR_b;
    uint32_t                                 RESERVED0[128];
    stc_intc_evter_bit_t                     EVTER_b;
    stc_intc_ekeycr_bit_t                    EKEYCR_b;
    uint32_t                                 RESERVED1[160];
    stc_intc_fprcr_bit_t                     FPRCR_b;
    stc_intc_eirqcr_bit_t                    EIRQCR0_b;
    stc_intc_eirqcr_bit_t                    EIRQCR1_b;
    stc_intc_eirqcr_bit_t                    EIRQCR2_b;
    stc_intc_eirqcr_bit_t                    EIRQCR3_b;
    stc_intc_eirqcr_bit_t                    EIRQCR4_b;
    stc_intc_eirqcr_bit_t                    EIRQCR5_b;
    stc_intc_eirqcr_bit_t                    EIRQCR6_b;
    stc_intc_eirqcr_bit_t                    EIRQCR7_b;
    stc_intc_eirqcr_bit_t                    EIRQCR8_b;
    stc_intc_eirqcr_bit_t                    EIRQCR9_b;
    uint32_t                                 RESERVED2[64];
    stc_intc_wupenr_bit_t                    WUPENR_b;
    stc_intc_eirqfr_bit_t                    EIRQFR_b;
    stc_intc_eirqclr_bit_t                   EIRQCLR_b;
    uint32_t                                 RESERVED3[288];
    stc_intc_iselar_bit_t                    ISELAR8_b;
    stc_intc_iselar_bit_t                    ISELAR9_b;
    stc_intc_iselar_bit_t                    ISELAR10_b;
    stc_intc_iselar_bit_t                    ISELAR11_b;
    stc_intc_iselar_bit_t                    ISELAR12_b;
    stc_intc_iselar_bit_t                    ISELAR13_b;
    stc_intc_iselar_bit_t                    ISELAR14_b;
    stc_intc_iselar_bit_t                    ISELAR15_b;
    stc_intc_iselar_bit_t                    ISELAR16_b;
    stc_intc_iselar_bit_t                    ISELAR17_b;
    stc_intc_iselar_bit_t                    ISELAR18_b;
    stc_intc_iselar_bit_t                    ISELAR19_b;
    stc_intc_iselar_bit_t                    ISELAR20_b;
    stc_intc_iselar_bit_t                    ISELAR21_b;
    stc_intc_iselar_bit_t                    ISELAR22_b;
    stc_intc_iselar_bit_t                    ISELAR23_b;
    stc_intc_iselbr_bit_t                    ISELBR24_b;
    stc_intc_iselbr_bit_t                    ISELBR25_b;
    stc_intc_iselbr_bit_t                    ISELBR26_b;
    stc_intc_iselbr_bit_t                    ISELBR27_b;
    stc_intc_iselbr_bit_t                    ISELBR28_b;
    stc_intc_iselbr_bit_t                    ISELBR29_b;
    stc_intc_iselbr_bit_t                    ISELBR30_b;
    stc_intc_iselbr_bit_t                    ISELBR31_b;
} bM0P_INTC_TypeDef;

typedef struct
{
    stc_port_pidr0_bit_t                     PIDR0_b;
    stc_port_pidr1_bit_t                     PIDR1_b;
    stc_port_pidr2_bit_t                     PIDR2_b;
    stc_port_pidr3_bit_t                     PIDR3_b;
    stc_port_pidr4_bit_t                     PIDR4_b;
    stc_port_pidr5_bit_t                     PIDR5_b;
    stc_port_pidr6_bit_t                     PIDR6_b;
    stc_port_pidr7_bit_t                     PIDR7_b;
    uint32_t                                 RESERVED0[32];
    stc_port_pidr12_bit_t                    PIDR12_b;
    stc_port_pidr13_bit_t                    PIDR13_b;
    stc_port_pidr14_bit_t                    PIDR14_b;
    uint32_t                                 RESERVED1[8];
    stc_port_podr0_bit_t                     PODR0_b;
    stc_port_podr1_bit_t                     PODR1_b;
    stc_port_podr2_bit_t                     PODR2_b;
    stc_port_podr3_bit_t                     PODR3_b;
    stc_port_podr4_bit_t                     PODR4_b;
    stc_port_podr5_bit_t                     PODR5_b;
    stc_port_podr6_bit_t                     PODR6_b;
    stc_port_podr7_bit_t                     PODR7_b;
    uint32_t                                 RESERVED2[32];
    stc_port_podr12_bit_t                    PODR12_b;
    stc_port_podr13_bit_t                    PODR13_b;
    stc_port_podr14_bit_t                    PODR14_b;
    uint32_t                                 RESERVED3[8];
    stc_port_poer0_bit_t                     POER0_b;
    stc_port_poer1_bit_t                     POER1_b;
    stc_port_poer2_bit_t                     POER2_b;
    stc_port_poer3_bit_t                     POER3_b;
    stc_port_poer4_bit_t                     POER4_b;
    stc_port_poer5_bit_t                     POER5_b;
    stc_port_poer6_bit_t                     POER6_b;
    stc_port_poer7_bit_t                     POER7_b;
    uint32_t                                 RESERVED4[32];
    stc_port_poer12_bit_t                    POER12_b;
    stc_port_poer13_bit_t                    POER13_b;
    stc_port_poer14_bit_t                    POER14_b;
    uint32_t                                 RESERVED5[8];
    stc_port_posr0_bit_t                     POSR0_b;
    stc_port_posr1_bit_t                     POSR1_b;
    stc_port_posr2_bit_t                     POSR2_b;
    stc_port_posr3_bit_t                     POSR3_b;
    stc_port_posr4_bit_t                     POSR4_b;
    stc_port_posr5_bit_t                     POSR5_b;
    stc_port_posr6_bit_t                     POSR6_b;
    stc_port_posr7_bit_t                     POSR7_b;
    uint32_t                                 RESERVED6[32];
    stc_port_posr12_bit_t                    POSR12_b;
    stc_port_posr13_bit_t                    POSR13_b;
    stc_port_posr14_bit_t                    POSR14_b;
    uint32_t                                 RESERVED7[8];
    stc_port_porr0_bit_t                     PORR0_b;
    stc_port_porr1_bit_t                     PORR1_b;
    stc_port_porr2_bit_t                     PORR2_b;
    stc_port_porr3_bit_t                     PORR3_b;
    stc_port_porr4_bit_t                     PORR4_b;
    stc_port_porr5_bit_t                     PORR5_b;
    stc_port_porr6_bit_t                     PORR6_b;
    stc_port_porr7_bit_t                     PORR7_b;
    uint32_t                                 RESERVED8[32];
    stc_port_porr12_bit_t                    PORR12_b;
    stc_port_porr13_bit_t                    PORR13_b;
    stc_port_porr14_bit_t                    PORR14_b;
    uint32_t                                 RESERVED9[8];
    stc_port_potr0_bit_t                     POTR0_b;
    stc_port_potr1_bit_t                     POTR1_b;
    stc_port_potr2_bit_t                     POTR2_b;
    stc_port_potr3_bit_t                     POTR3_b;
    stc_port_potr4_bit_t                     POTR4_b;
    stc_port_potr5_bit_t                     POTR5_b;
    stc_port_potr6_bit_t                     POTR6_b;
    stc_port_potr7_bit_t                     POTR7_b;
    uint32_t                                 RESERVED10[32];
    stc_port_potr12_bit_t                    POTR12_b;
    stc_port_potr13_bit_t                    POTR13_b;
    stc_port_potr14_bit_t                    POTR14_b;
    uint32_t                                 RESERVED11[9480];
    stc_port_pspcr_bit_t                     PSPCR_b;
    uint32_t                                 RESERVED12[16];
    stc_port_pccr_bit_t                      PCCR_b;
    stc_port_pinaer_bit_t                    PINAER_b;
    stc_port_pwpr_bit_t                      PWPR_b;
} bM0P_PORT_TypeDef;

typedef struct
{
    stc_pwc_stpmcr_bit_t                     STPMCR_b;
    uint32_t                                 RESERVED0[24];
    stc_pwc_pwrc_bit_t                       PWRC_b;
    uint32_t                                 RESERVED1[56];
    stc_pwc_ramcr_bit_t                      RAMCR_b;
    uint32_t                                 RESERVED2[24];
    stc_pwc_lvdcsr_bit_t                     LVDCSR_b;
    uint32_t                                 RESERVED3[120];
    stc_pwc_fprc_bit_t                       FPRC_b;
    uint32_t                                 RESERVED4[240];
    stc_pwc_dbgc_bit_t                       DBGC_b;
} bM0P_PWC_TypeDef;

typedef struct
{
    stc_rmu_rstf0_bit_t                      RSTF0_b;
} bM0P_RMU_TypeDef;

typedef struct
{
    stc_rtc_cr0_bit_t                        CR0_b;
    uint32_t                                 RESERVED0[24];
    stc_rtc_cr1_bit_t                        CR1_b;
    uint32_t                                 RESERVED1[24];
    stc_rtc_cr2_bit_t                        CR2_b;
    uint32_t                                 RESERVED2[24];
    stc_rtc_cr3_bit_t                        CR3_b;
    uint32_t                                 RESERVED3[24];
    stc_rtc_sec_bit_t                        SEC_b;
    uint32_t                                 RESERVED4[24];
    stc_rtc_min_bit_t                        MIN_b;
    uint32_t                                 RESERVED5[24];
    stc_rtc_hour_bit_t                       HOUR_b;
    uint32_t                                 RESERVED6[24];
    stc_rtc_week_bit_t                       WEEK_b;
    uint32_t                                 RESERVED7[24];
    stc_rtc_day_bit_t                        DAY_b;
    uint32_t                                 RESERVED8[24];
    stc_rtc_mon_bit_t                        MON_b;
    uint32_t                                 RESERVED9[24];
    stc_rtc_year_bit_t                       YEAR_b;
    uint32_t                                 RESERVED10[24];
    stc_rtc_almmin_bit_t                     ALMMIN_b;
    uint32_t                                 RESERVED11[24];
    stc_rtc_almhour_bit_t                    ALMHOUR_b;
    uint32_t                                 RESERVED12[24];
    stc_rtc_almweek_bit_t                    ALMWEEK_b;
    uint32_t                                 RESERVED13[24];
    stc_rtc_errcrh_bit_t                     ERRCRH_b;
    uint32_t                                 RESERVED14[24];
    stc_rtc_errcrl_bit_t                     ERRCRL_b;
} bM0P_RTC_TypeDef;

typedef struct
{
    stc_spi_dr_bit_t                         DR_b;
    stc_spi_cr1_bit_t                        CR1_b;
    uint32_t                                 RESERVED0[32];
    stc_spi_cfg1_bit_t                       CFG1_b;
    uint32_t                                 RESERVED1[32];
    stc_spi_sr_bit_t                         SR_b;
    stc_spi_cfg2_bit_t                       CFG2_b;
} bM0P_SPI_TypeDef;

typedef struct
{
    stc_swdt_cr_bit_t                        CR_b;
    stc_swdt_sr_bit_t                        SR_b;
    stc_swdt_rr_bit_t                        RR_b;
} bM0P_SWDT_TypeDef;

typedef struct
{
    stc_tmr0_cntar_bit_t                     CNTAR_b;
    uint32_t                                 RESERVED0[32];
    stc_tmr0_cmpar_bit_t                     CMPAR_b;
    uint32_t                                 RESERVED1[32];
    stc_tmr0_bconr_bit_t                     BCONR_b;
    stc_tmr0_stflr_bit_t                     STFLR_b;
} bM0P_TMR0_TypeDef;

typedef struct
{
    stc_tmrb_cnter_bit_t                     CNTER_b;
    uint32_t                                 RESERVED0[16];
    stc_tmrb_perar_bit_t                     PERAR_b;
    uint32_t                                 RESERVED1[464];
    stc_tmrb_cmpar_bit_t                     CMPAR_b;
    uint32_t                                 RESERVED2[496];
    stc_tmrb_bcstr_bit_t                     BCSTR_b;
    uint32_t                                 RESERVED3[16];
    stc_tmrb_hconr_bit_t                     HCONR_b;
    uint32_t                                 RESERVED4[16];
    stc_tmrb_hcupr_bit_t                     HCUPR_b;
    uint32_t                                 RESERVED5[16];
    stc_tmrb_hcdor_bit_t                     HCDOR_b;
    uint32_t                                 RESERVED6[16];
    stc_tmrb_iconr_bit_t                     ICONR_b;
    uint32_t                                 RESERVED7[16];
    stc_tmrb_econr_bit_t                     ECONR_b;
    uint32_t                                 RESERVED8[48];
    stc_tmrb_stflr_bit_t                     STFLR_b;
    uint32_t                                 RESERVED9[784];
    stc_tmrb_cconr_bit_t                     CCONR_b;
    uint32_t                                 RESERVED10[496];
    stc_tmrb_pconr_bit_t                     PCONR_b;
} bM0P_TMRB_TypeDef;

typedef struct
{
    stc_usart_sr_bit_t                       SR_b;
    stc_usart_dr_bit_t                       DR_b;
    stc_usart_brr_bit_t                      BRR_b;
    stc_usart_cr1_bit_t                      CR1_b;
    stc_usart_cr2_bit_t                      CR2_b;
    stc_usart_cr3_bit_t                      CR3_b;
    stc_usart_pr_bit_t                       PR_b;
} bM0P_USART_TypeDef;



/******************************************************************************/
/*      Device Specific Peripheral bit_band declaration & memory map          */
/******************************************************************************/

#define bM0P_ADC                             ((bM0P_ADC_TypeDef *)0x42170000UL)
#define bM0P_AOS                             ((bM0P_AOS_TypeDef *)0x42018000UL)
#define bM0P_CMU                             ((bM0P_CMU_TypeDef *)0x42288000UL)
#define bM0P_CRC                             ((bM0P_CRC_TypeDef *)0x422A8000UL)
#define bM0P_CTC                             ((bM0P_CTC_TypeDef *)0x42000000UL)
#define bM0P_DBGC                            ((bM0P_DBGC_TypeDef *)0x422A0000UL)
#define bM0P_EFM                             ((bM0P_EFM_TypeDef *)0x42010000UL)
#define bM0P_I2C                             ((bM0P_I2C_TypeDef *)0x42090000UL)
#define bM0P_INTC                            ((bM0P_INTC_TypeDef *)0x42220000UL)
#define bM0P_PORT                            ((bM0P_PORT_TypeDef *)0x42270000UL)
#define bM0P_PWC                             ((bM0P_PWC_TypeDef *)0x42280000UL)
#define bM0P_RMU                             ((bM0P_RMU_TypeDef *)0x42282000UL)
#define bM0P_RTC                             ((bM0P_RTC_TypeDef *)0x421A8000UL)
#define bM0P_SPI                             ((bM0P_SPI_TypeDef *)0x42070000UL)
#define bM0P_SWDT                            ((bM0P_SWDT_TypeDef *)0x42198000UL)
#define bM0P_TMR0                            ((bM0P_TMR0_TypeDef *)0x420B0000UL)
#define bM0P_TMRB1                           ((bM0P_TMRB_TypeDef *)0x420F0000UL)
#define bM0P_TMRB2                           ((bM0P_TMRB_TypeDef *)0x420F8000UL)
#define bM0P_TMRB3                           ((bM0P_TMRB_TypeDef *)0x42100000UL)
#define bM0P_TMRB4                           ((bM0P_TMRB_TypeDef *)0x42108000UL)
#define bM0P_TMRB5                           ((bM0P_TMRB_TypeDef *)0x42110000UL)
#define bM0P_TMRB6                           ((bM0P_TMRB_TypeDef *)0x42118000UL)
#define bM0P_TMRB7                           ((bM0P_TMRB_TypeDef *)0x42120000UL)
#define bM0P_TMRB8                           ((bM0P_TMRB_TypeDef *)0x42128000UL)
#define bM0P_USART1                          ((bM0P_USART_TypeDef *)0x42030000UL)
#define bM0P_USART2                          ((bM0P_USART_TypeDef *)0x42038000UL)
#define bM0P_USART3                          ((bM0P_USART_TypeDef *)0x42040000UL)
#define bM0P_USART4                          ((bM0P_USART_TypeDef *)0x42048000UL)


#ifdef __cplusplus
}
#endif

#endif /* __HC32F120_H__ */

