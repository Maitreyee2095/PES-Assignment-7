/*
 * Analog_in.h
 *
 *  Created on: Nov 21, 2020
 *      Author: maitreyee rao
 */

#ifndef ANALOG_IN_H_
#define ANALOG_IN_H_


#define CLOCK		(48e6) //sys clock used


/**********************************************************************************************************************************
 *void Init_TPM0(int period):Function to Initialize TPM0 based on required period
 *@param takes period as parameter
 *returns void
 ************************************************************************************************************************************/

void Init_TPM0(int period);
/**********************************************************************************************************************************
 *void Init_ADC():Function to Initialize ADC
 *takes no parameters
 *returns void
 *code designed as suggested by Prof. Howdy Pierce in lecture series

 ************************************************************************************************************************************/

void Init_ADC();
/**********************************************************************************************************************************
*void ADC_config(uint16_t *buffs, uint32_t num): starts ADC buffer filling
 *@Param uint16_t *buffs: takes buffer to fill as parameter
 *@Param uint32_t count : number of buffer elements
 *returns void
 *code designed as suggested by Prof. Howdy Pierce in lecture series
 ************************************************************************************************************************************/

void ADC_config(uint16_t *buffs, uint32_t num);
#endif /* ANALOG_IN_H_ */
