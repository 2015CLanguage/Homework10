#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee
{
	char name[10];
	int number;
	char sex[5];
	int age;
	char addr[20];
	int salary;
	char health[10];
	char study[10];
}em[20];
struct Short_Employee
{
	char name[10];
	int salary;
}sem[20];
int main()
{
	FILE *fp1, *fp2;
	int i,j;
	if((fp1=fopen("employee","r"))==NULL)
	{
		printf("Error!");
		exit(0);
	}
	for(i=0;fread(&em[i],sizeof(struct Employee),1,fp1);i++)
	{
		strcpy(em[i].name,sem[i].name);
		sem[i].salary=em[i].salary;
	}
	printf("新数据为\n");
	if((fp2=fopen("employee_salary","wb"))==NULL)
	{
		printf("Error!");
		exit(0);
	}
	for(j=0;j<i;j++)
	{
		if(fwrite(&sem[j],sizeof(struct Short_Employee),1,fp2)!=1)
			printf("Error!\n");
		printf("%5s%5d",sem[j].name,sem[j].salary);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
