// Fichero: subimagen.cpp
// Genera una copia de de una imagen PGM a partir de otra imagen PGM
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  int fila, columna, filas_sub, cols_sub;
  Image image, subimagen;

  // Comprobar validez de la llamada
  if (argc != 7){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino> <fil> " 
         << "<<col> < filas_sub> <cols_sub>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  fila = atoi(argv[3]);
  columna = atoi(argv[4]);
  filas_sub = atoi(argv[5]);
  cols_sub = atoi(argv[6]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  if (!image.Load(origen)){
    cerr << "Error: No pudo leerse la imagen origen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

  // Calcular la subimagen
  subimagen = image.Crop(fila, columna, filas_sub, cols_sub);

  // Guardar la imagen resultado en el fichero
  if (subimagen.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  return 0;
}