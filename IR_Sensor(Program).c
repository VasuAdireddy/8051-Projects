#include<reg51.h>
sbit out = P3^5;
sbit in = P3^6;

void main(void)
{
	out =0;
	if(in == 1)
	{
		out = 1;
	}
	else
	{
		out = 0;
	}
}