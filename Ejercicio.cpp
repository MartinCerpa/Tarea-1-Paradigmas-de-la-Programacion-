#include "Ejercicio.h"

Ejercicio::Ejercicio(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUso) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->nivelIntensidad = nivelIntensidad;
    this->tiempoMinutos = tiempoMinutos;
    this->descripcion = descripcion;
    this->ultimaSemanaUso = ultimaSemanaUso;
}

Ejercicio::~Ejercicio() {
}

void Ejercicio::mostrarInformacion() {
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << getTipo() << endl;
    cout << "Nivel de intensidad: " << nivelIntensidad << endl;
    cout << "Tiempo estimado: " << tiempoMinutos << " minutos" << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Ultima semana de uso: " << ultimaSemanaUso << endl;
}

string Ejercicio::getTipo() {
    return "General";
}

int Ejercicio::getCodigo() {
    return codigo;
}

string Ejercicio::getNivelIntensidad() {
    return nivelIntensidad;
}

int Ejercicio::getTiempoMinutos() {
    return tiempoMinutos;
}

string Ejercicio::getNombre() {
    return nombre;
}

int Ejercicio::getUltimaSemanaUso() {
    return ultimaSemanaUso;
}

void Ejercicio::setNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

void Ejercicio::setNivelIntensidad(string nuevoNivel) {
    nivelIntensidad = nuevoNivel;
}

void Ejercicio::setTiempoMinutos(int nuevoTiempo) {
    tiempoMinutos = nuevoTiempo;
}

void Ejercicio::setDescripcion(string nuevaDescripcion) {
    descripcion = nuevaDescripcion;
}

void Ejercicio::setUltimaSemanaUso(int nuevaSemana) {
    ultimaSemanaUso = nuevaSemana;
}