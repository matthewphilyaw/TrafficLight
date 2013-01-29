#include <avr/io.h>
#include <util/delay.h>

#define SECOND 1000
#define F_CPU 1200000

int main(void)
{
	DDRB = (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
	PORTB = 0;
	
	const int mGreen = SECOND * 10;
	const int mYellow = SECOND * 3;
	const int mRed = mGreen + mYellow;
	
    while(1)
    {
		PORTB = (1 << DDB2); 
		_delay_ms(mGreen);
		
		PORTB = (1 << DDB1);
		_delay_ms(mYellow);
		
		PORTB = (1 << DDB0);
		_delay_ms(mRed);
    }
}