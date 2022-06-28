
#include<reg51.h>
sbit in = P3^1;
sbit enable = P3^5;
sbit RS = P3^6;

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
	delay(25);
	enable = 0;
	RS = 0;
	P2=Z[a];
}

void dat(int b)
{
	unsigned char V[34]="OBSTACLE DETECT OBSTAC NOT DTCT";
	enable = 1;
	
	enable = 0;
	RS = 1;
	P2=V[b];
}


void main(void)
{
	int z;
	for(z =0;z<4;z++)
	{
		comm(z);
	}
	if(in == 1)
	{
		int x;
		for(x=0;x<15;x++)
		{
			dat(x);
		}
	}
	else
	{
		int y;
		for(y=16;y<31;y++)
		{
			dat(y);
		}
	}
}