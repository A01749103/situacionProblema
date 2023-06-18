// episodio.h
#ifndef EPISODIO_H
#define EPISODIO_H

#include "video.h"
#include <string>
#include <vector>
using namespace std;

class Episodio : public Video {
    private:
        int temporada;
        int numEpisodio;
    public:
        Episodio(string id, string nombre, int temporada, int numEpisodio, vector<string> generos, int calificacion, int duracion, string fechaEstreno);
        int getTemporada();
        int getNumEpisodio();
        bool esEpisodio();
};

#endif