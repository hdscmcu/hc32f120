/**
 *******************************************************************************
 * @file  hc32_common.h
 * @brief This file contains the common part of the HC32 series.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-04       Yangjp          First version
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
 * of the software.common part.
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
#ifndef __HC32_COMMON_H__
#define __HC32_COMMON_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include <stddef.h>

/**
 * @addtogroup CMSIS
 * @{
 */

/**
 * @addtogroup HC32_Common_Part
 * @{
 */

/**
 * @brief HC32 Common Device Include
 */
#if defined(HC32F120)
    #include "hc32f120.h"
    #include "system_hc32f120.h"
#else
    #error "Please select first the target HC32xxxx device used in your application (in hc32xxxx.h file)"
#endif

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup HC32_Common_Global_Types HC32 Common Global Types
 * @{
 */

/**
 * @brief Single precision floating point number (4 byte)
 */
typedef float float32_t;

/**
 * @brief Double precision floating point number (8 byte)
 */
typedef double float64_t;

/**
 * @brief Function pointer type to void/void function
 */
typedef void (*func_ptr_t)(void);

/**
 * @brief Function pointer type to void/uint8_t function
 */
typedef void (*func_ptr_arg1_t)(uint8_t);

/**
 * @brief Functional state
 */
typedef enum
{
    Disable = 0u,
    Enable  = 1u,
} en_functional_state_t;

/* Check if it is a functional state */
#define IS_FUNCTIONAL_STATE(state)      (((state) == Disable) || ((state) == Enable))

/**
 * @brief Flag status
 */
typedef enum
{
    Reset = 0u,
    Set   = 1u,
} en_flag_status_t, en_int_status_t;

/**
 * @brief Generic error codes
 */
typedef enum
{
    Ok                       = 0u,   /*!< No error */
    Error                    = 1u,   /*!< Non-specific error code */
    ErrorAddressAlignment    = 2u,   /*!< Address alignment does not match */
    ErrorAccessRights        = 3u,   /*!< Wrong mode (e.g. user/system) mode is set */
    ErrorInvalidParameter    = 4u,   /*!< Provided parameter is not valid */
    ErrorOperationInProgress = 5u,   /*!< A conflicting or requested operation is still in progress */
    ErrorInvalidMode         = 6u,   /*!< Operation not allowed in current mode */
    ErrorUninitialized       = 7u,   /*!< Module (or part of it) was not initialized properly */
    ErrorBufferFull          = 8u,   /*!< Circular buffer can not be written because the buffer is full */
    ErrorTimeout             = 9u,   /*!< Time Out error occurred (e.g. I2C arbitration lost, Flash time-out, etc.) */
    ErrorNotReady            = 10u,  /*!< A requested final state is not reached */
    OperationInProgress      = 11u,  /*!< Indicator for operation in progress (e.g. ADC conversion not finished, DMA channel used, etc.) */
} en_result_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup HC32_Common_Global_Macros HC32 Common Global Macros
 * @{
 */

/**
 * @brief Compiler Macro Definitions
 */
#if defined (__ICCARM__)                /*!< IAR Compiler */
    #define __WEAKDEF                   __weak
    #define __ALIGN_BEGIN               _Pragma("data_alignment=4")
    #define __NOINLINE                  _Pragma("optimize = no_inline")
    #define __RAM_FUNC                  __ramfunc
#elif defined (__CC_ARM)                /*!< ARM Compiler */
    #define __WEAKDEF                   __attribute__((weak))
    #define __ALIGN_BEGIN               __align(4)
    #define __NOINLINE                  __attribute__((noinline))
    /* RAM functions are defined using the toolchain options.
    Functions that are executed in RAM should reside in a separate source module.
    Using the 'Options for File' dialog you can simply change the 'Code / Const'
    area of a module to a memory space in physical RAM. */
    #define __RAM_FUNC
#else
    #error  "unsupported compiler!!"
#endif

/**
 * @defgroup Extend_Macro_Definitions Extend Macro Definitions
 * @{
 */
/* Decimal to BCD */
#define DEC2BCD(x)                      ((((x) / 10u) << 4u) + ((x) % 10u))

/* BCD to decimal */
#define BCD2DEC(x)                      ((((x) >> 4u) * 10u) + ((x) & 0x0Fu))

/* Returns the dimension of an array */
#define ARRAY_SZ(X)                     (sizeof(X) / sizeof((X)[0]))
/**
 * @}
 */

/**
 * @defgroup Register_Macro_Definitions Register Macro Definitions
 * @{
 */
#define SET_BIT(REG, BIT)               ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)             ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)              ((REG) & (BIT))

#define CLEAR_REG(REG)                  ((REG) = (0x0))

#define WRITE_REG(REG, VAL)             ((REG) = (VAL))

#define READ_REG(REG)                   ((REG))

#define MODIFY_REG(REGS, CLEARMASK, SETMASK)    (WRITE_REG((REGS), (((READ_REG((REGS))) & (~(CLEARMASK))) | (SETMASK))))

/* Specificed register bit width */
#define SET_REG8_BIT(REG, BIT)          ((REG) |= ((uint8_t)(BIT)))
#define SET_REG16_BIT(REG, BIT)         ((REG) |= ((uint16_t)(BIT)))
#define SET_REG32_BIT(REG, BIT)         ((REG) |= ((uint32_t)(BIT)))

/* Specificed register bit width */
#define CLEAR_REG8_BIT(REG, BIT)        ((REG) &= ((uint8_t)(~(BIT))))
#define CLEAR_REG16_BIT(REG, BIT)       ((REG) &= ((uint16_t)(~(BIT))))
#define CLEAR_REG32_BIT(REG, BIT)       ((REG) &= ((uint32_t)(~(BIT))))

/* Specificed register bit width */
#define READ_REG8_BIT(REG, BIT)         ((REG) & ((uint8_t)(BIT)))
#define READ_REG16_BIT(REG, BIT)        ((REG) & ((uint16_t)(BIT)))
#define READ_REG32_BIT(REG, BIT)        ((REG) & ((uint32_t)(BIT)))

/* Specificed register bit width */
#define CLEAR_REG8(REG, BIT)            ((REG) = ((uint8_t)(0u)))
#define CLEAR_REG16(REG, BIT)           ((REG) = ((uint16_t)(0u)))
#define CLEAR_REG32(REG, BIT)           ((REG) = ((uint32_t)(0ul)))

/* Specificed register bit width */
#define WRITE_REG8(REG, VAL)            ((REG) = ((uint8_t)(VAL)))
#define WRITE_REG16(REG, VAL)           ((REG) = ((uint16_t)(VAL)))
#define WRITE_REG32(REG, VAL)           ((REG) = ((uint32_t)(VAL)))

/* Specificed register bit width */
#define READ_REG8(REG)                  ((uint8_t)(REG))
#define READ_REG16(REG)                 ((uint16_t)(REG))
#define READ_REG32(REG)                 ((uint32_t)(REG))

/* Specificed register bit width */
#define MODIFY_REG8(REGS, CLEARMASK, SETMASK)   (WRITE_REG((REGS), (((READ_REG((REGS))) & ((uint8_t)(~(CLEARMASK)))) | ((uint8_t)(SETMASK)))))
#define MODIFY_REG16(REGS, CLEARMASK, SETMASK)  (WRITE_REG((REGS), (((READ_REG((REGS))) & ((uint16_t)(~(CLEARMASK)))) | ((uint16_t)(SETMASK)))))
#define MODIFY_REG32(REGS, CLEARMASK, SETMASK)  (WRITE_REG((REGS), (((READ_REG((REGS))) & ((uint32_t)(~(CLEARMASK)))) | ((uint32_t)(SETMASK)))))
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
 * Global function prototypes (definition in C source)
 ******************************************************************************/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32_COMMON_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
