int main(void) {
    AD1PCFG = 0xFFFF;   // Configure AN pins as digital I/O
    JTAGEN_bit = 0;     // Disable JTAG
    TRISE = 0XFF;       // portE is inputs to read push-buttons.
    TRISA = 0x0000;     // port a outputs the pattern for DC motors

    while (1) {
        /*
        if(!PORTEbits.RE0 & !PORTEbits.RE1) {
            LATA.F1=0;
            LATA.F2=0;
            Delay_ms(1);
        } else if(!PORTEbits.RE0) {
            // ccw turn
            LATA.F1=0;
            LATA.F2=1;
            Delay_ms(1);
            LATA.F1=0;
            LATA.F2=0;
            Delay_ms(1);
        } else if(!PORTEbits.RE1) {
            // cw turn
            LATA.F1=1;
            LATA.F2=0;
            Delay_ms(1);
            LATA.F1=0;
            LATA.F2=0;
            Delay_ms(1);
        } else {
            LATA.F1=0;
            LATA.F2=0;
            Delay_ms(1);
        }
        */
        // Button 0 for counter clockwise, button 1 for clockwise
        PORTAbits.RA1=PORTEbits.RE0;
        PORTAbits.RA2=PORTEbits.RE1;
        Delay_ms(1);
    }
}