/*
 * print_samples.h
 *
 *  Created on: Nov 19, 2020
 *      Author: maitreyee rao
 */

#ifndef PRINT_SAMPLES_H_
#define PRINT_SAMPLES_H_

/**********************************************************************************************************************************
*void print_analysis(uint16_t *buffer, uint32_t count):print analyzed data for ADC
*@param uint16_t *buffs:buffer filled with output values of ADC
*@param count total number of values in buffer
*@return void
 ************************************************************************************************************************************/

void print_analysis(uint16_t *buffs, uint32_t total_num);


#endif /* PRINT_SAMPLES_H_ */
