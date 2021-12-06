
/*
Write a C program to print reverse Pyramid or reverse equilateral triangle made of asterisks.
   Example:
   
   Enter the height: 5
   
   *********
    *******
     *****
      ***
       * 
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
int height,i,j;
printf("please enter the height: \n");
scanf("%d",&height);
printf("\n================================\n");
         
        for(i=1;i<=height;i++)    {
            
            for(j=1;j<i;j++)    {
                    printf(" ");}                   
            
            for(j=i;j<=height;j++){
                    printf("*");  }
            
            for(j=i;j<height;j++){
                    printf("*"); }
                                 
        printf("\n");
                                      }


printf("\n================================");



    return 0;
}
