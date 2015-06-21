#include<stdio.h>
#include<stdlib.h>
#define N 3
struct Student
{
char num[10];
char name[10];
float score[3]={0};
float avep;
}stu[N],temp;

int main()
{
int i,j;
FILE*fp,*in;
if((fp=fopen("stu.dat","r"))==NULL)
	{
	printf("can not open the file!\n");
	exit(0);
	}//打开文件 
for(i=0;i<N;i++)
{
	fread(&stu[i],sizeof(struct Student),1,fp);
	printf("%s %s",stu[i].num,stu[i].name);
	for(j=0;j<3;j++)
		printf("%8.2f",stu[i].score[j]);
	printf("%8.2f\n",stu[i].avep);
}
fclose(fp);
for(i=0;i<N;i++)
	{
	if(stu[i].avep<stu[i+1].avep)
		{
		temp=stu[i+1];
		stu[i+1]=stu[i];
		stu[i]=temp;
		}
	}
in=fopen("stu_sort.dat","w");
for(i=0;i<N;i++)
	{
	if(fwrite(&stu[i],sizeof(struct Student),1,in)!=1)
		printf("file write error\n");
	}
for(i=0;i<N;i++)
	{
	printf("%s %s",stu[i].num,stu[i].name);
	for(j=0;j<3;j++)
		{printf("%8.2f",stu[i].score[j]);}
	printf("%8.2f\n",stu[i].avep);
	}
fclose(in);
return 0;
}
