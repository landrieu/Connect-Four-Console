//************************ Application console (C++)****************************
//******************************************************************************
//  PROGRAMME :
//  DATE      :
//  OBJET     :
//  LIMITES   :
//  AUTEUR(S) :
//******************************************************************************
/* Si vous construisez un projet sous Code::Blocks et si vous utilisez l'une
   des bibliothèques de iutupadte :
   1- décommenter la ligne //define _IUT_TLSE3_PROJ et cliquez sur les onglets
      [Projet|Options de construction...|Options de l'éditeur de liens | Ajouter]
      puis rechercher la bibliothèque *.a sous \CodeBlocks\MinGW\lib\iut_tlse3
   2- au paragraphe suivant décommentez le(s) fichiers(s) d'entête *.h ou
      *.hpp pour inclure les déclarations des fonctions utilisées */
//#define _IUT_TLSE3_PROJ

/* Ce paragraphe permet d'inclure les fonctions des fichiers suivants :
   conio-bis - gestion de fenêtres dos, de couleurs, lecture sans écho...
   dos-bis   - gestion du temps, attentes...
   frame     - tracé de cadres, grilles, traits, flèches...
   transcode - affichage avec accents ou sans accent sous dos ou windows
   keys-fr   - liste des clés sous forme de noms symboliques
   iutupdate - inclut TOUS les fichiers précédents en une seule fois
      (cf le fichier de présentation iutupdate.pdf dans l'aide en ligne)
=> pour référencer les bibliothèques "décommenter" les lignes correspondantes */
//#include <iut_tlse3\iutupdate.hpp>    //inclut tout à la fois
//#include <iut_tlse3\frame.hpp>        //inclut frame + conio-bis
//#include <iut_tlse3\conio-bis.h>      //inclut conio-bis
//#include <iut_tlse3\dos-bis.h>        //inclut dos-bis
//#include <iut_tlse3\transcode.hpp>    //inclut transcode
//#include <iut_tlse3\keys-fr.h>        //inclut la définition du clavier français

#include <iostream>    // flux d'entrée sortie
#include <iomanip>     // manipulateurs de flux
#include <cstdlib>     // bibliothèque c standart
#include <conio.h>     // nécessaire pour kbhit

using namespace std;   // permet d'utiliser les flux cin et cout

//*************************** Déclaration globale ******************************
/***** constante *****/

/******* type ********/

/***** variable ******/
  // UN PROGRAMME BIEN CONSTRUIT NE DOIT PAS COMPORTER DE VARIABLE GLOBALE !
/***** fonction ******/

//*************************** Programme principal ******************************
int main ()
{
   // Déclaration locale

   // Action


   // Fin : retour au sytème d'exploitation
   while(!kbhit()); // attente de l'appui d'une touche pour quitter
   return (0);
}
//****************************  Fin du programme *******************************

