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
#include "task_actuator_attribute.h"
#include "task_actuator_interface.h"

/********************** macros and definitions *******************************/
#define DEL_LED_MIN		0ul
#define DEL_LED_MED		250ul
#define DEL_LED_MAX		500ul

#define ACTUATOR_CFG_QTY	(sizeof(task_actuator_cfg_list)/sizeof(task_actuator_cfg_t))
#define ACTUATOR_DTA_QTY	ACTUATOR_CFG_QTY

/********************** internal data declaration ****************************/
const task_actuator_cfg_t task_actuator_cfg_list[] = {
	{ID_LED_A,  LED_A_PORT,  LED_A_PIN, LED_A_ON,  LED_A_OFF, DEL_LED_MAX}
};

task_actuator_dta_t task_actuator_dta_list[ACTUATOR_DTA_QTY];

/********************** internal functions declaration ***********************/
void task_actuator_statechart(uint32_t index);

/********************** internal data definition *****************************/
const char *p_task_actuator 		= "Task Actuator (Actuator Statechart)";
const char *p_task_actuator_ 		= "Non-Blocking Code";
const char *p_task_actuator__ 		= "(Update by Time Code, period = 1mS)";

/********************** external data declaration ****************************/

/********************** external functions definition ************************/
void task_actuator_init(void *parameters)
{
	uint32_t index;
	const task_actuator_cfg_t *p_task_actuator_cfg;
	task_actuator_dta_t *p_task_actuator_dta;
	task_actuator_st_t state;
	task_actuator_ev_t event;
	bool b_event;

	/* Print out: Task Initialized */
	LOGGER_INFO(" ");
	LOGGER_INFO("  %s is running - Tick [mS] = %lu", GET_NAME(task_actuator_init), HAL_GetTick());
	LOGGER_INFO("   %s is a %s", GET_NAME(task_actuator), p_task_actuator);
	LOGGER_INFO("   %s is a %s", GET_NAME(task_actuator), p_task_actuator_);
	LOGGER_INFO("   %s is a %s", GET_NAME(task_actuator), p_task_actuator__);

	for (index = 0; ACTUATOR_DTA_QTY > index; index++)
	{
		/* Update Task Actuator Configuration & Data Pointer */
		p_task_actuator_cfg = &task_actuator_cfg_list[index];
		p_task_actuator_dta = &task_actuator_dta_list[index];

		/* Init & Print out: Index & Task execution FSM */
		state = ST_LED_IDLE;
		p_task_actuator_dta->state = state;

		event = EV_LED_IDLE;
		p_task_actuator_dta->event = event;

		b_event = false;
		p_task_actuator_dta->flag = b_event;

		LOGGER_INFO(" ");
		LOGGER_INFO("   %s = %lu   %s = %lu   %s = %lu   %s = %s",
					 GET_NAME(index), index,
					 GET_NAME(state), (uint32_t)state,
					 GET_NAME(event), (uint32_t)event,
					 GET_NAME(b_event), (b_event ? "true" : "false"));

		HAL_GPIO_WritePin(p_task_actuator_cfg->gpio_port, p_task_actuator_cfg->pin, p_task_actuator_cfg->led_off);
	}
}

void task_actuator_update(void *parameters)
{
	uint32_t index;

	for (index = 0; ACTUATOR_DTA_QTY > index; index++)
	{
		/* Run Task Statechart */
		task_actuator_statechart(index);
	}
}

void task_actuator_statechart(uint32_t index)
{
	const task_actuator_cfg_t *p_task_actuator_cfg;
	task_actuator_dta_t *p_task_actuator_dta;

	/* Update Task Actuator Configuration & Data Pointer */
	p_task_actuator_cfg = &task_actuator_cfg_list[index];
	p_task_actuator_dta = &task_actuator_dta_list[index];

	switch (p_task_actuator_dta->state)
	{
		case ST_LED_IDLE:

			if ((true == p_task_actuator_dta->flag) && (EV_LED_ACTIVE == p_task_actuator_dta->event))
			{
				p_task_actuator_dta->flag = false;
				HAL_GPIO_WritePin(p_task_actuator_cfg->gpio_port, p_task_actuator_cfg->pin, p_task_actuator_cfg->led_on);
				p_task_actuator_dta->state = ST_LED_ACTIVE;
			}

			break;

		case ST_LED_ACTIVE:

			if ((true == p_task_actuator_dta->flag) && (EV_LED_IDLE == p_task_actuator_dta->event))
			{
				p_task_actuator_dta->flag = false;
				HAL_GPIO_WritePin(p_task_actuator_cfg->gpio_port, p_task_actuator_cfg->pin, p_task_actuator_cfg->led_off);
				p_task_actuator_dta->state = ST_LED_IDLE;
			}

			break;

		default:

			p_task_actuator_dta->tick  = DEL_LED_MIN;
			p_task_actuator_dta->state = ST_LED_IDLE;
			p_task_actuator_dta->event = EV_LED_IDLE;
			p_task_actuator_dta->flag = false;

			break;
	}
}

/********************** end of file ******************************************/
