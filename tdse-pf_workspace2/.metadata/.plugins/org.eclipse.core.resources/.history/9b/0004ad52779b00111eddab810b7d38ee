/*
 * Copyright (c) 2026 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 */

/********************** inclusions *******************************************/
/* Project includes */
#include "main.h"

/* Demo includes */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes */
#include "board.h"
#include "app.h"
#include "task_system_attribute.h"

/********************** macros and definitions *******************************/
#define EMPTY			(255ul)
#define QUEUE_LENGTH	(16ul)
#define ITEM_SIZE		(sizeof(task_system_ev_t))

typedef struct
{
	uint32_t			head;
	uint32_t			tail;
	uint32_t			count;
	task_system_ev_t	queue[QUEUE_LENGTH];
} event_task_system_queue_t;

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/
event_task_system_queue_t event_task_system_queue;

/********************** external data declaration ****************************/

/********************** external functions definition ************************/
void init_event_task_system(void)
{
	uint32_t i;

	event_task_system_queue.head = 0;
	event_task_system_queue.tail = 0;
	event_task_system_queue.count = 0;

	for (i = 0; i < QUEUE_LENGTH; i++)
		event_task_system_queue.queue[i] = EMPTY;
}

void put_event_task_system(task_system_ev_t event)
{
	event_task_system_queue.count++;
	event_task_system_queue.queue[event_task_system_queue.head++] = event;

	if (QUEUE_LENGTH == event_task_system_queue.head)
		event_task_system_queue.head = 0;
}

task_system_ev_t get_event_task_system(void)
{
	task_system_ev_t event;

	event_task_system_queue.count--;
	event = event_task_system_queue.queue[event_task_system_queue.tail];
	event_task_system_queue.queue[event_task_system_queue.tail++] = EMPTY;

	if (QUEUE_LENGTH == event_task_system_queue.tail)
		event_task_system_queue.tail = 0;

	return event;
}

bool any_event_task_system(void)
{
  return (event_task_system_queue.head != event_task_system_queue.tail);
}

/********************** end of file ******************************************/
