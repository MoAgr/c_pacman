#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
	
	int height=20;
	int width=50;
	bool gameover;
	int x,y,score;
	enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
	enum eDirection dir;
	
			
	void Setup(){
		gameover=false;
		dir=STOP;
		x = width / 2;
		y = height / 2;
		score=0;
		
	}

	void Draw(){
		int i,j;
		system("cls");
		for (i=0;i<width;i++)
		{
			if(i==0) printf("%c",201);
			else if(i==width-1) printf("%c",187);
			else printf("%c",205);
		}
	
		printf("\n");
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				if(j==0 || j==width-1) printf("%c",186);
				else if(j==x && i==y) printf("C");
				
				else printf(".");

			}
			printf("\n");
		}

		for (i=0;i<width;i++)
		{
			if(i==0) printf("%c",200);
			else if(i==width-1) printf("%c",188);
			else printf("%c",205);
		}
		
	}
	
	void Input(){
		if(_kbhit()){
			switch(_getch()){
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
		switch(dir){
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
		
	}
	int main(){
		Setup();
		while(!gameover){
			Draw();
			Input();
			Logic();
		}
		return 0;
	}
