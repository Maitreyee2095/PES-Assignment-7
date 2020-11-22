# PES-Assignment-7

GETTING IN TUNE
In this assignment, we implemented DAC and ADC.

Sine wave generation:
Sine wave was generated using the sine lookup table , the sine lookup table is mapped for values from 0 to PI/2
for values for PI/2 to PI we use the relation sin(x)=sin(PI-x)
for values for 0 to -PI we use the relation sin(-x)= - sin(x)
For any intermefiate values we use the function interpolate to calculate values for sin(x)

Once the sine wave is generated we fill the buffer for desired frequency.

 After initializing the DAC and DMA ,I use TPM1 for DAC.
 We use DMA to transfer this buffer to DAC.

Once DAC outputs, we configure ADC, for ADC I use TPM0.
I configure ADC such that output of DAC is input for ADC.

each module is saved in its own file
sin wave generation function is stored in sin_trig.c/sin_trig.h
DAC initialization function is stored in DAC_config.c/DAC_config.h
DMA TPM1 and buffer filling is stored in Analog_out.c & analog_out.h
ADC TPM0 is stored in analog_in.c/analog_in.h
