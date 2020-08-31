#include <dht.h> //The DHT11 library
#include<Wire.h> //Wire library for I2C
#include<LiquidCrystal_I2C.h> //Library for the I2C LCD

LiquidCrystal_I2C lcd(0x27, 16, 2); //The charset of the LCD
dht DHT;

const int dht11 = 10; //Global constant integer type variable containing the pin the DHT11 sensor is connected to
const int led = 12; //Global constant integer type variable containing the pin the LED diode is connected to

void setup() 
{
  lcd.init(); //LCD initialization
  lcd.backlight(); //LCD backlight on
  pinMode(dht11, INPUT); //Setting the DHT11 pin as an INPUT
  pinMode(led, OUTPUT); //Setting the LED pin as an OUTPUT
  Serial.begin(9600); //Serial port bitrate
}

void loop() //ciklus
{
  delay(2000); //1 second long delay
  int chk = DHT.read11(dht11); //Reading and storing the values comming from the sensor
  Serial.print("Hőmérséklet = "); //Displaying the value of Temperature on the Serial port
  Serial.println(DHT.temperature); //Displaying the value of Temperature on the Serial port
  lcd.setCursor(1, 0); //Cursor positioning
  lcd.print("A HOMERSEKLET:"); //Printing out the string
  lcd.setCursor(5, 1); //Cursor positioning
  lcd.print(DHT.temperature); //Displaying the value of Temperature on the LCD display
  lcd.setCursor(11,1); //Cursor positioning
  lcd.print("C"); //Printing out the char "C"
  delay(5000); //5 second long delay
  lcd.clear(); //Clearing the LCD content
  Serial.print("Páratartalom = "); //Printing out the string on the Serial port
  Serial.println(DHT.humidity);//Displaying the value of Humidity on the Serial port
  lcd.setCursor(1, 0); //Cursor positioning
  lcd.print("A PARATARTALOM:"); //Printing out the string
  lcd.setCursor(5, 1); //Cursor positioning
  lcd.print(DHT.humidity); //Displaying the value of Humidity on the LCD display
  lcd.setCursor(11,1); //Cursor positioning
  lcd.print("%"); //Printing out the string on the LCD display
  delay(5000); //5 second long delay
}
