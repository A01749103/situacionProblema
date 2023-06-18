//episodio
#include "episodio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Episodio::Episodio(std::string id, std::string nombre, int temporada, int numEpisodio, std::vector<std::string> generos, int calificacion, double duracion, std::string fechaEstreno)
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
