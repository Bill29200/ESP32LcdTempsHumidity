//.....................................
//#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//.....................................

#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  
 lcd.begin();
 lcd.backlight();
  //................................
   Serial.begin(9600);
   //serial.println(F("DHTxx test!"));
   dht.begin();
   lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,0);
  lcd.print("Hello");
  lcd.setCursor(0,1);
  lcd.print("Bill project");
  
}

void loop() {

  //..................................
// set cursor to first column, first row
 
  delay(1000);
  // clears the display to print new message
  
  lcd.clear(); 
  //..................................
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    //serial.println(F("Failed to read from DHT sensor!"));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");
   lcd.setCursor(0, 1);
   lcd.print("sensor");
    return;
  }
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  //.........................................
  if (t >=30 ){
    lcd.clear();
    //serial.print("Alert temperature >30°C");
    lcd.setCursor(0, 0);
    lcd.print("Alert ...");
   lcd.setCursor(0, 1);
   lcd.print("Tempr plus 30.C ");
    }
   //.........................................
  //serial.print(F("Humidity: "));
  //serial.print(h);
  //...................
  lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("   Tempr:");lcd.print(t);lcd.print(" C");
   lcd.setCursor(0, 1);   
   lcd.print("Humidity:");lcd.print(h);lcd.print(" %");
   //....................
  //serial.print(F("%  Temperature: "));
  //serial.print(t);
  //serial.print(F("°C "));
  //serial.print(f);
  //serial.print(F("°F  Heat index: "));
  //serial.print(hic);
  //serial.print(F("°C "));
  //serial.print(hif);
  //serial.println(F("°F"));

}
