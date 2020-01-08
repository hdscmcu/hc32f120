/**
 *******************************************************************************
 * @file  adc/adc_06_awd_interrupt/source/main.c
 * @brief Main program of ADC AWD interrupt for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-03-20       Wuze            First version
   2020-01-08       Wuze            Modified the type of 'u32Event0' in structure stc_adc_trg_cfg_t,
                                    from 'uint32 enEvent0' to 'en_event_src_t enEvent0'. Same with 'u32Event1'.
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
 * @addtogroup ADC_AWD_Interrupt
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* ADC channels definition for this example. */
#define AWD0_PIN                    (ADC_ANI11)
#define AWD1_PIN                    (ADC_ANI2)
#define AWD0_CH                     ((uint16_t)(1ul << AWD0_PIN))
#define AWD1_CH                     ((uint16_t)(1ul << AWD1_PIN))

/* The channels of AWD0 and AWD1 can be configured in the same sequence.
   AWD0 and AWD1 can also be configured with the same channel.  */
#define ADC_SA_CHANNEL              (ADC_CH0 | AWD0_CH)
#define ADC_SA_CHANNEL_COUNT        (2u)

#define ADC_SB_CHANNEL              (AWD1_CH | ADC_CH4)
#define ADC_SB_CHANNEL_COUNT        (2u)

/* AWD definition for this example. */
#define USE_AWD0                    (1u)
#define ADW0_MD                     (ADC_AWD_CMP_IN_RANGE)
#define AWD0_DR0_LOWER              ((uint16_t)1000)
#define AWD0_DR1_UPPER              ((uint16_t)4000)

#define USE_AWD1                    (1u)
#define ADW1_MD                     (ADC_AWD_CMP_IN_RANGE)
#define AWD1_DR0_LOWER              ((uint16_t)3000)
#define AWD1_DR1_UPPER              ((uint16_t)4000)

#if (USE_AWD0 && USE_AWD1)
#define AWD_COMBINATION_MODE        (ADC_AWD_COMB_OR)
#endif // (USE_AWD0 && USE_AWD1)

/* ADC channel sampling time. */
#define ADC_SAMPLE_TIME             ((uint8_t)10)

/* ADC resolution definition. */
#define ADC_RESOLUTION              (ADC_RESOLUTION_12B)

/* ADC accuracy. */
#define ADC_ACCURACY                (1ul << 12u)

/* ADC reference voltage. The voltage of pin VREFH. */
#define ADC_VREF                    (3.29f)

/* ADC interrupt flag bit mask definition. */
#define ADC_AWD0_IRQ_BIT            (ADC_FLAG_AWD0)
#define ADC_AWD1_IRQ_BIT            (ADC_FLAG_AWD1)

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

static void AdcSetChannelPinAnalogMode(uint16_t u16Channel);
static void AdcSetPinAnalogMode(uint8_t u8PinNbr);

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static uint8_t m_u8AdcIrqFlag = 0u;

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 * @brief  Main function of adc_06_awd_interrupt project
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
        /* Check ADC AWD0. */
        if (m_u8AdcIrqFlag & ADC_AWD0_IRQ_BIT)
        {
            m_u8AdcIrqFlag &= (uint8_t)(~ADC_AWD0_IRQ_BIT);
            // TODO: Your service code.
        }

        /* Check ADC AWD1. */
        if (m_u8AdcIrqFlag & ADC_AWD1_IRQ_BIT)
        {
            m_u8AdcIrqFlag &= (uint8_t)(~ADC_AWD1_IRQ_BIT);
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
 *         The clock of ADC: HRC8MHz / 2 = 4MHz.
 * @param  None
 * @retval None
 */
static void AdcClockConfig(void)
{
    CLK_SetADClkDiv(CLK_HCLK_DIV2);
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
    CLK_FcgPeriphClockCmd(CLK_FCG_ADC, Enable);

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
    uint8_t u8AwdNbr;
    stc_awd_cfg_t stcAwdCfg;

    /* 1. Set the ADC pin to analog mode. */
    AdcSetChannelPinAnalogMode(ADC_SA_CHANNEL | ADC_SB_CHANNEL);

    /* 2. Add ADC sequence A channels. */
    ADC_AddAdcChannel(ADC_SEQ_A, ADC_SA_CHANNEL);

    /* 3. Add ADC sequence B channels. */
    ADC_AddAdcChannel(ADC_SEQ_B, ADC_SB_CHANNEL);

    /* 4. Configrues AWD. */
    u8AwdNbr = ADC_AWD_0;
    stcAwdCfg.u8AdcPin = AWD0_PIN;
    stcAwdCfg.u16AwdMd = ADW0_MD;
    stcAwdCfg.u16Dr0   = AWD0_DR0_LOWER;
    stcAwdCfg.u16Dr1   = AWD0_DR1_UPPER;
    ADC_AwdConfig(u8AwdNbr, &stcAwdCfg);

    u8AwdNbr = ADC_AWD_1;
    stcAwdCfg.u8AdcPin = AWD1_PIN;
    stcAwdCfg.u16AwdMd = ADW1_MD;
    stcAwdCfg.u16Dr0   = AWD1_DR0_LOWER;
    stcAwdCfg.u16Dr1   = AWD1_DR1_UPPER;
    ADC_AwdConfig(u8AwdNbr, &stcAwdCfg);

#ifdef AWD_COMBINATION_MODE
    /* If combination mode is valid(ADC_AWD_COMB_OR/ADC_AWD_COMB_AND/ADC_AWD_COMB_XOR) and
       the channles selected by the AWD0 and AWD1 are deferent, make sure that the channel
       of AWD1 is converted after the channel conversion of AWD0 ends. */
    ADC_AwdConfigCombMode(AWD_COMBINATION_MODE);
#endif

    ADC_AwdCmd(ADC_AWD_0, Enable);
    ADC_AwdCmd(ADC_AWD_1, Enable);
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
       the software startup is still valid. */
    u8Seq = ADC_SEQ_A;
    stcTrgCfg.u16TrgSrc = ADC_TRGSRC_EX_PIN;

    /* 1. Configures the function of pin ADTRGA's. */
    GPIO_SetFunc(GPIO_PORT_1, GPIO_PIN_0, GPIO_FUNC_1_ADTRG);
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
    stcTrgCfg.enEvent0  = EVT_ADC_EOCA;
    /* 1. Enable AOS. */
    CLK_FcgPeriphClockCmd(CLK_FCG_AOS, Enable);
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

    /* Configures AWD0 interrupt.
       The following 2 configurations of interrupt are both valid. */
#ifdef SHARE_INTERRUPT
    /* Share interrupt. */
    stcIrqRegiConf.enIntSrc    = INT_ADC_CMP0;
    stcIrqRegiConf.enIRQn      = Int030_IRQn;
    INTC_ShareIrqCmd(stcIrqRegiConf.enIntSrc, Enable);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_02);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);
#else
    /* Independent interrupt. */
    stcIrqRegiConf.enIntSrc    = INT_ADC_CMP0;
    stcIrqRegiConf.enIRQn      = Int020_IRQn;
    stcIrqRegiConf.pfnCallback = &AdcCmp0_IrqHandler;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_02);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);
#endif // #ifdef SHARE_INTERRUPT

    /* Configures AWD1 interrupt. */
    stcIrqRegiConf.enIntSrc    = INT_ADC_CMP1;
    stcIrqRegiConf.enIRQn      = Int022_IRQn;
    stcIrqRegiConf.pfnCallback = &AdcCmp1_IrqHandler;
    INTC_IrqRegistration(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Enable the interrupts. */
    ADC_AwdIntCmd(ADC_AWD_0, Enable);
    ADC_AwdIntCmd(ADC_AWD_1, Enable);
}

/**
 * @brief  ADC AWD0 IRQ callback.
 * @param  None
 * @retval None
 */
void AdcCmp0_IrqHandler(void)
{
    if (ADC_AwdGetFlag(ADC_FLAG_AWD0) == Set)
    {
        ADC_AwdClrFlag(ADC_FLAG_AWD0);
        m_u8AdcIrqFlag |= ADC_AWD0_IRQ_BIT;
    }
}

/**
 * @brief  ADC AWD1 IRQ callback.
 * @param  None
 * @retval None
 */
void AdcCmp1_IrqHandler(void)
{
#ifdef AWD_COMBINATION_MODE
    if (ADC_AwdGetFlag(ADC_FLAG_AWD_COMB) == Set)
    {
        ADC_AwdClrFlag(ADC_FLAG_AWD_COMB);
        m_u8AdcIrqFlag |= ADC_AWD1_IRQ_BIT;
    }
#else
    if (ADC_AwdGetFlag(ADC_FLAG_AWD1) == Set)
    {
        ADC_AwdClrFlag(ADC_FLAG_AWD1);
        m_u8AdcIrqFlag |= ADC_AWD1_IRQ_BIT;
    }
#endif // #ifdef AWD_COMBINATION_MODE
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
    uint8_t u8Port = GPIO_PORT_2;
    uint8_t u8Pin  = GPIO_PIN_0;
    uint8_t u8Flag = 1u;

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
        u8Flag = 0u;
        break;
    }

    if (u8Flag != 0u)
    {
        GPIO_SetFunc(u8Port, u8Pin, GPIO_FUNC_1_ANIN);
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
