#include<stdio.h>

struct Employee
{
	char id[5];
	char name[10];
	char sex;
	int age;
	char addr[10];
	int salary;
	char health[5];
	char edu[10];
};

void main()
{
	FILE *fp;
	struct Employee employee[4],*p;
	fp=fopen("employee.txt","r");
	for(p=employee;p<employee+4;p++)
	{
		fscanf(fp,"%d %s %c %d %s %d %s %s \n",&(p->id),
			&(p->name),&(p->sex),&(p->age),&(p->addr)
			,&(p->salary),&(p->health),&(p->edu));
	}
	fclose(fp);
	fp=fopen("brief_info","w");
	for(p=employee;p<employee+4;p++)
	{
		fprintf(fp,"%s %d\n",p->name,p->salary);
	}
	fclose(fp);
}

