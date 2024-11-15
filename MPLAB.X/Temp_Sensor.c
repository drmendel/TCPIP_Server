/* 
 * File:   Temp_sensor.c
 * Author: Greg
 *
 * Created on 13 November 2024, 14:41
 */

#include <p18f97j60.h>
#include "Temp_Sensor.h"
#include <stdio.h>
#include <string.h>

void TMP_Init(void)
{
    TRISAbits.TRISA3 = 1;   // AN3 input
    ADCON0 = 0x0D;          // 0b 0000 1101     CH: AN3, ADON
    ADCON1 = 0x0B;          // 0b 0000 1011     AN0-AN3 analog input, else digital
    ADCON2 = 0xBE;          // 0b 1011 1110     Right justify, 20TAD ACQ time, Fosc/64 (~21.0kHz) - copied from the potentiometer demo program
    return;
}
unsigned int TMP_Read(void)
{
    ADCON0bits.GO = 1;                  // Start to sample and conversion
    while(!ADCON0bits.DONE) Nop();      // Waiting to finish
    return (ADRESH << 8) | ADRESL;      // Read the buffer
}
void ADC_to_TMP(unsigned char* buffer, unsigned int AD_value)
{
    float TMP = (((float)AD_value / 1023) * U_max_mV - 500) / TMP_Slope;    // convert 0-1023, (-40.00°C)-(125.00 °C)
    memset(buffer, 0, TMP_Buffer_Size);                                     // clear the buffer
    sprintf(buffer, "%.2f °C", TMP);                                        // load the value with .2 precision to the buffer
    return;
}


