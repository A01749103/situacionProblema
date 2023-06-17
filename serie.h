// serie.h
#ifndef SERIE_H
#define SERIE_H

#include <string>
#include <vector>
using namespace std;

class Serie {
   protected:
      string id;
      string nombre;

   public:
      Serie(string id, string nombre);
      string getId();
      string getNombre();
};
#endif