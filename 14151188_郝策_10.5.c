#include"stdio.h"
#include"stdlib.h"
#define N 5
struct student
{
	char num[10];
	char name[10];
	float score[3];
	float aver;
};
int main()
{
	struct student a[N];
	int i,j;
	float sum;
	FILE *fp;
	for(i=0;i<N;i++)
	{
		printf("学号:");
		scanf("%s",a[i].num);
		printf("姓名:");
		scanf("%s",a[i].name);
		for(j=0;j<3;j++)
		{
			printf("科目%d成绩:",j+1);
			scanf("%f",&a[i].score[j]);
			
		}
	}
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
		{
			sum=sum+a[i].score[j];	
		}
		a[i].aver=sum/3;
	}
	
	if((fp=fopen("stdu.txt","w"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	//fprintf(fp,"学号\t姓名\t科目1\t科目2\t科目3\t平均分\t\n");
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%s%s",a[i].num,a[i].name);
		for(j=0;j<3;j++)
		{
			fprintf(fp,"%3.2f",a[i].score[j]);
		}
		fprintf(fp,"%3.2f\n",a[i].aver);
	}
	fclose(fp);
}
