#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//Prototype des fonctions
void afficher_menu_principale();
void afficher_gestion();
void Naviguer();
void Nouveau();
void Consulter();
void Modifier();
void Supprimer();
void generation_d_etats();
void cadre();
int Chercher(int numero);
void gotoligcol( int lig, int col );
void reservation_en_cours();
void facture();
void Quitter();

// les variables globales
char  choixglobal[100];
int k=0, j=1,nbr_existe=0,nbr_chambre=0, nbr_reservation=0 ;

struct client{
	int id;
	char Nom[100];
	char Prenom[100];
	char CIN[20];
	int Tel;
};
typedef struct client Client;
Client client[100];

struct chambre{
    int Numero_De_Chambre;
    float Prix;
    char Type_De_Chambre[20];

};
typedef struct chambre Chambre;
Chambre chambre[100];

struct reservation{
    int N_Reservation ;
    char Date_Reservation;
    char Debut_Sejour;
    char Fin_Sejour;
    int Nombre_nuits;
    float Montant_Avance;
    int Numero_De_Client;
    char Type_De_Chambre;
};
typedef struct reservation Reservation;
Reservation reservation[100];



void main()
{
  afficher_menu_principale();
}
// fct menu principale

void afficher_menu_principale()
  {
      int choix;
      clrscr();
      cadre();
      system("color 79");
      gotoligcol(8,22);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0XA1);
      printf("\t\t        ============= GESTION DE RESERVATION HOTELIERE ============= \n\n\n");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1046);
      printf("\t\t\t\t                     1 > GESTION DES CLIENTS                         \n");
      printf("\t\t\t\t                                                                     \n");
      printf("\t\t\t\t                     2 > GESTION DES CHAMBRES                        \n");
      printf("\t\t\t\t                                                                     \n");
      printf("\t\t\t\t                     3 > GESTION DES RESERVATIONS                    \n");
      printf("\t\t\t\t                                                                     \n");
      printf("\t\t\t\t                     4 > GENERATION D'ETATS                          \n");
      printf("\t\t\t\t                                                                     \n");
      printf("\t\t\t\t                     5 > QUITTER                                     \n");

      do
      {
      printf("\n\t\t\t\t\t\t\t\t  Veuillez saisir votre choix: ");

      scanf("%d",&choix);
      }
      while(choix>5 || choix<1);
      switch(choix)
       {
        case 1:
           strcpy(choixglobal,"Clients");
           afficher_gestion();
           break;
        case 2:
           strcpy(choixglobal,"Chambres");
           afficher_gestion();
           break;
        case 3:
           strcpy(choixglobal,"Reservations");
           afficher_gestion();
           break;
        case 4:
            generation_d_etats();
           break;
        case 5:
             Quitter();
            break;


      }

  }
 void afficher_gestion()
    {

        clrscr();
        cadre();

        gotoligcol(5,28);
        system("color F0");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
	    printf("\t\t--------------- Gestion des %ss ---------------         \n\n",choixglobal);
	    system("color F0");
        printf("\t\t\t                                                              \n");
	    printf("\t\t\t                                                              \n");
	    printf("\t\t\t                                                              \n");
	    printf("\t\t\t                                                              \n");
	    printf("\t\t\t                                                              \n");
	    printf("\t\t\t                                                              \n\n\n\n");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
	    printf("\n\n\n\t\t\t        F1:Nouveau   F2:Consulter   F3:Modifier   F4:Supprimer     ESC:Menu       ");
	    printf("\n\n\n\t\t\t\t  *Cliquer sur une boutton pour acceder au menu que vous voulez* ");

  Naviguer();
}
void Naviguer()
   {	char c;
           c=getche();
        if(c==0)
        {c=getche();}
        if(c==27){afficher_menu_principale();}
         else if(c==59){Nouveau();}
              else if (c==60){Consulter();}
                    else if(c==61){Modifier();}
                          else if(c==62){Supprimer();}
                               else {do {printf("\n\t\t\t\tErreur, taper une des bouttons ci-dessus .");
                                          getch();          }
                                    while (c!=27 && c<60 && c>62);}

    }
void Nouveau()
{    int N;
     clrscr();
     system("color F0");
     cadre();
     gotoxy(24,6);
  if(strcmp(choixglobal,"Clients")==0)
       {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
        printf("\t\t            --------------- Gestion Des %s -------------             \n\n",choixglobal);
       if(nbr_existe<=99)
       {
         client[nbr_existe].id=1999+j;
         printf("\t\t\t            Numero Du Client         :     %d\n",client[nbr_existe].id);
         printf("\n\t\t\t          Prenom Du Client         :   "); scanf("%s",client[nbr_existe].Prenom);
         printf("\n\t\t\t          Nom Du Client            :  "); scanf("%s",client[nbr_existe].Nom);
         printf("\n\t\t\t          CIN Du Client            :  "); scanf("%s",client[nbr_existe].CIN);
         printf("\n\t\t\t          Telephone                :  "); scanf("%d",&client[nbr_existe].Tel);
         j++;

         nbr_existe++;}
       else  {printf("\t\t\tLa table est pleine .\n");}
       getch();
       printf("\n\n\n\t\t\t        F1:Nouveau   F2:Consulter   F3:Modifier   F4:Supprimer     ESC:Menu       ");
       Naviguer();
        }
    else if(strcmp(choixglobal,"Chambres")==0)
        {
         printf("\t\t          --------------- Gestion des %s -------------             \n\n",choixglobal);
         if(nbr_existe>nbr_chambre)
         {
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1168);
         printf("\n\t\t\t\t\t\t   N de chambre  ---  Type     ");
         printf("\n\t\t\t\t\t\t   [1-40]      --->   Double   " );
         printf("\n\t\t\t\t\t\t   [41-80]     --->   Singel   " );
         printf("\n\t\t\t\t\t\t   [81-100]    --->   Sweet    " );
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
         printf("\n\n\n\t\t\t     Numero De Chambre :                    ");
         scanf("%d",&chambre[nbr_chambre].Numero_De_Chambre);
         N=chambre[nbr_chambre].Numero_De_Chambre;
         if(N<=40)
         {  strcpy(chambre[nbr_chambre].Type_De_Chambre,"Double");
            chambre[nbr_chambre].Prix=500;
           printf("\n\t\t\t     Type de Chambre     :   ");
           printf("%s",chambre[nbr_chambre].Type_De_Chambre);
           printf("\n\n\t\t\t     Prix               :    ");
           printf("%.2f DH",chambre[nbr_chambre].Prix);}
         else{if(N>40||N<=80)
            {strcpy(chambre[nbr_chambre].Type_De_Chambre,"Singel");
            chambre[nbr_chambre].Prix=350;
           printf("\n\t\t\t     Type de Chambre    :   ");
           printf("%s",chambre[nbr_chambre].Type_De_Chambre);
           printf("\n\n\t\t\t     Prix              :    ");
           printf("%.2f DH",chambre[nbr_chambre].Prix); }
         else {strcpy(chambre[nbr_chambre].Type_De_Chambre,"Sweet");
            chambre[nbr_chambre].Prix=1500;
           printf("\n\t\t\t     Type de Chambre    :   ");
           printf("%s",chambre[nbr_chambre].Type_De_Chambre);
           printf("\n\n\t\t\t     Prix              :    ");
           printf("%.2f DH",chambre[nbr_chambre].Prix);}
         }
         nbr_chambre++;

         getch();
         printf("\n\n\n\t\t\t        F1:Nouveau   F2:Consulter   F3:Modifier   F4:Supprimer     ESC:Menu       ");
         Naviguer();
         }
         else printf("\n\n\n\n\n\n\t\t\tVous devez remplir le champs de GESTION DES CLIENTS avant d'acceder a ce champs \n\n\n\n");
         printf("\n\n\n\t\t\t        F1:Nouveau   F2:Consulter   F3:Modifier   F4:Supprimer     ESC:Menu       ");
         getch();
         Naviguer();
        }
    else {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
         printf("\t\t          --------------- Gestion des %s -------------             \n\n",choixglobal);
         if(nbr_existe<=99)

         {   reservation[nbr_reservation].N_Reservation=k+2901;
             printf("\t\t\t      Numero De Reservation  : %d\n",reservation[nbr_reservation].N_Reservation );
             printf("\n\t\t\t      Date De Reservation    : "); scanf("%s",&reservation[nbr_reservation].Date_Reservation);
             printf("\n\t\t\t      Debut De Sejour        : "); scanf("%s",&reservation[nbr_reservation].Debut_Sejour);
             printf("\n\t\t\t      Fin De Sejour          : "); scanf("%s",&reservation[nbr_reservation].Fin_Sejour);
             printf("\n\t\t\t      Nombre de Nuits        : "); scanf("%d",&reservation[nbr_reservation].Nombre_nuits);
             printf("\n\t\t\t      Montant Avance         : "); scanf("%f",&reservation[nbr_reservation].Montant_Avance);
             printf("\n\t\t\t      Numero De Client       : %d\n",1999+j);
             printf("\n\t\t\t      Type De Chambre        : "); scanf("%d",&reservation[nbr_reservation].Type_De_Chambre);
             nbr_reservation++;
             k++;
             printf("\n\n\n\n\t\t\t        F1:Nouveau   F2:Consulter   F3:Modifier   F4:Supprimer     ESC:Menu       ");
             getch();
            Naviguer();

         }
       }

  }


void Modifier()
{ int idm,rech;
  clrscr();
     system("color F0");
     cadre();
     gotoxy(24,6);
  if(strcmp(choixglobal,"Clients")==0)
  {   gotoligcol(8,20);
      printf("Remarque: Le dernier ID saisie est : %d",1999+j);
      printf("\t\t Entrer ID a modifier: ");
      scanf("%d",&idm);
      rech=Chercher(idm);
      if(rech==-1)
      {
          printf("\t\t\t Element introuvable");
          system("pause");
        afficher_gestion();
       Naviguer();
      }
      else{     clrscr();
				printf("\t\t\t Id de client: %d\n",client[rech].id);
				printf("\t\t\t Nom de client: %s\n",client[rech].Nom);
				printf("\t\t\t Prenom de client: %d\n",client[rech].Prenom);
				printf("\t\t\t CIN de client: %s\n",client[rech].CIN);
				printf("\t\t\t Tel de client: %d\n",client[rech].Tel);
				printf("\t\t\t------MODIFICATION------\n");
				printf("\t\t\t Saisir un Nouveau Nom de client: "); scanf("%s",client[rech].Nom);
				printf("\t\t\t Saisir un Nouveau Prenom de client: "); scanf("%s",client[rech].Prenom);
				printf("\t\t\t Saisir un Nouveau CIN de client: "); scanf("%s",client[rech].CIN);
				printf("\t\t\t Saisir un Nouveau Tel de client: "); scanf("%d",client[rech].Tel);
				cadre();
           system("pause");
           afficher_gestion();
           Naviguer();
           }
    }
   else if(strcmp(choixglobal,"Chambres")==0)
       {printf("\n\tEntrer le nombre de chambre a modifier");
         scanf("%d",&idm);
         rech=Chercher(idm);
           if(rech==-1)
             printf("Chambre introuvable");
           else {
                printf("\t\t\t     Numero De Chambre : %d",&chambre[rech].Numero_De_Chambre);
                printf("\t\t\t     Type de Chambre   : %s",chambre[rech].Type_De_Chambre);
                printf("\t\t\t     Prix              : %f",&chambre[rech].Prix);
                printf("\t\t\t------MODIFICATION------\n");
                printf("\t\t\t     Saisir un Nouveau  Numero De Chambre: "); scanf("%d",&chambre[rech].Numero_De_Chambre);
                printf("\t\t\t     Saisir un Nouveau Type de Chambre   : "); scanf("%s",chambre[rech].Type_De_Chambre);
                printf("\t\t\t     Saisir un Nouveau Prix              : "); scanf("%f",&chambre[rech].Prix);
            system("pause");
		   afficher_gestion();
                }
   }
    else{   printf("\t\tRemarque le dernier nombre de reservation saisie est: %d",k+2901);
            printf("\n\t\tEntrer le Nombre de Reservation a Modifier: ");
            scanf("%d",&idm);
            rech=Chercher(idm);
            if(rech==-1)
                printf("Le Nombre de Reservation introuvable.");
            else{
             printf("\n\t\t\t      Numero De Reservation  : %d",&reservation[rech].N_Reservation);
             printf("\n\t\t\t      Date De Reservation    : %d",&reservation[rech].Date_Reservation);
             printf("\n\t\t\t      Debut De Sejour        : %d",&reservation[rech].Debut_Sejour);
             printf("\n\t\t\t      Fin De Sejour          : %d",&reservation[rech].Fin_Sejour);
             printf("\n\t\t\t      Nombre de Nuits        : %d",&reservation[rech].Nombre_nuits);
             printf("\n\t\t\t      Montant Avance         : %f",&reservation[rech].Montant_Avance);
             printf("\n\t\t\t      Numero De Client       : %d",&reservation[rech].Numero_De_Client);
             printf("\n\t\t\t      Type De Chambre        : %d",&reservation[rech].Type_De_Chambre);
             printf("\n\t\t\t------MODIFICATION------\n");
             printf("\n\t\t\t      Saisir un Nouveau Numero De Reservation  : "); scanf("%d",&reservation[rech].N_Reservation);
             printf("\n\t\t\t      Saisir une Nouvelle Date De Reservation    : "); scanf("%d",&reservation[rech].Date_Reservation);
             printf("\n\t\t\t      Saisir Debut De Sejour        : "); scanf("%d",&reservation[rech].Debut_Sejour);
             printf("\n\t\t\t      Saisir Fin De Sejour          : "); scanf("%d",&reservation[rech].Fin_Sejour);
             printf("\n\t\t\t      Saisir le Nombre de Nuits        : "); scanf("%d",&reservation[rech].Nombre_nuits);
             printf("\n\t\t\t      Saisir le Nouveau Montant Avance         : "); scanf("%f",&reservation[rech].Montant_Avance);
             printf("\n\t\t\t      Saisir un Nouveau Numero De Client       : "); scanf("%d",&reservation[rech].Numero_De_Client);
             printf("\n\t\t\t      Saisir un Nouveau Type De Chambre        : "); scanf("%d",&reservation[rech].Type_De_Chambre);
             system("pause");
		   afficher_gestion();
                }
    }
}


void Consulter()
{
      int i;
      clrscr();
      gotoxy(8,8);
	  if(strcmp(choixglobal,"Client")==0)
      {
		system("cls");
		printf(" ---------- Consulter la liste des Clients ----------------\n\n");
		if(nbr_existe==0)
			printf("Table vide .... \n");
        else{
              printf("\t\t\t-----liste des clients-----");
			for(i=0;i<nbr_existe;i++){
				printf("\t\t\t Id de client: %d\n",client[i].id);
				printf("\t\t\t Nom de client: %s\n",client[i].Nom);
				printf("\t\t\t Prenom de client: %d\n",client[i].Prenom);
				printf("\t\t\t CIN de client: %s\n",client[i].CIN);
				printf("\t\t\t Tel de client: %d\n",client[i].Tel);
			                         }
		   }

		 system("pause");
		 afficher_gestion();
	  }
	  else
            if(strcmp(choixglobal,"Chambres")==0)
		   {clrscr();
              printf("\t\t\t-----liste des Chambres-----");
			for(i=0;i<nbr_chambre;i++){
				printf("\t\t\t Chambres Numero: %d\n",chambre[i].Numero_De_Chambre);
				printf("\t\t\t Type de Chambres: %d\n",chambre[i].Type_De_Chambre);
			    printf("\t\t\t Prix: %d\n",chambre[i].Prix);
			                         }
		    system("pause");
		    afficher_gestion();}
       else
		 {
            {clrscr();
           printf("\t\t\t-----liste des Reservations----");
			for(i=0;i<nbr_reservation;i++){
             printf("\t\t\t      Numero De Reservation  : %d",&reservation[i].N_Reservation);
             printf("\t\t\t      Date De Reservation    : %d",&reservation[i].Date_Reservation);
             printf("\t\t\t      Debut De Sejour        : %d",&reservation[i].Debut_Sejour);
             printf("\t\t\t      Fin De Sejour          : %d",&reservation[i].Fin_Sejour);
             printf("\t\t\t      Nombre de Nuits        : %d",&reservation[i].Nombre_nuits);
             printf("\t\t\t      Montant Avance         : %f",&reservation[i].Montant_Avance);
             printf("\t\t\t      Numero De Client       : %d",&reservation[i].Numero_De_Client);
             printf("\t\t\t      Type De Chambre        : %d",&reservation[i].Type_De_Chambre);
			                         }
		   }
		    system("pause");
            afficher_gestion();}
}


void Supprimer()
{
    int rec, numero_a_sup,i;
    clrscr();
    cadre();
    gotoxy(27,6);
  if(strcmp(choixglobal,"Clients")==0)
     {
         printf("\n\t\t\t donner l'id a supprimer");
         scanf("%d",&numero_a_sup);
         rec=Chercher(numero_a_sup);
         if(rec==-1)
            printf("element introuvable");
         else{
         for(i=rec;i<nbr_existe-1;i++)
         {
           client[i].id=client[i+1].id;
           strcpy(client[i].Prenom,client[i+1].Prenom);
           strcpy(client[i].Nom,client[i+1].Nom);
           strcpy(client[i].CIN,client[i+1].CIN);
           client[i].Tel=client[i+1].Tel;
         }
        nbr_existe--;
         printf("\t\t\t\n\n votre chambre a ete supprimer");
        afficher_gestion();
        Naviguer();
      }
     }
  else{
     if(strcmp(choixglobal,"Chambres")==0)
     {
         printf("donner le numero de chambre a supprimer");
         scanf("%d",&numero_a_sup);
         rec=Chercher(numero_a_sup);
          if(rec==-1)
            printf("element introuvable");
         else {
            for(i=rec;i<nbr_chambre;i++)
            {
           chambre[i].Numero_De_Chambre=chambre[i+1].Numero_De_Chambre;
           strcpy(&chambre[i].Type_De_Chambre,&chambre[i+1].Type_De_Chambre);
           chambre[i].Prix=chambre[i+1].Prix;
            }
             nbr_existe--;
             printf("\t\t\t\n\n votre chambre a ete supprimer");
             afficher_gestion();
        Naviguer();
              }

     }
     else { if (strcmp(choixglobal,"Reservations")==0)

        {
         printf("donner le numero de reservation a supprimer");
         scanf("%d",&numero_a_sup);
         rec=Chercher(numero_a_sup);
          if(rec==-1)
            printf("element introuvable");
         else {
         for(i=0;i<nbr_reservation;i++)
         {
           reservation[i].N_Reservation=reservation[i+1].N_Reservation;
           reservation[i].Date_Reservation=reservation[i+1].Date_Reservation;
           reservation[i].Debut_Sejour=reservation[i+1].Debut_Sejour;
           reservation[i].Fin_Sejour=reservation[i+1].Fin_Sejour;
           reservation[i].Montant_Avance=reservation[i+1].Montant_Avance;
           reservation[i].Numero_De_Client=reservation[i+1].Numero_De_Client;
           strcpy(&reservation[i].Type_De_Chambre,&reservation[i+1].Type_De_Chambre);
         }
        nbr_reservation--;
         printf("\t\t\t\n\n votre chambre a ete supprimer");
        afficher_gestion();
        Naviguer();
       }

          }
}
    }
}


void generation_d_etats()
{
     int choix;

        clrscr();
        gotoxy(7,14);
        system("color F0");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),18);

        printf("\t\t============================== GENERATION D'ETATS ==============================  \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
        printf("\t\t                               1 _ RESERVATION EN COURS                           \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),18);
        printf("\t\t                               2 _ FACTURE                                        \n");
        printf("\t\t                               3 _ QUITTER                                        \n");
       do
      {
      printf("\n\t\t\t\t\t\t\t\t\t votre choix:");
      scanf("%d",&choix);
      }
      while(choix>3 || choix<1);


      switch(choix)
       {
        case 1: reservation_en_cours();
           break;
        case 2: facture();
           break;
        case 3: afficher_menu_principale();
           break;
        }
    }
void reservation_en_cours()
{     int i;
      clrscr();
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
      printf("\n\n\n\n");
      printf("\t\t   Res n           Nom           Arrivee           Depart           Chambre           Type   \n");
      for(i=0;i<nbr_existe;i++){
        printf("\t\t   %d",reservation[i].N_Reservation);
        printf("\t%s",client[i].Nom);
        printf("\t%s",client[i].Prenom);
        printf("`t%d",reservation[i].Debut_Sejour);
        printf("\t%d",reservation[i].Fin_Sejour);
        printf("\t%d",chambre[i].Numero_De_Chambre);
        printf("\t%s",chambre[i].Type_De_Chambre);
			                         }

  Naviguer();
}
void facture()
{
    int N,rec;

    clrscr();

   system("color F0");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
   printf("\n\n\t\t\t\t\t                    facture                    ");
   printf("\n\t\t FACTURE N       :     %d   " ); scanf("%d",N);
   rec=Chercher(N);
   printf("\n\t\t Date d'edition  :     %s", reservation[rec].Date_Reservation );
   printf("\n\t\t Periode         :     %s AU %s", reservation[rec].Debut_Sejour ,reservation[rec].Fin_Sejour);
   printf("\n\t\t Duree           :     %d   Jours(s) ", reservation[rec].Nombre_nuits );
   printf("\n\t\t Montant avance  :     %d   DH TTC ", reservation[rec].Montant_Avance );
   printf("\n\n\n\n\t\t\t        F1:Nouveau   F2:Consulter   F3:Modifier   F4:Supprimer     ESC:Menu       ");
             getch();
            Naviguer();




}

void cadre()
{ int j;
 gotoxy(22,5);
         printf("\332");
    for(j=0;j<89;j++)
       {
         gotoxy(23+j,5);
         printf("\304");
       }

         printf("\277");
    for(j=1;j<21;j++)
       {
         gotoxy(112,5+j);
         printf("\263");
       }
        gotoxy(112,25);
        printf("\331");

    for(j=1;j<21;j++)
      {
           gotoxy(22,5+j);
           printf("\263");
      }
      gotoxy(22,25);
      printf("\300");

      for(j=0;j<89;j++)
      {
          gotoxy(23+j,25);
          printf("\304");
      }
}

int Chercher(int numero)
{
    int i;
  if(strcmp(choixglobal,"Clients")==0)
     {
         for(i=0;i<nbr_existe;i++)
         {
             if(numero==client[i].id)
             return i;
         }
          return -1;
     }
  else{
     if(strcmp(choixglobal,"Chambres")==0)
     {
         for(i=0;i<nbr_existe;i++)
         {
             if(numero==chambre[i].Numero_De_Chambre)
             return i;
         }
          return -1;
     }

     else if (strcmp(choixglobal,"Reservations")==0)

        {
         for(i=0;i<nbr_existe;i++)
          {
             if(numero==reservation[i].N_Reservation)
             return i;
          }
          return -1;
         }

     }

    }

 void Quitter()
{
    clrscr();
    cadre();
    system("color 79");
    gotoligcol(8,22);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0XA1);
    printf("\n\t\t\t\t\t                                                     \n");
    printf("\t\t\t\t\t       **********CREATIVE CODERS**********           ");
    printf("\n\t\t\t\t\t_____________________________________________________\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),121);
    printf("\t\t\t\t\t   REALISE PAR :   \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),114);
    printf("\t\t\t\t\t\t    AAKAR REHAB    \n");
    printf("\t\t\t\t\t\t\t    AAKAR RABAB    \n");
    printf("\t\t\t\t\t\t\t\t    BROUK SAFAA    \n");
    printf("\t\t\t\t\t\t\t\t\t    BAHRAOUI SALMA    \n");
    getch();

}

void gotoligcol( int lig, int col )
{
// ressources
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
