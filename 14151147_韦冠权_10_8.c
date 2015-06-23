#include"stdio.h" 
#include"stdlib.h" 
#define N 5 
struct student 
 { 
 	char num[10]; 
 	char name[10]; 
 	float score[3]; 
 	float aver; 
 }; stu[N]
 int main() 
 { 
 	struct student c[N + 1]; 
 	int i, j; 
 	float sum; 
 	FILE *fp, *fp2; 
 
 
 	printf("学号："); 
 	scanf_s("%s", stu[N].num); 
 	printf("姓名:"); 
 	scanf_s("%s", stu[N].name); 
 	for (j = 0; j<3; j++) 
 	{ 
 		printf("科目%d成绩：", j + 1); 
 		scanf_s("%f", &stu[N].score[j]); 
 	} 
 
 
 	sum = 0; 
 	for (j = 0; j<3; j++) 
 	{ 
 		sum = sum + stu[N].score[j]; 
 	} 
 	c[N].aver = sum / 3; 
 
 
 
 	if ((fp = fopen("stdu.txt", "r")) == NULL) 
 	{ 
 		printf("cannot open the file"); 
 		exit(0); 
 	} 
 	fclose(fp); 
 	float temp; 
 	for (i = 0; i<N + 1; i++) 
 	{ 
 		for (j = i + 1; i<N; j++) 
 		{ 
 			if (stu[i].aver<stu[j].aver) 
 			{ 
 				temp = stu[i].aver; 
 				stu[i].aver = stu[j].aver; 
 				stu[j].aver = temp; 
 			} 
 		} 
 	} 
 	if ((fp2 = fopen("stdu.txt", "w+")) == NULL) 
 	{ 
 		printf("cannot open this file\n"); 
 		exit(0); 
 	} 
 	for (i = 0; i<N + 1; i++) 
 	{ 
 		fprintf(fp2, "%s%s", stu[i].num, stu[i].name); 
 		for (j = 0; j<3; j++) 
 		{ 
 			fprintf(fp2, "%3.2f", stu[i].score[j]); 
 		} 
 		fprintf(fp2, "%3.2f\n", stu[i].aver); 
 	} 
 	fclose(fp2); 
 } 
