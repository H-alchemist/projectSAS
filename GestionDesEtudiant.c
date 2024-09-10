#include <stdio.h>
#include <string.h>

#define max 30

 typedef  struct  {

    char cni[10];

    char nom[50];

    char prenom[50];
    char dateNaissance[11];
     char departement[30];
    float ntGenerale;


}etudiant;

const char listeD[3][9] = {"physique", "math", "chimie"};

  etudiant etudiants[max];
int numTotal = 0;

int chercher(char cni[]) {

    for (int i = 0; i < numTotal; i++) {
        if (strcmp(etudiants[i].cni, cni) == 0) {
            return i;
        }
    }
    return -1;
}

void ajoute() {
    if (numTotal < max) {

         etudiant e;

        float nt1, nt2, nt3;
        int x;

        printf("Entrez le cni: ");

        scanf("%s", e.cni);

        if (chercher(e.cni) != -1) {
            printf("cette cni deja existe .\n");
            return;
        }

        printf("Entrez le nom: ");
        scanf("%s", e.nom);

        printf("Entrez le prenom: ");
        scanf("%s", e.prenom);

        printf("Entrez la date de naissance (YYYY-MM-DD): ");
        scanf("%s", e.dateNaissance);
     
         printf("pour le departement:enter 1 pour physique - 2 pour math - 3 pour chimie ");

        scanf("%d", &x);
         strcpy(e.departement, listeD[x-1]); 

        printf("Entrez la premiere note: ");

         scanf("%f", &nt1);

        printf("Entrez la deuxieme note: ");
        scanf("%f", &nt2 );

     printf("Entrez la troisieme note: ");

        scanf("%f",  &nt3);

        e.ntGenerale = (nt1 + nt3 + nt2) / 3.0;

        etudiants[numTotal] = e;
        numTotal++;

       
    } else {
        printf("La liste des etudiants est pleine.\n");
    }
}

void supprime() {
    char cni[10];
    printf("Entrez le cni de l'etudiant a supprimer: ");
    scanf("%s", cni);

    int res = chercher(cni);
    if (res != -1) {
        for (int i = res; i < numTotal - 1; i++) {
            etudiants[i] = etudiants[i+1];
        }
        numTotal--;
        printf("etudiant supprimer avec succes.\n");
    } else {
        printf("etudiant ne exit pas.\n");
    }
}

void modifier() {
    char cni[10];
    printf("Entrez le cni de l'etudiant a modifier: ");
    scanf("%s", cni);

    int res = chercher(cni);
    if (res != -1) {
         etudiant *e1 = &etudiants[res];
        float nt1, nt2, nt3;

        printf("modifier le nom actuel: %s: ", e1->nom);
        scanf("%s", e1->nom);

        printf("modifier le prenom actuel: %s: ", e1->prenom);
        scanf("%s", e1->prenom);

        

        printf("modifier le departement actuel: %s: ", e1->departement);
        scanf("%s", e1->departement);

        printf("modifier la premiere nt: ");
        scanf("%f", &nt1);

        printf("modifier la deuxieme nt: ");
        scanf("%f", &nt2);

        printf("modifier la troisieme nt: ");
        scanf("%f", &nt3);

        e1->ntGenerale = (nt1 + nt2 + nt3) / 3.0;

        printf("etudiant modifie avec succes.\n");
    } else {
        printf("etudiant ne exit pas\n");
    }
}

void afficheOne(int y) {
   

        printf("etudiant %d:\n", y + 1);
        printf("  cni: %s\n", etudiants[y].cni);
        printf("  nom: %s\n", etudiants[y].nom);
        printf("  prenom: %s\n", etudiants[y].prenom);
        printf("  date de naissance: %s\n", etudiants[y].dateNaissance);
        printf("  departement: %s\n", etudiants[y].departement);
        printf("  note generale: %.2f\n\n", etudiants[y].ntGenerale);

}

    void afficherEtudiant(){
      char x[10];

      printf("enter le cni de etudiant");
       scanf("%s" , x);
       int res=chercher(x);
       if (res != -1) {
        afficheOne(res);
       }else{

        printf("cette cni ne exit pas\n");

       }
      

    }


    void afficheDepartement(){
        int x;
        printf("pour le departement:enter 1 pour physique - 2 pour math - 3 pour chimie ");
        scanf("%d", &x);
        for(int i=0 ; i<numTotal ; i++){

            if(strcmp(etudiants[i].departement, listeD[x-1])==0){
                afficheOne(i);
            }
        }
    }

        void  moyenneGenerale(){
            float MDP=0;
            int NEDP=0;
            float MDM=0;
            int NEDM=0;
            float MDC=0;
            int NEDC=0;
            float MEU=0;
            
            

            for(int i=0 ; i<numTotal ;i++ ){
                if(strcmp(etudiants[i].departement , listeD[0])==0){ //physique
                MDP+=etudiants[i].ntGenerale;
                MEU+=etudiants[i].ntGenerale;
                NEDP++;

                }
                else if(strcmp(etudiants[i].departement , listeD[1])==0){ // math

                MDM+=etudiants[i].ntGenerale;
                MEU+=etudiants[i].ntGenerale;
                NEDM++;
                }else{
                    MDC+=etudiants[i].ntGenerale;
                    MEU+=etudiants[i].ntGenerale;
                    NEDC++;
                }

            }
            printf("moyenne de departement de physique :%f \n" , MDP/NEDP);
            printf("moyenne de departement de math :%f \n" , MDM/NEDM);
            printf("moyenne de departement de chimie :%f \n" , MDC/NEDC);
            printf("moyenne de departement de unversite :%f \n" , MEU/numTotal);
            

            

        }

    void afficheTrieParNom() {
    for (int i = 1; i < numTotal; ++i) {
        etudiant key = etudiants[i];
        int j = i;
        while (j > 0 && strcmp(etudiants[j - 1].nom, key.nom) > 0) {
            etudiants[j] = etudiants[j - 1];
            --j;
        }
        etudiants[j] = key;
    }

    for(int i = 1; i < numTotal; ++i) {

         afficheOne(i);

    }
}
void afficheTrieParMoyG() {
    for (int i = 1; i < numTotal; ++i) {
        etudiant key = etudiants[i];
        int j = i;
        while (j > 0 && etudiants[j - 1].ntGenerale> key.ntGenerale) {
            etudiants[j] = etudiants[j - 1];
            --j;
        }
        etudiants[j] = key;
    }

    for(int i = 1; i < numTotal; ++i) {

         afficheOne(i);

    }
}
void afficheTrieParState() {
    int x10[50];
    int y9[50];
   
    int reussiteCount = 0;
    int pasReussiteCount = 0;

    // Separate students into passed and failed
    for (size_t i = 0; i < numTotal; ++i) {
        if (etudiants[i].ntGenerale >= 10) {
            x10[reussiteCount++] = i;
        } else {
            y9[pasReussiteCount++] = i;
        }
    }
     printf("l'etudiant qui reussit ")
    for(int i=0;i<reussiteCount;i++){

        afficheOne(x10[i]);
    }
 printf("\n \n \n l'etudiant qui ne reussit pas")
    for(int i=0;i<pasReussiteCount;i++){
        afficheOne(y9[i]);
    }



}
int main() {
    int choix;

    do {
        printf("1. ajouter un etudiant\n");
        printf("2. afficher un etudiant\n");
        printf("3. supprimer un etudiant\n");
        printf("4. modifier un etudiant\n");
         printf("5. pour affiche les moyennes generale \n");
         printf("6. afficher un etudiant par departement\n");
         printf("7. pour affiche les etudiants par oreder de A à Z \n");
         printf("8. pour affiche les etudiants par oreder de moyenne générale\n");
          printf("10. pour affiche les etudiants par state \n");
        printf("9. quitter\n");
        printf("entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajoute();
                break;
            case 2:
                afficherEtudiant();
                break;
            case 3:
                supprime();
                break;
            case 4:
                modifier();
                break;
            case 5:
                moyenneGenerale();
                break;
            case 6:
                afficheDepartement();
                break;
            case 7:
                afficheTrieParNom();
                break;
            case 8:
                afficheTrieParMoyG();
                break;
            case 10:
                afficheTrieParState();
                break;
            case 9:
                printf(" fin de programme  \n");
                break;
            default:
                
                break;
        }
    } while (choix != 5);

    return 0;
}
