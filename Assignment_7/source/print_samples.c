/*
 * print_samples.c
 * this file analyzes and prints the adc output
 *
 *  Created on: Nov 19, 2020
 *      Author: maitr
 */

#include "autocorrelate.h"
#include "assert.h"
#include "stdio.h"
#include "stdint.h"

#include "fsl_debug_console.h"
#define PERIOD 96000

/**********************************************************************************************************************************
 *void print_analysis(uint16_t *buffs, uint32_t count):print analyzed data for ADC
 *@param uint16_t *buffs:buffs filled with output values of ADC
 *@param count total number of values in buffs
 *@return void
 ************************************************************************************************************************************/

void print_analysis(uint16_t *buffs, uint32_t total_num) {

	int i=0;
	uint32_t maximum=0, minimum = 65536U, sum = 0;//set values for min max

	for (i=0; i < total_num; i++) {

		if (buffs[i] < minimum) //check if value in buffer less than minimum
		{
			minimum = buffs[i]; //update minimum
		}
		if (buffs[i] > maximum) //check if value greater than max
		{
			maximum = buffs[i]; //update max
		}
		sum+= buffs[i]; //update sum

	}

	int period = autocorrelate_detect_period(buffs, total_num, 1); //calculate period using autocorrelate function
	PRINTF("minimum=%u maximum=%u avg=%u period=%d frequency=%d Hz\r\n",
			minimum, maximum, sum / total_num, period, PERIOD / period);

}
