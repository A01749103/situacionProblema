// main
#include "video.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Video::Video(string id, string nombre, vector<string> generos, int calificacion, int duracion, string fechaEstreno){
   this->id = id;
   this->nombre = nombre;
   this->generos = generos;
   this->duracion = duracion;
   this->fechaEstreno = fechaEstreno;
   this-> calificacion = calificacion;
}
void Video::setCalificacion(int calificacion) { 
   this->calificacion = calificacion; 
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
int Video::getDuracion() {
    return duracion;
}
std::string Video::getFechaEstreno() {
    return fechaEstreno;
}