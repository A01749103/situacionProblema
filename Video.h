// video.h
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Video {
   private:
      string id;
      string nombre;
      vector<string> generos;
      int calificaciones;
      int duracion;
      string fechaEstreno;

   public:
      Video(string id, string nombre, vector<string> generos, int calificaciones, int duracion, string fechaEstreno);
      void setCalificacion(int calificacion);
      string getId();
      string getNombre();
      vector<string> getGeneros();
      int getCalificacion();
      int getDuracion();
      string getFechaEstreno();
};
#endif 