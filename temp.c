#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#define height 21
#define width 51
	bool gameover;
	int x,y,s core;  //x,y are pacman's co-ortinates
	enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
	enum eDirection dir;
    char grid[height][width]={
        "**************************************************",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "*................................................*",
        "**************************************************"
    };

	void Setup(){
		gameover=false;
		dir=STOP;
		x = width / 2;
		y = height / 2;
		score=0;

	}

	void Draw(){
		int i;
		system("cls");
		for(i=0;i<height;i++){
            printf("%s\n",grid[i]);
		}

	}

	void Input(){
		if(_kbhit()){
			switch(_getch()){                           //if user presses stuff then only getch() activates and hence takes input
				case 'a':
					dir=LEFT;
					break;

				case 'd':
					dir=RIGHT;
					break;

				case 'w':
					dir=UP;
					break;


				case 's':
					dir=DOWN;
					break;

				case 'x':
					gameover=true;
					break;
			}
		}
	}

	void Logic(){

			switch(dir){                            //pacman's co-ordinate changes when corresponding key is pressed
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UP:
					y--;
					break;
				case DOWN:
					y++;
					break;
			}
		if(x>width) x=width-2;
		if(y>height) y=height-1;
		if(x<0) x=1;
		if(y<0)y=0;
	}
	int main(){
		Setup();
		while(!gameover){
			Draw();
			Input();
			Logic();
			Sleep(50);
		}
		if(score==300) printf("Congrats You won");                  //score not implemented.....yet
		else printf("Too bad.... try again");
		return 0;
	}
