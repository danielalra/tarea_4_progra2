#ifndef UNIT_TEST

#include "procesadorInstrucciones.h"
#include "identificadorOperaciones.h"
#include "operacionHola.h"
#include "operacionSuma.h"

#include <iostream>
#include <string>
#include <fstream>

#include "proveedorFormato.h"
#include "proveedorFormatoDesdeStream.h"

using namespace std;

int main() {

    try {
        // Inicialización
        // Configuración de la inyección de dependencias
        map<string, Operacion *> operaciones {};

        std::ifstream ifs("formato.ini", std::ifstream::in);

        if (!ifs.is_open())
        {
            std::cerr << "Error leyendo archivo formato.ini" << std::endl;
            return -1;
        }

        ProveedorFormato *proveedorFormato = new ProveedorFormatoDesdeStream(&ifs);

        OperacionHola *operacionHola = new OperacionHola(proveedorFormato);
        operaciones.insert(std::pair<string, Operacion *>("hola", operacionHola));

        //funcionalidad del hello
        std::ifstream ifs2("formato2.ini", std::ifstream::in);

        if (!ifs2.is_open())
        {
            std::cerr << "Error leyendo archivo formato2.ini" << std::endl;
            return -1;
        }

        ProveedorFormato *proveedorFormato2 = new ProveedorFormatoDesdeStream(&ifs2);

        OperacionHola *operacionHello = new OperacionHola(proveedorFormato2);
        operaciones.insert(std::pair<string, Operacion *>("hello", operacionHello));

        //operacion suma
        OperacionSuma *operacionSuma = new OperacionSuma();
        operaciones.insert(std::pair<string, Operacion *>("suma", operacionSuma)); 

        IdentificadorOperacionesBase *identificadorOperaciones = new IdentificadorOperaciones(operaciones);
        // Fin de inicialización 
        
        ProcesadorInstrucciones *procesador = new ProcesadorInstrucciones(identificadorOperaciones);
        string resultado1 = procesador->Procese("hola", "todos");
        string resultado2 = procesador->Procese("hello", "everyone");
        string resultado3 = procesador->Procese("suma", "2 + 3");

        cout << "Resultado1: " << resultado1 << endl;
        cout << "Resultado2: " << resultado2 << endl;
        cout << "Resultado3: " << resultado3 << endl;

        // Cerrar archivo de entrada
        ifs.close();
        ifs2.close();

    } catch (char const* exception)
    {
        cerr << "Error: " << exception << endl;
    }

    return 0;
}

#endif