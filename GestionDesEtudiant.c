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
  
int numTotal = 10;
// chercher par CNI
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
     
         printf("pour les departement:enter 1 pour physique - 2 pour math - 3 pour chimie ");

        scanf("%d", &x);
         strcpy(e.departement, listeD[x-1]); 

        printf("Entrez la  note GENERALE: ");

         scanf("%f", &e.ntGenerale );


        

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
        
        
        printf("modifier le nom actuel: %s: ", etudiants[res].nom);
        scanf("%s", etudiants[res].nom);

        printf("modifier le prenom actuel: %s: ", etudiants[res].prenom);
        scanf("%s", etudiants[res].prenom);

        int x;

        printf("modifier le departement actuel:enter 1 pour physique - 2 pour math - 3 pour chimie  ",&x);

        strcpy(etudiants[res].departement,listeD[x-1]);
         

        scanf("%s", etudiants[res].departement);

        printf("modifier la note generale: ");
        scanf("%f", &etudiants[res].ntGenerale);


        

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
        printf("pour les departement:enter 1 pour physique - 2 pour math - 3 pour chimie ");
        scanf("%d", &x);
        for(int i=0 ; i<numTotal ; i++){

            if(strcmp(etudiants[i].departement, listeD[x-1])==0){
                afficheOne(i);
            }
        }
    }

        void  moyenneGenerale(){
            float MDPhysique=0;
            int NEDPhysique=0;
            float MDMath=0;
            int NEDMath=0;
            float MDChimie=0;
            int NEDChimie=0;
            float MEUniversitie=0;
            
            

            for(int i=0 ; i<numTotal ;i++ ){
                if(strcmp(etudiants[i].departement , listeD[0])==0){ //physique
                MDPhysique+=etudiants[i].ntGenerale;
                MEUniversitie+=etudiants[i].ntGenerale;
                NEDPhysique++;

                }
                else if(strcmp(etudiants[i].departement , listeD[1])==0){ // math

                MDMath+=etudiants[i].ntGenerale;
                MEUniversitie+=etudiants[i].ntGenerale;
                NEDMath++;
                }else{
                    MDChimie+=etudiants[i].ntGenerale;
                    MEUniversitie+=etudiants[i].ntGenerale;
                    NEDChimie++;
                }

            }
            printf("\n\nmoyenne de departement de physique :%f \n" , MDPhysique/NEDPhysique);
            printf("moyenne de departement de math :%f \n" , MDMath/NEDMath);
            printf("moyenne de departement de chimie :%f \n" , MDChimie/NEDChimie);
            printf("moyenne  de unversite :%f \n\n\n" , MEUniversitie/numTotal);
            

            

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

    for(int i = 0; i < numTotal; ++i) {

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

    for(int i = 0; i < numTotal; ++i) {

         afficheOne(i);

    }
}
void afficheTrieParState() {
    int x10[50];
    int y9[50];
   
    int reussiteCount = 0;
    int pasReussiteCount = 0;

    
    for (size_t i = 0; i < numTotal; ++i) {
        if (etudiants[i].ntGenerale >= 10) {
            x10[reussiteCount++] = i;
        } else {
            y9[pasReussiteCount++] = i;
        }
    }
     printf("\n\n\nl'etudiant qui reussit \n ");
    for(int i=0;i<reussiteCount;i++){

        afficheOne(x10[i]);
    }
 printf("\n \n \n l'etudiant qui ne reussit pas \n");
    for(int i=0;i<pasReussiteCount;i++){
        afficheOne(y9[i]);
    }



}
void Statistiques(){
    printf(" le nombre total d'etudiants inscrits : %d  \n" , numTotal);
            int NEDP[2]={0};
            int NEDM[2]={0};
            int NEDC[2]={0};
    for(int i=0 ; i<numTotal ;i++ ){
                if(strcmp(etudiants[i].departement , listeD[0])==0){ //physique
               
                NEDP[0]++;
                if (etudiants[i].ntGenerale>=10)
                {
                   NEDP[1]++;
                }
                

                }
                else if(strcmp(etudiants[i].departement , listeD[1])==0){ // math

               
                NEDM[0]++;
                if (etudiants[i].ntGenerale>=10)
                {
                   NEDM[1]++;
                }
                }else if(strcmp(etudiants[i].departement , listeD[2])==0){
                    
                    NEDC[0]++;
                    if (etudiants[i].ntGenerale>=10)
                {
                   NEDC[1]++;
                }
                }

            }
             printf("\n\n############################################## \n" );
            printf("le nombre d'etudiants dans chaque departement \n" );
            printf("  le nombre d'etudiants dans la departement de physique : %d \n" , NEDP[0] );
            printf("  le nombre d'etudiants dans la departement de math : %d \n" ,NEDM[0]);
            printf("  le nombre d'etudiants dans la departement de chimie : %d\n" ,NEDC[0]);


            printf("\n\n############################################## \n" );
             printf("le nombre d'etudiants reussit dans chaque departement \n" );
            printf("  le nombre d'etudiants dans la departement de physique : %d \n" , NEDP[1] );
            printf("  le nombre d'etudiants dans la departement de math : %d \n" ,NEDM[1]);
            printf("  le nombre d'etudiants dans la departement de chimie : %d\n\n\n\n" ,NEDC[1]);

}

void StatistiquesSeuil(){
       
     float seuil;
    
    printf("\n entrer un certain seuil \n");
    scanf("%f",&seuil);
    printf("les etudiants ayant une moyenne generale superieure a  seuil %d. \n" ,seuil);
    for (int i = 0; i < numTotal; i++)
    {
        if (etudiants[i].ntGenerale>=seuil)
        {
           afficheOne(i);
        }
        
           
    }
   
   

}
void etudiantReussi(){
     int nombreReussi;
    for (int i = 0; i < numTotal; i++)
    {
        
        if (etudiants[i].ntGenerale>=10)
        {
          afficheOne(i);
        }
           
    }
   
    



}

void les3PremierNotes(){
       for (int i = 1; i < numTotal; ++i) {
        etudiant key = etudiants[i];
        int j = i;
        while (j > 0 && etudiants[j - 1].ntGenerale> key.ntGenerale) {
            etudiants[j] = etudiants[j - 1];
            --j;
        }
        etudiants[j] = key;
    }
     
    printf("\nles 3 etudiants ayant les meilleures 3 notes.\n");
     afficheOne(numTotal-1);
     afficheOne(numTotal-2);
     afficheOne(numTotal-3);
    
   

}
void afficheStatistiques(){
    int x;
        printf("  1. Afficher les 3 étudiants ayant les meilleures notes\n");
        printf("  2. Afficher le nombre d'étudiants dans chaque département ,et le nombre d'étudiants ayant réussi dans chaque département\n");
        printf("  3. Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil \n");
         printf("  4. Afficher les étudiants selon leur statut de réussite \n");
          scanf("%d" , &x);

        switch (x) {
            case 1:
                les3PremierNotes();
                break;
            case 2:
                Statistiques();
                break;
            case 3:
                StatistiquesSeuil();
                break;
            case 4:
               etudiantReussi();
                break;
                default:
                
                break;
        }
        
        
}


void affiche(){
    int x;
        printf("  1. afficher un etudiant\n");
        printf("  2. afficher les etudiant d'un departement\n");
        printf("  3. afficher les etudiant  par order A _ Z \n");
        printf("  4. afficher les etudiant  par les moyeenes\n");
        printf("  5. afficher les etudiant  par state\n");
       

        scanf("%d" , &x);

        switch (x) {
            case 1:
                afficherEtudiant();
                break;
            case 2:
                afficheDepartement();
                break;
            case 3:
                afficheTrieParNom();
                break;
            case 4:
               afficheTrieParMoyG();
                break;
            case 5:
               afficheTrieParState();
                break;

             default:
                
                break;
        }






}




int main() {
    etudiants[0] = (etudiant){"CNI001", "HAMZA", "HAMZA", "2000-01-15", "physique", 12.5};
    etudiants[1] = (etudiant){"CNI002", "ISMAIL", "ISMAIL", "1999-04-22", "math", 14.3};
    etudiants[2] = (etudiant){"CNI003", "AHMED", "AHMED", "2001-11-05", "chimie", 8.2};
    etudiants[3] = (etudiant){"CNI004", "MOHAMMED", "MOHAMMED", "2000-03-09", "physique", 16.0};
    etudiants[4] = (etudiant){"CNI005", "AMINA", "AMINA", "1998-07-25", "math", 10.8};
    etudiants[5] = (etudiant){"CNI006", "OUSSAMA", "OUSSAMA", "2001-10-30", "chimie", 15.7};
    etudiants[6] = (etudiant){"CNI007", "MERIEM", "MERIEM", "1999-12-12", "physique", 3.0};
    etudiants[7] = (etudiant){"CNI008", "YASSIN", "YASSIN", "2000-08-20", "math", 11.0};
    etudiants[8] = (etudiant){"CNI009", "YOUSSEF", "YOUSSEF", "1999-06-17", "chimie", 13.5};
    etudiants[9] = (etudiant){"CNI010", "AYMEN", "AYMEN", "2001-02-14", "physique", 10};

    int choix;

    do {
        printf("1. ajouter un etudiant\n");
        printf("2. afficher un etudiant\n");
        printf("3. supprimer un etudiant\n");
        printf("4. modifier un etudiant\n");
        printf("5. pour affiche les moyennes generale \n");
        printf("6. pour affiche les affiche Statistiques\n");
         
        printf("7. quitter\n");
        printf("entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajoute();
                break;
            case 2:
                affiche();
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
                afficheStatistiques();
                
                
            default:
                
                break;
        }
    } while (choix != 7);

    return 0;
}
