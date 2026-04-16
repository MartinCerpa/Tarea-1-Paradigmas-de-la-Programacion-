#ifndef RUTINA_H
#define RUTINA_H

#include <iostream>
#include <vector>
#include <string>
#include "Ejercicio.h"

using namespace std;

class Rutina {
private:
    string nombreCliente;
    string objetivo;
    int semana;
    vector<Ejercicio*> ejercicios;

public:
    // Constructor
    Rutina(string nombreCliente, string objetivo, int semana);

    // Métodos
    void agregarEjercicio(Ejercicio* e);
    int calcularTiempoTotal();
    void mostrarRutina();
};

#endif