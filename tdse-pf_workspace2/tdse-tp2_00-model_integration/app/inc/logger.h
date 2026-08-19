/*
 * Copyright (c) 2026 Sebastian Bedin <sebabedin@gmail.com>.
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
 * @author : Sebastian Bedin <sebabedin@gmail.com>
 */

#ifndef LOGGER_H_
#define LOGGER_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/********************** macros ***********************************************/

#define LOGGER_CONFIG_ENABLE                    (1)
#define LOGGER_CONFIG_MAXLEN                    (64)
#define LOGGER_CONFIG_USE_SEMIHOSTING           (1)

#if 1 == LOGGER_CONFIG_ENABLE
#define LOGGER_LOG(...)\
	__asm("CPSID i");	/* disable interrupts*/\
    {\
        logger_msg_len = snprintf(logger_msg, (LOGGER_CONFIG_MAXLEN - 1), __VA_ARGS__);\
        logger_log_print_(logger_msg);\
    }\
	__asm("CPSIE i");	/* enable interrupts*/
#else
#define LOGGER_LOG(...)
#endif

#if 1 == LOGGER_CONFIG_ENABLE
#define LOGGER_INFO(...)\
	__asm("CPSID i");	/* disable interrupts*/\
	{\
		logger_log_print_("[info] ");\
    	logger_msg_len = snprintf(logger_msg, (LOGGER_CONFIG_MAXLEN - 1), __VA_ARGS__);\
    	logger_log_print_(logger_msg);\
    	logger_log_print_("\n");\
	}\
	__asm("CPSIE i");	/* enable interrupts*/
#else
#define LOGGER_INFO(...)
#endif

#define GET_NAME(var)  #var

/********************** typedef **********************************************/

extern char* const logger_msg;
extern int logger_msg_len; // only for debug information

/********************** external functions declaration ***********************/

void logger_log_print_(char* const msg);

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* LOGGER_H_ */

/********************** end of file ******************************************/
