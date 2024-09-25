#define F_CPU 8000000
#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"

void segment_diplay(char n)
{
	const char seg_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	char r=0;
	r=n%10;
	n=n/10;
	PORTC=0b01000000;
	PORTA=seg_arr[r]<<1;
	_delay_ms(10);
	PORTC=0b10000000;
	PORTA=seg_arr[n]<<1;
	_delay_ms(10);
	
}
void segment_diplay2(char n)
{
	const char seg_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	char r=0;
	r=n%10;
	n=n/10;
	PORTC=0b10000000;
	PORTA=seg_arr[n]<<1;
	_delay_ms(1);
	PORTC=0b01000000;
	PORTA=seg_arr[r]<<1;
	_delay_ms(1);
	
}


void segment_diplay_mono(char n)
{
	const char seg_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
	PORTA=seg_arr[n]<<1;
}

