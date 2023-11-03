#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main();
//tic tac toe
char space[3][3];
int gamer = 1; 

void printBoard() 
   {
    int k=0;
    printf("  1 2 3\n");
    printf("\n");
    for(int i=0;i<3;i++)
    {
        printf("%d ",i+1);
        for(int j=0;j<3;j++)
        {
            if(space[i][j]=='X')
            {
               printf("\033[1;34m%c\033[1;0m",space[i][j]);
            }
        else if(space[i][j]=='O')
            {
               printf("\033[1;36m%c\033[1;0m",space[i][j]);
            }
        else{printf("%c",space[i][j]);}
        k=k+1;
        if(k<3){printf("|");}
        if(k==3){k=0;}
        if(j==2 && i<2)
        {printf("\n  -----\n");}
        }
    }
    
}
    

int isBoardFull() {
    for (int r= 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (space[r][c] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int Winner(char player) {
    for (int i = 0; i < 3; i++) {
        if (space[0][i] == player && space[1][i] == player && space[2][i] == player) {
            return 1; 
        } 
        if (space[i][0] == player && space[i][1] == player && space[i][2] == player) {
            return 1; 
        }
    }  
    
    if (space[0][0] == player && space[1][1] == player && space[2][2] == player) {
        return 1; 
    }
    if (space[0][2] == player && space[1][1] == player && space[2][0] == player) {
        return 1; 
    }
    return 0; 
}

int tictactoe()
 {
    for (int i = 0; i < 3; i++)
     {
       for (int j = 0; j < 3; j++)
        {
           space[i][j] = ' ';
        }
     }
 
    int r, c;

    printf("\033[1;35mhello guys Welcome to Tic-Tac-Toe!\n");
    printf("enter (0,0) if you want to quit the game\033[1;0m \n");

    while (1) {
        printBoard();
        printf("\n\n\nPlayer %d, enter your move (row and column): ", gamer);
        scanf("%d %d", &r, &c);
        if(r==0 && c==0){system("cls");
        printf("\033[1;32myou left the game\033[1;0m\n");
        break;}

        if (r < 1 || r > 3 || c < 1 || c > 3 || space[r - 1][c - 1] != ' ') {
            system("cls");
            printf("\033[1;31mInvalid move!\033[1;0m Try again.\n");

            continue;
        }
        if (gamer == 1){
            space[r - 1][c - 1] = 'X';
        } else {
            space[r - 1][c - 1] = 'O';
        }
        if (Winner(gamer == 1 ? 'X' : 'O')) {
            system("cls");
            printBoard();
            printf("\n\n\033[1;35mPlayer %d wins!!\033[1;0m\n", gamer);
            break;
        }
        if (isBoardFull()) {
            system("cls");
            printBoard();
            printf("\n\n\033[1;32mIt's a draw!!\033[1;0m\n");
            break;
        }
        if(gamer==1)
        {
            gamer=2;
        }
        else{gamer=1;} 
        system("cls");
    }

    return 0;
}
//pacman
#define WIDTH 40 
#define HEIGHT 20 
#define PACMAN 'C' 
#define WALL '#' 
#define FOOD '.' 
#define POISON '*'
#define EMPTY ' ' 
#define DEMON 'X' 
#define DEMON_ 'x'
int res=0;
int score=0; 
int pacman_x, pacman_y; 
int demon_x1,demon_y1;
int demon_x2,demon_y2;
char board[HEIGHT][WIDTH]; 
int food=0; 
int curr=0; 
int f=3,p=25;
void initialize() 
{ 
    for (int i=0;i<HEIGHT;i++) 
    { 
        for (int j=0;j<WIDTH;j++)
         { 
            if (i==0 || j==WIDTH-1 || j==0 
                || i==HEIGHT-1) 
            { 
                board[i][j]=WALL; 
            } 
            else
            {
                board[i][j]=EMPTY;
            } 
        } 
    } 
    for (int j=4;j<WIDTH-3;j++)
    {
        board[3][j]=WALL;
        board[7][j]=WALL;
        board[13][j]=WALL;
        board[17][j]=WALL;
    }
    board[1][2]=WALL;
    board[2][16]=WALL;
    board[1][12]=WALL;
    board[2][30]=WALL;
    board[1][37]=WALL;
    board[5][4]=WALL;
    board[5][17]=WALL;
    board[5][28]=WALL;
    board[5][37]=WALL;
    board[9][6]=WALL;
    board[9][19]=WALL;
    board[9][33]=WALL;
    board[11][3]=WALL;
    board[11][15]=WALL;
    board[11][23]=WALL;
    board[11][29]=WALL;
    board[11][37]=WALL;
    board[15][5]=WALL;
    board[15][15]=WALL;
    board[15][25]=WALL;
    board[15][37]=WALL;
    board[2][35]=DEMON_;
    board[4][4]=DEMON_;
    board[6][35]=DEMON_;
    board[9][13]=DEMON_;
    board[9][27]=DEMON_;
    board[9][36]=DEMON_;
    board[11][9]=DEMON_;
    board[11][20]=DEMON_;
    board[11][33]=DEMON_;
    board[15][10]=DEMON_;
    board[15][21]=DEMON_;
    board[15][31]=DEMON_;
    pacman_x=WIDTH / 2; 
    pacman_y=HEIGHT / 2; 
    demon_y1=HEIGHT/4;
    demon_x1=WIDTH/4;
    demon_y2=HEIGHT/9;
    demon_x2=WIDTH/9;
    board[pacman_y][pacman_x]=PACMAN; 
    board[demon_y1][demon_x1]=DEMON;
    board[demon_y2][demon_x2]=DEMON;
    for (int i=0;i<HEIGHT;i++) 
    { 
        for (int j=0;j<WIDTH;j++)
        { 
            if (i%2==0 && j%2==0 
                && board[i][j]!=WALL 
                && board[i][j]!=DEMON 
                && board[i][j]!=PACMAN && board[i][j]!=DEMON_)
            { 
                board[i][j]=FOOD; 
                food=food+1; 
            } 
        } 
    } 
} 
void draw() 
{ 
    system("cls");  
    for (int i=0;i<HEIGHT;i++)
    { 
        for (int j=0;j<WIDTH;j++) 
        { 
            printf("%c",board[i][j]); 
        } 
        printf("\n"); 
    } 
    printf("\033[1;34m\nScore: %d\033[1;0m",score); 
} 
void move(int move_x, int move_y) 
{ 
    int x=pacman_x + move_x; 
    int y=pacman_y + move_y; 
    if (board[y][x]!= WALL) 
    { 
        if (board[y][x]==FOOD) 
        { 
            score=score+1; 
            food=food-1; 
            curr=curr+1; 
            if (score>=140) 
            { 
                res=2; 
                return; 
            } 
        } 
        else if (board[y][x]==DEMON || board[y][x]==DEMON_)
        { 
            f=f-1;
        } 
        else if(board[y][x]==POISON)
        {
            p=p-1;
        }
        board[pacman_y][pacman_x]=EMPTY; 
        pacman_x=x; 
        pacman_y=y; 
        board[pacman_y][pacman_x]=PACMAN; 
    } 
} 
void move_demons1(int move_a,int move_b)
{
  int a=demon_x1 + move_a;
  int b=demon_y1 + move_b;
  if(board[b][a]!=WALL)
  {
  if (board[demon_y1][demon_x1]==PACMAN)
  {
    board[demon_y1][demon_x1]=PACMAN;
  }
  if (board[b][a]==POISON)
  {
    board[b][a]=DEMON;
    board[demon_y1][demon_x1]=POISON;
  }
  else
     board[demon_y1][demon_x1]=EMPTY;
  if(board[b][a]==FOOD)
    {
    board[demon_y1][demon_x1]=POISON;
    }
        demon_x1=a; 
        demon_y1=b;
        if(board[b][a]==PACMAN)
        {
        f=f-1;
        board[b][a]=PACMAN;;
        }
        else
        board[demon_y1][demon_x1]=DEMON;
}
}
void move_demons2(int move_a2,int move_b2)
{
  int a2=demon_x2 + move_a2;
  int b2=demon_y2 + move_b2;
if(board[b2][a2]!=WALL)
  {
    if (board[demon_y2][demon_x2]==PACMAN)
    {
        board[demon_y2][demon_x2]=PACMAN;
    }
    if (board[b2][a2]==POISON)
    {
        board[b2][a2]=DEMON;
        board[demon_y2][demon_x2]=POISON;
    }
    else
        board[demon_y2][demon_x2]= EMPTY;
  
  if(board[b2][a2]==FOOD)
  {
    board[demon_y2][demon_x2] = POISON;
  }
       demon_x2=a2; 
        demon_y2=b2; 
        if(board[b2][a2]==PACMAN)
        {
            f=f-1;
        board[b2][a2] =PACMAN; 
        }
        else
        board[demon_y2][demon_x2] =DEMON;
  }
}
int pacman() 
{ 
    initialize(); 
    char ch; 
    int totalFood=food; 
    int  n;
    printf("\033[1;32m\nINSTRUCTIONS TO PLAY PAC-MAN GAME:\n\033[1;0m");
    printf("\033[1;36m\n1) C IS PACMAN, '.' IS FOOD, '*' IS POISON, '#' IS WALL\n");
    printf("\033[1;36m\n2) X IS MOVABLE DEMON, x IS STATIONARY DEMON, YOU HAVE 3 LIVES AND 25 POISON LIVES\n");
    printf("\033[1;36m\n3) USE ARROW KEYS TO MOVE PAC-MAN\n");
    printf("\033[1;36m\n4) USE w(UP),a(LEFT),s(DOWN),d(RIGHT) KEYS TO MOVE 1ST DEMON X\n");
    printf("\033[1;36m\n5) USE i(UP),j(LEFT),k(DOWN),l(RIGHT) KEYS TO MOVE 2ND DEMON X\n");
    printf("\033[1;36m\n6) BOTH THE DEMONS REPLACE FOOD BY POISON ALONG THEIR PATH\n");
    printf("\033[1;36m\n7) IF YOUR SCORE IS MORE THAN 140 YOU WIN!\n");
    printf("\033[1;36m\n8) PLEASE ENTER ONLY ONE COMMAND AT A TIME\n");
    printf("\033[1;36m\n9) BE AWARE THE DEMON X IS IMMORTAL!!!\n");
    printf("\033[1;36m\nENTER Y TO CONTINUE OR q TO QUIT GAME:\033[1;0m"); 
    ch = getch(); 
    if (ch!='Y') 
    { 
        printf("\033[1;31mEXIT GAME!\033[1;0m"); 
        return 1; 
    } 
    while (1)
    { 
        draw(); 
        printf("\033[1;34m\nTOTAL FOOD COUNT: %d\033[1;0m",totalFood); 
        printf("\033[1;34m\nTOTAL FOOD EATEN: %d\033[1;0m",curr); 
        printf("\033[1;34m\nTOTAL LIVES REMAINING: %d\033[1;0m",f);
        printf("\033[1;34m\nTOTAL POISON LIVES REMAINING: %d\033[1;0m",p);
        if (f==0 || p==0) 
        { 
            system("cls"); 
            printf("\033[1;31m\nGAME OVER! DEAD BY DEMON \nYOUR SCORE: %d\033[1;0m\n",score); 
            return 1; 
        } 
        if (res==2) 
        { 
            system("cls"); 
            printf("\033[1;32m\nYOU WIN!\nYOUR SCORE: %d\033[1;0m",score); 
            return 1; 
        }  
       ch=getch();  
        switch (ch) 
        { 
        case 72: 
            move(0, -1); 
            break; 
        case 80: 
            move(0, 1); 
            break; 
        case 75: 
            move(-1, 0); 
            break; 
        case 77: 
            move(1, 0); 
            break;
        case 'i': 
            move_demons1(0, -1); 
            break; 
        case 'k': 
            move_demons1(0, 1); 
            break; 
        case 'j': 
            move_demons1(-1, 0); 
            break; 
        case 'l': 
            move_demons1(1, 0); 
            break; 
        case 'w': 
            move_demons2(0, -1); 
            break; 
         case 's': 
            move_demons2(0, 1); 
            break; 
        case 'a': 
            move_demons2(-1, 0); 
            break; 
        case 'd': 
            move_demons2(1, 0); 
            break; 
        case 'q': 
            printf("\033[1;31m\nYOU LEFT THE GAME!\nYOUR SCORE: %d\033[1;0m",score); 
            return 0; 
        break;
        }
    }
} 

  
//snake and ladders
int rd()
{
	int rem;
	A:rem=rand()%7;
	if(rem==0)
		goto A;
	else
		return rem;
}
void displaychart(int curp,char player[4])
{	int i,j,t,c,sft=0,diceres,pos1,pos2;


		if(curp==100)
		{
			printf("Congratulations!!!!!! \n\nPlayer %s wins\n",player);
			scanf("%*s");
			exit(0);
		}

	for(i=10;i>0;i--)
	{
		t=i-1;
		if((sft%2)==0)
		{
			c=0;
			for(j=10;j>=1;j--)
			{
				diceres=(i*j)+(t*c++);

				if(curp==diceres)
					printf("%s\t",player);
				else
				printf("%d\t",diceres);

			}
			sft++;
		}
		else
		{
			c=9;
			for(j=1;j<=10;j++)
			{
				diceres=(i*j)+(t*c--);

				if(curp==diceres)
					printf("%s\t",player);
				else
					printf("%d\t",diceres);
			}


			sft++;
		}
		printf("\n\n");
	}



	printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
}
void snakesandladders()
{
	int i,dice,cur_pos1=0,cur_pos2=0;
	int ch;
	while(1)
	{
		printf("Snakes: | 25 to 9  | 65 to 40 | 99 to 1  |\nLadder: | 13 to 42 | 60 to 83 | 70 to 93 |\n\n");
		printf("Choose your option\n");
		printf("[1] Player 1 plays\n");
		printf("[2] Player 2 plays\n");
		printf("[3] Exit\n");
    fflush(stdin);
		scanf("%d",&ch);

		switch(ch)
		{

			case 1:dice=rd();
                    system("cls");
                    printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
                    printf("\t\t\t    Snakes And Ladders\n");
                    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					cur_pos1=dice+cur_pos1;
					if(cur_pos1<101){
						if(cur_pos1==99)
						{
						displaychart(1,"-P1-");//snake
						}
						if(cur_pos1==65)
						{
						displaychart(40,"-P1-");//snake
						}
						if(cur_pos1==25)
						{
						displaychart(9,"-P1-");//snake
						}
						if(cur_pos1==70)
						{
						displaychart(93,"-P1-");//ladder
						}
						if(cur_pos1==60)
						{
						displaychart(83,"-P1-");//ladder
						}
						if(cur_pos1==13)
						{
						displaychart(42,"-P1-");//ladder
						}
						else{
							displaychart(cur_pos1,"-P1-");
						}
                        printf("\t\t\t\tDice = %d\n",dice);
                        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					}
					else{
						cur_pos1=cur_pos1-dice;
						printf("Range exceeded of Player 1.\n");
						displaychart(cur_pos1,"-P1-");
					}
					printf("Player 2 position is %d\n\n",cur_pos2);

				break;
			case 2:dice=rd();
                    system("cls");
                    printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
                    printf("\t\t\t    Snakes And Ladders\n");
                    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					cur_pos2=dice+cur_pos2;
					if(cur_pos2<101){
						if(cur_pos2==99)	//snake
						{
						displaychart(1,"$-P2-");
						}
						if(cur_pos2==65)	//snake
						{
						displaychart(40,"-P2-");
						}
						if(cur_pos2==25)	//snake
						{
						displaychart(9,"-P2-");
						}
						if(cur_pos2==70)	//ladder
						{
						displaychart(93,"-P2-");
						}
						if(cur_pos2==60)	//ladder
						{
						displaychart(83,"-P2-");
						}
						if(cur_pos2==13) 	//ladder
						{
						displaychart(42,"-P2-");
						}
						else{
							displaychart(cur_pos2,"-P2-");
						}
						printf("\t\t\t\tDice = %d\n",dice);
						printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
					}

					else{
						cur_pos2=cur_pos2-dice;
						printf("Range exceeded of Player 2.\n");
						displaychart(cur_pos2,"-P2-");
					}
					printf("Player 1 position is %d\n\n",cur_pos1);
				break;
			case 3:
      {
        fflush(stdin);
        system("cls");
        main();
      }

			default:printf("Incorrect choice.Try Again\n");

		}

	}

}

//hangman
int hangman() {
    char word[20];
    char unknown[20];
    int length, i;
    char letter;
    int v=0;
    int f;
    printf("\033[1;32m\nINSTRUCTIONS TO PLAY GAME\n\033[1;0m");
    printf("\033[1;36m\n1) IT IS A TWO PLAYER GAME PLAYER 1 WILL ENTER THE WORD THAT SHOULD BE GUESSED BY PLAYER 2\n\033[1;0m");
    printf("\033[1;36m\nPLAYER 1 PLEASE ENTER THE WORD FOR PLAYER 2 TO GUESS:\033[1;0m");
    scanf("%s", word);

    length = strlen(word);
    system("cls");

    printf("\033[1;33m\nWELCOME TO HANGMAN GAME PLAYER 2!!! TRY TO GUESS THE WORD!\n\033[1;0m");
    printf("\033[1;32m\nINSTRUCTIONS TO PLAY GAME\n\033[1;0m");
    printf("\033[1;36m\n1) YOU HAVE TO  GUESS THE WORD WITHIN 8 WRONG ATTEMPTS\033[1;0m");

    for (i = 0; i < length; i++) {
        unknown[i] = '_';
    }
    unknown[i] = '\0';

    while (v<7)
     {
        printf("\n\n%s\n", unknown);
        printf("\033[1;34mGUESS A LETTER:\033[1;0m");
        scanf(" %c", &letter);
        system("cls");
        f=0;

        for (i = 0; i < length; i++) {
            if (word[i] == letter) {
                unknown[i] = letter;
                f++;
            }

        }
        if(f==0)
        {
            v++;
        }
        printf("\033[1;31mThe number of wrong attempts : %d\033[1;0m",v);

        if (strcmp(word, unknown) == 0) {
            system("cls");
            printf("\033[1;32m\nCONGRATULATIONS!! YOU GUESSED THE WORD: %s\n\033[1;0m", word);
            break;
        }

        
    }

    if (v>=7) {
      system("cls");
        printf("\033[1;33m\nSORRY, YOU HAVE USED ALL THE TRIES. THE WORD WAS: %s\n\033[1;0m", word);
    }

    return 0;
}

//quiz
#define MAX_QUESTIONS 5

typedef struct
{
  char question[256];
  char options[4][64];
  int correct_option;
} Question;


void displayQuestion(Question q)
{
  printf("%s\n", q.question);
  for (int i = 0; i < 4; i++)
  {
    printf("%d. %s\n", i + 1, q.options[i]);
  }
}


int checkAnswer(Question q,int user_answer)
{
  return (user_answer == q.correct_option);
}

// Lifeline(Only 2 chances)
void eliminateOptions(Question *q)
{
  int eliminated = 0;
  for (int i = 0; i < 4; i++)
  {
    if (q->correct_option != (i + 1) && eliminated < 2)
    {
      strcpy(q->options[i], "Eliminated");
      eliminated++;
    }
  }
}


int quiz()
{
  // random Question generator
  srand(time(NULL));
  Question original_questions[MAX_QUESTIONS] = {
      {"Who is the CEO of Adobe?",
       {"Sundar Pichai", "Shantanu Narayana", "Satya Nadella", "Parag Agrawal"},
       2},
      {"What's the time shown in Iphone Ads?",
       {"10 am","9:41 am","12 noon","7:00 pm"},
       2},
      {"Where does the President of the United States "
       "live while in office?",
       {"The White House", "The Parliament",
        "House of Commons", "Washington DC"},
       1},
      {"Which state is famous for Hollywood?",
       {"Sydney", "California", "New York", "Paris"},
       2},
      {"Which batsman has scored the fastest 100 in ODIs",
       {"Glenn Maxwell", "AB Devilliers", "Corey Anderson", "Shahid Afridi"},
       2}};

  Question questions[MAX_QUESTIONS];
  memcpy(questions, original_questions, sizeof(original_questions));

  int num_questions = MAX_QUESTIONS;
  int f=0;

  int score = 0;

  printf("Hola! Here's your Quiz Game!\n");
  printf("Answer the questions and win points\n");
  printf("There are 2 lifelines in which the player can eliminate 2 options from the question\n");
  for (int i = 0; i < MAX_QUESTIONS; i++)
  {
    int random_index = rand() % num_questions;
    Question current_question = questions[random_index];
    p:
    displayQuestion(current_question);

    int user_answer;
    t:
    printf("Enter your answer (1-4), 5 to quit, 6 to eliminate: ");    
      scanf("%d", &user_answer);
      if (user_answer==5)
      {
        break;
      }
      else if(user_answer==6 && f<2)
      {
        eliminateOptions(&current_question);
        f++;
        displayQuestion(current_question);
        //i--;
        goto t;
      }
      else if(f>=2 && user_answer==6)
      {
        printf("Elimination can be done only twice\n");
        //i--;
        goto p;
      }

      else if (user_answer>=1 && user_answer<=4)
      {
        
        if (checkAnswer(current_question, user_answer)==1)
        {
          printf("Correct!\n");
          score++;
        }
        else
        {
          printf("Incorrect. The correct answer is "
                 "%d. %s\n",
                 current_question.correct_option,
                 current_question.options[current_question.correct_option - 1]);
        }
      
     
    }

    questions[random_index] = questions[num_questions - 1];
    num_questions--;
  }
printf("Well Done Champ !!!! Quiz completed! Your "
         "score: %d/%d\n",score, MAX_QUESTIONS);

  return 0;
}

int main()
{
    
    int k;
    printf("\n\033[1;33mHello gamer!!\033[1;0m\n");
    printf("\n\n\033[1;33mIf you want to play\033[1;0m\n\nfor TIC TAC TOE\033[1;36m press (1)\033[1;0m\n\nfor PACMAN \033[1;32mpress (2)\033[1;0m\n\nfor SNAKES AND LADDERS \033[1;36mpress (3)\033[1;0m\n\nfor HANGMAN \033[1;34mpress (4)\033[1;0m\n\nfor QUIZ \033[1;35mpress (5)\033[1;0m\n\n");
    printf("Enter the number : ");
    scanf("%d",&k);
    switch(k)
    {
        case 1:
        system("cls");
        tictactoe();
        printf("\033[1;32mThanks for playing !!\033[1;0m");
        break;

        case 2:
        system("cls");
        pacman();
        printf("\033[1;32mthanks for playing !!\033[1;0m");
        break;

        case 3:
        system("cls");
        snakesandladders();
        printf("\033[1;32mthanks for playing !!\033[1;0m");
        break;

        case 4:
        system("cls");
        hangman();
        printf("\033[1;32mthanks for playing !!\033[1;0m");
        break;

        case 5:
        system("cls");
        quiz();
        printf("thanks for playing hope you had a great time !!");
        break;

        default:
        {system("cls");
        printf("\033[1;31msorry !! you have entered the wrong input.Please try again :) \033[1;31m");}
    }
    char l;
    printf("\n\n\033[1;32menter T to go back to the menu and Q to quit the game :\033[1;0m");
    fflush(stdin);
    scanf("%c",&l);
    if(l=='T')
    {system("cls");
    main();}
    else if(l=='Q')
    {
      printf("\n\033[1;32mhope you enjoyed the play!\nthank you!!\033[1;0m");
    }
    else printf("\nsorry wrong input");
  
}
