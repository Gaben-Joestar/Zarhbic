#include <stdio.h>
#include <stdlib.h>    
#include <string>
#include <math.h>
#include <iostream>
using namespace std;


//Service d'initialisation des piles
// Initialise une pile en fonction de sa taille
// et met chaque case de la pile à 0.1 (pile statique)
// Entrées : une pile et sa taille
void Initialisation_Pile(double pile[], int taillePile){
    for (int i=0; i<taillePile;i++){
        pile[i]=0.1;
    }
}
// Service de test Pile Pleine
// Teste si la pile entrée en paramètre est pleine,
// et renvoie le résultat
// Entrées: une pile (double []) et sa taille (int)
bool PilePleine(double pile[], int taillePile){
    return (fmod(pile[taillePile-1],0.1) == 0);
}


// Service d'ajout dans une pile
// Teste si la pile est vide, et si tel est le cas, ajoute le nombre
// à ajouter sur le dessus de la pile.
// Entrées: une pile (double[]), sa taille (int), le nombre à ajouter (int)
void Ajout_Pile(double pile[],int taillePile, int nombreAajouter){
    if (!(PilePleine)){
        int parcours=0;
        bool chiffre_ajoute = false;
        while (!(chiffre_ajoute)){
            if(fmod(pile[taillePile-1],0.1)==0){
                pile[parcours]=nombreAajouter;
                chiffre_ajoute = true;
            }
            else{parcours++;}
        }
        
    }
}

int Depiler_Pile(double pile[], int taillePile){
    int i=taillePile-1;
    int resultat;
    bool chiffre_depile = false;
    while (i>0 && chiffre_depile == false ){
        if (pile[i]!=0.1){
            resultat=pile[i];
            chiffre_depile=true;
        }
        
        
        i--;
    }
}

int Switch_Case_Operateurs(char caractere,double nombre1, double nombre2){
    int resultat = 0;
    switch (caractere) {
        case '+':
            resultat = nombre1 + nombre2;
            break;
        case '-':
            resultat = nombre1 - nombre2;
            break;
        case '*':
            resultat = nombre1 * nombre2;
            break;
        case '/':
            resultat = nombre1 / nombre2;
            break;
        default:
            cout << "Erreur, l'opérateur n'est pas correct "<< endl;
            resultat = 0;
            break;
    }
    return resultat;
}


int Parcours_Chaine(string chaine, double pile[], int taillePile){
    int travail;
    while(i<chaine.length()){
        if (chaine.at(i) >= 48 and chaine.at(i) <= 57){
            travail = stoi(chaine);
            
            i=-1;
        }
        else if (chaine[i] =="+" or chaine[i] =="-" or chaine[i] =="*" or chaine[i] =="/" ){
            travail = Switch_Case_Operateurs(chaine[i],depiler(pile,taillePile),depiler(pile,taillePile));
            Ajout_Pile(pile,taillePile,travail);
        }
        i++;
    }
    
int Calcul (string chaine){
    double pileDeTravail[chaine.length()];
    Initialisation_Pile(pileDeTravail,chaine.length());
    Parcours_Chaine(chaine,pileDeTravail,chaine.length());
    return 0;
}
    
    return travail;
}




// Service principal du programme
int main()
{
    string operation;
    cout << "Entrez le calcul à effectuer" << endl;
    getline(cin,operation);
    int res = Calcul(operation);
    cout << operation << endl;
}