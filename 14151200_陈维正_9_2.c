#include<stdio.h> 
int main()
{
int days(int x,int y,int z);
int a,b,c;
printf("请输入年月日：");
scanf("%d%d%d",&a,&b,&c);
printf("该天是本年的第%d天",days(a,b,c));
}

int days(int x,int y,int z)
{
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if(x%100!=0&&x%4==0)
	a[1]=29;
if(x%400==0)
	a[1]=29;
int i,h=0;
for(i=0;i<=y-2;i++)
	h=h+a[i];
h=h+z;
return(h);
}
