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

int main(int argc, char **argv){
   vector<Video> videos;
   vector<Serie> series;
   int menu;
   ifstream cvs;
   string nombreArchivo;
   string linea;
   vector<string> separar(string linea);

   do { 
        cout << "1. Cargar el archivo de datos en formato csv." << endl;
        cout << "2. Mostrar los videos en general con:" << endl;
        cout << "   - Una calificación mayor o igual al valor seleccionado." << endl;
        cout << "   - Un género específico." << endl;
        cout << "3. Mostrar todos los episodios de una determinada serie." << endl;
        cout << "4. Mostrar las películas con una calificacion mayor al valor seleccionado." << endl;
        cout << "5. Calificar un video." << endl;
        cout << "6. Calcular el promedio de la calificación de una serie." << endl;
        cout << "7. Salir." << endl<<endl;
        cout << "Seleccione una opción: ";
        cin >> menu;

        switch (menu) {
            // 0-ID,1-Nombre Pelicula/Serie,2-Duración,3-Género,4-Calificación,5-Fecha Estreno,6-ID Episodio,7-Nombre Episodio,8-Temporada,9-Num Episodio
            case 1:
                // Cargar el archivo de datos en formato csv
                cout << "Ingrese el nombre del archivo: "  << endl;
                cin >> nombreArchivo;
                cvs.open(nombreArchivo);
                while(getline(cvs,linea)){
                  vector<string> datos=separar(linea, ',');
                  if (datos.size()==6){
                     //pelicula
                     Video pelicula(datos[0], datos[1], separar(datos[3], '&'), stoi(datos[4]), stoi(datos[2]), stoi(datos[5]) );
                     videos.push_back(pelicula);
                  }
                  else{
                     //episodio
                      Episodio episodio(datos[0], datos[1], separar(datos[3], '&'), stoi(datos[8]), stoi(datos[9]), stoi(datos[4]), stoi(datos[2]), stoi(datos[5]), datos[7]);
                      videos.push_back(episodio);
                  }
                  
                  separar(linea);
                  }
                  cvs.close();
                break;
            break;
            case 2:
                // Mostrar los videos en general calif

                break;
            case 3:
                // Mostrar todos los episodios de una seria

                break;
            case 4:
                // Mostrar las películas calif

                break;
            case 5:
                // Calificar un video

                break;
            case 6:
                // Calcular el promedio

                break;
            case 7:
                // Salir
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
            break;
        }
   } while (menu!=7);
}

vector<string> separar(string linea, char delimitador){
   string dato;
   int numComps=0;
   vector<string> comps;
   stringstream linent(linea);
   while(getline(linent, dato, delimitador)){
      if (dato!=" "&& dato!="\n"){
         comps.push_back(dato);
      }
   }
   return comps;
}