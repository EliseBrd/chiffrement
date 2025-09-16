#include <iostream> // pour cout/cin
#include <string> // pour utiliser string

using namespace std; // evite d'utiliser std::cout à chaque fois

string cesar(string mot) {
    int decalage = 3; // décalage fixé à 3
    string resultat = "";

    for (char c : mot) { // pour chaque lettre du mot
        if (isalpha(c)) { // si c’est une lettre
            char base = isupper(c) ? 'A' : 'a'; // base différente selon majuscule ou minuscule de 0 à 26
            // (c - base) → transforme la lettre en un nombre de 0 à 25.
            // % 26 → permet de boucler dans l’alphabet (si on dépasse Z, on revient à A).
            // + base → on revient à un caractère ASCII
            c = (c - base + decalage) % 26 + base;
        } else {
            cout << "Erreur : le mot doit contenir uniquement des lettres." << endl;
            exit(1); // arrêt immédiat du programme
        }
        resultat += c; // ajoute la lettre transformée
    }
    return resultat;
}

int main() {
    string mot;

    cout << "Entrer un mot : ";
    cin >> mot; // lecture du mot

    string crypte = cesar(mot);

    cout << "Mot chiffrer avec un decalage de 3 : " << crypte  << endl;

    return 0;
}