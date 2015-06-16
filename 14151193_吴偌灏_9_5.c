#include <stdio.h>
struct student
{
	int Id;
	double grade[3];
	double aver;
	char Name[10];
}s[10];
void main()
{
	int i,j;
	for (i=0; i<10; i++)
	{
		scanf("%d%s",&s[i].Id,s[i].Name);
		for (j=0;j<3;j++)scanf("%lf",&s[i].grade[j]);	
		s[i].aver=(s[i].grade[0] + s[i].grade[1] + s[i].grade[2])/3;
	}
	double MaxGrade=0;
	int id;
	for (i=0; i<10; i++)
	{
		if (s[i].aver>MaxGrade)
		{
			MaxGrade=s[i].aver;
			id=i;
		}
	}
	for (i=0; i<10; i++)	printf("%.2f",s[i].aver);
	printf("The Highest student:");
	printf("%d %s ",s[id].Id,s[id].Name);
	for (j=0; j<3; j++)  printf("%.2lf ",s[id].grade[j]);
	printf("%.2lf\n",s[id].aver);
}
