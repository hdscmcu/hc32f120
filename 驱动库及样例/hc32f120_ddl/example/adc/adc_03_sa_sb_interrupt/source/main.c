/**
 *******************************************************************************
 * @file  adc/adc_03_sa_sb_interrupt/source/main.c
 * @brief Main program of ADC interrupt for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-20       Wuze            First version
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
 * @addtogroup ADC_Interrupt
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* Enable ADC peripheral. */
#define ENABLE_ADC()                CLK_FcgPeriphClockCmd(CLK_FCG_ADC, Enable)

/* Disable ADC peripheral. */
#define DISABLE_ADC()               CLK_FcgPeriphClockCmd(CLK_FCG_ADC, Disable)

/* Enable AOS. */
#define ENABLE_AOS()                CLK_FcgPeriphClockCmd(CLK_FCG_AOS, Enable)

/* Disable ADC. */
#define DISABLE_AOS()               CLK_FcgPeriphClockCmd(CLK_FCG_AOS, Disable)

/* ADC channels definition for this example. */
#define ADC_SA_CHANNEL              (ADC_CH0 | ADC_CH11)
#define ADC_SA_CHANNEL_COUNT        (2u)

#define ADC_SB_CHANNEL              (ADC_CH2 | ADC_CH4)
#define ADC_SB_CHANNEL_COUNT        (2u)

/* ADC channel sampling time. */
#define ADC_SAMPLE_TIME             ((uint8_t)10)

/* ADC resolution definition. */
#define ADC_RESOLUTION              ADC_RESOLUTION_12B

/* ADC accuracy. */
#define ADC_ACCURACY                (1ul << 12u)

/* ADC reference voltage. The voltage of pin VREFH. */
#define ADC_VREF                    (3.29f)

/* ADC interrupt flag bit mask definition. */
#define ADC_SA_IRQ_BIT              ADC_FLAG_EOCA
#define ADC_SB_IRQ_BIT              ADC_FLAG_EOCB

/* Share interrupt definition. */
#define SHARE_INTERRUPT

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
static void AdcConfig(void);
static void AdcClockConfig(void);
static void AdcInitConfig(void);
static void AdcChannelConfig(void);
static void AdcTriggerConfig(void);
static void AdcIrqConfig(void);

void AdcSeqA_IrqHandler(void);
void AdcSeqB_IrqHandler(void);

static void AdcSetChannelPinAnalogMode(uint16_t u16Channel);
static void AdcSetPinAnalogMode(uint8_t u8PinNbr);

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static uint32_t m_u32AdcIrqFlag = 0u;
static uint16_t m_au16AdcSaVal[ADC_SA_CHANNEL_COUNT];
static uint16_t m_au16AdcSbVal[ADC_SB_CHANNEL_COUNT];

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 * @brief  Main function of adc_03_sa_sb_interrupt project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    /* 1. The system clock is set to HRC8HMz by default.
       2. Pull down the pin P10 or call the function ADC_Start to start sequence A, 
          then sequence B will be triggered by EOCA(End Of Conversion of sequence A). */

    /* Configures ADC. */
    AdcConfig();

    /***************** Configuration end, application start **************/

    while (1u)
    {
        /* Check ADC SA. */
        if (m_u32AdcIrqFlag & ADC_SA_IRQ_BIT)
        {
            m_u32AdcIrqFlag &= ~ADC_SA_IRQ_BIT;
            // TODO: Your service code.
        }

        /* Check ADC SB. */
        if (m_u32AdcIrqFlag & ADC_SB_IRQ_BIT)
        {
            m_u32AdcIrqFlag &= ~ADC_SB_IRQ_BIT;
            // TODO: Your service code.
        }
    }
}

/**
 * @brief  ADC configuration, including clock configuration, initial configuration,
 *         channel configuration, trigger source configuration and interrupt
 *         configuration.
 * @param  None
 * @retval None
 */
static void AdcConfig(void)
{
    AdcClockConfig();
    AdcInitConfig();
    AdcChannelConfig();
    AdcTriggerConfig();
    AdcIrqConfig();
}

/**
 * @brief  Configures ADC clock.
 *         The clock of ADC: HRC8MHz / 1 = 8MHz.
 * @param  None
 * @retval None
 */
static void AdcClockConfig(void)
{
    CLK_SetADClkDiv(CLK_HCLK_DIV1);
}
/**
 * @brief  Initializes ADC.
 * @param  None
 * @retval None
 */
static void AdcInitConfig(void)
{
    stc_adc_init_t stcInit;

    /* Set a default value. */
    ADC_StructInit(&stcInit);

    /* User configurations. */
    stcInit.u16ScanConvMode = ADC_MODE_SA_SB_SINGLE;
    stcInit.u16Resolution   = ADC_RESOLUTION;
    stcInit.u8SampTime      = ADC_SAMPLE_TIME;

    /* 1. Enable ADC peripheral. */
    ENABLE_ADC();

    /* 2. Initializes ADC. */
    ADC_Init(&stcInit);
}

/**
 * @brief  Configures ADC channel(s).
 * @param  None
 * @retval None
 */
static void AdcChannelConfig(void)
{
    /* 1. Set the ADC pin to analog mode. */
    AdcSetChannelPinAnalogMode(ADC_SA_CHANNEL | ADC_SB_CHANNEL);

    /* 2. Add ADC sequence A channels. */
    ADC_AddAdcChannel(ADC_SEQ_A, ADC_SA_CHANNEL);

    /* 3. Add ADC sequence B channels. */
    ADC_AddAdcChannel(ADC_SEQ_B, ADC_SB_CHANNEL);
}

/**
 * @brief  Configures ADC trigger source.
 * @note   Sequence A and sequence B are not recommended to be set to the same trigger source.
 * @param  None
 * @retval None
 */
static void AdcTriggerConfig(void)
{
    uint8_t u8Seq;
    stc_adc_trg_cfg_t stcTrgCfg;

    /* Set a default value for stcTrgCfg.  */
    ADC_TriggerSrcStructInit(&stcTrgCfg);

    /* Configrues sequence A's trigger source.
       Sets the external pin ADTRGA(pin P10) as the trigger source for sequence A.
       ADTRGA from high to low and stays low 1.5 * 4 cycles of HCLK or more will
       trigger sequence A conversion. Although sequence A sets the trigger source,
       the software startup is still valid. 
       Pin ADTRGB(P50) and pin ADTRGC(P60) can also be configured as the trigger
       source of the ADC. */
    u8Seq = ADC_SEQ_A;
    stcTrgCfg.u16TrgSrc = ADC_TRGSRC_EX_PIN;

    /* 1. Configures the function of pin ADTRGA. */
    GPIO_SetFunc(GPIO_PORT_1, GPIO_PIN_0, GPIO_FUNC_ADTRG);
    /* 2. Configrues the trigger source of sequence A. */
    ADC_ConfigTriggerSrc(u8Seq, &stcTrgCfg);
    /* 3. Enable the trigger source. */
    ADC_TriggerSrcCmd(u8Seq, Enable);

    /* Configrues sequence B's trigger source.
       Set EOCA(End Of Conversion of sequence A) as the trigger source of sequence B.
       Sequence B can only be started by the trigger source. */
    u8Seq = ADC_SEQ_B;
    /* The trigger source of sequence B is not recommended to be set to ADC_TRGSRC_EX_PIN at here. */
    stcTrgCfg.u16TrgSrc = ADC_TRGSRC_IN_EVT0;
    stcTrgCfg.u32Event0 = EVT_ADC_EOCA;
    /* 1. Enable AOS */
    ENABLE_AOS();
    /* 2. Configrues the trigger source of sequence B. */
    ADC_ConfigTriggerSrc(u8Seq, &stcTrgCfg);
    /* 3. Enable the trigger source. */
    ADC_TriggerSrcCmd(u8Seq, Enable);
}

/**
 * @brief  ADC interrupt configuration.
 * @param  None
 * @retval None
 * @note   All ADC interrupts can be configured as independent interrupt or shared interrupt.
 *         INT_ADC_EOCA: Sequence A conversion end interrupt.
 *                       Independent vec[Int016_IRQn, Int017_IRQn]
 *                       Share vec [Int028_IRQn]
 *         INT_ADC_EOCB: Sequence B conversion end interrupt.
 *                       Independent vec[Int018_IRQn, Int019_IRQn]
 *                       Share vec[Int029_IRQn]
 *         INT_ADC_CMP0: Analog watchdog 0 interrupt.
 *                       Independent vec[Int020_IRQn, Int021_IRQn]
 *                       Share vec[Int030_IRQn]
 *         INT_ADC_CMP1: Analog watchdog 1 interrupt.
 *                       Independent vec[Int022_IRQn, Int023_IRQn]
 *                       Share vec[Int031_IRQn]
 */
static void AdcIrqConfig(void)
{
    stc_irq_regi_config_t stcIrqRegiConf;

    /* Configures EOCA(End Of Conversion of sequence A) interrupt.
       The following 2 configurations of interrupt are both valid. */
#ifdef SHARE_INTERRUPT
    /* Share interrupt. */
    stcIrqRegiConf.enIntSrc    = INT_ADC_EOCA;
    stcIrqRegiConf.enIRQn      = Int028_IRQn;
    INTC_ShareIrqCmd(stcIrqRegiConf.enIntSrc, Enable);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_02);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);
#else
    /* Independent interrupt. */
    stcIrqRegiConf.enIntSrc    = INT_ADC_EOCA;
    stcIrqRegiConf.enIRQn      = Int016_IRQn;
    stcIrqRegiConf.pfnCallback = AdcSeqA_IrqHandler;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_02);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);
#endif // #ifdef SHARE_INTERRUPT

    /* Configures EOCB(End Of Conversion of sequence B) interrupt. */
    stcIrqRegiConf.enIntSrc    = INT_ADC_EOCB;
    stcIrqRegiConf.enIRQn      = Int018_IRQn;
    stcIrqRegiConf.pfnCallback = AdcSeqB_IrqHandler;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Enable the interrupts. */
    ADC_AdcIntCmd(ADC_SEQ_A, Enable);
    ADC_AdcIntCmd(ADC_SEQ_B, Enable);
}

/**
 * @brief  ADC sequence A IRQ callback.
 * @param  None
 * @retval None
 */
void AdcSeqA_IrqHandler(void)
{
    if (ADC_GetEocFlag(ADC_FLAG_EOCA) == Set)
    {
        ADC_GetSeqData(ADC_SEQ_A, (uint16_t *)&m_au16AdcSaVal[0u]);
        ADC_ClrEocFlag(ADC_FLAG_EOCA);
        m_u32AdcIrqFlag |= ADC_SA_IRQ_BIT;
    }
}

/**
 * @brief  ADC sequence B IRQ callback.
 * @param  None
 * @retval None
 */
void AdcSeqB_IrqHandler(void)
{
    if (ADC_GetEocFlag(ADC_FLAG_EOCB) == Set)
    {
        ADC_GetSeqData(ADC_SEQ_B, (uint16_t *)&m_au16AdcSbVal[0u]);
        ADC_ClrEocFlag(ADC_FLAG_EOCB);
        m_u32AdcIrqFlag |= ADC_SB_IRQ_BIT;
    }
}

/**
 * @brief  Set the pin(s) corresponding to the specified channel(s) to analog mode.
 * @param  [in]  u16Channel         The specified channel(s).
 * @retval None
 */
static void AdcSetChannelPinAnalogMode(uint16_t u16Channel)
{
    uint8_t u8PinNbr;

    u8PinNbr    = 0u;
    u16Channel &= ADC_CH_ALL;

    while (u16Channel != 0u)
    {
        if (u16Channel & 0x1u)
        {
            AdcSetPinAnalogMode(u8PinNbr);
        }

        u16Channel >>= 1u;
        u8PinNbr++;
    }
}

/**
 * @brief  Set specified ADC pin to analog mode.
 * @param  [in]  u8PinNbr           The ADC pin number.
 *                                  This parameter can be a value of @ref ADC_Pin_Number
 * @retval None
 */
static void AdcSetPinAnalogMode(uint8_t u8PinNbr)
{
    uint8_t u8Port;
    uint8_t u8Pin;

    switch (u8PinNbr)
    {
    case ADC_ANI0:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_0;
        break;

    case ADC_ANI1:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_1;
        break;

    case ADC_ANI2:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_2;
        break;

    case ADC_ANI3:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_3;
        break;

    case ADC_ANI4:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_4;
        break;

    case ADC_ANI5:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_5;
        break;

    case ADC_ANI6:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_6;
        break;

    case ADC_ANI7:
        u8Port = GPIO_PORT_2;
        u8Pin  = GPIO_PIN_7;
        break;

    case ADC_ANI8:
        u8Port = GPIO_PORT_14;
        u8Pin  = GPIO_PIN_7;
        break;

    case ADC_ANI9:
        u8Port = GPIO_PORT_0;
        u8Pin  = GPIO_PIN_0;
        break;

    case ADC_ANI10:
        u8Port = GPIO_PORT_0;
        u8Pin  = GPIO_PIN_1;
        break;

    case ADC_ANI11:
        u8Port = GPIO_PORT_12;
        u8Pin  = GPIO_PIN_0;
        break;

    default:
        return;
    }

    GPIO_SetFunc(u8Port, u8Pin, GPIO_FUNC_ANIN);
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
