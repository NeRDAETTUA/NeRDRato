#include <Arduino.h>
#include <motor_control.h>
#include <sensors.h>

void setup() {
    Serial.begin(9600);
    sensors_init();
    init_motors();
}

void loop() {
    set_motor_speed(LEFT_MOTOR, 40, FORWARD);
    for(int i=0; i<10; i++){
        print_left_encoder_steps();
        delay(100);
    }
    set_motor_speed(LEFT_MOTOR, 40, BACKWARD);
    for(int i=0; i<10; i++){
        print_left_encoder_steps();
        delay(100);
    }
    /*
    set_motor_speed(1, 100, FORWARD);
    delay(1000);
    set_motor_speed(1, 100, BACKWARD);
    delay(1000);
    */
}