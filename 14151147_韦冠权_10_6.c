#include<stdio.h> 
 #define N 5 
 void save(); 
 struct Student 
 { 
 	int index; 
 	char name[20]; 
 	float score[3]; 
 	float aver; 
 }; 
 struct Student stu[N],temp; 
 void save() 
 { 
 	FILE *fp; 
 	int i; 
 	if((fp=fopen("stud.dat","wb"))==NULL) 
 	{ 
 		printf("文件无法打开.\n"); 
 	} 
 	for(i=0;i<N;i++) 
 	{ 
 		if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1) 
 		{ 
 			printf("数据写入错误.");  
 		} 
 	} 
 	fclose(fp); 
 } 
 int main() 
 { 
 	int i,j; 
 	printf("请输入5个学生的信息：\n");  
 	for(i=0;i<N;i++) 
 	{ 
 		scanf("%d%s%f%f%f",&stu[i].index,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]); 
 		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;  
 	} 
 	save(); 
 	FILE *fp1; 
 	fp1=fopen("stud.dat","rb"); 
 	for(i=0;i<N;i++) 
 	{ 
 	    fread(&stu[i],sizeof(struct Student),1,fp1); 
     } 
     fclose(fp1); 
     for (i=0; i<N; i++) 
     { 
 	    for (j=i+1; j<N; j++) 
 	    { 
 	        if (stu[i].aver<stu[j].aver) 
 	        { 
 	  	        temp=stu[i]; 
 				stu[i]=stu[j]; 
 				stu[j]=temp; 
 	  	    } 
 	    } 
     } 
     FILE *fp2; 
     if((fp2=fopen("stu_sort.dat","wb"))==NULL) 
 	{ 
 		printf("文件无法打开.\n"); 
 		return 0; 
 	} 
 	printf("排序后为：\n"); 
 	for(i=0;i<N;i++) 
 	{ 
 		if(fwrite(&stu[i],sizeof(struct Student),1,fp2)!=1) 
 		{ 
 			printf("数据写入错误.");  
 		} 
 		printf("该学生的学号：%d 姓名：%s 三门课成绩：%5.1f %5.1f %5.1f 平均分：%5.1f"
 		,stu[i].index,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver); 
 	} 
 	fclose(fp2); 
 	return 0; 
 } 
