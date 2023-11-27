/** **************************************************************************************
 * @file
 * @brief          iot_transfer test
 * @note
 * @author          zhangjiayi
 * @date            2023-01-03 06:35:39
 * @version         v0.1
 * @copyright       Copyright (c) 2020-2050  zhangjiayi
 * @par             LastEdit
 * @LastEditTime    2023-01-03 21:36:01
 * @LastEditors     zhangjiayi
 * @FilePath
 *****************************************************************************************/
#include "main.h"
#ifndef SDCC
sbit  LED1 = P3^6;
sbit  LED2 = P3^7;
sbit  NC   = P5^4;
sbit  NO   = P5^5;
#else
SBIT(LED1, 0xB0,6);
SBIT(LED2, 0xB0,7);
SBIT(NC, 0xC8,4);
SBIT(NO, 0xC8,5);
#endif

/** **************************************************************************************
 * @brief delay
 * @note
 * @param void
 * @return
 * @retval
 *****************************************************************************************/
void delay()
{
    int i, j;
    for (i=0; i<1000; i++)
        for (j=0; j<500; j++);
}

/** **************************************************************************************
 * @brief main
 * @note
 * @param void
 * @return
 * @retval
 *****************************************************************************************/
void main(void)
{
    static unsigned long count;
    char temp = 0;
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
    P5M0 = 0x20;
    P5M1 = 0x00;
    P6M0 = 0x00;
    P6M1 = 0x00;
    P7M0 = 0x00;
    P7M1 = 0x00;

    P1 = 0xff;
    delay();
    NC = 0;
    NO = 1;
    for(;; count++)
    {
        if(count%3000 ==0)
        {
            NC = !NC;
            NO = !NO;
        }

        if((P1 & 0x15) == 0)
        {
            LED2 = 1;
        }
        else if((P1 & 0x15) == 0x15)
        {
            LED2 = 0;
        }
        else
        {
            if(count%300 ==0)
            {
                LED2 = !LED2;
            }
        }

        if((P1 & 0x2a) == 0)
        {
            LED1 = 1;
        }
        else if((P1 & 0x2a) == 0x2a)
        {
            LED1 = 0;
        }
        else
        {
            if(count%300 ==0)
            {
                LED1 = !LED1;
            }
        }
    }

}
