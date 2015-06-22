#include<stdio.h>
struct Student
{
	int number;
	char name[20];
	int score[3];
	float average;
};
struct Student stu[6];
void save(int x);
int insert();
int main()
{
	int m;
    m=insert();
	save(m); 
	return 0;
}
void save(int x)
{
	FILE *fp;
	int i;
	if((fp=fopen("stu_sort.dat","wb"))==NULL)
	{
		printf("Error！\n");
	}
	fseek(fp,x*sizeof(struct Student),0);
	if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
	{
		printf("Error！"); 
	}
	fclose(fp);
}
int insert()
{
	printf("请输入要插入的学生信息：\n");
	scanf("%d%s%d%d%d",&stu[5].number,&stu[5].name,&stu[5].score[0],&stu[5].score[1],&stu[5].score[2]);
	stu[5].average=(stu[5].score[0]+stu[5].score[1]+stu[5].score[2])/3.0; 
	int i,j,temp;
	FILE *fp1;
	fp1=fopen("stu_sort.dat","rb");
	for(i=0;i<5;i++)
	{
	    fread(&stu[i],sizeof(struct Student),1,fp1);
    }
    fclose(fp1);
    for (i=0; i<5; i++)
    {
    	if (stu[i].average>stu[5].average&&stu[i+1].average<stu[5].average)
	    {
	    	temp=i+1;
		}
    }
    return temp;
}
