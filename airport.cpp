//
// Created by vuilletg on 3/24/26.
//

#include "airport.h"

Aeroport::Aeroport() : id(""), nom(""), latitude(0), longitude(0) {}

Aeroport::Aeroport(std::string i, std::string n, double lat, double lon)
        : id(i), nom(n), latitude(lat), longitude(lon) {}
std::string Aeroport::getId() const { return id; }

std::istream& operator>>(std::istream& is, Aeroport& a) {
    is >> a.id >> a.nom >> a.latitude >> a.longitude;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Aeroport& a) {
    os << a.id << " " << a.nom << " " << a.latitude << " " << a.longitude;
    return os;
}

Connexion::Connexion() : idDepart(""), idArrivee(""), duree(0) {}

Connexion::Connexion(std::string dep, std::string arr, double d)
        : idDepart(dep), idArrivee(arr), duree(d) {}

std::string Connexion::getDepart() const { return idDepart; }

std::string Connexion::getArrivee() const { return idArrivee; }

double Connexion::getDuree() const { return duree; }

std::istream& operator>>(std::istream& is, Connexion& c) {
    is >> c.idDepart >> c.idArrivee >> c.duree;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Connexion& c) {
    os << c.idDepart << " " << c.idArrivee << " " << c.duree;
    return os;
}
double Aeroport::calculerDistance(const Aeroport& autre) const {
    double dx = latitude - autre.latitude;
    double dy = longitude - autre.longitude;
    return std::sqrt(dx*dx + dy*dy);
}