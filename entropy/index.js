/**
 * Programme pour calculer l'entropie d'une chaîne donné (mot de passe, clé, etc.)
 */

// Création de l'interface readline
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Lancement du programme
console.log("=== Programme de calcul d'entropie ===");
demanderChaine();


function calculerEntropie(chaine) {
    if (!chaine || chaine.lengh === 0) {
        console.log('⚠ Erreur : La chaîne est vide !');
        return;
    }

    const longueur = chaine.length;
    const frequence = new Map(); // pour stocker les fréquences d’apparition des caractères

    // Compter combien de fois chaque caractère apparaît
    for (let c of chaine) {
        frequence.set(c, (frequence.get(c) || 0) + 1);
    }

    // Calcul de l'entropie
    let entropie = 0;
    for (let [char, count] of frequence) { // pour chaque caractère du map
        let p = count / longueur; // probabilité p du caractère, Exemple : "l" apparaît 2 fois dans 5 caractères → p = 2/5 = 0.4
        entropie += -p * Math.log2(p); // formule mathématique de Shannon & "-p" car On corrige le signe du log (pour que ce soit positif).
    }

    return entropie; // valeur en bits qui représente la quantité d’information : bits/caractère
}

// Fonction récursive pour tester plusieurs chaînes
function demanderChaine() {
    rl.question("👉 Entrez une chaîne (ou tapez 'exit' pour quitter) : ", (input) => {
        if (input.toLowerCase() === "exit") {
            console.log("👋 Fin du programme.");
            rl.close();
        } else {
            const H = calculerEntropie(input); // l’entropie de Shannon est notée par la lettre H
            console.log(`🔑 Entropie de "${input}" : ${H.toFixed(3)} bits\n`); // .toFixed(3) arrondit le nombre à 3 décimales pour la lisibilité.
            demanderChaine(); // relance pour une nouvelle saisie de chaine
        }
    });
}


