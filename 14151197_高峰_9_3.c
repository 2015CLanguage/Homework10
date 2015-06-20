#include <stdio.h>
struct Student{
	int num;
	char name[20];
	int ke1;
	int ke2;
	int ke3;
} a[10];
int main(){
	int i,j1,j2,j3,av1=0,av2=0,av3=0,max;
	for(i=0;i<10;i++){
		scanf("%d%s%d%d%d",&a[i].num,&a[i].name,&a[i].ke1,&a[i].ke2,&a[i].ke3);
	}
	for(i=0;i<=10;i++){
		av1=av1+a[i].ke1;
	}
	av1/=10;
		for(i=0;i<=10;i++){
		av2=av2+a[i].ke2;
	}
	av2/=10;
		for(i=0;i<=10;i++){
		av3=av3+a[i].ke3;
	}
	av3/=10;
	max=a[0].ke1;
	for(i=0;i<10;i++){
		if(a[i].ke1>max){
			j1=i;
			max=a[i].ke1;
		}
	}
		max=a[0].ke2;
	for(i=0;i<10;i++){
		if(a[i].ke2>max){
			j2=i;
			max=a[i].ke2;
		}
	}
		max=a[0].ke3;
	for(i=0;i<10;i++){
		if(a[i].ke3>max){
			j3=i;
			max=a[i].ke3;
		}
	}
	printf("科目1的平均分为%d，科目1的平均分为%d，科目1的平均分为%d。\n",av1,av2,av3);
	printf("科目1成绩最高的是%s同学，他的学号是%d，科目一分数%d，科目二分数%d，科目三分数%d",a[j1].name,a[j1].num,a[j1].ke1,a[j1].ke2,a[j1].ke3);
    printf("科目2成绩最高的是%s同学，他的学号是%d，科目一分数%d，科目二分数%d，科目三分数%d",a[j2].name,a[j2].num,a[j2].ke1,a[j2].ke2,a[j2].ke3);
    printf("科目3成绩最高的是%s同学，他的学号是%d，科目一分数%d，科目二分数%d，科目三分数%d",a[j3].name,a[j3].num,a[j3].ke1,a[j3].ke2,a[j3].ke3);
	return 0;
}
