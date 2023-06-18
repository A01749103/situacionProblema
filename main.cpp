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
        
            case 1:
                //Cargar el archivo 
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

vector<string> separar(string linea){
   string dato;
   int numComps;
   vector<string> comps;
   stringstream linent(linea);
   while(getline(linent, dato, ',')){
      if (dato!=" "&& dato!="\n"){
         cout<<dato<<endl;
         comps.push_back(dato);
         numComps++;
      }
   }
   cout<<"número de componentes: "<<numComps<<endl;
   return comps;
}