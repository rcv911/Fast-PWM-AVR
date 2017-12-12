#include <avr\io.h>
#include <avr\interrupt.h>
#include <avr\signal.h>

#define ANTI	for(int a=0; a<20; a++);

int main(void) {
	// button
	DDRB = 0;
	PORTB = 255;
	// led
	DDRC = 255;
	PORTC = 0;
	// t/c1
	// fast PWM 8bit, CLK/256, TOP(ICR1)=0x00ff
	TCCR1A=(1<<COM1A1)|(0<<WGM11)|(1<<WGM10);
	TCCR1B=(0<<WGM13)|(1<<WGM12)|(1<<CS12);

	OCR1A=50;
	TCNT1=0;
	
	while(1) {
		unsigned int count;
		if(PINB==254) {   // button0
			ANTI
			if(count<254) {
				for(int i=0; i<1000;i++); //delay
				count++;
				OCR1A = count;
			}
		}
		
		if(PINB==253) {   // button1
			ANTI
			if(count>0) {
				for(int i=0; i<1000;i++); //delay
				count--;
				OCR1A = count;
			}
		}

   }
}


