#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct employee                                        //定义结构体
{
	int num;
	char name[10];
	char sex[2];
	int age;
	char addr[20];
	int salary;
	char health[8];
	char classy[10];
}employee[10];

struct emp
{
	char name[10];
	int salary;
}em[10];

void main()
{
	FILE *fp1, *fp2;
	int i, j;
	if ((fp1 = fopen("employee", "r")) == NULL)                    //打开文件
	{
		printf("不能打开.\n");
		exit(0);
	}
	
	for (i=0; fread(&employee[i], sizeof(struct employee),1,fp1)!=0; i++)//读取数据
	{
		strcpy(em[i].name, employee[i].name);
		em[i].salary = employee[i].salary;
	}
	
	if ((fp2 =fopen("emp_salary", "wb")) == NULL)
	{
		printf("不能打开.\n");
		exit(0);
	}
	for (j=0; j<i; j++)                                  //写入到另一文件
	{
		if (fwrite(&em[j], sizeof(struct emp),1,fp2)!=1)
			printf("error!");
	}
	fclose(fp1);//关闭文件
	fclose(fp2);
}
