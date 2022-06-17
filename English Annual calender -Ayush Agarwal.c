
#include<stdio.h>
#include<math.h>

int month_days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *month_name[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int get_first_daycode(int year)
{
	int daycode;
	int x, y, z;
	
	x = (year - 1) / 4;
	y = (year - 1) / 100;
	z = (year - 1) / 400;
	daycode = (year + x - y + z) %7;
	return daycode;
}


void set_feb_days(int year)
{
	if(year% 4 == 0 && year%100 != 0 || year%400 == 0)
	   month_days[2] = 29;
	else
	   month_days[2] = 28;
}

void print_calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s, %d", month_name[month], year);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
		
		
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}
		
		// For loop from day 1 to last day of month,for printing all the dates for one month
		for ( day = 1; day <= month_days[month]; day++ )
		{
			printf("%2d", day );
			
			// Checking if day before Saturday, otherwise start next line from Sunday.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Here setting position for next month, according to the daycode
			daycode = ( daycode + month_days[month] ) % 7;
	}
}

int main(void)
{
	int year, daycode, leapyear;
	
	printf("Please Enter a Four Digit Year,{Example} 2022 : ");
	scanf("%d", &year);
	daycode = get_first_daycode(year);
	set_feb_days(year);
	print_calendar(year, daycode);
	printf("\n");
	return 0;
}