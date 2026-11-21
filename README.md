# 2026FA-ENGR-2304-3-AZAK-ISMAIL-P09

# ENGR 2304 Final Project
## Pressure Regulation and Rocket Launch Countdown System

### 1. Project Description

This project uses an Arduino Uno to simulate a pressure regulation system with a rocket launch countdown sequence.

The program accepts a desired pressure from the user through a potentiometer and compares it with a simulated current pressure reading. When the desired pressure is reached, the compressor output is deactivated and a countdown sequence begins.

The countdown is displayed on a 16x2 LCD and four LEDs using binary representation.

### 2. Hardware Components

The project uses the following components:

- Arduino Uno
- Two potentiometers
- 16x2 I2C LCD
- Four LEDs for binary countdown
- One red LED for compressor status indication
- Resistors
- Breadboard
- Four-AA battery holder (not currently connected)

### 3. Pin Configuration

| Arduino Pin | Component | Function |
|---|---|---|
| A0 | Potentiometer 1 | Target pressure input |
| A2 | Potentiometer 2 | Current pressure input |
| D7 | Red LED | Compressor status output |
| D13 | Countdown LED 1 | Binary bit 0 |
| D12 | Countdown LED 2 | Binary bit 1 |
| D8 | Countdown LED 3 | Binary bit 2 |
| D4 | Countdown LED 4 | Binary bit 3 |
| A4 | LCD SDA | I2C data |
| A5 | LCD SCL | I2C clock |

### 4. Program Functionality

The program operates in the following sequence:

1. Initialize the Arduino pins and LCD.
2. Read the target pressure from the first potentiometer.
3. Read the simulated current pressure from the second potentiometer.
4. Convert analog readings into a pressure scale of 0–100 PSI.
5. Compare the target pressure with the current pressure.
6. Activate the compressor output when current pressure is below the target.
7. Deactivate the compressor output when the target pressure is reached.
8. Initiate a countdown from 10 to 0.
9. Display the countdown on the LCD and LEDs in binary.
10. Display "LIFTOFF!" when the countdown finishes.

### 5. Binary Number Convention

All numeric values in the program are represented in binary unless they use the `0x` prefix for hexadecimal notation.

Examples:

| Binary | Decimal |
|---|---:|
| 0b0111 | 7 |
| 0b1000 | 8 |
| 0b1010 | 10 |
| 0b1100100 | 100 |
| 0b1111111111 | 1023 |

The four countdown LEDs represent the four bits of a binary number. The Arduino uses the `bitRead()` function to determine which LEDs should turn on or off.

### 6. Software and Libraries

The project uses:

- Arduino C++ (Arduino IDE)
- Adafruit LiquidCrystal library
- Wire library for I2C communication
- Tinkercad Circuits for hardware simulation

### 7. How to Run

1. Open the project in Tinkercad Circuits.
2. Open the Arduino code editor.
3. Insert the project source code.
4. Start the circuit simulation.
5. Adjust the target pressure potentiometer.
6. Adjust the current pressure potentiometer.
7. Observe the compressor indicator and LCD.
8. Once the target pressure is reached, observe the countdown sequence.

### 8. GitHub Collaboration

The project source code is maintained in a GitHub repository.

Two classmates are invited to review the source code and propose improvements through Pull Requests. Accepted revisions are merged into the main branch.

### 9. Project Limitations

This project is an educational simulation. The potentiometers simulate pressure readings rather than measuring actual pressure. The compressor output is represented by an LED and does not operate a physical compressor.

The countdown is a visual demonstration and does not activate any physical launch or ignition mechanism.

### 10. Author

**Ismail Azak**

ENGR 2304 - Programming for Engineers

Fall 2026
