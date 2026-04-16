#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>
#include "Ejercicio.h"
#include "EjercicioCardiovascular.h"
#include "EjercicioFuerza.h"
#include "Rutina.h"

using namespace std;

class Sistema {
private:
    vector<Ejercicio*> ejercicios;

public:
    void menu();

    void crearEjercicio();
    void listarEjercicios();
    void buscarPorIntensidad();
    void eliminarEjercicio();
    void actualizarEjercicio();
    void consultarEjercicio();
    void generarRutina();
};

#endif