#include <Arduino.h>
#include "Motor.h"

int motorPins[6] = {4, 5, 3, 7, 8, 9};

#define forw_time 1000
#define turn_time 700

Motor motor_one(motorPins[0], motorPins[1], motorPins[2]);
Motor motor_two(motorPins[3], motorPins[4], motorPins[5]);

void setup() {
    for(int i = motorPins[0]; i <= motorPins[5]; i ++){
        pinMode(i, OUTPUT);
    }
}

void loop() {
    motor_one.forward(true, 255);
    motor_two.forward(true, 255);
    delay(forw_time);

    motor_one.forward(true, 0);
    motor_two.forward(true, 0);
    delay(forw_time);
}