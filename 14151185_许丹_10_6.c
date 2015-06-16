#include <stdio.h>
#include <stdlib.h>
#define N 10

struct student
{
    char num[10];
    char name[8];
    int score[3];
    float ave;
}st[N],temp;



int main()
{

    int i,j,n;
    FILE *fp;
    if((fp=fopen("stud","r"))==NULL)
    {
        printf("error in opening file 'stud'\n");
        exit(0);
    }
    printf("FILE 'stud':");

    for(i=0;fread(&st[i],sizeof(struct student),1,fp)!=0;i++)
    {
        printf("\n%8s%8s",st[i].num,st[i].name);
        for(j=0;j<3;j++)
            printf("%8d",st[i].score[j]);
        printf("%10.2f",st[i].ave);
    }
    printf("\n");
    fclose(fp);
    n=i;
    for(i=0;i<n;i++)
       for(j=i+1;j<n;j++)
        if(st[i].ave<st[i].ave)
       {
           temp=st[i];st[i]=st[j];st[j]=temp;
       }
    printf("\nNow:");


    if((fp=fopen("stu-sort","w"))==NULL)
    {
        printf("error in opening file 'stu-sort'\n");
        exit(0);
    }
    for(i=0;i<n;i++)
       {

       fwrite(&st[i],sizeof(struct student),1,fp);
       printf("\n%8s%8s",st[i].num,st[i].name);
       for(j=0;j<3;j++)
        printf("%10.2f",st[i].ave);
       }
       printf("\n");
    fclose(fp);

    return 0;
}
