/**
 *******************************************************************************
 * @file  hc32f120_rtc.c
 * @brief This file provides firmware functions to manage the Real-Time
 *        Clock(RTC).
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-06       Yangjp          First version
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
#include "hc32f120_rtc.h"
#include "hc32f120_utility.h"

/**
 * @addtogroup HC32F120_DDL_Driver
 * @{
 */

/**
 * @defgroup DDL_RTC RTC
 * @brief Real-Time Clock Driver Library
 * @{
 */

#if (DDL_RTC_ENABLE == DDL_ON)

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup RTC_Local_Macros RTC Local Macros
 * @{
 */

/**
 * @defgroup RTC_Check_Parameters_Validity RTC Check Parameters Validity
 * @{
 */
#define IS_RTC_PERIOD_INTERRUPT(x)                                             \
(   (RTC_PERIOD_INT_INVALID == (x))             ||                             \
    (RTC_PERIOD_INT_HALF_SECOND == (x))         ||                             \
    (RTC_PERIOD_INT_ONE_SECOND == (x))          ||                             \
    (RTC_PERIOD_INT_ONE_MINUTE == (x))          ||                             \
    (RTC_PERIOD_INT_ONE_HOUR == (x))            ||                             \
    (RTC_PERIOD_INT_ONE_DAY == (x))             ||                             \
    (RTC_PERIOD_INT_ONE_MONTH == (x)))

#define IS_RTC_HOUR_FORMAT(x)                                                  \
(   (RTC_HOUR_FORMAT_12 == (x))                 ||                             \
    (RTC_HOUR_FORMAT_24 == (x)))

#define IS_RTC_WORK_MODE(x)                                                    \
(   (RTC_WORK_MODE_COUNT == (x))                ||                             \
    (RTC_WORK_MODE_WRITE_OR_READ == (x)))

#define IS_RTC_CLOCK_SOURCE(x)                                                 \
(   (RTC_CLOCK_SOURCE_XTAL32 == (x))            ||                             \
    (RTC_CLOCK_SOURCE_LRC == (x)))

#define IS_RTC_DATA_FORMAT(x)                                                  \
(   (RTC_DATA_FORMAT_DEC == (x))                ||                             \
    (RTC_DATA_FORMAT_BCD == (x)))

#define IS_RTC_HOUR12_AM_PM(x)                                                 \
(   (RTC_HOUR12_AM == (x))                      ||                             \
    (RTC_HOUR12_PM == (x)))

#define IS_RTC_YEAR(x)                          ((x) <= 99)

#define IS_RTC_MONTH(x)                         (((x) >= 1) && ((x) <= 12))

#define IS_RTC_DAY(x)                           (((x) >= 1) && ((x) <= 31))

#define IS_RTC_HOUR12(x)                        (((x) >= 1) && ((x) <= 12))

#define IS_RTC_HOUR24(x)                        ((x) <= 23)

#define IS_RTC_MINUTE(x)                        ((x) <= 59)

#define IS_RTC_SECOND(x)                        ((x) <= 59)

#define IS_RTC_WEEKDAY(x)                       ((x) <= 6)

#define IS_RTC_ALARM_WEEKDAY(x)                 ((x) <= 0x7F)

#define IS_RTC_FLAG(x)                                                         \
(   (RTC_FLAG_PERIOD == (x))                    ||                             \
    (RTC_FLAG_ALARM == (x))                     ||                             \
    (RTC_FLAG_WAIT == (x)))

#define IS_RTC_INT_FLAG(x)                                                     \
(   (RTC_FLAG_PERIOD == (x))                    ||                             \
    (RTC_FLAG_ALARM == (x)))

#define IS_RTC_INTERRUPT(x)                                                    \
(   (RTC_INT_PERIOD == (x))                     ||                             \
    (RTC_INT_ALARM == (x)))

#define IS_RTC_COMPENSATION_VALUE(x)            ((x) <= 0x1FF)
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

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @defgroup RTC_Global_Functions RTC Global Functions
 * @{
 */

/**
 * @brief  De-Initialize RTC.
 * @param  None
 * @retval An en_result_t enumeration value:
 *           - Ok: De-Initialize success
 *           - ErrorTimeout: De-Initialize timeout
 */
en_result_t RTC_DeInit(void)
{
    uint32_t enRegSta;
    uint32_t u32Timeout, u32TimeCnt = 0;
    en_result_t enRet = Ok;

    bM0P_RTC->CR0_b.RESET = Reset;
    /* Waiting for normal count status or end of RTC software reset */
    u32Timeout = SystemCoreClock >> 8;
    do
    {
        enRegSta = bM0P_RTC->CR0_b.RESET;
        u32TimeCnt++;
    } while ((u32TimeCnt < u32Timeout) && (Reset != enRegSta));

    if (Reset != enRegSta)
    {
        enRet = ErrorTimeout;
    }
    else
    {
        /* Reset all RTC registers */
        bM0P_RTC->CR0_b.RESET = Set;
    }

    return enRet;
}

/**
 * @brief  Initialize RTC.
 * @param  [in] pstcRtcInit             Pointer to a stc_rtc_init_t structure
 *                                      that contains configuration information.
 *   @arg  See the struct @ref stc_rtc_init_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Initialize success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_Init(const stc_rtc_init_t *pstcRtcInit)
{
    if (NULL == pstcRtcInit)
    {
        return ErrorInvalidParameter;
    }

    /* Check parameters */
    DDL_ASSERT(IS_RTC_CLOCK_SOURCE(pstcRtcInit->u8ClockSource));
    DDL_ASSERT(IS_RTC_HOUR_FORMAT(pstcRtcInit->u8HourFormat));
    DDL_ASSERT(IS_RTC_PERIOD_INTERRUPT(pstcRtcInit->u8PeriodInterrupt));

    /* RTC CR1 Configuration */
    MODIFY_REG(M0P_RTC->CR1, (RTC_CR1_PRDS | RTC_CR1_AMPM),
               (pstcRtcInit->u8PeriodInterrupt | pstcRtcInit->u8HourFormat));

    /* RTC CR3 Configuration */
    if (RTC_CLOCK_SOURCE_XTAL32 != pstcRtcInit->u8ClockSource)
    {
        MODIFY_REG(M0P_RTC->CR3, (RTC_CR3_LRCEN | RTC_CR3_RCKSEL),
                   (pstcRtcInit->u8ClockSource | RTC_CR3_LRCEN));
    }
    else
    {
        MODIFY_REG(M0P_RTC->CR3, (RTC_CR3_LRCEN | RTC_CR3_RCKSEL),
                   pstcRtcInit->u8ClockSource);
    }

    return Ok;
}

/**
 * @brief  Fills each stc_rtc_init_t member with default value.
 * @param  [out] pstcRtcInit            Pointer to a stc_rtc_init_t structure
 *                                      which will be initialized.
 *   @arg  See the struct @ref stc_rtc_init_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: stc_rtc_init_t member initialize success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_StructInit(stc_rtc_init_t *pstcRtcInit)
{
    if (NULL == pstcRtcInit)
    {
        return ErrorInvalidParameter;
    }

    pstcRtcInit->u8ClockSource = RTC_CLOCK_SOURCE_XTAL32;
    pstcRtcInit->u8HourFormat = RTC_HOUR_FORMAT_12;
    pstcRtcInit->u8PeriodInterrupt = RTC_PERIOD_INT_INVALID;

    return Ok;
}

/**
 * @brief  Enter RTC read/write mode.
 * @param  None
 * @retval An en_result_t enumeration value:
 *           - Ok: Enter mode success
 *           - ErrorTimeout: Enter mode timeout
 */
en_result_t RTC_EnterRwMode(void)
{
    uint32_t enRegSta;
    uint32_t u32Timeout, u32TimeCnt = 0;
    en_result_t enRet = Ok;

    /* Mode switch when RTC is running */
    if (Reset != bM0P_RTC->CR1_b.START)
    {
        bM0P_RTC->CR2_b.WAIT = Set;
        /* Waiting for WAITF bit set */
        u32Timeout = SystemCoreClock >> 8;
        do
        {
            enRegSta = bM0P_RTC->CR2_b.WAITF;
            u32TimeCnt++;
        } while ((u32TimeCnt < u32Timeout) && (Set != enRegSta));

        if (Set != enRegSta)
        {
            enRet = ErrorTimeout;
        }
    }

    return enRet;
}

/**
 * @brief  Exit RTC read/write mode.
 * @param  None
 * @retval An en_result_t enumeration value:
 *           - Ok: Exit mode success
 *           - ErrorTimeout: Exit mode timeout
 */
en_result_t RTC_ExitRwMode(void)
{
    uint32_t enRegSta;
    uint32_t u32Timeout, u32TimeCnt = 0;
    en_result_t enRet = Ok;

    /* Mode switch when RTC is running */
    if (Reset != bM0P_RTC->CR1_b.START)
    {
        bM0P_RTC->CR2_b.WAIT = Reset;
        /* Waiting for WAITF bit reset */
        u32Timeout = SystemCoreClock >> 8;
        do
        {
            enRegSta = bM0P_RTC->CR2_b.WAITF;
            u32TimeCnt++;
        } while ((u32TimeCnt < u32Timeout) && (Reset != enRegSta));

        if (Reset != enRegSta)
        {
            enRet = ErrorTimeout;
        }
    }

    return enRet;
}

/**
 * @brief  RTC period interrupt config.
 * @param  [in] u8IntCond               Specifies the period interrupt type.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_PERIOD_INT_INVALID:     Period interrupt invalid
 *   @arg  RTC_PERIOD_INT_HALF_SECOND: 0.5 second period interrupt
 *   @arg  RTC_PERIOD_INT_ONE_SECOND:  1 second period interrupt
 *   @arg  RTC_PERIOD_INT_ONE_MINUTE:  1 minute period interrupt
 *   @arg  RTC_PERIOD_INT_ONE_HOUR:    1 hour period interrupt
 *   @arg  RTC_PERIOD_INT_ONE_DAY:     1 day period interrupt
 *   @arg  RTC_PERIOD_INT_ONE_MONTH:   1 month period interrupt
 * @retval None
 */
void RTC_PeriodIntConfig(uint8_t u8IntCond)
{
    uint32_t enRtcSta, enIntSta;

    /* Check parameters */
    DDL_ASSERT(IS_RTC_PERIOD_INTERRUPT(u8IntCond));

    enRtcSta = bM0P_RTC->CR1_b.START;
    enIntSta = bM0P_RTC->CR2_b.PRDIE;
    /* Disable period interrupt when START=1 and clear period flag after write */
    if ((Set == enIntSta) && (Set == enRtcSta))
    {
        bM0P_RTC->CR2_b.PRDIE = Reset;
    }

    /* RTC CR1 Configuration */
    MODIFY_REG(M0P_RTC->CR1, RTC_CR1_PRDS, u8IntCond);

    if ((Set == enIntSta) && (Set == enRtcSta))
    {
        MODIFY_REG(M0P_RTC->CR2, RTC_CR2_PRDF, RTC_CR2_PRDIE);
    }
}

/**
 * @brief  RTC enter low power condition check.
 * @param  None
 * @retval An en_result_t enumeration value:
 *           - Ok: Can enter low power mode
 *           - ErrorTimeout: Can't enter low power mode
 */
en_result_t RTC_LowPowerCheck(void)
{
    uint32_t enRegSta;
    uint32_t u32Timeout, u32TimeCnt = 0;
    en_result_t enRet = Ok;

    /* Check RTC work status */
    if (Reset == bM0P_RTC->CR1_b.START)
    {
        return enRet;
    }

    bM0P_RTC->CR2_b.WAIT = Set;
    /* Waiting for RTC WAITF bit set */
    u32Timeout = SystemCoreClock >> 8;
    do
    {
        enRegSta = bM0P_RTC->CR2_b.WAITF;
        u32TimeCnt++;
    } while ((u32TimeCnt < u32Timeout) && (Set != enRegSta));

    if (Set != enRegSta)
    {
        enRet = ErrorTimeout;
    }
    else
    {
        bM0P_RTC->CR2_b.WAIT = Reset;
        /* Waiting for RTC WAITF bit reset */
        u32TimeCnt = 0;
        do
        {
            enRegSta = bM0P_RTC->CR2_b.WAITF;
            u32TimeCnt++;
        } while ((u32TimeCnt < u32Timeout) && (Reset != enRegSta));

        if (Reset != enRegSta)
        {
            enRet = ErrorTimeout;
        }
    }

    return enRet;
}

/**
 * @brief  Set RTC clock compensation value.
 * @param  [in] u16CompenVal            Specifies the clock compensation value of RTC.
 *   @arg  This parameter can be any value between 0x00 and 0x1FF.
 * @retval None
 */
void RTC_SetClkCompenValue(uint16_t u16CompenVal)
{
    /* Check parameters */
    DDL_ASSERT(IS_RTC_COMPENSATION_VALUE(u16CompenVal));

    bM0P_RTC->ERRCRH_b.COMP8 = (u16CompenVal >> 8) & 0x01;
    WRITE_REG(M0P_RTC->ERRCRL, (u16CompenVal & 0x00FF));
}

/**
 * @brief  Set RTC current date.
 * @param  [in] u8Format                Specifies the format of the entered parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [in] pstcRtcDate             Pointer to a stc_rtc_date_t structure
 *                                      that contains date configuration information.
 *   @arg  See the struct @ref stc_rtc_date_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Set date success
 *           - Error: Set date failed
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_SetDate(uint8_t u8Format, const stc_rtc_date_t *pstcRtcDate)
{
    en_result_t enRet = Ok;

    if (NULL == pstcRtcDate)
    {
        return ErrorInvalidParameter;
    }
    /* Check parameters */
    DDL_ASSERT(IS_RTC_DATA_FORMAT(u8Format));

    if (RTC_DATA_FORMAT_DEC == u8Format)
    {
        DDL_ASSERT(IS_RTC_YEAR(pstcRtcDate->u8Year));
        DDL_ASSERT(IS_RTC_MONTH(pstcRtcDate->u8Month));
        DDL_ASSERT(IS_RTC_DAY(pstcRtcDate->u8Day));
    }
    else
    {
        DDL_ASSERT(IS_RTC_YEAR(BCD2DEC(pstcRtcDate->u8Year)));
        DDL_ASSERT(IS_RTC_MONTH(BCD2DEC(pstcRtcDate->u8Month)));
        DDL_ASSERT(IS_RTC_DAY(BCD2DEC(pstcRtcDate->u8Day)));
    }
    DDL_ASSERT(IS_RTC_WEEKDAY(pstcRtcDate->u8Weekday));

    /* Enter read/write mode */
    if (Ok != RTC_EnterRwMode())
    {
        enRet = Error;
    }
    else
    {
        if (RTC_DATA_FORMAT_DEC == u8Format)
        {
            WRITE_REG(M0P_RTC->YEAR, DEC2BCD(pstcRtcDate->u8Year));
            WRITE_REG(M0P_RTC->MON, DEC2BCD(pstcRtcDate->u8Month));
            WRITE_REG(M0P_RTC->DAY, DEC2BCD(pstcRtcDate->u8Day));
        }
        else
        {
            WRITE_REG(M0P_RTC->YEAR, pstcRtcDate->u8Year);
            WRITE_REG(M0P_RTC->MON, pstcRtcDate->u8Month);
            WRITE_REG(M0P_RTC->DAY, pstcRtcDate->u8Day);
        }
        WRITE_REG(M0P_RTC->WEEK, pstcRtcDate->u8Weekday);

        /* Exit read/write mode */
        if (Ok != RTC_ExitRwMode())
        {
            enRet = Error;
        }
    }

    return enRet;
}

/**
 * @brief  Fills each stc_rtc_date_t member with default value.(Date = xx00 January 01 Monday).
 * @param  [out] pstcRtcDate            Pointer to a stc_rtc_date_t structure
 *                                      which will be initialized.
 *   @arg  See the struct @ref stc_rtc_date_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: stc_rtc_date_t member Initialize success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_DateStructInit(stc_rtc_date_t *pstcRtcDate)
{
    if (NULL == pstcRtcDate)
    {
        return ErrorInvalidParameter;
    }

    /* xx00 January 01 Monday */
    pstcRtcDate->u8Year = 0;
    pstcRtcDate->u8Month = RTC_MONTH_JANUARY;
    pstcRtcDate->u8Day = 1;
    pstcRtcDate->u8Weekday = RTC_WEEKDAY_MONDAY;

    return Ok;
}

/**
 * @brief  Get RTC current date.
 * @param  [in] u8Format                Specifies the format of the returned parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [out] pstcRtcDate            Pointer to a stc_rtc_date_t structure
 *                                      will contain returned current date information.
 *   @arg  See the struct @ref stc_rtc_date_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Get date success
 *           - Error: Get date failed
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_GetDate(uint8_t u8Format, stc_rtc_date_t *pstcRtcDate)
{
    en_result_t enRet = Ok;

    if (NULL == pstcRtcDate)
    {
        return ErrorInvalidParameter;
    }
    /* Check parameters */
    DDL_ASSERT(IS_RTC_DATA_FORMAT(u8Format));

    /* Enter read/write mode */
    if (Ok != RTC_EnterRwMode())
    {
        enRet = Error;
    }
    else
    {
        /* Get RTC date registers */
        pstcRtcDate->u8Year = READ_REG(M0P_RTC->YEAR);
        pstcRtcDate->u8Month = READ_REG(M0P_RTC->MON);
        pstcRtcDate->u8Day = READ_REG(M0P_RTC->DAY);
        pstcRtcDate->u8Weekday = READ_REG(M0P_RTC->WEEK);

        /* Check decimal format*/
        if (RTC_DATA_FORMAT_DEC == u8Format)
        {
            pstcRtcDate->u8Year = BCD2DEC(pstcRtcDate->u8Year);
            pstcRtcDate->u8Month = BCD2DEC(pstcRtcDate->u8Month);
            pstcRtcDate->u8Day = BCD2DEC(pstcRtcDate->u8Day);
        }

        /* exit read/write mode */
        if (Ok != RTC_ExitRwMode())
        {
            enRet = Error;
        }
    }

    return enRet;
}

/**
 * @brief  Set RTC current time.
 * @param  [in] u8Format                Specifies the format of the entered parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [in] pstcRtcTime             Pointer to a stc_rtc_time_t structure
 *                                      that contains time configuration information.
 *   @arg  See the struct @ref stc_rtc_time_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Set time success
 *           - Error: Set time failed
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_SetTime(uint8_t u8Format, const stc_rtc_time_t *pstcRtcTime)
{
    en_result_t enRet = Ok;

    if (NULL == pstcRtcTime)
    {
        return ErrorInvalidParameter;
    }
    /* Check parameters */
    DDL_ASSERT(IS_RTC_DATA_FORMAT(u8Format));

    if (RTC_DATA_FORMAT_DEC == u8Format)
    {
        if (RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM)
        {
            DDL_ASSERT(IS_RTC_HOUR12(pstcRtcTime->u8Hour));
            DDL_ASSERT(IS_RTC_HOUR12_AM_PM(pstcRtcTime->u8AmPm));
        }
        else
        {
            DDL_ASSERT(IS_RTC_HOUR24(pstcRtcTime->u8Hour));
        }
        DDL_ASSERT(IS_RTC_MINUTE(pstcRtcTime->u8Minute));
        DDL_ASSERT(IS_RTC_SECOND(pstcRtcTime->u8Second));
    }
    else
    {
        if (RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM)
        {
            DDL_ASSERT(IS_RTC_HOUR12(BCD2DEC(pstcRtcTime->u8Hour)));
            DDL_ASSERT(IS_RTC_HOUR12_AM_PM(pstcRtcTime->u8AmPm));
        }
        else
        {
            DDL_ASSERT(IS_RTC_HOUR24(BCD2DEC(pstcRtcTime->u8Hour)));
        }
        DDL_ASSERT(IS_RTC_MINUTE(BCD2DEC(pstcRtcTime->u8Minute)));
        DDL_ASSERT(IS_RTC_SECOND(BCD2DEC(pstcRtcTime->u8Second)));
    }

    /* Enter read/write mode */
    if (Ok != RTC_EnterRwMode())
    {
        enRet = Error;
    }
    else
    {
        if (RTC_DATA_FORMAT_DEC == u8Format)
        {
            if ((RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM) &&
                (RTC_HOUR12_PM == pstcRtcTime->u8AmPm))
            {
                WRITE_REG(M0P_RTC->HOUR, (DEC2BCD(pstcRtcTime->u8Hour) | RTC_HOUR12_PM));
            }
            else
            {
                WRITE_REG(M0P_RTC->HOUR, DEC2BCD(pstcRtcTime->u8Hour));
            }
            WRITE_REG(M0P_RTC->MIN, DEC2BCD(pstcRtcTime->u8Minute));
            WRITE_REG(M0P_RTC->SEC, DEC2BCD(pstcRtcTime->u8Second));
        }
        else
        {
            if ((RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM) &&
                (RTC_HOUR12_PM == pstcRtcTime->u8AmPm))
            {
                WRITE_REG(M0P_RTC->HOUR, (pstcRtcTime->u8Hour | RTC_HOUR12_PM));
            }
            else
            {
                WRITE_REG(M0P_RTC->HOUR, pstcRtcTime->u8Hour);
            }
            WRITE_REG(M0P_RTC->MIN, pstcRtcTime->u8Minute);
            WRITE_REG(M0P_RTC->SEC, pstcRtcTime->u8Second);
        }

        /* Exit read/write mode */
        if (Ok != RTC_ExitRwMode())
        {
            enRet = Error;
        }
    }

    return enRet;
}

/**
 * @brief  Fills each stc_rtc_time_t member with default value.(Time = Am: 06h:00m:00s).
 * @param  [out] pstcRtcTime            Pointer to a stc_rtc_time_t structure
 *                                      which will be initialized.
 *   @arg  See the struct @ref stc_rtc_time_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: stc_rtc_time_t member Initialize success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_TimeStructInit(stc_rtc_time_t *pstcRtcTime)
{
    if (NULL == pstcRtcTime)
    {
        return ErrorInvalidParameter;
    }

    /* Am: 06h:00m:00s */
    pstcRtcTime->u8Hour = 6;
    pstcRtcTime->u8Minute = 0;
    pstcRtcTime->u8Second = 0;
    pstcRtcTime->u8AmPm = RTC_HOUR12_AM;

    return Ok;
}

/**
 * @brief  Get RTC current time.
 * @param  [in] u8Format                Specifies the format of the returned parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [out] pstcRtcTime            Pointer to a stc_rtc_time_t structure
 *                                      will contain returned current time information.
 *   @arg  See the struct @ref stc_rtc_time_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Get time success
 *           - Error: Get time failed
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_GetTime(uint8_t u8Format, stc_rtc_time_t *pstcRtcTime)
{
    en_result_t enRet = Ok;

    if (NULL == pstcRtcTime)
    {
        return ErrorInvalidParameter;
    }
    /* Check parameters */
    DDL_ASSERT(IS_RTC_DATA_FORMAT(u8Format));

    /* Enter read/write mode */
    if (Ok != RTC_EnterRwMode())
    {
        enRet = Error;
    }
    else
    {
        /* Get RTC time registers */
        pstcRtcTime->u8Hour = READ_REG(M0P_RTC->HOUR);
        pstcRtcTime->u8Minute = READ_REG(M0P_RTC->MIN);
        pstcRtcTime->u8Second = READ_REG(M0P_RTC->SEC);
        if (RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM)
        {
            if (RTC_HOUR12_PM == (pstcRtcTime->u8Hour & RTC_HOUR12_PM))
            {
                CLEAR_BIT(pstcRtcTime->u8Hour, RTC_HOUR12_PM);
                pstcRtcTime->u8AmPm = RTC_HOUR12_PM;
            }
            else
            {
                pstcRtcTime->u8AmPm = RTC_HOUR12_AM;
            }
        }

        /* Check decimal format*/
        if (RTC_DATA_FORMAT_DEC == u8Format)
        {
            pstcRtcTime->u8Hour = BCD2DEC(pstcRtcTime->u8Hour);
            pstcRtcTime->u8Minute = BCD2DEC(pstcRtcTime->u8Minute);
            pstcRtcTime->u8Second = BCD2DEC(pstcRtcTime->u8Second);
        }

        /* exit read/write mode */
        if (Ok != RTC_ExitRwMode())
        {
            enRet = Error;
        }
    }

    return enRet;
}

/**
 * @brief  Set RTC alarm time.
 * @param  [in] u8Format                Specifies the format of the entered parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [in] pstcRtcAlarm            Pointer to a stc_rtc_alarm_t structure
 *                                      that contains alarm time configuration information.
 *   @arg  See the struct @ref stc_rtc_alarm_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Set RTC alarm time success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_SetAlarm(uint8_t u8Format, const stc_rtc_alarm_t *pstcRtcAlarm)
{
    if (NULL == pstcRtcAlarm)
    {
        return ErrorInvalidParameter;
    }
    /* Check parameters */
    DDL_ASSERT(IS_RTC_DATA_FORMAT(u8Format));

    if (RTC_DATA_FORMAT_DEC == u8Format)
    {
        if (RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM)
        {
            DDL_ASSERT(IS_RTC_HOUR12(pstcRtcAlarm->u8AlarmHour));
            DDL_ASSERT(IS_RTC_HOUR12_AM_PM(pstcRtcAlarm->u8AlarmAmPm));
        }
        else
        {
            DDL_ASSERT(IS_RTC_HOUR24(pstcRtcAlarm->u8AlarmHour));
        }
        DDL_ASSERT(IS_RTC_MINUTE(pstcRtcAlarm->u8AlarmMinute));
    }
    else
    {
        if (RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM)
        {
            DDL_ASSERT(IS_RTC_HOUR12(BCD2DEC(pstcRtcAlarm->u8AlarmHour)));
            DDL_ASSERT(IS_RTC_HOUR12_AM_PM(pstcRtcAlarm->u8AlarmAmPm));
        }
        else
        {
            DDL_ASSERT(IS_RTC_HOUR24(BCD2DEC(pstcRtcAlarm->u8AlarmHour)));
        }
        DDL_ASSERT(IS_RTC_MINUTE(BCD2DEC(pstcRtcAlarm->u8AlarmMinute)));
    }
    DDL_ASSERT(IS_RTC_ALARM_WEEKDAY(pstcRtcAlarm->u8AlarmWeekday));

    /* Configure alarm registers */
    if (RTC_DATA_FORMAT_DEC == u8Format)
    {
        if ((RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM) &&
            (RTC_HOUR12_PM == pstcRtcAlarm->u8AlarmAmPm))
        {
            WRITE_REG(M0P_RTC->ALMHOUR, (DEC2BCD(pstcRtcAlarm->u8AlarmHour) | RTC_HOUR12_PM));
        }
        else
        {
            WRITE_REG(M0P_RTC->ALMHOUR, DEC2BCD(pstcRtcAlarm->u8AlarmHour));
        }
        WRITE_REG(M0P_RTC->ALMMIN, DEC2BCD(pstcRtcAlarm->u8AlarmMinute));
    }
    else
    {
        if ((RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM) &&
            (RTC_HOUR12_PM == pstcRtcAlarm->u8AlarmAmPm))
        {
            WRITE_REG(M0P_RTC->ALMHOUR, (pstcRtcAlarm->u8AlarmHour | RTC_HOUR12_PM));
        }
        else
        {
            WRITE_REG(M0P_RTC->ALMHOUR, pstcRtcAlarm->u8AlarmHour);
        }
        WRITE_REG(M0P_RTC->ALMMIN, pstcRtcAlarm->u8AlarmMinute);
    }
    WRITE_REG(M0P_RTC->ALMWEEK, pstcRtcAlarm->u8AlarmWeekday);

    return Ok;
}

/**
 * @brief  Fills each stc_rtc_alarm_t member with default value.(Time = Am: 6h:00m Monday).
 * @param  [out] pstcRtcAlarm           Pointer to a stc_rtc_alarm_t structure
 *                                      which will be initialized.
 *   @arg  See the struct @ref stc_rtc_alarm_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: stc_rtc_alarm_t member initialize success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_AlarmStructInit(stc_rtc_alarm_t *pstcRtcAlarm)
{
    if (NULL == pstcRtcAlarm)
    {
        return ErrorInvalidParameter;
    }

    /* Monday Am: 6h:00m */
    pstcRtcAlarm->u8AlarmAmPm = RTC_HOUR12_AM;
    pstcRtcAlarm->u8AlarmHour = 6;
    pstcRtcAlarm->u8AlarmMinute = 0;
    pstcRtcAlarm->u8AlarmWeekday = RTC_ALARM_WEEKDAY_MONDAY;

    return Ok;
}

/**
 * @brief  Get RTC alarm time.
 * @param  [in] u8Format                Specifies the format of the returned parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [out] pstcRtcAlarm           Pointer to a stc_rtc_alarm_t structure
 *                                      will contain returned alarm time information.
 *   @arg  See the struct @ref stc_rtc_alarm_t.
 * @retval An en_result_t enumeration value:
 *           - Ok: Get RTC alarm time success
 *           - ErrorInvalidParameter: Invalid parameter
 */
en_result_t RTC_GetAlarm(uint8_t u8Format, stc_rtc_alarm_t *pstcRtcAlarm)
{
    if (NULL == pstcRtcAlarm)
    {
        return ErrorInvalidParameter;
    }
    /* Check parameters */
    DDL_ASSERT(IS_RTC_DATA_FORMAT(u8Format));

    /* Get RTC date and time register */
    pstcRtcAlarm->u8AlarmWeekday = READ_REG(M0P_RTC->ALMWEEK);
    pstcRtcAlarm->u8AlarmMinute = READ_REG(M0P_RTC->ALMMIN);
    pstcRtcAlarm->u8AlarmHour = READ_REG(M0P_RTC->ALMHOUR);
    if (RTC_HOUR_FORMAT_12 == bM0P_RTC->CR1_b.AMPM)
    {
        if (RTC_HOUR12_PM == (pstcRtcAlarm->u8AlarmHour & RTC_HOUR12_PM))
        {
            CLEAR_BIT(pstcRtcAlarm->u8AlarmHour, RTC_HOUR12_PM);
            pstcRtcAlarm->u8AlarmAmPm = RTC_HOUR12_PM;
        }
        else
        {
            pstcRtcAlarm->u8AlarmAmPm = RTC_HOUR12_AM;
        }
    }

    /* Check decimal format*/
    if (RTC_DATA_FORMAT_DEC == u8Format)
    {
        pstcRtcAlarm->u8AlarmHour = BCD2DEC(pstcRtcAlarm->u8AlarmHour);
        pstcRtcAlarm->u8AlarmMinute = BCD2DEC(pstcRtcAlarm->u8AlarmMinute);
    }

    return Ok;
}

/**
 * @brief  Enable or disable RTC alarm.
 * @param  [in] enNewSta                The function new state.
 *   @arg  This parameter can be: Enable or Disable.
 * @retval None
 */
void RTC_AlarmCmd(en_functional_state_t enNewSta)
{
    uint32_t enRtcSta, enIntSta;

    /* Check parameters */
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewSta));

    enRtcSta = bM0P_RTC->CR1_b.START;
    enIntSta = bM0P_RTC->CR2_b.ALMIE;
    /* Disable alarm interrupt and clear alarm flag when START=1 and ALMIE=1 */
    if ((Set == enIntSta) && (Set == enRtcSta))
    {
        bM0P_RTC->CR2_b.ALMIE = Reset;
    }
    bM0P_RTC->CR2_b.ALME = enNewSta;

    if ((Set == enIntSta) && (Set == enRtcSta))
    {
        MODIFY_REG(M0P_RTC->CR2, RTC_CR2_ALMF, RTC_CR2_ALMIE);
    }
}

/**
 * @brief  Enable or disable specified RTC interrupt.
 * @param  [in] u8IntSource             Specifies the RTC interrupt source.
 *                                      This parameter can be one or a combination of the following values:
 *   @arg  RTC_INT_PERIOD: Period count interrupt
 *   @arg  RTC_INT_ALARM:  Alarm interrupt
 * @param  [in] enNewSta                The function new state.
 *   @arg  This parameter can be: Enable or Disable.
 * @retval None
 */
void RTC_IntCmd(uint8_t u8IntSource, en_functional_state_t enNewSta)
{
    /* Check parameters */
    DDL_ASSERT(IS_RTC_INTERRUPT(u8IntSource));
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewSta));

    if (Disable != enNewSta)
    {
        SET_BIT(M0P_RTC->CR2, u8IntSource);
    }
    else
    {
        CLEAR_BIT(M0P_RTC->CR2, u8IntSource);
    }
}

/**
 * @brief  Get RTC flag status.
 * @param  [in] u8Flag                  Specifies the RTC flag type.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_FLAG_PERIOD: Period count flag
 *   @arg  RTC_FLAG_ALARM:  Alarm flag
 *   @arg  RTC_FLAG_WAIT:   Wait flag
 * @retval An en_flag_status_t enumeration value:
 *           - Set: Flag is set
 *           - Reset: Flag is reset
 */
en_flag_status_t RTC_GetFlag(uint8_t u8Flag)
{
    en_flag_status_t enFlagSta = Reset;

    /* Check parameters */
    DDL_ASSERT(IS_RTC_FLAG(u8Flag));

    if (Reset != (READ_BIT(M0P_RTC->CR2, u8Flag)))
    {
        enFlagSta = Set;
    }

    return enFlagSta;
}

/**
 * @brief  Clear RTC flag.
 * @param  [in] u8Flag                  Specifies the RTC flag type.
 *                                      This parameter can be one or a combination of the following values:
 *   @arg  RTC_FLAG_PERIOD: Period count flag
 *   @arg  RTC_FLAG_ALARM:  Alarm flag
 *   @arg  RTC_FLAG_WAIT:   Wait flag
 * @retval None
 */
void RTC_ClearFlag(uint8_t u8Flag)
{
    /* Check parameters */
    DDL_ASSERT(IS_RTC_FLAG(u8Flag));

    CLEAR_BIT(M0P_RTC->CR2, u8Flag);
}

/**
 * @brief  Get RTC interrupt flag status.
 * @param  [in] u8IntFlag               Specifies the RTC interrupt flag type.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_FLAG_PERIOD: Period count flag
 *   @arg  RTC_FLAG_ALARM:  Alarm flag
 * @retval An en_flag_status_t enumeration value:
 *           - Set: Interrupt flag is set
 *           - Reset: Interrupt flag is reset
 */
en_flag_status_t RTC_GetIntFlag(uint8_t u8IntFlag)
{
    en_flag_status_t enFlagSta = Reset;

    /* Check parameters */
    DDL_ASSERT(IS_RTC_INT_FLAG(u8IntFlag));

    if (Reset != (READ_BIT(M0P_RTC->CR2, u8IntFlag)))
    {
        enFlagSta = Set;
    }

    return enFlagSta;
}

/**
 * @brief  Clear RTC interrupt flag.
 * @param  [in] u8IntFlag               Specifies the RTC interrupt flag type.
 *                                      This parameter can be one or a combination of the following values:
 *   @arg  RTC_FLAG_PERIOD: Period count flag
 *   @arg  RTC_FLAG_ALARM:  Alarm flag
 * @retval None
 */
void RTC_ClearIntFlag(uint8_t u8IntFlag)
{
    /* Check parameters */
    DDL_ASSERT(IS_RTC_INT_FLAG(u8IntFlag));

    CLEAR_BIT(M0P_RTC->CR2, u8IntFlag);
}

/**
 * @}
 */

#endif /* DDL_RTC_ENABLE */

/**
 * @}
 */

/**
* @}
*/

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/
