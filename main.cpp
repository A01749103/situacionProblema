// Autor:Palavicini Saldívar Santiago
// Implementación de la clase main, donde se despliega el menu dado en el archivo README por medio de in switch
// 18/jun/2023

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
      cout << endl
           << "\033[35m----------------------------------------\033[0m" << endl;
      cout << left << setw(5) << "1."
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
           << "Salir" << endl;
      cout << "\033[35m----------------------------------------\033[0m" << endl;
      cout << left << setw(5) << "Seleccione una opción: ";
      cin >> menu;

      switch (menu)
      {
      case 1:
         // Cargar el archivo de datos en formato csv
         cout << left << setw(30) << "Ingrese el nombre del archivo: ";
         cin >> nombreArchivo;
         cvs.open(nombreArchivo);

         // Verificar si el archivo se abrió correctamente
         if (!cvs.is_open())
         {
            cout << endl
                 << "\033[31mNo se pudo abrir el archivo " << nombreArchivo << "\033[0m" << endl
                 << "El nombre de archivo debe incluir su terminación, ej. 'NombreArchivo.csv'" << endl
                 << endl;
            break;
         }

         // Leer la primera línea del archivo (encabezados)
         getline(cvs, linea);

         // Mensaje pa que se vea bonito
         cout << endl
              << "Cargando datos..." << endl;
         cout << "\033[35m----------------------------------------\033[0m" << endl;

         // Leer las líneas restantes del archivo (datos)
         while (getline(cvs, linea))
         {
            vector<string> datos = separar(linea, ',');

            // Crear objetos según el tipo de dato
            if (datos.size() == 10 && datos[6].empty())
            {
               // Película
               Video pelicula(datos[0], datos[1], separar(datos[3], '&'), stoi(datos[4]), stoi(datos[2]), datos[5]);
               videos.push_back(pelicula);
               cout << left << setw(20) << "\033[32mPelícula creada:\033[0m " << pelicula.getNombre() << endl;
            }
            else if (datos.size() == 10)
            {
               // Episodio
               Episodio episodio(datos[6], datos[7], stoi(datos[8]), stoi(datos[9]), separar(datos[3], '&'), stoi(datos[4]), stoi(datos[2]), datos[5]);
               videos.push_back(episodio);
               cout << left << setw(20) << "\033[32mEpisodio creado:\033[0m " << episodio.getNombre() << endl;

               // Agregar el episodio a la serie correspondiente
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
                  cout << left << setw(20) << "\033[32mSerie creada:\033[0m " << nuevaSerie.getNombre() << endl;
               }
            }
         }

         // Mensaje pa que se vea bonito
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         cout << "\033[32mDatos cargados correctamente.\033[0m" << endl;
         break;

      case 2:
         // Mostrar los videos en general con una calificación mayor o igual al valor seleccionado y un género específico
         cout << "Ingrese la calificación mínima: ";
         // Validar la entrada
         while (!(cin >> calificacionMinima))
         {
            cout << "\033[31mError: por favor ingrese un valor numérico válido para la calificación mínima:\033[0m ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         // Solicitar el género
         cout << "Ingrese el género: ";
         cin >> genero;
         cout << endl;
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         // Recorrer la lista de videos y mostrar aquellos que cumplan con las características ingresadas
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
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         // Mensaje pa que se vea bonito
         if (numVideosEncontrados == 0)
         {
            cout << "\033[31mNo se encontraron películas o episodios que cumplan con las características ingresadas.\033[0m" << endl
                 << endl;
         }
         break;

      case 3:
         // Mostrar todos los episodios de una determinada serie
         cout << "Ingrese el nombre de la serie: ";
         cin.ignore();
         getline(cin, nombreSerie);
         cout << endl;
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         // Recorrer la lista de series y mostrar los episodios de la serie seleccionada
         for (Serie &serie : series)
         {
            if (serie.getNombre() == nombreSerie)
            {
               serieEncontrada = true;
               for (Episodio &episodio : serie.getEpisodios())
               {
                  cout << "\033[32mTemporada " << episodio.getTemporada() << ",\033[0m \033[33mEpisodio " << episodio.getNumEpisodio() << ":\033[0m " << episodio.getNombre() << endl;
               }
               break;
            }
         }
         // Mostrar un mensaje si no se encontró una serie con el nombre ingresado
         if (!serieEncontrada)
         {
            cout << "\033[31mNo se encontró una serie con el nombre ingresado.\033[0m" << endl;
         }
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         // Mensaje pa que se vea bonito
         if (!serieEncontrada)
         {
            cout << "\033[31mNo se encontró una serie con el nombre ingresado.\033[0m" << endl
                 << endl;
         }
         break;

      case 4:
         // Mostrar las películas con una calificacion mayor al valor seleccionado
         cout << "Ingrese la calificación mínima: ";
         // Validar entrada
         while (!(cin >> calificacionMinima))
         {
            cout << endl
                 << "\033[31mError: por favor ingrese un valor numérico válido para la calificación mínima:\033[0m ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         cout << endl;
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         // Recorrer la lista de videos y mostrar las películas que cumplan con las características
         for (Video &video : videos)
         {
            if (!video.esEpisodio() && video.getCalificacion() > calificacionMinima)
            {
               cout << video.getNombre() << endl;
               numPeliculasEncontradas++;
            }
         }
         cout << "\033[35m----------------------------------------\033[0m" << endl;
         // Mensaje pa que se vea bonito
         if (numPeliculasEncontradas == 0)
         {
            cout << "\033[31mNo se encontraron películas con una calificación mayor al valor seleccionado.\033[0m" << endl
                 << endl;
         }
         break;

      case 5:
         // Calificar un video
         cout << "Ingrese el título de la película o el nombre del episodio de la serie a calificar: ";
         cin.ignore();
         getline(cin, nombreVideo);
         cout << endl;
         // Recorrer la lista de videos y actualizar la calificación del video seleccionado
         for (Video &video : videos)
         {
            if (video.getNombre() == nombreVideo)
            {
               videoEncontrado = true;
               cout << "Ingrese la nueva calificación: ";
               while (!(cin >> nuevaCalificacion))
               {
                  cout << "\033[31mError: por favor ingrese un valor númerico válido para la nueva calificación:\033[0m ";
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               video.setCalificacion(nuevaCalificacion);
               break;
            }
         }
         // Mensaje pa que se vea bonito
         if (!videoEncontrado)
         {
            cout << "\033[31mNo se encontró una película o episodio con el título ingresado.\033[0m" << endl
                 << endl;
         }
         break;

      case 6:
         // Calcular el promedio de la calificación de una serie
         cout << "Ingrese el nombre de la serie: ";
         cin.ignore();
         getline(cin, nombreSerie);
         serieEncontrada = false;
         // Recorrer la lista de series y calcular el promedio de calificaciones de la serie seleccionada
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
                  cout << "El promedio de la calificación de la serie " << serie.getNombre() << " es: " << promedioCalificaciones << endl
                       << endl;
               }
               // Mensaje pa que se vea bonito
               else
               {
                  cout << "\033[31mLa serie no tiene episodios.\033[0m" << endl
                       << endl;
               }
               break;
            }
         }
         // Mensaje pa que se vea bonito
         if (!serieEncontrada)
         {
            cout << "\033[31mNo se encontró una serie con el nombre ingresado.\033[0m" << endl
                 << endl;
         }
         break;

      case 7:
         // Salir
         cout << "\033[32mGracias por utilizar el programa. ¡Hasta la próxima:)!\033[0m" << endl;
         break;

      default:
         // Mostrar un mensaje de error si la opción ingresada es inválida (menu)
         cout << left << setw(30) << "\033[31mOpción inválida. Intente de nuevo.\033[0m" << endl
              << endl;
         break;
      }

   } while (menu != 7);
};

// Función para separar una cadena en componentes utilizando un delimitador
vector<string> separar(string linea, char delimitador)
{
   string dato;
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
