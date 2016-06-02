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

#ifndef     __ROBEE_H__
#define     __ROBEE_H__

#include    "RoBeeDef.h"
#include    "Arduino.h"
#include    <Servo.h>
#include    <SoftwareSerial.h>
#include    <dht.h>





class       RoBee: public Servo, public SoftwareSerial{
    private:
            long    duration;
            dht     DHT;
    
    public:
            RoBee();
        
    //get Sonar distance
    float   getDistance(byte m=CM);
    
    
    void    dhtUpdate();
    //get DHT11 temperature
    float   getTemperature();
    //get DHT11 humidity
    float   getHumidity();
    
    //get photo-resistor value 0 is dark, 1024 is bright 
    int     getLux();
    
    //get button status
    boolean isPressed();
    
    //get trimmer value
    int     getTrimmer();
    
    //leds commands
    void    setRed(int p=255);
    void    clearRed();
    void    setGreen(int p=255);
    void    clearGreen();
    void    setBlue(int p=255);
    void    clearBlue();
    void    setRGB(byte R, byte G, byte B);
    
    //servo functions are the same of Servo.h
    void    attach(int pin=SERVO);
    
    //motors range -255:255
    void    setMotorA(int);
    void    setMotorB(int);

    
};





#endif