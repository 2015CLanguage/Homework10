#include<stdio.h>
#include<string.h>
struct employee1
{
	char name[20];
	int index;
    char sex[2];
	int age;
	char addr[20];
	int salary;
	char health[10];
	char education[20];
}emp1[10];

struct employee2
{
	char name[20];
	int salary;
}emp2[10];

void main()
{
	FILE*fp;
	int i,j;
	fp=fopen("employee","r");
	for(i=0;i<10;i++)
	{
		fread(&emp1[i],sizeof(employee1),1,fp1);
		printf("%10s%5d%5s%5d%10s%8d%8s%10s",emp1[i].name,emp1[i].index,emp1[i].sex,
			emp1[i].age,emp1[i].addr,emp1.salaly,emp1.health,emp1.education);
		strcpy(emp2[i].name=emp1[i].name);
		emp2[i].salary=emp1[i].salary;
	}//将职工的工资信息提取
	fclose(fp);
    printf("现在为:\n");
	fp=fopen("employee_salary","w");
	for(i=0;i<10;i++)
	{
		fwrite(&stu[i],sizeof(struct Student),1,fp);
		printf("%8s%6d\n",emp2[i].name,emp2[i].salary);
	}
    fclose(fp);//另存为新文件中
}
