#include <stdio.h> 
     struct date{
     	int year;
     	int month;
     	int day;
	 } a;
int main(){
	int jisuan(date a);
	int b;
	scanf("%d%d%d",&a.year,&a.month,&a.day);
	b=jisuan(a);
	printf("%d",b);
    return 0;
}

int jisuan(date a){
	int b=0,c=0,i;
	if(a.year%4==0&&a.year%100!=0||a.year%400==0){
		b=1;
	}
	for(i=1;i<a.month;i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			c=c+31;
		}
		if(i==4||i==6||i==9||i==11){
			c=c+30;
		}
		if(i==2){
			if(b==1)
			c=c+29;
			if(b==0)
			c=c+28;
		}
	}
	c=c+a.day;
	return c;
};
