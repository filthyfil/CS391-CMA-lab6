// author: fj
// simple test program

#include <stdint.h>

static uint32_t sub(uint32_t a, uint32_t b) {
	return a - b;
}

void main(void) {
	// write to known addresses
	volatile uint32_t *i = (volatile uint32_t *)0x1000;
	volatile uint32_t *j = (volatile uint32_t *)0x1004;
	volatile uint32_t *k = (volatile uint32_t *)0x1008;
	*i = 1;
	*j = 1;
	*k = 1;

	for (; *i < 42; (*i)++) {
		*j = 1;
		for (; *j < 31; (*j)++) {
			*k = *k + 4;
		}
	}
	if (*k >= 1) {
		*j = sub(*k, *i);
	}
	return; 
}
