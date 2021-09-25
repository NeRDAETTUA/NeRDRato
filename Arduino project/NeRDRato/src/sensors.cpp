#include <sensors.h>

static volatile int encoder1_steps = 0;
static volatile int encoder2_steps = 0;

void sensors_init(){
    pinMode(OUT1_PIN, INPUT);
    pinMode(OUT2_PIN, INPUT);
    pinMode(OUT3_PIN, INPUT);
    pinMode(OUT4_PIN, INPUT);
    pinMode(OUT5_PIN, INPUT);
    pinMode(MOTOR1_ENCODER, INPUT);
//    pinMode(MOTOR2_ENCODER, INPUT);

    attachInterrupt(digitalPinToInterrupt(MOTOR1_ENCODER), interrupt_encoder1, RISING);
//    attachInterrupt(digitalPinToInterrupt(MOTOR2_ENCODER), interrupt_encoder2, RISING);
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

void interrupt_encoder1(){
    encoder1_steps++;
    if(encoder1_steps % ENCODER_SECTORS == 0){
        Serial.println("+1 Rotation");
    }
}

void interrupt_encoder2(){
    
}