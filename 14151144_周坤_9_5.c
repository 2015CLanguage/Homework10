# Homework10
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
struct Grades
{
	int Id;
	double grade[3];
	double aver;
	char Name[10];
}G[10];


int main()
{
	int i,j;
	for (i=0; i<10; i++)
	{
		scanf("%d%s",&G[i].Id,G[i].Name);
		for (j=0; j<3; j++)
		scanf("%lf",&G[i].grade[j]);
		G[i].aver=(G[i].grade[0] + G[i].grade[1] + G[i].grade[2])/3;
	}
	double MaxGrade=0;
	int Max_Grade_Id;
	for (i=0; i<10; i++)
	{
		if (G[i].aver>MaxGrade)
		{
			MaxGrade=G[i].aver;
			Max_Grade_Id=i;
		}
	}
	for (i=0; i<10; i++)	printf("%.1f",G[i].aver);

	printf("The Highest student:");
	printf("%d %s ",G[Max_Grade_Id].Id,G[Max_Grade_Id].Name);
	for (j=0; j<3; j++)  printf("%.0lf ",G[Max_Grade_Id].grade[j]);
	printf("%.1ld\n",G[Max_Grade_Id].aver);
	
	return 0;
}
