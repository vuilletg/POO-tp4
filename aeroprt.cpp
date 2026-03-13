//
// Created by vuilletg on 3/13/26.
//
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "aeroprt.h"
Aeroprt::Aeroprt (fstream &stream, std::string delimiter){
    getLine(stream, nom, delimiter);
    getLine(stream, id, delimiter);
    getLine(stream, lat, delimiter);
    getLine(stream, lon, delimiter);
}
void Aeroprt::write (fstream &stream, std::string delimiter){
    stream << nom << delimiter << id << delimiter << lat << delimiter << lon;
}
void Aeroprt::ajouter_connection_entre(int *conection) {
    entre.push_back(conection);
}
void Aeroprt::ajouter_connection_sortie(int *conection) {
    sortie.push_back(conection);
}

Conexion::Conexion(fstream &stream, std::string delimiter, std::vector<Aeroprt> aeroprt) {
    std::string dep;
}