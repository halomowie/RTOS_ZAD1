/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define traceTASK_SWITCHED_IN() set_led_id(pxCurrentTCB->uxTaskNumber);
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void task_ledblink(void *pvParameters);
/* USER CODE END FunctionPrototypes */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
__weak void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
__weak void vApplicationTickHook( void )
{
   /* This function will be called by each tick interrupt if
   configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
   added here, but the tick hook is called from an interrupt context, so
   code must not attempt to block, and only the interrupt safe FreeRTOS API
   functions can be used (those that end in FromISR()). */
//	TaskHandle_t current_task = xTaskGetCurrentTaskHandle();
//	led_id = uxTaskGetTaskNumber(current_task);
}
/* USER CODE END 3 */

/* USER CODE BEGIN 4 */
__weak void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
  UNUSED(xTask);
  UNUSED(pcTaskName);
  /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
__weak void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
int iLicznik =0;
/* USER CODE END Header_StartDefaultTask */
void DefaultTask(void *argument) {
	UNUSED(argument);
  /* Infinite loop */
  for(;;)
  // while(True)
  {
	  iLicznik++;
	  iLicznik = (iLicznik % 10);
	  printf("%d\n",(int)iLicznik);
	  vTaskDelay(1000);
  }
}

struct params {
	unsigned timeout;
	unsigned led_id;
};

void task_ledblink(void *pvParameters) {
	uint32_t PreviousWakeTime;
	struct params *p = (struct params *)pvParameters;

	// inicjalizacja/start
	PreviousWakeTime = xTaskGetTickCount();

	// sam kod wątku
	for (;;) {
		//set_led_id(p->led_id);
		switch(p->led_id) {
//		case 1: LED1_TOGGLE(); printf("1\n"); break;
//		case 2: LED2_TOGGLE(); printf("2\n"); break;
//		case 3: LED3_TOGGLE(); printf("3\n"); break;
//		case 4: LED4_TOGGLE(); printf("4\n"); break;
		case 1: LED1_TOGGLE();  break;
		case 2: LED2_TOGGLE();  break;
		case 3: LED3_TOGGLE();  break;
		case 4: LED4_TOGGLE();  break;
		default:
			break;
		}
		vTaskDelayUntil(&PreviousWakeTime, p->timeout);
	}
}

//struct params param1 = {1371,1};
//struct params param2 = {2593,2};
//struct params param3 = {3717,3};
struct params param1 = {300,1};
struct params param2 = {500,2};
struct params param3 = {1300,3};
struct params param4 = {1700,4};
void led_task_init(unsigned uxPriority) {
	unsigned nr=1;
	TaskHandle_t xTask;

	xTaskCreate(task_ledblink, "Green", configMINIMAL_STACK_SIZE, &param1, uxPriority, &xTask );
	vTaskSetTaskNumber(xTask,nr++);
	xTaskCreate(task_ledblink, "Orange", configMINIMAL_STACK_SIZE, &param2, uxPriority, &xTask );
	vTaskSetTaskNumber(xTask,nr++);
	xTaskCreate(task_ledblink, "Red", configMINIMAL_STACK_SIZE, &param3, uxPriority, &xTask );
	vTaskSetTaskNumber(xTask,nr++);
	xTaskCreate(task_ledblink, "Blue", configMINIMAL_STACK_SIZE, &param4, uxPriority, &xTask );
	vTaskSetTaskNumber(xTask,nr++);

}


/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
