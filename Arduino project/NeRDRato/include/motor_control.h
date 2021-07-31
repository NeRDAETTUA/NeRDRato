#include <Arduino.h>
#include <stdint.h>

#define MOTOR1_PIN1 5
#define MOTOR1_PIN2 6
#define MOTOR2_PIN1 5
#define MOTOR2_PIN2 5
#define FORWARD 1
#define BACKWARD 0


void init_motors();
void set_motor_speed(int motor, int percentage, bool motor_direction);