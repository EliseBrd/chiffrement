#include <iostream> // pour cout/cin
#include <string> // pour utiliser string

using namespace std; // evite d'utiliser std::cout à chaque fois

string vigenere(string mot) {
    string resultat = "";
    string cle = "guy"; // clé fixe
    int taille_cle = cle.length();
    int j = 0; // index pour parcourir la clé

    for (char c : mot) {
        if (isalpha(c)) { // si c'est une lettre
            c = tolower(c); // conversion du mot en minuscule
            // calcule pour chaque lettre du mot combien la décaler selon la clé
            char decalage = cle[j % taille_cle] - 'a';

            // On transforme le mot en indice 0-25, on applique le décalage modulo 26
            c = (c - 'a' + decalage) % 26 + 'a';

            resultat += c; // on ajoute au résultat
            j++; // on passe à la lettre suivante de la clé (ici guy)
        } else {
            cout << "Erreur : le mot doit contenir uniquement des lettres." << endl;
            exit(1); // arrêt immédiat du programme
        }
    }
    return resultat;
}

int main() {
    string mot;

    cout << "Entrer un mot : ";
    cin >> mot; // lecture du mot

    string crypte = vigenere(mot);

    cout << "Mot chiffrer avec un chiffrement viginere : " << crypte  << endl;

    return 0;
}