#include <stdio.h>
struct grade
{
    float c1;
    float c2;
    float c3;
};
struct student
{
    int index;
    char name[20];
    struct grade score;
};
float M(float,float,float);

float M(float x,float y,float z)
{
    float m;
    m=x>y?x:y;
    m=m>z?m:z;
    return m;
}

int main()
{
    struct student a[10];
    int i,k=1;
    float average,all,max;
    printf("Please input the data of 10 students in the order:index,name,c1,c2,c3:\n");
    for(i=0;i<10;i++)
        scanf("%d%s%f%f%f",&a[i].index,a[i].name,&a[i].score.c1,&a[i].score.c2,&a[i].score.c3);
    for(all=0,i=0;i<10;i++)
        all=all+a[i].score.c1+a[i].score.c2+a[i].score.c3;
    average=all/30;
    max=M(a[0].score.c1,a[0].score.c2,a[0].score.c3);
    for(i=1;i<10;i++)
      {
          if(max<M(a[i].score.c1,a[i].score.c2,a[i].score.c3))
        {
            max=M(a[i].score.c1,a[i].score.c2,a[i].score.c3);
            k=i;
        }
      }
    printf("the average is %f\n",average);
    printf("the highest grade is %f\n the information:%d\t%s\t%f\t%f\t%f\t",max,a[k].index,a[k].name,a[k].score.c1,a[k].score.c2,a[k].score.c3);
    return 0;
}
