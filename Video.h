// video.h
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
using namespace std;

class Video {
    protected:
        string id;
        string nombre;
        vector<string> generos;
        int calificacion;
        int duracion;
        string fechaEstreno;
    public:
        Video(string id, string nombre, vector<string> generos, double calificacion, int duracion, string fechaEstreno);
        string getId();
        string getNombre();
        vector<string> getGeneros();
        int getCalificacion();
        void setCalificacion(int calificacion);
        int getDuracion();
        string getFechaEstreno();
        virtual bool esEpisodio();
};

#endif