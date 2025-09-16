#include <iostream> // pour cout/cin
#include <string> // pour utiliser string

using namespace std; // evite d'utiliser std::cout à chaque fois

string homophonic(string mot) {

    string resultat = "";

    for (char c :mot) { // pour chaque lettre du mot
        if (isalpha(c)) { // si c'est une lettre
            c = tolower(c); // conversion du mot en minuscule

            int indice = c - 'a'; // transforme une lettre en un nombre 0 à 25 correspondant à sa position dans l’alphabet

            // indice / 10 → division entière :
                // Pour a à j (0-9) → 0
                // Pour k à t (10-19) → 1
                // Pour u à z (20-25) → 2

            // (indice / 10 + 1) * 10 → chiffre des dizaines du code :
                // Indices 0-9 → (0+1)*10 = 10
                // Indices 10-19 → (1+1)*10 = 20
                // Indices 20-25 → (2+1)*10 = 30

            // (indice % 10 + 1) → chiffre des unités :
            // % 10 → reste de la division par 10 → position dans le groupe de 10
            // +1 → pour que ça commence à 1 au lieu de 0

                // Exemple :
                // a (indice=0) → 0%10+1=1 → code = 10 + 1 = 11
                // b (indice=1) → 1%10+1=2 → code = 10 + 2 = 12
                // m (indice=12) → (12/10+1)*10 = 20, (12%10+1)=3 → code = 23
            int code = (indice / 10 + 1) * 10 + (indice % 10 + 1); // générer un nombre de substitution à deux chiffres pour chaque lettre
            resultat += to_string(code) + " "; // ajoute le code au mot final et ajoute un esapce
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

    string crypte = homophonic(mot);

    cout << "Mot chiffrer avec un chiffrement homophonic : " << crypte  << endl;

    return 0;
}