//
// Created by Константин on 02.03.2025.
//
#ifndef MOTOR_H
#define MOTOR_H

class Motor {
public:
    Motor(int positive_pin, int negative_pin, int rotation_pin);

    void forward(bool state, int turn_speed);
    void turn_move(int speed);
    void soft_stop();
    void stop();

private:
    int _positive_pin;
    int _negative_pin;
    int _rotation_pin;
};

#endif //MOTOR_H
