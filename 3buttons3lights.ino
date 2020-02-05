/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 05 -- PUSH BUTTONS
 * 
 *   Use pushbuttons for digital input
 * 
 *   Connect one side of the pushbutton to GND, and the other
 *   side to a digital pin. When we press down on the pushbutton,
 *   the pin will be connected to GND, and therefore will be read
 *   as "LOW" by the Arduino.
 *
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * This code is completely free for any use.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 9/2014 BCH
/*****************************************************************/
#include <LiquidCrystal.h>

const int button1Pin = 7;// pushbutton 1 pin
const int button2Pin = 11;// pushbutton 2 pin
const int button3Pin = 12;// pushbutton 3 pin
const int led1Pin =  13;// LED pin
const int led2Pin =  12;//LED pin
const int led3Pin =  11; //LED pin
int button1State, button2State, button3State;  // variables to hold the pushbutton states
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  // Set up the LED pin to be an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT); 

  lcd.begin(16, 2); //Initialize the 16x2 LCD
  lcd.clear();  //Clear any old data displayed on the LCD
  lcd.print("hello, world!"); // Display a message on the LCD!
}

void loop()
{
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  // if button1 or button 2 are pressed (but not both)
  //(((button1State == LOW) && (button2State == HIGH)) || ((button1State == HIGH) && (button2State == LOW)))
  if ((button1State == LOW) && (button2State == HIGH) && (button3State == HIGH))
  {
    digitalWrite(led1Pin, HIGH);  // turn the LED on
  }
  if ((button1State == HIGH) && (button2State == LOW) && (button3State == HIGH))
  {
    digitalWrite(led2Pin, HIGH);
  }
  if ((button1State == HIGH) && (button2State == HIGH) && (button3State == LOW))
  {
    digitalWrite(led3Pin, HIGH);
  }
  else
  {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);// turn the LED off
  }
}
