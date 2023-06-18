// Autor:Palavicini Saldívar Santiago
// Implementacion de clase video.h, declaración de clases, atributos y métodos
// 18/jun/2023

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>

class Video {
    protected:
        std::string id;
        std::string nombre;
        std::vector<std::string> generos;
        int calificacion;
        int duracion;
        std::string fechaEstreno;
    public:
        Video(std::string id, std::string nombre, std::vector<std::string> generos, int calificacion, int duracion, std::string fechaEstreno);
        std::string getId();
        std::string getNombre();
        std::vector<std::string> getGeneros();
        int getCalificacion();
        void setCalificacion(int calificacion);
        int getDuracion();
        std::string getFechaEstreno();
        virtual bool esEpisodio();
};

#endif
