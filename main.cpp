#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

char map[8][8]={' ',' ','*','*','*',' ',' ',' ',
                 ' ',' ','*','O','*',' ',' ',' ',
                 ' ',' ','*',' ','*','*','*','*',
                 '*','*','*','#',' ','#','O','*',
                 '*','O',' ','#','U','*','*','*',
                 '*','*','*','*','#','*',' ',' ',
                 ' ',' ',' ','*','O','*',' ',' ',
                 ' ',' ',' ','*','*','*',' ',' '};
int youx=4,youy=4;//��¼�˵�ǰ��λ��

void type();//��ӡ��ǰ״̬

bool judge(int ,int );//�ж��Ƿ��ܽ�����һ��

bool win();//�ж��Ƿ��Ѿ��ɹ�

void game();//��Ϸ����

void move(int ,int );//�ƶ�

int main()
{
    type();
    game();
    while(1);
    return 0;
}

void type(){
    if(map[1][3]==' ')
        map[1][3]='O';
    if(map[3][6]==' ')
        map[3][6]='O';
    if(map[4][1]==' ')
        map[4][1]='O';
    if(map[6][4]==' ')
        map[6][4]='O';
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cout<<map[i][j];
        cout<<endl;
        }
    }

bool judge(int x,int y){
    if(map[youx+x][youy+y]=='*'){
        printf("\aWrong step!\n");
        return 0;
        }
    if(map[youx+x][youy+y]=='#'&&map[youx+2*x][youy+2*y]=='*'){
        printf("\aWrong step!\n");
        return 0;
        }
    return 1;
    }

bool win(){
    if(map[1][3]=='#'&&map[3][6]=='#'&&map[4][1]=='#'&&map[6][4]=='#')
        return 1;
    return 0;
    }

void game(){
    char c;
    cin>>c;
    if(!(c=='W'||c=='w'||c=='A'||c=='a'||c=='S'||c=='s'||c=='D'||c=='d')){
        printf("\aWrong input!\n");
        game();
        }
    if(c=='W'||c=='w'){
        if(!judge(-1,0))
            game();
        else move(-1,0);
        }
    if(c=='A'||c=='a'){
        if(!judge(0,-1))
            game();
        else move(0,-1);
        }
    if(c=='S'||c=='s'){
        if(!judge(1,0))
            game();
        else move(1,0);
        }
    if(c=='D'||c=='d'){
        if(!judge(0,1))
            game();
        else move(0,1);
        }
    system("cls");
    type();
    if (win()){
        cout<<"You are win!"<<endl;
        return ;
        }
    game();
    }

void move(int x,int y){
    if(map[youx+x][youy+y]=='#'){
        map[youx+2*x][youy+2*y]='#';
        }
    map[youx][youy]=' ';
    youx+=x;
    youy+=y;
    map[youx][youy]='U';
    }

