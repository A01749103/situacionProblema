//episodio
#include "episodio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Episodio::Episodio(string id, string nombre, vector<string> generos, int temporada, int numEpisodio, int calificacion, int duracion, string fechaEstreno, string nombreEpisodio) :Serie(id, nombre){
    this->temporada = temporada;
    this->numEpisodio = numEpisodio;
    this->generos = generos;
    this->calificacion = calificacion;
    this->duracion = duracion;
    this->fechaEstreno = fechaEstreno;
    this->nombreEpisodio = nombreEpisodio;
}
int Episodio::getTemporada() {
    return temporada;
}
int Episodio::getNumEpisodio() {
    return numEpisodio;
}
vector<string> Episodio::getGeneros() {
    return generos;
} 
int Episodio::getCalificacion() {
    return calificacion;
}
void Episodio::setCalificacion(int calificacion) {
    this->calificacion = calificacion;
}
int Episodio::getDuracion() {
    return duracion;
}
string Episodio::getFechaEstreno() {
    return fechaEstreno;
}