// Load the LiquidCrystal library, which will give us
// commands to interface to the LCD:

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int LIGHT_SENSOR=0;

const int RED_PIN = 8;
const int GREEN_PIN = 9;
const int BLUE_PIN = 10;

int redLevel=-1, blueLevel=-1, greenLevel=-1;
int high=0;
int low=1023;

const boolean BASELINE=false;

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Spectrometer 1.0");
  
  delay(1000);
}

void loop()
{
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please wait,");
    lcd.setCursor(0,1);
    lcd.print("Analyzing..");
    
    digitalWrite(RED_PIN,HIGH);
    delay(10000);
    redLevel=analogRead(LIGHT_SENSOR);
    
    digitalWrite(RED_PIN,LOW);
    digitalWrite(GREEN_PIN,HIGH);
    delay(10000);
    greenLevel=analogRead(LIGHT_SENSOR);
    
    digitalWrite(GREEN_PIN,LOW);
    digitalWrite(BLUE_PIN,HIGH);
    delay(10000);
    blueLevel=analogRead(LIGHT_SENSOR);
 
    digitalWrite(BLUE_PIN,LOW);
 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Light levels are:");
    lcd.setCursor(0,1);
    lcd.print(redLevel);
    lcd.print(" ");
    lcd.print(greenLevel);
    lcd.print(" ");
    lcd.print(blueLevel);
    delay(10000);   
}

