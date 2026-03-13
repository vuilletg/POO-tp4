//
// Created by vuilletg on 3/13/26.
//
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include "aeroprt.h"
using namespace std;
Aeroprt::Aeroprt (fstream stream, string delimiter){
    getline(stream, nom, delimiter);
    getline(stream, id, delimiter);
    string clatitude;
    string clongitude;
    getline(stream, (double ) clatitude, delimiter);
    getline(stream, (double ) clongitude, delimiter);
    latitude = (double ) clatitude;
    longitude = (double ) clongitude;
    aeroport.resize(++size_a);
    aeroport.push_back(this);
}
void Aeroprt::write (fstream stream, string delimiter){
    stream << nom << delimiter << id << delimiter << to_string(latitude) << delimiter << to_string(longitude);
}
void Aeroprt::ajouter_connection_entre(shared_ptr<Conexion> conection) {
    entre.resize(++size_e);
    entre.push_back(conection);
}
void Aeroprt::ajouter_connection_sortie(shared_ptr<Conexion> conection) {
    entre.resize(++size_s);
    sortie.push_back(conection);
}

Conexion::Conexion(fstream stream, string delimiter, vector<shared_ptr<Aeroprt>> aeroprt) {
    std::string dep;
    std::string arr;
    getline(stream, dep, delimiter);
    getline(stream, dep, delimiter);
    string cduree;
    getline(stream, cduree, delimiter);
    duree = (float) cduree;
    entree = aeroprt[dep];
    sortie = aeroprt[arr];
    entree->ajouter_connection_entre(this);
    sortie->ajouter_connection_sortie(this);
}
void Conexion::write(fstream stream, string delimiter) {
    stream << entree->id << delimiter << sortie ->id << delimiter << to_string(duree);
}
