#include<stdio.h>
struct grade
    {
        int num;
        char name[10];
        float score[3];
    };
void print(struct grade student[5]);
void print(struct grade student[5])
{
    int i,j;
    for(i=0;i<5;i++)
       {printf("%d %s ",student[i].num,student[i].name);
        for(j=0;j<3;j++)
            printf("%2f  ",student[i].score[j]);
        printf("\n");
        }
}
int main()
{

    struct grade student[5];
    int i,j;
    printf("input students' index ,name and three scores:");
    for(i=0;i<5;i++)
       {scanf("%d%s",&student[i].num,&student[i].name);
        for(j=0;j<3;j++)
            scanf("%f",&student[i].score[j]);
        printf("\n");
        }
    print(student);
    return 0;
}
