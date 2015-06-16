 #include <stdio.h> 
 #include <stdlib.h>  
 #include <string.h> 
 struct Grade 
 { 
 	int Id; 
 	double grade[3]; 
 	double aver; 
 	char Name[10]; 
 }G[10],tmp; 
 
 
 
 
 int main() 
 { 
 	FILE *fp; 
 	int i,j; 
 	for (i=0; i<5; i++) 
 	{ 
 		scanf("%d%s",&G[i].Id,G[i].Name); 
 		for (j=0; j<3; j++) 
 		scanf("%lf",&G[i].grade[j]); 
 		G[i].aver=(G[i].grade[0] + G[i].grade[1] + G[i].grade[2])/3; 
 	} 
 	for (i=0; i<5; i++) 
 	  for (j=i+1; j<5; j++) 
 	  if (G[i].aver>G[j].aver) 
 	  { 
 	  	tmp=G[i];G[i]=G[j];G[j]=tmp; 
      } 
 	if (( fp=fopen("stu_sort.dat","w") )== NULL) 
 	{ 
 		printf("error\n"); 
 		exit(0); 
 	} 
 	for (i=0; i<5; i++) 
 	{ 
 		fprintf(fp,"%d %s ",G[i].Id,G[i].Name); 
 		for (j=0; j<3; j++)  printf("%.0lf ",G[i].grade[j]); 
 		printf("%.1lf\n",G[i].aver); 
 	} 
 	fclose(fp); 
 	return 0; 
 } 
