#ifndef EJERCICIOFUERZA_H
#define EJERCICIOFUERZA_H

#include "Ejercicio.h"

class EjercicioFuerza : public Ejercicio {
public:
    EjercicioFuerza(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUso);
    ~EjercicioFuerza();

    void mostrarInformacion();
    string getTipo();
};

#endif