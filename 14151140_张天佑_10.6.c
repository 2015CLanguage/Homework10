#include "stdio.h"
#include "stdlib.h"
struct Student                                          //定义结构体
{
	int num;
	char name[8];
	int score[3];
	float ave;
}stu[5],t;
void main()
{
	FILE *fp;
	int i, j,n;
	if ((fp = fopen("stud", "r")) == NULL)                   //读取文件
	{
		printf("can not open.\n");
		exit(0);
	}
	printf("文件 stud:");
	for (i = 0; fread(&stu[i], sizeof(struct Student), 1, fp) != 0; i++)
	{
		printf("\n%8d%8s", stu[i].num, stu[i].name);
		for (j = 0; j < 3; j++)
		{
			printf("%8d", stu[i].score[j]);
		}
		printf("%10.2f", stu[i].ave);
	}
	printf("\n");
	fclose(fp);
	n = i;                                        //对数据进行排序
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (stu[j].ave < stu[j+1].ave)
			{
				t = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = t;
			}
		}
	}
	printf("排序后:\n");
	fp = fopen("stu_sort", "w");                             //输出排序结果
	for (i = 0;i<n; i++)
	{
		fwrite(&stu[i], sizeof(struct Student), 1, fp);
		printf("\n%8d%8s", stu[i].num, stu[i].name);
		for (j = 0; j < 3; j++)
		{
			printf("%8d", stu[i].score[j]);
		}
		printf("%10.2f", stu[i].ave);
	}
	printf("\n");
	fclose(fp);
}
