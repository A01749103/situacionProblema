// Autor:Palavicini Saldívar Santiago
// Implementacion de clase serie.cpp, definiciones de los métodos dados por serie.h
// 18/jun/2023

#include "serie.h"
#include <iostream>
using namespace std;

Serie::Serie(string id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

string Serie::getId() {
    return id;
}

string Serie::getNombre() {
    return nombre;
}

void Serie::agregarEpisodio(Episodio episodio) {
    episodios.push_back(episodio);
}

vector<Episodio> Serie::getEpisodios() {
    return episodios;
}
