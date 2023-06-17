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

   public:
      Episodio(int temporada, int numEpisodio, vector<string> generos, int calificacion, int duracion, string fechaEstreno);
      int getTemporada();
      int getNumEpisodio();
      vector<string> getGeneros();
      int getCalificacion();
      void setCalificacion(int calificacion);
      int getDuracion();
      string getFechaEstreno();
};
#endif