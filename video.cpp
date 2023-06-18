// video.cpp
#include "video.h"

Video::Video(string id, string nombre, vector<string> generos, double calificacion, int duracion, string fechaEstreno) {
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

double Video::getCalificacion() {
    return calificacion;
}

void Video::setCalificacion(double calificacion) {
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
