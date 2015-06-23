#include "stdio.h"
#include "stdlib.h"

//定义结构体
struct Student                                          
{
	int num;
	char name[8];
	int score[3];
	float ave;
}stu[5],a;

void main()
{
	FILE *fp;
	int i,j,n,t;

	
	//输入待插入的数据	
	printf("\n学号:");                                        
	scanf("%d", a.num);
	printf("姓名:");
	scanf("%s", a.name);
	printf("学科1,学科2,学科3:");
	scanf("%d,%d,&d", &a.score[0], &a.score[1], &a.score[2]);
	a.ave=(a.score[0]+ a.score[1]+ a.score[2])/3.0;
	
	
	if ((fp=fopen("stu_sort","r"))==NULL)                  
	{
		printf("不能打开\n");
		exit(0);
	}
	
	//读取文件
	for(i=0; fread(&stu[i], sizeof(struct Student),1,fp)!=0; i++)
	printf("\n");
	//找到插入位置
	n=i;                                       
	for(t=0; stu[t].ave>a.ave&&t<n; t++)
	//前段
	fp=fopen("stu_sort", "w");                             
	for (i=0;i<t; i++)
	{
		fwrite(&stu[i], sizeof(struct Student), 1, fp);
	}
	//实现插入
	fwrite(&a, sizeof(struct Student), 1, fp);              
	//后段
	for (i=t; i<n; i++)
	{
		fwrite(&stu[i], sizeof(struct Student), 1, fp);
	}
	printf("\n");
	fclose(fp);
}
