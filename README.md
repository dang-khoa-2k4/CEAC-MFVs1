# CEAC-MFVs1

## Description

This project implements the firmware for a multi-functional vehicle (MFV) based on the STM32F4xx microcontroller. The vehicle appears to support multiple modes of operation including configuration, Bluetooth control, maze solving, and line following.

## Hardware

*   **Microcontroller:** STM32F4xx series (Specific model inferred from HAL/CMSIS drivers)
*   **Sensors:**
    *   Infrared (IR) sensors ([`Core/Inc/IR.h`](Core/Inc/IR.h))
    *   Ultrasonic sensors ([`Core/Inc/ultraSonic.h`](Core/Inc/ultraSonic.h))
    *   Encoders ([`Core/Inc/encoder.h`](Core/Inc/encoder.h))
*   **Actuators:**
    *   DC Motors (controlled via PWM [`Core/Inc/PWMcontrol.h`](Core/Inc/PWMcontrol.h))
    *   Servo motor ([`Core/Inc/PWMcontrol.h`](Core/Inc/PWMcontrol.h))
*   **Communication:**
    *   HC-08 Bluetooth Low Energy (BLE) module ([`Core/Inc/communication.h`](Core/Inc/communication.h))
    *   UART for debugging/communication
*   **User Interface:**
    *   Buttons ([`Core/Inc/input_reading.h`](Core/Inc/input_reading.h))
    *   LEDs ([`Core/Inc/led_display.h`](Core/Inc/led_display.h))

## Software & Tools

*   **Language:** C
*   **IDE:** STM32CubeIDE (inferred from project files)
*   **Framework/Libraries:**
    *   STM32Cube HAL ([`Drivers/STM32F4xx_HAL_Driver`](Drivers/STM32F4xx_HAL_Driver))
    *   CMSIS ([`Drivers/CMSIS`](Drivers/CMSIS))

## Features

*   **Finite State Machine (FSM):** Manages different operating modes ([`Core/Inc/FSM.h`](Core/Inc/FSM.h)).
    *   **Configuration Mode:** Allows hardware testing and setup (e.g., servo calibration, color sensor calibration) ([`Core/Inc/FSM_config.h`](Core/Inc/FSM_config.h)).
    *   **BLE Mode:** Handles Bluetooth communication and control ([`Core/Inc/FSM_BLE.h`](Core/Inc/FSM_BLE.h)).
    *   **Maze Solving Mode:** Implements maze navigation logic ([`Core/Inc/FSM_maze.h`](Core/Inc/FSM_maze.h)).
    *   **Line Following Mode:** Implements line following algorithms ([`Core/Inc/FSM_line.h`](Core/Inc/FSM_line.h)).
*   **Motor Control:** PWM control for motors, potentially with PID regulation ([`Core/Inc/PID.h`](Core/Inc/PID.h)).
*   **Sensor Processing:** Reading and filtering data from various sensors (e.g., [`Core/Inc/average_filter.h`](Core/Inc/average_filter.h)).
*   **EEPROM Emulation:** Storing configuration data in Flash memory ([`Core/Inc/EEPROM_emulation.h`](Core/Inc/EEPROM_emulation.h)).
*   **Scheduler:** Simple task scheduling ([`Core/Inc/scheduler.h`](Core/Inc/scheduler.h)).

## Folder Structure

```
.
├── Core/                 # Main application code
│   ├── Inc/              # Header files (.h)
│   ├── Src/              # Source files (.c)
│   └── Startup/          # Startup file (.s)
├── Drivers/              # MCU and board-specific drivers
│   ├── CMSIS/            # Cortex Microcontroller Software Interface Standard
│   └── STM32F4xx_HAL_Driver/ # STM32F4xx Hardware Abstraction Layer
├── .settings/            # IDE specific settings (e.g., STM32CubeIDE)
├── .vscode/              # VS Code specific settings
├── Debug/                # Output directory for debug builds (ignored by git)
├── .gitignore            # Specifies intentionally untracked files that Git should ignore
└── README.md             # This file
```

## Getting Started

1.  **Clone the repository:**
    ```bash
    # Navigate to your desired workspace directory in the terminal
    cd d:\git_workspace
    git clone <repository-url> # Replace <repository-url> with the actual URL
    cd CEAC-MFVs1
    ```
2.  **Open the project:** Open the project folder `.\CEAC-MFVs1` in STM32CubeIDE.
3.  **Build the project:** Build the project using the IDE's build command.
4.  **Flash the microcontroller:** Connect the STM32 board and flash the compiled firmware using a debugger (like ST-Link).

*(Add more specific instructions regarding hardware connections, dependencies, or configuration steps if necessary.)*
