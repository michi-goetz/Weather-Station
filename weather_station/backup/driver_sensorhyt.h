#ifndef driver_sensorHYT_h
	#define driver_sensorHYT_h

/** \file driver_sensorHYT.h \brief
\n----------------------------------------------------------------------------
 \n  HYGROSENS Instruments GmbH
 \n
 \n  Ted Mölter (c) 2010
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
 *		Ted Mölter @
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


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
 *			> -40		-	+125	°C
 *			> -40		-	+257	°F
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
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/





/*						*/
// 		defines			//
//~~~~~~~~~~~~~~~~~~~~~~//

#define		ILLEGAL_RETURN_VALUE		(double)-1000000		// returning illegal value (-10^6) if desired unit doesn't exist.
																// This value must be illegal because this temperature can't exist
																// reg

//definitions you might prefer to use to specify your desired unit
	#define		DEGREE_CELSIUS				"°C"
	#define		DEGREE_FAHRENHEIT			"°F"
	#define		KELVIN						"K"
	#define		PERCENT						"%"

// #define		double						??? similarForYourMicrochip !!!
// #define		int							??? similarForYourMicrochip !!!
// #define		char						??? similarForYourMicrochip !!!




/*						*/
// function definitions	//
//~~~~~~~~~~~~~~~~~~~~~~//



/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 **	double sensorHYT_rawConversion( unsigned int uMeasuredRawValue, char* desiredUnit )
 **
 **		-> converts a given measured raw value to a desired physical unit
 **
 **		Parameter	type			name					mission
 **		---------------------------------------------------------------
 **				1:	unsigned int	uMeasuredRawValue		two bytes of measurement	(real raw -> unformatted)
 **		   
 **		   return:	double			dResult					result of physical unit sensitive conversion
 **															!! If desired physical unit isn't familiar to function result will be "ILLEGAL_RETURN_VALUE" !!
 **/
double sensorHYT_rawConversion( unsigned int uMeasuredRawValue, char* desiredUnit );



/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 **	double sensorHYT_dewPoint( double dTemperatureInDegreeCelsius, double dRelativeHumidity )
 **
 **		-> dew point calculation with Magnus formula
 **
 **
 **		Parameter	type		name							mission
 **		------------------------------------------------------------------------------
 **				1:	double		dTemperatureInDegreeCelsius		air temperature in [°C]
 **				2:	double		dRelativeHumidity				relative humidity in [%]
 **		   
 **		   return:	double		dResult							dew point based on given temperature and humidity in [°C]
 **
 **.........................................................
 **		point of origin:
 **
 **							  (	17.5043 * dp )
 **			E(dp) = E(0) * exp(--------------)		Magnus formula
 **							  (	241.2°C + dp )
 **
 **					E(dp)
 **			phi = -------- * 100%					value correlation
 **					E(T)
 **
 **
 **		both formulas solved to the DEW POINT:
 **
 **							  (	phi )	 4222.03716 * T
 **					241.2 * ln(-----) + ----------------
 **							  ( 100 )		241.2 + T
 **			dp =  ----------------------------------------
 **							  	( phi )	   17.5043 * T
 **					17.5043 - ln(-----) - --------------
 **							  	( 100 )		241.2 + T
 **
 **
 **		parameter legend:
 **
 **			E	:=	saturation vapour pressure	[ hPa ]
 **			dp	:=	dew point temperature		[  °C ]
 **			phi	:=	relative humidity			[   % ]
 **			T	:=	air temperature				[  °C ]
 **
 **/
double sensorHYT_dewPoint( double dTemperatureInDegreeCelsius, double dRelativeHumidity );



/**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 **	void sensorHYT_buildPCLOGstring( unsigned int rawTemperatureValue, unsigned int rawHumidityValue, char* strOutputString )
 **
 **		-> builds a string which fits the protocoll of HYGROSENS Instruments PC-Datalogger(c)
 **
 **		JUST FOR QUICK TESTING PURPOSES
 **			- the string will be build with current measured values, but the sensor-IDs and CRCs are not recognized -
 **			- the sensorIDs are only examples / simulated -
 **			- HYGROSENS Instruments PC-Datalogger(c) doesn't need essentially correct CRCs -
 **
 **
 **		Parameter	type			name					mission
 **		-----------------------------------------------------------------------------
 **				1:	unsigned int	rawTemperatureValue		two bytes of temperature measurement	(real raw -> unformatted)
 **				2:	unsigned int	rawHumidityValue		two bytes of humidity measurement		(real raw -> unformatted)
 **				3:	char*			strOutputString			reference for output string				(please pay attention to the IMPORTANT notice)
 **
 **
 **		IMPORTANT:
 **			- strOutputString will be at least 68 bytes long, make sure that no sensible data will be overwritten -
 **/
void sensorHYT_buildPCLOGstring( unsigned int rawTemperatureValue, unsigned int rawHumidityValue, char* strOutputString );




#endif	/* driver_sensorHYT_h */
