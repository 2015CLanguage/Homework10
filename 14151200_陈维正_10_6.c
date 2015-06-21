#include<stdio.h>
#include<stdlib.h>
#define N 3
struct Student
{
char num[10];
char name[10];
float score[3];
float avep;
}stu[N];

int main()
{
int i;
float temp;
FILE*fp,*in;
if((fp=fopen("stu.dat","r"))==NULL)
	{
	printf("can not open the file!\n");
	exit(0);
	}//打开文件 
for(i=0;i<N;i++)
	{
	if(stu[i].avep<stu[i+1].avep)
		{
		temp=stu[i+1].avep;
		stu[i+1].avep=stu[i].avep;
		stu[i].avep=temp;
		}
	}
if((in=fopen("stu_sort","wb"))==NULL)
	{
	printf("can not open the file!\n");
	exit(0);
	}
for(i=0;i<N;i++)
	{
	if(fwrite(&stu[i],sizeof(struct Student),1,in)!=1)
		printf("file write error\n");
	fclose(in);
	}
return 0;
}
