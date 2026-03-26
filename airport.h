//
// Created by vuilletg on 3/24/26.
//

#ifndef TP4_BIS_AIRPORT_H
#define TP4_BIS_AIRPORT_H

#include <string>
#include <iostream>
#include <cmath>

class Aeroport {
private:
    std::string id;
    std::string nom;
    double latitude;
    double longitude;

public:
    Aeroport();
    Aeroport(std::string i, std::string n, double lat, double lon);

    std::string getId() const;

    friend std::istream& operator>>(std::istream& is, Aeroport& a);
    friend std::ostream& operator<<(std::ostream& os, const Aeroport& a);
    double calculerDistance(const Aeroport& autre) const;
};

class Connexion {
private:
    std::string idDepart;
    std::string idArrivee;
    double duree;

public:
    Connexion();
    Connexion(std::string dep, std::string arr, double d);

    std::string getDepart() const;
    std::string getArrivee() const;
    double getDuree() const;

    friend std::istream& operator>>(std::istream& is, Connexion& c);
    friend std::ostream& operator<<(std::ostream& os,const Connexion& c);
};
#endif //TP4_BIS_AIRPORT_H
