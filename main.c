#include <stdio.h>
#include <stdlib.h>

void triangleDePascalStatique(int taille) {   
  // On crée une variable triangleStatique qui sera notre triangle de Pascal de taille taille
  int triangleStatique[taille][taille];
  // On rempli triangleStatique
  printf("\nTriangle de Pascal de façon statique :\n\n");
  for (int i = 0; i < taille; i++) {
    // Effet de style pour représenter une pyramide
    for (int j = 0; j < taille-i; j++) {
      // Condition pour maintenir le style selon la grandeur de la pyramide
      printf("%s", (taille <=5) ? " " : "  ");

    }
    for (int j = 0; j < i+1; j++) {
      // Si j est égal à 0, on met 1 dans la case
      if (j == 0) {
        triangleStatique[i][0] = 1;
      } else {
        // Si i est égal à j, on rempli la diagonale
        if (i == j) {
          triangleStatique[i][j] = 1;

        }
        // Sinon on calcul le résultat de la case
        else {
          triangleStatique[i][j] = triangleStatique[i-1][j-1] + triangleStatique[i-1][j];

        }
      }
      // On affiche toutes les valeurs des cases avec un effet de style
      // Conditions pour maintenir le style selon la grandeur de la pyramide
      if (taille <= 5) {
        printf("%3d", triangleStatique[i][j]);

      } else if (taille <= 10) {
        printf("%4d", triangleStatique[i][j]);

      } else {
        printf("%5d", triangleStatique[i][j]);

      }

    }
    printf("\n");
  }
}

void triangleDePascalDynamique(int taille) {
  // On crée une variable triangleDynamique qui contiendra un double pointeur
  int **triangleDynamique;
  // On donne à triangleDynamique la valeur de malloc avec comme paramètres : la taille multiplié par la taille d'un entier
  triangleDynamique = (int**) malloc(taille * sizeof(int*));
  // Pour chaque ligne dans le triangleDynamique on donne à triangleDynamique[i] la valeur de malloc avec comme paramètres : la taille de i+1 multipliépar la taille d'un entier
  for (int i = 0; i < taille; i++) {
    triangleDynamique[i] = (int*) malloc((i+1) * sizeof(int));
 
  }
  // On rempli triangleDynamique
  printf("\nTriangle de Pascal de façon dynamique :\n\n");
  for (int i = 0; i < taille; i++) {
    // Effet de style pour représenter une pyramide
    for (int j = 0; j < taille-i; j++) {
      // Condition pour maintenir le style selon la grandeur de la pyramide
      printf("%s", (taille <=5) ? " " : "  ");

    }
    for (int j = 0; j < i+1; j++) {
      // Si j est égal à 0, on met 1 dans la case
      if (j == 0) {
        triangleDynamique[i][0] = 1;
      } else {
        // Si i est égal à j, on rempli la diagonale
        if (i == j) {
          triangleDynamique[i][j] = 1;

        }
        // Sinon on calcul le résultat de la case
        else {
          triangleDynamique[i][j] = triangleDynamique[i-1][j-1] + triangleDynamique[i-1][j];

        }
      }
      // On affiche toutes les valeurs des cases avec un effet de style
      // Conditions pour maintenir le style selon la grandeur de la pyramide
      if (taille <= 5) {
        printf("%3d", triangleDynamique[i][j]);

      } else if (taille <= 10) {
        printf("%4d", triangleDynamique[i][j]);

      } else {
        printf("%5d", triangleDynamique[i][j]);

      }

    }
    printf("\n");
  }
  // On libère les colonnes de triangleDynamique
  for (int i = 0; i < 3; i++) {
    free(triangleDynamique[i]);
  }
  // On libère le reste de triangleDynamique (soit les lignes)
  free(triangleDynamique);

}

int main(void) {
  // On crée les variables int taille et tailleValide                
  int taille, tailleValide = 0;
  // On demande à l'utilisateur la la taille   
  do {
    printf("Saisissez une taille pour vos triangles => ");
    scanf("%d", &taille);
    if (taille < 1) {
      printf("Veuillez saisir un nombre supérieur à 1 => ");
    } else if (taille > 15) {
      printf("Votre nombre est grand pour le triangle de Pascal.\nLe triangle risque d'être mal affiché. Souhaitez-vous continuer ? 1-Oui | 2-Non => ");
      scanf("%d", &tailleValide);
      tailleValide = (tailleValide == 1) ? 1 : 0;
    } else {
      tailleValide = 1;
    }

  } while (tailleValide == 0);
  /* 
   * Triangle de Pascal Statique *
                                 */  
  triangleDePascalStatique(taille); 

  /*
  * Triangle de Pascal Dynamique *
                                 */
  triangleDePascalDynamique(taille);

  return 0;
}