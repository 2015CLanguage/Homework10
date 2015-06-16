#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2
struct employee
{
	int num;
	char name[20];
	char sex[2];
	int age;
	char addr[20];
	float salary;
	char health[20];
	char degree[10];
}emp[N];
struct newem
{
	char name[20];
	float salary;
}empnew[N];
int main()
{
	FILE *fp,*fp1,*fp2;
	int i,j;
	/*for(i=0;i<N;i++)
	{
		scanf("%d%s%s%d%s%f%s%s",&emp[i].num,emp[i].name,emp[i].sex,&emp[i].age,emp[i].addr,&emp[i].salary,emp[i].health,emp[i].degree);
	}
	fp=fopen("employee.dat","w");
	for(i=0;i<N;i++)
	{
		fwrite(&emp[i],sizeof(struct employee),1,fp);
	}
	fclose(fp);                     */                    //employee建立部分
	fp1=fopen("employee.dat","r");
	printf("original dat\n");
	for(i=0;i<N;i++)
	{
		fread(&emp[i],sizeof(struct employee),1,fp1);
		printf("%3d %s %s %6d %s %6.2f %s %s\n",emp[i].num,emp[i].name,emp[i].sex,emp[i].age,emp[i].addr,emp[i].salary,emp[i].health,emp[i].degree);
		strcpy(empnew[i].name,emp[i].name);
		empnew[i].salary=emp[i].salary;
	}
	fclose(fp1);
	if((fp2=fopen("salary.dat","wb"))==NULL)
	{
		printf("error");
		exit(0);
	}
	for(j=0;j<N;j++)
	{
		fwrite(&empnew[i],sizeof(struct employee),1,fp2);
		printf("%-8s%6.2f\n",empnew[j].name,empnew[j].salary);
	}
	return 0;
}
