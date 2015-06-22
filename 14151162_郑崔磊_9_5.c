Enter file contents here
#include<stdio.h> 
		+ #define N 10 
		+ struct Student 
		+ { 
		+ int num; 
		+ char name[20]; 
		+ float score[3]; 
		+ float avep; 
		+ }stu[N]; 
		+ int main() 
		+ { 
		+ int i,j,maxi; 
		+ for(i=0;i<N;i++) 
		+ { 
		+ printf("请输入学号："); 
		+ scanf("%d",&stu[i].num); 
		+ printf("请输入姓名："); 
		+ scanf("%s",stu[i].name); 
		+ for(j=0;j<3;j++) 
		+ { 
		+ printf("输入第%d科成绩：",j+1); 
		+ scanf("%f",&stu[i].score[j]); 
		+ } 
		+ } 
		+ float sum[3]={0},ave[3]={0}; 
		+ for(i=0;i<3;i++) 
		+ {for(j=0;j<N;j++) 
		+ {sum[i]=sum[i]+stu[j].score[i];} 
		+ ave[i]=sum[i]/N; 
		+ } 
		+ for(i=0;i<3;i++) 
		+ printf("第%d科的总平均分是：%8.2f\n",i+1,ave[i]); 
		+ 
		+ 
		+ float b[N]={0}; 
		+ for(i=0;i<N;i++) 
		+ {for(j=0;j<3;j++) 
		+ {b[i]=b[i]+stu[i].score[j];} 
		+ stu[i].avep=b[i]/3.0; 
		+ } 
		+ for(i=0;i<N-1;i++) 
		+ { 
		+ if(stu[i].avep>stu[i+1].avep) 
		+ stu[i+1]=stu[i]; 
		+ } 
		+ printf("平均分最高的学生是：%s\n",stu[N-1].name); 
		+ printf("他的学号是：%d\n",stu[N-1].num); 
		+ printf("他的平均分是：%8.2f\n",stu[N-1].avep); 
		+ for(i=0;i<3;i++) 
		+ printf("他的第%d科的成绩是：%8.2f\n",i+1,stu[N-1].score[i]); 
		+ } 
