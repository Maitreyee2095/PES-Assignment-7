/*
 * ADC_config.c
 *
 *  Created on: Nov 19, 2020
 *      Author: maitreyee Rao
 */



#include "MKL25Z4.h"
#include "stdio.h"
#include "stdint.h"
#include "Analog_in.h"

/**********************************************************************************************************************************
 *void Init_TPM0(int period):Function to Initialize TPM0 based on required period
 *@param takes period as parameter
 *returns void
 ************************************************************************************************************************************/


void Init_TPM0(int period) {

	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;

	// Disable TPM for config
	TPM0->SC = 0;


	TPM0->MOD = TPM_MOD_MOD(CLOCK / period);
	TPM0->CNT = 0;

	// Prescalar Settings
	TPM0->SC = TPM_SC_PS(0) | TPM_SC_CPWMS(0);

}
/**********************************************************************************************************************************
 *void Init_ADC():Function to Initialize ADC
 *takes no parameters
 *returns void
 *code designed as suggested by Prof. Howdy Pierce in lecture series
 ************************************************************************************************************************************/

void Init_ADC() {
	// ADC0 Clock Gate Control
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;

	// Normal power config//divide ratio 1 //short sampling period// single-ended 16-bit conversion//select bus clock
	ADC0->CFG1 = ADC_CFG1_ADLPC(0) | ADC_CFG1_ADIV(0) | ADC_CFG1_ADLSMP(0) | ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(0);

	ADC0->CFG2 = 0;

	// Compare function disabled //DMA initially disabled//default ref voltage selected
	ADC0->SC2 = ADC_SC2_ADTRG(1) | ADC_SC2_ACFE(0) | ADC_SC2_DMAEN(0) | ADC_SC2_REFSEL(0);

	//enable adc interrupt //single ended conversion // 10111 When DIFF=0, AD23 is selected as input for ADC
	//AD23 is nothing but 12 bit DAC output
	ADC0->SC1[0] = ADC_SC1_AIEN(0) | ADC_SC1_DIFF(0) | ADC_SC1_ADCH(23);

	// select tpm1 for adc
	//alternate trigger for ADC is selected we dont want it to be TPM1
	//ADC0TRGSEL 8 : is TPM0 overflow
	SIM->SOPT7 = SIM_SOPT7_ADC0ALTTRGEN(1) | SIM_SOPT7_ADC0TRGSEL(8)|SIM_SOPT7_ADC0PRETRGSEL(0);

}
/**********************************************************************************************************************************
*void ADC_config(uint16_t *buffs, uint32_t num): starts ADC buffer filling
 *@Param uint16_t *buffs: takes buffer to fill as parameter
 *@Param uint32_t count : number of buffer elements
 *returns void
 *code designed as suggested by Prof. Howdy Pierce in lecture series
 ************************************************************************************************************************************/


void ADC_config(uint16_t *buffs, uint32_t num) {

	int i =0;
	//start TPM0
	TPM0->SC |= TPM_SC_CMOD(1);

	for (i =0; i < num; i++) {
		while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK)) //wait for read to complete
		      ;

		buffs[i] = ADC0->R[0];//fill buffer
	}

	// Stop TPM0
	TPM0->SC &= ~TPM_SC_CMOD_MASK;
}
