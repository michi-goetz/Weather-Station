Project:      output/weather_station
Build Number: 0
Date:         Wed Apr 04 12:04:37 2012
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0150   027B =    635. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01D8  LoadConfigTBL_weather_station_Bank0
       0233  LoadConfigTBL_weather_station_Bank1
       0256  __ctype
       03CB  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   03CB   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       03CB  __func_lit_start
       03CD  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   03CD   0135 =    309. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03CD  LoadConfigTBL_weather_station_Ordered
       0492  _LoadConfigInit
       0492  LoadConfigInit
       04AB  _LoadConfig_weather_station
       04AB  LoadConfig_weather_station
       0502  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0502   068F =   1679. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0502  _SleepTimer_ISR
       0522  _SleepTimer_EnableInt
       0522  SleepTimer_EnableInt
       0526  SleepTimer_DisableInt
       0526  _SleepTimer_DisableInt
       052A  SleepTimer_Start
       052A  _SleepTimer_Start
       053B  SleepTimer_Stop
       053B  _SleepTimer_Stop
       053C  SleepTimer_SetInterval
       053C  _SleepTimer_SetInterval
       054E  _SleepTimer_TickWait
       054E  SleepTimer_TickWait
       055D  SleepTimer_SyncWait
       055D  _SleepTimer_SyncWait
       056B  _SleepTimer_bGetTickCntr
       056B  SleepTimer_bGetTickCntr
       056E  SleepTimer_SetTimer
       056E  _SleepTimer_SetTimer
       0571  _SleepTimer_bGetTimer
       0571  SleepTimer_bGetTimer
       0574  SleepTimer_iGetTickCntr
       0574  _SleepTimer_iGetTickCntr
       057F  SleepTimer_lGetTickCntr
       057F  _SleepTimer_lGetTickCntr
       0598  _LCD_PrCString
       0598  LCD_PrCString
       05AA  LCD_HEX_STR
       05BA  _LCD_PrHexByte
       05BA  LCD_PrHexByte
       05CD  _LCD_PrHexInt
       05CD  LCD_PrHexInt
       05D4  LCD_PrString
       05D4  _LCD_PrString
       05DE  _LCD_Write_Data
       05DE  _LCD_WriteData
       05DE  LCD_Write_Data
       05DE  LCD_WriteData
       05F2  _LCD_Control
       05F2  LCD_Control
       0699  _LCD_Init
       0699  LCD_Init
       0699  LCD_Start
       0699  _LCD_Start
       0705  LCD_ROW_OFFSET
       0709  _LCD_Position
       0709  LCD_Position
       0715  LCD_Delay50uTimes
       0715  _LCD_Delay50uTimes
       071B  LCD_Delay50u_Table
       0723  LCD_Delay50u
       0723  _LCD_Delay50u
       0737  LCD_DrawBG
       075D  _LCD_DrawBG
       0786  LCD_DrawVBG
       07B3  _LCD_DrawVBG
       07E3  LCD_InitVBG
       07E3  _LCD_InitVBG
       0810  LCD_BG_TYPE1
       0817  LCD_BG_TYPE2
       081E  _LCD_InitBG
       081E  LCD_InitBG
       084E  _I2Cm_Start
       084E  I2Cm_Start
       0868  _I2Cm_Stop
       0868  I2Cm_Stop
       0869  _I2Cm_fReadBytes
       08B2  I2Cm_fReadBytes
       08F6  _I2Cm_bWriteBytes
       0933  I2Cm_bWriteBytes
       096B  _I2Cm_bWriteCBytes
       09AB  I2Cm_bWriteCBytes
       09E8  _I2Cm_fSendRepeatStart
       09E8  I2Cm_fSendRepeatStart
       0A1B  _I2Cm_fSendStart
       0A1B  I2Cm_fSendStart
       0A4C  I2Cm_fWrite
       0A4C  _I2Cm_fWrite
       0ACB  I2Cm_bRead
       0ACB  _I2Cm_bRead
       0B5E  _I2Cm_SendStop
       0B5E  I2Cm_SendStop
       0B91  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0B91   0C69 =   3177. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0B91  _measuring
       0B91  __text_start
       0CC7  _printtemp
       0D3E  _printhum
       0DB5  _main
       0FF6  __plcall
       1002  _itoa
       117F  _utoa
       127D  _isdigit
       129B  _islower
       12B9  _isspace
       12D7  _toupper
       130C  __csdepi
       1326  _csprintf
       1365  __cprint
       17FA  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0000   0009 =      9. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __rZ
       0001  __rY
       0002  __rX
       0003  __r5
       0004  __r4
       0005  __r3
       0006  __r2
       0007  __r1
       0008  __r0
       0009  __virtual_registers_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                    InterruptRAM   0009   000D =     13. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0009  SleepTimer_fTick
       0009  _SleepTimer_fTick
       000A  _SleepTimer_bTimerValue
       000A  SleepTimer_bTimerValue
       000B  SleepTimer_bCountDown
       000B  _SleepTimer_bCountDown
       000C  SleepTimer_TickCount
       000C  _SleepTimer_TickCount
       0010  _Port_0_Data_SHADE
       0010  Port_0_Data_SHADE
       0010  _NO_SHADOW
       0010  NO_SHADOW
       0011  _Port_2_Data_SHADE
       0011  Port_2_Data_SHADE
       0012  _Port_0_DriveMode_0_SHADE
       0012  Port_0_DriveMode_0_SHADE
       0013  _Port_0_DriveMode_1_SHADE
       0013  Port_0_DriveMode_1_SHADE
       0014  Port_2_DriveMode_0_SHADE
       0014  _Port_2_DriveMode_0_SHADE
       0015  _Port_2_DriveMode_1_SHADE
       0015  Port_2_DriveMode_1_SHADE
       0016  __InterruptRAM_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0016   001B =     27. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0016  __bss_start
       0031  __bss_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
             weather_station_RAM   0031   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0031  _I2Cm_bStatus
       0031  I2Cm_bStatus
       0032  _I2Cm_bData
       0032  I2Cm_bData
       0033  _I2Cm_bAddr
       0033  I2Cm_bAddr
       0035  __weather_station_RAM_end
       0035  __ramareas_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             TOP   0000   00D7 =    215. bytes (abs,ovr,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __Start
       00D4  _bGetPowerSetting
       00D4  bGetPowerSetting

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
./obj/hyt271.o	[ hyt271.c ]
./obj/main.o	[ main.c ]
<library>	[ sleeptimerint.asm, sleeptimer.asm, psocconfigtbl.asm, psocconfig.asm, lcd.asm, i2cm.asm, rZ.asm ]
[ rY.asm, rX.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmod_16x16_16_util.asm, divmodu_16x16_16_util.asm ]
[ i_div16_block_util.asm, mul16_util.asm, plcall.s, itoa.s, utoa.s, isdigit.s, islower.s, isspace.s ]
[ ctype.s, toupper.s, sprintf.s, _printf.s ]

Area Definitions

-blit:0x150.0x3fff
-bdata:0.0xff
-rwh:SSCParmBlk:0xf7.0xff

