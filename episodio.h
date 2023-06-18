// episodio.h
#ifndef EPISODIO_H
#define EPISODIO_H

#include "serie.h"
#include <string>
#include <vector>
using namespace std;

class Episodio : public Serie {
    private:
        int temporada;
        int numEpisodio;
        vector<string> generos;
        int calificacion;
        int duracion;
        string fechaEstreno;
        string nombreEpisodio;

    public:
        Episodio(string id, string nombre, int temporada, int numEpisodio, vector<string> generos, int calificacion, int duracion, string fechaEstreno, string nombreEpisodio);
        int getTemporada();
        int getNumEpisodio();
        vector<string> getGeneros();
        int getCalificacion();
        void setCalificacion(int calificacion);
        int getDuracion();
        string getFechaEstreno();
};

#endif