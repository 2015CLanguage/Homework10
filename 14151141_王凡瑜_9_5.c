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
/******************调试用******************
	struct Student stu[10]=
	{
		{101,"Wang",{93,89,87}},
		{102,"Li",{85,80,78}},
		{103,"Zhao",{65,70,59}},
		{104,"Ma",{77,70,83}},
		{105,"Han",{70,67,60}},
		{106,"Zhang",{99,97,95}},
		{107,"Zhou",{88,89,88}},
		{108,"Chen",{87,88,85}},
		{109,"Yang",{72,70,69}},
		{110,"Liu",{78,80,83}}
	};
	struct Student *p,*hstu=stu;
******************************************/

	struct Student stu[10],*p,*hstu=stu;
	double aver=0,h=0;
	int *s;
	for(p=stu;p<stu+10;p++)
	{
		s=p->score;
		printf("Please input Student %d's ID and name.\n",p-stu+1);
		scanf("%ld %s",&(p->id),&(p->name));
		printf("Please input Student %d's scores.\n",p-stu+1);
		scanf("%d %d %d",s,s+1,s+2);
		for(s=p->score;s<(p->score)+3;s++)
		{
			p->aver+=(*s)/3.0;
		}
		aver+=(p->aver)/10.0;
		if((p->aver)>h)
		{
			h=p->aver;
			hstu=p;
		}
		//Scaffolding
		//printf("%ld %s got score",p->id,p->name);
		//printf("%4d %4d %4d.\n",*(p->score),*((p->score)+1),*((p->score)+2));
		//printf("AVER:%.2lf\n",p->aver);
	}
	printf("The average score of 3 courses is %.2lf.\n\n",aver);
	printf("%ld %s got the highest score ",hstu->id,hstu->name);
	printf("%d %d %d,\n",*(hstu->score),*((hstu->score)+1),*((hstu->score)+2));
	printf(" the average of which are %.2lf .\n\n",hstu->aver);
}
