/** \file driver_sensorHYT.c \brief
\n----------------------------------------------------------------------------
 \n  HYGROSENS Instruments GmbH
 \n
 \n  Ted M�lter (c) 2010
 \n  ----------------------------------------------------------------------------
 \n You may use this file if you retain the complete copyright notice
 \n
**/

/*!****************************************************************************
 *
 * \brief  driver source file for raw value interpretation of temperature and
 *			humidity sensor.
 *
 *      The driver is not intended for size and/or speed critical code, since
 *      most functions are just a few lines of code, and the function call
 *      overhead would decrease code performance. The driver is intended for
 *      rapid prototyping and documentation purposes for getting started with
 *      the HYGROSENS temperature and humidity sensor.
 *
 *      For size and/or speed critical code, it is recommended to copy the
 *      function contents directly into your application instead of making
 *      a function call.
 *
 * \author
 *		Ted M�lter @
 *      HYGROSENS Instruments GmbH: http://www.hygrosens.com \n
 *      Support email: info@hygrosens.com
 *
 * $Revision: A217 $
 * $Date: 2010-02-23T11:16:43 +0100 (Tue, 23 Feb 2010) $  \n
 *
 * Copyright (c) 2010, HYGROSENS Instruments GmbH All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of SOURCE CODE must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in BINARY FORM must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY HYGROSENS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
 * SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL HYGROSENS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

/** \page Changelog
\n ----------------------------------------------------------------------------
\n 2010/02/23	11:16		v1.00
\n Date of Creation
\n ----------------------------------------------------------------------------
**/



/*++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 *	GENERAL SENSOR INFORMATION
 *-------------------------------
 *	
 *	sensor abilities:
 *		/ humidity
 *			> 0x0000	- 	0x3FFF	hex
 *			> 0			- 	16383	dec
 *			> 0			- 	100		%	relative humidity
 *
 *		/ temperature
 *			> 0x0000	-	0x3FFF	hex
 *			> 0			-	16383	dec
 *			> -40		-	+125	�C
 *			> -40		-	+257	�F
 *			> +233.15	-	+398.15	K
 *
 *	raw value format:
 *
 *		|	1.byte	|	2.byte	|	3.byte	|	4.byte	|
 *		|-----------------------|-----------------------|
 *		|		Humidity		|		Temperature		|
 *		|-----------------------|-----------------------|
 *		|	2 bit	|	14 bit	|	14 bit	|	2 bit 	|
 *		|-----------|-----------|-----------|-----------|
 *		|	state	|	data	|	data	|	state	|
 *
 *
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 
 


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include "string.h"
#include "math.h"



//own functions /definitions included
//====================================
#include "drvier_sensorHYT.h"



/*						*/
//	global definitions	//
//~~~~~~~~~~~~~~~~~~~~~~//




/*						*/
// 		function		//
//   predeclaration		//
//~~~~~~~~~~~~~~~~~~~~~~//




/*						*/
// function definitions	//
//~~~~~~~~~~~~~~~~~~~~~~//


/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 **	double sensorHYT_rawConversion( unsigned int uMeasuredRawValue, char* desiredUnit )
 **
 **		-> converts a given measured raw value to a desired physical unit
 **
 **		!! FOR FURTHER INFORMATION VISIT HEADER !!
 **/
double sensorHYT_rawConversion( unsigned int uMeasuredRawValue, char* desiredUnit )
{
	double dResult = 0;
			
	//------------------------------------------------------
	// step 1: set conversion coefficients
	//------------------------------------------------------
	
	double	dScaleCoeff		= 0;
	double dAxisIntersect	= 0;

	if( strcmp( desiredUnit, "%") == 0 )
	{
		// uMeasuredRawValue is humidity
		
		dScaleCoeff		= 163.83;
		dAxisIntersect	= 0.0;
		
		//removing humidity status bits (ignored)
		uMeasuredRawValue &= 0x3FFF;
	}
	else
	{
		// uMeasuredRawValue should be temperature
		
		if( strcmp( desiredUnit, "C") == 0 )
		{
			dScaleCoeff		= 99.2909;
			dAxisIntersect	= -40.0;
		}
		else if( strcmp( desiredUnit, "F") == 0 )
		{	
			dScaleCoeff		= 55.1616;
			dAxisIntersect	= -40.0;
		}
		else if( strcmp( desiredUnit, "K") == 0 )
		{
			dScaleCoeff		= 99.2909;
			dAxisIntersect	= 233.15;
		}
		else
		{
			return ILLEGAL_RETURN_VALUE;				//returning illegal value if desired unit doesn't exist
		}
		
		//removing temperature status bits (ignored)
		uMeasuredRawValue = uMeasuredRawValue >> 2;
	}
	
	
	//------------------------------------------------------
	// step 2: convert measured raw value to desired unit
	//------------------------------------------------------
	
	dResult = ( (double)uMeasuredRawValue / dScaleCoeff ) + dAxisIntersect;
	
	return dResult;
}



/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 **	double sensorHYT_dewPoint( double dTemperatureInDegreeCelsius, double dRelativeHumidity )
 **
 **		-> dew point calculation with Magnus formula
 **	
 **		!! FOR FURTHER INFORMATION VISIT HEADER !!
 **/
double sensorHYT_dewPoint( double dTemperatureInDegreeCelsius, double dRelativeHumidity )
{
	//more than one time needed values
	double dTempConstant_1 = log( (double)(dRelativeHumidity / 100) );
	double dTempConstant_2 = dTemperatureInDegreeCelsius + 241.2;
	
	//above slash
	double dResult = 4222.03716 / dTempConstant_2 * dTemperatureInDegreeCelsius + 241.2 * dTempConstant_1;
	
	//below slash
	dResult /= 17.5043 - 17.5043 * dTemperatureInDegreeCelsius / dTempConstant_2 - dTempConstant_1;	
	
	return dResult;
}



/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 **	void sensorHYT_buildPCLOGstring( unsigned int rawTemperatureValue, unsigned int rawHumidityValue, char* strOutputString )
 **
 **		-> builds a string which fits the protocoll of HYGROSENS Instruments PC-Datalogger (c)
 **
 **		!! JUST FOR QUICK TESTING PURPOSES !!
 **
 **		!! FOR FURTHER INFORMATION VISIT HEADER !!
 **
 **		!! IMPORTANT: !!
 **			- "strOutputString" will be at least 68 bytes long, make sure that no sensible data will be overwritten -
 **/
void sensorHYT_buildPCLOGstring( unsigned int rawTemperatureValue, unsigned int rawHumidityValue, char* strOutputString )
{
	// formatting measure values
	rawTemperatureValue	= (unsigned int)(100 * sensorHYT_rawConversion( rawTemperatureValue, "C") );
	rawHumidityValue	= (unsigned int)(200 * sensorHYT_rawConversion( rawHumidityValue, "%") );
	
	// building output string
	sprintf( strOutputString, "@\rI01010100B00725030178\rV01%04X%02X\rI02020100B00725030148\rV02%04X%02X\r$\r", \
				rawTemperatureValue, 0xFF, \
				rawHumidityValue, 0xFF );
}
