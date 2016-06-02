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

#include    "RoBee.h"

        RoBee::RoBee():SoftwareSerial(BTRX,BTTX){
    
    pinMode(TRIG,OUTPUT);
    pinMode(ECHO,INPUT);
    
    
    pinMode(RED,OUTPUT);
    pinMode(GREEN,OUTPUT);
    pinMode(BLUE,OUTPUT);
    
    pinMode(BUTT,INPUT);
    pinMode(TRIM,INPUT);
            
    pinMode(PWMA,OUTPUT);
    pinMode(EN1A,OUTPUT);
    pinMode(EN2A,OUTPUT);
    pinMode(PWMB,OUTPUT);
    pinMode(EN1B,OUTPUT);
    pinMode(EN2B,OUTPUT);


    setRGB(0,0,0);
    
    duration=0;
    
}


//----------------------
// sonar
float   RoBee::getDistance(byte m){
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO,HIGH);
    if (m==CM){
        return duration /29 / 2;
    }
    else{
        if (m==INCH){
            return duration / 74 / 2;
        }
        else{
            return -1.0;
        }
    }    
}

//----------------------
// dht11
void   RoBee::dhtUpdate(){
    DHT.read11(UTSD);
}

float   RoBee::getTemperature(){
    return   DHT.temperature;
}

float   RoBee::getHumidity(){
    return   DHT.humidity;
}


//----------------------
// leds
void    RoBee::setRed(int p){
    analogWrite(RED,p);
}

void    RoBee::clearRed(){
    setRed(0);
}

void    RoBee::setGreen(int p){
    analogWrite(GREEN,p);
}

void    RoBee::clearGreen(){
    setGreen(0);
}

void    RoBee::setBlue(int p){
    analogWrite(BLUE,p);
}

void    RoBee::clearBlue(){
    setBlue(0);
}

void    RoBee::setRGB(byte R, byte G, byte B){
    setRed(R);
    setGreen(G);
    setBlue(B);
}

//----------------------
// inputs
int     RoBee::getLux(){
    return 1024-analogRead(LUXS);
}

boolean RoBee::isPressed(){
    return digitalRead(BUTT);
}

int     RoBee::getTrimmer(){
    return analogRead(TRIM);
}

//----------------------
// motors
void    RoBee::attach(int pin){
    Servo::attach(pin);
}

void    RoBee::setMotorA(int s){
    if (s>=0){
        analogWrite(PWMA,s);
        digitalWrite(EN1A,HIGH);
        digitalWrite(EN2A,LOW);
    }
    else{
        analogWrite(PWMA,-s);
        digitalWrite(EN1A,LOW);
        digitalWrite(EN2A,HIGH);
    }
}

void    RoBee::setMotorB(int s){
    if (s>=0){
        analogWrite(PWMB,s);
        digitalWrite(EN1B,HIGH);
        digitalWrite(EN2B,LOW);
    }
    else{
        analogWrite(PWMA,-s);
        digitalWrite(EN1B,LOW);
        digitalWrite(EN2B,HIGH);
    }
}
