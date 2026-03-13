//
// Created by vuilletg on 3/13/26.
//

#ifndef TP4_AEROPRT_H
#define TP4_AEROPRT_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <map>
struct Aeroprt;
struct Conexion;
struct Aeroprt {
    std::string nom;
    std::string id;
    double latitude;
    double longitude;
    static std::vector<std::shared_ptr<Aeroprt>> aeroport;
    std::vector<std::shared_ptr<Conexion>> entre;
    std::vector<std::shared_ptr<Conexion>> sortie;
    Aeroprt(std::fstream stream, std::string delimiter);
    void write (std::fstream stream, std::string delimiter);
    void ajouter_connection_entre(std::shared_ptr<Conexion> conection);
    void ajouter_connection_sortie(std::shared_ptr<Conexion> conection);
    int size_e =0;
    int size_s =0;
    int size_a =0;
};
struct Conexion {
    std::shared_ptr<Aeroprt> entree;
    std::shared_ptr<Aeroprt> sortie;
    float duree;
    Conexion (std::fstream stream, std::string delimiter, std::map<std::string ,std::shared_ptr<Aeroprt>> aeroprt);
    void write (std::fstream stream, std::string delimiter);
};


#endif //TP4_AEROPRT_H
