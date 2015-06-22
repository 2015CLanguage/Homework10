#include<stdio.h>
struct student
{
	char num[10];
	char name[8];
	int score[3];
	float ave;
}s[5];
int main()
{
	int i,j,sum;
	FILE *fp;
	for(i=0;i<5;i++)
	{
		printf("请输入第%d个学生的成绩\n",i+1);
		printf("学号:");
		scanf("%s",s[i].num);
		printf("姓名:");
		scanf("%s",s[i].name);
		sum=0;
		for(j=0;j<3;j++)
		{
			printf("科目%d分数:",j+1);
			scanf("%d",&s[i].score[j]);
			sum+=s[i].score[j];
		}
		s[i].ave=sum/3;
	}
	fp=fopen("stud.zyz","w");
	for(i=0;i<5;i++)
	{
		if(fwrite(&s[i],sizeof(struct student),1,fp)!=1)
		{
			printf("file write error\n");
		}
	}
	fclose(fp);
	fp=fopen("stud.zyz","r");
	for(i=0;i<5;i++)
	{
		fread(&s[i],sizeof(struct student),1,fp);
		printf("\n%s,%s,%d,%d,%d,%6.2f\n",s[i].num,s[i].name,s[i].score[0],s[i].score[1],s[i].score[2],s[i].ave);
	}
	return 0;
}
