

#include <stdio.h>
#include<stdlib.h>
struct stu_infor{
    int No;
    char name[10];
    float grade[3];
    float ave;
}stu[5];
int main(int argc, const char * argv[]) {
    void aver(struct stu_infor stu[5]);
    FILE *fp;
    int i,j;
    //input
    for(i=0;i<5;i++){
        printf("\ninformation of the %dth student !",i+1);
        printf("\nNo:");
        scanf("%d",&stu[i].No);
        printf("\nname:");
        scanf("%s",stu[i].name);
        for(j=0;j<3;j++){
            printf("\ngrade%d:",j+1);
            scanf("%f",&stu[i].grade[j]);
        }
    }
    aver(stu);
    //write in file
    fp=fopen("stud.dat","w");
    if (fp==NULL) {
        printf("0");
    }
    else printf("1");
    for(i=0;i<5;i++){
        if(fwrite(&stu[i],sizeof(struct stu_infor),1,fp)!=1)
            printf("file write error !");
    }
    fclose(fp);
    //output
    fp=fopen("stud.dat","r");
    for(i=0;i<5;i++){
        if(fread(&stu[i],sizeof(struct stu_infor),1,fp)!=0){
            printf("\n%5d%10s",stu[i].No,stu[i].name);
            for(j=0;j<3;j++)
                printf("%8.2f",stu[i].grade[j]);
            printf("%8.2f",stu[i].ave);
        }
    }
    fclose(fp);
    return 0;
}
void aver(struct stu_infor stu[5]){
    int i;
    for(i=0;i<5;i++)
        stu[i].ave=(stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[0])/3;
}
