### GOAL
Replicate ESP32-Wrover-E Freenove Starter Kit guide projects in a more detailed way through ESP-IDF VS Code extension.
*I've dropped following its guide projects through Arduino as there are quite a number of calls to deprecated functions and I would like to keep staying in a more embedded configuration so that I can grow.*

### PROJECT SETTING
- **ESP32-Wrover-E** Freenove Starter Kit
- **VS Code** with **ESP-IDF** extension
- [optional] Ubuntu OS running on the computer

### 00.Blinking Led [check]
This project was just to check the VS Code with ESP-IDF environment settings.
The same is done on Starter Kit guide.
- **GOAL**: set up VS Code and ESP-IDF extension and run the base example of blinking led making *IO2* led blinking on chip
- Requisites [hardware]:
    - ESP32-Wrover-E (with its cable)
    
#### What I've Learned
I've learned to setting up ESP-IDF extension (and all its on computer requirements) and also how to deal with a multi-folder project as I would like to manage this repository.
Also, I've learned that on ESP32 there are three possible ways to flash the binary on the microcontroller:
- JTAG: Joint Test Action Group, it allows the deepest and more detailed mode to debug, hardware breakpoints, and direct flash access (write the application firmware directly to the flash memory)
- UART
- DFU: Device Firmware Upgrade

### 01.Blinking Led
- **GOAL**: make an external led blinking.
- Requisites [hardware]:
    - ESP32-Wrover-E (with its cable)
    - Resostor (220 Ohm)
    - Led (red)
    
#### What I've Learned
Starting and calling ESP32 timer.
Also, learned a bit how to manage a c/cpp project in VS Code separated in more folders.