//
// Created by Константин on 02.03.2025.
//
#include <Arduino.h>
#include "Motor.h"

Motor::Motor(int positive_pin, int negative_pin, int rotation_pin) {
    pinMode(positive_pin, OUTPUT);
    pinMode(negative_pin, OUTPUT);
    pinMode(rotation_pin, OUTPUT);

    _positive_pin = positive_pin;
    _negative_pin = negative_pin;
    _rotation_pin = rotation_pin;
}

void Motor::forward(bool state, int turn_speed) {
    digitalWrite(_positive_pin, state);
    digitalWrite(_negative_pin, !state);
    analogWrite(_rotation_pin, turn_speed);
}

void Motor::turn_move(int speed) {
    if (speed > 0) {
        digitalWrite(_positive_pin, HIGH);
        digitalWrite(_negative_pin, LOW);
    } else if (speed < 0) {
        digitalWrite(_positive_pin, LOW);
        digitalWrite(_negative_pin, HIGH);
    } else {
        stop(); // Остановка мотора при нулевой скорости
    }
    analogWrite(_rotation_pin, abs(speed)); // Модуль скорости
}

void Motor::soft_stop() {
    for (int speed = 255; speed >= 0; speed--) {
        analogWrite(_rotation_pin, speed);
        delay(10); // Можно настроить длительность задержки
    }
    digitalWrite(_positive_pin, LOW);
    digitalWrite(_negative_pin, LOW);
}

void Motor::stop() {
  digitalWrite(_positive_pin, LOW);
  digitalWrite(_negative_pin, LOW);
  analogWrite(_rotation_pin, 0);
}

