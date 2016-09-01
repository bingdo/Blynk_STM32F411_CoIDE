
#include <stdio.h>
#include "blynkDependency.h"

#include "gpioHandler.h"
#include "adcHandler.h"

uint8_t digitalRead(uint8_t pin)
{
	uint8_t val = pin;
	val = get_IO_Status(pin);
	printf("digital pin %d read\r\n", pin);
	return val;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	if(val == HIGH) 	IO_On(pin);
	else if(val == LOW)	IO_Off(pin);
	printf("digital pin %d write val %d\r\n", pin, val);
}

uint16_t analogRead(uint8_t pin)
{
	uint8_t analog_pin = 0;
	uint16_t val = 0;
	if(pin >  14) analog_pin = pin - 14;
	val = get_ADC_val(analog_pin);
	printf("analog pin %d read\r\n", analog_pin);
	return val;
}

void analogWrite(uint8_t pin, uint8_t val)
{
	printf("Analog Write: Not supported yet. pin %d, val %d", pin, val);
	printf("analog pin %d write val %d\r\n", pin, val);
}

// Pin mode (dir) defines
// 0: Input
// 1: Output
// 2: Input Pull-up
void pinMode(uint8_t pin, pinmode_dir dir)
{
	if(dir == INPUT) 				IOdata[pin] = Input;
	else if(dir == INPUT_PULLUP)	IOdata[pin] = Input;
	else if(dir == OUTPUT)			IOdata[pin] = Output; // Output
	IO_Init(pin);
	printf("pinmode setting: pin %d dir %d\r\n", pin, dir);
}

// Virtual Pin Read / Write functions; Not fully supported yet
uint16_t virtualRead(uint8_t pin)
{
	printf("virtual pin %d read\r\n", pin);
	return pin;
}

void virtualWrite(uint8_t pin, uint16_t val)
{
	printf("virtual pin %d write val %d\r\n", pin, val);
}
