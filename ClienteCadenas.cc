/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica Nº2 : Símbolos, alfabetos y cadenas
 *
 * AUTHOR:  Enrique Álvarez Mesa
 * DATE:    6 Oct 2020
 * EMAIL:   alu0101142104@ull.edu.es
 * VERSION: 1
 * BRIEF:   Contiene la función main del proyecto que usa la clase
 *          Cadenas, donde se recibe un fichero de entrada, un fochero de
 *          salida y un opcode con la operación a realizar sobre las cadenas
 *          que se encuentran en el fichero de entrada para luego escribir en
 *          el fichero de salida el resultado de la operación.
 *
 * SEE: https://www.cplusplus.com/reference/string/string/
 *      https://www.cplusplus.com/reference/vector/vector/
 *
 * COMPILATION: make
 * EXECUTION:   ./Cadenas "ficheroEntrada".txt "ficheroSalida".txt "opcode"
 *
 */

#include "Cadenas.h"


// Comprueba que se pueden abrir los ficheros y que el opcode es válido.
bool comprobaciones(int& argc, char* argv[], int& opcode) {
  std::string fichero_entrada = argv[1];
  std::string fichero_salida  = argv[2];
  
  std::ifstream archivo_entrada(fichero_entrada);
  std::ofstream archivo_salida(fichero_salida);

  if (archivo_entrada.is_open() && archivo_salida.is_open()) {
    archivo_entrada.close();
    archivo_salida.close();
    if (opcode >= 1 && opcode <= 5) {
      return true;
    }
  }
  return false;
}


int main(int argc, char* argv[]) {
  int opcode = atoi(argv[3]);

  if (comprobaciones(argc, argv, opcode)) {
    std::string name;
    std::vector<std::string> vector;
    int lineas = 0;
    std::vector<std::string> alfabeto_;
    std::string linea;
    std::ifstream archivo_entrada(argv[1]);
    while (getline(archivo_entrada, linea, '\n')) {
      lineas++;
      vector.push_back(linea);
    }
    archivo_entrada.close();
    
    // Creo un vector de objetos de la clase Cadenas. Uno para cada cadena.
    std::string cadena;
    std::vector<Cadena> array;
    for (int i = 0; i < lineas; ++i) {
      cadena = vector[i];
      array.push_back(Cadena(cadena, argv[2]));
    }

    for (int i = 0; i < lineas; ++i) {
      switch (opcode) {
      case 1:
          array[i].longuitud();
        break;
      case 2:
          array[i].inversa();
        break;
      case 3:
          array[i].prefijos();
        break;
      case 4:
          array[i].sufijos();
        break;
      case 5:
          array[i].subcadenas();
        break;
      }
    }

  } else {
    std::cout << "Ha ocurrido un error."; 
  }
  return 0;
}