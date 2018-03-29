#include <ubidots.h> 
#define DEVICE  "uco_parking"  // Put here your Ubidots device label
#define VARIABLE_1  "count"  // Put here your Ubidots variable label
#define  VARIABLE_2 "Tempreture"
#define VARIABLE_3 "Status"
#define TOKEN  "BBFF-i38tlKFwQxEVNb4z1KccTcZfsa79xG"  // Put here your Ubidots TOKEN
#define WIFISSID "ATT3mIQ5fU" // Put here your Wi-Fi SSID
#define PASSWORD "4ex4ww?7zbp6" // Put here your Wi-Fi password
//LCD Commands 
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

Ubidots client(TOKEN);

void setup() {

//lcd intialize 
lcd.begin (20,4); //  <<----- My LCD was 16x2
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home

//client serial

Serial.begin(115200);
client.wifiConnection(WIFISSID, PASSWORD);
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, 1);
//client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop() {
    float value_1 = client.getValueWithDevice(DEVICE, VARIABLE_1);
        float value_2 = client.getValueWithDevice(DEVICE, VARIABLE_2);
    float value_3 = client.getValueWithDevice(DEVICE, VARIABLE_3);

    if (value != ERROR_VALUE){
      Serial.print(F("value obtained: "));
      Serial.println(value_1);
      Serial.println(value_2);
      Serial.println(value_3);


    }else{
      Serial.println(F("Error getting value"));
    }
    delay(1000);
lcd.setCursor (0,0);        // go to start of 1st line
lcd.print("Free Spots:");
lcd.print(value_1)
lcd.setCursor (0,1);        // go to start of 2nd line
lcd.print("-------------------- ");
lcd.setCursor (0,2);        // go to start of 3rd line
lcd.print("Tempreture:");
lcd.print(value_2);
lcd.setCursor (0,3);        // go to start of 4th line
lcd.print("Status:");
lcd.print(value_3);
}


