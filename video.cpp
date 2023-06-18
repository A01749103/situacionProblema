// Autor:Palavicini Saldívar Santiago
// Implementacion de clase video.cpp, definiciones de los métodos dados por video.h
// 18/jun/2023

#include "video.h"
using namespace std;


Video::Video(string id, string nombre, vector<string> generos, int calificacion, int duracion, string fechaEstreno) {
    this->id = id;
    this->nombre = nombre;
    this->generos = generos;
    this->calificacion = calificacion;
    this->duracion = duracion;
    this->fechaEstreno = fechaEstreno;
}

string Video::getId() {
    return id;
}

string Video::getNombre() {
    return nombre;
}

vector<string> Video::getGeneros() {
    return generos;
}

int Video::getCalificacion() {
    return calificacion;
}

void Video::setCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

int Video::getDuracion() {
    return duracion;
}

string Video::getFechaEstreno() {
    return fechaEstreno;
}

bool Video::esEpisodio() {
    return false;
}
