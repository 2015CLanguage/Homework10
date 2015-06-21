#include<stdio.h>
#define N 6
struct Student
{
	int index;
	char name[20];
	float score[3];
	float aver;
};
struct Student stu[6];
void save(int x);
int insert();
int main()
{
	int a;
    a=insert();
	save(a); 
	return 0;
}
void save(int x)
{
	FILE *fp;
	int i;
	if((fp=fopen("stu_sort.dat","wb"))==NULL)
	{
		printf("文件无法打开！\n");
	}
	fseek(fp,x*sizeof(struct Student),0);
	if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
	{
		printf("数据写入错误！"); 
	}
	fclose(fp);
}
int insert()
{
	printf("请输入要插入的学生信息：\n");
	scanf("%d%s%f%f%f",&stu[N-1].index,&stu[N-1].name,&stu[N-1].score[0],&stu[N-1].score[1],&stu[N-1].score[2]);
	stu[N-1].aver=(stu[N-1].score[0]+stu[N-1].score[1]+stu[N-1].score[2])/3.0; 
	int i,j,temp;
	FILE *fp1;
	fp1=fopen("stu_sort.dat","rb");
	for(i=0;i<N-1;i++)
	{
	    fread(&stu[i],sizeof(struct Student),1,fp1);
    }
    fclose(fp1);
    for (i=0; i<N-1; i++)
    {
    	if (stu[i].aver>stu[N-1].aver&&stu[i+1].aver<stu[N-1].aver)
	    {
	    	temp=i+1;
		}
    }
    return temp;
}


