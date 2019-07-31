/**
 *******************************************************************************
 * @file  timerb/timerb_output_compare/source/main.c
 * @brief This example demonstrates TIMERB output compare function.
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
 * @addtogroup TIMERB_Output_Compare
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* TIMERB unit & interrupt number & counter period/compare value definition */
#define TIMERB_ODD_UNIT                 M0P_TMRB1
#define TIMERB_ODD_UNIT_CMP_INT         INT_TMRB_1_CMP
#define TIMERB_ODD_UNIT_CMP_IRQn        Int022_IRQn
#define TIMERB_ODD_UNIT_PERIOD_VALUE    (SystemCoreClock/512)
#define TIMERB_ODD_UNIT_COMPARE_VALUE   (TIMERB_ODD_UNIT_PERIOD_VALUE/2)

#define TIMERB_EVEN_UNIT                M0P_TMRB2
#define TIMERB_EVEN_UNIT_CMP_INT        INT_TMRB_2_CMP
#define TIMERB_EVEN_UNIT_CMP_IRQn       Int020_IRQn
#define TIMERB_EVEN_UNIT_PERIOD_VALUE   TIMERB_ODD_UNIT_PERIOD_VALUE
#define TIMERB_EVEN_UNIT_COMPARE_VALUE  (TIMERB_EVEN_UNIT_PERIOD_VALUE/2)

/* TIMERB TIMB_t_PWM1 Port/Pin definition */
#define TIMERB_ODD_UNIT_PWM1_PORT       GPIO_PORT_14    /* P146: TIMB_1_PWM1_D */
#define TIMERB_ODD_UNIT_PWM1_PIN        GPIO_PIN_6

#define TIMERB_EVEN_UNIT_PWM1_PORT      GPIO_PORT_1     /* P16: TIMB_2_PWM1_A */
#define TIMERB_EVEN_UNIT_PWM1_PIN       GPIO_PIN_6

/* Function clock gate definition  */
#define FUNCTION_CLK_GATE               (CLK_FCG_TIMB1 | CLK_FCG_TIMB2)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
static void SystemClockConfig(void);
static void TimerbOddUnitCmpIrqCallback(void);
static void TimerbEvenUnitCmpIrqCallback(void);

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static stc_timerb_init_t m_stcTimerbInit = {
    .u16CntDir = TIMERB_CNT_UP,
    .u16ClkDiv = TIMERB_CLKDIV_DIV512,
    .u16CntMode = TIMERB_SAWTOOTH_WAVE,
    .u16OverflowAction = TIMERB_OVERFLOW_COUNT,
    .u16SynStartState = TIMERB_SYNC_START_ENABLE,
};

static stc_timerb_oc_init_t m_stcTimerbOddUnitOcInit = {
    .u16PortOutputState = TIMERB_OC_PORT_OUTPUT_ENABLE,
    .u16StartCntOutput = TIMERB_OC_STARTCNT_OUTPUT_HIGH,
    .u16StopCntOutput = TIMERB_OC_STOPCNT_OUTPUT_HIGH,
    .u16CompareMatchOutput = TIMERB_OC_CMPMATCH_OUTPUT_INVERTED,
    .u16PeriodMatchOutput = TIMERB_OC_PERIODMATCH_OUTPUT_HOLD,
};

static stc_timerb_oc_init_t m_stcTimerbEvenUnitOcInit = {
    .u16PortOutputState = TIMERB_OC_PORT_OUTPUT_ENABLE,
    .u16StartCntOutput = TIMERB_OC_STARTCNT_OUTPUT_HIGH,
    .u16StopCntOutput = TIMERB_OC_STOPCNT_OUTPUT_HIGH,
    .u16CompareMatchOutput = TIMERB_OC_CMPMATCH_OUTPUT_INVERTED,
    .u16PeriodMatchOutput = TIMERB_OC_PERIODMATCH_OUTPUT_HOLD,
};

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

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
 * @brief  TIMERB odd unit compare match IRQ callback.
 * @param  None
 * @retval None
 */
static void TimerbOddUnitCmpIrqCallback(void)
{
    TIMERB_ClearFlag(TIMERB_ODD_UNIT, TIMERB_FLAG_CMP);
}

/**
 * @brief  TIMERB even unit compare match IRQ callback
 * @param  None
 * @retval None
 */
static void TimerbEvenUnitCmpIrqCallback(void)
{
    TIMERB_ClearFlag(TIMERB_EVEN_UNIT, TIMERB_FLAG_CMP);
}

/**
 * @brief  Main function of TIMERB output compare project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_irq_regi_config_t stcIrqRegiConf;

    /* Configure system clock. */
    SystemClockConfig();

    /* Configure TIM_<t>_PWM1. */
    GPIO_SetFunc(TIMERB_ODD_UNIT_PWM1_PORT, TIMERB_ODD_UNIT_PWM1_PIN, GPIO_FUNC_TIMB);
    GPIO_SetFunc(TIMERB_EVEN_UNIT_PWM1_PORT, TIMERB_EVEN_UNIT_PWM1_PIN, GPIO_FUNC_TIMB);

    /* Enable peripheral clock */
    CLK_FcgPeriphClockCmd(FUNCTION_CLK_GATE, Enable);

    /* Initialize TIMERB odd unit. */
    m_stcTimerbInit.u16PeriodVal = TIMERB_ODD_UNIT_PERIOD_VALUE;
    TIMERB_Init(TIMERB_ODD_UNIT, &m_stcTimerbInit);

    /* Initialize TIMERB even unit output compare function . */
    m_stcTimerbOddUnitOcInit.u16CompareVal = TIMERB_ODD_UNIT_COMPARE_VALUE;
    TIMERB_OC_Init(TIMERB_ODD_UNIT, &m_stcTimerbOddUnitOcInit);
    TIMERB_IntCmd(TIMERB_ODD_UNIT, TIMERB_IT_CMP, Enable);

    /* Register IRQ handler && configure NVIC. */
    stcIrqRegiConf.enIRQn = TIMERB_ODD_UNIT_CMP_IRQn;
    stcIrqRegiConf.enIntSrc = TIMERB_ODD_UNIT_CMP_INT;
    stcIrqRegiConf.pfnCallback = TimerbOddUnitCmpIrqCallback;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Initialize TIMERB even unit. */
    m_stcTimerbInit.u16PeriodVal = TIMERB_EVEN_UNIT_PERIOD_VALUE;
    TIMERB_Init(TIMERB_EVEN_UNIT, &m_stcTimerbInit);

    /* Initialize TIMERB even unit output compare function . */
    m_stcTimerbEvenUnitOcInit.u16CompareVal = TIMERB_EVEN_UNIT_COMPARE_VALUE;
    TIMERB_OC_Init(TIMERB_EVEN_UNIT, &m_stcTimerbEvenUnitOcInit);
    TIMERB_IntCmd(TIMERB_EVEN_UNIT, TIMERB_IT_CMP, Enable);

    /* Register IRQ handler && configure NVIC. */
    stcIrqRegiConf.enIRQn = TIMERB_EVEN_UNIT_CMP_IRQn;
    stcIrqRegiConf.enIntSrc = TIMERB_EVEN_UNIT_CMP_INT;
    stcIrqRegiConf.pfnCallback = TimerbEvenUnitCmpIrqCallback;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Start TIMERB counter. */
    TIMERB_Start(TIMERB_ODD_UNIT);

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
