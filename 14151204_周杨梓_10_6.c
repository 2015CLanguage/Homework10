#include<stdio.h>
#include<stdlib.h>
struct student
{
	char num[10];
	char name[8];
	int score[3];
	float ave;
}st[10],temp;
int main()
{
	FILE *fp;
	int i,j,n;
	if((fp=fopen("stud","r"))==NULL)
	{
		printf("error!\n");
		exit(0);
	}
	printf("File stud:");
	for(i=0;fread(st+i,sizeof(struct student),1,fp)!=0;i++)
	{
		printf("\n%8s%8s",st[i].num,st[i].name);
		for(j=0;j<3;j++)
		{
			printf("%8d",st[i].score[j]);
		}
		printf("%10.2f",st[i].ave);
	}
	printf("\n");
	fclose(fp);
	n=i;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(st[j].ave>st[j+1].ave)
			{
				temp=st[j];
				st[j]=st[j+1];
				st[j+1]=temp;
			}
		}
	}
	printf("\n排序后的结果:");
	fp=fopen("stu_sort","w");
	for(i=0;i<n;i++)
	{
		fwrite(&st[i],sizeof(struct student),1,fp);
		printf("\n%8s%8s",st[i].num,st[i].name);
		for(j=0;j<3;j++)
		{
			printf("%8d",st[i].score[j]);
		}
		printf("%10.2f",st[i].ave);
	}
	printf("\n");
	fclose(fp);
	return 0;
}
