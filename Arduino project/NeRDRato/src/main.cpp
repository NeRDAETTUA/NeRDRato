#include <Arduino.h>
#include <motor_control.h>
#include <sensors.h>

void setup() {
    Serial.begin(9600);
    sensors_init();
    init_motors();
}

void loop() {
    delay(3000);
    set_motor_speed(1, 40, FORWARD);
    /*
    set_motor_speed(1, 100, FORWARD);
    delay(1000);
    set_motor_speed(1, 100, BACKWARD);
    delay(1000);
    */
}