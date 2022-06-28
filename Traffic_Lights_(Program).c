#include<reg51.h>
sbit G1 = P3^0;
sbit Y1 = P3^1;
sbit R1 = P3^2;
sbit G2 = P3^3;
sbit Y2 = P3^4;
sbit R2 = P3^5;

void delay(int ms){
   unsigned int i, j;
   for(i = 0; i< ms; i++){
      for(j = 0; j < 1275; j++){
      }
   }
}

void main(void)
{
	G1 =0;Y1 =0;R1 =0;G2 =0;Y2 =0;R2 =0;
	while(1)
	{
			G1 =1;Y1 =0;R1 =0;G2 =0;Y2 =0;R2 =1;
			delay(500);
			G1 =0;Y1 =1;R1 =0;G2 =0;Y2 =1;R2 =0;
			delay(200);
		 	G1 =0;Y1 =0;R1 =1;G2 =1;Y2 =0;R2 =0;
			delay(500);

	}
}