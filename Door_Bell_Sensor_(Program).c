#include <reg51.h>
sbit Dsensor = P1^2;
sbit Buzzer = P1^6;

void msDelay(int k){
int i;
for(i = 0; i < k; i++){
}
}
void main(void)
{
Dsensor = 1;
while(1)
{
Buzzer = 0;
while(1)
{
if(Dsensor == 1)
{
Buzzer = 1;
msDelay(50000);
Buzzer = 0;
msDelay(50000);
if(Dsensor == 0)
{
	Buzzer = 0;
break;
}
}
}
}
}