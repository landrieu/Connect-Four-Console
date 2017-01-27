//************************ Application console (C++)****************************
//******************************************************************************
//  PROGRAMME :
//  DATE      :
//  OBJET     :
//  LIMITES   :
//  AUTEUR(S) :
//******************************************************************************
/* Si vous construisez un projet sous Code::Blocks et si vous utilisez l'une
   des biblioth�ques de iutupadte :
   1- d�commenter la ligne //define _IUT_TLSE3_PROJ et cliquez sur les onglets
      [Projet|Options de construction...|Options de l'�diteur de liens | Ajouter]
      puis rechercher la biblioth�que *.a sous \CodeBlocks\MinGW\lib\iut_tlse3
   2- au paragraphe suivant d�commentez le(s) fichiers(s) d'ent�te *.h ou
      *.hpp pour inclure les d�clarations des fonctions utilis�es */
//#define _IUT_TLSE3_PROJ

/* Ce paragraphe permet d'inclure les fonctions des fichiers suivants :
   conio-bis - gestion de fen�tres dos, de couleurs, lecture sans �cho...
   dos-bis   - gestion du temps, attentes...
   frame     - trac� de cadres, grilles, traits, fl�ches...
   transcode - affichage avec accents ou sans accent sous dos ou windows
   keys-fr   - liste des cl�s sous forme de noms symboliques
   iutupdate - inclut TOUS les fichiers pr�c�dents en une seule fois
      (cf le fichier de pr�sentation iutupdate.pdf dans l'aide en ligne)
=> pour r�f�rencer les biblioth�ques "d�commenter" les lignes correspondantes */
//#include <iut_tlse3\iutupdate.hpp>    //inclut tout � la fois
//#include <iut_tlse3\frame.hpp>        //inclut frame + conio-bis
//#include <iut_tlse3\conio-bis.h>      //inclut conio-bis
//#include <iut_tlse3\dos-bis.h>        //inclut dos-bis
//#include <iut_tlse3\transcode.hpp>    //inclut transcode
//#include <iut_tlse3\keys-fr.h>        //inclut la d�finition du clavier fran�ais

#include <iostream>    // flux d'entr�e sortie
#include <iomanip>     // manipulateurs de flux
#include <cstdlib>     // biblioth�que c standart
#include <conio.h>     // n�cessaire pour kbhit

using namespace std;   // permet d'utiliser les flux cin et cout

//*************************** D�claration globale ******************************
/***** constante *****/

/******* type ********/

/***** variable ******/
  // UN PROGRAMME BIEN CONSTRUIT NE DOIT PAS COMPORTER DE VARIABLE GLOBALE !
/***** fonction ******/

//*************************** Programme principal ******************************
int main ()
{
   // D�claration locale

   // Action


   // Fin : retour au syt�me d'exploitation
   while(!kbhit()); // attente de l'appui d'une touche pour quitter
   return (0);
}
//****************************  Fin du programme *******************************

