#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100


typedef struct   				//structure that contains details of every passenger
{
  char name[20];
} details;

typedef struct 
{ 
  int passno,waitlistno;	//contains no of passengers and people in waitlist for each coach
  details pass[MAX_SIZE];	//array of passenger details
  details waitlist[MAX_SIZE];	//array of details in waiting list
} coach;

typedef struct 
{ 
  coach ac;			//the three mandatory coaches
  coach sl;
  coach unr;
  coach add1;			//additional three coaches for each mandatory coach
  coach add2;
  coach add3;
} train;
train t1,t2;			//two trains to be managed or create array of trains
int passno=0,waitlistno=0;		//initialise no od passengers to 0 in each list

void view()
{
  int a;
  printf("ENTER THE TRAIN NO: \n 1:FOR SHATABDI \n 2: FOR RAJDHANI \n");
  scanf("%d",&a);
  switch(a)		//for each train: prints the no of passengers and people in waiting list
  { 
    case 1: 
    printf("FOR SHATABDI THE STATUS IS \n");
    printf("The number of passengers are in AC Coach are \n %d passengers \n %d waiting list ",t1.ac.passno,t1.ac.waitlistno);
    printf("The number of passengers are in SL Coach are \n %d passengers \n %d waiting list ",t1.sl.passno,t1.sl.waitlistno);
    printf("The number of passengers are in UN-RESERVED Coach are \n %d passengers \n %d waiting list ",t1.unr.passno,t1.unr.waitlistno);
    break;
    case 2:  
    printf("FOR RAJDHANI THE STATUS IS \n");
    printf("The number of passengers are in AC Coach are \n %d passengers \n %d waiting list 
3



",t2.ac.passno,t2.ac.waitlistno);
    printf("The number of passengers are in SL Coach are \n %d passengers \n %d waiting list ",t2.sl.passno,t2.sl.waitlistno);
    printf("The number of passengers are in UN-RESERVED Coach are \n %d passengers \n %d waiting list ",t2.unr.passno,t2.unr.waitlistno);
    break;
  }
}


void reserve()
{ 
  int b,c,i;
  printf("CHOOSE THE DESIRED TRAIN: \n 1: SHATABDI \n 2: RAJDHANI \n");
  scanf("%d",&b);
  if(b==1)			//for the selection of train
  { 
    printf("CHOOSE THE DESIRED COACH \n 1: AC \n 2:SL \n 3:UN-RESERVED \n");
    scanf("%d",&c);
    switch(c) 			//for the selection of coach
    { 
      case 1:
      printf("Enter your name \n");
      if (t1.ac.passno<MAX_SIZE)	//if coach is not full, add to the coach
      {
        scanf("%s",&t1.ac.pass[t1.ac.passno++].name);
        printf("TICKET CONFIRMED IN AC COACH \n",t1.ac.pass[passno].name);
      }
      else
      { 
        if(t1.ac.waitlistno<75)			//if waiting list is not full, add to the waiting list
          scanf("%s",t1.ac.waitlist[t1.ac.waitlistno++].name);
        else					//if waiting list exceeds 75, create new coach
        { 
          for(i=0;i<75;i++)
          {
            strcpy(t1.add1.pass[i].name, t1.ac.waitlist[i].name);
          }
          t1.ac.waitlistno=0;
          scanf("%s",t1.ac.waitlist[t1.ac.waitlistno++].name);
        }
      }
      break;


      case 2: 
      printf("Enter your name \n");
      if (t1.sl.passno<MAX_SIZE)
      {
        scanf("%s",t1.sl.pass[t1.sl.passno++].name);
        printf("TICKET CONFIRMED IN SL COACH",t1.sl.pass[t1.sl.passno].name);
      }
      else 
      { 	4
        if(t1.sl.waitlistno<75)
          scanf("%s",t1.sl.waitlist[t1.sl.waitlistno++].name);
        else
        { 
          for(i=0;i<75;i++)
          {
            strcpy(t1.add2.pass[i].name, t1.sl.waitlist[i].name);
          }
          t1.sl.waitlistno=0;
          scanf("%s",t1.sl.waitlist[t1.sl.waitlistno++].name);
        }
      }
      break;


      case 3:
      printf("Enter your name \n");
      if (t1.unr.passno<MAX_SIZE)
      {
        scanf("%s",t1.unr.pass[t1.unr.passno++].name);
        printf("TICKET CONFIRMED IN UN-RESERVED COACH",t1.unr.pass[t1.unr.passno].name);
      }
      else
      {
        if(t1.unr.waitlistno<75)
          scanf("%s",t1.unr.waitlist[t1.unr.waitlistno++].name);
        else 
        { 
          for(i=0;i<75;i++)
          {
            strcpy(t1.add3.pass[i].name, t1.unr.waitlist[i].name);
          }
          t1.unr.waitlistno=0;
          scanf("%s",t1.unr.waitlist[t1.unr.waitlistno++].name);
        }
      }
      
    }
  }
  else if(b==2)
  { 
    printf("CHOOSE THE DESIRED COACH \n 1: AC \n 2:SL \n 3:UN-RESERVED \n");
    scanf("%d",&c);

    switch(c)
    {
      case 1:
      
        printf("Enter your name \n");
        if (t2.ac.passno<MAX_SIZE)
        {
          scanf("%s",t1.ac.pass[t2.ac.passno++].name);
       5
   printf("TICKET CONFIRMED IN AC COACH FOR %s",t1.ac.pass[t2.ac.passno].name);
        }
        else 
        { 
          if(t2.ac.waitlistno<75)
          scanf("%s",t2.ac.waitlist[t2.ac.waitlistno++].name);
          else
          { 
            for(i=0;i<75;i++)
            {
              strcpy(t2.add1.pass[i].name, t2.ac.waitlist[i].name);
            }
            t2.ac.waitlistno=0;
            scanf("%s",t2.ac.waitlist[t2.ac.waitlistno++].name);
          }
       }
     break;


    case 2:
    
      printf("Enter your name \n");
      if (t2.sl.passno<MAX_SIZE)
      {
        scanf("%s",t2.sl.pass[t2.sl.passno++].name);
        printf("TICKET CONFIRMED IN SL COACH FOR %s",t2.sl.pass[t2.sl.passno].name);
      }
     else
     { 
        if(t2.sl.waitlistno<75)
          scanf("%s",t2.sl.waitlist[t2.sl.waitlistno++].name);
        else 
        { 
          for(i=0;i<75;i++)
          {
            strcpy(t2.add2.pass[i].name, t2.sl.waitlist[i].name);
          }
          t2.sl.waitlistno=0;
          scanf("%s",t2.sl.waitlist[t2.sl.waitlistno++].name);
        }
      }
      break;

    case 3:
      printf("Enter your name \n");
      if (t2.unr.passno<MAX_SIZE)
      {
        scanf("%s",t2.unr.pass[t2.unr.passno++].name);
        printf("TICKET CONFIRMED IN UN-RESERVED COACH FOR %s",t2.unr.pass[t2.unr.passno].name);
      }
      else
      { 
        if(t2.unr.waitlistno<75)	6
          scanf("%s",t2.unr.waitlist[t2.unr.waitlistno++].name);
        else
        { 
          for(i=0;i<75;i++)
          {
            strcpy(t2.add3.pass[i].name, t2.unr.waitlist[i].name);
          }
          t2.unr.waitlistno=0;
          scanf("%s",t2.unr.waitlist[t2.unr.waitlistno++].name);
        }
      }
      break;
    }
  }
  else
   printf("INVALID CHOICE");
}

void cancel(int n)
{ 
  int b,count1=0,count2=0,count3=0,c;
  printf("CHOOSE THE DESIRED TRAIN: \n 1: SHATABDI \n 2: RAJDHANI \n");
  scanf("%d",&b);
  if(b==1)		//for selection of train
  { 
    printf("CHOOSE THE DESIRED COACH \n 1: AC \n 2:SL \n 3:UN-RESERVED \n");
    scanf("%d",&c);

    switch(c) 	//for a certain coach delete the particular passenger and insert from waiting list 
    { 
      case 1: strcpy(t1.ac.pass[n].name, t1.ac.waitlist[count1++].name);	
           t1.ac.passno--;
           break;
      case 2: strcpy(t1.sl.pass[n].name, t1.sl.waitlist[count2++].name);
           t1.sl.passno--;
           break;
      case 3: strcpy(t1.unr.pass[n].name, t1.unr.waitlist[count3++].name);
           t1.unr.passno--;
           break;
    }
  }
  else if(b==2)
  { 
    printf("CHOOSE THE DESIRED COACH \n 1: AC \n 2:SL \n 3:UN-RESERVED \n");
    scanf("%d",&c);

    switch(c)
    { 
      case 1: strcpy(t2.ac.pass[n].name, t2.ac.waitlist[count1++].name);
           t2.ac.passno--;
           break;
      case 2: strcpy(t2.sl.pass[n].name, t2.sl.waitlist[count2++].name);
          t2.sl.passno--;
          break;	7
      case 3: strcpy(t2.unr.pass[n].name, t2.unr.waitlist[count3++].name);
               t2.unr.passno--;
          break;
    }

  }
}
int main()
{ 
  int ch,n;
  while(1)		//menu driven function calls
  { 
    printf(" SELECT THE OPTION \n 1: VIEW ALL TRAINS \n 2: RESERVE A TICKET \n 3:CANCEL A TICKET \n 4:EXIT \n");
    scanf("%d",&ch);
    switch(ch)
    { 
      case 1: view();
      //getch();
      //menu();
      break;
      case 2: reserve();
      //getch();
      //menu();
      break;
      case 3:
      printf("Enter your passno or waitlistno\n");
      scanf("%d",&n);
      cancel(n);
      //getch();
      //menu();
      break;
      
      case 4: 
        return 0;
      break;


      default: printf("Enter a valid option:");
    }
  }
}
