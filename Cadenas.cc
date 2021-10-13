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
 * BRIEF:   Contiene la implementación de la clase Cadenas.
 * SEE: https://www.cplusplus.com/reference/string/string/
 *      https://www.cplusplus.com/reference/vector/vector/
 *
 * COMPILATION: make
 * EXECUTION:   ./Cadenas "ficheroEntrada".txt "ficheroSalida".txt "opcode"
 *
 */

#include "Cadenas.h"
#include <iostream>
#include <fstream>


// Constructor.
Cadena::Cadena(std::string linea, std::string fichero_salida) {
  fichero_salida_ = fichero_salida;
  identificarCadena(linea);
  compruebaCadena();
  std::cout << std::endl;
}


// Destructor.
Cadena::~Cadena() {}


// A partir de una linea leida del fichero se identifica la cadena y el alfabeto
// correspondiente.
void Cadena::identificarCadena(std::string linea) {
  std::size_t buscado = linea.find_last_of(" ");
  cadena_ = linea.substr(buscado + 1);
  char caracter = cadena_.back();

  // Se elimina de la cadena el último caracter si este es un retorno de carro '\n'.
  if (caracter == 13)
    cadena_.pop_back();

  std::cout << "\nCadena_: " << cadena_ << std::endl;
  std::istringstream isstream(linea);
  
  while(std::getline(isstream, linea, ' ')) {
    alfabeto_.push_back(linea);
  }

  alfabeto_.pop_back();

  std::string aux;
  if (alfabeto_.empty()) {
    for (unsigned i = 0; i < cadena_.size(); ++i) {
      aux = cadena_[i];
      alfabeto_.push_back(aux);
    }
  }
  std::cout << "Alfabeto: ";
  for (auto it = alfabeto_.begin(); it != alfabeto_.end(); ++it)
    std::cout << *it << ' ';
  
  std::cout << std::endl;
  std::cout << "Size alfabeto: " << alfabeto_.size() << std::endl;
}


// Separa los simbolos de una cadena en funcion de su alfabeto para luego
// realizar la operacion sobre ellos.
void Cadena::compruebaCadena(){
  unsigned i = 0, j = 0;
  std::string simbolo;
  std::string aux;

  if (alfabeto_.size() == 0)
    std::cout << "buscado vacio" << '\n';
 
  while(i < cadena_.size() && !alfabeto_.empty()) {
    bool buscado = false;
    aux = cadena_[i];
    while(j < alfabeto_.size()) {
      simbolo = alfabeto_[j];
      if (aux == simbolo){
        vector_simbolos_.push_back(aux); 
        buscado = true;
        break;
      }
      j++;
    }
    int sumador = 1;
    while(!buscado) {
      j = 0;
      aux = aux + cadena_[i + sumador];
      while(j < alfabeto_.size()) {
        simbolo = alfabeto_[j];
        if (aux == simbolo) {
          vector_simbolos_.push_back(aux);
          ++i;
          buscado = true;
          break;
        }
        j++;
      }
    }
    j = 0;
    i++;
  }
  
  std::cout << "Vector de simbolos: ";
  for (unsigned i = 0; i < vector_simbolos_.size(); ++i)
    std::cout << vector_simbolos_[i] << ' ';
  std::cout << std::endl;
}


// Indica la longuitud de una cadena.
void Cadena::longuitud() {
  std::vector<std::string> longuitud;
  int longuitud_cadena = cadena_.size();
  std::string aux = std::to_string(longuitud_cadena);

  std::cout << "Longuitud: ";
  std::cout << longuitud_cadena << std::endl;

  longuitud.push_back(aux);

  preparaSalida(longuitud);
}


// Calcula la inversa de una cadena.
void Cadena::inversa() {
  std::vector<std::string> inversa;
  std::string aux;

  for (auto it = vector_simbolos_.end() - 1; it >= vector_simbolos_.begin(); --it)
    aux = aux + *it;
  inversa.push_back(aux);

  std::cout << "Inversa: ";
  for (unsigned i = 0; i < inversa.size(); ++i)
    std::cout << inversa[i];
  std::cout << std::endl;

  preparaSalida(inversa);
}


// Calcula los prefijos de una cadena.
void Cadena::prefijos() {
  std::vector<std::string> prefijos;
  std::string aux;

  prefijos.push_back("&");
  for (unsigned i = 0; i < vector_simbolos_.size(); ++i) {
    aux = aux + vector_simbolos_[i];
    prefijos.push_back(aux);
  }

  std::cout << "Prefijos: ";
  for (unsigned i = 0; i < prefijos.size(); ++i)
    std::cout << prefijos[i] << ' ';
  std::cout << std::endl;

  preparaSalida(prefijos);
}


// Calcula los sufijos de una cadena.
void Cadena::sufijos() {
  std::vector<std::string> sufijos;
  std::string aux;
  
  sufijos.push_back("&");
  for (auto it = vector_simbolos_.end() - 1; it >= vector_simbolos_.begin(); --it) {
    aux = *it + aux;
    sufijos.push_back(aux);
  }

  std::cout << "Sufijos: ";
  for (unsigned i = 0; i < sufijos.size(); ++i)
    std::cout << sufijos[i] << ' ';
  std::cout << std::endl;

  preparaSalida(sufijos);
}


// Calcula las subcadenas de una cadena.
void Cadena::subcadenas() {
  std::vector<std::string> subcadenas;

  subcadenas.push_back("&");
  for (unsigned k = 0; k != vector_simbolos_.size(); ++k) {
    std::string aux;
    for (unsigned i = k; i != vector_simbolos_.size(); ++i) {
      aux = aux + vector_simbolos_[i];
      subcadenas.push_back(aux);
    }
  }
  std::cout << "Subcadenas: ";
  for (unsigned i = 0; i < subcadenas.size(); ++i) {
    std::cout << subcadenas[i] << ' ';
  }
  std::cout << std::endl;
  preparaSalida(subcadenas);
}


// Prepara el resultado de una operacion para ser escrita en un fichero de
// salida.
void Cadena::preparaSalida(std::vector<std::string> vector){
  for (unsigned i = 0; i < vector.size(); ++i) {
    cadena_salida_ = cadena_salida_ + vector[i] + ' ';
  }
  cadena_salida_ = cadena_salida_ + '\n';
  escribirFichero();
}


// Escribe una de la operaciones en un fichero de salida.
void Cadena::escribirFichero() {
  std::ofstream fichero_salida;
  fichero_salida.open(fichero_salida_, std::ios::app);
  fichero_salida << cadena_salida_;
  fichero_salida.close();
}