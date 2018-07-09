//************SNAKE GAME**************
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<ctype.h>
#include<process.h>
#include<stdlib.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
int length;
int len;
int life;
int bend_no;
void print();
char key;
void load();
void border();
void Food();
void endgame();
int Score();
void Bend();
void Down();
void gotoxy(int x,int y);
void gotoXY(int x,int y);
void Up();
void Left();
void Right();
void move();
void delay(long double);
void Bend();



 struct coordinate {
	int x;
	int y;
	int direction;
};

struct coordinate body[30],head,food,bend[500];

int main()
{
	char key;
	print();
	system("cls");
	load();
	length=5;
	head.x=25;
	head.y=20;
	head.direction=RIGHT;
	Food();
	border();
	life=3;
	bend[0]=head;
	move();

	 return 0;
}
void print()
{
	printf("welcome to the snake game\npress any key to continue\n");
	getch();
	system("cls");
	printf("game instructions\nuse arrow keys to move the snake\ncollect the food provided at various co ordinates\nthe lenght of the snake will increase by one element and thus the score\n ");
	printf("you will have 3 lives\nlives qwill decrease if u hit the wall or yourself\n pause the game by pressing any key, to unpause it press any other key\n if u want to exit press esc\n");
	printf("press any key to play the game\n");
	if(getch()==27)
	exit (0);	
}
void gotoxy(int x,int y)
{
	COORD coord;
	HANDLE a;
	coord.X=x;
	coord.Y=y;
	a=GetStdHandle(STD_OUTPUT_HANDLE);
	
SetConsoleCursorPosition(a,coord);
}
void gotoXY(int x,int y)
{
	COORD b;
	HANDLE c;
	fflush(stdout);
	b.X=x;
	b.Y=y;
	c=GetStdHandle(STD_OUTPUT_HANDLE);
	
SetConsoleCursorPosition(c,b);
}
void load()
{
	int r,q;
	 
	gotoxy(36,14);
	printf("loading...");
	gotoxy(30,15);
	for(r=0;r<=20;r++)
	{
		for(q=0;q<=10000000;q++);
		printf("%c",177);
	}
	getch();
}
void border()
{
	system("cls");
	int i;
	gotoXY(food.x,food.y);
	printf("o");
	for(i=10;i<71;i++)
	{
		gotoXY(i,10);
		printf("!");
		gotoXY(i,30);
		printf("!");
	}
		for(i=10;i<31;i++)
		{
			gotoXY(10,i);
			printf("!");
			gotoXY(70,i);
			printf("!");
			
		}
	
	
	
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
 
            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void endgame()
{
	int i,f=0;
	for(i=4;i<=length;i++)
	{
		if(body[0].x==body[i].x && body[0].y==body[i].y)
		{
			f=1;
				
		}
		if(i==length||f!=0)
		break;
		
	}
	if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||f!=0)
	{
		life--;
		if(life>=0)
		{
			head.x=25;
			head.y=20;
			bend_no=0;
			head.direction=RIGHT;
			move();
		}
		else
		{
			system("cls");
			printf("all the lives are over\npress any key to exit\n");
			exit(0);
		}
	}
	
}
int Score()
{
	int score;
	gotoXY(20,8);
	score=length-5;
	printf("SCORE=%d",score);
	gotoXY(50,8);
	printf("life=%d",life);
	return life;
	
}
void Down()
{
	int i;
	for(i=0;i<=(head.y-bend[bend_no].y)&& len<length;i++)
	{
		gotoXY (head.x,head.y-i);
		if(len==0)
		printf("v");
		else
		printf("*");
		body[len].x=head.x;
		body[len].y=head.y-i;
		len++;
		
	}
	Bend();
	if(!kbhit())
	head.y++;
}
void Up()
{
	int i;
	for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
	{
		gotoXY (head.x,head.y+i);
		if(len==0)
		printf("^");
		else
		printf("*");
		body[len].x=head.x;
		body[len].y=head.y+i;
		len++;
	}
	Bend();
	if(!kbhit())
	head.y--;
		
}
void Right()
{
	int i;
	for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
	{
	//	gotoXY (head.x-i,head.y);
	 body[len].x=head.x-i;
        body[len].y=head.y;
        gotoXY(body[len].x,body[len].y);
		if(len==0)
		printf(">");
		else
		printf("*");
		body[len].y=head.y;
		body[len].x=head.x-i;
		len++;
	}
	Bend();
	if(!kbhit())
	head.x++;
}
void Left()
{
	int i;
	for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
	{
		gotoXY ((head.x+i),head.y);
		if(len==0)
		printf("<");
		else
		printf("*");
		body[len].x=head.x+i;
		body[len].y=head.y;
		len++;
	}
	Bend();
	if(!kbhit())
	head.x--;
}
void  move()
{
	int a,i;
 	do{
 		Food();
 		fflush(stdin);
 		len=0;
 		for(i=0;i<30;i++)
 		{
 			body[i].x=0;
 			body[i].y=0;
 			if(i==length)
 			break;
 			
		 }
		 delay (length);
		 border();
		 if(head.direction==RIGHT)
		 Right();
		  else if(head.direction==LEFT)
 
            Left();
 
        else if(head.direction==DOWN)
 
            Down();
 
        else if(head.direction==UP)
 
            Up();
            endgame();
            
		 
	 }while(!kbhit());
	 a=getch();
	 if(a==27)
	 {
	 	system("cls");
	 	exit(0);
	 }
	 key=getch();
	 if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
	{
		bend_no++;
		bend[bend_no]=head;
		head.direction=key;
		if(key==UP)
		head.y--;
		if(key==DOWN)
		head.y++;
		if(key==LEFT)
		head.x--;
		if(key==RIGHT)
		head.x++;
		move();
		
	 } 
	 else if(key==27)
	 {
	 	system("cls");
	 	exit(0);
	 }
	else
	{
		printf("\a");
		move();
		
	}

}
void Bend()
{
	int i,j,diff;
	for(i=bend_no;i>=0&&len<length;i++)
	{
		if(bend[i].x==bend[i-1].x)
		{
			diff=bend[i].y-bend[i-1].y;
			if (diff<0)
			{
				for(j=1;j<=-(diff);j++)
				{
				body[len].x==bend[i].x;
				body[len].y==bend[i].y+j;
				gotoXY (body[len].x,body[len].y);			
				printf("*");
				len++;
				if(len==length)
				break;
				}
			}
			 else if(diff>0)
            {
					     for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        gotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
		}
		 else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
             {
				  for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    gotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
			}
           else if(diff>0)
               {
			   for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   gotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
			   }
       }
   }
}
void delay(long double k)
{
	Score();
	long double i;
	for(i=0;i<=10000000;i++);
	
}
















