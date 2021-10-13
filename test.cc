#include "Cadenas.h"

Cadena::Cadena(std::string linea) {
  //std::cout << "Constructor imprime línea:\n" << linea << std::endl;
  identificarCadena(linea);
  inversa();
}


//Cadena::~Cadena() {}


void Cadena::identificarCadena(std::string linea) {
  std::size_t found = linea.find_last_of(" ");
  cadena_ = linea.substr(found + 1);
  std::cout << "\nCadena_: " << cadena_ << std::endl;

  std::istringstream isstream(linea);
  
  while(std::getline(isstream, linea, ' ')) {
    alfabeto_.push_back(linea);
  }

  alfabeto_.pop_back();

  std::cout << "Alfabeto: ";

  for (auto it = alfabeto_.begin(); it != alfabeto_.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << std::endl;
}


/*char Cadena::comprobar(){
  std::cout << "Comprobar." << std::endl;
  bool salida = false;
  while(!salida){
    for (unsigned i = 0; i < cadena_.size(); ++i) {
      for (unsigned j = 0; j < alfabeto_.size(); ++j) {
        std::string aux = alfabeto_[j];
        for (unsigned k = 0; k < aux.size(); ++k) {
          std::cout << cadena_[i] << " " << aux[k] << std::endl;
          if (cadena_[i] == aux[k]) {
            salida = true;
            std::cout << "Está." << std::endl;
            return cadena_[i];
          }
          if (cadena_[i] == ' ')
            return cadena_[i];
        }
      }
    }
  }
  
}*/


void Cadena::inversa() {
  std::string aux3;
  std::cout << "Inversa:" << std::endl;
  std::cout << "Size alfabeto: " << alfabeto_.size() << std::endl;
  bool termina = false;
  unsigned i = 0;
  unsigned j = 0;
  bool encuentra = false;
  std::string comprobando;
  std::string aux;
  int k;
  while(i < cadena_.size()) {
    bool found = false;
    aux = cadena_[i];
    std::cout << "cadena " << aux << std::endl;
    while (j < alfabeto_.size() || encuentra == true) {
      comprobando = alfabeto_[j];
      std::cout << "alfabeto " << comprobando << std::endl;
      if (aux == comprobando) {
        std::cout << "Encuentra simbolo" << std::endl;
        encuentra = true;
        found = true;
        break;
      } else {
        encuentra = false;
      }
      j++;
    }
    k = 0;
    while (encuentra == false) {
      aux = aux + alfabeto_[k]
    }
    j = 0;
    i++;
  }
  i = 0;
}
//for (unsigned i = 0; i < array.size(); ++i) {
      //array[i].comprobar();
    //}
    /*

    // Extracción de las cadenas.
    std::vector<std::string> cadenas;
    std::string cadena;
    for (unsigned i = 0; i < vector.size(); ++i) {
      
      std::size_t found = vector[i].find_last_of(" ");
      cadena = vector[i].substr(found + 1);

      //std::cout << "linea: " << cadena << std::endl;
      //found = linea1.find('\n');
      //linea1 = linea1.substr(found);
      
      cadenas.push_back(cadena);
    }
    std::cout << std::endl;
    
    // Normal.
    std::cout << "Normal:" << std::endl;
    int size_total = 0;
    for (unsigned i = 0; i < vector.size(); ++i) {
      std::cout << cadenas[i] << std::endl;
      size_total = size_total + cadenas[i].size();
    }
    std::cout << size_total << std::endl;
    std::cout << std::endl;

    // Inversa.
    std::cout << "Inversa:" << std::endl;
    for (unsigned i = 0; i < vector.size(); ++i) {
      std::string cadena_inversa (cadenas[i].rbegin(), cadenas[i].rend());
      std::cout << cadena_inversa << std::endl;
    }

    std::cout << std::endl;
    
    // Caracter a caracter.
    std::cout << "Caracteres:" << std::endl;
    std::string cadena_caracteres;
    for (unsigned i = 0; i < vector.size(); ++i) {
      for (std::string::iterator it = cadenas[i].begin(); it != cadenas[i].end(); ++it) {
        //std::cout << cadenas[i] << std::endl;
        std::cout <<*it << std::endl;
        cadena_caracteres.push_back(*it);
      }
    }

    std::cout << std::endl;

    int vector_size1 = cadena_caracteres.size();
    
    std::cout << vector_size1 << std::endl;

    for (int i = 0; i < vector_size1; ++i) {
      std::cout << cadena_caracteres[i] << std::endl;
      if (cadena_caracteres[i] == ' ')
        std::cout << "Cacota" << std::endl;
    }

    std::cout << std::endl;

    // Prefijos.
    std::vector<std::string> prefijos;
    std::string aux;
    for (std::string::iterator it = cadenas[1].begin(); it != cadenas[1].end() - 2; ++it) {
      aux.push_back(*it);
      prefijos.push_back(aux);
    }
    std::cout << "Prefijos:" << std::endl;
    for (unsigned i = 0; i < prefijos.size(); ++i) {
      std::cout << prefijos[i]<< std::endl;
    }

    std::cout << std::endl;
    
    // Sufijos.
    std::cout << std::endl;
    std::vector<std::string> sufijos;
    std::string aux1;
    for (std::string::iterator it = cadenas[1].end() - 2; it != cadenas[1].begin(); --it) {
      aux1.push_back(*it);
      sufijos.push_back(aux1);
    }
    std::cout << "Sufijos:" << std::endl;
    for (unsigned i = 0; i < sufijos.size(); ++i) {
      std::cout << sufijos[i]<< std::endl;
    }

    std::cout << std::endl;
    
    // Subcadenas.
    std::vector<std::string> subcadenas;
    std::string aux2;
    std::string aux3;
    for (unsigned k = 0; k != cadenas.size(); ++k) {
      aux2 = cadenas[k];
      for (unsigned i = 0; i != aux2.size() - 1; ++i) {
        aux3 = aux2[i]; 
        for (unsigned j = i + 1; j != aux2.size() - 1; ++j) {
          // Debo moverme en la cadena con dos bucles. 
          aux3 = aux3 + aux2[j];
          //std::cout << aux3 << std::endl;
          subcadenas.push_back(aux3);
        }
      }
    }
    std::cout << "Subcadenas:" << std::endl;
    for (unsigned i = 0; i < subcadenas.size(); ++i) {
      std::cout << subcadenas[i]<< std::endl;
    }

    std::cout << std::endl;

  */