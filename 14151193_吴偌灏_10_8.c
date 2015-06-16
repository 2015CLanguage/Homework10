#include <stdio.h>
#include <stdlib.h> 
struct student
{
	int Id;
	double grade[3];
	double aver;
	char Name[10];
}s[10],temp;
void sort()
{
	int i,j;
	FILE *fp;
	for (i=0; i<5; i++)
	{for (j=i+1; j<5; j++)
	  if (s[i].aver>s[j].aver)
	  {
	  	temp=s[i];s[i]=s[j];s[j]=temp;
	  }
	}
	  for (j=i+1; j<5; j++)
	  if (s[i].aver>s[j].aver)
	  {
	  	temp=s[i];s[i]=s[j];s[j]=temp;
	  }
	if (( fp=fopen("stu_sort.dat","w") )== NULL)
	   {
		printf("打不开文件\n");
		exit(1);
	  }  
	for (i=0; i<5; i++)
	{
		fprintf(fp,"%d %s ",s[i].Id,s[i].Name);
		for (j=0; j<3; j++)  fprintf(fp,"%.2lf ",s[i].grade[j]);
		fprintf(fp,"%.2lf\n",s[i].aver);
	}
	fclose(fp);
}
void insert()
{
	FILE *fp;
	int i,j;
	scanf("%d%s",&s[5].Id,s[5].Name);
	for (j=0; j<3; j++)
	scanf("%lf",&s[5].grade[j]);
	s[5].aver=(s[5].grade[0] + s[5].grade[1] + s[5].grade[2])/3;
	
	for (i=0; i<6; i++)
	  for (j=i+1; j<6; j++)
	  if (s[i].aver>s[j].aver)
	  {
	  	temp=s[i];s[i]=s[j];s[j]=temp;
	  }
	  
	if (( fp=fopen("stu_sort.dat","w") )== NULL)
	   {
		printf("打不开文件\n");
		exit(1);
	  }  
	for (i=0; i<5; i++)
	{
		fprintf(fp,"%d %s ",s[i].Id,s[i].Name);
		for (j=0; j<3; j++)  fprintf(fp,"%.2lf ",s[i].grade[j]);
		fprintf(fp,"%.2lf\n",s[i].aver);
	}
	fclose(fp);
}
void main()
{

	int i,j;
	for (i=0; i<5; i++)
	{
		scanf("%d%s",&s[i].Id,s[i].Name);
		for (j=0; j<3; j++)
		scanf("%lf",&s[i].grade[j]);
		s[i].aver=(s[i].grade[0] + s[i].grade[1] + s[i].grade[2])/3;
	}
	sort();
	insert();
}
