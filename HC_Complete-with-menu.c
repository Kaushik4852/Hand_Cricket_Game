#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

int batting();
int bowling();
int toss();
int menu(int s);

enum gstatus {Notout, Out};
enum gstatus status = Notout;
int target = 0,x = 0;
int main()
{
    int  run1, run2,mopt;
    end:
    mopt=menu(target);
    if(mopt==1)
    {
      srand(time(NULL));
      x=toss();
        if (x==11 || x==22)
        {
          run1 = batting();
          target = run1 + 1;
          printf("\t\t\t\tTarget = %d\n", target);
          status = Notout;
          run2 = bowling();
            if(run1>run2)
            {
                printf("Player Wins");
            }
            if(run2>run1)
            {
                printf("Player Loses");
            }
            if(run1==run2)
            {
                printf("Draw");
            }
        }
        if (x==12 || x==21)
        {
          run1 = bowling();
          target = run1 + 1;
          printf("\t\t\t\tTarget = %d\n", target);
          status = Notout;
          run2 = batting();
            if(run2>run1)
            {
            printf("Player Wins");
            }
            if(run1>run2)
            {
            printf("Player Loses");
            }
            if(run1==run2)
            {
            printf("Draw");
            }
        }
        goto end;
    }
    return 0;
}
   


int menu(int s)
{
    int sel;
    if(target==0)
    {
        start11:
        printf("1>Start\n2>Exit\n");
        scanf("%d",&sel);
        switch(sel)
        {
            case 1:
            printf("Here goes nothing.\n");
            return 1;
            break;

            case 2:
            printf("Good bye\t&\tPlay again if you like.\n");
            exit(0);
            break;

            default:
            printf("Invalid option!!!!Try again.\n");
            goto start11;
        }
    }
    else
    {
        start12:
        printf("\n1>Play again\n2>Exit\n");
        scanf("%d",&sel);
        switch(sel)
        {
            case 1:
            printf("Here goes nothing.\n");
            target=0;
            return 1;
            break;

            case 2:
            printf("Good bye\t&\tPlay again if you like.\n");
            exit(0);
            break;

            default:
            printf("Invalid option!!!!Try again.\n");
            goto start12;
        }
    }
}

int batting()
{
    int run = 0;
    printf("\t\t\t\tPlayer's Move\t\tComputer's Move\t\tRun\n");
    while(status != Out)
    {
      int a,c;
      printf("Your Move: ");
      scanf("%d", &a);
      c = rand()%7;
      status = (a==c) ? Out : Notout;
      if(a>=0 && a<=6)
      {
      if(a==0)
      {
          run = run + c;
      }
      if(a!=c && status != Out)
      {
          run = run + a;
      }
      printf("\t\t\t\t%5d\t\t\t%5d\t\t%9d\n", a, c, run);
      if(run>=target && target!=0)
      break;
      }
      else
      {
          printf("Enter a number between 0-6!!\n");
      }
    }
    if(status == Out)
    printf("\n\n\t\t\t\t\t\t\t*****OUT*****\n");
    return run;
}
/*Declare Status = Out before calling the second function int the main function*/
int bowling()
{
    int run = 0;
    printf("\t\t\t\tPlayer's Move\t\tComputer's Move\t\tRun\n");
    while(status != Out )
    {
      int a,c;
      printf("Your Move: ");
      scanf("%d", &a);
      if(a>=0 && a<=6)
      { 
      c = rand()%7;
      status = (c==a) ? Out : Notout;
      if(c==0)
      {
          run = run + a;
      }
      if(c!=a && status != Out)
      {
          run = run + c;
      }
      printf("\t\t\t\t%5d\t\t\t%5d\t\t%9d\n", a, c, run);
      if(run>=target && target!=0)
      break;
      }
      else
      {
          printf("Enter a number between 0-6!!\n");
      }
    }
    if(status == Out)
    printf("\n\n\t\t\t\t\t\t\t*****OUT*****\n");
    return run;
}
int toss()
{
   int r = rand()%2,opt;
    int compr = rand()%2;
   printf("Enter 1->Head\t2->Tail:\n");
   scanf("%d",&opt);
   if(opt ==1 || opt==2)
    {
          if( (opt==1 && r==0 ) || (opt==2 && r==1))
          {
              printf("You win the toss.\n");
              printf("Choose  1->Bat\t2->Bowl:\n");
              scanf("%d", &opt);
                 switch(opt)
                 {
                     case 1:
                     return 11;
                     break;
                     case 2:
                     return 12;
                     break;
                     default:
                     printf("Enter 1 or 2!!!");
                 }
          }
          else
          {
             printf("You loss the toss.\n");
             
             switch(compr)
             {
                 case 0:
                 printf("Computer Chose to Bat\n");
                 return 21;
                 break;
                 case 1:
                 printf("Computer Chose to Bowl\n");
                 return 22;
                 break;
    
             }     
          }
    }
   else
    {
       printf("Enter 1 or 2!!!!");
    }
}
