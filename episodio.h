// Autor:Palavicini Saldívar Santiago
// Implementacion de clase episodio.h, declaración de clases, atributos y métodos
// 18/jun/2023

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
#include <vector>
#include "video.h"

class Episodio : public Video {
    private:
        int temporada;
        int numEpisodio;
    public:
        Episodio(std::string id, std::string nombre, int temporada, int numEpisodio, std::vector<std::string> generos, int calificacion, int duracion, std::string fechaEstreno);
        int getTemporada();
        int getNumEpisodio();
        bool esEpisodio();
};

#endif
