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
}stu[N];

int main()
{
    int i;
    printf("录入学生信息:\n");
    for (i=0; i<N; i++)
    {
        printf("学号:");
        scanf("%d",&stu[i].num);
        printf("姓名:");
        scanf("%s",stu[i].name);
        printf("三门课的成绩:");
        scanf("%d,%d,%d",&stu[i].score1,&stu[i].score2,&stu[i].score3);
    }
   
    FILE *fp;
    if ((fp=fopen("stud.txt","w+"))==NULL)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
        for (i=0; i<N; i++)
        {
            fprintf(fp, "%d %-11s %d %d %d\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3);
        }
    }
    fclose(fp);
   
    if ((fp=fopen("stud.txt","r"))==NULL)
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
        }
        fclose(fp);
    }
    if ((fp=fopen("stud_sort.txt","w+"))==NULL)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
        int j;
        for (i=0; i<N; i++)
        {
            stu[i].ave=(stu[i].score1+stu[i].score2+stu[i].score3)/3;
        }
        struct student temp;
        for (i=0; i<N-1; i++)
        {
            for (j=0; j<N-i-1; j++)
            {
                if (stu[j].ave>stu[j+1].ave)
                {
                    temp=stu[j];
                    stu[j]=stu[j+1];
                    stu[j+1]=temp;
                }
            }
        }
       
        for (i=0; i<N; i++)
        {
                fprintf(fp, "%d %-11s %d %d %d %f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].ave);
        }
    }
    return 0;
}
