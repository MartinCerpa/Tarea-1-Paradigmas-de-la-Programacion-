#include "EjercicioFuerza.h"

EjercicioFuerza::EjercicioFuerza(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUso)
    : Ejercicio(codigo, nombre, nivelIntensidad, tiempoMinutos, descripcion, ultimaSemanaUso) {
}

EjercicioFuerza::~EjercicioFuerza() {
}

void EjercicioFuerza::mostrarInformacion() {
    Ejercicio::mostrarInformacion();
}

string EjercicioFuerza::getTipo() {
    return "Fuerza";
}