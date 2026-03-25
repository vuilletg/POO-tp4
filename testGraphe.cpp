#include "graph.h"
#include "airport.h"
#include <iostream>

int main() {
    Graphe<Aeroport, Connexion> monReseau;

    Aeroport lyon("LYS", "Lyon", 45.72, 5.08);
    Aeroport paris("CDG", "Paris", 49.00, 2.54);
    Aeroport marseille("MRS", "Marseille", 43.43, 5.21);
    Aeroport toulouse("TLS", "Toulouse", 43.63, 1.37);

    monReseau.ajouterSommet(lyon.getId(), lyon);
    monReseau.ajouterSommet(paris.getId(), paris);
    monReseau.ajouterSommet(marseille.getId(), marseille);
    monReseau.ajouterSommet(toulouse.getId(), toulouse);

    monReseau.ajouterArete(Connexion("LYS", "CDG", 1.0));
    monReseau.ajouterArete(Connexion("CDG", "TLS", 1.5));
    monReseau.ajouterArete(Connexion("LYS", "MRS", 0.5));
    monReseau.ajouterArete(Connexion("MRS", "TLS", 1.2));

    return 0;
}