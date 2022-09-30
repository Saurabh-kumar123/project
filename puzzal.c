#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
 // show matrix
  void showmatrix(int arr[][4])
   {
        int i,j;
        printf("---------------------\n");
        for(i=0;i<4;i++)
        {
             printf("| ");
          for(j=0;j<4;j++)
          {
               if(arr[i][j]!=0)
             printf("%2d | ", arr[i][j]);
             else
                    printf("   | ");
          }
          printf("\n");
        }
          printf("---------------------\n");
   }
   // game rule
  void  gamerule(int arr[][4])
   {
        system("cls");
        int i,j,k=0;
        printf("\n       {   Matrix Puzzle  }\n\n");
        printf("         Rule of this Game\n");
        printf("        -------------------\n\n");
        printf("  you can move only 1 step at a time by arrow key \n\n");
        printf("\t|  up arrow key   |\n");
        printf("\t| down arrow key  |\n");
        printf("\t| left arrow key  |\n");
        printf("\t| right arrow key | \n\n");
        printf("  you can move number at empty position only\n");
        printf("  each valid move total chance from decreased by 1 chance\n\n");
        printf("{.....winning situation.....}\n\n");
        printf("---------------------\n");
        for(i=0;i<4;i++)
        {
             printf("| ");
             for(j=0;j<4;j++)
             {
                  if(arr[i][j]!=0)
                    printf("%2d | ",4*i+j+1);
                  else
                    printf("   | ");
             }
             printf("\n");
        }
        printf("---------------------\n");
        printf("\n  you can exit the game at any time by pressing 'E' or 'e' ");
        printf("\n  try to win minimum number of move\n");
        printf("  Enter any key to start........");
        int x = readEnteredKey();
   }
  // create matrix
  void creatematrix(int arr[][4])
  {
       int n=15;
       int num[n],i,j;
       for(i=0;i<15;i++) // these 1 - 15 number
          num[i]=i+1;
       srand(time(NULL));  //for random number generate
       int lastindex = n-1,index;
       for(i=0;i<4;i++)
          for(j=0;j<4;j++)
       {
            if(lastindex >= 0)
            {
                 index = rand()% (lastindex + 1);
                 arr[i][j]=num[index];
                 num[index]=num[lastindex--];
            }
       }
       arr[i-1][j-1]=0; // last number is zero
  }
  // winning check by this fuction
  int winner(int arr[][4])
  {
       int i,j,k=1;
       for(i=0;i<4;i++)
       {
            for(j=0;j<4;j++,k++)
            if(arr[i][j]!=k&&k!=16)
            break;
            if(j<4)
               break;
       }
       if(j<4)
          return 0;
       return 1;
  }
   // swap function
   void swap(int *x,int *y)
   {
        *x=*x+*y;
        *y=*x-*y;
        *x=*x-*y;
        printf("");
   }
   // read char value return ascii value of that
   int readEnteredKey()
   {
        char c;
        c = _getch();
        if(c==-32)
          c = _getch();
        return c;
   }
   // shift up
   int shiftUp(int arr[][4])
   {
        int i,j;
        for(i=0;i<4;i++)
        {
             for(j=0;j<4;j++)
               if(arr[i][j]==0)
               break;
             if(j<4)
               break;
        }
        if(i==3)
          return 0;
        swap(&arr[i][j],&arr[i+1][j]);
        return 1;
   }
   int shiftDown(int arr[][4])
   {
        int i,j;
        for(i=0;i<4;i++)
        {
             for(j=0;j<4;j++)
               if(arr[i][j]==0)
               break;
             if(j<4)
               break;
        }
        if(i==0)
          return 0;
        swap(&arr[i][j],&arr[i-1][j]);
        return 1;
   }
   int shiftRight(int arr[][4])
   {
        int i,j;
        for(i=0;i<4;i++)
        {
             for(j=0;j<4;j++)
               if(arr[i][j]==0)
               break;
             if(j<4)
               break;
        }
        if(j==0)
          return 0;
        swap(&arr[i][j],&arr[i][j-1]);
        return 1;
   }
   int shiftLeft(int arr[][4])
   {
        int i,j;
        for(i=0;i<4;i++)
        {
             for(j=0;j<4;j++)
               if(arr[i][j]==0)
               break;
             if(j<4)
               break;
        }
        if(j==3)
          return 0;
        swap(&arr[i][j],&arr[i][j+1]);
        return 1;
   }
//  main function...
int main()
{
     int arr[4][4]; //matrix
     int maxtry=10;  //try
     char name[20];
     printf("\n--------------------(  Number Shifting Game  )-------------------\n\n");
     printf("  Player name :  ");
     fgets(name,20,stdin);
     system("cls"); // clear screen
  while(1)
  {
     creatematrix(arr);  //calling function to create matrix
     gamerule(arr); // game rule calling
     while(!winner(arr))  //checking for winning sitiuation
     {
          system("cls");
     if(!maxtry) // for reaming move
          break;
      printf("\n\n Player name :  %s   Available  Chance   :  %d\n\n",name,maxtry);
      showmatrix(arr);
      int key = readEnteredKey();
      switch(key)
      {
           case 101:
           case 69:
               printf("\a\a\a\a\a\a\n    Thank for playing  ! \n\a");
               printf("\nEnter to exit the game\n");
               key = readEnteredKey();
               return 0;
           case 72:
               if(shiftUp(arr))
                    maxtry--;
               break;
           case 80:
               if(shiftDown(arr))
                    maxtry--;
               break;
           case 77:
               if(shiftRight(arr))
                    maxtry--;
               break;
           case 75:
               if(shiftLeft(arr))
                    maxtry--;
               break;
           default:
               printf("\n\n   \a\aNot allowed \a");
      }
     }
     if(!maxtry)
     printf("\n\a    !  You Lose !     \a\a\n");
     else
          printf("\n!!!!!!!!     YOU  WIN     !!!!!!\n\n!!!!!   Congratulation  %s   !!!!\a",name);
     fflush(stdin);
     char check;
     printf("\n  want to play again ?\n");
     printf("enter  'y' to play again: ");
     scanf("%c",&check);
     if((check!='y')&&(check!='Y'))
     {
     printf("\nThanks for playing this Game...  %s\n",name);
        break;}
      maxtry = 10;
  }
     return 0;
}
