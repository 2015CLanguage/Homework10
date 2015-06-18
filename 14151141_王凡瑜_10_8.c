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
	struct Student stu[6],*p,*max,*q,temp;
	FILE *fp;
	fp=fopen("stu_sort","r");
	int *s;
	for(p=stu;p<stu+5;p++)
	{
		s=p->score;
		fscanf(fp,"%ld %s ",&(p->id),&(p->name));
		fscanf(fp,"%d %d %d %lf \n",s,s+1,s+2,&(p->aver));
	}
	fclose(fp);
	fp=fopen("stu_sort","w");
	s=p->score;
	p->aver=0;
	printf("Please input the new student's ID and name.\n");
	scanf("%ld %s",&(p->id),&(p->name));
	printf("Please input the new student's scores.\n");
	scanf("%d %d %d",s,s+1,s+2);
	for(;s<(p->score)+3;s++)
	{
		p->aver+=(*s)/3.0;
	}
	for(p=stu;p<stu+6;p++)
	{
		max=p;
		for(q=p;q<stu+6;q++)
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
	for(p=stu;p<stu+6;p++)
	{
		//Scaffolding
		//printf("%ld %s got score",p->id,p->name);
		//printf("%4d %4d %4d.\n",*(p->score),*((p->score)+1),*((p->score)+2));
		//printf("AVER:%.2lf\n",p->aver);
		fprintf(fp,"%ld %s %d %d %d %.2lf\n",p->id,p->name,*(p->score),*((p->score)+1),*((p->score)+2),p->aver);
	}
	fclose(fp);
}
