#include "main.h"
sbit  LED1 = P3^6;
sbit  LED2 = P3^7;
sbit  NC   = P5^4;
sbit  NO   = P5^5;

void delay()
{
    int i, j;

    for (i=0; i<1000; i++)
    for (j=0; j<500; j++);
}
void main(void)
{
    static unsigned long count;
    char temp;
    delay();
    P0M0 = 0x00;
    P0M1 = 0x00;
    P1M0 = 0x00;
    P1M1 = 0xff;
    P2M0 = 0x00;
    P2M1 = 0x00;
    P3M0 = 0x00;
    P3M1 = 0x00;
    P4M0 = 0x00;
    P4M1 = 0x00;
    P5M0 = 0x00;
    P5M1 = 0x00;
    P6M0 = 0x00;
    P6M1 = 0x00;
    P7M0 = 0x00;
    P7M1 = 0x00;
    
    P1 = 0xff;
    delay();
    temp = P1;
    
   for(;;count++)
   {
     if(count%10000 ==0)
     {
         LED1 = ~LED1;
         NC = ~NC;
         NO = ~NO;
     }
     if(P1 == temp) 
     {
         LED2 = 1;
     }
     else
     {
         LED2 = 0;
     }
   }
    
}



