//
// Created by vuilletg on 3/13/26.
//

#ifndef TP4_AEROPRT_H
#define TP4_AEROPRT_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

struct Aeroprt {
    std::string nom;
    std::string id;
    int latitude;
    int longitude;
    std::vector<*Conexion> entre;
    std::vector<*Conexion> sortie;
    Aeroprt(fstream &stream, std::string delimiter);
    void write (fstream &stream, std::string delimiter);
    void ajouter_connection_entre(*conection);
    void ajouter_connection_sortie(*conection);
    int size_e =0;
    int size_s =0;
};
struct Conexion {
    Aeroprt* entree;
    Aeroprt* sortie;
    float duree;
    Conexion (fstream &stream, std::string delimiter, std::map<std::string ,*Aeroprt> aeroprt);
    void write (fstream &stream, std::string delimiter);
};


#endif //TP4_AEROPRT_H
