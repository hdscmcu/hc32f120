/**
 *******************************************************************************
 * @file  hc32f120_efm.h
 * @brief This file contains all the functions prototypes of the EFM driver
 *        library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-05-06       Chengy          First version
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
#ifndef __HC32F120_EFM_H__
#define __HC32F120_EFM_H__

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
 * @addtogroup DDL_EFM
 * @{
 */

#if (DDL_EFM_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup EFM_Global_Types EFM Global Types
 * @{
 */

/**
 * @brief EFM windows protect address definition
 */
typedef struct
{
    uint32_t            u32StartAddr;      /*!< The protect start address.     */
    uint32_t            u32EndAddr;        /*!< The protect end address.       */
} stc_efm_win_protect_addr_t;

/**
 * @brief EFM configure structure
 */
typedef struct
{
    uint32_t            u32Latency;     /*!< Specifies the efm latency.
                                            This parameter can be a value of @ref EFM_Latency.              */

    uint32_t            u32InsCache;    /*!< Specifies the instruction cache on or off.
                                            This parameter can be a value of @ref EFM_InsCache_State.       */

    uint32_t            u32BusState;    /*!< Specifies the bus state busy or release while program & erase.
                                            This parameter can be a value of @ref EFM_Bus_State.            */
} stc_efm_cfg_t;

/**
 * @brief EFM unique ID definition
 */
typedef struct
{
    uint32_t            u32UniqueID0;      /*!< unique ID 0.       */
    uint32_t            u32UniqueID1;      /*!< unique ID 1.       */
    uint32_t            u32UniqueID2;      /*!< unique ID 2.       */
} stc_efm_unique_id_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup EFM_Global_Macros EFM Global Macros
 * @{
 */
#define EFM_TIMEOUT                0x1000U

/**
 * @defgroup EFM_Address EFM address area
 * @{
 */
#define EFM_START_ADDR              0x00000000U
#define EFM_END_ADDR                0X0000FFFFU
/**
 * @}
 */

/**
 * @defgroup EFM_Sector_Address EFM Sector Address
 * @{
 */
#define EFM_SECTOR0_ADRR            0x00000000U
#define EFM_SECTOR1_ADRR            0X00000200U
#define EFM_SECTOR2_ADRR            0x00000400U
#define EFM_SECTOR3_ADRR            0X00000600U
#define EFM_SECTOR4_ADRR            0x00000800U
#define EFM_SECTOR5_ADRR            0X00000A00U
#define EFM_SECTOR6_ADRR            0x00000C00U
#define EFM_SECTOR7_ADRR            0x00000E00U
#define EFM_SECTOR8_ADRR            0X00001000U
#define EFM_SECTOR9_ADRR            0x00001200U
#define EFM_SECTOR10_ADRR           0X00001400U
#define EFM_SECTOR11_ADRR           0x00001600U
#define EFM_SECTOR12_ADRR           0X00001800U
#define EFM_SECTOR13_ADRR           0x00001A00U
#define EFM_SECTOR14_ADRR           0X00001C00U
#define EFM_SECTOR15_ADRR           0x00001E00U
#define EFM_SECTOR16_ADRR           0X00002000U
#define EFM_SECTOR17_ADRR           0x00002200U
#define EFM_SECTOR18_ADRR           0X00002400U
#define EFM_SECTOR19_ADRR           0X00002600U
#define EFM_SECTOR20_ADRR           0x00002800U
#define EFM_SECTOR21_ADRR           0x00002A00U
#define EFM_SECTOR22_ADRR           0X00002C00U
#define EFM_SECTOR23_ADRR           0x00002E00U
#define EFM_SECTOR24_ADRR           0X00003000U
#define EFM_SECTOR25_ADRR           0x00003200U
#define EFM_SECTOR26_ADRR           0X00003400U
#define EFM_SECTOR27_ADRR           0x00003600U
#define EFM_SECTOR28_ADRR           0X00003800U
#define EFM_SECTOR29_ADRR           0X00003A00U
#define EFM_SECTOR30_ADRR           0x00003C00U
#define EFM_SECTOR31_ADRR           0x00003E00U
#define EFM_SECTOR32_ADRR           0X00004000U
#define EFM_SECTOR33_ADRR           0x00004200U
#define EFM_SECTOR34_ADRR           0X00004400U
#define EFM_SECTOR35_ADRR           0x00004600U
#define EFM_SECTOR36_ADRR           0X00004800U
#define EFM_SECTOR37_ADRR           0x00004A00U
#define EFM_SECTOR38_ADRR           0X00004C00U
#define EFM_SECTOR39_ADRR           0X00004E00U
#define EFM_SECTOR40_ADRR           0x00005000U
#define EFM_SECTOR41_ADRR           0x00005200U
#define EFM_SECTOR42_ADRR           0X00005400U
#define EFM_SECTOR43_ADRR           0x00005600U
#define EFM_SECTOR44_ADRR           0X00005800U
#define EFM_SECTOR45_ADRR           0x00005A00U
#define EFM_SECTOR46_ADRR           0X00005C00U
#define EFM_SECTOR47_ADRR           0x00005E00U
#define EFM_SECTOR48_ADRR           0X00006000U
#define EFM_SECTOR49_ADRR           0X00006200U
#define EFM_SECTOR50_ADRR           0x00006400U
#define EFM_SECTOR51_ADRR           0x00006600U
#define EFM_SECTOR52_ADRR           0X00006800U
#define EFM_SECTOR53_ADRR           0x00006A00U
#define EFM_SECTOR54_ADRR           0X00006C00U
#define EFM_SECTOR55_ADRR           0x00006E00U
#define EFM_SECTOR56_ADRR           0X00007000U
#define EFM_SECTOR57_ADRR           0x00007200U
#define EFM_SECTOR58_ADRR           0X00007400U
#define EFM_SECTOR59_ADRR           0X00007600U
#define EFM_SECTOR60_ADRR           0x00007800U
#define EFM_SECTOR61_ADRR           0x00007A00U
#define EFM_SECTOR62_ADRR           0X00007C00U
#define EFM_SECTOR63_ADRR           0x00007E00U
#define EFM_SECTOR64_ADRR           0X00008000U
#define EFM_SECTOR65_ADRR           0x00008200U
#define EFM_SECTOR66_ADRR           0X00008400U
#define EFM_SECTOR67_ADRR           0x00008600U
#define EFM_SECTOR68_ADRR           0X00008800U
#define EFM_SECTOR69_ADRR           0X00008A00U
#define EFM_SECTOR70_ADRR           0x00008C00U
#define EFM_SECTOR71_ADRR           0x00008E00U
#define EFM_SECTOR72_ADRR           0X00009000U
#define EFM_SECTOR73_ADRR           0x00009200U
#define EFM_SECTOR74_ADRR           0X00009400U
#define EFM_SECTOR75_ADRR           0x00009600U
#define EFM_SECTOR76_ADRR           0X00009800U
#define EFM_SECTOR77_ADRR           0x00009A00U
#define EFM_SECTOR78_ADRR           0X00009C00U
#define EFM_SECTOR79_ADRR           0X00009E00U
#define EFM_SECTOR80_ADRR           0x0000A000U
#define EFM_SECTOR81_ADRR           0x0000A200U
#define EFM_SECTOR82_ADRR           0X0000A400U
#define EFM_SECTOR83_ADRR           0x0000A600U
#define EFM_SECTOR84_ADRR           0X0000A800U
#define EFM_SECTOR85_ADRR           0x0000AA00U
#define EFM_SECTOR86_ADRR           0X0000AC00U
#define EFM_SECTOR87_ADRR           0x0000AE00U
#define EFM_SECTOR88_ADRR           0X0000B000U
#define EFM_SECTOR89_ADRR           0X0000B200U
#define EFM_SECTOR90_ADRR           0x0000B400U
#define EFM_SECTOR91_ADRR           0x0000B600U
#define EFM_SECTOR92_ADRR           0X0000B800U
#define EFM_SECTOR93_ADRR           0x0000BA00U
#define EFM_SECTOR94_ADRR           0X0000BC00U
#define EFM_SECTOR95_ADRR           0x0000BE00U
#define EFM_SECTOR96_ADRR           0X0000C000U
#define EFM_SECTOR97_ADRR           0x0000C200U
#define EFM_SECTOR98_ADRR           0X0000C400U
#define EFM_SECTOR99_ADRR           0X0000C600U
#define EFM_SECTOR100_ADRR          0x0000C800U
#define EFM_SECTOR101_ADRR          0x0000CA00U
#define EFM_SECTOR102_ADRR          0X0000CC00U
#define EFM_SECTOR103_ADRR          0x0000CE00U
#define EFM_SECTOR104_ADRR          0X0000D000U
#define EFM_SECTOR105_ADRR          0x0000D200U
#define EFM_SECTOR106_ADRR          0X0000D400U
#define EFM_SECTOR107_ADRR          0x0000D600U
#define EFM_SECTOR108_ADRR          0X0000D800U
#define EFM_SECTOR109_ADRR          0X0000DA00U
#define EFM_SECTOR110_ADRR          0x0000DC00U
#define EFM_SECTOR111_ADRR          0x0000DE00U
#define EFM_SECTOR112_ADRR          0X0000E000U
#define EFM_SECTOR113_ADRR          0x0000E200U
#define EFM_SECTOR114_ADRR          0X0000E400U
#define EFM_SECTOR115_ADRR          0x0000E600U
#define EFM_SECTOR116_ADRR          0X0000E800U
#define EFM_SECTOR117_ADRR          0x0000EA00U
#define EFM_SECTOR118_ADRR          0X0000EC00U
#define EFM_SECTOR119_ADRR          0X0000EE00U
#define EFM_SECTOR120_ADRR          0x0000F000U
#define EFM_SECTOR121_ADRR          0x0000F200U
#define EFM_SECTOR122_ADRR          0X0000F400U
#define EFM_SECTOR123_ADRR          0x0000F600U
#define EFM_SECTOR124_ADRR          0X0000F800U
#define EFM_SECTOR125_ADRR          0x0000FA00U
#define EFM_SECTOR126_ADRR          0X0000FC00U
#define EFM_SECTOR127_ADRR          0x0000FE00U
/**
 * @}
 */

/**
 * @defgroup EFM_State EFM State
 * @{
 */
#define EFM_ON                      0x00000000U
#define EFM_OFF                     EFM_FSTP_FSTP
/**
 * @}
 */

/**
 * @defgroup EFM_Latency EFM latency value
 * @{
 */
#define EFM_LATENCY_0               0x00000000U
#define EFM_LATENCY_1               0x00000001U
/**
 * @}
 */

/**
 * @defgroup EFM_InsCache_State EFM instruction cache state
 * @{
 */
#define EFM_INSCACHE_ON             EFM_FRMC_PREFETE
#define EFM_INSCACHE_OFF            0x00000000U
/**
 * @}
 */

/**
 * @defgroup EFM_Bus_State EFM Bus state while flash program or erase
 * @{
 */
#define EFM_BUS_BUSY                0x00000000U
#define EFM_BUS_RELEASE             EFM_FWMC_BUSHLDCTL
/**
 * @}
 */

/**
 * @defgroup EFM_Mode_definition EFM program or erase mode definition
 * @{
 */
#define EFM_MODE_PROGRAMSINGLE      0x00000010U         /*!< Program single at a specified address          */
#define EFM_MODE_PROGRAMREADBACK    0x00000020U         /*!< Program and read back at a specified address   */
#define EFM_MODE_PROGRAMSEQUENCE    0x00000030U         /*!< Program sequence at sequence address           */
#define EFM_MODE_ERASESECTOR        0x00000040U         /*!< Sector erase                                   */
#define EFM_MODE_ERASECHIP          0x00000050U         /*!< Chip erase                                     */
#define EFM_MODE_READONLY           0x00000000U         /*!< Read only                                      */
#define EFM_MODE_READONLY1          0x00000060U         /*!< Read only                                      */
#define EFM_MODE_READONLY2          0x00000070U         /*!< Read only                                      */
/**
 * @}
 */

/**
 * @defgroup EFM_Flag_definition EFM Flag definition
 * @{
 */
#define EFM_FLAG_PEWERR             EFM_FSR_PEWERR          /*!< EFM Programming/erase error flag.              */
#define EFM_FLAG_PEPRTERR           EFM_FSR_PEPRTERR        /*!< EFM Programming/erase protect area error flag. */
#define EFM_FLAG_PGMISMTCHERR       EFM_FSR_PGMISMTCH       /*!< EFM Programming  miss match error flag         */
#define EFM_FLAG_OPTEND             EFM_FSR_OPTEND          /*!< EFM End of Operation flag.                     */
#define EFM_FLAG_COLERR             EFM_FSR_RDCOLERR        /*!< EFM Read collide error flag.                   */
#define EFM_FLAG_RDY                EFM_FSR_RDY             /*!< EFM ready flag.                                */

#define EFM_FLAG_CLR_PEWERRCLR      EFM_FSCLR_PEWERRCLR     /*!< EFM Programming/erase error flag.              */
#define EFM_FLAG_CLR_PEPRTERRCLR    EFM_FSCLR_PEPRTERRCLR   /*!< EFM Programming/erase protect area error flag. */
#define EFM_FLAG_CLR_PGMISMTCHCLR   EFM_FSCLR_PGMISMTCHCLR  /*!< EFM Programming  miss match error flag         */
#define EFM_FLAG_CLR_OPTENDCLR      EFM_FSCLR_OPTENDCLR     /*!< EFM End of Operation flag.                     */
#define EFM_FLAG_CLR_COLERRCLR      EFM_FSCLR_RDCOLERRCLR   /*!< EFM Read collide error flag.                   */

/**
 * @}
 */

/**
 * @defgroup EFM_Interrupt_definition EFM Interrupt definition
 * @{
 */
#define EFM_INT_EOP                 EFM_FITE_OPTENDITE      /*!< End of EFM Operation Interrupt source      */
#define EFM_INT_PEERR               EFM_FITE_PEERRITE       /*!< Program/erase error Interrupt source       */
#define EFM_INT_RDCOLERR            EFM_FITE_RDCOLERRITE    /*!< Read collide error Interrupt source        */
/**
 * @}
 */

/**
 * @defgroup EFM_Keys EFM Keys
 * @{
 */
#define EFM_KEY1                    0x00000123U
#define EFM_KEY2                    0x00003210U
/**
 * @}
 */

/**
 * @defgroup EFM_State EFM State
 * @{
 */
#define EFM_LOCK                    0x00000000
#define EFM_UNLOCK                  0x00000001
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
 * @addtogroup EFM_Global_Functions
 * @{
 */

void EFM_Unlock(void);
void EFM_Lock(void);

void EFM_Cmd(en_functional_state_t enNewState);
void EFM_SetLatency(uint32_t u32Latency);
void EFM_SetBusState(uint32_t u32State);
void EFM_InstructionCacheCmd(en_functional_state_t enNewState);
void EFM_SetWinProtectAddr(stc_efm_win_protect_addr_t stcAddr);
void EFM_InterruptCmd(uint32_t u32EfmInt, en_functional_state_t enNewState);

en_result_t EFM_StrucInit(stc_efm_cfg_t *pstcEfmCfg);
en_result_t EFM_Config(stc_efm_cfg_t *pstcEfmCfg);

void EFM_SetOperateMode(uint32_t u32PeMode);
en_result_t EFM_ProgramWord(uint32_t u32Addr, uint32_t u32Data);
en_result_t EFM_ProgramHalfWord(uint32_t u32Addr, uint16_t u16Data);
en_result_t EFM_ProgramByte(uint32_t u32Addr, uint8_t u8Data);
en_result_t EFM_ProgramWordRB(uint32_t u32Addr, uint32_t u32Data);
en_result_t EFM_ProgramHalfWordRB(uint32_t u32Addr, uint16_t u16Data);
en_result_t EFM_ProgramByteRB(uint32_t u32Addr, uint8_t u8Data);
en_result_t EFM_SequenceProgram(uint32_t u32Addr, uint32_t u32Len, void *pBuf);
en_result_t EFM_SectorErase(uint32_t u32Addr);
en_result_t EFM_ChipErase(void);

void EFM_ClearFlag(uint32_t u32Flag);
en_flag_status_t EFM_GetFlagStatus(uint32_t u32Flag);
stc_efm_unique_id_t EFM_ReadUID(void);
/**
 * @}
 */

#endif /* DDL_EFM_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32F120_EFM_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
