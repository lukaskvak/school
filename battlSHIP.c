
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h>

#define SIZE 10	/* constant for size of game board */
/* function prototypes */

void displayhit(int **board);
void printGridRow(int i);
void dispGrid(int **board);
int assignShip(int **board, int shipType);
void hitormiss(int **board);
char roww;
       int  colm;
       int  HITC; 

int main(void)
{
    int i;
 int j;
        int **board;		/* pointer to two-dimensional array for game board */
       			/* index used in loop counters, specifically outer loop */
        			/* index used in loop counters, specifically inner loop */
	/* user input for difficulty of game */
        int validLoc = 0;	/* boolean indicating whether or not valid location found to assign ship */

	 

	  /* assign number of shots available based on difficulty level chosen */
       



        printf("Initializing board... ");

        /* allocate memory for and initialize two-dimensional board */
        board = calloc(SIZE, sizeof(int *));

        for(i = 0; i < SIZE; i++)
        {
                board[i] = calloc(SIZE, sizeof(int));
        }

        /* now place battleship on board */
        printf("now let's begin!\n\n");
    
	  /* repeatedly attempt to assign battleship until successful */
        while (!validLoc)
        {
                validLoc = assignShip(board, 4);//B
        }

        	/* re-initialize valid location to false for aircraft carrier */
        validLoc = 0;
         while (!validLoc)
        {
                validLoc = assignShip(board, 4);//B
        }
                validLoc = 0;
	  /* repeatedly attempt to assign aircraft carrier until successful */
        while (!validLoc)
        {
                validLoc = assignShip(board, 5); //A
        }
        validLoc = 0;
            while (!validLoc)
        {
                validLoc = assignShip(board, 3);
                 ;//D
        }

                validLoc = 0;

       
          /* call function to display board with ships assigned */	
      dispGrid(board);
      printf("Give me the coords. for the hit: ");
      scanf("%c%d",&roww,&colm);
      int colmm = colm - 1;        
       switch (roww){

case 'A':
HITC = 0 ;
break;
case 'B':
HITC = 1 ; 
    break;
case 'C':
HITC = 2;
break;
case 'D':
HITC = 3;
break;
case 'E':
HITC = 4;
break;
case 'F':
HITC = 5;
break;
case 'G':
HITC = 6;
break;
case 'H':
HITC = 7;
break;
case 'I':
HITC = 8;
break;
case 'J':
HITC = 9;
break;


default: printf("you have entered wrong coords...");

}
  
  printf("%d%d",HITC,colmm);
    
  if(board[HITC][colmm] == 3 || board[HITC][colmm] == 4 || board[HITC][colmm] == 5){
          board[HITC][colmm] += 10;
         dispGrid(board);
        
  }
    


     
  
        return 0;
}

        
        
    

void printGridRow(int i)
{
	  /* based on row integer passed, print out corresponding row letter of board 
        switch (i)
        {
        case 0: printf("A| ");
                break;
        case 1: printf("B| ");
                break;
        case 2: printf("C| ");
                break;
        case 3: printf("D| ");
                break;
        case 4: printf("E| ");
                break;
        case 5: printf("F| ");
                break;
        case 6: printf("G| ");
                break;
        case 7: printf("H| ");
                break;
        case 8: printf("I| ");
                break;
        case 9: printf("J| ");
                break;
        default:printf("Unknown grid row value: %d. Program terminating.\n", i);
                exit(1);
        }
        */

      printf("%c|",'A'+i);  
}


void dispGrid(int **board)
{
        int  i;	/* index used in outer loop counter */
        int  j;	/* index used in inner loop counter */

        printf("   0123456789 \n");
        printf("  +---------+\n");  
        

	  /* loop through two-dimensional array to print out corresponding items */
        for (i = 0; i < SIZE; i++)
        {
                printGridRow(i); /* print grid row and left vertical column of board */

                for (j = 0; j < SIZE; j++)
                {
                        switch (board[i][j])
                        {
                         case 0: /* print blank space for open/unassigned location */
                                printf("?");
                                 break;


                         case 3: printf("?");  /* print d destroyer */
                                break;


                         case 4: /* print 'B' for assigned battleship */
                                printf("?");
                                    
                                 break;
                         case 5: /* print 'A' for assigned aircraft carrier */
                                 printf("?");
                                
                                 break;

                        case 13: printf("D");  /* print d destroyer */
                                break;


                         case 14: /* print 'B' for assigned battleship */
                                printf("B");
                                    
                                 break;
                         case 15: /* print 'A' for assigned aircraft carrier */
                                 printf("A");
                                
                                 break;       
                        default:/* should never get here, but handle error case by terminating program gracefully */
                                printf("Unknown value for board[%d][%d] : %3d. Terminating program.\n", i, j, board[i][j]);
                                exit(1);
                        }
                }


                printf("|\n");  /* print right vertical column of board */
        }

        printf(" +-------------------------------+\n");
      

}
/*void hitormiss(int **board){
dispGrid(board);
char roww;
int colm;
int HITC;
printf("Please enter spot to hit e.g A4 : ");
scanf("%c",&roww);
scanf("%d",&colm);

switch (roww){
case 'A':
HITC = 0 ;
    break;
case 'B':
HITC = 1 ; 
    break;
case 'C':
HITC = 2;
break;
case 'D':
HITC = 3;
break;
case 'E':
HITC = 4;
break;
case 'F':
HITC = 5;
break;
case 'G':
HITC = 6;
break;
case 'H':
HITC = 7;
break;
case 'I':
HITC = 8;
break;
case 'J':
HITC = 9;
break;


default: printf("you have entered wrong coords...");








}
if


}
*/

int assignShip(int **board, int shipType)
{
        int valid = 0;  /* use 0 for false (not assigned); otherwise 1 means assigned successfully */
        int i;		/* index used in loop counter as row */
        int j;		/* index used in loop counter as column */
        int vertical;	/* randomly generated ship orientation */
        int shipRowPos;	/* randomly generated row position of ship */
        int shipColPos;	/* randomly generated column position of ship */

        srand(time(NULL));

        vertical   = rand() % 2;	/* randomly generated ship orientation: 1 = vertical, 0 = horizontal */

        shipRowPos = rand() % 10;	/* randomly generated ship row position */ 
        shipColPos = rand() % 10;	/* randomly generated ship column position */

        if (vertical) /* vertical orientation */
        {
		    /* check to see whether a vertical ship can be placed on board at this location */
                if ((shipRowPos + shipType) < SIZE)
                {
                        /* need check if ship already in this position first */
                        for (i = shipRowPos; i < (shipRowPos + shipType); i++)
                        {
                                if (board[i][shipColPos] != 0)
                                {
                                        /* ship already here, return valid = 0 */
                                        return valid;
                                }
                        }

                        /* ship able to fit vertically on board */
                        valid = 1;

                        /* need assign ship's position on board */
                        for (i = shipRowPos; i < (shipRowPos + shipType); i++)
                        {
                                board[i][shipColPos] = shipType;
                        }
                }
        }
        else /* horizontal orientation */
        {
		    /* check to see if horizontal ship can be placed on board at this location */
                if ((shipColPos + shipType) < SIZE)
                {
                        /* need check if ship already in this position first */
                        for (j = shipColPos; j < (shipColPos + shipType); j++)
                        {
                                if (board[shipRowPos][j] != 0)
                                {
                                        /* ship already here */
                                        return valid;
                                }
                        }

                        /* ship able to fit vertically on board */
                        valid = 1;

                        /* need assign ship's position on board */
                        for (j = shipColPos; j < (shipColPos + shipType); j++)
                        {
                                board[shipRowPos][j] = shipType;
                        }
                }
        }

        return valid;
}
