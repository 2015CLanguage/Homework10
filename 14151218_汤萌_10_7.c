#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee1
{
	char num[8];
	char name[10];
	char sex[2];
	int age;
	char addr[30];
	int salar;
	char health[20];
	char class[10];
}elp1[10];
struct Employee2
{
	char name[10];
	int salary;
}elp2[10]
int mian()
{
	FILE *fp1, *fp2;
	int i, j;
	if (fp1 = fopen("Employee1", "r") == NULL)
	{
		printf("文件打开错误!");
		exit(0);
	}
	for (i = 0; fread(&epl1[i], sizeof(struct Employee1), 1, fp1) !=0; i++)
	{
		printf("\n%s\t%s\t%s\t%d\t%s\t%d\t%s\t%s", epl1[i].num, epl1[i].name, epl1[i].sex, 
				epl1[i].age, epl1[i].addr, epl1[i].salar, epl1[i].health, epl1[i].class);
		strcpy(epl2[i].name, epl1[i].name);
		epl2[i].salar = epl1[i].salar;
	}
	if (fp1 = fopen("Employee2", "wb") == NULL)
	{
		printf("文件打开错误!");
		exit(0);
	}
	for (j = 0; j < i; j++)
	{
		if(fwrite(&epl2[j], sizeof(struct Employee2), 1, fp2) != 1)
		  printf("写入文件错误！");
		printf("\n%s\t%d", epl2[j].name, epl2[j].salar);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
