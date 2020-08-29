#include <dht.h> //A DHT11-es szenzor használatához szükséges könyvtár
#include<Wire.h> //Wire könyvtár beillesztése az I2C busz használatához
#include<LiquidCrystal_I2C.h> //Az I2C Folyékony kristályos LCD kijelző kezelő könyvtára
LiquidCrystal_I2C lcd(0x27, 16, 2); //Az általunk használt kijelző karakterkészlete 16 karakter és 2 sor
dht DHT;
const int dht11 = 10; //konstans globális integer típusú változó mely a DHT11 szenzor pin-jét tárolja
const int led = 12; //konstans globális integer típusú változó mely a LED dióda pin-jét tárolja
void setup() 
{
  lcd.init(); //Az LCD kijelző inicializálása
  lcd.backlight(); //Az LCD kijelző háttérvilágításának bekapcsolása
  pinMode(dht11, INPUT); //A DHT11 által használt Pin bemenetté alakítása
  pinMode(led, OUTPUT); //A LED diódát tartalmazó Pin kimenetté alakítása
  Serial.begin(9600); //A soros porton történő kommunikáció bitrátája
}
void loop() //ciklus
{
  delay(2000); //Várakozás 1 másodpercig
  int chk = DHT.read11(dht11); //A DHT11 értékének a kiolvasása és segédváltozóban tárolása
  Serial.print("Hőmérséklet = "); 
  Serial.println(DHT.temperature); //A Hőmérséklet értékének a soros porton való megjelenítése
  lcd.setCursor(1, 0); //Kurzor pozicionálás ez esetben 1. karakter a 0. sorban
  lcd.print("A HOMERSEKLET:"); //Megadott karakterlánc kiíratása
  lcd.setCursor(5, 1); //Kurzor pozicionálás ez esetben 5. karakter az 1. sorban
  lcd.print(DHT.temperature); //A Hőmérséklet értékének kiíratása
  lcd.setCursor(11,1); //Kurzor pozicionálás ez esetben 11. karakter az 1. sorban
  lcd.print("C"); //Megadott karakter kiíratása
  delay(5000); //Várakozás 5 másodpercig
  lcd.clear(); //Az LCD kijelző tartalmának a törlése
  Serial.print("Páratartalom = ");
  Serial.println(DHT.humidity);//A Páratartalom értékének a soros porton való megjelenítése
  lcd.setCursor(1, 0); //Kurzor pozicionálás ez esetben 1. karakter a 0. sorban
  lcd.print("A PARATARTALOM:"); //Megadott karakterlánc kiíratása
  lcd.setCursor(5, 1); //Kurzor pozicionálás ez esetben 5. karakter az 1. sorban
  lcd.print(DHT.humidity); //A Páratartalom értékének kiíratása
  lcd.setCursor(11,1); //Kurzor pozicionálás ez esetben 11. karakter az 1. sorban
  lcd.print("%"); //Megadott karakter kiíratása
  delay(5000); //Várakozás 5 másodpercig
}
