/* Create a C program, which reads 2 integers. List all nontrivial factors for both numbers, then display one more list, which contains those factors, which are shared by both integers.

    Example:
    
    Enter 2 integers: 24 42
    24: 2 3 4 6 8 12
    42: 2 3 6 7 14 21
    Common factors: 2 3 6
*/

#include<stdio.h>
#include<stdlib.h>



int main(void){
int n1,n2,divider,n3,j;
printf("Enter 2 integers: ");
scanf("%d %d",&n1,&n2);
printf("|-------------------------------|");
printf("\n|CF:");
if(n1<n2||n1==n2){n3=n1;}if(n2<n1||n2==n1){n3=n2;}
                                                
for(int i=0;i<=n3;i++){if(n1%i==0 && n2%i==0){printf("%5d",i);}}
    
    printf("\n|-------------------------------|");
    printf("\n|%d:  ",n1);
    for(j=0;j<=n1;j++){
        if(n1%j==0){printf("%3d",j);}
                      }
    printf("\n|-------------------------------|");                             
    printf("\n|%d:  ",n2);
    for(j=0;j<=n2;j++){
        if(n2%j==0){printf("%3d",j);}
                      }           
    printf("\n|-------------------------------|");
return 0;


}
