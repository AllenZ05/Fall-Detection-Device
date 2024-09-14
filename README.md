# Fall-Detection-Device

A Fall Detection Device designed to assist the elderly by detecting falls and notifying caregivers in real-time. Falls, trips, and balance issues are the most common cause of injury for adults aged 65+. This device addresses those concerns by providing a reliable and immediate response to such incidents, ultimately improving the quality of life for seniors

## Features
  
- **Fall Detection:** Detects falls through accelerometer and gyroscope sensors
- **Timer-based Auto Alert:** A timer starts when a fall is detected. If the cancel button isn't pressed within a set time, an automatic call for help is initiated
- **LED Indicators:** Provides visual feedback on device status (e.g., fall detected, timer active, help requested)
- **Emergency Button:** Allows the user to manually trigger an alert in case of an emergency
- **Cancel Button:** Lets the user cancel false alarms before automatic alerting
- **Call for Help:** Automatically sends a distress signal to the caregiver via GSM if no intervention occurs during the timer

## Hardware Components 

- **STM32 Nucleo-64 Development Board:** STM32F401RE MCU
- **MPU6050:** Accelerometer/gyroscope sensor
- **GSM Module:** Sends alerts
- **LED Lights:** Provides visual feedback
- **Push Buttons:** Emergency and cancel functionalities

## Tech Stack

- **Programming Languages:** C/C++
- **Microcontroller:** STM32 Nucleo-64 (STM32F401RE)
- **Sensors:** MPU6050 accelerometer/gyroscope
- **Communication:** GSM Module
  
## Timeline 

- **Sep - Oct 2023:** Planning and design phase
- **Nov 2023:** Development and coding phase