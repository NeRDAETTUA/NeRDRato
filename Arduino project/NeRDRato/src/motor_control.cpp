#include <motor_control.h>

volatile bool left_motor_direction = FORWARD;
volatile bool right_motor_direction = FORWARD;

void init_motors(){
    pinMode(LEFT_MOTOR_PIN1, OUTPUT);
    pinMode(LEFT_MOTOR_PIN2, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
}

void set_motor_speed(int motor, int percentage, bool motor_direction){  // true -> forward, false -> backward
    int analog_value = (percentage*255)/100 % 256;

    if(motor == LEFT_MOTOR && motor_direction == FORWARD){
        analogWrite(LEFT_MOTOR_PIN1, analog_value);
        digitalWrite(LEFT_MOTOR_PIN2, 0);
        left_motor_direction = motor_direction;
    }else if(motor == LEFT_MOTOR && motor_direction == BACKWARD){
        analogWrite(LEFT_MOTOR_PIN2, analog_value);
        digitalWrite(LEFT_MOTOR_PIN1, 0);
        left_motor_direction = motor_direction;
    }else if(motor == RIGHT_MOTOR && motor_direction == FORWARD){
        analogWrite(RIGHT_MOTOR_PIN2, analog_value);
        digitalWrite(RIGHT_MOTOR_PIN2, 0);
        right_motor_direction = motor_direction;
    }else if(motor == RIGHT_MOTOR && motor_direction == BACKWARD){
        analogWrite(RIGHT_MOTOR_PIN1, analog_value);
        digitalWrite(RIGHT_MOTOR_PIN2, 0);
        right_motor_direction = motor_direction;
    }
}

bool get_motor_direction(int motor){
    if(motor == LEFT_MOTOR){
        return left_motor_direction;
    }else if(motor == RIGHT_MOTOR){
        return right_motor_direction;
    }
    
}