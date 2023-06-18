// episodio.cpp
#include "episodio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Episodio::Episodio(string id, string nombre, int temporada, int numEpisodio, vector<string> generos, double calificacion, int duracion, string fechaEstreno)
: Video(id, nombre, generos, calificacion, duracion, fechaEstreno) {
    this->temporada = temporada;
    this->numEpisodio = numEpisodio;
}

int Episodio::getTemporada() {
    return temporada;
}

int Episodio::getNumEpisodio() {
    return numEpisodio;
}

bool Episodio::esEpisodio() {
    return true;
}
