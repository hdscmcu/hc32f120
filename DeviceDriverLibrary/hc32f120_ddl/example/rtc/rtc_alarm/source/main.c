/**
 *******************************************************************************
 * @file  rtc/rtc_alarm/source/main.c
 * @brief Main program of RTC Alarm for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-04-18       Yangjp          First version
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
 * @addtogroup RTC_Alarm
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* LED_R Port/Pin definition */
#define LED_R_PORT                      (GPIO_PORT_2)
#define LED_R_PIN                       (GPIO_PIN_5)

#define LED_R_ON()                      (GPIO_ResetPins(LED_R_PORT, LED_R_PIN))
#define LED_R_OFF()                     (GPIO_SetPins(LED_R_PORT, LED_R_PIN))
#define LED_R_TOGGLE()                  (GPIO_TogglePins(LED_R_PORT, LED_R_PIN))

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static uint8_t u8SecIntFlag = 0u;
static uint8_t u8AlarmIntFlag = 0u, u8AlarmCnt = 0u;

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  RTC period interrupt callback function.
 * @param  None
 * @retval None
 */
static void RtcPeriod_IrqCallback(void)
{
    u8SecIntFlag = 1u;
    RTC_ClearIntFlag(RTC_FLAG_PERIOD);
}

/**
 * @brief  RTC alarm interrupt callback function.
 * @param  None
 * @retval None
 */
static void RtcAlarm_IrqCallback(void)
{
    u8AlarmCnt = 10u;
    u8AlarmIntFlag = 1u;
    RTC_ClearIntFlag(RTC_FLAG_ALARM);
}

/**
 * @brief  RTC calendar configuration.
 * @param  None
 * @retval None
 */
static void RTC_CalendarConfig(void)
{
    stc_rtc_date_t stcRtcDateCfg;
    stc_rtc_time_t stcRtcTimeCfg;

    /* Date configuration */
    stcRtcDateCfg.u8Year = 18u;
    stcRtcDateCfg.u8Month = 10u;
    stcRtcDateCfg.u8Day = 10u;
    stcRtcDateCfg.u8Weekday = RTC_WEEKDAY_WEDNESDAY;

    /* Time configuration */
    stcRtcTimeCfg.u8Hour = 11u;
    stcRtcTimeCfg.u8Minute = 59u;
    stcRtcTimeCfg.u8Second = 55u;
    stcRtcTimeCfg.u8AmPm = RTC_HOUR12_PM;

    if (RTC_SetDate(RTC_DATA_FORMAT_DEC, &stcRtcDateCfg) != Ok)
    {
        printf("Set Date failed!\r\n");
    }

    if (RTC_SetTime(RTC_DATA_FORMAT_DEC, &stcRtcTimeCfg) != Ok)
    {
        printf("Set Time failed!\r\n");
    }
}

/**
 * @brief  RTC display weekday.
 * @param  [in] u8Weekday               This parameter can be one of the following values:
 *   @arg  RTC_WEEKDAY_SUNDAY           Sunday
 *   @arg  RTC_WEEKDAY_MONDAY           Monday
 *   @arg  RTC_WEEKDAY_TUESDAY          Tuesday
 *   @arg  RTC_WEEKDAY_WEDNESDAY        Wednesday
 *   @arg  RTC_WEEKDAY_THURSDAY         Thursday
 *   @arg  RTC_WEEKDAY_FRIDAY           Friday
 *   @arg  RTC_WEEKDAY_SATURDAY         Saturday
 * @retval None
 */
static void RTC_DisplayWeekday(uint8_t u8Weekday)
{
    switch (u8Weekday)
    {
        case RTC_WEEKDAY_SUNDAY:
            printf("Sunday\r\n");
            break;
        case RTC_WEEKDAY_MONDAY:
            printf("Monday\r\n");
            break;
        case RTC_WEEKDAY_TUESDAY:
            printf("Tuesday\r\n");
            break;
        case RTC_WEEKDAY_WEDNESDAY:
            printf("Wednesday\r\n");
            break;
        case RTC_WEEKDAY_THURSDAY:
            printf("Thursday\r\n");
            break;
        case RTC_WEEKDAY_FRIDAY:
            printf("Friday\r\n");
            break;
        case RTC_WEEKDAY_SATURDAY:
            printf("Saturday\r\n");
            break;
        default:
            break;
    }
}

/**
 * @brief  RTC display date and time.
 * @param  [in] u8Format                Specifies the format of the entered parameters.
 *                                      This parameter can be one of the following values:
 *   @arg  RTC_DATA_FORMAT_DEC: Decimal data format
 *   @arg  RTC_DATA_FORMAT_BCD: BCD data format
 * @param  [in] pTitle                  Pointer to a title information of display.
 * @param  [in] pRtcDate                Pointer to a stc_rtc_date_t structure
 *                                      that contains date display information.
 * @param  [in] pRtcTime                Pointer to a stc_rtc_time_t structure
 *                                      that contains time display information.
 * @retval None
 *
 */
static void RTC_DisplayDataTime(uint8_t u8Format, char *pTitle, const stc_rtc_date_t *pRtcDate,
                                const stc_rtc_time_t *pRtcTime)
{
    if (RTC_DATA_FORMAT_BCD == u8Format)
    {
        printf("%s 20%02x/%02x/%02x %02x:%02x:%02x ", pTitle, pRtcDate->u8Year,
               pRtcDate->u8Month, pRtcDate->u8Day, pRtcTime->u8Hour,
               pRtcTime->u8Minute, pRtcTime->u8Second);
    }
    else
    {
        printf("%s 20%02d/%02d/%02d %02d:%02d:%02d ", pTitle, pRtcDate->u8Year,
               pRtcDate->u8Month, pRtcDate->u8Day, pRtcTime->u8Hour,
               pRtcTime->u8Minute, pRtcTime->u8Second);
    }

    if (pRtcTime->u8AmPm == RTC_HOUR12_AM)
    {
        printf("Am ");
    }
    else
    {
        printf("Pm ");
    }
    RTC_DisplayWeekday(pRtcDate->u8Weekday);
}

/**
 * @brief  RTC configuration.
 * @param  None
 * @retval None
 */
static void RTC_Config(void)
{
    uint8_t u8Ret;
    stc_rtc_init_t stcRtcInit;
    stc_rtc_alarm_t stcRtcAlarmCfg;
    stc_irq_regi_config_t stcIrqRegister;

    /* Enable peripheral clock */
    CLK_FcgPeriphClockCmd(CLK_FCG_RTC, Enable);

    /* Reset RTC counter */
    if (ErrorTimeout == RTC_DeInit())
    {
        printf("Reset RTC failed!\r\n");
    }
    else
    {
        /* Configuration RTC structure */
        stcRtcInit.u8ClockSource = RTC_CLOCK_SOURCE_XTAL32;
        stcRtcInit.u8HourFormat = RTC_HOUR_FORMAT_12;
        stcRtcInit.u8PeriodInterrupt = RTC_PERIOD_INT_ONE_SECOND;
        RTC_Init(&stcRtcInit);

        /* Configuration alarm clock time: Monday to Friday£¬PM 12:00 */
        stcRtcAlarmCfg.u8AlarmHour = 0x12u;
        stcRtcAlarmCfg.u8AlarmMinute = 0x00u;
        stcRtcAlarmCfg.u8AlarmWeekday = RTC_ALARM_WEEKDAY_MONDAY | RTC_ALARM_WEEKDAY_TUESDAY |
                                        RTC_ALARM_WEEKDAY_WEDNESDAY | RTC_ALARM_WEEKDAY_THURSDAY |
                                        RTC_ALARM_WEEKDAY_FRIDAY;
        stcRtcAlarmCfg.u8AlarmAmPm = RTC_HOUR12_AM;
        RTC_SetAlarm(RTC_DATA_FORMAT_BCD, &stcRtcAlarmCfg);
        RTC_AlarmCmd(Enable);

        /* Update date and time */
        RTC_CalendarConfig();

        /* Configure interrupt of RTC period */
        stcIrqRegister.enIntSrc = INT_RTC_PRD;
        stcIrqRegister.enIRQn = Int022_IRQn;
        stcIrqRegister.pfnCallback = &RtcPeriod_IrqCallback;
        u8Ret = INTC_IrqRegistration(&stcIrqRegister);
        if (Ok != u8Ret)
        {
            /* check parameter */
            while (1)
            {
            }
        }

        /* Clear pending */
        NVIC_ClearPendingIRQ(stcIrqRegister.enIRQn);
        /* Set priority */
        NVIC_SetPriority(stcIrqRegister.enIRQn, DDL_IRQ_PRIORITY_DEFAULT);
        /* Enable NVIC */
        NVIC_EnableIRQ(stcIrqRegister.enIRQn);

        /* Configure interrupt of RTC alarm */
        stcIrqRegister.enIntSrc = INT_RTC_ALM;
        stcIrqRegister.enIRQn = Int023_IRQn;
        stcIrqRegister.pfnCallback = &RtcAlarm_IrqCallback;
        u8Ret = INTC_IrqRegistration(&stcIrqRegister);
        if (Ok != u8Ret)
        {
            /* check parameter */
            while (1)
            {
            }
        }

        /* Clear pending */
        NVIC_ClearPendingIRQ(stcIrqRegister.enIRQn);
        /* Set priority */
        NVIC_SetPriority(stcIrqRegister.enIRQn, DDL_IRQ_PRIORITY_DEFAULT);
        /* Enable NVIC */
        NVIC_EnableIRQ(stcIrqRegister.enIRQn);

        /* Enable period and alarm interrupt */
        RTC_IntCmd(RTC_INT_PERIOD, Enable);
        RTC_IntCmd(RTC_INT_ALARM, Enable);

        /* Startup RTC count */
        RTC_Cmd(Enable);
    }
}

/**
 * @brief  System clock configuration.
 * @param  None
 * @retval None
 */
static void SystemClockConfig(void)
{
    stc_clk_xtal_init_t   stcXTALInit;
    stc_clk_xtal32_init_t stcXTAL32Init;

    /* Configure XTAL */
    stcXTALInit.u8XtalState = CLK_XTAL_ON;
    stcXTALInit.u8XtalMode = CLK_XTALMODE_OSC;
    stcXTALInit.u8XtalDrv = CLK_XTALDRV_HIGH;
    stcXTALInit.u8XtalSupDrv = CLK_XTAL_SUPDRV_OFF;
    stcXTALInit.u8XtalStb = CLK_XTALSTB_8;
    CLK_XTALInit(&stcXTALInit);
    /* Switch system clock from HRC(default) to XTAL */
    CLK_SetSysclkSrc(CLK_SYSCLKSOURCE_XTAL);

    /* Configure XTAL32 */
    stcXTAL32Init.u8Xtal32State = CLK_XTAL32_ON;
    stcXTAL32Init.u8Xtal32Drv = CLK_XTAL32DRV_HIGH;
    stcXTAL32Init.u8Xtal32SupDrv = CLK_XTAL32_SUPDRV_OFF;
    stcXTAL32Init.u8Xtal32NF = CLK_XTAL32NF_FULL;
    CLK_XTAL32Init(&stcXTAL32Init);
    /* Wait for xtal32 running */
    DDL_Delay1ms(3000u);
}

/**
 * @brief  Main function of RTC Alarm.
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_rtc_date_t stcCurrentDate;
    stc_rtc_time_t stcCurrentTime;

    /* Configure clock */
    SystemClockConfig();

    /* Configure structure initialization */
    GPIO_StructInit(&stcGpioInit);

    /* LED Port/Pin initialization */
    stcGpioInit.u16PinMode = PIN_MODE_OUT;
    GPIO_Init(LED_R_PORT, LED_R_PIN, &stcGpioInit);
    LED_R_OFF();

    /* Configure UART */
    DDL_UartInit();
    /* Configure RTC */
    RTC_Config();

    while (1)
    {
        if (1u == u8SecIntFlag)
        {
            u8SecIntFlag = 0u;
            /* Print alarm information */
            if ((1u == u8AlarmIntFlag) && (u8AlarmCnt > 0u))
            {
                /* Alarm LED flicker */
                LED_R_TOGGLE();
                u8AlarmCnt--;
                if (0u == u8AlarmCnt)
                {
                    u8AlarmIntFlag = 0u;
                    LED_R_OFF();
                }
                /* Get alarm date */
                if (Ok == RTC_GetDate(RTC_DATA_FORMAT_BCD, &stcCurrentDate))
                {
                    /* Get alarm time */
                    if (Ok == RTC_GetTime(RTC_DATA_FORMAT_BCD, &stcCurrentTime))
                    {
                        /* Print alarm date and time */
                        RTC_DisplayDataTime(RTC_DATA_FORMAT_BCD, "Alarm", &stcCurrentDate, &stcCurrentTime);
                    }
                    else
                    {
                        printf("Get alarm time failed!\r\n");
                    }
                }
                else
                {
                    printf("Get alarm date failed!\r\n");
                }
            }
            /* Print current date and time */
            else
            {
                /* Get current date */
                if (Ok == RTC_GetDate(RTC_DATA_FORMAT_DEC, &stcCurrentDate))
                {
                    /* Get current time */
                    if (Ok == RTC_GetTime(RTC_DATA_FORMAT_DEC, &stcCurrentTime))
                    {
                        /* Print current date and time */
                        RTC_DisplayDataTime(RTC_DATA_FORMAT_DEC, "Normal", &stcCurrentDate, &stcCurrentTime);
                    }
                    else
                    {
                        printf("Get time failed!\r\n");
                    }
                }
                else
                {
                    printf("Get date failed!\r\n");
                }
            }
        }
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
