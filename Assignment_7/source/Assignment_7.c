/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    Assignment_7.c
 * @brief   Application entry point.
 */

/****************************** LIBRARIES **************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "analog_out.h"
#include "test_sin.h"
#include "math.h"
#include "DAC_config.h"
#include "Analog_in.h"
#include "print_samples.h"
#include "analog_out.h"

#define SAMPLING_RATE 96000 //Sampling rate for ADC
#define COUNT 1024 //total number of buffer elements
#define BUFF_MAX 1024
/*********************GLOBAL VARIABLES******************************************************/

uint16_t *buff;

/*************************   MAIN  **************************************************/

int main(void) {

	/* Init board hardware. */

	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	int sample, i=0;
	uint16_t buffs_op[BUFF_MAX], buffs_ip[BUFF_MAX];
	int freq[] = {440, 587, 659, 880};
	Init_DAC();
	Init_TPM1();		//Initialize TPM1 for DAC
	Init_DMA();
	Init_TPM0(SAMPLING_RATE);	//Initialize TPM0 for ADC , at 96Khz Sampling rate
	Init_ADC();
	test_sine();		//test sine function

	while(i<5) {
		sample = tone_to_samples(freq[i], buffs_op, COUNT); //computes tone for specified frequency
		Copy_DMA_buffer(buffs_op, sample);//get buffer ready to be copied
		Start_DMA_transfer(); //start DMA transfer, copy contents from buffer to output on DAC
		ADC_config(buffs_ip, COUNT);//configure ADC
		print_analysis(buffs_ip, COUNT); //analyze ADC buffer
		if(i==3)  	//to keep looping between frequencies reset the counter
		{
			i=0;
		}
		else{
			i++;
		}

	}
	return 0 ;
}
