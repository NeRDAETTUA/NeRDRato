#include <sensors.h>

void sensors_init(){
    pinMode(OUT1_PIN, INPUT);
    pinMode(OUT2_PIN, INPUT);
    pinMode(OUT3_PIN, INPUT);
    pinMode(OUT4_PIN, INPUT);
    pinMode(OUT5_PIN, INPUT);
}

ir_sensors read_sensors(){
    ir_sensors sensor_struct;

    sensor_struct.sensor1 = digitalRead(OUT1_PIN);
    sensor_struct.sensor2 = digitalRead(OUT2_PIN);
    sensor_struct.sensor3 = digitalRead(OUT3_PIN);
    sensor_struct.sensor4 = digitalRead(OUT4_PIN);
    sensor_struct.sensor5 = digitalRead(OUT5_PIN);

    return sensor_struct;
}