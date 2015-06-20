#include<stdio.h>
struct Student
{
	int index;
	char name[20];
    float score[3];
	float avr;
}stu[6],temp;

void main()
{
	FILE*fp;
	int i,j;
	float sum=0;
	printf("原数据为:\n");
	fp=fopen("stud_sort","r");
	for(i=0;i<5;i++)
	{
		fread(&stu[i],sizeof(Student),1,fp);
		printf("%-6d%-8s",stu[i].index,stu[i].name);
		for(j=0;j<3;j++)
		printf("%6.2f",stu[i].score[j]);
		printf("%6.2f\n",stu[i].avr);
	}
	fclose(fp);//读取文件
	printf("请输入第六个学生数据\n");
	printf("学号:\n");
	scanf("%d",&stu[5].index);
	printf("姓名:\n");
	scanf("%s",stu[5].name);
	for(j=0;j<3;j++)
	{
		printf("score %d:\n",j+1);
		scanf("%f",&stu[5].score[j]);
	}//插入的学生数据
	for(j=0;j<3;j++)
		{sum=sum+stu[5].score[j];}
	stu[5].avr=sum/3.0;//计算平均分
	printf("现在结果为:\n");
    for(i=0;i<6;i++)
	{
	    for(j=i+1;j<6;j++)
		{
			if(stu[i].avr<stu[j].avr)
			{
				 temp=stu[i];
		         stu[i]=stu[j];
				 stu[j]=temp;}
		}
	}//排序
	

	printf("现在为:\n");
	fp=fopen("stud_sort1","w");
	for(i=0;i<6;i++)
	{
		fwrite(&stu[i],sizeof(struct Student),1,fp);
		printf("%-6d%-8s",stu[i].index,stu[i].name);
		for(j=0;j<3;j++)
		printf("%6.2f",stu[i].score[j]);
		printf("%6.2f\n",stu[i].avr);
	}
    fclose(fp);//另存为新文件中
}
