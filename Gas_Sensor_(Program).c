#include<reg51.h>
sbit M2 = P3^0;
sbit M3 = P3^1;
sbit M4 = P3^2;
sbit M5 = P3^3;
sbit enable = P3^6;
sbit RS = P3^4;
sbit L2 = P1^4;
sbit L3 = P1^5;
sbit L4 = P1^6;
sbit L5 = P1^7;

void delay(int ms){
   unsigned int i, j;
   for(i = 0; i< ms; i++){
      for(j = 0; j < 1275; j++){
      }
   }
}

void comm(int a)
{
	unsigned char Z[4] = {0x01,0x38,0x0E,0x80};
	enable = 1;
	delay(1);
	enable = 0;
	RS = 0;
	P2=Z[a];
}
void dat(unsigned char b[16])
{
	int k;
	for(k=0;k<16;k++)
	{
	enable = 1;
	delay(1);
	enable = 0;
	RS = 1;
	P2=b[k];
	}
}
void main(void)
{
	unsigned char Q2[]={"SMOKE IS HIGH"};
	unsigned char Q3[]={"ALCOHOL IS HIGH"};
	unsigned char Q4[]={"CNG GAS IS HIGH"};
	unsigned char Q5[]={"NATURAL GAS HIGH"};
	unsigned char Q6[]={"ALL GAS ARE LOW"};
	int i;
	for(i=0;i<4;i++)
	{
		comm(i);
	}
	
	if(M2 == 1)
	{
		dat(Q2);
		L2=1;L3=0;L4=0;L5=0;
	}
	else if(M3 == 1)
	{
		dat(Q3);
		L2=0;L3=1;L4=0;L5=0;
	}
	else if(M4 == 1)
	{
		dat(Q4);
		L2=0;L3=0;L4=1;L5=0;
	}
	else if(M5 == 1)
	{
		dat(Q5);
		L2=0;L3=0;L4=0;L5=1;
	}
	else
	{
		dat(Q6);
		L2=0;L3=0;L4=0;L5=0;
	}	
}