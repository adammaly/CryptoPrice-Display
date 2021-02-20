#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <Wire.h>
#include "SH1106.h"      //https://github.com/ThingPulse/esp8266-oled-ssd1306 use version 4.1.0, 4.2.0 doesn't work for me
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson
#include "images.h"

//config
int amountOfCryptos = 5; // type amount of cryptocurrencies
String cryptos[] = {"bitcoin","ethereum","litecoin","dogecoin","bitcoin-cash"}; // find your crypto here: https://api.coingecko.com/api/v3/coins/list
String cryptosShow[] = {"BITCOIN","ETHEREUM","LITECOIN","DOGECOIN","BCH"}; // type the name you want to appear on the display
String currency = "usd"; // find your currency here: https://api.coingecko.com/api/v3/simple/supported_vs_currencies
String symbol = "$"; //currency symbol
char ssid[] = "WiFi name";          // your network SSID (name)
char password[] = "Wifi password";  // your network key
// Pins based on your wiring
#define SCL_PIN D5
#define SDA_PIN D3

unsigned long screenChangeDelay = 10000;
WiFiClientSecure client;

SH1106 display(0x3c, SDA_PIN, SCL_PIN);

unsigned long screenChangeDue;

String ipAddressString;

void setup() {
  Serial.begin(115200);

  // Initialising the display
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 0, F("CryptoPrice"));
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 18, F("By Adam Malý"));
  display.drawXbm(34, 30, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
  display.display();
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  ipAddressString = ip.toString();
}

int i = 0;
int decimal;
void loop() {
  unsigned long timeNow = millis();
   if (timeNow > screenChangeDue && i <= amountOfCryptos && WiFi.status() == WL_CONNECTED)  {
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();
    HTTPClient http;
    http.begin(*client, "https://api.coingecko.com/api/v3/simple/price?ids=" + cryptos[i] + "&vs_currencies=" + currency + "&include_24hr_change=true");
    int httpCode = http.GET();
                                                                
StaticJsonDocument<96> doc;

DeserializationError error = deserializeJson(doc, http.getString());
if (error) {
  Serial.print(F("deserializeJson() failed: "));
  Serial.println(error.f_str());
}
float price = doc[cryptos[i]][currency];
float change24h = doc[cryptos[i]][currency + "_24h_change"];
if (price > 100) {
  decimal = 2;
}
else decimal = 4;
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 0, (cryptosShow[i]));
  display.setFont(ArialMT_Plain_24);
  display.drawString(64, 18, (symbol + String(price, decimal)));
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 48, "24h: " + String(change24h) + "%");
  display.display();
    http.end(); 
i++;
if (i == amountOfCryptos)
   i = 0;
screenChangeDue = timeNow + screenChangeDelay;
   }
}
