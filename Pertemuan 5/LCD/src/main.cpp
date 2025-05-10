#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D3;
int SCL_pin = D2;
LiquidCrystal_I2C lcd(0x27,26,1);

void setup() {
Wire.begin(SDA_pin,SCL_pin);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Yongpokz ");
lcd.setCursor(0,1);
lcd.print("2nd kkimjangz ");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(200);
}

