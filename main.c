#include <stdio.h>
#include <stdlib.h>

void jeu(const char couleurs[], const int max_tentatives, const int nb_couleurs, const int taille_code, char code_secret[], char saisie_user[],int choix, int continuer);
void regles(const char couleurs[], const int max_tentatives, const int nb_couleurs, const int taille_code, char code_secret[], char saisie_user[], int choix, int continuer);


int menu(const char couleurs[], const int max_tentatives, const int nb_couleurs, const int taille_code, char code_secret[], char saisie_user[], int choix, int continuer)
{
    continuer = 1;

    printf("\t\t\t\t----------------------MASTERMIND------------------------------\n\n\n");
    printf("MENU : \n\n");
    printf("\t -1 --> Jouer\n");
    printf("\t -2 --> Regles\n");
    printf("\t -3 --> Quitter\n");
    scanf("%d", &choix);

    do
    {
        switch (choix)
    {
    case 1:
        jeu(couleurs,max_tentatives,nb_couleurs,taille_code,code_secret,saisie_user,choix,continuer);
        break;

    case 2:
        regles(couleurs, max_tentatives,nb_couleurs,taille_code,code_secret,saisie_user,choix,continuer);
        break;

    case 3:
        return 0;



    default:
        continuer = 1;
        break;

    }

    }while (continuer != 1);


    return 0;
}

void regles(const char couleurs[], const int max_tentatives, const int nb_couleurs, const int taille_code, char code_secret[], char saisie_user[], int choix, int continuer)
{
    printf("\tHabituellement le Mastermind est un jeu qui se joue avec des couleurs, ici nous utiliserons les initiales de ces couleurs.\n Il y a 5 couleurs possibles dans le jeu, mais la combinaison secrete n'en comporte que 4.\n Ainsi c'est a vous d'ecrire en majuscule et sans espace la combinaisons que vous pensez etre la bonne.\n Vous possedez 12 tentatives.\n Vous aurez pour seul indices le nombre de couleurs bien placees dans votre proposition \n\n ");

    printf("\t\t\t Pour retourner au MENU apuyez sur une touche \n\n");

     while (getchar() == '\n')
        {

        }
    menu(couleurs,max_tentatives,nb_couleurs,taille_code,code_secret,saisie_user,choix, continuer);

}



void jeu(const char couleurs[], const int max_tentatives, const int nb_couleurs, const int taille_code, char code_secret[], char saisie_user[],int choix, int continuer)
{


    do
    {
            for (int nb_tentatives=1; nb_tentatives<=max_tentatives; nb_tentatives++)
        {

            continuer = 1;
            printf("Donnez un code de 4 couleurs parmis {'R','V','B','J','O'} \n ");
            fflush(stdin);
            scanf("%c%c%c%c", saisie_user, (saisie_user+1), (saisie_user+2), (saisie_user+3));

            int nb_couleurs_places = 0;

            for (int i = 0; i<4; i++)
            {
                if (code_secret[i] == saisie_user[i])
                {
                    nb_couleurs_places++;
                }
            }
            if (nb_couleurs_places == taille_code)
            {
                printf("felicitation  vous avez trouver en %d tentatives \n\n",nb_tentatives);
                break;
            }
            else if (nb_tentatives>=max_tentatives)
            {
                printf("\t\tTentatives %d/%d \n", nb_tentatives,max_tentatives);
                printf("nb de tentatives depasser le code secret etait %c%c%c%c\n",code_secret[0], code_secret[1], code_secret[2], code_secret[3]);
                break;
            }
            else
            {
                printf("\t\tTentatives %d/%d \n", nb_tentatives,max_tentatives);
                printf("couleurs bien placees : %d\n\n", nb_couleurs_places);


            }


        }
        printf("\t\t\tSouhaitez vous rejouer ? [1 --> OUI / 2--> NON] \n\n");
        scanf("%d", &continuer);
        if (continuer == 2)
        {
            menu(couleurs,max_tentatives,nb_couleurs,taille_code,code_secret,saisie_user,choix, continuer);

        }

    }while (continuer !=2);

}



int main()
{

    const char couleurs[] = {'R','v','B','J','O'};
    const int max_tentatives = 12;
    const int nb_couleurs = 5;
    const int taille_code = 4;

    char code_secret[] = {'V', 'B', 'J', 'O'};
    char saisie_user[taille_code];
    int choix =0;
    int continuer = 0;


    menu(couleurs,max_tentatives,nb_couleurs,taille_code,code_secret,saisie_user,choix, continuer);

    return 0;


}



