#include<stdio.h>
#define N 2
struct Stu
{
	int num;
	char name[20];
	float score[3];
	float aver;
}st[N],stunew,check[N+1];
int main()
{
	int i,m;
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("stud_sort.dat","rb");
	printf("the original file\n");
	for(i=0;i<N;i++)
	{
		fread(&st[i],sizeof(struct Stu),1,fp1);
		printf("%d %s %3.1f %3.2f %3.1f %3.1f\n",st[i].num,st[i].name,st[i].score[0],st[i].score[1],st[i].score[2],st[i].aver);
	}
	printf("please input student's scores\n");
	scanf("%d%s%f%f%f",&stunew.num,stunew.name,&stunew.score[0],&stunew.score[1],&stunew.score[2]);
	stunew.aver=(stunew.score[0]+stunew.score[1]+stunew.score[2])/3;
	fclose(fp1);
	fp2=fopen("stud_sort.dat","wb");
	for(m=0;m<N&&st[m].aver>stunew.aver;m++);
	for(i=0;i<m;i++)
	{
		fwrite(&st[i],sizeof(struct Stu),1,fp2);
	}
	fwrite(&stunew,sizeof(struct Stu),1,fp2);
	for(i=m;i<N;i++)
	{
		fwrite(&st[i],sizeof(struct Stu),1,fp2);
	}
	fclose(fp2);
	fp3=fopen("stud_sort.dat","rb");
	for(i=0;i<N+1;i++)
	{
		fread(&check[i],sizeof(struct Stu),1,fp3);
		printf("%d %s %3.1f %3.2f %3.1f %3.1f\n",check[i].num,check[i].name,check[i].score[0],check[i].score[1],check[i].score[2],check[i].aver);
	}
	fclose(fp3);
	return 0;
}
