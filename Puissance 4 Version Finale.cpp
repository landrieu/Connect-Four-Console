//************************ Application console (C++)****************************
//******************************************************************************
//  PROGRAMME :Puissance 4
//  DATE      :01/05/2012
//  OBJET     :
//  LIMITES   :
//  AUTEUR(S) :Andrieu Lionel et Calas Marion
//******************************************************************************
#include <iut_tlse3\iutupdate.hpp>

#include <iostream>    // flux d'entrée sortie
#include <iomanip>     // manipulateurs de flux
#include <cstdlib>     // bibliothèque c standart
#include <conio.h>     // nécessaire pour kbhit
#include <string>
#include <fstream>

using namespace std;   // permet d'utiliser les flux cin et cout
//*************************** Déclaration globale ******************************
/***** constante *****/
const int vide =0; //valeur d'une case vide
const int noir=1;  //valeur d'un pion
const int blanc=2;  //valeur d'un pion
const int colonne=7;
const int ligne=6;
char joueur_1 [10];
char joueur_2 [10];
/******* type ********/
typedef int t_plateau [ligne][colonne];
typedef int t_sauvegarde [ligne][colonne];
typedef struct
{
int couleur;     // couleur du texte
int cumulnoir;   // cumul du score joueur pion noir
int cumulblanc;  // cumul du score joueur pion blanc
int niveau;      // niveau de l'IA
    }puissance;
/***** variable ******/

/***** fonction ******/
void saisir_nom(int color)
{ clrscr();
  textcolor(color);
  cout<<endl<<"                    ----------------  PUISSANCE 4    -------------"<<endl<<endl<<endl;

  cout<<"Saisir le nom du joueur 1:";
  cin.getline(joueur_1,10);//saisie le nom joueur

  cout<<"Saisir le nom du joueur 2:";
  cin.getline(joueur_2,10);

}
/** Change le joueur ***/
int change_joueur(int ja)
{
    int suivant;
    if(ja==noir)
    {suivant=blanc;}
    else
    {suivant=noir;}
    return(suivant);
}
/**** Initialise le tableau ****/
void initialisation(t_plateau & p)
{
    int cpt1,cpt2;

    for(cpt1=0;cpt1<ligne;cpt1=cpt1+1)
    {
        for(cpt2=0;cpt2<colonne;cpt2=cpt2+1)
        {
            p[cpt1][cpt2]=vide;
        }
    }
}
/******* Affiche le tableau ******/
void affiche_grille(t_plateau grille,puissance p4)
{
   int i,j;
   textcolor(p4.couleur);
   cout<<endl<<"                  ----------------  PUISSANCE 4    -------------"<<endl<<endl;
   cout<<endl<<endl;
   cout<< "\t   ";

   for(j=0;j<ligne+1;j++)
   {cout<<j+1<<"   ";}

   cout<<endl<< "\t +";
   for(j=0;j<ligne+1;j++)
   {textcolor(p4.couleur);
       cout<<"---+";
       }
   for(i=0;i<ligne;i++)
   {
     cout<<endl<< "\t |";

for(j=0;j<ligne+1;j++)
     {
      switch(grille [i][j])
      {
          case vide: cout<<"   |";
          break;
          case noir:
          textcolor(YELLOW);
          cout<<" O ";
          textcolor(p4.couleur);
          cout<<"|";
          break;
          case blanc:
          textcolor(RED);
          cout<<" O ";
          textcolor(p4.couleur);
          cout<<"|";
          break;

          }
       }
       cout<<endl<<"\t +";
       for(j=0;j<ligne+1;j++)
       {textcolor(p4.couleur);
           cout<<"---+";
       }}
       cout<<endl<<endl;
}
/**** Vérifie si il y a un vainqueur *****/
void gagnant(t_plateau croisement,bool & vainqueur_b,bool & vainqueur_n)
{
int cpt1,cpt2;

for(cpt1=0;cpt1<=5;cpt1++)// Verification Horizonale
{
    for(cpt2=0;cpt2<=3;cpt2++)
    {

       if (croisement[cpt1][cpt2]==noir && croisement[cpt1][cpt2+1]==noir && croisement[cpt1][cpt2+2]==noir && croisement[cpt1][cpt2+3]==noir)
       {
        vainqueur_n=true;
       }
       if (croisement[cpt1][cpt2]==blanc && croisement[cpt1][cpt2+1]==blanc && croisement[cpt1][cpt2+2]==blanc && croisement[cpt1][cpt2+3]==blanc)
       {
       vainqueur_b=true;
       }
    }
}

for(cpt1=3;cpt1<=5;cpt1++) // Verification Verticale
{
    for(cpt2=0;cpt2<=6;cpt2++)
    {
      if (croisement[cpt1][cpt2]==noir && croisement[cpt1-1][cpt2]==noir && croisement[cpt1-2][cpt2]==noir && croisement[cpt1-3][cpt2]==noir)
      {
       vainqueur_n=true;
      }
      if (croisement[cpt1][cpt2]==blanc && croisement[cpt1-1][cpt2]==blanc && croisement[cpt1-2][cpt2]==blanc && croisement[cpt1-3][cpt2]==blanc)
      {
      vainqueur_b=true;
      }
    }
}

for(cpt1=3;cpt1<=5;cpt1++) // Verification Diagonal Haut Droite
{
    for(cpt2=0;cpt2<=3;cpt2++)
    {
     if (croisement[cpt1][cpt2]==noir && croisement[cpt1-1][cpt2+1]==noir && croisement[cpt1-2][cpt2+2]==noir && croisement[cpt1-3][cpt2+3]==noir)
     {
      vainqueur_n=true;
     }
     if (croisement[cpt1][cpt2]==blanc && croisement[cpt1-1][cpt2+1]==blanc && croisement[cpt1-2][cpt2+2]==blanc && croisement[cpt1-3][cpt2+3]==blanc)
     {
     vainqueur_b=true;
     }
    }
}

for(cpt1=3;cpt1<=5;cpt1++)  // Verification Diagonal Haut Gauche
{
    for(cpt2=3;cpt2<=6;cpt2++)
    {
     if (croisement[cpt1][cpt2]==noir && croisement[cpt1-1][cpt2-1]==noir && croisement[cpt1-2][cpt2-2]==noir && croisement[cpt1-3][cpt2-3]==noir)
     {
      vainqueur_n=true;
     }
     if (croisement[cpt1][cpt2]==blanc && croisement[cpt1-1][cpt2-1]==blanc && croisement[cpt1-2][cpt2-2]==blanc && croisement[cpt1-3][cpt2-3]==blanc)
     {
     vainqueur_b=true;
     }
    }
}
}

/***** Avance le pion dans le tableau ******/
void avance_pion(t_plateau & aire,int joueur,int rangee)
{
int i=0;

if(joueur==blanc)
{
  while(aire[i][rangee]!=blanc && aire[i][rangee]!=noir && i<ligne)
  {
   i=i+1;
  }

  if(i>ligne-1)
  {
  aire[ligne-1][rangee]=blanc;
  }
  else
  {
  aire[i-1][rangee]=blanc;
  }
}
else
{
   while(aire[i][rangee]!=noir&& aire[i][rangee]!=blanc && i<ligne)
   {
    i=i+1;
   }
   if(i>ligne-1)
   {
    aire[ligne-1][rangee]=noir;
   }
   else
   {
    aire[i-1][rangee]=noir;
    }
}
}

void curseur (int & cptr_ligne, int y)
{
int touche;
textcolor(12);

do
{
  gotoxy(30,10+3*cptr_ligne) ;
  cprintf("=>") ;

    if(kbhit())
    {
    touche = getxkey();
    }
    else
    {
    touche=0;
    }

    if(touche==584)//touche haut
    {
    cptr_ligne--;
    gotoxy(30,10+(cptr_ligne+1)*3); //efface la ligne precedente du curseur
    cout<<"  ";
    }

    if(touche==592)//touche bas
    {
    cptr_ligne++;
    gotoxy(30,10+(cptr_ligne-1)*3);
    cout<<"  ";
    }

    if (cptr_ligne>y)
    {
    cptr_ligne=0;
    }
    if (cptr_ligne<0)
    {
    cptr_ligne=y;
    }

}while(touche!= 0x00d);// Touche Entrée
clrscr();
textcolor(15);
cptr_ligne++;
}

/***** Choisir son adversaire *****/
int choix_joueur (int couleur)
{
   int a,adv,b=0;
   clrscr();
   a=0;
   textcolor(couleur);
   cout<<endl<<"                   ----------------  PUISSANCE 4    -------------"<<endl<<endl<<endl;
   gotoxy(35,10);
   cout<<"Jouer contre l'IA "<<endl;
   gotoxy(35,13);
   cout<<"Jouer contre un joueur 2 "<<endl;
   gotoxy(35,16);
   cout<<"Revenir au menu principal"<<endl;
   curseur(a,2);


   if (a==2)
   {
     adv=0;
   }
   if(a==1)
   {
     clrscr();
     textcolor(couleur);

     cout<<endl<<"                   ----------------  PUISSANCE 4    -------------"<<endl<<endl<<endl;
     gotoxy(35,10);
     cout<<w2d("1- Débutant")<<endl;
     gotoxy(35,13);
     cout<<w2d("2- Facile")<<endl;
     gotoxy(35,16);
     cout<<"Revenir au menu principal";
     curseur(b,2);

     switch (b)
     {
       case 1:adv=11;//valeur de l'IA
       break;
       case 2:adv=12;
       break;
       case 3:
       break;
     }
    }
return(adv);
}

/***** Affiche les règles a l'écran *****/
void regle(puissance p4)
{
    cout<<endl<<"                   ----------------  PUISSANCE 4    -------------"<<endl<<endl<<endl;
    textcolor(p4.couleur);
    cout<<endl<<endl<<w2d("Règles :");
    cout<<endl<<endl<<w2d("Le but du jeu est d'aligner 4 pions sur une grille comptant 6 rangées")<<endl;
    cout<<w2d("et 7 colonnes.Chaque joueur dispose de 21 pions d'une couleur par convention,");
    cout<<w2d("en general jaune ou rouge. Tour à tour les deux joueurs placent un pion dans la")<<endl;
    cout<<w2d("colonne de leur choix, le pion coulisse alors jusqu'à la position la plus basse")<<endl;
    cout<<w2d(" possible dans la colonne suite à quoi c'est à l'adversaire de jouer.")<<endl;
    cout<<w2d("Le vainqueur est le joueur qui realise le premier un alignement (horizontal,")<<endl;
    cout<<w2d(" vertical ou diagonal) d'au moins quatre pions de sa couleur." )<<endl<<endl;
    cout<<w2d("Si alors que toutes les cases de la grille de jeu sont remplies aucun ")<<endl;
    cout<<w2d("des deux joueurs n'a realisé un tel alignement, la partie est declarée")<<endl;
    cout<<w2d("nulle.")<<endl<<endl<<endl<<endl;

    cout<<"Appuyez sur une touche pour revenir au menu."<<endl;
    while(!kbhit());
    getxkey();
    cout<<endl<<endl<<endl;
    clrscr();
}

/***** Test si il y a de la place dans le tableau *****/
void test_place(t_plateau plateau,int rang,bool & erreur)
{
  if(plateau[0][rang]==blanc || plateau[0][rang]==noir)
  {
   erreur=true;
  }
  else
  {
  erreur=false;
  }
}
void sauvegarde (t_plateau tabl,t_sauvegarde & tabsauv)
{
int i,j;

   for(i=0;i<ligne;i++)
   {
     for(j=0;j<colonne;j++)
     {
       tabsauv[i][j]=tabl[i][j];
     }
    }
}


/**** Choisir les options du jeu ****/
void option (t_sauvegarde save,puissance & p4)
{
  int choix,choix2=0;

  choix=0;
  clrscr();
  textcolor(p4.couleur);
  gotoxy(20,2);
  cout<<"----------------  PUISSANCE 4    -------------"<<endl;
  gotoxy(35,10);
  cout<<"  Choisir l'adversaire"<<endl;
  gotoxy(35,13);
  cout<<"  Remettre les score a zero"<<endl;
  gotoxy(35,16);
  cout<<"  Changer le nom des joueurs"<<endl;
  gotoxy(35,19);
  cout<<"  Changer la couleur de la console"<<endl;
  gotoxy(35,22);
  cout<<w2d("  Voir la dernière sauvegarde")<<endl;
  gotoxy(35,25);
  cout<<"  Revenir au menu principal"<<endl;
  curseur(choix,5);

  switch (choix)
  {
   case 1:p4.niveau=choix_joueur(p4.couleur);
          break;
   case 2:p4.cumulblanc =0;
          p4.cumulnoir  =0;
          break;
   case 3 :saisir_nom(p4.couleur);
           break;
   case 4 :clrscr();
           textcolor(p4.couleur);
           gotoxy(20,2);
           cout<<"----------------  PUISSANCE 4    -------------"<<endl;
           gotoxy(35,10);
           cout<<"Fond blanc, caractere violet"<<endl;
           gotoxy(35,13);
           cout<<"Fond vert, caractere rouge"<<endl;
           gotoxy(35,16);
           cout<<"Fond blanc, caractere noir"<<endl;
           gotoxy(35,19);
           cout<<w2d("Fond cyan, caractère rouge")<<endl;
           gotoxy(35,22);
           cout<<w2d("Fond noir, caractère blanc")<<endl;
           gotoxy(35,25);
           cout<<"Revenir au menu principal";

           curseur(choix2,5);

           switch (choix2)
           {
            case 1:textbackground(15);
                   p4.couleur=5;
                   break;
            case 2:textbackground(GREEN);
                   p4.couleur=4;
                   break;
            case 3:textbackground(WHITE);
                   p4.couleur=0;
                   break;
            case 4:textbackground(3);
                   p4.couleur=4;
                   break;
            case 5:textbackground(BLACK);
                   p4.couleur=15;
            case 6:
                   break;
           }
          break;
    case 5: affiche_grille(save,p4);
    break;
    case 6:
    break;
}
gotoxy(30,40);
textcolor(p4.couleur);
cout<<"Appuyez sur une touche pour revenir au menu."<<endl;
while(!kbhit());
getxkey();
clrscr();
}

/****** Menu Principal du jeu *****/
void menu (int & r,puissance p4)
{
    textcolor(p4.couleur);

    gotoxy(20,2);
    cout<<"----------------  PUISSANCE 4    -------------";
    gotoxy(35,10);
    cout<<"Jouer";
    gotoxy(35,13);
    cout<<"Options";
    gotoxy(35,16);
    cout<<"Regles";
    gotoxy(35,19);
    cout<<"Quitter";
    r=0;
curseur(r,3);
}

void IA (t_plateau & tabl,bool & vainqu_blanc,bool & vainqu_noir,int & num_joueur,puissance p4)
{

int rang=1,j,plein,cpt1,cpt2,i;
plein=0;
vainqu_blanc=false;
vainqu_noir=false;
bool erreur=false;

initialisation(tabl);
do
{
  do
  {
  j=noir;
  clrscr();
  affiche_grille(tabl,p4);
    if(erreur==true || rang<1 || rang>colonne)
    {
     cout<<"Se deplacement n'est pas possible rejouez"<<endl;
    }
    else
    {
    cout<<"Placer le pion "<<endl<<"(Saisissez le numero de la colonne) :";
    }
    cin>>rang;
    test_place(tabl,rang-1,erreur);
   }
   while (rang<1 || rang>colonne || erreur==true);
 avance_pion(tabl,j,rang-1);
 gagnant(tabl,vainqu_blanc,vainqu_noir);
   if (vainqu_blanc==false)
   {
   j=blanc;
   do
   {
    switch(p4.niveau)
    {
    case 11:rang=rand()%7;
    break;
    case 12:
           for(cpt1=0;cpt1<colonne;cpt1=cpt1+1)
           {
            for(cpt2=0;cpt2<colonne;cpt2=cpt2+1)
            {


/**** hasard ****/
if(i==0)
{
do{
 rang=rand()%7;
 }
 while (rang<1 || rang>7);
}
i=i+1;


/**** 1 pions ***/
  //oblique bas gauche

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2-1]==vide && tabl[cpt1+2][cpt2-1]!=vide )
{
   rang=cpt2-1;
    }

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1-1][cpt2+1]==vide && tabl[cpt1][cpt2+1]!=vide )
{
   rang=cpt2+1;
    }

//oblique bas droite

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2+1]==vide && tabl[cpt1+2][cpt2+1]!=vide )
{
   rang=cpt2+1;
    }

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1-1][cpt2-1]==vide && tabl[cpt1][cpt2-1]!=vide )
{
   rang=cpt2-1;
    }

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1-1][cpt2]==vide )
{
   rang=cpt2;
    }

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1][cpt2+1]==vide && tabl[cpt1+1][cpt2+1]!=vide )
{
   rang=(cpt2+1);
    }


if (tabl[cpt2][cpt1]==blanc && tabl[cpt2][cpt1-1]==vide && tabl[cpt2+1][cpt1-1]!=vide )
{
   rang=cpt1-1;
    }

/**** 2 pions ****/


  //oblique bas gauche

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2-1]==blanc && tabl[cpt1+2][cpt2-2]==vide && tabl[cpt1+3][cpt2-2]!=vide)
{
   rang=cpt2-2;
    }

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2-1]==blanc && tabl[cpt1+2][cpt2-2]==vide && tabl[cpt1+3][cpt2-2]!=vide )
{
   rang=cpt2-2;
    }

//oblique bas droite

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2+1]==blanc && tabl[cpt1+2][cpt2+2]==vide && tabl[cpt1+3][cpt2+2]!=vide)
{
   rang=cpt2+2;
    }

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2+1]==blanc && tabl[cpt1-1][cpt2-1]==vide && tabl[cpt1][cpt2-1])
{
   rang=cpt2-1;
    }
//vertical
if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2]==blanc && tabl[cpt1+2][cpt2]==vide )
{
   rang=cpt2;
    }
if (tabl[cpt2][cpt1]==blanc && tabl[cpt2][cpt1+1]==blanc && tabl[cpt2][cpt1+2]==vide && tabl[cpt2+1][cpt1+2]!=vide)
{
   rang=cpt1+2;
    }
if (tabl[cpt2][cpt1]==blanc && tabl[cpt2][cpt1+1]==blanc && tabl[cpt2][cpt1-1]==vide && tabl[cpt2+1][cpt1-1]!=vide )
{
   rang=cpt1-1;
    }

 /**** 3 pions ***/
  //oblique bas gauche
if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2-1]==blanc && tabl[cpt1+2][cpt2-2]==blanc && tabl[cpt1+3][cpt2-3]==vide && tabl[cpt1+4][cpt2-3]!=vide)
{
   rang=cpt2-3;
    }
if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2-1]==blanc && tabl[cpt1+2][cpt2-2]==blanc && tabl[cpt1-1][cpt2+1]==vide && tabl[cpt1][cpt2+1]!=vide)
{
   rang=cpt2+1;
    }

//oblique bas droite

if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2+1]==blanc && tabl[cpt1+2][cpt2+2]==blanc && tabl[cpt1+3][cpt2+3]==vide && tabl[cpt1+4][cpt2+3]!=vide)
{
   rang=cpt2+3;
    }
if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2+1]==blanc && tabl[cpt1+2][cpt2+2]==blanc && tabl[cpt1-1][cpt2-1]==vide && tabl[cpt1][cpt2-1]!=vide)
{
   rang=cpt2-1;
    }
//vertical
if (tabl[cpt1][cpt2]==blanc && tabl[cpt1+1][cpt2]==blanc && tabl[cpt1+2][cpt2]==blanc && tabl[cpt1+3][cpt2]==vide )
{
   rang=cpt2;
    }
if (tabl[cpt2][cpt1]==blanc && tabl[cpt2][cpt1+1]==blanc && tabl[cpt2][cpt1+2]==blanc && tabl[cpt2][cpt1+3]==vide && tabl[cpt2+1][cpt1+3]!=vide)
{
   rang=cpt1+3;
    }
if (tabl[cpt2][cpt1]==blanc && tabl[cpt2][cpt1+1]==blanc && tabl[cpt2][cpt1+2]==blanc && tabl[cpt2][cpt1-1]==vide && tabl[cpt2+1][cpt1-1]!=vide)
{
   rang=cpt1-1;
    }
     }}
rang=rang+1;

break;
}

}
while(rang<1 || rang>7 || tabl[0][rang-1]==blanc || tabl[0][rang-1]==noir);
  avance_pion(tabl,j,rang-1);
  clrscr();
  gagnant(tabl,vainqu_blanc,vainqu_noir);
  plein=plein+2;
  }
}
while(vainqu_noir==false && vainqu_blanc==false && plein< colonne*ligne);

clrscr();
affiche_grille(tabl,p4);

 if(plein==colonne*ligne)
 {
  cout<<"Match nul"<<endl;
  }
 else
 {
    if(vainqu_blanc==true)
    {
    cout<<"Le vainqueur est l'ordinateur"<<endl<<endl;
    p4.cumulblanc=p4.cumulblanc+1 ;
    }
    else
    {
    cout<<"Le vainqueur est le joueur 1"<<endl<<endl;
    p4.cumulnoir=p4.cumulnoir+1 ;
    }
  }

  if  (p4.cumulblanc==p4.cumulnoir)
  {
  cout<<"Les 2 joueurs sont a egalite "<<p4.cumulblanc<<" partout"<<endl<<endl;
  }
  else
  {
    if(p4.cumulnoir>p4.cumulblanc)
    {
    cout<<"Le joueur 1 mene de "<<p4.cumulnoir<<" a "<<p4.cumulblanc<<endl<<endl;
    }
    else
    {
    cout<<"L'ordinateur mene de "<<p4.cumulblanc<<" a "<<p4.cumulnoir<<endl<<endl;
    }
  }
cout<<endl<<endl<<"Appuyez sur une touche pour revenir au menu."<<endl;
while(!kbhit());
getxkey();
clrscr();
}

/***** Joueur contre Joueur ****/
void J_VS_J (t_plateau & grille,bool & vainqu_b,bool & vainqu_n,int & n_joueur,t_sauvegarde & sauv,puissance p4 )
{
  int pion=1,plein;
  char pion2[10];
  bool error;
  int sauve;
  sauve=2;
  error=false;
  plein=0;
  initialisation(grille);
  vainqu_b=false;
  vainqu_n=false;

 if(p4.cumulblanc>p4.cumulnoir)
 {
 n_joueur=blanc;
 }
 else
 {
 n_joueur=noir;
 }

do{
  clrscr();
  affiche_grille(grille,p4);
  do{
     if(error==true || pion<0 || pion>colonne-1)
     {  clrscr();
      affiche_grille(grille,p4);
      cout<<"Le pion ne peut pas etre place a cet endroit"<<endl<<"Rejouer"<<endl;
     }
     else
     {
      cout<<"Au joueur ";
        if(n_joueur==noir)
        {
        cout<<joueur_1 ;
        }
        else
        {
        cout<<joueur_2 ;
        }
        cout<<" de placer un pion."<<endl;
        cout<<"Dans quelle colonne voulez-vous placer votre pion ?"<<endl<<"(Saisissez le numero de la colonne) :";
      }
   cin>>pion2;
   pion=atoi(pion2);
   pion=pion-1;
   test_place(grille,pion,error);
  }
  while (pion<0 || pion>colonne-1 || error==true);

avance_pion(grille,n_joueur,pion);
gagnant(grille,vainqu_b,vainqu_n);
n_joueur=change_joueur(n_joueur);
plein=plein+1;
}
while(vainqu_n==false && vainqu_b==false && plein< colonne*ligne);

clrscr();
affiche_grille(grille,p4);
  if(plein==colonne*ligne)
  {
  cout<<"Match nul"<<endl;
  }
  else
  {
      if(vainqu_b==true)
      {
      cout<<"Le vainqueur est "<<joueur_2<<endl<<endl;
      p4.cumulblanc=p4.cumulblanc+1 ;
      }
      else
      {
      cout<<"Le vainqueur est "<<joueur_1<<endl<<endl;
      p4.cumulnoir=p4.cumulnoir+1 ;
      }
   }

  if  (p4.cumulnoir==p4.cumulblanc)
  {
  cout<<w2d("Les 2 joueurs sont a egalite ")<<p4.cumulnoir<<" partout"<<endl<<endl;
  }
  else
  {
    if(p4.cumulnoir>p4.cumulblanc)
    {
    cout<<joueur_1<<w2d(" mène de ")<<p4.cumulnoir<<" a "<<p4.cumulblanc<<endl<<endl;
    }
    else
    {
    cout<<joueur_2<<w2d(" mène de ")<<p4.cumulblanc<<" a "<<p4.cumulnoir<<endl<<endl;
    }
  }

cout<<"Voulez-vous sauvegarder la partie ?"<<endl<<"1-OUI"<<endl<<"2-NON"<<endl;
cin>>pion2;
sauve=atoi(pion2);
  if(sauve==1)
  {
  initialisation(sauv);
  sauvegarde(grille,sauv) ;
  }

cout<<endl<<"Appuyez sur une touche pour revenir au menu."<<endl;
while(!kbhit()); // attente de l'appui d'une touche pour quitter
getxkey();
clrscr();

    }

/**** Menu du jeu ****/
void jouer (t_plateau & tab,bool & vainqu_bl,bool & vainqu_no,int & n_joueurs,int & n,t_sauvegarde & save,puissance p4 )
{

  switch(p4.niveau)
  {
      case 0 :if (n==0)
              {
              saisir_nom(p4.couleur);
              n=n+1;
              }// Permet de saisir nom des joueurs seulement la première partie
              J_VS_J(tab,vainqu_bl,vainqu_no,n_joueurs,save,p4);
              break;

   case 11:IA(tab,vainqu_bl,vainqu_no,n_joueurs,p4);
           break;

   case 12:IA(tab,vainqu_bl,vainqu_no,n_joueurs,p4);
           break;
   }
}
void presentation (t_plateau & tab,puissance p4)
{
p4.couleur=15;
initialisation(tab);
tab[5][6]=1;
tab[4][5]=1;
tab[3][4]=1;
tab[2][3]=1;
tab[3][3]=2;
tab[4][3]=2;
tab[5][3]=2;
tab[5][5]=2;
tab[5][4]=1;
tab[4][4]=2;
tab[5][1]=2;
tab[4][2]=2;
tab[5][2]=1;
affiche_grille(tab,p4);

gotoxy(28,25);
cout<<"Projet de Programmation"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;



gotoxy(0,39);
cout<<"ANDRIEU Lionel"<<endl<<"CALAS Marion";

 gotoxy(25,40);
 cout<<"Appuyer sur une touche pour passer au menu";
 while(!kbhit());
 getxkey();
 clrscr();
    }
//*************************** Programme principal ******************************
int main ()
{
   // Déclaration locale
t_plateau tab;
int a,b=0;
int num_joueur,cptr;
bool vainq_b,vainq_n;
puissance p4={15,0,0,0};
t_sauvegarde save;
initialisation(save);


_resize_screen(80,45);// taille de la console
_setcursortype(_NOCURSOR);// enlever le curseur : _
presentation(tab,p4);
do
{
clrscr();

menu(a,p4);
switch(a)
{
    case 1:jouer(tab,vainq_b,vainq_n,num_joueur,b,save,p4);
           break;

    case 2:option(save,p4);
           break;

    case 3:regle(p4);
           break;
}
}
while(a!=4 );


  for(cptr=1;cptr<41;cptr=cptr+1)
    {
       gotoxy(cptr,18);
       textcolor(RED);
       cout<<"  Puissance 4 par Andrieu et Calas";
       delay(30);
       gotoxy(cptr,18);
       cout<<" ";
    }
textcolor(p4.couleur);
cout<<endl<<endl<<"Appuyez sur une touche pour quitter le jeu."<<endl;
while(!kbhit()); // attente de l'appui d'une touche pour quitter
return (0);
}
//****************************  Fin du programme *******************************
