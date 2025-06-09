# UART-H7 
This is my first foray into using CMSIS for embedded development. Using CMSIS allows me to save time by not needing to define any registers - CMSIS does that for me.   

Functionality: 
- Press user button 1 to toggle the 3 leds (LD1, LD2, LD3) on/off. Uses an interrupt with no debouncing. Button is connect to VCC. 
- IN DEVELOPMENT: UART driver to send serial data to usb port on computer. 

### Dependencies: 
#### STM32CubeH7
To get STM32CubeH7, use the following command in the same directory that this repository is stored:
```
git clone git@github.com/STMicroelectronics/STM32CubeH7.git
```

