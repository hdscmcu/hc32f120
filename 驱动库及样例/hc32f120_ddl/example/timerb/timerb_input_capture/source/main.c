/**
 *******************************************************************************
 * @file  timerb/timerb_input_capture/source/main.c
 * @brief This example demonstrates TIMERB input capture function.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-26       Hongjh          First version
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
 * @addtogroup TIMERB_Input_Capture
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/
/**
 * @brief  Buffer structure definition
 */
typedef struct
{
    uint16_t u16Capacity;
    uint16_t u16Index;
    uint16_t au16Buf[50];
} stc_buffer_t;

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* EXINT Port/Pin definition */
#define EXINT0_PORT                         GPIO_PORT_7
#define EXINT0_PIN                          GPIO_PIN_0

/* Green LED Port/Pin definition */
#define LED_G_PORT                          GPIO_PORT_2
#define LED_G_PIN                           GPIO_PIN_6
#define LED_G_ON()                          GPIO_ResetPins(LED_G_PORT, LED_G_PIN)

/* TIMERB input capture unit & interrupt number & counter period/compare value definition */
#define TIMERB_IC_ODD_UNIT                  M0P_TMRB1
#define TIMERB_IC_ODD_UNIT_CMP_INT          INT_TMRB_1_CMP
#define TIMERB_IC_ODD_UNIT_CMP_IRQn         Int022_IRQn
#define TIMERB_IC_ODD_UNIT_PERIOD_VALUE     TIMERB_OC_UNIT_PERIOD_VALUE

#define TIMERB_IC_EVEN_UNIT                 M0P_TMRB2
#define TIMERB_IC_EVEN_UNIT_CMP_INT         INT_TMRB_2_CMP
#define TIMERB_IC_EVEN_UNIT_CMP_IRQn        Int020_IRQn
#define TIMERB_IC_EVEN_UNIT_PERIOD_VALUE    TIMERB_OC_UNIT_PERIOD_VALUE

/* TIMERB output compare unit & counter period/compare value definition */
#define TIMERB_OC_UNIT                      M0P_TMRB3
#define TIMERB_OC_UNIT_PERIOD_VALUE         (SystemCoreClock/512)
#define TIMERB_OC_UNIT_COMPARE_VALUE        (TIMERB_OC_UNIT_PERIOD_VALUE/2)

/* TIMERB TIMB_t_PWM1 Port/Pin definition */
#define TIMERB_IC_ODD_UNIT_PWM1_PORT        GPIO_PORT_14    /* P146: TIMB_1_PWM1_D */
#define TIMERB_IC_ODD_UNIT_PWM1_PIN         GPIO_PIN_6

#define TIMERB_IC_EVEN_UNIT_PWM1_PORT       GPIO_PORT_1     /* P16: TIMB_2_PWM1_A */
#define TIMERB_IC_EVEN_UNIT_PWM1_PIN        GPIO_PIN_6

#define TIMERB_OC_UNIT_PWM1_PORT            GPIO_PORT_1     /* P17: TIMB_3_PWM1_A */
#define TIMERB_OC_UNIT_PWM1_PIN             GPIO_PIN_7

/* Function clock gate definition */
#define FUNCTION_CLK_GATE                   (CLK_FCG_TIMB1 | CLK_FCG_TIMB2 | CLK_FCG_TIMB3 | CLK_FCG_AOS)

/* Buffer size definition */
#define TIMERB_IC_CMPBUF_SIZE               (50)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
static void SystemClockConfig(void);
static void LedConfig(void);
static void TimerbOcConfig(void);
static void TimerbIcOddUnitCmpIrqCallback(void);
static void TimerbIcEvenUnitCmpIrqCallback(void);
static void BufferWrite(stc_buffer_t *pstcBuffer, uint16_t u16Data);

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static stc_buffer_t m_stcOddUnitCmpBuf = {
    .u16Index = 0u,
    .u16Capacity = TIMERB_IC_CMPBUF_SIZE,
};

static stc_buffer_t m_stcEvenUnitCmpBuf= {
    .u16Index = 0u,
    .u16Capacity = TIMERB_IC_CMPBUF_SIZE,
};

static stc_timerb_init_t m_stcTimerbInit = {
    .u16CntDir = TIMERB_CNT_UP,
    .u16ClkDiv = TIMERB_CLKDIV_DIV512,
    .u16CntMode = TIMERB_SAWTOOTH_WAVE,
    .u16OverflowAction = TIMERB_OVERFLOW_COUNT,
    .u16SynStartState = TIMERB_SYNC_START_DISABLE,
};

static stc_timerb_ic_init_t m_stcTimerbIcInit = {
    .u16CaptureCondition = TIMERB_IC_FALLING,
    .u16NoiseFilterClkDiv = TIMERB_IC_NOFICLKDIV_NONE,
};

static stc_timerb_oc_init_t m_stcTimerbOcInit = {
    .u16PortOutputState = TIMERB_OC_PORT_OUTPUT_ENABLE,
    .u16StartCntOutput = TIMERB_OC_STARTCNT_OUTPUT_HIGH,
    .u16StopCntOutput = TIMERB_OC_STOPCNT_OUTPUT_HIGH,
    .u16CompareMatchOutput = TIMERB_OC_CMPMATCH_OUTPUT_INVERTED,
    .u16PeriodMatchOutput = TIMERB_OC_PERIODMATCH_OUTPUT_INVERTED,
};

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 * @brief  Configure TIMERB output compare.
 * @param  None
 * @retval None
 */
static void TimerbOcConfig(void)
{
    /* Configure TIM_<t>_PWM1. */
    GPIO_SetFunc(TIMERB_OC_UNIT_PWM1_PORT, TIMERB_OC_UNIT_PWM1_PIN, GPIO_FUNC_TIMB);

    /* Initialize TIMERB unit. */
    m_stcTimerbInit.u16PeriodVal = TIMERB_OC_UNIT_PERIOD_VALUE;
    TIMERB_Init(TIMERB_OC_UNIT, &m_stcTimerbInit);

    /* Initialize TIMERB output compare function . */
    m_stcTimerbOcInit.u16CompareVal = TIMERB_OC_UNIT_COMPARE_VALUE;
    TIMERB_OC_Init(TIMERB_OC_UNIT, &m_stcTimerbOcInit);
}

/**
 * @brief  Configure system clock.
 * @param  None
 * @retval None
 */
static void SystemClockConfig(void)
{
    stc_clk_xtal_init_t stcXTALInit;

    /* Configure XTAL */
    stcXTALInit.u8XtalState = CLK_XTAL_ON;
    stcXTALInit.u8XtalMode = CLK_XTALMODE_OSC;
    stcXTALInit.u8XtalDrv = CLK_XTALDRV_HIGH;
    stcXTALInit.u8XtalSupDrv = CLK_XTAL_SUPDRV_OFF;
    stcXTALInit.u8XtalStb = CLK_XTALSTB_8;

    /* Initialize XTAL clock */
    CLK_XTALInit(&stcXTALInit);

    /* Switch system clock from HRC(default) to XTAL */
    CLK_SetSysclkSrc(CLK_SYSCLKSOURCE_XTAL);
}

/**
 * @brief  Configure RGB LED.
 * @param  None
 * @retval None
 */
static void LedConfig(void)
{
    stc_gpio_init_t stcGpioInit = {0};

    stcGpioInit.u16PinMode = PIN_MODE_OUT;
    stcGpioInit.u16PinState = PIN_STATE_SET;
    GPIO_Init(LED_G_PORT, LED_G_PIN, &stcGpioInit);
}

/**
 * @brief  TIMERB odd unit compare match IRQ callback.
 * @param  None
 * @retval None
 */
static void TimerbIcOddUnitCmpIrqCallback(void)
{
    BufferWrite(&m_stcOddUnitCmpBuf, TIMERB_GetCompare(TIMERB_IC_ODD_UNIT));
    TIMERB_ClearFlag(TIMERB_IC_ODD_UNIT, TIMERB_FLAG_CMP);
}

/**
 * @brief  TIMERB even unit compare match IRQ callback
 * @param  None
 * @retval None
 */
static void TimerbIcEvenUnitCmpIrqCallback(void)
{
    BufferWrite(&m_stcEvenUnitCmpBuf, TIMERB_GetCompare(TIMERB_IC_EVEN_UNIT));
    TIMERB_ClearFlag(TIMERB_IC_EVEN_UNIT, TIMERB_FLAG_CMP);
}

/**
 * @brief  External interrupt Ch.0 ISR
 * @param  None
 * @retval None
 */
void EXINT00_Handler(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH00))
   {
        EXINT_ClrSrc(EXINT_CH00);
        LED_G_ON();
   }
}

/**
 * @brief  Push data into buffer.
 * @param  [in] pstcBuffer              Pointer to a @ref stc_buffer_t structure
 * @param  [in] u16Data                 Data to write into buffer
 * @retval None
 */
static void BufferWrite(stc_buffer_t *pstcBuffer, uint16_t u16Data)
{
    if (pstcBuffer->u16Index > pstcBuffer->u16Capacity)
    {
        pstcBuffer->u16Index = 0;
    }

    pstcBuffer->au16Buf[pstcBuffer->u16Index++] = u16Data;
}
/**
 * @brief  Main function of TIMERB input capture project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_exint_config_t stcExIntInit;
    stc_irq_regi_config_t stcIrqRegiConf;

    /* Configure system clock. */
    SystemClockConfig();

    /* Configure RGB LED. */
    LedConfig();

    /* External interrupt Ch.0 initialize */
    GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(EXINT0_PORT, EXINT0_PIN, &stcGpioInit);

    /* EXINT Channel 0 (SW2) configure */
    EXINT_StructInit(&stcExIntInit);
    stcExIntInit.u16ExIntCh = EXINT_CH00;
    stcExIntInit.u8ExIntFE = EXINT_FILTER_ON;
    stcExIntInit.u8ExIntFClk = EXINT_FCLK_HCLK_DIV8;
    stcExIntInit.u8ExIntLvl = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* Configure NVIC */
    NVIC_ClearPendingIRQ(EXINT00_IRQn);
    NVIC_SetPriority(EXINT00_IRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(EXINT00_IRQn);

    /* Configure TIM_<t>_PWM1. */
    GPIO_SetFunc(TIMERB_IC_ODD_UNIT_PWM1_PORT, TIMERB_IC_ODD_UNIT_PWM1_PIN, GPIO_FUNC_TIMB);
    GPIO_SetFunc(TIMERB_IC_EVEN_UNIT_PWM1_PORT, TIMERB_IC_EVEN_UNIT_PWM1_PIN, GPIO_FUNC_TIMB);

    /* Enable peripheral clock */
    CLK_FcgPeriphClockCmd(FUNCTION_CLK_GATE, Enable);

    /* Configure TIMERB output compare function. */
    TimerbOcConfig();

    /* Initialize TIMERB odd unit. */
    m_stcTimerbInit.u16PeriodVal = TIMERB_IC_ODD_UNIT_PERIOD_VALUE;
    TIMERB_Init(TIMERB_IC_ODD_UNIT, &m_stcTimerbInit);

    /* Initialize TIMERB even unit input capture function. */
    TIMERB_IC_Init(TIMERB_IC_ODD_UNIT, &m_stcTimerbIcInit);
    TIMERB_IntCmd(TIMERB_IC_ODD_UNIT, TIMERB_IT_CMP, Enable);

    /* Register IRQ handler && configure NVIC. */
    stcIrqRegiConf.enIRQn = TIMERB_IC_ODD_UNIT_CMP_IRQn;
    stcIrqRegiConf.enIntSrc = TIMERB_IC_ODD_UNIT_CMP_INT;
    stcIrqRegiConf.pfnCallback = TimerbIcOddUnitCmpIrqCallback;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Initialize TIMERB even unit. */
    m_stcTimerbInit.u16PeriodVal = TIMERB_IC_EVEN_UNIT_PERIOD_VALUE;
    TIMERB_Init(TIMERB_IC_EVEN_UNIT, &m_stcTimerbInit);

    /* Initialize TIMERB even unit input capture function . */
    TIMERB_IC_Init(TIMERB_IC_EVEN_UNIT, &m_stcTimerbIcInit);
    TIMERB_IntCmd(TIMERB_IC_EVEN_UNIT, TIMERB_IT_CMP, Enable);

    /* Register IRQ handler && configure NVIC. */
    stcIrqRegiConf.enIRQn = TIMERB_IC_EVEN_UNIT_CMP_IRQn;
    stcIrqRegiConf.enIntSrc = TIMERB_IC_EVEN_UNIT_CMP_INT;
    stcIrqRegiConf.pfnCallback = TimerbIcEvenUnitCmpIrqCallback;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Set trigger source. */
    TIMERB_SetTriggerSrc(EVT_PORT_EIRQ0);

    /* Start TIMERB start count condition. */
    TIMERB_SetHwStartCondition(TIMERB_OC_UNIT, TIMERB_HWSTART_TIMB_EVT);
    TIMERB_SetHwStartCondition(TIMERB_IC_ODD_UNIT, TIMERB_HWSTART_TIMB_EVT);
    TIMERB_SetHwStartCondition(TIMERB_IC_EVEN_UNIT, TIMERB_HWSTART_TIMB_EVT);

    while (1)
    {
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
