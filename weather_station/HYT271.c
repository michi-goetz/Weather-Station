

#include "PSoCAPI.h"
#include <stdio.h>
#include <stdlib.h>


	void measuring (int*temperature, int*humidity) {
	
	
		//get temp and humidity here
		

		int capdata07, capdata813, tempdata, humdata, i;
		
		I2Cm_Start();				//Initialize I2C
		I2Cm_fSendStart( 0x28, 0);	//Send Measuring Request
		I2Cm_fSendStart( 0x28, 1);	//Send Data Fetch
		
		capdata813=I2Cm_bRead (I2Cm_ACKslave);
		capdata07 =I2Cm_bRead (I2Cm_ACKslave);
		tempdata  =I2Cm_bRead (I2Cm_NAKslave);
		
		I2Cm_SendStop();			//Stop I2C	
		
		// calculating temp and humidity
		capdata813=capdata813<<8;
		humdata=capdata813|capdata07;
		humdata=humdata&0x3FFF;
		
		humdata=100/2^14*humdata;
		tempdata=165/2^14*tempdata-40;
		
		
		
		
		//FIR filter
		for(i=0; i<4; i++) temperature[i] = temperature[i+1];
		temperature[4] = tempdata;
		
		
		for(i=0; i<4; i++) humidity[i] = humidity[i+1];
		humidity[4] = humdata;
		
		}
		
		
		
		void printtemp (char *firstLine, char *secondLine, int*temperature) {
					//calculate the average of temperature
					int result, i;
					result = 0;
					for(i=0; i<5; i++) result = result + temperature [i]; 
					result = result/5;
					
					//send to LCD
					csprintf(firstLine, "Temperature:    ");
					csprintf(secondLine,"%i C            ",result);
					}
					
					
					
					
		void printhum (char *firstLine, char *secondLine, int*humidity) {
					//calculate the average of humidity
					int result, i;
					result = 0;
					for(i=0; i<5; i++) result = result + humidity [i];
					result = result/5;
					
					//send to LCD
					csprintf(firstLine, "Humidity:       ");
					csprintf(secondLine,"%i  %           ",result);
					}
					
					
				
		
		
		
		
				
			
			
			
			
			
		