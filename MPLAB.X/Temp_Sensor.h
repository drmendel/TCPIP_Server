/* 
 * File:   Temp_Sensor.h
 * Author: Greg
 *
 * Created on 13 November 2024, 12:39
 */

#ifndef TEMP_SENSOR_H
#define	TEMP_SENSOR_H

/*  TC1047 - Precision Temperature-to-Voltage Converter
 *      The TC1047 is a linear output temperature sensor whose output voltage is directly proportional to measured temperature.
 *      The TC1047 can accurately measure temperature from -40°C to +125°C.
 *      For the TC1047, the output voltage range is typically
 *          100mV at -40°C,
 *          500mV at 0°C,
 *          750mV at +25°C, and
 *          1.75V at +125°C.
 *      A 10mV/°C voltage slope allows for the wide temperature range.
 *      The TC1047 is packaged in space saving 3-Pin SOT-23B packages, making them ideal for space critical applications.
 *      
 * 
 *      Supply Voltage Range: 2.7V to 4.4V
 *      Wide Temperature Measurement Range: -40°C to +125°C
 *      High Temperature Converter Accuracy: 2°C (max) at 25°C
 *      Linear Temperature Slope ...........................  10mV/°C
 *      Very Low Supply Current ............................ ~35uA
 */
#include <p18f97j60.h>

// One step is
// 3.226 mV - 0.3226 °C

#define TMP_Slope 10.0              // based on the TMP sensor description
#define U_max_mV 3300.0             // max voltage (we might measure this)          1 2 3 4 5 6 7 8 9 10
#define TMP_Buffer_Size 10          // char numbers of the min and max values       -_4_0_._0_0_ _°_C_\0
//                                                                                  1_2_5_._0_0_ _°_C_\0

void TMP_Init(void);                                                        // Setup AD converter (AN3)
unsigned int TMP_Read(void);                                                // Returns the AD converter value
void ADC_to_TMP(unsigned char* buffer, unsigned int AD_Value);              // Loads the TMP value to TMP_Buffer

#endif	/* TEMP_SENSOR_H */

