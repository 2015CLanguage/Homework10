#include<stdio.h>
int insert();
void save(int x);
#define N 6
struct Student
{
	int index;
	char name[20];
	float score[3];
	float average;
};
struct Student stu[6];
void save(int x);
int insert();
int insert()
{
	printf("请输入要插入的学生信息：\n");
	scanf("%d%s%f%f%f",&stu[N-1].index,&stu[N-1].name,&stu[N-1].score[0],&stu[N-1].score[1],&stu[N-1].score[2]);
	stu[N-1].average=(stu[N-1].score[0]+stu[N-1].score[1]+stu[N-1].score[2])/3.0; 
	int i,j,t;
	FILE *fp1;
	fp1=fopen("stu_sort.dat","rb");
	for(i=0;i<N-1;i++)
	{
	    fread(&stu[i],sizeof(struct Student),1,fp1);
    }
    fclose(fp1);
    for (i=0; i<N-1; i++)
    {
    	if (stu[i].average>stu[N-1].average&&stu[i+1].average<stu[N-1].average)
	    {
	    	t=i+1;
		}
    }
    return t;
}
void save(int x)
{
	FILE *fp;
	int i;
	if((fp=fopen("stu_sort.dat","wb"))==NULL)
	{
		printf("文件无法打开.\n");
	}
	fseek(fp,x*sizeof(struct Student),0);
	if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
	{
		printf("数据写入错误."); 
	}
	fclose(fp);
}
int main()
{
	int a;
    a=insert();
	save(a); 
	return 0;
}
