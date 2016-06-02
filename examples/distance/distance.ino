/*
The MIT License (MIT)

Copyright (c) Thu Jun 02 2016 Giovanni di Dio Bruno

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORTOR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

socials: @br1johnny
mail:     giovannididio.bruno@gmail.com
*/

/*
DISTANCE EXAMPLE
getDistance -> read distance U3 (sonar) value on your RoBee v2 board

NOTE: STANDBY PIN OF TB6612FNG IS CONNECTED ON ECHO PIN OF HCSR04 SO YOU SHOULD CHOOSE MOTORS VS. SONAR
*/

#include "RoBee.h"
#include <Servo.h>
#include <SoftwareSerial.h>
#include <dht.h>


RoBee my;

void setup(){
    Serial.begin(9600);
}


void loop(){
    Serial.print("Distance: \t");
    Serial.print(my.getDistance());         //get distance default parameter is CM, you can use INCH, too
    Serial.println("\t cm");
    delay(1000);
}