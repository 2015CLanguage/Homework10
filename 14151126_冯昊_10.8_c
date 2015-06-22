#include <stdio.h>
#include <stdlib.h>
#define N 3

struct student{
    int num;
    char name[10];
    int score1;
    int score2;
    int score3;
    float ave;
}stu[N+1];

int main()
{
	int i;
	FILE *fp;
	if ((fp=fopen("stud_sort.txt","r"))==NULL)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
        for (i=0; i<N; i++)
        {
            fscanf(fp, "%d",&stu[i].num);
            fgetc(fp);
            fgets(stu[i].name, 11, fp);
            fgetc(fp);
            fscanf(fp, "%d",&stu[i].score1);
            fgetc(fp);
            fscanf(fp, "%d",&stu[i].score2);
            fgetc(fp);
            fscanf(fp, "%d",&stu[i].score3);
            fgetc(fp);
            fscanf(fp,"%f",&stu[i].ave);
            fgetc(fp);
        }
        fclose(fp);
    }
    struct student temp;
	printf("输入插入信息：");
	printf("学号:");
    scanf("%d",&temp.num);
    printf("姓名:");
    scanf("%s",temp.name);
    printf("三门课的成绩:");
    scanf("%d,%d,%d",&temp.score1,&temp.score2,&temp.score3); 
    temp.ave=(temp.score1+temp.score2+temp.score3)/3;
    
    for(i=0;i<N;i++)
    {
    	if(temp.ave<=stu[i].ave) break;
	}
	
	int j;
	for(j=N;j>i;j--)
	{
		stu[j]=stu[j-1];
	}
	stu[i]=temp;
	
	if ((fp=fopen("stud_sort.txt","w+"))==NULL)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
        for (i=0; i<N+1; i++)
        {
            fprintf(fp, "%d %-11s %d %d %d %f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].ave);
        }
    }
    fclose(fp);
    return 0;
}
