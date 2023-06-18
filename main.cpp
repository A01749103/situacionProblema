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
   double calificacionMinima = 0;
   string nombreSerie;
   string nombreVideo;
   double nuevaCalificacion;
   int numVideosEncontrados = 0;
   int numPeliculasEncontradas = 0;
   bool serieEncontrada = false;
   bool videoEncontrado = false;
   double sumaCalificaciones = 0;
   int numEpisodios = 0;

   vector<string> separar(string linea, char);

   do
   {
      cout <<endl<< left << setw(5) << "1."
           << "Cargar el archivo que contiene los datos (obligatorio como primer paso)." << endl;
      cout << left << setw(5) << "2."
           << "Mostrar los videos en general con:" << endl;
      cout << setw(8) << ""
           << "- Una calificación mayor o igual al valor seleccionado." << endl;
      cout << setw(8) << ""
           << "- Un género específico." << endl;
      cout << left << setw(5) << "3."
           << "Mostrar todos los episodios de una determinada serie." << endl;
      cout << left << setw(5) << "4."
           << "Mostrar las películas con una calificacion mayor al valor seleccionado." << endl;
      cout << left << setw(5) << "5."
           << "Calificar un video." << endl;
      cout << left << setw(5) << "6."
           << "Calcular el promedio de la calificación de una serie." << endl;
      cout << left << setw(5) << "7."
           << "Salir" << endl
           << endl;
      cout << left << setw(30) << "Seleccione una opción: ";
      cin >> menu;

      switch (menu)
      {
      case 1:
         // Cargar el archivo de datos en formato csv
         cout << left << setw(30) << "Ingrese el nombre del archivo: ";
         cin >> nombreArchivo;
         cvs.open(nombreArchivo);
      
         if (!cvs.is_open())
         {
            cout << endl<<"No se pudo abrir el archivo " << nombreArchivo << endl
                 << "El nombre de archivo debe incluir su terminación, ej. 'NombreArchivo.csv'" << endl<< endl<<endl;
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
         // Mostrar los videos en general con una calificación mayor o igual al valor seleccionado y un género específico
         cout << "Ingrese la calificación mínima: ";
         while (!(cin >> calificacionMinima))
         {
            cout << "Error: por favor ingrese un valor numérico válido para la calificación mínima: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         cout << "Ingrese el género: ";
         cin >> genero;
         cout<<endl;
         for (Video &video : videos)
         {
            if (video.getCalificacion() >= calificacionMinima)
            {
               for (string &g : video.getGeneros())
               {
                  if (g == genero)
                  {
                     cout << video.getNombre() << endl;
                     numVideosEncontrados++;
                     break;
                  }
               }
            }
         }
         if (numVideosEncontrados == 0)
         {
            cout << "No se encontraron películas o episodios que cumplan con las características ingresadas." << endl<< endl<<endl;
         }
         break;

      case 3:
         // Mostrar todos los episodios de una determinada serie
         cout << "Ingrese el nombre de la serie: ";
         cin.ignore();
         getline(cin, nombreSerie);
         cout<<endl;
         for (Serie &serie : series)
         {
            if (serie.getNombre() == nombreSerie)
            {
               serieEncontrada = true;
               for (Episodio &episodio : serie.getEpisodios())
               {
                  cout << "Temporada " << episodio.getTemporada() << ", Episodio " << episodio.getNumEpisodio() << ": " << episodio.getNombre() << endl;
               }
               break;
            }
         }
         if (!serieEncontrada)
         {
            cout << "No se encontró una serie con el nombre ingresado." << endl<< endl<<endl;
         }
         break;

      case 4:
         // Mostrar las películas con una calificacion mayor al valor seleccionado
         cout << "Ingrese la calificación mínima: ";
         while (!(cin >> calificacionMinima))
         {
            cout <<endl<<  "Error: por favor ingrese un valor numérico válido para la calificación mínima: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         cout<<endl;
         for (Video &video : videos)
         {
            if (!video.esEpisodio() && video.getCalificacion() > calificacionMinima)
            {
               cout << video.getNombre() << endl;
               numPeliculasEncontradas++;
            }
         }
         if (numPeliculasEncontradas == 0)
         {
            cout << "No se encontraron películas con una calificación mayor al valor seleccionado." << endl<< endl<<endl;
         }
         break;

      case 5:
         // Calificar un video
         cout << "Ingrese el título de la película o el nombre del episodio de la serie a calificar: ";
         cin.ignore();
         getline(cin, nombreVideo);
         cout<<endl;
         for (Video &video : videos)
         {
            if (video.getNombre() == nombreVideo)
            {
               videoEncontrado = true;
               cout << "Ingrese la nueva calificación: ";
               while (!(cin >> nuevaCalificacion))
               {
                  cout << "Error: por favor ingrese un valor númerico válido para la nueva calificación: ";
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               video.setCalificacion(nuevaCalificacion);
               break;
            }
         }
         if (!videoEncontrado)
         {
            cout << "No se encontró una película o episodio con el título ingresado." << endl<< endl<<endl;
         }
         break;

      case 6:
         // Calcular el promedio de la calificación de una serie
         cout << "Ingrese el nombre de la serie: ";
         cin.ignore();
         getline(cin, nombreSerie);
         serieEncontrada = false;
         cout<<endl;
         for (Serie &serie : series)
         {
            if (serie.getNombre() == nombreSerie)
            {
               serieEncontrada = true;
               for (Episodio &episodio : serie.getEpisodios())
               {
                  sumaCalificaciones += episodio.getCalificacion();
                  numEpisodios++;
               }
               if (numEpisodios > 0)
               {
                  double promedioCalificaciones = sumaCalificaciones / numEpisodios;
                  cout << "El promedio de la calificación de la serie " << serie.getNombre() << " es: " << promedioCalificaciones << endl<< endl<<endl;
               }
               else
               {
                  cout << "La serie no tiene episodios." << endl<< endl<<endl;
               }
               break;
            }
         }
         if (!serieEncontrada)
         {
            cout << "No se encontró una serie con el nombre ingresado." << endl<< endl<<endl;
         }
         break;

      case 7:
         // Salir
         break;

      default:
         cout << left << setw(30) << "Opción inválida. Intente de nuevo." << endl<<endl<<endl;
         break;
      }
      
   }while (menu != 7);
};

vector<string> separar(string linea, char delimitador) {
    string dato;
    vector<string> comps;
    stringstream linent(linea);
    while (getline(linent, dato, delimitador)) {
        if (dato != " " && dato != "\n") {
            comps.push_back(dato);
        }
    }
    return comps;
}