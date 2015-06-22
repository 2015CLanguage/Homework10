#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define N 10
struct employee
{
	char num[6];
	char name[10];
	char sex[2];
	int age;
	char add[20];
	int sal;
	char health[8];
	char degree[10];
} em[N];
struct salary
{
	char name[10];
	int sal;
}em_s[N];
int main()
{
	FILE *fp1, *fp2;
	int i, j;
	if ((fp1 = fopen("employee", "w")) == NULL)
	{
		printf("不能打开该文件\n");
		exit(0);
	}
	printf("\n编号\t姓名\t性别\t年龄\t地址\t工资\t健康\t文化\n");
	for (i = 0; fread(&em[i], sizeof(struct employee), 1, fp1) != 0; i++)
	{
		printf("\n%4s\t%8s\t%4s\t%6d\t%10s\t%6d\t%10s\t%8s", em[i].num, em[i].name, em[i].sex, em[i].age, em[i].add, em[i].sal, em[i].health, em[i].degree);
		strcpy(em_s[i].name, em[i].name);
		em_s[i].sal = em[i].sal;
	}
	printf("\n");
	printf("工资单");
	if ((fp2 = fopen("em_s", "wb")) == NULL)
	{
		printf("不能打开该文件\n");
		exit(0);
	}
	for (j = 0; j < i; j++)
	{
		if (fwrite(&em_s[j], sizeof(struct salary), 1, fp2) != 1)
			printf("输出错误");
		printf("\n %12s %10d", em_s[j].name, em_s[j].sal);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
