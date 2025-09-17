#include <iostream>
#include <vector>
#include <numeric>   // pour std::gcd (pgcd en C++17+)

using namespace std;

/*
 * Fonction : multiplyMatrixVector
 * Rôle     : Multiplie une matrice par un vecteur
 * Arguments:
 *    - mat : matrice (tableau 2D)
 *    - vec : vecteur (tableau 1D)
 * Retour   : vecteur résultat
 */
vector<int>multiplyMatrixVector(const vector<vector<int>>& mat, const vector<int>& vec) {
    size_t  rows = mat.size();
    size_t  cols = mat[0].size();

    if (cols != vec.size()) {
        throw invalid_argument("Les dimensions entre la matrice et le vecteur ne sont pas compatible");
    }

    vector<int> result(rows, 0); //vecteur résultat initialisé à 0

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += mat[i][j] * vec[j]; // produit scalaire de la ligne i et du vecteur
        }
    }

    return result;
}

/*
 * Fonction : addMatrices
 * Rôle     : Additionne deux matrices de même dimension
 * Arguments:
 *    - matriceA, matriceB : matrices à additionner
 * Retour   : matrice somme
 */
vector<vector<int>> addMatrices(const vector<vector<int>>& matriceA, const vector<vector<int>>& matriceB) {
    size_t rows = matriceA.size();
    size_t cols = matriceA[0].size();

    if (matriceB.size() != (size_t)rows || matriceB[0].size() != (size_t)cols) {
        throw invalid_argument("Les matrices doivent avoir la même taille !");
    }

    vector<vector<int>> result(rows, vector<int>(cols, 0)); // matrice résultat initialisé à 0

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matriceA[i][j] + matriceB[i][j];
        }
    }
    return result;
}

/*
 * Fonction : determinant2x2
 * Rôle     : Calcule le déterminant d'une matrice 2x2
 * Arguments:
 *    - mat : matrice 2x2
 * Retour   : valeur du déterminant
 */
int determinantMatrice2x2(const vector<vector<int>>& mat) {
    if (mat.size() != 2 || mat[0].size() != 2 || mat[1].size() != 2) {
        throw invalid_argument("La matrice doit être 2x2 !");
    }
    int calculDeterminant = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    return calculDeterminant;
}

/*
 * Fonction : isInvertibleModN
 * Rôle     : Vérifie si une matrice 2x2 est inversible modulo n
 * Arguments:
 *    - mat : matrice 2x2
 *    - n   : modulo
 * Retour   : true si inversible, false sinon
 */
bool isInvertibleModN(const vector<vector<int>>& mat, int modulo) {
    int det = determinantMatrice2x2(mat);
    int g = gcd(det, modulo); // pgcd(determinant, modulo)

    return g == 1;
}


int main() {
    // Exercice 1 : Multiplication matrice x vecteur
    vector<vector<int>> M = {{1 ,2}, {3, 4}};
    vector<int> v = {5, 6};

    vector<int> result = multiplyMatrixVector(M, v);
    cout << "Multiplication matrice x vecteur : " ;
    for (int x : result) cout << x << " ";
    cout << endl;

    // Exercice 2 : Addition de matrices
    vector<vector<int>> matriceA = {{1 ,2}, {3, 4}};
    vector<vector<int>> matriceB = {{5, 6}, {7, 8}};
    vector<vector<int>> sum = addMatrices(matriceA, matriceB);

    cout << "Addition de matrices :" << endl;
    for (auto& row : sum) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    // Exercice 3 : Déterminant et inversibilité
    vector<vector<int>> matriceC = {{3 ,3}, {2, 5}};

    int det = determinantMatrice2x2(matriceC);
    cout << "Determinant de matriceC : " << det << endl;

    int modulo = 26;
    cout << "La matrice M est-elle inversible modulo " << modulo << " ? "
        << (isInvertibleModN(M, modulo) ? "OUI" : "NON") << endl;

    return 0;
}