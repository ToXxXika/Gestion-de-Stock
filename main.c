#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
typedef struct Categorie {
 int idCat;
 char NomCat[50];
}Categorie;
typedef struct type{
  int idType ;
  char NomType[50] ;
  Categorie Cat ;
}type;
typedef struct MaDate{
 int JJ;
 int MM;
 int AA;
}MaDate;
typedef struct Produit{
int id ;
char Nom[50] ;
type Typ ;
MaDate DateExpiration ;
}Produit;
int Nbcat=0 ;
int NbType=0 ;
Categorie TabCat[20] ;
type  TabType[50];
Produit Stock[100][50];
int TabQte[50];
void InitCat( struct Categorie *A){
    printf("Donner ID Cat \n");
    scanf("%d",&A->idCat);
    printf("Donner Nom Cat \n");
    scanf("%s",&A->NomCat);
}
void InitType(type *B){
    printf("Donner id Type \n");
    scanf("%d",&B->idType);
    printf("Donner Nom Type \n");
    scanf("%s",&B->NomType);
    printf(" **** Vers Categorie **** \n");
    InitCat(&B->Cat);
}
void InitDate(MaDate *MD){
  do{
    printf("Donner le jour \n");
    scanf("%d",&MD->JJ);
  }while((MD->JJ<1) && (MD->JJ>31));
  do{
    printf("Donner le Mois \n ");
    scanf("%d",&MD->MM);
  }while((MD->MM<1) && (MD->MM>12));
  do{

  }while((MD->AA<1000) && (MD->AA>9999));
}
void InitProd(Produit *P){
    printf("Donner id Produit \n");
    scanf("%d",&P->id);
    printf("Donner le nom du produit");
    scanf("%s",&P->Nom);
    InitType(&P->Typ);
    InitDate(&P->DateExpiration);
    printf("Product Loaded : %d\n",P->id);
    printf("Product Loaded Nom : %s\n",P->Nom);
}

/* Remplissage du Tableau Categorie */
void RemplirTab(struct Categorie A, Categorie TabCat[20]){
    int Res=-1,i=0 ;
    if(Nbcat<20){
        printf("NomCat : %s",A.NomCat);
       while(i<Nbcat+1){
           Res = strcmp(TabCat[i].NomCat,A.NomCat);
           printf(" Res = %d",Res);
           if(Res == 0){
               printf("Categorie deja ajoute \n");
               break;
           }else{
             i++;
           }
       }
        if(Res == -1){
            TabCat[Nbcat]=A;
            Nbcat++;
            printf("Categorie Ajoutee avec success \n");
        }
    }
    }
void AjouterType(struct type T,type TabType[50]){
    int Res=-1,i=0;int j=0;
    int Res2=-1;
      while(i<Nbcat){
          Res=strcmp(TabCat[i].NomCat,T.Cat.NomCat);
          if(Res==0){
              printf("Categorie deja ajoutee");
              break;
          }else{
              i++;
          }
      }
      if(Res==-1){
          if(NbType<50){
              while (j<NbType+1){
                Res2= strcmp(TabType[j].NomType,T.NomType);
                if(Res2==0){
                    printf("Type deja Ajoutee");
                    break;
                } else{
                    j++;
                }
              }
              if(Res2==-1){
                  TabType[NbType]=T;
                  NbType++;
                  printf("Type Ajoutee avec success \n");
              }
          }
      }

}

void RemplirTabQte(){
    char ch[50]="";
    int i;
    int j=0;
    int Compteur=0;
    ch[50]=TabType[0].NomType;
     for(i=1;i<NbType;i++){
         int Res= strcmp(TabType[i].NomType,ch);
         if(Res == 0){
             Compteur++;
         }
     }
     TabQte[j]=Compteur;
     j++;
}
/* Cette Fonction est utilisée pour remplir le Tableau Des Produits */
void AjouterPdt( Produit P){
   /* Cette partie pour la recherche dans quelle Case est le Type de Produit */
   int j=0;
    printf("Nbrtype: %d \n",NbType);
    for(int i=0;i<NbType;i++){
        if(strcmp(TabType[i].NomType,P.Typ.NomType)==0){
            printf("Type de Produit Trouve \n ");
             j=i;
            break;
        }
    }
    printf("j : %d \n",j);
    for(int k=0;k<100;k++){
        if(Stock[k][j].id==0){
          Stock[k][j]=P;
            printf("Stock [%d][%d] : %d \n",k,j,P.id);
            printf("Produit Ajoute au Stock \n");
            TabQte[j]=TabQte[j]+1;
            printf("TabQte[%d]= %d \n",j,TabQte[j]);
            break;
        }
    }
}
/* Cette Fonction est utilisée pour remplir */
void SupprimerCat(Categorie C ){

    int i=0,j =0;
    while (i<3){
        if(strcmp(TabCat[i].NomCat,C.NomCat)==0){
            printf("Categorie N");
             j=i;
            break;
        }else {
            i++;

        }

    }
    // Suppression d'un Element trouvé dans le Tableau
    for( i=j;i<3;i++){
        TabCat[i]=TabCat[i+1];
    }
    Nbcat--;
}
void SupprimerType(type T){
    int Compteur =0;  // ce Compteur est utilisé pour tester le nombre de produits qui ont le un type Spécifié
   for(int i=0;i<100;i++){
       for(int j=0;j<50;j++){
           if(strcmp(Stock[i][j].Typ.NomType,T.NomType)==0){
             Compteur++;
           }
       }
   }
   int k=0;
   int k1=0;
    if(Compteur==0){
        while (k<NbType){
            if(strcmp(TabType[k].NomType,T.NomType)==0){
                printf("Type Trouvé dans la Case : %d",k);
                k1=k;
                break;
            }
        }
        for(int L=k1;L<NbType;L++){
            TabType[L]=TabType[L+1];
        }
        NbType--;
    }
}
void SupprimerPdt(Produit P){
    printf("Produit Nom : %s \n",P.Nom);
    int K=0; // this variable is used to store Product column
    int L=0;
   for(int i=0;i<100;i++){
       for(int j=0;i<50;i++){
           if(Stock[i][j].id==P.id){
              K=j;
              L=i;
              break;
           }
       }
   }
   // Mise a jour du Stock
   if (TabQte[K]>10){
    for(int i=L;i<100;i++){
        Stock[i][K]=Stock[i+1][K];
    }

    //Mise a jour du Quantité
    TabQte[K]=TabQte[K]-1;
       printf("Produit Supprimé \n");
   }else printf("Quantite de produit < 10 !");

}
void MainMenu(){
 int fin;

   fin = 0;
   while(!fin)
   {
      int c;

      /* affichage menu */
      printf("1- Gestion du Stock \n"
             "2- Vente et Statistique\n"
             "3.Quitter \n");

      c = getchar();

      /* suppression des caracteres dans stdin */
      if(c != '\n' && c != EOF)
      {
         int d;
         while((d = getchar()) != '\n' && d != EOF);
      }

      switch(c)
      {
         case '1':
            printf("Choix 1\n");
            break;

         case '2':
            printf("Choix 2\n");
            break;
         case '0':
             exit(0);
             break;

         default:
            printf("Choix errone\n");
      }
   }

}
/* Pour Menu Gestion Stock */
void AfficherStock(Stock){
    printf("Etat du Stock :");
    printf("Categorie  Type    Qte  id-Pdt    Date-Exp");
    printf("____________________________________________");

}
char * LoadDateSysteme(){
    time_t rawtime ;
    struct tm* timeinfo;
    static char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,80, "%m/%d/%Y.",timeinfo);

    return buffer ;
}
struct Produit VendreProduit(int type){
/*   for (int i = 0; i <NbType ; i++) {
        if(TabType[i].idType==P.Typ.idType){
            x=i;
            break;
        }
    }*/
    printf("Type: %d \n",type);
    int  x=type; // x va prendre l' idType
    int MMx,AAx,JJx;
    MMx=Stock[0][x].DateExpiration.MM;
    JJx=Stock[0][x].DateExpiration.JJ;
    AAx=Stock[0][x].DateExpiration.AA;
    printf("JJx: %d \n",JJx);
    printf("MMx: %d \n",MMx);
    printf("AAx: %d \n",AAx);
    char p[50] ;
    strcpy( p,LoadDateSysteme());
    printf("%s",p);
    int i=1;
    int AA,MM,JJ;
    printf("i1: %d \n",i);
    while(i<100) {
         AA= Stock[i][x].DateExpiration.AA;
         MM= Stock[i][x].DateExpiration.MM;
         JJ= Stock[i][x].DateExpiration.JJ;
         printf("AAx: %d \n",AAx);
        printf("AA : %d \n",AA);
        if (AA > AAx) {
            printf("if 1 \n");
            printf("i: %d \n",i);
            printf("x: %d \n",x);
            printf("Produit Nom : %s",Stock[i][x].Nom);
            return Stock[i][x];

        }
        else if ((AA < AAx)&&(MM > MMx)) {
            printf("if 2 \n");
            return Stock[i][x];
            break;
        }
        else if (JJ > JJx) {
            printf("if 3 \n");
            return Stock[i][x];
        }else i++;

    }

}
bool FichierProduit(struct Produit P){
    FILE  *fichier ;
     if ((fichier =fopen("C:\\Users\\mabro\\Desktop\\Projet\\Produit.txt","w+"))== NULL){
         printf("Erreur dans l'ouverture de fichier Produit \n");
         exit(1);
     }else{
         int i =1;
         printf("\n");
         fprintf(fichier,"%d\t%s\t%d\t%s\t%d\t%s\t%s",P.id,P.Nom,P.Typ.idType,P.Typ.NomType,P.Typ.Cat.idCat,P.Typ.Cat.NomCat,LoadDateSysteme());
         printf("Fichier done");
         return 1;
     }
    return 0 ;

}
/* Cettee fonction est utilisée pour trouver la date Systeme  */

void TestTables(){
    char NomType[50] = "Kamel";
    char NomType2[50] = "Ahmed";
    char NomType3[50] = "Oussema";
    char NomCat[50]="Potato";
    char NomCat2[50]="Tomato";
    char NomCat3[50]="Felfel";
    strcpy(TabCat[0].NomCat,NomCat);
    strcpy(TabCat[1].NomCat,NomCat2);
    strcpy(TabCat[2].NomCat,NomCat3);
    strcpy(TabType[0].NomType,NomType);
    strcpy(TabType[1].NomType,NomType2);
    strcpy(TabType[2].NomType,NomType3);
    TabType[0].idType=1;
    TabType[1].idType=2;
    TabType[2].idType=3;
    TabCat[0].idCat=1;
    TabCat[1].idCat=2;
    TabCat[2].idCat=3;
   NbType=3;
   Nbcat=3;
   struct Produit *p ;
   struct Produit *p2;
    p=(struct Produit*) malloc(sizeof (struct Produit));
    p->id=5;
    strcpy(p->Nom,"Chips");
    strcpy(p->Typ.NomType,"Ahmed");
    p->Typ.idType=2;
    p->DateExpiration.JJ=05;
    p->DateExpiration.MM=05;
    p->DateExpiration.AA=2005;
    p2=(struct Produit*) malloc(sizeof (struct Produit));
    p2->id=4;
    strcpy(p2->Nom,"Chips");
    strcpy(p2->Typ.NomType,"Ahmed");
    p2->Typ.idType=2;
    p2->DateExpiration.JJ=07;
    p2->DateExpiration.MM=06;
    p2->DateExpiration.AA=2008;
    Stock[0][2]=*p;
    Stock[1][2]=*p2;

}
int main()
{
    /* Declaration des Pointeurs et Allocations Dynamiques */
     struct Categorie *A;
     struct type *B ;
     struct Produit *P;

    A= (struct Categorie*) malloc(sizeof(struct Categorie));
    B= (struct type*) malloc(sizeof(struct type));
    P= (struct Produit*) malloc(sizeof (struct Produit));

    /* for (int i=0;i<2;i++){


         InitCat(A);
         RemplirTab(*A,TabCat);
     }*/
    /* for(int i=0;i<2;i++){
         InitType(B);
         AjouterType(*B,TabType);
         printf("********* NEXT *********** \n ");
     }



    InitProd(P);
    AjouterPdt(*P);
    InitType(B);
    SupprimerType(*B);
*/
  /*  TestTables();
    for(int i=0;i<=2;i++){
        printf("NomCat: %s \n",TabCat[i].NomCat);
        printf("IdCat: %d \n",TabCat[i].idCat);
    }
    InitCat(A);
    SupprimerCat(*A);
    for(int i=0;i<2;i++){
        printf("NomCat: %s \n",TabCat[i].NomCat);
        printf("IdCat: %d \n",TabCat[i].idCat);
    }
*/

    TestTables();
    FichierProduit(VendreProduit(2));
    return 0;
}
