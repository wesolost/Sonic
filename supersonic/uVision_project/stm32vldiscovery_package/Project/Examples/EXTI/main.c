/**
  ******************************************************************************
  * @file    EXTI/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    09/13/2010
  * @brief   Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup Examples
  * @{
  */
GPIO_InitTypeDef GPIO_InitStructure;
GPIO_InitTypeDef GPIO_PA9PA11;
GPIO_InitTypeDef GPIO_PB1;

#define SHIFT_TIME      0
static __IO uint32_t Mtime = 0;
static __IO uint32_t Mera_time = 0;
/* Private function prototypes -----------------------------------------------*/
void Sonic_TR_8PWN();
void Sonic_dely(__IO uint32_t Delay);


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                         RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
                         RCC_APB2Periph_GPIOE, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                         RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
                         RCC_APB2Periph_GPIOE, DISABLE); 
//-----------------------------
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_PA9PA11.GPIO_Pin = GPIO_Pin_9;  
  GPIO_PA9PA11.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_PA9PA11.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_PA9PA11);
		GPIO_PA9PA11.GPIO_Pin = GPIO_Pin_11;
		GPIO_Init(GPIOA,&GPIO_PA9PA11);

  /* Initialize Leds LD3 and LD4 mounted on STM32VLDISCOVERY board */
  STM32vldiscovery_LEDInit(LED3);
  STM32vldiscovery_LEDInit(LED4);
	STM32vldiscovery_LEDOn(LED3);
//	STM32vldiscovery_LEDOff(LED4);

  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f10x_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c file
     */  
 STM32vldiscovery_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);
 STM32vldiscovery_PBInit(EXIT_PIN, BUTTON_MODE_EXTI);  
  
	if (SysTick_Config(SystemCoreClock/100000))   { while (1);} 
while(1)
{	
   Sonic_dely(0x1fffff);
		STM32vldiscovery_LEDToggle(LED3);
//	  Sonic_TR_8PWN();
	Sonic_dely(0x1fffff);
	STM32vldiscovery_LEDToggle(LED3);
//	  Sonic_TR_8PWN();
}
}
void Sonic_TR_8PWN(void)
{
	Sonic_timeclear();
  GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
	
	GPIOA->BSRR=0x08000200;
  Sonic_dely(42);
	GPIOA->BSRR=0x02000800;
	Sonic_dely(42);
}

void Sonic_dely(__IO uint32_t Delay)
{
	while(Delay!=0x00){Delay--;}
}

void Sonic_timeclear()
{
	__IO uint32_t cleardely=0xff;
	while(cleardely!=0x00){cleardely--;}
	Mtime = 0;
}
void Mearuse_time(void)
{
  Mera_time = Mtime;
}

void TimingDelay(void)
{ 
  Mtime++;
}


/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
