#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTTYPE DHT11

const int DHTPIN = 6, RS = 7, EN = 8, D4 = 9, D5 = 10, D6 = 11, D7 = 12;
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup()
{
      Serial.begin(9600); //for error printing
      lcd.begin(16, 2); // inialize the lcd
      lcd.print("Initializing....");
      dht.begin(); // initialize the humidity/temp sensor      
}

void loop()
{
  delay(2000);

  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Fahrenheit
  float tempF = dht.readTemperature(true);

  // check if any reads failed and print to serial if so
  if (isnan(humi)) {
    Serial.println("Failed to read humidity!");
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humi);
    lcd.print("%");
  }
  if (isnan(tempF)){
    Serial.println("Failed to read temperature (F)!");
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Temp:     ");
    lcd.print(tempF);
    lcd.print("F");
  }
  
}
