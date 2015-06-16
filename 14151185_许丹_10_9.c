#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define N 10
struct employee
{
	char name[10];
	int num;
	char sex[5];
	int age;
	char adress[30];
	char health[20];
	char edu[10];
	int salary;
}Emp[N],tmp;


int main()
{
	int i;
	FILE *fp;
	if  ((fp=fopen("employee.dat","r"))==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		for (i=0; i<N; i++)
		fread(&Emp[i],sizeof(struct employee),1,fp);
		fclose(fp);
	}
	if ((fp=fopen("salary.dat","w"))==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		for (i=0; i<N; i++)
		fprintf(fp,"%s %s",Emp[i].name,Emp[i].salary);
		fclose(fp);
	}
	return 0;
}
