//
// Created by vuilletg on 3/13/26.
//

#ifndef TP4_AEROPRT_H
#define TP4_AEROPRT_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Aeroprt {
    std::string nom;
    std::string id;
    int lat;
    int lon;
    std::vector<*Conexion> entre;
    std::vector<*Conexion> sortie;
public:
    Aeroprt(fstream &stream, std::string delimiter);
    void write (fstream &stream, std::string delimiter);
    void ajouter_connection_entre(*conection);
    void ajouter_connection_sortie(*conection);

};
class Conexion {
    Aeroprt* entree;
    Aeroprt* sortie;
    float duree;
public:
    Conexion (fstream &stream, std::string delimiter, std::map<std::string ,*Aeroprt> aeroprt);
    void write (fstream &stream, std::string delimiter);
};


#endif //TP4_AEROPRT_H
