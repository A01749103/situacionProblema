// serie.h
#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <vector>
#include "episodio.h"
using namespace std;

class Serie {
    private:
        string id;
        string nombre;
        vector<Episodio> episodios;
    public:
        Serie(string id, string nombre);
        string getId();
        string getNombre();
        void agregarEpisodio(Episodio episodio);
        vector<Episodio> getEpisodios();
};

#endif
