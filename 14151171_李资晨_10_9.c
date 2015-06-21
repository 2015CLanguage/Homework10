<stdio.h>
#include <stdlib.h>
#define N 10
struct employee{
	char name[10];
	int num;
	char sex[5];
	int age;
	char adress[30];
	char health[20];
	char edu[10];
	int salary;
}emp[N]; 

int main()
{
	int i;
	FILE *fp;
	if ((fp=fopen("employee.dat","r"))==NULL)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
    	for(i=0;i<N;i++)
    	{
    		fread(&emp[i],sizeof(struct employee),1,fp);
	    } 
	    fclose(fp);
	}
	
	if ((fp=fopen("salary.txt","w"))==NULL)
    {
        printf("error\n");
        exit(0);
    }
    else
    {
    	for (i=0;i<N;i++)
    	{
    		fprintf(fp,"%-10s%d\n",emp[i].name,emp[i].salary);
		}
		fclose(fp);
	}
	return 0;
}
