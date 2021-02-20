# CryptoPrice-Display
Get the current price of cryptocurrencies with the ESP8266 and OLED display
### What you need: 
* ESP8266 board: https://www.aliexpress.com/item/32665100123.html
* OLED display: https://www.aliexpress.com/item/32683094040.html
* Female to female jumper wires

### Necessary libraries:
* esp8266-oled-ssd1306: https://github.com/ThingPulse/esp8266-oled-ssd1306 please, install version 4.1.0, 4.2.0 doesn't work for me
* ArduinoJson: https://github.com/bblanchon/ArduinoJson
* And install driver for ESP8266 to Arduino IDE

### Application configuration:
For the code with the config note:
* change the SSID
* WiFi password
* the number of cryptocurrencies you want to monitor
* which currencies you want to monitor
* in which currency you want to display the exchange rate

### Wiring 

| Pin On Display| Pin on ESP8266 |
| ------------- |----------------|
| GND     | G |
| VCC     | 3V (some boards say 3.3V |
| SCL (Sometimes SCK)    | D5 |
| SDA     | D3 |

Do you like it? You can send me some change as a reward
* BTC: bc1q763x4mg990fy862h28l5vd7eexdnuvww89wszj
* ETH: 0x247674d37843932562D42501553A845bcA5Cc9B6
* DOGE: DF1Ps9VnM5nP61R9Cj7g5rAE55dR3t4GU4

### Images
![alt text](https://hodlerio.cz/CryptoDisplay/1.jpg "Display 1")
![alt text](https://hodlerio.cz/CryptoDisplay/2.jpg "Display 2")
![alt text](https://hodlerio.cz/CryptoDisplay/3.jpg "Display 3")
