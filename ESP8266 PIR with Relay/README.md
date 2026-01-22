# WiFi PIR Motion Sensor Relay Switch with ESP8266 And Buzzer - AC Powered
The Smart WiFi Motion-Activated Relay Module is an all-in-one IoT solution designed for automated lighting, security, and smart home applications. By combining a high-sensitivity PIR motion sensor, a 10A power relay, and the ESP8266 WiFi MCU, this board allows users to switch AC loads based on physical movement or remote WiFi commands. Best feature supports MQTT, HTTP, and REST APIs, allowing you to view all activity on the server, as well as receive mobile notifications, etc.

The integrated HLK-5M05L power module allows the board to be powered directly from AC mains (100V–240V), eliminating the need for external power bricks.
<hr>

⚠️ **Safety Warning**

High Voltage Hazard: This module operates at AC 100V–240V. Touching the board while it is powered can result in serious injury or death. Always ensure the device is mounted inside its non-conductive enclosure (provided) before applying power.
<hr>

**External Connector (Terminals)**


    INPUT (L / N): Connect your 110V/220V AC Live and Neutral lines here.
    
    OUTPUT (L / N): Connect your AC Load (Light bulb, fan, etc.) here.

<hr>

**Programming Header**


    Use a USB-to-TTL (FTDI) adapter connected to these pins to flash firmware:
    
    GND / 3.3V: Power input for flashing.
    
    TX / RX: Serial communication.
    
    GPIO0: Pull to GND during boot to enter "Flash Mode."
<hr>

**Internal GPIO Mapping**

For developers using Arduino or ESP-IDF, the internal connections are pre-routed on the PCB:

    PIR Sensor: GPIO 5
    
    Buzzer (BUZ): GPIO 4
    
    Relay Control: GPIO 16
