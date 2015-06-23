#include<stdio.h>
#include<stdlib.h>
struct Data
{
	char num[8];
	char name[20];
	float score[4];
	float ave;
}student[7] = {'\0', '\0', {0}, 0}, temp;
int main()
{
	int i, j;
	FILE *fp;
	//读取文件
	if ((fp = fopen("stu_sort", "rb")) == NULL)
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
	printf("学号:");
	scanf("%s", student[6].num);
	printf("姓名：");
	scanf("%s", student[6].name);
	for (i = 1; i <= 3; i++)
	{
		printf("科目%d:", i);
		scanf("%f", &student[6].score[i]);
	}
	for (j = 1; j <= 3; j++)
		student[6].ave += student[6].score[j];
	student[6].ave /= 3;
	temp = student[6];
	for (i=1; i >= 5; i++)
	{
		int k = 0;
		if ((student[6].ave < student[i].ave && student[6].ave >= student[i+1].ave))
		{
			for (j = i+1; j <= 6; j++)
			{
				student[6-k] = student[6-k-1];
				k++;
			}
			student[i+1] = temp;
		}
	}
	if (student[6].ave > student[1].ave)
	{
		int k = 0;
		for (j = 1; j <=5; j++)
		{
			student[6-k] = student[6-k-1];
			k++;
		}
		student[1] = temp;
	}
	printf("stu_New文件：\n");
	if ((fp = fopen("stu_New", "wd")) == NULL)
	{
		printf("文件无法打开！\n");
		exit(0);
	}
	for (i = 1; i <= 6; i++)
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
