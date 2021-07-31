#include <Arduino.h>

#define OUT1_PIN 2
#define OUT2_PIN 4
#define OUT3_PIN 7
#define OUT4_PIN 8
#define OUT5_PIN 12

struct ir_sensors{
    bool sensor1;
    bool sensor2;
    bool sensor3;
    bool sensor4;
    bool sensor5;    
};

void sensors_init();
ir_sensors read_sensors();