/*
 * freertos.h
 *
 *  Created on: Apr 7, 2020
 *      Author: bodek
 */

#ifndef INC_FREERTOS_H_
#define INC_FREERTOS_H_

float load;
volatile unsigned thread_nr;

//#define traceTASK_SWITCHED_IN() {thread_nr=(int)pxCurrentTCB->uxTaskNumber;}

void DefaultTask(void *argument);

void led_task_init(unsigned uxPriority);

#endif /* INC_FREERTOS_H_ */
