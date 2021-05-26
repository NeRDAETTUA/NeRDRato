#define SYS_FREQ        84755000UL
#define FCY             SYS_FREQ/2
#define _XTAL_FREQ      84755000UL
#define CLOCK_SystemFrequencyGet()        (84755000UL)
#define CLOCK_PeripheralFrequencyGet()    (CLOCK_SystemFrequencyGet() / 2)
#define CLOCK_InstructionFrequencyGet()   (CLOCK_SystemFrequencyGet() / 2)

/**
 * @brief Initializes clock
 */

void initClock();

