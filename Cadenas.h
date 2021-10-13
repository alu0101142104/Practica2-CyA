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
 * BRIEF:   Contiene la definición de la clase Cadenas.
 *
 * SEE: https://www.cplusplus.com/reference/string/string/
 *      https://www.cplusplus.com/reference/vector/vector/
 *
 * COMPILATION: make
 * EXECUTION:   ./Cadenas "ficheroEntrada".txt "ficheroSalida".txt "opcode"
 *
 */


#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include <sstream>

#include <cstdlib>

class Cadena{
  public:
    Cadena(std::string, std::string);
    ~Cadena();
    void longuitud();
    void inversa();
    void prefijos();
    void sufijos();
    void subcadenas();
    
  private:
    void identificarCadena(std::string);
    void compruebaCadena();
    void preparaSalida(std::vector<std::string> vector);
    void escribirFichero();

    std::vector<std::string> alfabeto_;
    std::vector<std::string> vector_simbolos_;
    
    std::string cadena_;
    std::string fichero_salida_;
    std::string cadena_salida_;
};