/**
 *******************************************************************************
 * @file  hc32f120_rtc.h
 * @brief This file contains all the functions prototypes of the RTC driver
 *        library.
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
#ifndef __HC32F120_RTC_H__
#define __HC32F120_RTC_H__

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
 * @addtogroup DDL_RTC
 * @{
 */

#if (DDL_RTC_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup RTC_Global_Types RTC Global Types
 * @{
 */

/**
 * @brief RTC Init structure definition
 */
typedef struct
{
    uint8_t u8ClockSource;      /*!< Specifies the RTC Clock Source.
                                     This parameter can be a value of @ref RTC_Clock_Source */
    uint8_t u8HourFormat;       /*!< Specifies the RTC Hour Format.
                                     This parameter can be a value of @ref RTC_Hour_Format */
    uint8_t u8PeriodInterrupt;  /*!< Specifies the RTC Period Interrupt.
                                     This parameter can be a value of @ref RTC_Period_Interrupt */
} stc_rtc_init_t;

/**
 * @brief RTC Date structure definition
 */
typedef struct
{
    uint8_t u8Year;     /*!< Specifies the RTC Year.
                             This parameter can be a number between 0 and 99 */
    uint8_t u8Month;    /*!< Specifies the RTC Month.
                             This parameter can be a value of @ref RTC_Date */
    uint8_t u8Day;      /*!< Specifies the RTC Day.
                             This parameter can be a number between 1 and 31 */
    uint8_t u8Weekday;  /*!< Specifies the RTC Weekday.
                             This parameter can be a value of @ref RTC_Weekday */
} stc_rtc_date_t;

/**
 * @brief RTC Time structure definition
 */
typedef struct
{
    uint8_t u8Hour;    /*!< Specifies the RTC Hour.
                            This parameter can be a number between 1 and 12 if the RTC_HourFormat_12 is selected
                            or between 0 and 23 if the RTC_HourFormat_24 is selected */
    uint8_t u8Minute;  /*!< Specifies the RTC Minute.
                            This parameter can be a number between 0 and 59 */
    uint8_t u8Second;  /*!< Specifies the RTC Second.
                            This parameter can be a number between 0 and 59 */
    uint8_t u8AmPm;    /*!< Specifies the RTC Am/Pm Time.
                            This parameter can be a value of @ref RTC_Hour12_AM_PM */
} stc_rtc_time_t;

/**
 * @brief RTC Alarm structure definition
 */
typedef struct
{
    uint8_t u8AlarmHour;     /*!< Specifies the RTC Alarm Hour.
                                  This parameter can be a number between 1 and 12 if the RTC_HourFormat_12 is selected
                                  or between 0 and 23 if the RTC_HourFormat_24 is selected */
    uint8_t u8AlarmMinute;   /*!< Specifies the RTC Alarm Minute.
                                  This parameter can be a number between 0 and 59 */
    uint8_t u8AlarmWeekday;  /*!< Specifies the RTC Alarm Weekday.
                                  This parameter can be a value of @ref RTC_Alarm_Weekday */
    uint8_t u8AlarmAmPm;     /*!< Specifies the RTC Alarm Am/Pm Time.
                                  This parameter can be a value of @ref RTC_Hour12_AM_PM */
} stc_rtc_alarm_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup RTC_Global_Macros RTC Global Macros
 * @{
 */

/**
 * @defgroup RTC_Period_Interrupt RTC Period Interrupt
 * @{
 */
#define RTC_PERIOD_INT_INVALID          ((uint8_t)0x00)
#define RTC_PERIOD_INT_HALF_SECOND      ((uint8_t)RTC_CR1_PRDS_0)
#define RTC_PERIOD_INT_ONE_SECOND       ((uint8_t)RTC_CR1_PRDS_1)
#define RTC_PERIOD_INT_ONE_MINUTE       ((uint8_t)(RTC_CR1_PRDS_0 | RTC_CR1_PRDS_1))
#define RTC_PERIOD_INT_ONE_HOUR         ((uint8_t)RTC_CR1_PRDS_2)
#define RTC_PERIOD_INT_ONE_DAY          ((uint8_t)(RTC_CR1_PRDS_0 | RTC_CR1_PRDS_2))
#define RTC_PERIOD_INT_ONE_MONTH        ((uint8_t)(RTC_CR1_PRDS_1 | RTC_CR1_PRDS_2))
/**
 * @}
 */

/**
 * @defgroup RTC_Hour_Format RTC Hour Format
 * @{
 */
#define RTC_HOUR_FORMAT_12              ((uint8_t)0x00)
#define RTC_HOUR_FORMAT_24              ((uint8_t)RTC_CR1_AMPM)
/**
 * @}
 */

/**
 * @defgroup RTC_Work_Mode RTC Work Mode
 * @{
 */
#define RTC_WORK_MODE_COUNT             ((uint8_t)0x00)
#define RTC_WORK_MODE_WRITE_OR_READ     ((uint8_t)RTC_CR2_WAIT)
/**
 * @}
 */

/**
 * @defgroup RTC_Clock_Source RTC Clock Source
 * @{
 */
#define RTC_CLOCK_SOURCE_XTAL32         ((uint8_t)0x00)
#define RTC_CLOCK_SOURCE_LRC            ((uint8_t)RTC_CR3_RCKSEL)
/**
 * @}
 */

/**
 * @defgroup RTC_Data_Format RTC Data Format
 * @{
 */
#define RTC_DATA_FORMAT_DEC             ((uint8_t)0x00)
#define RTC_DATA_FORMAT_BCD             ((uint8_t)0x01)

/**
 * @}
 */

/**
 * @defgroup RTC_Hour12_AM_PM RTC Hour12 AM/PM
 * @{
 */
#define RTC_HOUR12_AM                   ((uint8_t)0x00)
#define RTC_HOUR12_PM                   ((uint8_t)RTC_HOUR_HOURD_1)
/**
 * @}
 */

/**
 * @defgroup RTC_Date RTC Date
 * @{
 */
#define RTC_MONTH_JANUARY               ((uint8_t)0x01)
#define RTC_MONTH_FEBRUARY              ((uint8_t)0x02)
#define RTC_MONTH_MARCH                 ((uint8_t)0x03)
#define RTC_MONTH_APRIL                 ((uint8_t)0x04)
#define RTC_MONTH_MAY                   ((uint8_t)0x05)
#define RTC_MONTH_JUNE                  ((uint8_t)0x06)
#define RTC_MONTH_JULY                  ((uint8_t)0x07)
#define RTC_MONTH_AUGUST                ((uint8_t)0x08)
#define RTC_MONTH_SEPTEMBER             ((uint8_t)0x09)
#define RTC_MONTH_OCTOBER               ((uint8_t)0x0A)
#define RTC_MONTH_NOVEMBER              ((uint8_t)0x0B)
#define RTC_MONTH_DECEMBER              ((uint8_t)0x0C)
/**
 * @}
 */

/**
 * @defgroup RTC_Weekday RTC Weekday
 * @{
 */
#define RTC_WEEKDAY_SUNDAY              ((uint8_t)0x00)
#define RTC_WEEKDAY_MONDAY              ((uint8_t)0x01)
#define RTC_WEEKDAY_TUESDAY             ((uint8_t)0x02)
#define RTC_WEEKDAY_WEDNESDAY           ((uint8_t)0x03)
#define RTC_WEEKDAY_THURSDAY            ((uint8_t)0x04)
#define RTC_WEEKDAY_FRIDAY              ((uint8_t)0x05)
#define RTC_WEEKDAY_SATURDAY            ((uint8_t)0x06)
/**
 * @}
 */

/**
 * @defgroup RTC_Alarm_Weekday RTC Alarm Weekday
 * @{
 */
#define RTC_ALARM_WEEKDAY_SUNDAY        ((uint8_t)RTC_ALMWEEK_ALMWEEK_0)
#define RTC_ALARM_WEEKDAY_MONDAY        ((uint8_t)RTC_ALMWEEK_ALMWEEK_1)
#define RTC_ALARM_WEEKDAY_TUESDAY       ((uint8_t)RTC_ALMWEEK_ALMWEEK_2)
#define RTC_ALARM_WEEKDAY_WEDNESDAY     ((uint8_t)RTC_ALMWEEK_ALMWEEK_3)
#define RTC_ALARM_WEEKDAY_THURSDAY      ((uint8_t)RTC_ALMWEEK_ALMWEEK_4)
#define RTC_ALARM_WEEKDAY_FRIDAY        ((uint8_t)RTC_ALMWEEK_ALMWEEK_5)
#define RTC_ALARM_WEEKDAY_SATURDAY      ((uint8_t)RTC_ALMWEEK_ALMWEEK_6)
/**
 * @}
 */

/**
 * @defgroup RTC_Flag RTC Flag
 * @{
 */
#define RTC_FLAG_PERIOD                 ((uint8_t)RTC_CR2_PRDF)
#define RTC_FLAG_ALARM                  ((uint8_t)RTC_CR2_ALMF)
#define RTC_FLAG_WAIT                   ((uint8_t)RTC_CR2_WAITF)
/**
 * @}
 */

/**
 * @defgroup RTC_Interrupt RTC Interrupt
 * @{
 */
#define RTC_INT_PERIOD                  ((uint8_t)RTC_CR2_PRDIE)
#define RTC_INT_ALARM                   ((uint8_t)RTC_CR2_ALMIE)
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
 * @addtogroup RTC_Global_Functions
 * @{
 */

/**
 * @brief  Enable or disable RTC count.
 * @param  [in] enNewSta                The function new state.
 *   @arg  This parameter can be: Enable or Disable.
 * @retval None
 */
__STATIC_INLINE void RTC_Cmd(en_functional_state_t enNewSta)
{
    bM0P_RTC->CR1_b.START = enNewSta;
}

/**
 * @brief  Enable or disable clock compensation.
 * @param  [in] enNewSta                The function new state.
 *   @arg  This parameter can be: Enable or Disable.
 * @retval None
 */
__STATIC_INLINE void RTC_ClkCompenCmd(en_functional_state_t enNewSta)
{
    bM0P_RTC->ERRCRH_b.COMPEN = enNewSta;
}

/**
* @brief  Enable or disable RTC 1HZ output.
* @param  [in] enNewSta                 The function new state.
*   @arg  This parameter can be: Enable or Disable.
* @retval None
*/
__STATIC_INLINE void RTC_OneHzOutputCmd(en_functional_state_t enNewSta)
{
    bM0P_RTC->CR1_b.ONEHZOE = enNewSta;
}

/* Initialization and configuration functions */
en_result_t RTC_DeInit(void);
en_result_t RTC_Init(const stc_rtc_init_t *pstcRtcInit);
en_result_t RTC_StructInit(stc_rtc_init_t *pstcRtcInit);
en_result_t RTC_EnterRwMode(void);
en_result_t RTC_ExitRwMode(void);
void RTC_PeriodIntConfig(uint8_t u8IntCond);
en_result_t RTC_LowPowerCheck(void);
void RTC_SetClkCompenValue(uint16_t u16CompenVal);

/* Date and time functions */
en_result_t RTC_SetDate(uint8_t u8Format, const stc_rtc_date_t *pstcRtcDate);
en_result_t RTC_DateStructInit(stc_rtc_date_t *pstcRtcDate);
en_result_t RTC_GetDate(uint8_t u8Format, stc_rtc_date_t *pstcRtcDate);
en_result_t RTC_SetTime(uint8_t u8Format, const stc_rtc_time_t *pstcRtcTime);
en_result_t RTC_TimeStructInit(stc_rtc_time_t *pstcRtcTime);
en_result_t RTC_GetTime(uint8_t u8Format, stc_rtc_time_t *pstcRtcTime);

/* Alarm configuration functions */
en_result_t RTC_SetAlarm(uint8_t u8Format, const stc_rtc_alarm_t *pstcRtcAlarm);
en_result_t RTC_AlarmStructInit(stc_rtc_alarm_t *pstcRtcAlarm);
en_result_t RTC_GetAlarm(uint8_t u8Format, stc_rtc_alarm_t *pstcRtcAlarm);
void RTC_AlarmCmd(en_functional_state_t enNewSta);

/* Interrupts and flags management functions */
void RTC_IntCmd(uint8_t u8IntSource, en_functional_state_t enNewSta);
en_flag_status_t RTC_GetFlag(uint8_t u8Flag);
void RTC_ClearFlag(uint8_t u8Flag);
en_flag_status_t RTC_GetIntFlag(uint8_t u8IntFlag);
void RTC_ClearIntFlag(uint8_t u8IntFlag);

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

#ifdef __cplusplus
}
#endif

#endif /* __HC32F120_RTC_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
