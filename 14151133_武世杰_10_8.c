#include<stdio.h>
#include<stdlib.h>
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
	struct student c[N+1];
	int i,j;
	float sum;
	FILE *fp,*fp2;

		printf("学号：");
		scanf("%s",c[N].num);
		printf("姓名:");
		scanf("%s",c[N].name);
		for(j=0;j<3;j++)
		{
			printf("科目%d成绩：",j+1);
			scanf("%f",&c[N].score[j]);			
		}

		sum=0;
		for(j=0;j<3;j++)
		{
			sum=sum+c[N].score[j];	
		}
		c[N].aver=sum/3;

	
	if((fp=fopen("stdu.txt","r"))==NULL)
	{
		printf("cannot open the file");
		exit(0);	
	}
	fclose(fp);
	float temp;
	for(i=0;i<N+1;i++)
	{
		for(j=i+1;i<N;j++)
		{
			if(c[i].aver<c[j].aver)
			{
				temp=c[i].aver;
			c[i].aver=c[j].aver;
		c[j].aver=temp;
			}
		}
	}
	if((fp2=fopen("stdu.txt","w+"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for(i=0;i<N+1;i++)
	{
		fprintf(fp2,"%s%s",c[i].num,c[i].name);
		for(j=0;j<3;j++)
		{
			fprintf(fp2,"%3.2f",c[i].score[j]);
		}
		fprintf(fp2,"%3.2f\n",c[i].aver);
	}
	fclose(fp2);
}
