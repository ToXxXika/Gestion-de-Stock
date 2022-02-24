#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Categorie
{
    int idCat;
    char NomCat[50];
}Categorie;

typedef struct MaDate
{
    int JJ;
    int MM;
    int AA;
}MaDate;

typedef struct Type
{
    int idType;
    char NomType[50];
    Categorie Cat;
}Type;

typedef struct Produit
{
    int id;
    char Nom[50];
    Type Typ;
    MaDate Date_expiration;
}Produit;

void Initcat(Categorie *cat)
{
    printf("donner id de la categorie \n");
    scanf("%d",&(cat->idCat));
    printf("donner nom de la categorie \n");
    scanf("%s",(cat->NomCat));

}

void InitType (Type *tp)
{
    printf("donner id de type \n");
    scanf("%d",&(tp->idType));
    printf("donner nom de type \n");
    scanf("%s",(tp->NomType));
    Initcat(&(tp->Cat));

}

void InitDate (MaDate *Date)
{
    do{
        printf("donner l annee \n");
        scanf("%d",&(Date->AA));
    }while(((Date->AA)>9999)||((Date->AA)<1000));

    do{
        printf("donner le mois \n");
        scanf("%d",&(Date->MM));
    }while(((Date->MM)>12)||((Date->MM)<1));


    if((Date->MM)==2)
    {if(((Date->AA)%4)==0)
        {do
            {
                printf("donner le jour \n");
                scanf("%d",&(Date->JJ));
            }while(((Date->JJ)>29)||((Date->JJ)<1));
        }
        else
        {do
            {
                printf("donner le jour \n");
                scanf("%d",&(Date->JJ));
            }while(((Date->JJ)>28)||((Date->JJ)<1));
        }
    }
    else if(((Date->MM)>=1)&&((Date->MM)<8))
    {if(Date->MM%2==0)
        {do
            {
                printf("donner le jour \n");
                scanf("%d",&(Date->JJ));
            }while(((Date->JJ)>30)||((Date->JJ)<1));
        }
        else{do
            {
                printf("donner le jour \n");
                scanf("%d",&(Date->JJ));
            }while(((Date->JJ)>31)||((Date->JJ)<1));
        }
    }
    else
    {if(((Date->MM)%2)==0)
        {do
            {
                printf("donner le jour \n");
                scanf("%d",&(Date->JJ));
            }while(((Date->JJ)>31)||((Date->JJ)<1));
        }
        else{do
            {
                printf("donner le jour \n");
                scanf("%d",&(Date->JJ));
            }while(((Date->JJ)>30)||((Date->JJ)<1));}
    }
}

void InitPdt (Produit *Pdt)
{
    printf("donner id de produit \n");
    scanf("%d",&(Pdt->id));
    printf("donner nom de produit \n");
    scanf("%s",(Pdt->Nom));
    InitType (&(Pdt->Typ));
    printf("Donner la date d'expiration du produit: \n");
    InitDate (&(Pdt->Date_expiration));

}


void AjouterCat(Categorie*TabCat, int *NbCat)
{
    int idCat;
    int s;
    if(*NbCat>=20)
    {
        printf("\t Ajout impossible:espace du stockage saturé!\n");
    }
    else
    {
        printf("\t Donner id de la catégorie a ajouter \n");
        scanf("%d",&idCat);
        for(int i=0;i<*NbCat;i++)
        {
            if(TabCat[i].idCat==idCat)
            {
                s=0;
            }
            else
            {
                s=1;
            }

        }
        if (s==0)
        {
            printf("\t catégorie existe deja \n");
        }
        else
        {Initcat(&TabCat[*NbCat]);
            (*NbCat)++;
        }
    }
}


void AjouterTyp(Type* TabType, int *NbTyp,int NbCat ,Categorie* TabCat)
{
    Type tp;
    int s=0;
    int y=0;
    int i=0;
    int a=0;// compteur pour le tableau TABCAT

    if((*NbTyp)>=50)
    {
        printf("\t Ajout impossible:espace du stockage saturé!\n");
    }
    else
    {
        printf("\t Donner les informations du type a ajouter \n");
        InitType (&tp);
        while(i<NbCat){
            if(tp.Cat.idCat==TabCat[i].idCat){
                printf("Categorie Trouvé");
                s=1;
                break ;
            } else{
                i++;
            }
        }
        if(i==NbCat){
            printf("Categorie non trouvé");
        }else {
            if (s == 1) {
                while (y < (*NbTyp)) {
                    if (TabType[y].idType == tp.idType) {
                        printf("Type Existe \n");
                        break;
                    } else {
                        y++;
                        a = 1;
                    }
                }
                if (a == 1) {
                    TabType[*NbTyp] = tp;
                    NbTyp++;
                    printf("Type Ajoutee avec Success \n");
                }
            }
        }

    }

}

/*void AjouterPdt (Produit* Stock,int* TabQte,Type* TabType,int NbTyp)
{
Produit Pdt;
int i=0;
int j=0;
int f=0;
int g=0;
printf ("\t Donner les information de produit à ajouter \n");
InitPdt (&Pdt);
while (i<=NbTyp){
    if (Pdt.Typ.idType== TabType[i].idType)
        while((j<=TabQte[i])&&(TabQte[i]<100))
             {if(( Pdt.id) ==(Stock[j][i].id) )
             {printf("\t Ajout impossible,produit deja existant \n");
             break;}
             else{j++;
                 f = 1;}
             }
        if (f==1){
        Stock[TabQte[i]+1][i] = Pdt;
        TabQte[i]++;
        printf("Produit Ajoutee avec Success \n");
        }
    else
        {i++;
        g=1;}
    if (g==1)
    {
     printf("\t pas de type correspondant  \n");
    }
}
}*/

void SupprimerCat(Type* TabType, int *NbTyp,int *NbCat ,Categorie* TabCat)
{
    int idCat;
    int i=0;
    int a=0;
    int j=0;
    int b=0;
    int x=0;
    printf("\t Donner id de la catégorie a supprimer \n");
    scanf("%d",&idCat);
    while(i<=(*NbTyp))
    {
        if(idCat == (TabType[i].Cat.idCat))
        {
            printf("\t categorie existe encore \n");
            break;
        }
        else
        {i++;
            a=1;}
    }

    if( a == 1 )
    {
        while(j<=(*NbCat))
        {if(idCat == (TabCat[j].idCat))
            {
                printf("\t catégorie trouvé \n ");
                b=j;
                break;
            }
            else
            {
                j++;
            }
        }
        for(x=b;x<(*NbCat);x++)
        {
            TabCat[x]=TabCat[x+1];
        }
        printf("suppression avec Success \n");
    }

}

/*void SupprimerTyp(Type* TabType, int *NbTyp,Produit* Stock)
 {
  int idtyp;
  int i=0;
  int a=0;
  int j=0;
  int b=0;
  int x=0;
  printf("\t Donner id du type a supprimer \n");
  scanf("%d",&idtyp);
  while(i<=(*NbTyp))
  {
      if(idtyp == (Stock[0][i].Typ.idType))
      {
          printf("\t Type existe encore \n");
          break;
      }
      else
        {i++;
         a=1;}
  }

  if( a == 1 )
  {
      while(j<=(*NbTyp))
        {if(idtyp == (TabType[j].idType))
          {
              printf("\t type trouvé \n ");
              b=j;
              break;
          }
          else
          {
              j++;
          }
        }
     for(x=b;x<(*NbTyp);x++)
     {
       TabType[x]=TabType[x+1];
     }
      printf("suppression avec Success \n");
      NbTyp--;
  }

 }

void SupprimerPdt(Type TabType, int NbTyp,Produit* Stock,int* TabQte)
{
  int idtpd;
  int idpd;
  int i=0;
  int j=0;
  int x=0;
  int a=0;
  int b=0;

  printf("\t Donner id du type de type a supprimer \n");
  scanf("%d",&idtpd);
  printf("\t Donner id du produit a supprimer \n");
  scanf("%d",&idpd);

  while(i<=(NbTyp))
        {if(idtpd ==(TabType[i].idType))
          {
              printf("\t type trouvé \n ");
              a=i;
              break;
          }
          else
          {
              i++;
          }
        }
  if(TabQte[a]<=10)
  {
      printf("suppression impossible");
  }
  else
  {
    while(j<=(TabQte[a]))
    {
        if(idpd == (*Stock[j][a].id) )
        {  printf("produit trouvé");
           b=j;
        }
        else
        {
           j++;
        }
   }

   for(x=b;x<TabQte[a];x++)
   {
     Stock[x][a]= Stock[x+1][a];
   }
   TabQte[a]--;

   }


}
*/

void VendrePdt(Type TabType[20], int NbTyp,Produit* Stock[100][50],int* TabQte)
{
    int idt;
    int i=0;
    int a=0;
    int j=0;
    int x=0;
    int b=0;
    printf("\t Donner l' id de type du produit a vendre \n");
    scanf("%d",&idt);
    while(i<=(NbTyp))
    {if(idt ==( TabType[i].idType))
        {
            printf("\t type trouvé \n ");
            a=i;
            break;
        }
        else
        {
            i++;
        }
    }
    MaDate min=Stock[0][a]->Date_expiration;
    while(j<=TabQte[a])
    {
        if(((min.AA)<(Stock[j][a]->Date_expiration.AA))&&((min.JJ)<(Stock[j][a]->Date_expiration.JJ))&&((min.MM)<(Stock[j][a]->Date_expiration.MM))
        {
            min=Stock[j][a].Date_expiration;
            b=j;
        }
                else
        {
            j++;
        }
    }

    for(x=b;x<TabQte[a];x++)
    {
        Stock[x][a]= Stock[x+1][a];
    }
    TabQte[a]--;

    FILE* p=NULL;
    p = fopen("Trace.txt","a");
    if( p == NULL )
    {
        printf("\t le fichier n'existe pas. \n");
    }
    else
    {
        fprintf(p,"%d %s %d %s %d %s %d/%d/%d", Stock[b][a].id, Stock[b][a].Nom, Stock[b][a].Typ.id, Stock[b][a].Typ.NomType, Stock[b][a].Typ.Cat.idCat, Stock[b][a].Typ.Cat.NomCat, min.JJ, min.MM, min.AA );
        fclose(p);
    }





}
int main()

{int NbCat=2;
    Categorie TabCat[20];
    Produit Stock[100][50];
    int NbTyp=2;
    Type TabType[50];
    Categorie  Cat ;
    for(int i=0;i<2;i++){
        Initcat(&TabCat[i]);
    }
    for(int j=0;j<2;j++){
        InitType(&TabType[j]);
    }
    /* AjouterTyp(TabType,&NbTyp,NbCat,TabCat);*/
    SupprimerCat(TabType,&NbTyp,&NbCat ,TabCat);



    printf("******************************************* \n ********      Bienvenue     *************** \n ******************************************* \n");
    int choix;
    printf("*Veuillez choisir une option:               * \n");
    printf("*1-Gestion du stock                         * \n");
    printf("*2-Vente et statistiques                    * \n");
    do
    { printf("*>> Tapez votre choix:                      * \n");
        scanf ("%d", &choix);
        if(choix>2 || choix<0)
            printf("votre choix doit etre Compris entre 1 et 2 \n");
    }while(choix>2 || choix<0);

    int choix1;
    int choix2;
    switch(choix)
    {
        case 1:

            printf("1- Gestion des Cat馮ories   \n");
            printf("2- Gestion des Types \n");
            printf("3- Gestion des Produits \n");
            printf("4- Affichage du Stock \n");
            printf("5- Retour Menu Principal");
            do
            { printf("*>> Tapez votre choix:                      * \n");
                scanf ("%d", &choix1);
                if(choix1>5 || choix1<0)
                    printf("votre choix doit etre Compris entre 1 et 5 \n");
            }while(choix1>5 || choix1<0);

            break;

        case 2:

            printf("1- Vente de Produits \n");
            printf("2- Statistiques \n");
            printf("3- Retour Menu Principal");
            do
            { printf("*>> Tapez votre choix:                      * \n");
                scanf ("%d", &choix2);
                if(choix2>3 || choix2<0)
                    printf("votre choix doit etre Compris entre 1 et 3 \n");
            }while(choix2>3 || choix2<0);
            break;

        case 3:
            exit(0);

    }

    int choix1_1;
    switch(choix1)
    {    case 1:
            printf("1- Ajout d置ne nouvelle Cat馮orie \n");
            printf("2- Suppression d置ne Cat馮ories \n");
            printf("3- Retour Menu Gestion du stock");
            printf("4- Retour Menu Principal");
            do
            {   printf(">> Tapez votre choix:                    \n ");
                scanf ("%d", &choix1_1);
                if(choix1_1>4 || choix1_1<0)
                    printf("votre choix doit etre Compris entre 1 et 4 \n");
            }while(choix1_1>4 || choix1_1<0);

            break;

        case 2:
            printf("1- Ajout d置n nouveau Type \n");
            printf("2- Suppression d置n Type \n");
            printf("3- Retour Menu Gestion du stock");
            printf("4- Retour Menu Principal");
            do
            {   printf(">> Tapez votre choix:                    \n ");
                scanf ("%d", &choix1_1);
                if(choix1_1>4 || choix1_1<0)
                    printf("votre choix doit etre Compris entre 1 et 4 \n");
            }while(choix1_1>4 || choix1_1<0);

            break;

        case 3:
            printf("1- Ajout d置n nouveau Produit \n");
            printf("2- Suppression d置n Produit \n");
            printf("3- Retour Menu Gestion du stock");
            printf("4- Retour Menu Principal");
            do
            {   printf(">> Tapez votre choix:                    \n ");
                scanf ("%d", &choix1_1);
                if(choix1_1>4 || choix1_1<0)
                    printf("votre choix doit etre Compris entre 1 et 4 \n");
            }while(choix1_1>4 || choix1_1<0);

            break;

        case 4:
            printf("1- Affichage du Stock \n");
            printf("2- Retour Menu Gestion du stock");
            printf("3- Retour Menu Principal");
            do
            {   printf(">> Tapez votre choix:                    \n ");
                scanf ("%d", &choix1_1);
                if(choix1_1>3 || choix1_1<0)
                    printf("votre choix doit etre Compris entre 1 et 3 \n");
            }while(choix1_1>3 || choix1_1<0);

            break;

        case 5:
            exit(0);
    }


    int choix2_1;
    switch(choix2)
    {
        case 1:
            printf("1- Vente de Produits \n");
            printf("2- Retour Menu Vente et statistiques");
            printf("3- Retour Menu Principal");
            do
            {   printf(">> Tapez votre choix:                    \n ");
                scanf ("%d", &choix2_1);
                if(choix2_1>3 || choix2_1<0)
                    printf("votre choix doit etre Compris entre 1 et 3 \n");
            }while(choix2_1>3 || choix2_1<0);


            break;

        case 2:
            printf("1- Statistiques par mois \n");
            printf("2- Statistiques par ann馥 \n");
            printf("3- Retour Menu Vente et statistiques");
            printf("4- Retour Menu Principal");
            do
            {   printf(">> Tapez votre choix:                    \n ");
                scanf ("%d", &choix2_1);
                if(choix2_1>4 || choix2_1<0)
                    printf("votre choix doit etre Compris entre 1 et 4 \n");
            }while(choix2_1>4 || choix2_1<0);

            break;
        case 3:
            exit (0);
    }

    return 0;
}
/*switch(choix1_1)
{    case 1:
      AjouterCat(TabCat,p);

    break;
    case 2:


   return 0;
}*/
