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
    delay();
    P0M0 = 0x00;
    P0M1 = 0x00;
    P1M0 = 0x00;
    P1M1 = 0x00;
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
    
    P1 = 0x3f;
    
   for(;;count++)
   {
     if(count%100000)
     {
         LED1 = ~LED1;
         NC = ~NC;
         NO = ~NO;
     }
     if(P1 & 0x3f == 0x3f) 
     {
         LED2 = 0;
     }
     else
     {
         LED2 = 1;
     }
   }
    
}



