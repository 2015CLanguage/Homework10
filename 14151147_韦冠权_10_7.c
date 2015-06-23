#include<stdio.h>
#include<stdlib.h> 
 struct Student                                           
 { 
 	int num; 
 	char name[8]; 
 	int score[3]; 
 	float ave; 
 }stu[5],a; 
 
 
 void main() 
 { 
 	FILE *fp,*fp1; 
 	int i,j,n,t; 
 	printf("\n学号:");                                         
 	scanf("%d", a.num); 
 	printf("姓名:"); 
 	scanf("%s", a.name); 
 	printf("学科1,学科2,学科3:"); 
 	scanf("%d,%d,&d", &a.score[0], &a.score[1], &a.score[2]); 
 	a.ave=(a.score[0]+ a.score[1]+ a.score[2])/3.0; 
 	if ((fp=fopen("stu_sort","r"))==NULL)                   
 	{ 
 		printf("不能打开该文件\n"); 
 		exit(0); 
 	} 
 	 

 	for(i=0; fread(&stu[i], sizeof(struct Student),1,fp)!=0; i++) 
 	printf("\n"); 
 	n=i;                                        
 	for(t=0; stu[t].ave>a.ave&&t<n; t++) 
 	fp1=fopen("sort1.dat", "w");                              
 	for (i=0;i<t; i++) 
 	{ 
 		fwrite(&stu[i], sizeof(struct Student), 1, fp1); 
 	} 
 	fwrite(&a, sizeof(struct Student), 1, fp1);               
 	for (i=t; i<n; i++) 
 	{ 
 		fwrite(&stu[i], sizeof(struct Student), 1, fp1); 
 	} 
 	printf("\n"); 
 	fclose(fp); 
 	fclose(fp1); 
 } 
