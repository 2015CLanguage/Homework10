#include<stdio.h>
int days(int year,int month,int day);


struct//定义结构体
{
	int year;
	int month;
	int day;
}date;

int main()
{	
	printf("请输入年，月，日：");
	scanf("%d,%d,%d",&date.year,&date.month,&date.day);//输入
	printf("%d月%d日，是%d年的第%d天\n",date.month,date.day,date.year,days(date.year,date.month,date.day));//调用
	return 0;
}

int days(int year,int month,int day)//定义函数
{
	int i;
	int days=0;
	int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	for(i=1;i<month;i++)//计数
		days=days+day_tab[i];
	days=days+day;
	
	if((year%4==0&&year%100!=0||year%400==0)&&month>=3)//闰年加天数
		days=days+1;

	return(days);

}
