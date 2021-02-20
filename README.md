# CryptoPrice-Display
Get the current price of cryptocurrencies with the ESP8266 and OLED display
What you need: 
ESP8266 board: https://www.aliexpress.com/item/32665100123.html
OLED display: https://www.aliexpress.com/item/32683094040.html
Female to female jumper wires

Necessary libraries:
esp8266-oled-ssd1306: https://github.com/ThingPulse/esp8266-oled-ssd1306 please, install version 4.1.0, 4.2.0 doesn't work for me
ArduinoJson: https://github.com/bblanchon/ArduinoJson
And install driver for ESP8266 to Arduino IDE

Application configuration:
For the code with the config note:
change the SSID
WiFi password
the number of cryptocurrencies you want to monitor
which currencies you want to monitor
in which currency you want to display the exchange rate
