#include<stdio.h>
#include<stdlib.h>
#define N 2
struct Stu
{
	int num;
	char name[20];
	float score[3];
	float aver;
}st[N],stu[N],temp;
void save();
void sort();
int main()
{
	int i;
	float sum[N];
	FILE *fp;
	for(i=0;i<N;i++)
	{
		printf("please input number.%d student\n",i+1);
		scanf("%d%s%f%f%f",&st[i].num,st[i].name,&st[i].score[0],&st[i].score[1],&st[i].score[2]);
		sum[i]=(st[i].score[0]+st[i].score[1]+st[i].score[2]);
		st[i].aver=sum[i]/3;
	}
	save();
	sort();
	fp=fopen("stud_sort.dat","rb");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct Stu),1,fp);
		printf("%d %s %3.1f %3.2f %3.1f %3.1f\n",st[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	return 0;
}
void save()
{
	FILE *fp;
	int i;
	if((fp=fopen("stud.dat","wb"))==NULL)
	{
		printf("can not open\n");
		return;
	}
	for(i=0;i<N;i++)
		if(fwrite(&st[i],sizeof(struct Stu),1,fp)!=1)
		{
			printf("can not open\n");
			return;
	    }
    fclose(fp);
}
void sort()
{
	FILE *fp1,*fp2;
	int i,j;
	if((fp1=fopen("stud.dat","rb"))==NULL)
	{
		printf("can not open\n");
		exit(0);
	}
	if((fp2=fopen("stud_sort.dat","wb"))==NULL)
	{
		printf("can not open\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		if(fread(&stu[i],sizeof(struct Stu),1,fp1)!=1)
		{
			printf("can not open\n");
			return;
	    }
	}
	for(i=0;i<N;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(stu[i].aver<stu[j].aver)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
		fwrite(&stu[i],sizeof(struct Stu),1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
