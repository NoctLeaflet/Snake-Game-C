#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Sniki, Makanan, dan Map
char map[10][20];
char player = '^';
char tail = '*';
char food = '0';
int yFood, xFood;
int y=5 , x=5;
int yTail[10];
int xTail[10];
int nTail = 2;
int maxTail = 10;
int score;

//Void
void generateMap();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

//Main Program
int main(){
    score = 0;
    int i, n;
    char move;
    //program random food
    time_t t;
    srand((unsigned) time(&t));
    yFood = rand() % 7 + 1;
    xFood = rand() % 17 + 1;
    //Warna
    system("color 3");
    //Program Ekor
    yTail[0] = y+1;
    xTail[0] = x;
    yTail[1] = y+2;
    xTail[1] = x;

    //Program Untuk Gerakan
    do{
        system("cls");
        generateMap();
        displayMap();
        move = getch();

        switch(move){
            case 'w' :
                player = '^';
                moveUp();
                break;
            case 's' :
                player = 'v';
                moveDown();
                break;
            case 'a' :
                player = '<';
                moveLeft();
                break;
            case 'd' :
                player = '>';
                moveRight();
                break;
        }
        //Program Food
        if(y == yFood && x == xFood){
            map[y][x] = player;
            score++;
            if(nTail <= 10){
                nTail++;
            }
            yFood = rand() % 7 + 1;
            xFood = rand() % 17 + 1;
        }
        for(i=9; i>0; i--){
            yTail[i] = yTail[i-1];
            xTail[i] = xTail[i-1];
        }
    }
    while(score <= 10);
    printf ("\n");
    printf("SELAMAT \n");
    printf("Score Anda Adalah : %d", score);
    scanf("%d", i);
    printf("\n");

    return 0;
}

void generateMap(){
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
                if(i == 0 || i == 9){
                    map[i][j] = '-';
                }else if(j == 0 || j == 19){
                    map[i][j] = '|';
                }
                else{
                    map[i][j] = ' ';
                }
        }
    }
    map[y][x] = player;
    map[yFood][xFood] = food;
    for(i=0; i<=nTail; i++){
        map[yTail[i]][xTail[i]] = tail;
    }
}

void displayMap(){
    int i,j;
    for(i=0; i<10; i++){
        for(j=0; j<20; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Score : %d ", score);
}

void moveUp(){
    if(y-1 > 0){
        yTail[0] = y; xTail[0] = x;
        y--;
    }
}
void moveDown(){
    if(y-1 < 7){
        yTail[0] = y; xTail[0] = x;
        y++;
    }
}
void moveLeft(){
    if(x-1 > 0){
        yTail[0] = y; xTail[0] = x;
        x--;
                }
}
void moveRight(){
    if(x-1 < 17){
        yTail[0] = y; xTail[0] = x;
        x++;
    }
}



