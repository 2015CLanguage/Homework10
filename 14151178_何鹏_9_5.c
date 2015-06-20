#include "stdio.h"
struct student
{
	int num;
	char name[10];
	float score[3];
	float ave; 
}stu[10];
void cau(struct student *p);
int main()
{
	int i;
	struct student *p=stu;
	for(i=0;i<10;i++)
	{
	    printf("请输入第%d个学生学号,姓名,及三门成绩：\n",i+1);
		scanf("%d%s%f%f%F",&(stu[i]).num,&(stu[i]).name,&(stu[i]).score[0],&(stu[i]).score[1],&(stu[i]).score[2]);
	}
	cau(p);
}
void cau(struct student *p)
{
	float a,b=0,allave;
	int i,j,k;
	for(i=0;i<10;i++)
	{
		a=0;
		for(j=0;j<3;j++)
		    a+=(p+i)->score[j];
		(p+i)->ave=a/3;
		b=b+a;
	}
	allave=b/30;
	for(i=0,k=0;i<10;i++)
		if(((p+k)->ave)<((p+i)->ave))
		    k=i;
	printf("总平均成绩为：%7.2f\n",allave);
	printf("最高分成绩学生学号姓名分别为:\n%d\n%s\n",(p+k)->num,(p+k)->name);
	printf("其三门课程成绩为：%7.2f%7.2f%7.2f\n平均分为：%5.2f\n",(p+k)->score[0],(p+k)->score[1],(p+k)->score[2],(p+k)->ave);
}
