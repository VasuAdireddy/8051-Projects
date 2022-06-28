#include<reg51.h>
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
	unsigned char Z[4] = {0x01,0x38,0x0E,0x95};
	enable = 1;
	delay(25);
	enable = 0;
	RS = 0;
	P2=Z[a];
}

void dat(int b)
{
	unsigned char V[4]={'L','P','U'};
	enable = 1;
	delay(25);
	enable = 0;
	RS = 1;
	P2=V[b];
}

void main(void)
{
	comm(0);
	comm(1);
	comm(2);
	comm(3);
	dat(0);
	dat(1);
	dat(2);	

}
