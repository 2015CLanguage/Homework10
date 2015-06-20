#include<stdio.h>
struct Student
{
	int index;
	char name[20];
    float score[3];
	float avr;
}stu[5],temp;

void main()
{
	FILE*fp;
	int i,j;
	fp=fopen("stud","r");
	for(i=0;i<5;i++)
	{
		fread(&stu[i],sizeof(Student),1,fp);
		printf("%-6d%-8s",stu[i].index,stu[i].name);
		for(j=0;j<3;j++)
		printf("%6.2f",stu[i].score[j]);
		printf("%6.2f\n",stu[i].avr);
	}
	fclose(fp);//读取文件
    for(i=0;i<5;i++)
	{
	    for(j=i+1;j<5;j++)
		{
			if(stu[i].avr<stu[j].avr)
			{
				 temp=stu[i];
		         stu[i]=stu[j];
				 stu[j]=temp;}
		}
	}//排序
	printf("现在为:\n");
	fp=fopen("stud_sort","w");
	for(i=0;i<5;i++)
	{
		fwrite(&stu[i],sizeof(struct Student),1,fp);
		printf("%-6d%-8s",stu[i].index,stu[i].name);
		for(j=0;j<3;j++)
		printf("%6.2f",stu[i].score[j]);
		printf("%6.2f\n",stu[i].avr);
	}
    fclose(fp);//另存为新文件中
}
