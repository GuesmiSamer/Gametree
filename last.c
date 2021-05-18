#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <ctype.h>
#include <windows.h>

//ludo
#define max 6
#define min 0
//battleships
#define CORVETTE_ID 1
#define CORVETTE_WIDTH 1
#define CORVETTE_NB 1

#define DESTROYER_ID 2
#define DESTROYER_WIDTH 3
#define DESTROYER_NB 1

#define CROISEUR_ID 3
#define CROISEUR_WIDTH 4
#define CROISEUR_NB 0

#define PORTE_AVION_ID 4
#define PORTE_AVION_WIDTH 6
#define PORTE_AVION_NB 0

#define lignesmax 200
#define colonnesmax 200
//sudoko
/* dimension des cotes des petits carreaus */
#define MINN 3
/* dimension de cote du grand carreau */
#define MAXX 9
/* code de sortie des fonctions */
#define FAUX 0
#define VRAI 1



/**********/
char grille[MAXX][MAXX]; /* la grille */
long int g_comp_tests; /* compteur de tests */
int g_flag_affiche; /* Drapeau d'option d'affichage de l'option -a */
/********/
int SUDOKOmain(int argc, char *argv[]);
int parametre_affichage(char t[]);
/**** SAISIES ET VERIFICATIONS ****/
int saisie_grille(void);
int saisie_une_ligne(int ligne);
int verif_saisie_grille(void);
int verif_saisie_lignes(void);
int verif_saisie_une_ligne(int ligne);
int verif_saisie_colonnes(void);
int verif_saisie_une_colonne(int col);
int verif_saisie_carres(void);
int verif_saisie_un_carre(int carre);
void trans_carre(char tamp[], int carre);
/**** RESOLUTION ****/
void resolve(void);
int case_dispo_nbre(int nbre, int ligne, int col);
void trans_carre_de_case(char tamp[], int ligne, int col);
/**** DIVERS ****/
void affiche_grille_attente(void);
void affiche_grille(void);
void affiche_chaine(int nbre);
int grille_finie(void);
void attente(void);
/*****************************************
*******************************************/

int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,comp;

void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch,int pos);
COORD coord= {0,0}; // this is global variable


int i, val, sum1=0, sum2=0, sum3=0, sum4=0, total, turn;
char player1[30], player2[30], player3[30], player4[30];
time_t t;


int main(int argc, char *argv[]) {


    int rows, starNumber, spaceNumber;
      int choice;
    int rowCount, spaceCount, starCount, treeTrunkCount, treeTrunkSpaceCount;

rows=10;
    for(rowCount = 1; rowCount <= rows; rowCount++) {
        starNumber = rowCount * 2 - 1;
        spaceNumber = rowCount + rows - starNumber;
         printf("\t\t\t ");

        for(spaceCount = 0; spaceCount < spaceNumber; spaceCount++)
             printf(" ");

        for(starCount = 0; starCount < starNumber; starCount++)
            printf("%c",'*');

        printf("\n");
    }

    for(treeTrunkCount = 0; treeTrunkCount < 5; treeTrunkCount++) {
         printf("\t\t\t ");
        for(treeTrunkSpaceCount = 0; treeTrunkSpaceCount < (rows * 2 + 1)/2; treeTrunkSpaceCount++)

            printf(" ");

        printf("%c\n",'|');
    }
 printf("\t\t         Welcome to GAME TREE\n\t\t          ________________________\n");



    while(1)
    {
        puts("\t1. LUDO\n\t2. SUDOKO\n\t3. BATTLESHIPS\n\t4. TIC TAC TOE\n\t0. Exit\nSelect Your Option");
        scanf("%d", &choice);

        if(choice==1)
        {
            ludomain();
        }
        else if(choice==2)
        {
           SUDOKOmain(0,0);
        }
        else if(choice==3)
        {
          bsmain();
        }
        else if(choice==4)
        {
            tttmain();
        }

        else if(choice==0)
        {
            char ch[10];
            printf("Do you want to exit now (y/n)?\n");
            scanf("%s", ch);

            if(strcmp(ch, "n")==0)
            {
                continue;
            }
            else if(strcmp(ch, "y")==0)
            {
                break;
            }
        }
        else
        {
            printf("Invalid option selected! Try again..\n\n");
        }
    }

    return 0;
}

                                         /********************/
                                         /**** LUDO ****/
                                         /********************/




void single_player()
{
    int count=0;

    while(1)
    {
        printf("Enter Player name: ");
        scanf("%s", player1);

        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            if(sum1>=total && sum1>sum2)
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);
                printf("COMPUTER's score = %d. So, COMPUTER gain last position\n\n\n", sum2);

                sum1=0, sum2=0;
                break;
            }
            else if(sum1 == sum2)
            {
                printf("COMPUTER's score = %d & %s's score = %d. So, the game is tie\n", sum2, player1, sum1);
                sum1=0, sum2=0;
                break;
            }
            else
            {
                printf("COMPUTER's score = %d. So, COMPUTER gain first position\n", sum2);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                sum1=0, sum2=0;
                break;
            }
        }

        if(count%2==0)
        {
            printf("\n%s's turn now\n", player1);
            printf("Press 5 to show your score or\nPress 1 for your turn\n");
            scanf("%d", &turn);

            if(turn ==1)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\n\tYour point: %d\n", val);

                count++;

                if(val == 0)
                {
                    sum1--;
                }

                if(val == 6)
                {
                    sum1 = sum1 + val;
                    count--;

                    if(sum1<total)
                    {
                        printf("\tYou got a bonus turn!\n");
                    }
                }
                else
                {
                    sum1 = sum1 + val;
                }
            }

            else if(turn == 5)
            {
                printf("\n\t%s's scoreboard: %d\n", player1, sum1);
            }

            else
            {
                continue;
            }
        }

        else if(count%2!=0)
        {
            printf("\nCOMPUTER's turn now");
            count++;

            srand((unsigned) time(&t));
            val = (rand() % (max - min)) + min;
            printf("\n\tCOMPUTER's point: %d\n", val);

            if(val == 0)
            {
                sum2--;
            }
            else if(val == 6)
            {
                sum2 = sum2 + val;
                count++;

                if(sum2<total)
                {
                    printf("\tCOMPUTER got a bonus turn!\n");
                }
            }
            else
            {
                sum2 = sum2 + val;
            }
        }
    }
}

void double_palyer()
{
    int count=0;

    while(1)
    {
        printf("Enter Player1 name: ");
        scanf("%s", player1);

        printf("Enter Player2 name: ");
        scanf("%s", player2);

        if(strcmp(player1, player2)==0)
        {
            printf("\nEvery players should be a different name.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            if(sum1>=total && sum1>sum2)
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);

                sum1=0, sum2=0;
                break;
            }
            else if (sum1 == sum2)
            {
                printf("%s's score = %d & %s's score = %d. So, the game is tied!\n", player1, sum1, player2, sum2);

                sum1=0, sum2=0;
                break;
            }
            else
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                sum1=0, sum2=0;
                break;
            }
        }

        if(count%2==0)
        {
            printf("\n%s's turn now\n", player1);
            printf("Press 5 to show your score or\nPress 1 for your turn\n");
            scanf("%d", &turn);

            if(turn ==1)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\n\tYour point: %d\n", val);

                count++;

                if(val == 0)
                {
                    sum1--;
                }
                if(val == 6)
                {
                    sum1 = sum1 + val;
                    count--;

                    if(sum1<total)
                    {
                        printf("\tYou got a bonus turn!\n");
                    }
                }
                else
                {
                    sum1 = sum1 + val;
                }
            }
            else if(turn == 5)
            {
                printf("\n\t%s's scoreboard: %d\n", player1, sum1);
            }
        }
        else
        {
            printf("\n%s's turn now\n", player2);
            printf("Press 5 to show your score or\nPress 2 for your turn\n");
            scanf("%d", &turn);

            if(turn ==2)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\n\tYour point: %d\n", val);

                count++;

                if(val == 0)
                {
                    sum2--;
                }
                if(val == 6)
                {
                    sum2 = sum2 + val;
                    count--;

                    if(sum2<total)
                    {
                        printf("\tYou got a bonus turn!\n");
                    }
                }
                else
                {
                    sum2 = sum2 + val;
                }
            }
            else if(turn == 5)
            {
                printf("\n\t%s's scoreboard: %d\n", player2, sum2);
            }
        }
    }
}

void three_palyer()
{
    int count=0;

    while(1)
    {
        printf("Enter Player1 name: ");
        scanf("%s", player1);

        printf("Enter Player2 name: ");
        scanf("%s", player2);

        printf("Enter Player3 name: ");
        scanf("%s", player3);

        if((strcmp(player1, player2)==0) || (strcmp(player2, player3)==0) || (strcmp(player3, player1)==0))
        {
            printf("\nEvery players should be a different name.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total || sum3>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            if(sum1>=total && (sum1>sum2 && sum1>sum3))
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);

                if(sum2>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else if(sum2 == sum3)
                {
                    printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);

                    sum1=0, sum2=0, sum3=0;
                }
                break;
            }

            else if(sum2 >= total && (sum2>sum1 && sum2>sum3))
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);

                if(sum1>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else if(sum1 == sum3)
                {
                    printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player3, sum3, player1, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                    sum1=0, sum2=0, sum3=0;
                }

                break;
            }

            else if(sum3 >= total && (sum3>sum1 && sum3>sum2))
            {
                printf("%s's score = %d. So, %s gain first position\n", player3, sum3, player3);

                if(sum1>sum2)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);

                    sum1=0, sum2=0, sum3=0;
                }
                else if(sum1 == sum2)
                {
                    printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player2, sum2, player1, player2);

                    sum1=0, sum2=0, sum3=0;
                }
                else
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                    sum1=0, sum2=0, sum3=0;
                }
                break;
            }

            else if((sum1==sum2) && (sum1==sum3) && (sum2==sum3))
            {
                printf("%s's score = %d & %s's score = %d & %s's score = %d. So, The game is tied\n\n\n", player1, sum1, player2, sum2, player3, sum3);
                sum1=0, sum2=0, sum3=0;
                break;
            }
        }

        while(1)
        {
            if(count%2==0)
            {
                printf("\n%s's turn now\n", player1);
                printf("Press 5 to show your score or\nPress 1 for your turn\n");
                scanf("%d", &turn);

                if(turn ==1)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    count++;

                    if(val == 0)
                    {
                        sum1--;
                    }
                    if(val == 6)
                    {
                        sum1 = sum1 + val;
                        count--;

                        if(sum1<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum1 = sum1 + val;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player1, sum1);
                }
            }
            else if(count%2!=0)
            {
                printf("\n%s's turn now\n", player2);
                printf("Press 5 to show your score or\nPress 2 for your turn\n");
                scanf("%d", &turn);

                if(turn ==2)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum2--;
                    }
                    if(val == 6)
                    {
                        sum2 = sum2 + val;

                        if(sum2<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum2 = sum2 + val;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player2, sum2);
                }
            }
        }

        while(1)
        {
            if(count%2!=0)
            {
                printf("\n%s's turn now\n", player3);
                printf("Press 5 to show your score or\nPress 3 for your turn\n");
                scanf("%d", &turn);

                if(turn == 3)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum3--;
                    }
                    if(val == 6)
                    {
                        sum3 = sum3 + val;

                        if(sum3<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum3 = sum3 + val;
                        count++;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player3, sum3);
                }
            }
        }
    }
}

void four_player()
{
    int count=0;

    while(1)
    {
        printf("Enter Player1 name: ");
        scanf("%s", player1);

        printf("Enter Player2 name: ");
        scanf("%s", player2);

        printf("Enter Player3 name: ");
        scanf("%s", player3);

        printf("Enter Player4 name: ");
        scanf("%s", player4);

        if((strcmp(player1, player2)==0) || (strcmp(player1, player3)==0) || (strcmp(player1, player4)==0) || (strcmp(player2, player3)==0)|| (strcmp(player2, player4)==0)|| (strcmp(player3, player4)==0))
        {
            printf("\nEvery players should be a different name.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total || sum3>=total || sum4>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            //for sum1 greater
            if(sum1 >= total && (sum1>sum2 && sum1>sum3 && sum1>sum4))
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);

                if(sum2>sum3 && sum2>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);

                    if(sum3>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum3>sum2 && sum3>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);

                    if(sum2>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum4>sum2 && sum4>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);

                    if(sum3>sum2)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }

                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2==sum3 && sum2==sum4 && sum3==sum4)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player2, sum2, player3, sum3, player4, sum4, player2, player3, player4);
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2==sum3 || sum2==sum4 || sum3==sum4)
                {
                    if(sum2==sum3)
                    {
                        if(sum4>sum2 && sum4>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player3, sum3, player2, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                        }
                    }
                    else if(sum3==sum4)
                    {
                        if(sum2>sum3 && sum2>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player3, sum3, player4, sum4, player3, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player3, sum3, player4, sum4, player3, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum2==sum4)
                    {
                        if(sum3>sum2 && sum3>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player4, sum4, player2, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player4, sum4, player2, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            //2nd
            else if(sum2 >= total && (sum2>sum1 && sum2>sum3 && sum2>sum4))
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);

                if(sum1>sum3 && sum1>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);

                    if(sum3>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum3>sum1 && sum3>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);

                    if(sum1>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum4>sum1 && sum4>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);

                    if(sum3>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }

                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum3 && sum1==sum4 && sum3==sum4)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player1, sum1, player3, sum3, player4, sum4, player1, player3, player4);
                }

                else if(sum1==sum3 || sum1==sum4 || sum3==sum4)
                {
                    if(sum1==sum3)
                    {
                        if(sum4>sum1 && sum4>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player3, sum3, player1, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                        }
                    }
                    else if(sum3==sum4)
                    {
                        if(sum2>sum3 && sum2>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player3, sum3, player4, sum4, player3, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player3, sum3, player4, sum4, player3, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum1==sum4)
                    {
                        if(sum3>sum1 && sum3>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player4, sum4, player1, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player4, sum4, player1, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            //3rd
            else if(sum3 >= total && (sum3>sum1 && sum3>sum2 && sum3>sum4))
            {
                printf("%s's score = %d. So, %s gain first position\n", player3, sum3, player3);

                if(sum1>sum2 && sum1>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);

                    if(sum2>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2>sum1 && sum2>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);

                    if(sum1>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum4>sum1 && sum4>sum2)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);

                    if(sum2>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 && sum1==sum4 && sum2==sum4)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player4, sum4, player1, player2, player4);
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 || sum1==sum4 || sum2==sum4)
                {
                    if(sum1==sum2)
                    {
                        if(sum4>sum1 && sum4>sum2)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player1, player2);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player2, sum2, player1, player2);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                        }
                    }
                    else if(sum1==sum4)
                    {
                        if(sum2>sum1 && sum2>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player4, sum4, player1, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player4, sum4, player1, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum2==sum4)
                    {
                        if(sum1>sum2 && sum1>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player4, sum4, player2, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player4, sum4, player2, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            //4th
            else if(sum4 >= total && (sum4>sum1 && sum4>sum2 && sum4>sum3))
            {
                printf("%s's score = %d. So, %s gain first position\n", player4, sum4, player4);

                if(sum1>sum3 && sum1>sum2)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);

                    if(sum2>sum3)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2>sum1 && sum2>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);

                    if(sum3>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum3>sum2 && sum3>sum1)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);

                    if(sum2>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 && sum1==sum3 && sum2==sum3)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player3, sum3, player1, player2, player3);
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 || sum1==sum3 || sum2==sum3)
                {
                    if(sum1==sum2)
                    {
                        if(sum3>sum1 && sum3>sum2)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player1, player2);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player2, sum2, player1, player2);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                        }
                    }
                    else if(sum1==sum3)
                    {
                        if(sum2>sum1 && sum2>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player3, sum3, player1, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player3, sum3, player1, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum2==sum3)
                    {
                        if(sum1>sum2 && sum1>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player3, sum3, player2, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            else if(sum1==sum2 && sum1==sum3 && sum1==sum4 && sum2==sum3 && sum3==sum4 && sum2==sum4)
            {
                printf("%s's score = %d & %s's score = %d & %s's score = %d & %s's score = %d. So, The game is tied\n\n\n", player1, sum1, player2, sum2, player3, sum3, player4, sum4);

                sum1=0, sum2=0, sum3=0, sum4=0;
                break;
            }
        }

        while(1)
        {
            if(count%2==0)
            {
                printf("\n%s's turn now\n", player1);
                printf("Press 5 to show your score or\nPress 1 for your turn\n");
                scanf("%d", &turn);

                if(turn ==1)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    count++;

                    if(val == 0)
                    {
                        sum1--;
                    }
                    if(val == 6)
                    {
                        sum1 = sum1 + val;

                        if(sum1<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                        count--;
                    }
                    else
                    {
                        sum1 = sum1 + val;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player1, sum1);
                }
            }
            else if(count%2!=0)
            {
                printf("\n%s's turn now\n", player2);
                printf("Press 5 to show your score or\nPress 2 for your turn\n");
                scanf("%d", &turn);

                if(turn ==2)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum2--;
                    }
                    if(val == 6)
                    {
                        sum2 = sum2 + val;

                        if(sum2<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum2 = sum2 + val;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player2, sum2);
                }
            }
        }

        while(1)
        {
            if(count%2!=0)
            {
                printf("\n%s's turn now\n", player3);
                printf("Press 5 to show your score or\nPress 3 for your turn\n");
                scanf("%d", &turn);

                if(turn == 3)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    count++;

                    if(val == 0)
                    {
                        sum3--;
                    }
                    if(val == 6)
                    {
                        sum3 = sum3 + val;

                        if(sum3<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                        count--;
                    }
                    else
                    {
                        sum3 = sum3 + val;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player3, sum3);
                }
            }
            else if(count%2==0)
            {
                printf("\n%s's turn now\n", player4);
                printf("Press 5 to show your score or\nPress 4 for your turn\n");
                scanf("%d", &turn);

                if(turn == 4)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum4--;
                    }
                    if(val == 6)
                    {
                        sum4 = sum4 + val;

                        if(sum4<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum4 = sum4 + val;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player4, sum4);
                }
            }
        }
    }
}

void game_rules()
{
    printf("\t\t\t\t Rules of LUDU game\n\t\t\t\t--------------------\n#Rule :If a player point becomes 1/2/3/4/5 so, this point will be added to that particular player's scoreboard.\n#Rule : If your point becomes 6 then this 6 point be added to your scoreboard and also will get a bonus chance/turn.\n#Rule : If your point becomes 0 then your score decrease by one(that means -1) from your total score.\n#Rule : If any particular player score is greater than total number of score (that players were set at the begining) and all the players turn is finished then the game will automatic exit and automatic show the score and result of this game.\n#Rule: If two or more players score is equal then this two or more players result is tied when the game will be exit\n\n\n");
}

int ludomain()
{
    int choice;
        system("cls");

    puts("\t\t\tWelcome to LUDU game\n\t\t\t____________________\n");

    while(1)
    {
        puts("\t1. Single Player\n\t2. Double Player\n\t3. Three Player\n\t4. Four Player\n\t5. Game rules\n\t0. Exit\nSelect Your Option");
        scanf("%d", &choice);

        if(choice==1)
        {
            single_player();
        }
        else if(choice==2)
        {
            double_palyer();
        }
        else if(choice==3)
        {
            three_palyer();
        }
        else if(choice==4)
        {
            four_player();
        }
        else if(choice==5)
        {
            game_rules();
        }
        else if(choice==0)
        {
            char ch[10];
            printf("Do you want to exit now (y/n)?\n");
            scanf("%s", ch);

            if(strcmp(ch, "n")==0)
            {
                continue;
            }
            else if(strcmp(ch, "y")==0)
            {
                break;
            }
        }
        else
        {
            printf("Invalid option selected! Try again..\n\n");
        }
    }

    return 0;
}
                                         /********************/
                                         /**** BATTLESHIPS ****/
                                         /********************/




int doRand(int startVal, int endVal){
    /*srand(time(0));
    return (rand() % (endVal - startVal) + startVal);*/
    int n = rand() % (endVal - startVal) + startVal;
    return (n);
}

int mathInputInt(){
    int userChoise = 1;
    char userNumber[20];

    while(userChoise){
        scanf ("%s", userNumber);

            userChoise = atoi(userNumber);
            if(userChoise != 0){
                return userChoise;
            }else if(*userNumber=='0'){
                return 0;
            }else{
                userChoise = 1;
                printf ("Please use just numbers  ");
            }
    }
    return 0;
}

int testPlayerAlive(int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10], int playerNumber)
{
    int i, j;
    int flag = 1;
    for(i=0;i<linesNumber;i++){
        for(j=0;j<columnsNumber;j++){
            if(map[i][j][playerNumber] == CORVETTE_ID || map[i][j][playerNumber] == CROISEUR_ID
               || map[i][j][playerNumber] == DESTROYER_ID || map[i][j][playerNumber] == PORTE_AVION_ID){
                flag = 0;
               }
        }
    }
    if(flag == 0){
        return 1; //player alive
    }else{
        return 0; //player dead
    }
}

int numberPlayerLeft(int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10])
{
    int i;
    int nb = 0;
    for(i=1;i<=totalPlayers;i++){
        if(testPlayerAlive(linesNumber,columnsNumber,totalPlayers,map,i) == 1){
            nb = nb +1;
        }
    }
    return nb;
}

void printMap(int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10], int playerNumber)
{
    //printf("Legend of the map : 1/2/3/4 : ship of given type -- 0 : nothing -- X : where you already shot -- H : another player's ship you hit -- S : one of your sunken ships\n");
    int i = 0, j = 0;
    for(i=0;i<linesNumber+2;i++){
        if(i == 0 || i == linesNumber + 1){
            for(j=0;j<columnsNumber+2;j++){
                printf("#");
            }
            //printf("\n");
        }else{
            for(j=0;j<columnsNumber+2;j++){
                if(j == 0 || j == columnsNumber + 1){
                    printf("#");
                }else if(map[j-1][i-1][playerNumber] == -1){
                    printf("X");
                }else if(map[j-1][i-1][playerNumber] == -2){
                    printf("H");
                }else if(map[j-1][i-1][playerNumber] == -3){
                    printf("S");
                }else{
                    printf("%d", map[j-1][i-1][playerNumber]);
                }
            }
        //printf("\n");
        }
        if(i==0){
            printf("     Legend of the map :");
        }else if(i==2){
            printf("     1/2/3/4 : ship of given type");
        }else if(i==3){
            printf("     0 : nothing");
        }else if(i==4){
            printf("     X : where you already shot");
        }else if(i==5){
            printf("     H : another player's ship you hit");
        }else if(i==6){
            printf("     S : one of your sunken ships");
        }
        printf("\n");


    }
}

void checkShotAi(int absShot, int ordShot, int linesNumber, int columnsNumber,int totalHumans, int totalAi, int map[lignesmax][colonnesmax][10], int playerNumber, char playerNames[10][15])
{
    int i = 0;
    int flagShot = 1;
    for(i=1;i<=totalAi+totalHumans;i++){
        if(i!=playerNumber){
            if(map[absShot][ordShot][i] != 0 && map[absShot][ordShot][i] != -1 && map[absShot][ordShot][i] != -2 && map[absShot][ordShot][i] != -3){
                map[absShot][ordShot][playerNumber] = -2;
                if(i<=totalHumans){
                    printf("hit the ship type number %d of %s. Congratulations to him!\n",map[absShot][ordShot][i],playerNames[i]);
                }else{
                    printf("hit the ship type number %d of bot number %d. Congratulations to him!\n",map[absShot][ordShot][i],i-totalHumans);
                }
                //printf("hit the ship type number %d of player %d. Congratulations to him!\n",map[absShot][ordShot][i],i);
                map[absShot][ordShot][i] = -3;
                flagShot = 0;
            }else{
                map[absShot][ordShot][playerNumber] = -1;
            }
        }
    }
    if(flagShot == 1){
        printf("hit nothing.\n");
    }
}

int checkShotHuman(int absShot, int ordShot, int linesNumber, int columnsNumber,int totalHumans, int totalAi, int map[lignesmax][colonnesmax][10], int playerNumber, char playerNames[10][15])
{
    int i = 0;
    int flagShot = 1;
    for(i=1;i<=totalHumans+totalAi;i++){
        if(i!=playerNumber){
            if(map[absShot][ordShot][i] != 0 && map[absShot][ordShot][i] != -1 && map[absShot][ordShot][i] != -2 && map[absShot][ordShot][i] != -3){
                map[absShot][ordShot][playerNumber] = -2;
                if(i<=totalHumans){
                    printf("You hit the boat type number %d of %s. Congratulations!\n",map[absShot][ordShot][i],playerNames[i-1]);
                }else{
                    printf("You hit the boat type number %d of bot number %d. Congratulations!\n",map[absShot][ordShot][i],i-totalHumans);
                }
                map[absShot][ordShot][i] = -3;
                flagShot = 0;
            }else{
                map[absShot][ordShot][playerNumber] = -1;
            }
        }
    }
    if(flagShot == 1){
        printf("\nYou hit nothing.\n");
    }
    return 0;
}

int testShot(int absShot, int ordShot, int playerNumber, int map[lignesmax][colonnesmax][10])
{
    if(map[absShot][ordShot][playerNumber] == 0 ){ //nothing there
        return 0;
    }else if(map[absShot][ordShot][playerNumber] == -1 || map[absShot][ordShot][playerNumber] == -2){ //already shot there
        return -1;
    }else if(map[absShot][ordShot][playerNumber] == CORVETTE_ID || map[absShot][ordShot][playerNumber] == CROISEUR_ID
             || map[absShot][ordShot][playerNumber] == DESTROYER_ID || map[absShot][ordShot][playerNumber] == PORTE_AVION_ID || map[absShot][ordShot][playerNumber] == -3){ //one of your boats here
        return 1;
    }
}

/*int doShot(int absShot, int ordShot, int playerNumber, int map[lignesmax][colonnesmax][10])
{
    if(testShot(absShot, ordShot, playerNumber, map) == 0){
        map[absShot][ordShot][playerNumber] == -1;
        return 0;
    } else if(testShot(absShot, ordShot, playerNumber, map) == 1){
        return 1;
    }else if(testShot(absShot, ordShot, playerNumber, map) == -1){
        return -1;
    }
}*/

int aiTurn(int linesNumber, int columnsNumber, int totalHumans, int totalAi, int map[lignesmax][colonnesmax][10], int playerNumber, char playerNames[10][15])
{
    int ordShot, absShot;
    int flag = 1;

    while(flag){
        absShot = doRand(0,columnsNumber);
        ordShot = doRand(0,linesNumber);
        if(testShot(absShot,ordShot,playerNumber,map) == 0){
            flag = 0;
        }
    }
    flag = 1;
    printf("Bot number %d shot at [%d,%d] and ",playerNumber-totalHumans,absShot,ordShot);
    checkShotAi(absShot,ordShot,linesNumber,columnsNumber,totalHumans,totalAi,map,playerNumber,playerNames);
    return 0;
}

int humanTurn(int linesNumber, int columnsNumber, int totalHumans, int totalAi, int map[lignesmax][colonnesmax][10], int playerNumber, char playerNames[10][15])
{
    int ordShot, absShot;
    int flag = 1;
    while(flag){
        printf("\n\n >> %s's turn.<<\n", playerNames[playerNumber-1]);
        printMap(linesNumber,columnsNumber,totalAi+totalHumans,map,playerNumber);
        printf("\n\n");
        printf("Where do you want to shoot ?\n");
        printf("Abscisse: ");
        scanf("%d",&absShot);
        printf("Ordonnee: ");
        scanf("%d",&ordShot);
        if(testShot(absShot,ordShot,playerNumber,map) == 0){
            flag = 0;
        }else if(testShot(absShot,ordShot,playerNumber,map) == 1){
            printf("One of your ships is there. Start again.");
        }else if(testShot(absShot,ordShot,playerNumber,map) == -1){
            printf("You already shot here once. Start again.");
        }
    }
    flag = 1;
    checkShotHuman(absShot,ordShot,linesNumber,columnsNumber,totalHumans,totalAi,map,playerNumber,playerNames);
    return 0;
}

int beginGame(int linesNumber, int columnsNumber, int totalHumans, int totalAi, int map[lignesmax][colonnesmax][10], int humanLeftTable[10], int aiLeftTable[10], char playerNames[10][15])
{
    int i = 0, j = 0;
    int nb = 0;
    /*for(i=1;i<=totalHumans;i++){ //calculus of alive human players
        if(humanLeftTable[i-1] == 1){
            humansLeft++;
        }
    }
    for(i=1;i<=totalHumans;i++){  // calculus of alive bot players
        if(humanLeftTable[i-1] == 1){
            aisLeft++;
        }
    }*/
    nb = numberPlayerLeft(linesNumber,columnsNumber,totalAi+totalHumans,map);
    //printf("%d joueurs vivants", nb);
    while(nb>=2){
        for(i=1;i<=totalHumans;i++){
            if(testPlayerAlive(linesNumber,columnsNumber,totalHumans+totalAi,map,i) == 0 && humanLeftTable[i-1] == 1){
                printf("--- Player %s is now dead! RIP ---",playerNames[i-1]);
                humanLeftTable[i-1] = 0;
            }
            if(humanLeftTable[i-1] == 1){
                humanTurn(linesNumber,columnsNumber,totalHumans,totalAi,map,i,playerNames);
            }
        }
        for(i=1;i<=totalAi;i++){
            if(testPlayerAlive(linesNumber,columnsNumber,totalAi+totalHumans,map,i+totalHumans) == 0 && aiLeftTable[i-1] == 1){
                printf("--- Bot number %d is now dead! RIP ---\n", i);
                aiLeftTable[i-1] = 0;
            }
            if(aiLeftTable[i-1] == 1){
                aiTurn(linesNumber,columnsNumber,totalHumans,totalAi,map,i,playerNames);
            }
        }
        nb = numberPlayerLeft(linesNumber,columnsNumber,totalAi+totalHumans,map);
    }
    if(nb == 1){
        for(j==1;j<=totalAi+totalHumans;j++){
            //int a = testPlayerAlive(linesNumber,columnsNumber,totalAi+totalHumans,map,j);
            //printf("lala %d", a);
            if(testPlayerAlive(linesNumber,columnsNumber,totalAi+totalHumans,map,j)){
                //printf("lala");
                if(j < totalHumans){
                    printf("\n>>> Congratulations to %s for winning! <<<\n",j,playerNames[j-1]);
                }else{
                    printf("\n>>> Congratulations to bot number %d for winning <<<\n",j-totalHumans);
                }

            }
        }
    }
    return 0;
}

void setShip(int x, int y, int dir, int width, int id, int linesNumber, int columnsNumber, int totalPlayers, int playerNumber, int map[lignesmax][colonnesmax][10])
{
    int i = 0;

    //printf("setNavire joueur=%d x=%d y=%d size=%d id=%d dir=%d \n",playerNumber,x,y,width,id,dir);

    if(dir == 0){
        for(i= 0;i<width;i++){
            map[x][y+i][playerNumber] = id;
        }
    }else if(dir == 1){
        for(i=0;i<width;i++){
            map[x+i][y][playerNumber] = id;
        }
    }else if(dir == 2){
        for(i=0;i<width;i++){
            map[x][y-i][playerNumber] = id;
        }
    }else if(dir == 3){
        for(i=0;i<width;i++){
            map[x-i][y][playerNumber] = id;
        }
    }
}

int testCase(int x, int y, int dir, int width, int linesNumber, int columnsNumber, int totalPlayers, int playerNumber, int map[lignesmax][colonnesmax][10])
{
    int i = 0;
    int j = 0;
    int flagOk = 1;

    /*for(i = 0; i < totalPlayers; i++){ //test if case occupied by any player's boat
       if(map[x][y][i] !=0){
        flagOk = 0;
       }
    }*/

    if(dir == 0){ //towards bottom
        if(y + width - 1 <  linesNumber){ // boat doesnt go out of the board towards bottom
            for(i=0;i<width;i++){ // For each case towards bottom
                for(j=1;j<=playerNumber+1;j++){ // and for each player
                    if(map[x][y+i][j] != 0){ // case doesnt contain anything
                        flagOk = 0;
                    }
                }

            }
        }else{
        return -1;
        }
    }else if(dir == 1){ //towards right
        if(x + width - 1 <  columnsNumber){ // boat doesnt go out of the board towards right
            for(i=0;i<width;i++){ // For each case towards bottom
                for(j=1;j<=playerNumber;j++){ // and for each player
                    if(map[x+i][y][j] != 0){ // case doesnt contain anything
                        flagOk = 0;
                    }
                }

            }
        }else{
        return -1;
        }
    }else if(dir == 2){ //towards top
        if(y - width - 1 >  linesNumber){ // boat doesnt go out of the board towards top
            for(i=0;i<width;i++){ // For each case towards right
                for(j=1;j<=playerNumber;j++){ // and for each player
                    if(map[x][y-i][j] != 0){ // case doesnt contain anything
                        flagOk = 0;
                    }
                }

            }
        }else{
        flagOk = 0;
        }
    }else if(dir == 3){ //towards left
        if(x - width - 1 >  columnsNumber){ // boat doesnt go out of the board towards bottom
            for(i=0;i<width;i++){ // For each case towards left
                for(j=1;j<=playerNumber;j++){ // and for each player
                    if(map[x-i][y][j] != 0){ // case doesnt contain anything
                        flagOk = 0;
                    }
                }

            }
        }else{
        return -1;
        }
    }else{
        return -1;
    }

    if(flagOk == 0){// if any case occupied towards given direction
        return -1;
    }else{
        return 0;
    }
}

void setPorteAvion(int nbPorteAvion, int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10], int playerNumber)
{
    int i = 0;
    int x = -1;
    int y = -1;
    int d = -1;
    int flag = 1;
    for(i=0;i<nbPorteAvion;i++){
        while(flag){
            y = doRand(0,linesNumber);
            x = doRand(0,columnsNumber);
            d = doRand(0,4);
            if(testCase(x,y,d,PORTE_AVION_WIDTH,linesNumber,columnsNumber,totalPlayers,playerNumber,map) == 0){
                setShip(x,y,d,PORTE_AVION_WIDTH,PORTE_AVION_ID,linesNumber,columnsNumber,totalPlayers,playerNumber,map);
                flag = 0;
            }
        }
        flag = 1;
    }
}

void setDestroyer(int nbDestroyer, int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10], int playerNumber)
{
    int i = 0;
    int x = -1;
    int y = -1;
    int d = -1;
    int flag = 1;
    for(i=0;i<nbDestroyer;i++){
        while(flag){
            y = doRand(0,linesNumber);
            x = doRand(0,columnsNumber);
            d = doRand(0,4);
            if(testCase(x,y,d,DESTROYER_WIDTH,linesNumber,columnsNumber,totalPlayers,playerNumber,map) == 0){
                setShip(x,y,d,DESTROYER_WIDTH,DESTROYER_ID,linesNumber,columnsNumber,totalPlayers,playerNumber,map);
                flag = 0;
            }
        }
        flag = 1;
    }
}

void setCroiseur(int nbCroiseur, int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10], int playerNumber)
{
    int i = 0;
    int x = -1;
    int y = -1;
    int d = -1;
    int flag = 1;
    for(i=0;i<nbCroiseur;i++){
        while(flag){
            y = doRand(0,linesNumber);
            x = doRand(0,columnsNumber);
            d = doRand(0,4);
            if(testCase(x,y,d,CROISEUR_WIDTH,linesNumber,columnsNumber,totalPlayers,playerNumber,map) == 0){
                setShip(x,y,d,CROISEUR_WIDTH,CROISEUR_ID,linesNumber,columnsNumber,totalPlayers,playerNumber,map);
                flag = 0;
            }
        }
        flag = 1;
    }
}


void setCorvette(int nbCorvette, int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10], int playerNumber)
{
    int i = 0, x = -1, y = -1, d = -1;
    int flag = 1;
    for(i=0;i<nbCorvette;i++){
        while(flag){
            y = doRand(0,linesNumber);
            x = doRand(0,columnsNumber);
            d = doRand(0,4);
            if(testCase(x,y,d,CORVETTE_WIDTH,linesNumber,columnsNumber,totalPlayers,playerNumber,map) == 0){
                setShip(x,y,d,CORVETTE_WIDTH,CORVETTE_ID,linesNumber,columnsNumber,totalPlayers,playerNumber,map);
                flag = 0;
            }
        }
        flag = 1;
    }
}

void setShips(int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10])
{
    int k = 1;
    for(k=1;k<=totalPlayers;k++){ // i = numéro de joueur
        setCorvette(CORVETTE_NB,linesNumber,columnsNumber,totalPlayers,map,k);
        setDestroyer(DESTROYER_NB,linesNumber,columnsNumber,totalPlayers,map,k);
        setCroiseur(CROISEUR_NB,linesNumber,columnsNumber,totalPlayers,map,k);
        setPorteAvion(PORTE_AVION_NB,linesNumber,columnsNumber,totalPlayers,map,k);
    }
}

/*void generateMap(int linesNumber, int columnsNumber, int totalPlayers, int map[lignesmax][colonnesmax][10])
{
    setShips(linesNumber, columnsNumber, totalPlayers, map);
}*/

void purgeMap(int map[200][200][10])
{
    int i = 0;
    int j = 0;
    int k = 0;
    for(i=0;i<200;i++){
        for(j=0;j<200;j++){
            for(k=0;k<10;k++){
            map[i][j][k] = 0;
            }
        }
    }
}

void printBeginningMenu()
{
    int i = 0;
    int totalHumans = 0, totalAi = 0, linesNumber = 0, columnsNumber = 0;
    char inputFirstMenu[50];
    int map[lignesmax][colonnesmax][10];
    int humanLeftTable[10] = {0};
    int aiLeftTable[10] = {0};
    int flag = 1;
    char playerNames[10][15];

    purgeMap(map);

    system("cls");
    printf("###################################################\n");
    printf("#####                                         #####\n");
    printf("#####        Welcome to BATTLESHIP 1.0        #####\n");
    printf("#####                                         #####\n");
    printf("#####                    Press y to start     #####\n");
    printf("###################################################\n");
    printf("\n");
    scanf("%s",&inputFirstMenu);
    fflush(stdout);

    while(flag){
        printf("\nChoose the number of non-ai players (0 - 10): ");
        totalHumans = mathInputInt();
        if(totalHumans >=0 && totalHumans <=10){
            flag = 0;
        }
    }
    flag = 1;

    for(i=0;i<totalHumans;i++){ // asks players' names
        printf("Name of player number %d: ", i+1);
        scanf("%s",playerNames[i]);
    }

    while(flag){
        printf("\nChoose the number of ai players (0 - %d): ",10-totalHumans);
        totalAi = mathInputInt();
        if(totalAi >=0 && totalAi <= 10 - totalHumans){
            flag = 0;
        }
    }
    flag = 1;

    while(flag){
        printf("\nChoose the number of lines on the map (1 - 200): ");
        linesNumber = mathInputInt();
        if(linesNumber >= 1 && linesNumber <= 200){
            flag = 0;
        }
    }
    flag = 1;

    while(flag){
        printf("\nChoose the number of columns on the map (1 - 200): ");
        columnsNumber = mathInputInt();
        if(columnsNumber >= 1 && columnsNumber <= 200){
            flag = 0;
        }
    }

    for(i=0;i<totalHumans;i++){
        humanLeftTable[i] = 1;
    }
    for(i=0;i<totalAi;i++){
        aiLeftTable[i] = 1;
    }
    int totalPlayers = totalHumans + totalAi;
    setShips(linesNumber,columnsNumber,totalPlayers,map);
    printf("\n\n");
    /*printMap(linesNumber, columnsNumber, totalPlayers, map, 1);
    printf("\n\n");
    printMap(linesNumber, columnsNumber, totalPlayers, map, 2);
    printMap(linesNumber, columnsNumber, totalPlayers, map, 0);*/
    //flag = 0;

    beginGame(linesNumber,columnsNumber,totalHumans,totalAi,map,humanLeftTable,aiLeftTable,playerNames);
}

int bsmain()
{
        system("cls");
    printBeginningMenu();
    return 0;
}
                                         /********************/
                                         /**** SUDOKO ****/
                                         /********************/




int SUDOKOmain(int argc, char *argv[])

{
  /* option d'affichage dans la fontion resolve */
   g_flag_affiche = ((argc>= 2) && (parametre_affichage(argv[1])));
   /**********/
       system("cls");
   printf("\n******* SUDOKU *******\n\n");
   printf("l'option sudoku -a affiche la resolution case par case.\n\n");
   printf("Saisissez %d lignes de %d chiffres,\n", MAXX, MAXX);
   printf("les chiffres peuvent etre separes par n'importe quels caracteres\n");
   printf("Rentrez un 0 pour chaque case vide.\n");
   printf("Pour quitter le programme, valider la lettre Q.\n\n");
   while (saisie_grille()) {
      g_comp_tests = 0;
      resolve();

   affiche_grille();
      if (! grille_finie()) printf("Enonce errone...\n");
      printf("Tests : %ld\n\n", g_comp_tests);
   }
   printf("\n");
   return 0;
}



/*************************************
**************************************/
int parametre_affichage(char t[])

{
   /* Renvoi VRAI si l'utilisateur a taper une demande d'option d'affichage
   sous la forme : a, A, ou /a , /A , -a , -A ect... sinon renvoi FAUX */
   char param;
   if (strlen(t) == 1) param = t[0];
   else if (strlen(t) == 2) param = t[1];
   else param = 0;
   return ((param == 'A') || (param == 'a'));
}


                                            /**********************************/
                                            /**** SAISIES ET VERIFICATIONS ****/
                                            /**********************************/

 /************************
************************/

int saisie_grille(void)

{/* l'utilisateur saisie 9 lignes de 9 chiffres */
   int ligne;
   grille[0][0]=9;
        grille[0][1]=7;
        grille[0][2]=6;
        grille[0][3]=4;
        grille[0][4]=8;
        grille[0][5]=1;
        grille[0][6]=3;
        grille[0][7]=2;
        grille[0][8]=5;
        grille[8][0]=3;
        grille[8][1]=8;
        grille[8][2]=9;
        grille[8][3]=1;
        grille[8][4]=4;
        grille[8][5]=5;
        grille[8][6]=6;
        grille[8][7]=7;
        grille[8][8]=2;
   printf("Saisissez votre grille : \n");

   while (VRAI){
        affiche_grille();
      for (ligne = 0; ligne < MAXX; ligne++)
        {if (ligne==0) {

        printf("ligne 1 : %d %d %d %d %d %d %d %d %d  \n",grille[0][0],grille[0][1],grille[0][2],grille[0][3],grille[0][4],grille[0][5],grille[0][6],grille[0][7],grille[0][8]);}
        else if (ligne==8) {

        printf("ligne 9 : %d %d %d %d %d %d %d %d %d  \n",grille[0][0],grille[0][1],grille[0][2],grille[0][3],grille[0][4],grille[0][5],grille[0][6],grille[0][7],grille[0][8]);}
        else {
         if (! saisie_une_ligne(ligne)) return (FAUX);}
        }
      printf("\n Enonce : \n");
   affiche_grille();
      if (verif_saisie_grille()) return(VRAI);
      else printf("\n");
   }
}



  /************************
************************/




int saisie_une_ligne(int ligne)
{
/*Seuls les 9 premiers chiffres seront retenus . il faut eviter d'ecrire un chiffre plus q'une fois  */
   int c, i;
   int col = 0;
   int result = VRAI;
   /* RAZ des cases de la ligne */
   for (i = 0; i < MAXX; i++)
    {
      grille[ligne][i] = 0;
    }

   printf("Ligne %d : ", ligne+1);
   while(VRAI)
    {
      c = fgetc(stdin);
     if (c == feof(stdin) || c == 0x0A) return result;/*feof => end of*/
      else if ((c == 'Q') || (c == 'q')) result = FAUX;
      /* transfert de la saisie dans les cases de la ligne */
     else if ( (result) && (col < MAXX) && (c >= '0') && (c <= '9'))
        {
         grille[ligne][col++] = c-48;
        }
     }
}



/*****************************************
******************************************/

int verif_saisie_grille(void)

{/* verifie si pas de doublon dans l'ensemble de la grille */
   int result = VRAI;
   if (! verif_saisie_lignes()) result = FAUX;
   if (! verif_saisie_colonnes()) result = FAUX;
   if (! verif_saisie_carres()) result = FAUX;
   return result;
}




/*************************************************
**************************************************/



int verif_saisie_lignes(void)
{/* verifie si pas de doublon dans les lignes */
   int ligne;
   int result = VRAI;
   for (ligne = 0; ligne < MAXX; ligne++)
    {
      if (! verif_saisie_une_ligne(ligne)) result = FAUX;
    }
   return result;
}

/************************
************************/
int verif_saisie_une_ligne(int ligne)

{/* verifie si pas de doublon dans la ligne */
   int i,j;
   for (i = 0; i < MAXX-1; i++)
    {
      if ( grille[ligne][i] == 0 ) continue;
      for (j = i+1; j < MAXX; j++)
      {
         if (grille[ligne][i] == grille[ligne][j])
            {
            printf("Erreur ligne %d : chiffres egaux\n", ligne+1);
            return FAUX;
            }
      }
   }
   return VRAI;
}

/************************
************************/


int verif_saisie_colonnes(void)
/***********************/
{/* verifie si pas de doublon dans les colonnes */
   int col;
   int result = VRAI;
   for (col = 0; col < MAXX; col++)
    {
      if (! verif_saisie_une_colonne(col)) result = FAUX;
    }
   return result;
}


/************************
************************/


int verif_saisie_une_colonne(int col)
{/* verifie si pas de doublon dans la colonne */
   int i, j;
   for (i = 0; i < MAXX-1; i++)
   {
      if ( grille[i][col] == 0 ) continue;
      for (j = i+1; j < MAXX; j++)
      {
         if (grille[i][col] == grille[j][col])
         {
            printf("Erreur colonne %d : chiffres egaux\n", col+1);
            return FAUX;
         }
      }
   }
   return VRAI;
}



/************************
************************/



int verif_saisie_carres(void)

{/* verifie si pas de doublon dans les carres de 3 X 3 */
   int carre;
   int result = VRAI;
   for (carre = 0; carre < MAXX; carre++)
    {
      if (! verif_saisie_un_carre(carre)) result = FAUX;
    }
   return result;
}



/************************
************************/


int verif_saisie_un_carre(int carre)

{/* verifie si pas de doublon dans le carre de 3 X 3 */
   char tamp[MAXX+10];
   int i, j;
   trans_carre(tamp, carre);
   for (i = 0; i < MAXX-1; i++)
    {
      if (tamp[i] == 0 ) continue;
   for (j = i+1; j < MAXX; j++)
      {
   if (tamp[i] == tamp[j])
         {
   printf("Erreur carre %d : chiffres egaux\n", carre+1);
            return FAUX;
         }
      }
   }
   return VRAI;
}



/************************
************************/


void trans_carre(char tamp[], int carre)

{/* transfert le carre de 3 X 3 dans un tableau a une dimension */
   int i,j, x,y,z;
   x = (((carre) % MINN)*MINN);
   y = (((carre+MINN) / MINN)*MINN)-MINN;
   z = 0;
   for (j = y; j < y+MINN; j++)
   {
      for (i = x; i < x+MINN; i++)
      {
         tamp[z++] = grille[j][i];
      }
   }
}






/*************************************************
**************************************************/






                                         /********************/
                                         /**** RESOLUTION ****/
                                         /********************/



   void resolve(void)
{
   int ligne, col, nbre, nbre_tamp;
   for (ligne = 0; ligne < MAXX; ligne++)
   {
      for (col = 0; col < MAXX; col++)
        {
         if (grille[ligne][col]) continue;/* si differents de 0 rien a faire */
         for (nbre = 1; nbre <= MAXX; nbre++)
        {
            if (! case_dispo_nbre(nbre, ligne, col)) continue;  /*si le nbre entrer est impossible a utiliser */
            nbre_tamp = grille[ligne][col];
            grille[ligne][col] = nbre;
            g_comp_tests++;
            if (g_flag_affiche) affiche_grille_attente();
            resolve();
            if (grille_finie()) return;

            grille[ligne][col] = nbre_tamp;
         }
         return;
      }
   }
   return;
}




 /************************
************************/




int case_dispo_nbre(int nbre, int ligne, int col)
{
/* verifier si on peut utiliser le nombre
 */
   char tamp[MAXX+10];
   int i;
   /*si nbre est utilise dans la ligne, renvoi FAUX */
   for (i = 0; i < MAXX; i++) if (grille[ligne][i] == nbre) return(FAUX);
   /*si nbre est utilise dans la colonne, renvoi FAUX */
   for (i = 0; i < MAXX; i++) if (grille[i][col] == nbre) return(FAUX);
   /*si nbre est utilise dans le mini carre, renvoi FAUX */
   trans_carre_de_case(tamp, ligne, col);
   for (i = 0; i < MAXX; i++) if (tamp[i] == nbre) return (FAUX);
   /*donc nbre est diponible pour la case */
   return(VRAI);
}




/************************
************************/



void trans_carre_de_case(char tamp[], int ligne, int col)

/* tranfert le carre de 3 X 3 dans un tableau a une dimension */
{
   int i, j, k;
   while ((ligne % MINN) != 0) ligne--;
   while ((col % MINN) != 0) col--;
   k = 0;
   for (j = ligne; j < ligne+MINN; j++)
   {
      for (i = col; i < col+MINN; i++)
        {
         tamp[++k] = grille[j][i];
        }
   }
}

                                               /****************************************/
                                               /*****************DIVERS*****************/
                                               /****************************************/


void affiche_grille_attente(void)

{/* affiche la grille avec mise en attente de la touche entree */
   affiche_grille();
   printf("%ld, Touche entree pour la suite...", g_comp_tests);
   attente();
}




/*************************************************
*************************************************/



void affiche_grille(void)

{/* affiche l'ensemble de la grille */
   int ligne, col;
   for (ligne = 0; ligne < MAXX; ligne++)
   {
      for (col = 0; col < MAXX; col++)
      {
         printf(" %1d ", grille[ligne][col]);
         if ( ((col % MINN) == MINN-1) && (col < MAXX-1) )
         {
            printf(" | ");
         }
      }
      printf("\n");
      if ( ((ligne % MINN) == MINN-1) && (ligne < MAXX-1) ) {
         affiche_chaine(33);
      }
   }/* end for ligne */
   printf("\n");
}/* end affiche_grille */



/****************************************************
****************************************************/





void affiche_chaine(int nbre)

{/* Affiche une suite de caractere etoile */
   int i;
   for (i = 1; i <= nbre; i++) {
      printf("*");
   }
   printf("\n");
}



/**************************************************
**************************************************/

int grille_finie(void)

/* teste si la grille est finie.
Retourne VRAI  sinon retourne FAUX */
{
   int ligne, col;
   for (ligne = MAXX-1; ligne >= 0; ligne--) {
      for (col = MAXX-1; col >= 0; col--) {
         if (grille[ligne][col] == 0 ) {
            return FAUX;
         }
      }
  }
   return VRAI;
}


/***********************************************
***********************************************/



void attente(void)

{/* attente de la touche entree au clavier */
   char c;
   while(VRAI)
    {
      c = fgetc(stdin);
      if (c == feof(stdin) || c == 0x0A) return;
   }
}



                                         /********************/
                                         /**** TIC TAC TOE ****/
                                         /********************/


void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int tttmain()
{
    system("cls");
    menu();

    return 0;

}

void menu()
{
    int choice;
    system("cls");
    printf("\n--------MENU--------");
    printf("\n1 : Play with X");
    printf("\n2 : Play with O");
    printf("\n3 : Exit");
    printf("\nEnter your choice:>");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        player_first();
        break;
    case 2:
        player = 0;
        comp = 1;
        start_game();
        break;
    case 3:
        exit(1);
    default:
        menu();
    }

}

int make2()
{
    if(board[5] == 2)
        return 5;
    if(board[2] == 2)
        return 2;
    if(board[4] == 2)
        return 4;
    if(board[6] == 2)
        return 6;
    if(board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if(board[1] == 2)
        return 1;
    if(board[3] == 2)
        return 3;
    if(board[7] == 2)
        return 7;
    if(board[9] == 2)
        return 9;
    return 0;
}

int posswin(int p)
{
// p==1 then X   p==0  then  O
    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)//row check
    {
        if(board[i] * board[i+1] * board[i+2] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+1] == 2)
                return i+1;
            if(board[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(board[i] * board[i+3] * board[i+6] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+3] == 2)
                return i+3;
            if(board[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(board[1] * board[5] * board[9] == check_val)
    {
        if(board[1] == 2)
            return 1;
        if(board[5] == 2)
            return 5;
        if(board[9] == 2)
            return 9;
    }

    if(board[3] * board[5] * board[7] == check_val)
    {
        if(board[3] == 2)
            return 3;
        if(board[5] == 2)
            return 5;
        if(board[7] == 2)
            return 7;
    }
    return 0;
}

void go(int n)
{
    if(turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void player_first()
{
    int pos;

    check_draw();
    draw_board();
    gotoxy(30,18);
    printf("Your Turn :> ");
    scanf("%d",&pos);

    if(board[pos] != 2)
        player_first();

    if(pos == posswin(player))
    {
        go(pos);
        draw_board();
        gotoxy(30,20);
        //textcolor(128+RED);
        printf("Player Wins");
        getch();
        exit(0);
    }

    go(pos);
    draw_board();
    start_game();
}

void start_game()
{
// p==1 then X   p==0  then  O
    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(make2())
        go(make2());
    else
        go(make4());
    draw_board();

    if(flag)
    {
        gotoxy(30,20);
        //textcolor(128+RED);
        printf("Computer wins");
        getch();
    }
    else
        player_first();
}

void check_draw()
{
    if(turn > 9)
    {
        gotoxy(30,20);
        //textcolor(128+RED);
        printf("Game Draw");
        getch();
        exit(0);
    }
}

void draw_board()
{
    int j;

    for(j=9; j<17; j++)
    {
        gotoxy(35,j);
        printf("|       |");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<10; j++)
    {
        if(board[j] == 3)
            put_X_O('X',j);
        else if(board[j] == 5)
            put_X_O('O',j);
    }

}

void put_X_O(char ch,int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}





