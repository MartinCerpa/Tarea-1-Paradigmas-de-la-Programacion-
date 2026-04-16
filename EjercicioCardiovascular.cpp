#include "EjercicioCardiovascular.h"

EjercicioCardiovascular::EjercicioCardiovascular(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUso)
    : Ejercicio(codigo, nombre, nivelIntensidad, tiempoMinutos, descripcion, ultimaSemanaUso) {
}

EjercicioCardiovascular::~EjercicioCardiovascular() {
}

void EjercicioCardiovascular::mostrarInformacion() {
    Ejercicio::mostrarInformacion();
}

string EjercicioCardiovascular::getTipo() {
    return "Cardiovascular";
}