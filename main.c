

#include "MemMap.h"
#include "StdTypes.h"
#include "7segment.h"




#define F_CPU 8000000
#include <util/delay.h>


/* Counting mode 

1-PIND2  : tO restart the count down 
2-PIND3  : to pause 
3-PIND3  : to edit

*/

/* Edit mode

1-PIND2  : to increase tens
2-PIND3  : to increase ones
3-PIND3  : first press to edit tens
           second press to edit ones	 
		   third to back to counting mode and start count  
*/


	 
u8 mode=1,c=0;
s8 x=Min_u8;
int main(void)
{
	DDRC=0x00;
	DDRA=0xff;
	DDRD=0x00;
	u8 i=Min_u8,flag=Min_u8;
	while(1)
	{
		if(mode>2)
		{
			mode=0;
		}
		
		if(mode==0)
		{
			x=c   ;
			for (x=c;x>=Min_u8;x--)
			{
				
				for(i=0;i<=50;i++)
				{
					
					if(!GET_BIT(PIND,2))
					{
						x=c;
						_delay_ms(10);
						while(!GET_BIT(PIND,2));
						_delay_ms(10);
					}
					if(!GET_BIT(PIND,3)&&flag==0)
					{
						_delay_ms(10);
						while(!GET_BIT(PIND,3));
						flag=1;
						for(;;)
						{
							segment_diplay(x);
							if(!GET_BIT(PIND,3)&&flag==1)
							{
								break;
							}
						}
						
					}
					if(flag==1)
					{
						flag=0;
						while(!GET_BIT(PIND,3));
					}
					if(!GET_BIT(PIND,4))
					{
						break;
					}
					segment_diplay(x);
					
				}
				if(!GET_BIT(PIND,4))
				{
					while(!GET_BIT(PIND,4));
					_delay_ms(10);
					mode++;
					break;
				}
			}
			while(x<0)
			{
				segment_diplay(0);
				if(x<0 && !GET_BIT(PIND,2))
				{
					while(!GET_BIT(PIND,4));
					_delay_ms(10);
					break;
				}
				if(!GET_BIT(PIND,4))
				{
					while(!GET_BIT(PIND,4));
					_delay_ms(10);
					mode++;
					break;
				}
			}
			
		}
		if(mode==1)
		{
			
			for(;;)
			{
				
				if(!GET_BIT(PIND,2))
				{
					_delay_ms(80);
					while(!GET_BIT(PIND,2));
					_delay_ms(10);
					c=c+10;
				}
				if(c>99)
				{
					c=0;
				}
				if(!GET_BIT(PIND,4))
				{
					while(!GET_BIT(PIND,4));
					_delay_ms(10);
					mode++;
					break;
				}
				segment_diplay2(c);
				
			}
		}
		if(mode==2)
		{
			for(;;)
			{
				if(!GET_BIT(PIND,3))
				{
					_delay_ms(10);
					while(!GET_BIT(PIND,3));
					_delay_ms(10);
					c=c+1;
				}
				if(c>99)
				{
					c=0;
				}
				if(!GET_BIT(PIND,4))
				{
					while(!GET_BIT(PIND,4));
					_delay_ms(10);
					mode++;
					break;
				}
				segment_diplay(c);
			}
		}
		
	}	
		
} 
	



	







 