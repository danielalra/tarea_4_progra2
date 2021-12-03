#include "operacionSuma.h"
#include <string>
#include <sstream>

OperacionSuma::OperacionSuma() {
}

string OperacionSuma::Ejecute(string valores) {

    string resultado {};

    std::istringstream stream(valores);

    int numero1 = 0;
    int numero2 = 0;
    string signo = "";
    
    stream >> numero1 >> signo >> numero2;
    
    resultado = to_string(numero1+numero2);

    return resultado;
}