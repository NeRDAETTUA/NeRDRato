#include <Arduino.h>
#include <stdint.h>

#define LEFT_MOTOR_PIN1 9 
#define LEFT_MOTOR_PIN2 6
#define RIGHT_MOTOR_PIN1 11 
#define RIGHT_MOTOR_PIN2 10 
#define LEFT_MOTOR 1
#define RIGHT_MOTOR 2
#define FORWARD 1
#define BACKWARD 0


void init_motors();
void set_motor_speed(int motor, int percentage, bool motor_direction);
bool get_motor_direction(int motor);