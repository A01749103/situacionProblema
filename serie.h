// Autor:Palavicini Saldívar Santiago
// Implementacion de clase serie.h, declaración de clases, atributos y métodos
// 18/jun/2023

#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <vector>
#include "episodio.h"

class Serie {
    private:
        std::string id;
        std::string nombre;
        std::vector<Episodio> episodios;
    public:
        Serie(std::string id, std::string nombre);
        std::string getId();
        std::string getNombre();
        void agregarEpisodio(Episodio episodio);
        std::vector<Episodio> getEpisodios();
};

#endif
