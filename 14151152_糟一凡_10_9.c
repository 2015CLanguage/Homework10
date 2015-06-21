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
};
struct employee em[N];
int main()
{
	int i;
	FILE *fp1, *fp2;
	if  ((fp1=fopen("employee.dat","r"))==NULL)
	{
		printf("错误\n");
		exit(0);
	}
	else
	{
		for (i=0; i<N; i++)
		fread(&em[i],sizeof(struct employee),1,fp1);
	}
	fclose(fp1);
	if ((fp2=fopen("simplication.dat","w"))==NULL)
	{
		printf("错误\n");
		exit(0);
	}
	else
	{
		for (i=0; i<N; i++)
		{
		fprintf(fp2,"%s %s",em[i].name,em[i].salary);
	    }
	}
	fclose(fp2);
	return 0;
}
