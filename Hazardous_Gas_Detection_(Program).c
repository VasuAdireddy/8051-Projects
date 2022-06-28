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
	unsigned char Z[7] = {0x01,0x38,0x0E,0x80,0xC0,0x90,0xD0};
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
	delay(3);
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
	for(i=0;i<3;i++)
	{
		comm(i);
	}
	
	if(M2 == 1 && M3 == 1 && M4 == 1 && M5 == 1)
	{
		L2=1;L3=1;L4=1;L5=1;
		comm(3);dat(Q2);
		comm(4);dat(Q3);
		comm(5);dat(Q4);
		comm(6);dat(Q5);
		
	}
	else if(M2 == 1 && M3 == 1)
	{
		L2=1;L3=1;L4=0;L5=0;
		comm(3);dat(Q2);
		comm(4);dat(Q3);
		if(M4 == 1)
		{
			L2=1;L3=1;L4=1;L5=0;
			comm(5);dat(Q4);			
		}
		else if(M5 == 1)
		{
			L2=1;L3=1;L4=0;L5=1;
			comm(6);dat(Q5);			
		}
	}
	else if(M3 == 1 && M4 == 1)
	{
		L2=0;L3=1;L4=1;L5=0;
		comm(4);dat(Q3);
		comm(5);dat(Q4);
		if(M5 == 1)
		{
			L2=0;L3=1;L4=1;L5=1;
			comm(6);dat(Q5);			
		}
	}
	else if(M2 ==1 && M4 == 1)
	{
		L2=1;L3=0;L4=1;L5=0;
		comm(3);dat(Q2);
		comm(5);dat(Q4);
		if(M5 == 1)
		{
			L2=1;L3=0;L4=1;L5=1;
			comm(6);dat(Q5);
		}
	}
	else if(M2 == 1)
	{

		if(M5 == 1)
		{
			L2=1;L3=0;L4=0;L5=1;
			comm(3);dat(Q2);
			comm(6);dat(Q5);			
		}
		else
		{
			L2=1;L3=0;L4=0;L5=0;
			comm(3);dat(Q2);			
		}
	}
	else if(M3 == 1)
	{
		if(M5 == 1)
		{
			L2=0;L3=1;L4=0;L5=1;
			comm(4);dat(Q3);
			comm(6);dat(Q5);			
		}
		else
		{
			L2=0;L3=1;L4=0;L5=0;
			comm(4);dat(Q3);			
		}
	}
	else if(M4 == 1)
	{
		if(M5 == 1)
		{
			L2=0;L3=0;L4=1;L5=1;
			comm(5);dat(Q4);
			comm(6);dat(Q5);			
		}
		else
		{
			L2=0;L3=0;L4=1;L5=0;
			comm(5);dat(Q4);			
		}
	}
	else if(M5 == 1)
	{
		L2=0;L3=0;L4=0;L5=1;
		comm(6);dat(Q5);		
	}
	else
	{
		L2=0;L3=0;L4=0;L5=0;
		comm(3);dat(Q6);
	}
	
}
