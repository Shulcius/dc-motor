//
// Created by Константин on 02.03.2025.
//
#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int positive_pin, int negative_pin, int rotation_pin) {
    int nums[3] {positive_pin, negative_pin, rotation_pin};
    for(int i = nums[0]; i <= nums[2]; i++) {
        pinMode(i, OUTPUT);
    }

    _positive_pin = positive_pin;
    _negative_pin = negative_pin;
    _rotation_pin = rotation_pin;
}

void Motor::forward(bool state, int turn_speed) {
    digitalWrite(_positive_pin, state);
    digitalWrite(_negative_pin, !state);
    analogWrite(_rotation_pin, turn_speed);
}

void Motor::turn_move(bool rotation) {
  digitalWrite(_positive_pin, !rotation);
  digitalWrite(_negative_pin, rotation);
  analogWrite(_rotation_pin, round(255/2));
}

void Motor::stop() {
  digitalWrite(_positive_pin, LOW);
  digitalWrite(_negative_pin, LOW);
  analogWrite(_rotation_pin, 0);
}

