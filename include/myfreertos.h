/*
 * freertos.h
 *
 *  Created on: Apr 7, 2020
 *      Author: bodek
 */

#ifndef INC_MYFREERTOS_H_
#define INC_MYFREERTOS_H_

//float load;
//volatile unsigned thread_nr;

//#define traceTASK_SWITCHED_IN() {thread_nr=(int)pxCurrentTCB->uxTaskNumber;}

void DefaultTask(void *argument);

void led_task_init(unsigned uxPriority);

int CPU_work(int czas_obliczen_ms);

void FirstTask(void *argument);

void SecondTask(void *argument);



#endif /* INC_MYFREERTOS_H_ */
