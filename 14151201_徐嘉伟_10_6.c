#include <stdio.h>
#include <stdlib.h> 
struct student
{
	int Id;
	double grade[3];
	double aver;
	char Name[20];
}s[5],temp;
void main()
{
	FILE *fp;
	int i,j;
	for (i=0; i<5; i++)
	{
		scanf("%d%s",&s[i].Id,s[i].Name);
		for (j=0; j<3; j++)
		scanf("%lf",&s[i].grade[j]);
		s[i].aver=(s[i].grade[0] + s[i].grade[1] + s[i].grade[2])/3;
	}
	for (i=0; i<5; i++)
	{ 
	   for (j=i+1; j<5; j++)
	   { 
	   if (s[i].aver>s[j].aver){temp=s[i];s[i]=s[j];s[j]=temp;}	  
	   } 
	} 
	if (( fp=fopen("stu_sort.txt","w"))== NULL)
	{
		printf("文件无法被打开\n");
		exit(1);
	}
	for (i=0; i<5; i++)
	{
		fprintf(fp,"%d %s %.2lf\n",s[i].Id,s[i].Name,s[i].aver);
		for (j=0; j<3; j++) {printf("%.2lf ",s[i].grade[j]);} 
		printf("%.2lf\n",s[i].aver);
	}
	fclose(fp);
}
