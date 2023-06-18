// main
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
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
   double calificacionMinima;
   string nombreSerie;
   string nombreVideo;
   double nuevaCalificacion;

   vector<string> separar(string linea, char);

   do
   {
      cout << left << setw(5) << "1." << "Cargar el archivo de datos en formato csv." << endl;
cout << left << setw(5) << "2." << "Mostrar los videos en general con:" << endl;
cout << setw(8) << "" << "- Una calificación mayor o igual al valor seleccionado." << endl;
cout << setw(8) << "" << "- Un género específico." << endl;
cout << left << setw(5) << "3." << "Mostrar todos los episodios de una determinada serie." << endl;
cout << left << setw(5) << "4." << "Mostrar las películas con una calificacion mayor al valor seleccionado." << endl;
cout << left << setw(5) << "5." << "Calificar un video." << endl;
cout << left << setw(5) << "6." << "Calcular el promedio de la calificación de una serie."<<endl;
cout<<left<<setw(5)<<"7."<<"Salir"<<endl<<endl;
cout<<left<<setw(30)<<"Seleccione una opción: ";
cin>>menu;

      switch (menu)
      {
      case 1:
    // Cargar el archivo de datos en formato csv
    cout << left << setw(30) << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    cvs.open(nombreArchivo);
    if (!cvs.is_open())
    {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        break;
    }
    getline(cvs, linea);
    while (getline(cvs, linea))
    {
        vector<string> datos = separar(linea, ',');
        if (datos.size() == 10 && datos[6].empty())
        {
            // Película
            Video pelicula(datos[0], datos[1], separar(datos[3], '&'), stoi(datos[4]), stoi(datos[2]), datos[5]);
            videos.push_back(pelicula);
            cout << left << setw(20) << "Película creada: " << pelicula.getNombre() << endl;
        }
        else if (datos.size() == 10)
        {
            // Episodio
            Episodio episodio(datos[6], datos[7], stoi(datos[8]), stoi(datos[9]), separar(datos[3], '&'), stoi(datos[4]), stoi(datos[2]), datos[5]);
            videos.push_back(episodio);
            cout << left << setw(20) << "Episodio creado: " << episodio.getNombre() << endl;
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
                cout << left << setw(20) << "Serie creada: " << nuevaSerie.getNombre() << endl;
            }
        }
    }
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
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         getline(cin, nombreVideo);
         for (Video &video : videos)
         {
            if (video.getNombre() == nombreVideo)
            {
               while (true)
               {
                  cout << "Ingrese la nueva calificación: ";
                  if (cin >> nuevaCalificacion)
                  {
                     break;
                  }
                  else
                  {
                     cout << "Entrada inválida. Intente de nuevo." << endl;
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  }
               }
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