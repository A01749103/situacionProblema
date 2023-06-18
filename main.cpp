// main
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "video.h"
#include "serie.h"
#include "episodio.h"
using namespace std;

int main(int argc, char **argv)
{
   vector<Video> videos;
   vector<Serie> series;
   int menu;
   ifstream cvs;
   string nombreArchivo;
   string linea;
   string genero;
   int calificacionMinima;
   string nombreSerie;
   string nombreVideo;
   int nuevaCalificacion;

   vector<string> separar(string linea, char);

   do
   {
      cout << "1. Cargar el archivo de datos en formato csv." << endl;
      cout << "2. Mostrar los videos en general con:" << endl;
      cout << "   - Una calificación mayor o igual al valor seleccionado." << endl;
      cout << "   - Un género específico." << endl;
      cout << "3. Mostrar todos los episodios de una determinada serie." << endl;
      cout << "4. Mostrar las películas con una calificacion mayor al valor seleccionado." << endl;
      cout << "5. Calificar un video." << endl;
      cout << "6. Calcular el promedio de la calificación de una serie." << endl;
      cout << "7. Salir." << endl
           << endl;
      cout << "Seleccione una opción: ";
      cin >> menu;

      switch (menu)
      {
      // 0-ID,1-Nombre Pelicula/Serie,2-Duración,3-Género,4-Calificación,5-Fecha Estreno,6-ID Episodio,7-Nombre Episodio,8-Temporada,9-Num Episodio
      case 1:
         cout << "Ingrese el nombre del archivo: " << endl;
         cin >> nombreArchivo;
         cvs.open(nombreArchivo);
         while (getline(cvs, linea))
         {
            vector<string> datos = separar(linea, ',');
            if (datos.size() == 6)
            {
               // pelicula
               Video pelicula(datos[0], datos[1], separar(datos[3], '&'), stoi(datos[4]), stoi(datos[2]), stoi(datos[5]));
               videos.push_back(pelicula);
            }
            else
            {
               // episodio
               Episodio episodio(datos[0], datos[1], separar(datos[3], '&'), stoi(datos[8]), stoi(datos[9]), stoi(datos[4]), stoi(datos[2]), stoi(datos[5]), datos[7]);
               videos.push_back(episodio);
            }
            bool serieEncontrada = false;
            for (Serie &serie : series)
            {
               if (serie.getId() == datos[0])
               {
                  serie.agregarEpisodio(episodio);
                  serieEncontrada = true;
                  break;
               }
            }
            if (!serieEncontrada)
            {
               Serie nuevaSerie(datos[0], datos[1]);
               nuevaSerie.agregarEpisodio(episodio);
               series.push_back(nuevaSerie);
            }

            separar(linea);
         }
         cvs.close();
         break;
         break;
      case 2:
         // Mostrar los videos en general calif
         cout << "Ingrese la calificación mínima: ";
         cin >> calificacionMinima;
         cout << "Ingrese el género: ";
         cin >> genero;
         for (Video &video : videos)
         {
            if (video.getCalificacion() >= calificacionMinima)
            {
               for (string &g : video.getGeneros())
               {
                  if (g == genero)
                  {
                     cout << video.getNombre() << endl;
                     break;
                  }
               }
            }
         }
         break;

         break;
      case 3:
         // Mostrar todos los episodios de una serie
         cout << "Ingrese el nombre de la serie: ";
         getline(cin, nombreSerie);
         for (Serie &serie : series)
         {
            if (serie.getNombre() == nombreSerie)
            {
               for (Episodio &episodio : serie.getEpisodios())
               {
                  cout << "Temporada " << episodio.getTemporada() << ", Episodio " << episodio.getNumEpisodio() << ": " << episodio.getNombre() << endl;
               }
               break;
            }
         }
         break;
      case 4:
         // Mostrar las películas calif
         cout << "Ingrese la calificación mínima: ";
         cin >> calificacionMinima;
         for (Video &video : videos)
         {
            if (!video.esEpisodio() && video.getCalificacion() > calificacionMinima)
            {
               cout << video.getNombre() << endl;
            }
         }
         break;
      case 5:
         // Calificar un video
         cout << "Ingrese el título de la película o el nombre del episodio de la serie a calificar: ";
         cin.ignore();
         getline(cin, nombreVideo);
         for (Video &video : videos)
         {
            if (video.getNombre() == nombreVideo)
            {
               cout << "Ingrese la nueva calificación: ";
               cin >> nuevaCalificacion;
               video.setCalificacion(nuevaCalificacion);
               break;
            }
         }
         break;
      case 6:
         // Calcular el promedio
         cout << "Ingrese el nombre de la serie: ";
         cin.ignore();
         getline(cin, nombreSerie);
         for (Serie &serie : series)
         {
            if (serie.getNombre() == nombreSerie)
            {
               double sumaCalificaciones = 0;
               int numEpisodios = 0;
               for (Episodio &episodio : serie.getEpisodios())
               {
                  sumaCalificaciones += episodio.getCalificacion();
                  numEpisodios++;
               }
               double promedioCalificaciones = sumaCalificaciones / numEpisodios;
               cout << "El promedio de la calificación de la serie " << serie.getNombre() << " es: " << promedioCalificaciones << endl;
               break;
            }
         }

         break;
      case 7:
         // Salir
         break;
      default:
         cout << "Opción inválida. Intente de nuevo." << endl;
         break;
      }
   } while (menu != 7);
}

vector<string> separar(string linea, char delimitador)
{
   string dato;
   int numComps = 0;
   vector<string> comps;
   stringstream linent(linea);
   while (getline(linent, dato, delimitador))
   {
      if (dato != " " && dato != "\n")
      {
         comps.push_back(dato);
      }
   }
   return comps;
}