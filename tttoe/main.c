#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char viereck[10] = {'o','1','2','3','4','5','6','7','8','9'};
int gewinnBestaetigung();
void drawBoard();

int main()
{
    int player = 1, i, choice;
    char zeichen; //X,O
    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        printf("Spieler %d, auswahl angeben : ",player);
        scanf("%d",&choice);
        zeichen =(player == 1) ? 'X' : 'O';
        if(choice == 1 && viereck[1] == '1')
            viereck[1] = zeichen;
        else if(choice == 2 && viereck[2] == '2')
            viereck[2] = zeichen;
            else if(choice == 3 && viereck[3] == '3')
            viereck[3] = zeichen;
            else if(choice == 4 && viereck[4] == '4')
            viereck[4] = zeichen;
            else if(choice == 5 && viereck[5] == '5')
            viereck[5] = zeichen;
            else if(choice == 6 && viereck[6] == '6')
            viereck[6] = zeichen;
            else if(choice == 7 && viereck[7] == '7')
            viereck[7] = zeichen;
            else if(choice == 8 && viereck[8] == '8')
            viereck[8] = zeichen;
            else if(choice == 9 && viereck[9] == '9')
            viereck[9] = zeichen;

            else {
                printf("Ungültige Auswahl!");
                player--;
                getch();
            }
            i = gewinnBestaetigung();
            player++;

    }while(i == -1);

    drawBoard();
    if(i==1){
        printf("==>Spieler %d hat gewonnen",--player);
    }
    else {
        printf("==>Ausgeglichen");
    }
        getch();
        return 0;
}
int gewinnBestaetigung(){
    if(viereck[1] == viereck[2] && viereck[2] == viereck[3])
        return 1;
    else if(viereck[4] == viereck[5] && viereck[5] == viereck[6])
        return 1;
    else if(viereck[7] == viereck[8] && viereck[8] == viereck[9])
        return 1;
    else if(viereck[1] == viereck[5] && viereck[5] == viereck[9])
        return 1;
    else if(viereck[2] == viereck[5] && viereck[5] == viereck[8])
        return 1;
    else if(viereck[3] == viereck[6] && viereck[6] == viereck[9])
        return 1;
    else if(viereck[3] == viereck[5] && viereck[5] == viereck[7])
        return 1;
    else if(viereck[1] == viereck[4] && viereck[4] == viereck[7])
        return 1;
    else if(viereck[1] != '1' && viereck[2] != '2' && viereck[3] != '3' && viereck[4] != '4' && viereck[5] != '5' && viereck[6] != '6' && viereck[7] != '7' && viereck[8] != '8' && viereck[9] != '9')
        return 0;
    else
        return -1;

}

void drawBoard(){
    system("cls");
    printf("\n\n\t Tic Tac Toe \n\n");
    printf("Spieler1 (X) - Spieler2 (O) \n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",viereck[1],viereck[2],viereck[3]);
    printf("_____|_____|_____\n");
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c  \n",viereck[4],viereck[5],viereck[6]);
    printf("_____|_____|_____\n");
    printf("_____|_____|_____\n");
    printf("  %c  |  %c  |  %c  \n",viereck[7],viereck[8],viereck[9]);
    printf("_____|_____|_____\n");
}
