#include "stdio.h"
#include "stdlib.h"
struct Student                                          //定义结构体
{
	int num;
	char name[8];
	int score[3];
	float ave;
}stu[5],a;
void main()
{
	FILE *fp,*fp1;
	int i, j,n,b;
	printf("\n学号:");                                        //输入待插入的数据
	scanf("%d", a.num);
	printf("姓名:");
	scanf("%s", a.name);
	printf("学科1,学科2,学科3:");
	scanf("%d,%d,&d", &a.score[0], &a.score[1], &a.score[2]);
	a.ave = (a.score[0]+ a.score[1]+ a.score[2]) / 3.0;
	if ((fp = fopen("stu_sort", "r")) == NULL)                   //读取文件
	{
		printf("can not open.\n");
		exit(0);
	}
	for (i = 0; fread(&stu[i], sizeof(struct Student), 1, fp) != 0; i++)
	printf("\n");
	n = i;                                       
	for (b = 0; stu[b].ave>a.ave&&b < n; b++)
	fp1 = fopen("sort1.dat", "w");                             //输出排序结果
	for (i = 0;i<b; i++)
	{
		fwrite(&stu[i], sizeof(struct Student), 1, fp1);
	}
	fwrite(&a, sizeof(struct Student), 1, fp1);              //实现插入
	for (i = b; i<n; i++)
	{
		fwrite(&stu[i], sizeof(struct Student), 1, fp1);
	}
	printf("\n");
	fclose(fp);
	fclose(fp1);
}
