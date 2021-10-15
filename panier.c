#include <stdio.h>
#include <stdlib.h>

// le programme prends en compte que ces fonctions existent
void ask();
void panier();

// Déclaration des variables
char a[100];
char filename[35];
int m;
int i;
int v = 1;
float p;
float t;
float ttc;


int main()
{
    // Le programme débute avec un texte qui résume tout du programme
    printf("Programme qui calcul le total d'articles que vous avez et vous donne un reçu\n");
    printf("\n");
    printf("Nom du fichier de reçu : ");
    scanf("%s", filename);
    printf("\n");
    printf("Ajouter un article pour votre panier\n");
    ask(); // appelle la fonction ask
}

void ask()
{
    while (v == 1) // on lance une boucle et tant que la variable m n'est pas égale à un chiffre ou un nombre la boucle continue
    {
        printf("Combien d'articles voulez vous ajouter à votre panier ? Limite : 25\n");
        if (scanf("%i", &m) == 1) // si m est égale à un chiffre ou un nombre
        {
            if (m <= 25) // si m est plus petit ou égale à 25
            {
                panier(); // ça renvoie donc à la fonction panier
                v = 0; // le v sert à arrêter la boucle
            }
            else if (m >= 25) // si m est plus grand ou égale à 25
            {
                printf("LIMITER A 25 ARTICLES !\n");
                ask(); // renvoie à la fonction ask
            }
        }
        else // autrement si m n'est pas égale à un chiffre ou un nombre la boucle continue
        {
            printf("! Mauvais format !\n");
            getchar(); // on redemande à l'utilisateur de taper puis la touche entrer
        }
    }
}

void panier()
{
    // On ouvre un fichier
    FILE *file;
    file = fopen(filename, "a");
    // Enregistre dans le fichier
    fprintf(file, "Vous avez %i d'article(s)\n", m);
    fprintf(file, "\n");
    // boucle qui demande tant que l'utilisateur à terminer d'écrire ses articles et le prix
    for (i = 0; i < m; i++)
    {
        printf("Article %i : ", i + 1);
        scanf("%s", a);
        printf("Prix (HT) du produit en euro : ");
        scanf("%f", &p);
        t += p;
        fprintf(file, "Article %i : %s\nPrix de l'article (HT) : %.2f €\n", i + 1, a, p);
        fprintf(file, "TVA : %.2f\n", p * 0.2);
        fprintf(file, "\n");
    }
    ttc = t * 0.2;
    printf("Vous avez %i articles dans votre panier\n", m);
    fprintf(file, "Montant HT : %.2f €\n", t);
    fprintf(file, "\n");
    fprintf(file, "Montant total TTC : %.2f €\n", ttc + t);
    printf("Tout a été inscrit dans le reçu !\n");
    fclose(file); // ferme le fichier à la fin
}