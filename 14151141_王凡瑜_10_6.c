#include<stdio.h>

struct Student
{
	long int id;
	char name[20];
	int score[3];
	double aver;
};

void main()
{
/**************调试用**************
	struct Student stu[5]=
	{
		{110,"Li",{90,89,88}},
		{120,"Wang",{80,79,78}},
		{130,"Chen",{70,69,68}},
		{140,"Ma",{100,99,98}},
		{150,"Wei",{60,59,58}},
	};
	struct Student *p,*max,*q,temp;
***********************************/

	struct Student stu[5],*p,*max,*q,temp;
	FILE *fp;
	fp=fopen("stu_sort","w");
	int *s;
	for(p=stu;p<stu+5;p++)
	{
		s=p->score;
		printf("\nPlease input Student %d's ID and name.\n",p-stu+1);
		scanf("%ld %s",&(p->id),&(p->name));
		printf("Please input Student %d's scores.\n",p-stu+1);
		scanf("%d %d %d",s,s+1,s+2);
		p->aver=0;
		for(;s<(p->score)+3;s++)
		{
			p->aver+=(*s)/3.0;
		}
	}
	for(p=stu;p<stu+5;p++)
	{
		max=p;
		for(q=p;q<stu+5;q++)
		{
			if((q->aver)>(max->aver))
			{
				max=q;
			}
		}
		if(max!=p)
		{
			temp=*max;
			*max=*p;
			*p=temp;
		}
	}
	for(p=stu;p<stu+5;p++)
	{
		//Scaffolding
		//printf("%ld %s got score",p->id,p->name);
		//printf("%4d %4d %4d.\n",*(p->score),*((p->score)+1),*((p->score)+2));
		//printf("AVER:%.2lf\n",p->aver);
		fprintf(fp,"%ld %s %d %d %d %.2lf\n",p->id,p->name,*(p->score),*((p->score)+1),*((p->score)+2),p->aver);
	}
	fclose(fp);
}
