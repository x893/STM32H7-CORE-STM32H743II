/**
  @page Simple CANopen slave example

  @verbatim
  ******************************************************************************
  * @file    readme.txt
  * @author  emotas embedded comunication GmbH
  * @brief   Description of Simple CANopen slave example.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 emotas embedded comunication GmbH.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the License.pdf file.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

@note Initialization
  If you have selected the Slave Application in CubeMX generator,
  a simple CANopen initialization example will be added to your project.
  It's in the function MX_CANopen_Init() and will be called in main().
  If you did not select the Slave Application,
  you would have to implement your own initialization.
  Please refer the user manual for that.
  /Middlewares/Third_Party/emotas_CANopen/CANopenSlaveLibrary/Documentation

@note HAL_IncTick() is overwritten in app_canopen.c to provide a timer to the CAnopen stack.
  This is necessary to calculate timings and timeouts.
  you can use a own timer for this by calling coTimerTick() by yourself
  but you have to provide the interval
  by setting the #define CO_TIMER_INTERVAL in the file gen_dfine.h
  or even better by setting it in the CAnopen DeviceDesigner.
  If you dont change this also make sure that the SysTick time base
  is always set to 1 millisecond.

@note CAN GPIO Pins
  You have to activate the CAN peripheral in the Cube Settings,
  and setup the correct CAN GPIO Pins.
  You don't have to calculate a CAN bitrate and set it up in the Cube.
  Just leave the default values.
  
  We encountered problems with different evaluation boards,
  which share CAN GPIO pins with other peripherals.
  It is recommed to use the option "Set all free pins as analog" in the STM32CubeMX settings,
  and to setup all needed debug pins before starting.

@note CAN Clock
  Depending on the Clock Settings you setup in the Cube,
  the CAN Clock differs from device to device.
  Therefore we added the file codrv_canbittiming.c,
  which contents of many CAN bittiming tables for usual used CAN Clock frequencies.
  The default CAN Clock frequency is 40 MHz.
  It is set by the #define CODRV_CANCLOCK_40MHZ 1
  in the CANopen DeviceDesigner Project (emotas_CANopen_Slave.cddp) (see @note Object Dictionary)  
  If your CAN Clock frequency is different, please check codrv_canbittiming.c,
  to look for a suitable CAN bittiming table, and change #define CODRV_CANCLOCK_xXxMHZ.
  If there is no suitable CAN bittiming table in codrv_canbittiming.c,
  you can create a own table with the help of a generator by our colleague Heinz-Jürgen Oertel.
  http://www.bittiming.can-wiki.info

@note Configuration
  Information how to configure the CANopen slave at runtime can be found the user manual.
  Please keep the CANopen library limitations in mind!

@note Object Dictionary
  To change the CANopen services and object dictionary entries,
  you can use the CANopen Configuration Tool called CANopen DeviceDesigner (CDD).
  A Demo version can be downloaded here:
  https://www.emotas.de/tools/setup-emotas-cdd-3_10_0.zip
  In Demo mode the complexity of the object dictionary is very limited!

@note Support
  Questions that are not answered in the user manual can only be sent to: 
  evaluation@emotas.de

@note Full Evaluation
  We can provide a time-limited full version of the CANopen DeviceDesigner
  The limitations of the CANopen evaluation library however still stay the same as mentioned above.
  If interested, contact us and share the following information:
    - Full Name
    - Company Name
    - Company Address
    - Company Email Address
    - Company Telephone

@par Keywords

CAN, FDCAN, CANopen.

@par Directory contents

  - /CANopen/App/app_canopen.h  CANopen application header file
  - /CANopen/App/app_canopen.c  CANopen application file
  - /Src/main.c                 Main program
  - /Src/system_stm32g4xx.c     STM32G4xx system clock configuration file
  - /Src/stm32g4xx_it.c         Interrupt handlers
  - /Src/stm32g4xx_hal_msp.c    HAL MSP module
  - /Inc/main.h                 Main program header file
  - /Inc/stm32g4xx_hal_conf.h   HAL Configuration file
  - /Inc/stm32g4xx_it.h         Interrupt handlers header file


@par Hardware and Software environment

  - This software runs on most STM32 devices with MCAN CAN controller.
	At this point supported:
	- STM32G0
	- STM32G4
	- STM32H5
	- STM32H7
	- STM32L5
	- STM32U5

  - The example has been tested with NUCLEO-G431RB board and can be
    easily tailored to any other supported device and development boards.


@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example
 */
