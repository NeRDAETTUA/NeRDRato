#include <motor_control.h>

bool robot_direction = true; // true -> forward, false -> backward

void init_motors(){
    pinMode(MOTOR1_PIN1, OUTPUT);
    pinMode(MOTOR1_PIN2, OUTPUT);
    pinMode(MOTOR2_PIN1, OUTPUT);
    pinMode(MOTOR2_PIN2, OUTPUT);
}

void set_motor_speed(int motor, int percentage, bool motor_direction){  // true -> forward, false -> backward
    int analog_value = (percentage*255)/100 % 256;

    if(motor == 1 && motor_direction == FORWARD){
        analogWrite(MOTOR1_PIN1, analog_value);
        digitalWrite(MOTOR1_PIN2, 0);
    }else if(motor == 1 && motor_direction == BACKWARD){
        analogWrite(MOTOR1_PIN2, analog_value);
        digitalWrite(MOTOR1_PIN1, 0);
    }else if(motor == 2 && motor_direction == FORWARD){
        analogWrite(MOTOR2_PIN1, analog_value);
        digitalWrite(MOTOR2_PIN2, 0);
    }else if(motor == 2 && !motor_direction == BACKWARD){
        analogWrite(MOTOR2_PIN2, analog_value);
        digitalWrite(MOTOR2_PIN1, 0);
    }
}