//*****************************************************************************
//*****************************************************************************
//  FILENAME: I2Cm.h
//   Version: 1.4, Updated on 2012/3/2 at 9:14:44
//  Generated by PSoC Designer 5.2.2551
//
//  DESCRIPTION:  I2Cm User Module C Language interface file.
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef I2Cm_INCLUDE
#define I2Cm_INCLUDE

#include <m8c.h>

// Create pragmas to support proper argument and return value passing
#pragma fastcall16  I2Cm_fReadBytes
#pragma fastcall16  I2Cm_bWriteBytes
#pragma fastcall16  I2Cm_bWriteCBytes
#pragma fastcall16  I2Cm_Start
#pragma fastcall16  I2Cm_Stop
#pragma fastcall16  I2Cm_fSendStart
#pragma fastcall16  I2Cm_fSendRepeatStart
#pragma fastcall16  I2Cm_SendStop
#pragma fastcall16  I2Cm_fWrite
#pragma fastcall16  I2Cm_bRead

//-------------------------------------------------
// Prototypes of the I2Cm API.
//-------------------------------------------------
// High leval commands
extern void  I2Cm_Start(void);
extern BYTE  I2Cm_fReadBytes(BYTE bSlaveAddr, BYTE * pbXferData, BYTE bCnt, BYTE bMode);
extern BYTE  I2Cm_bWriteBytes(BYTE bSlaveAddr, BYTE * pbXferData, BYTE bCnt, BYTE bMode);
extern BYTE  I2Cm_bWriteCBytes(BYTE bSlaveAddr, const BYTE * pcbXferData, BYTE bCnt, BYTE bMode);
extern void  I2Cm_Stop(void);

// Low level commands
extern BYTE  I2Cm_fSendStart(BYTE bSlaveAddr, BYTE fRW);
extern BYTE  I2Cm_fSendRepeatStart(BYTE bSlaveAddr, BYTE fRW);
extern void  I2Cm_SendStop(void);
extern BYTE  I2Cm_fWrite(BYTE bData);
extern BYTE  I2Cm_bRead(BYTE fACK);

//-------------------------------------------------
// Constants for I2Cm API's.
//-------------------------------------------------
#define I2Cm_CompleteXfer   0x00 // Perform a complete I2C transfer
#define I2Cm_RepStart       0x01 // Perform a complete transfer with a Repeat Start
#define I2Cm_NoStop         0x02 // Perform a complete transfer, but leave off the stop

#define I2Cm_READ           0x01 // Set the R/W flag after the slave address.
#define I2Cm_WRITE          0x00 // Clear the R/W flag after the slave address.

#define I2Cm_XFER_ERROR     0x00 // Communication error with the slave.
#define I2Cm_NAKslave       0x00 // NAK the slave after a read.
#define I2Cm_ACKslave       0x01 // ACK the slave after a read.

#endif
// end of file I2Cm.h
