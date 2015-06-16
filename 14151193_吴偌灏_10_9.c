#include <stdio.h>
#include <stdlib.h> 
struct employee
{
	char name[10];
	int num;
	char sex[5];
	int age;
	char adress[30];
	int salary;
	char health[20];
	char edu[10];
}Emp[10];
void main()
{
	int i;
	FILE *fp;
	if  ((fp=fopen("employee.dat","r"))==NULL)
	{
		printf("无法打开文件\n");
		exit(1);
	}
	else
	{
		for (i=0; i<10; i++)
		fread(&Emp[i],sizeof(struct employee),1,fp);
		fclose(fp);
	}
	if ((fp=fopen("salary.dat","w"))==NULL)
	{
		printf("无法打开文件\n");
		exit(1);
	}
	else
	{
		for (i=0; i<10; i++)
		fprintf(fp,"%s %d",Emp[i].name,Emp[i].salary);
		fclose(fp);
	}
}
