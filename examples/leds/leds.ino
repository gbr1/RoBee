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
LEDS EXAMPLE
It shows implemented methods for RGB led L1 on RoBee v2 
*/


#include "RoBee.h"
#include <Servo.h>
#include <SoftwareSerial.h>
#include <dht.h>

RoBee my;

void setup(){
    
    //ON OFF methods
    my.setRed();                //Red is turned ON
    delay(1000);
    my.clearRed();              //Red is turned OFF
    
    my.setGreen();              //Green is turned ON
    delay(1000);
    my.clearGreen();            //Green is turned OFF
    
    my.setBlue();               //Blue is turned ON
    delay(1000);
    my.clearBlue();             //Blue is turned OFF
    
}


void loop(){
    
    //PWM methods
    
    //Red
    for (int i=0; i<255;i++){
        my.setRed(i);
        delay(10);
    }
    my.clearRed();
    delay(1000);
    
    //Green
    for (int i=0; i<255;i++){
        my.setGreen(i);
        delay(10);
    }
    my.clearGreen();
    delay(1000);
    
    //Blue
    for (int i=0; i<255;i++){
        my.setBlue(i);
        delay(10);
    }
    my.clearBlue();
    delay(1000);
    
    
    //RGB method
    for (int i=0; i<255;i++){
        my.setRGB(i,i,i);
        delay(10);
    }
    my.setRGB(0,0,0);
    delay(1000);
    
}