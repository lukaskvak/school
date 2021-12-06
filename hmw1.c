/*1. Create a program, which
    a) generates 10 random integers,
    b) shows them,
    c) gives a user choice to
        i)  erase an element - the user may choose its position;
        ii) add a new element - the user's choice is the value and position.
        Whenever a choice is made, the array elements are going to be shown.
        Keep in mind the meaning of the operations - here is an example:
       
        2 71 99 37 46 12 15 10 68 53
        Which operation is wanted?
        1 - erase an element
        2 - add an element
       
        > 1
        Which position?
       
        > 3
        2 71 99 46 12 15 10 68 53
        Which operation is wanted?
        1 - erase an element
        2 - add an element
       
        > 2
        What value and to what position should I add?
        > 77 6
        2 71 99 46 12 15 77 10 68 53*/




#include <stdio.h>
#include <stdlib.h>

int main(void) {

int value = 0;
int position = 0;
int valueofelement = 0;

int array[10],i;
for(i=0;i<10;i++){
    array[i]=rand()%100;
}
for(i=0;i<10;i++){
    printf("|%d|",array[i]);
}
printf("\n Which operation is wanted?\n1 - erase an element\n2 - add an element\nPlease enter the value: ");
scanf("%d",&value);
switch(value){

    case 1:
    printf("You have selected to erase an element");
    printf("\nWhat your element position is: ");
    scanf("%d",&position);
    for(i=0;i<position;i++){
    printf("|%d|",array[i]);
     }
    for(i=position+1;i<10;i++){
    printf("|%d|",array[i]);
}
break;
case 2:
printf("You have selected to add an element into an array");
printf("\nWhat value your element is: ");
scanf("%d",&valueofelement);
printf("\nOn what position would you like to add the element: ");
scanf("%d",&position);
for(i=0;i<position;i++){
    printf("|%d|",array[i]);
     }
printf("|%d|",valueofelement);   
printf("|%d|",array[position]);
for(i=position+1;i<10;i++){
 printf("|%d|",array[i]);
}






}    

    return 0;
}