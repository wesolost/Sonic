/**
  ******************************************************************************
  * @file    STM32vldiscovery.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    09/13/2010
  * @brief   Header file for STM32vldiscovery.c module.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F100_Dicovery_H
#define __STM32F100_Dicovery_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "STM32f10x.h"

/** @addtogroup Utilities
  * @{
  */ 
  
/** @addtogroup STM32vldiscovery
  * @{
  */ 

/** @defgroup STM32vldiscovery_Abstraction_Layer
  * @{
  */  

/** @defgroup STM32vldiscovery_HARDWARE_RESOURCES
  * @{
  */
  
/** @defgroup STM32vldiscovery_Exported_Types
  * @{
  */
typedef enum 
{
  LED3 = 0,
  LED4 = 1
} Led_TypeDef;

typedef enum 
{  
  BUTTON_USER = 0,
	EXIT_PIN = 1
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;              

/** 
  * @brief  STM32F100 Button Defines Legacy  
  */ 

#define Button_USER          BUTTON_USER
#define Mode_GPIO            BUTTON_MODE_GPIO
#define Mode_EXTI            BUTTON_MODE_EXTI
#define Button_Mode_TypeDef  ButtonMode_TypeDef


/** @addtogroup STM32vldiscovery_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             2
#define LED3_PIN                         GPIO_Pin_9  
#define LED3_GPIO_PORT                   GPIOC
#define LED3_GPIO_CLK                    RCC_APB2Periph_GPIOC  

#define LED4_PIN                         GPIO_Pin_8  
#define LED4_GPIO_PORT                   GPIOC
#define LED4_GPIO_CLK                    RCC_APB2Periph_GPIOC  

#define SONIC_TRn
#define SONIC_TRn

/**
  * @}
  */ 
  
/** @addtogroup STM32vldiscovery_LOW_LEVEL_BUTTON
  * @{
  */  
#define BUTTONn                          2

/* * @brief USER push-button
 */
#define USER_BUTTON_PIN0                   GPIO_Pin_0
#define USER_BUTTON_GPIO_PORT0             GPIOA
#define USER_BUTTON_GPIO_CLK0              RCC_APB2Periph_GPIOA
#define USER_BUTTON_EXTI_PORT_SOURCE0      GPIO_PortSourceGPIOA
#define USER_BUTTON_EXTI_PIN_SOURCE0       GPIO_PinSource0
#define USER_BUTTON_EXTI_LINE0             EXTI_Line0
#define USER_BUTTON_EXTI_IRQn0             EXTI0_IRQn
#define USER_BUTTON_PIN_MODE0              GPIO_Mode_IN_FLOATING 
#define USER_BUTTON_TRIGER_MODE0           EXTI_Trigger_Rising 

#define USER_BUTTON_PIN1                   GPIO_Pin_1
#define USER_BUTTON_GPIO_PORT1             GPIOB
#define USER_BUTTON_GPIO_CLK1              RCC_APB2Periph_GPIOB
#define USER_BUTTON_EXTI_PORT_SOURCE1      GPIO_PortSourceGPIOB
#define USER_BUTTON_EXTI_PIN_SOURCE1       GPIO_PinSource1
#define USER_BUTTON_EXTI_LINE1             EXTI_Line1
#define USER_BUTTON_EXTI_IRQn1             EXTI1_IRQn
#define USER_BUTTON_PIN_MODE1              GPIO_Mode_IN_FLOATING 
#define USER_BUTTON_TRIGER_MODE1           EXTI_Trigger_Falling 
/**
  * @}
  */ 

/** @defgroup STM32vldiscovery_LOW_LEVEL__Exported_Functions
  * @{
  */ 
void STM32vldiscovery_LEDInit(Led_TypeDef Led);
void STM32vldiscovery_LEDOn(Led_TypeDef Led);
void STM32vldiscovery_LEDOff(Led_TypeDef Led);
void STM32vldiscovery_LEDToggle(Led_TypeDef Led);
void STM32vldiscovery_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t STM32vldiscovery_PBGetState(Button_TypeDef Button);

/**
  * @}
  */ 
    
#ifdef __cplusplus
}
#endif


#endif /* __STM32vldiscovery_H */

/**
  * @}
  */ 

/**
  * @}
  */  

/**
  * @}
  */
  
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
