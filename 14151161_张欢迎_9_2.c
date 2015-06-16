 #include <stdio.h> 
 int days(int year,int month,int day); 
 struct date 
 { 
     int year; 
     int month; 
     int day; 
 }date; 
 
 
 int main() 
 { 
     int day=0; 
     printf("输入年月日:"); 
     scanf("%d,%d,%d",&date.year,&date.month,&date.day); 
     day=days(date.year, date.month, date.day); 
     printf("是第%d天\n",day); 
     return 0; 
 } 
 
 
 int days(int year,int month,int day) 
 { 
     int result=0; 
     switch (month) 
     { 
         case 1:{result=day;break;} 
         case 2:{result=day+31;break;} 
         case 3:{result=day+59;break;} 
         case 4:{result=day+90;break;} 
         case 5:{result=day+120;break;} 
         case 6:{result=day+151;break;} 
         case 7:{result=day+181;break;} 
         case 8:{result=day+212;break;} 
         case 9:{result=day+243;break;} 
         case 10:{result=day+273;break;} 
         case 11:{result=day+304;break;} 
         case 12:{result=day+334;break;} 
         default: 
             break; 
     } 
      
     if (((year%4==0&&year%100!=0)||year%400==0)&&month>=3) 
     { 
         result+=1; 
     } 
     return result; 
 } 
