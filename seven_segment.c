/*
Configuration for the code below:

Connect portA to J1 Port of 4 Digit Seven Segment Module
Jumpers of portA are : 5V, pull down ( top one to left, other to right )

Connect portE to J2 Port of 4 Digit Seven Segment Module
Jumpers of portE are : 5V, pull down ( top one to left, other to right )

*/

// Hexadecimal values for digits in 7 segment
unsigned char binary_pattern[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

int fourthDigit,thirdDigit,secondDigit,firstDigit;  //digits to be displayed
int number_x;       // x for f(x)
int result;         // result of f(x)
int timer;          // temporary needed to make execution slower and visible

int mod(int number){
    return number - (10 * (number / 10));
}

void main() {

 AD1PCFG = 0xFFFF;  // Configure AN pins as digital I/O
 JTAGEN_bit = 0;    // Disable JTAG

 TRISA = 0x00;      //portA is output to D
 TRISE = 0X00;      //portE is output to AN

 number_x = 1;
 result = 1;

 firstDigit = 0;
 secondDigit = 0;
 thirdDigit = 0;
 fourthDigit = 1;

 while(1)
 {
    if(timer > 300) {
        timer = 0;

        result = number_x * number_x * number_x;

        firstDigit = result/1000;
        secondDigit = mod(result/100);
        thirdDigit = mod(result/10);
        fourthDigit = mod(result);

        if (number_x < 21 ) {
            number_x = number_x + 1;  // increase x by 1
        }
        else {
            number_x = 1; // start from 1 after 9261 is reached
        }
    }

    // Digit 1
    PORTA=binary_pattern[firstDigit];   // Put number for the first digit
    PORTE=0x01;                         // Open first digit
    Delay_ms(1);

    // Digit 2
    PORTA=binary_pattern[secondDigit];  // Put number for the second digit
    PORTE=0x02;                         // Open second digit
    Delay_ms(1);

    // Digit 3
    PORTA=binary_pattern[thirdDigit];   // Put number for the third digit
    PORTE=0x04;                         // Open third digit
    Delay_ms(1);

    // Digit 4
    PORTA=binary_pattern[fourthDigit];  // Put number for the fourth digit
    PORTE=0x08;                         // Open fourth digit
    Delay_ms(1);

    timer++;
 }
}//main