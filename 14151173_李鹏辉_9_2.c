#include<stdio.h>
struct data
{
	int year;
	int month;
	int day;
}D;
int day(struct data D)
{
	int i,s=0;
	for(i=1;i<D.month;i++)
	{
		switch(i)
		{
		    case 1: s+=31;break;
			case 3: s+=31;break;
			case 4: s+=30;break;
			case 5: s+=31;break;
			case 6: s+=30;break;
			case 7: s+=31;break;
			case 8: s+=31;break;
			case 9: s+=30;break;
			case 10: s+=31;break;
			case 11: s+=30;break;
			case 12: s+=31;break;
			default:{
				       if(D.year%4==0 && D.year%100!=0 || D.year%400==0) s+=29;
				       else s+=28;
					}
		}
	}
	s+=D.day;
	return (s);
}
void main()
{
	printf("请输入年、月、日：");
	scanf("%d,%d,%d",&D.year,&D.month,&D.day);
	printf("第%d天\n",day(D));
}
