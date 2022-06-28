#include<reg51.h>
void delay(int ms){
   unsigned int i, j;
   for(i = 0; i< ms; i++){
      for(j = 0; j < 1275; j++){
      }
   }
}
void main(void)
{
unsigned char V[8]={0xF9,0xF9,0x98,0xC0,0xA4,0xA4,0xB0,0xF9};
int a;
while(1)
{
	for(a = 0; a < 8; a++)
	{
		P0 = V[a];
		delay(50);
		P0=0xFF;
		delay(150);
	}
}
}
