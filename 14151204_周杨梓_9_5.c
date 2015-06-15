#include<stdio.h>
#define N 10
struct Stud
{
	int num;
	char name[20];
	float score[3];
};
void input(struct Stud st[]);
void couraver(struct Stud st[],float aver[3]);
struct Stud max(struct Stud st[]);
int main()
{
	struct Stud std[N],maxstu;
	struct Stud *p=std;
	float courseaver[3]={0};
	input(p);
	couraver(p,courseaver);
	maxstu=max(p);
	printf("the courses's average scores are %5.2f, %5.2f, %5.2f\n",courseaver[0],courseaver[1],courseaver[2]);
	printf("the student who got the highest score is Nom%d %s\nhis scores are %5.2f,%5.2f,%5.2f\nthe average score is %5.2f\n",maxstu.num,maxstu.name,maxstu.score[0],
		maxstu.score[1],maxstu.score[2],(maxstu.score[0]+maxstu.score[1]+maxstu.score[2])/3);
}
void input(struct Stud st[])
{
	int i;
	printf("please input data:\n");
	for(i=0;i<N;i++)
	{
		printf("please input number.%d student:\n",i+1);
		scanf("%d %s %f %f %f",&st[i].num,st[i].name,&st[i].score[0],&st[i].score[1],&st[i].score[2]);
	}
}
void couraver(struct Stud st[],float aver[3])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<3;j++)
		{
			aver[j]+=st[i].score[j];
		}
	}
	for(j=0;j<3;j++)
		{
			aver[j]=aver[j]/N;
		}
}
struct Stud max(struct Stud st[])
{
	int i,j,max=0;
	float sum[N]={0};
	struct Stud maxs;
	for(i=0;i<N;i++)
	{
		for(j=0;j<3;j++)
		{
			sum[i]+=st[i].score[j];
		}
		if(sum[i]>sum[max])
			max=i;
	}
	maxs=st[max];
	return maxs;
}
