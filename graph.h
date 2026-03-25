#ifndef TP4_BIS_GRAPH_H
#define TP4_BIS_GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>      // Indispensable pour priority_queue
#include <functional> // Indispensable pour std::function
#include <limits>     // Indispensable pour numeric_limits (infinity)
#include <algorithm>  // Indispensable pour std::reverse

template <typename S, typename A>
class Graphe {
private:
    std::map<std::string, S> sommets;
    std::vector<A> aretes;

public:
    Graphe() {}

    void ajouterSommet(const std::string& id, const S& s) {
        sommets[id] = s;
    }

    void ajouterArete(const A& a) {
        aretes.push_back(a);
    }

    // Suppression d'une connexion (Point d)
    void supprimerArete(const std::string& dep, const std::string& arr) {
        for (auto it = aretes.begin(); it != aretes.end(); ) {
            if (it->getDepart() == dep && it->getArrivee() == arr) {
                it = aretes.erase(it);
            } else {
                ++it;
            }
        }
    }

    // Suppression d'un aéroport et ses vols (Point e)
    void supprimerSommet(const std::string& id) {
        sommets.erase(id);
        for (auto it = aretes.begin(); it != aretes.end(); ) {
            if (it->getDepart() == id || it->getArrivee() == id) {
                it = aretes.erase(it);
            } else {
                ++it;
            }
        }
    }

    void afficher() const {
        std::cout << "--- Aeroports ---" << std::endl;
        for (auto const& [id, s] : sommets) {
            std::cout << s << std::endl;
        }
        std::cout << "--- Connexions ---" << std::endl;
        for (auto const& a : aretes) {
            std::cout << a << std::endl;
        }
    }

    void sauvegarderFichier(const std::string& nomFichier) const {
        std::ofstream ofs(nomFichier);
        if (!ofs) return;
        ofs << sommets.size() << std::endl;
        for (auto const& [id, s] : sommets) ofs << s << std::endl;
        ofs << aretes.size() << std::endl;
        for (auto const& a : aretes) ofs << a << std::endl;
    }

    void dijkstra(const std::string& depart, const std::string& arrivee,
                  std::function<double(const A&)> poidsFonction) const {

        std::map<std::string, double> distances;
        std::map<std::string, std::string> parents;

        for (auto const& [id, s] : sommets) {
            distances[id] = std::numeric_limits<double>::infinity();
        }

        using Node = std::pair<double, std::string>;
        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

        if (sommets.find(depart) == sommets.end()) return;

        distances[depart] = 0;
        pq.push({0, depart});

        while (!pq.empty()) {
            std::string u = pq.top().second;
            double d = pq.top().first;
            pq.pop();

            if (d > distances[u]) continue;
            if (u == arrivee) break;

            for (const auto& arete : aretes) {
                if (arete.getDepart() == u) {
                    std::string v = arete.getArrivee();
                    double poids = poidsFonction(arete);

                    if (distances[u] + poids < distances[v]) {
                        distances[v] = distances[u] + poids;
                        parents[v] = u;
                        pq.push({distances[v], v});
                    }
                }
            }
        }

        if (distances[arrivee] == std::numeric_limits<double>::infinity()) {
            std::cout << "Aucun chemin entre " << depart << " et " << arrivee << std::endl;
        } else {
            std::cout << "Trajet (Poids : " << distances[arrivee] << ") : ";
            std::vector<std::string> chemin;
            for (std::string v = arrivee; v != ""; v = parents[v]) {
                chemin.push_back(v);
                if (v == depart) break;
            }
            std::reverse(chemin.begin(), chemin.end());
            for (size_t i = 0; i < chemin.size(); ++i) {
                std::cout << chemin[i] << (i == chemin.size() - 1 ? "" : " -> ");
            }
            std::cout << std::endl;
        }
    }
};

#endif