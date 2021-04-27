#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PC14_OSC32_IN_Pin GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOA
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
//=== blinking leds
#define LED_1_Pin 					GPIO_PIN_12
#define LED_1_GPIO_Port 			GPIOD
#define LED_2_Pin 					GPIO_PIN_13
#define LED_2_GPIO_Port 			GPIOD
#define LED_3_Pin 					GPIO_PIN_14
#define LED_3_GPIO_Port 			GPIOD
#define LED_4_Pin					GPIO_PIN_15
#define LED_4_GPIO_Port 			GPIOD
#define LED_5_Pin					GPIO_PIN_11
#define LED_5_GPIO_Port 			GPIOD

// leds specification
#define NUMBER_OF_LEDS	5
//PD4,PD7,PB4,PE0,PE1
#define BLINKLED_TAB		{{3,13},{3,12},{3,14},{3,15},{3,11}}

#define LED1_ON()		(LED_1_GPIO_Port->BSRR = (LED_1_Pin))
#define LED1_OFF()		(LED_1_GPIO_Port->BSRR = (LED_1_Pin)<<16)
#define LED1_TOGGLE()   (LED_1_GPIO_Port->ODR ^= (LED_1_Pin))
#define LED1_FLASH()	do{LED1_TOGGLE(); LED1_TOGGLE();} while(0)

#define LED2_ON()		(LED_2_GPIO_Port->BSRR = (LED_2_Pin))
#define LED2_OFF()		(LED_2_GPIO_Port->BSRR = (LED_2_Pin)<<16)
#define LED2_TOGGLE()   (LED_2_GPIO_Port->ODR ^= (LED_2_Pin))
#define LED2_FLASH()	do{LED2_TOGGLE(); LED2_TOGGLE();} while(0)

#define LED3_ON()		(LED_3_GPIO_Port->BSRR = (LED_3_Pin))
#define LED3_OFF()		(LED_3_GPIO_Port->BSRR = (LED_3_Pin)<<16)
#define LED3_TOGGLE()   (LED_3_GPIO_Port->ODR ^= (LED_3_Pin))
#define LED3_FLASH()	do{LED3_TOGGLE(); LED3_TOGGLE();} while(0)

#define LED4_ON()		(LED_4_GPIO_Port->BSRR = (LED_4_Pin))
#define LED4_OFF()		(LED_4_GPIO_Port->BSRR = (LED_4_Pin)<<16)
#define LED4_TOGGLE()   (LED_4_GPIO_Port->ODR ^= (LED_4_Pin))
#define LED4_FLASH()	do{LED4_TOGGLE(); LED4_TOGGLE();} while(0)

#define LED5_ON()		(LED_5_GPIO_Port->BSRR = (LED_5_Pin))
#define LED5_OFF()		(LED_5_GPIO_Port->BSRR = (LED_5_Pin)<<16)
#define LED5_TOGGLE()   (LED_5_GPIO_Port->ODR ^= (LED_5_Pin))
#define LED5_FLASH()	do{LED5_TOGGLE(); LED5_TOGGLE();} while(0)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
