# define F_CPU 1000000
#include <avr/io.h>
# include <util/delay.h>
void lcd_init();
void disp_cmd(unsigned int cmd);
void disp_data(int cmd);
void disp_num(unsigned int num);
void disp_string(  char *str);
void special_charswastik();
void special_charom();
void special_charringbell1();
 void special_charringbell2();
 void special_charringbell3();
int main(void)
{
	
	DDRB = 0XFF;

	lcd_init();
	special_charswastik();//0
	special_charom();//1
	special_charringbell1();//2
	special_charringbell2();//3
	special_charringbell3();//4
	while(1)
	{
		
		disp_cmd(0X84);
		disp_data(2);
		
		
		
		//disp_cmd(0X01);
		_delay_ms(1);
		disp_cmd(0X84);
		disp_data(3);
		_delay_ms(1);
		//disp_cmd(0X01);
		_delay_ms(0.5);
		disp_cmd(0X84);
		disp_data(4);
		_delay_ms(1);
		//disp_cmd(0X01);
		//_delay_ms(0.5);
	}

return 0;
}	
	
	void special_charswastik()//0
	{
		disp_cmd(0X40);
		disp_data(0X17);
		disp_data(0X14);
		disp_data(0X14);
		
	disp_data(0X1F);
	disp_data(0X05);
	disp_data(0X05);
	disp_data(0X1D);
	
	}
	void special_charom()//1
	{
		disp_cmd(0X48);
		disp_data(0X1E);
		disp_data(0X12);
		disp_data(0X02);
		
		disp_data(0X07);
		disp_data(0X13);
		disp_data(0X0B);
		disp_data(0X0F);
		
	}
	
	void special_charringbell1()//2
	{
		
		
		disp_cmd(0X50);
		disp_data(0X04);
		disp_data(0X0E);
		disp_data(0X11);
		
		disp_data(0X11);
		disp_data(0X11);
		disp_data(0X1F);
		disp_data(0X08);
		
		
				
		
	}
	void special_charringbell2()//3
	{
		disp_cmd(0X58);
		disp_data(0X04);
		disp_data(0X0E);
		disp_data(0X11);
		
		disp_data(0X11);
		disp_data(0X11);
		disp_data(0X1F);
		disp_data(0X04);
	}
	void special_charringbell3()//4
	{
		disp_cmd(0X60);
		disp_data(0X04);
		disp_data(0X0E);
		disp_data(0X11);
		
		disp_data(0X11);
		disp_data(0X11);
		disp_data(0X1F);
		disp_data(0X02);
	}
	void disp_cmd(unsigned int cmd)
	{
		PORTB=((cmd & 0XF0)+0X04);
		_delay_ms(1);
		PORTB=PORTB - 0X04;
		PORTB=(((cmd<<4)& 0XF0)+0X04);
		_delay_ms(1);
		PORTB=PORTB-0X04;
		
	}
	void disp_data( int cmd)
	{
		PORTB=((cmd  & 0XF0)+0X05);
		_delay_ms(1);
		PORTB=PORTB - 0X04;
		PORTB=(((cmd <<4)& 0XF0)+0X05);
		_delay_ms(1);
		PORTB=PORTB-0X04;
		
	}

	void disp_string( char *str)
	{
		int i=0;
		while (str[i]!='\0')
		{
			disp_data (str[i]);
			i++;
			
		}
	}

	void disp_num(unsigned int num)
	{
		int a=0;
		if (num==0)
		{
			disp_data(48);
		}
		disp_cmd (0X04);
		while (num!=0)
		{
			a=num % 10;
			disp_data(a+48);
			num=num/10;
		}
	}
	void lcd_init()
	{
		disp_cmd(0X02);
		disp_cmd(0X28);
		disp_cmd(0X0C);
		disp_cmd(0X06);
	}		