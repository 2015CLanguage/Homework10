#include"stdio.h"
#include"stdlib.h"
#define N 1
struct student
{
	char num[10];
	char name[10];
	float score[3];
	float aver;
};
int main()
{
	struct student b[N];
	int i,j;
	FILE *fp,*fp2;
	if((fp=fopen("stdu.txt","r"))==NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		fscanf(fp,"%s%s",b[i].num,b[i].name);
		for(j=0;j<3;j++)
		{
			fscanf(fp,"%3.2f",b[i].score[j]);
		}
		fscanf(fp,"%3.2f",b[i].aver);
	}
	fclose(fp);
	float temp;
	for(i=0;i<N;i++)
	{
		for(j=i+1;i<N;j++)
		{
			if(b[i].aver<b[j].aver)
			{
				temp=b[i].aver;
				b[i].aver=b[j].aver;
				b[j].aver=temp;
			}
		}
	}
	if((fp2=fopen("stdu_sort.txt","w"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	//fprintf(fp,"学号\t姓名\t科目1\t科目2\t科目3\t平均分\t\n");
	for(i=0;i<N;i++)
	{
		fprintf(fp2,"%s%s",b[i].num,b[i].name);
		for(j=0;j<3;j++)
		{
			fprintf(fp2,"%3.2f",b[i].score[j]);
		}
		fprintf(fp2,"%3.2f\n",b[i].aver);
	}
	fclose(fp2);
}
