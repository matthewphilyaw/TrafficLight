#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
    PORTB = 0;
    int mGreen = 10 * 1e3;
    const int mYellow = 3 * 1e3;
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