#ifndef EJERCICIOCARDIOVASCULAR_H
#define EJERCICIOCARDIOVASCULAR_H

#include "Ejercicio.h"

class EjercicioCardiovascular : public Ejercicio {
public:
    EjercicioCardiovascular(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUso);
    ~EjercicioCardiovascular();

    void mostrarInformacion();
    string getTipo();
};

#endif