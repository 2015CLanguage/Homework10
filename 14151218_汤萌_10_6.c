#include<stdio.h>
#include<stdlib.h>
struct Data
{
	char num[8];
	char name[20];
	float score[4];
	float ave;
}student[6] = {'\0', '\0', {0}, 0}, temp;
int main()
{
	int i, j;
	for (i = 1; i <=5; i++)
	{
		printf("学号: ");
		scanf("%s", (student+i) -> num);
		printf("姓名: ");
		scanf("%s", (student+i) -> name);
		printf("分数: \n");
		for (j = 1; j <=3; j++)
		{
			printf("科目%d: ", j);
			scanf("%f", &student[i].score[j]);
		}
	}
	for (i=1; i <= 5; i ++)
	{
		for (j = 1; j <= 3; j++)
			student[i].ave += student[i].score[j];
		student[i].ave /= 3;
	}
	//建立文件
	FILE*fp;
	if ((fp = fopen("stud", "wd")) == NULL)
	{
		printf("文件无法打开！\n");
		exit(0);
	}
	for (i = 1; i <= 5; i++)
	{
		if (fwrite(&student[i], sizeof(struct Data), 1, fp) != 1)
		{
			printf("文件写入时发生错误！\n");
		}
	}
	fclose(fp);
	//读取文件
	if ((fp = fopen("stud", "rb")) == NULL)
	{
		printf("文件打开错误！");
		exit(0);
	}
	printf("stud文件:\n");
	for (i = 1; fread(&student[i], sizeof(struct Data), 1, fp) != 0; i++)
	{
		printf("%s\t%s", student[i].num, student[i].name);
		for (j = 1; j <= 3; j++)
		{
			printf("\t%.2f", student[i].score[j]);
		}
		printf("\t%.2f\n", student[i].ave);
	}
	fclose(fp);
	//冒泡排序
	for (i=1; i <= 5; i++)
	{
		for (j = 1; j <= 5-i; j++)
		{
			if (student[j].ave < student[j+1].ave)
			{
				temp = student[j];
				student[j] = student[j+1];
				student[j+1] = temp;
			}
		}
	}
	printf("stu_sort文件：\n");
	if ((fp = fopen("stu_sort", "wd")) == NULL)
	{
		printf("文件无法打开！\n");
		exit(0);
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%s\t%s", student[i].num, student[i].name);
		for (j = 1; j <= 3; j++)
		{
			printf("\t%.2f", student[i].score[j]);
		}
		printf("\t%.2f\n", student[i].ave);
		if (fwrite(&student[i], sizeof(struct Data), 1, fp) != 1)
		{
			printf("文件写入时发生错误！\n");
		}
	}
	fclose(fp);
	return 0;
}
