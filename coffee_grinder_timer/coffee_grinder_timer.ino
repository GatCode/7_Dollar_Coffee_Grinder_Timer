//title           :coffee_grinder_timer.ino
//description     :This is a small timer program for a coffee grinder
//description     :realized with a Digispark MCU
//author          :GatCode
//year            :2017
//notes           :please feel free to adapt it to your needs

// Copyright (c) 2017 GatCode

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//==============================================================================

//------------------------------------------------------------------------------
// Input Pins
//
const byte POTENTIOMETER = 0; //Analog Input 0
const byte GRINDER = 0; //Digital Output 0
const byte BUTTON = 1; //Digital Input 1

//------------------------------------------------------------------------------
// Variables
//
const int min_grind_time = 4000; //minimum grinding time is 4 seconds
const int grind_time_multiplier = 8; //to achieve 8 sec. potentiometer delay

int potentiometer_value = 0;
int grinding_time = 0;

//------------------------------------------------------------------------------
// Setup
//
void setup()
{
  pinMode(GRINDER, OUTPUT);
  pinMode(BUTTON, INPUT);
}

//------------------------------------------------------------------------------
// Loop
//
void loop()
{
  potentiometer_value = analogRead(POTENTIOMETER);
  grinding_time = min_grind_time + (potentiometer_value * grind_time_multiplier);

  if(digitalRead(BUTTON))
  {
    digitalWrite(GRINDER, HIGH);
    delay(grinding_time);
    digitalWrite(GRINDER, LOW);
  }
}
