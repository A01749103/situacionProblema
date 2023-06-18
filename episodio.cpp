// Autor:Palavicini Saldívar Santiago
// Implementacion de clase episodio.cpp, definiciones de los métodos dados por episodio.h
// 18/jun/2023

#include "episodio.h"

Episodio::Episodio(std::string id, std::string nombre, int temporada, int numEpisodio, std::vector<std::string> generos, int calificacion, int duracion, std::string fechaEstreno)
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
