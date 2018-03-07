# MSPMotorControl
This is an implementation of a closed loop DC motor velocity control system using the MSP430 and a Motor Driver.

## Requirements

1. MSP430F5529LP board
2. Code Composer Studio (CCS) or some way to compile and flash to the MSP
3. A TI DRV8871 motor driver
4. A DC Motor with some digital rotary encoder
5. Some external Power Supply to power the DC Motor
6. P1.2 available for use (With a bit of work this can be modified)

## Usage

1. Clone the repo
2. Put it in CCS (or whatever development environment you use)
3. Connect the MSP, Motor driver, Motor all together. (You should test things separately first)
4. Flash the program to the MSP
5. Connect a serial Terminal, set it to 9600 baud, start bit, stop bit, no parity.
6. Enjoy
