/***************************************************************************************************************
    This file is part of Library for AVR.

    Library for AVR is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for AVR is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Library for AVR.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/



/***
**   File       : adxl335.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the adxl335 accelerometer driver include file for AVR family MCU's
***/

#ifndef __adxl335_h__
#define __adxl335_h__

#include "adc.h"

#define X_ZERO_BIAS_VOLTAGE   1.5
#define Y_ZERO_BIAS_VOLTAGE   1.5
#define Z_ZERO_BIAS_VOLTAGE   1

#define X_ASSEMBLY_ERROR      0
#define Y_ASSEMBLY_ERROR      0
#define Z_ASSEMBLY_ERROR      0

#define X_CHANNEL             0
#define Y_CHANNEL             1
#define Z_CHANNEL             2

#define PI                    3.142

#define ADXL335_SENSITIVITY   0.33

#define getXg()              ((analogReadVoltage(X_CHANNEL) - X_ZERO_BIAS_VOLTAGE - X_ASSEMBLY_ERROR) / ADXL335_SENSITIVITY)
#define getYg()              ((analogReadVoltage(Y_CHANNEL) - Y_ZERO_BIAS_VOLTAGE - Y_ASSEMBLY_ERROR) / ADXL335_SENSITIVITY)
#define getZg()              ((analogReadVoltage(Z_CHANNEL) - Z_ZERO_BIAS_VOLTAGE - Z_ASSEMBLY_ERROR) / ADXL335_SENSITIVITY)

#define RAD2DEG(val)         val * (180/PI)

#define getAngleX()          RAD2DEG(atan(getXg()/(sqrt(((pow(getYg() ,2)) + (pow(getZg(),2)))))))
#define getAngleY()          RAD2DEG(atan(getYg()/(sqrt(((pow(getXg() ,2)) + (pow(getZg(),2)))))))

#define ADXL335BEGIN()       Adcbegin()


// At 2.56 Volt, 2.34g is max

#endif




