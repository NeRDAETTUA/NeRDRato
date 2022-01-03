#include <sensors.h>

static volatile int left_encoder_steps = 0;
static volatile int right_encoder_steps = 0;

void sensors_init(){
    pinMode(OUT1_PIN, INPUT);
    pinMode(OUT2_PIN, INPUT);
    pinMode(OUT3_PIN, INPUT);
    pinMode(OUT4_PIN, INPUT);
    pinMode(OUT5_PIN, INPUT);
    pinMode(LEFT_MOTOR_ENCODER, INPUT);
//    pinMode(RIGHT_MOTOR_ENCODER, INPUT);

    attachInterrupt(digitalPinToInterrupt(LEFT_MOTOR_ENCODER), interrupt_left_encoder, RISING);
//    attachInterrupt(digitalPinToInterrupt(RIGHT_MOTOR_ENCODER), interrupt_right_encoder, RISING);
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

void interrupt_left_encoder(){
    if(get_motor_direction(LEFT_MOTOR) == FORWARD){
        left_encoder_steps++;
    }else{
        left_encoder_steps--;
    }
    /*
    left_encoder_steps++;
    if(left_encoder_steps % ENCODER_SECTORS == 0){
        Serial.println("+1 Rotation");
    }
    */
}

void interrupt_encoder2(){
    
}