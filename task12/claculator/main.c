/*
 * KeyPad_program.c

 *
 *  Created on: Jul 11, 2024
 *      Author: Utente
 */

#include "MCAL/Dio/Dio.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/KEYPAD/KeyPad_interface.h"

u8 Cheack_Password(u8 a[],u8 b[],u8 n);
u16 calc_sum(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_sub(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m);
u16 calc_div(  u8 a[],u8 b[],u8 n,u8 m);

void INT0_Interrupt();
u8 counter = 0;
u8 KpValue=255;                       //variable to store the pressed button for Keypad
u8 NumberOfDigit=0;                   //variable to calculate the number of digit of password
u8 Pasword[16];						 //array to store the password when set
u8 CheckPasword[16];					 //array to store the password when check
u8 Reset=1;

u8 FristNum[4];                       //Array to store the first number (Assuming the number of digits 4)
u8 SecondNum[4];						 //Array to store the Second number (Assuming the number of digits 4)
int main()
{
	Dio_init();
	LCD_Init();

	/*   Set Password for First time   */
	LCD_Send_String_Pos("Set password",1,1);
	while(1){
		do{
			KpValue = GetPressed();
		}while(KpValue != '&');
		NumberOfDigit++;
		if(KpValue == '&') break;
		LCD_Send_Number_Pos(KpValue,2,NumberOfDigit);
		_delay_ms(200);
		LCD_Send_Char_Pos('*',2,NumberOfDigit);
		Pasword[NumberOfDigit] =KpValue;

	}

	while(1)
	{

		/*    Get Password To Check It    */
		LCD_Send_Command(lcd_clear);
		_delay_ms(100);
		LCD_Send_String_Pos("check password",1,1);
		KpValue='\0';
		counter=0;
		while(KpValue != '&'){     // & --> on/off button

			do{
				KpValue = GetPressed();
			}while(KpValue == '\0');
			counter++;
			if(KpValue == '&') break;
			LCD_Send_Number_Pos(KpValue,2,counter);
			_delay_ms(200);
			LCD_Send_Char_Pos('*',2,counter);
			CheckPasword[counter] =KpValue;
		}



		/*   Check if Password is correct or not  */
		if(Cheack_Password(CheckPasword,Pasword,NumberOfDigit))
		{

			/*   Loading to Start Calculator    */
			LCD_Send_Command(lcd_clear);
			LCD_Send_String_Pos("Loading",1,1);
			for(u8 counter=0;counter<4;counter++)
			{
				LCD_Send_Char_Pos('.',1,counter+8);
				_delay_ms(500);
			}
			_delay_ms(200);
			LCD_Send_Command(lcd_clear);
			LCD_Send_String_Pos("Welecome",1,1);


			Reset=1;
			/*    loop for repeating the calculation    */
			while(1){
				LCD_Send_String_Pos("calc is ready",2,1);
				_delay_ms(1000);
				LCD_Send_Command(lcd_clear);
				//KpValue == '\0';
				counter=0;
				u8 opration=0;


				/*    Getting The First Number    */
				while(1)
				{
					do{
						KpValue = GetPressed();
						_delay_ms(200);
					}while(KpValue == '\0');
					if(KpValue == '+' || KpValue == '-' || KpValue == '/' || KpValue == '*'){
						opration = KpValue;
						LCD_Send_Char_Pos(KpValue,1,counter+1);
						break;
					}
					FristNum[counter]=KpValue;
					counter++;
					LCD_Send_Number_Pos(KpValue,1,counter);

				}
				u8 counter2=counter+1;
				u8 counter3=0;


				/*    Getting The Second Number    */
				while(1)
				{
					do{
						KpValue = GetPressed();
						_delay_ms(200);
					}while(KpValue == '\0');
					if(KpValue == '=' ){
						LCD_Send_Char_Pos(KpValue,1,counter2+1);
						break;}
					SecondNum[counter3]=KpValue;
					counter2++;
					counter3++;
					LCD_Send_Number_Pos(KpValue,1,counter2);
				}


				/*     switch which operation was Selected */
				switch(opration)
				{
					case '+': LCD_Send_Number_Pos(calc_sum(FristNum,SecondNum,counter,counter3),1,counter2+3);break;
					case '-': LCD_Send_Number_Pos(calc_sub(FristNum,SecondNum,counter,counter3),1,counter2+3);break;
					case '*': LCD_Send_Number_Pos(calc_multi(FristNum,SecondNum,counter,counter3),1,+3);break;
					case '/': LCD_Send_Number_Pos(calc_div(FristNum,SecondNum,counter,counter3),1,counter2+3);break;
				}
				_delay_ms(3000);
				LCD_Send_Command(lcd_clear);
				}

		}
		/*   This Segment if The Password is Wrong    */
		else{
			LCD_Send_Command(lcd_clear);
			LCD_Send_String_Pos("Wrong password",1,1);
			_delay_ms(2000);
		}

	}
}


void INT0_Interrupt()
{
	Reset=0;
}

u8 Cheack_Password(u8 a[],u8 b[],u8 n)
{
	u8 ret=0;
	for(u8 counter =0; counter<n-1;counter++)
	{
		if(a[counter] == b[counter])
		{
			ret++;
		}
	}
	if(ret == n-1)
		return 1;
	else
		return 0;
}

u16 calc_sum(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{

		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1+num2);
}

u16 calc_sub(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1-num2);
}

u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1*num2);
}

u16 calc_div(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0];
	u16 num2=b[0];
	for(u8 counter=1;counter<n;counter++)
	{
		num1 = num1*10 +a[counter];
	}

	for(u8 counter=1;counter<m;counter++)
	{
		num2= num2*10 +b[counter];
	}

	return (num1/num2);
}


