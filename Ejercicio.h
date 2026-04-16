#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <iostream>
#include <string>
using namespace std;

class Ejercicio {
protected:
    int codigo;
    string nombre;
    string nivelIntensidad;
    int tiempoMinutos;
    string descripcion;
    int ultimaSemanaUso;

public:
    Ejercicio(int codigo, string nombre, string nivelIntensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUso);
    virtual ~Ejercicio();

    virtual void mostrarInformacion();
    virtual string getTipo();

    int getCodigo();
    string getNivelIntensidad();
    int getTiempoMinutos();
    string getNombre();
    int getUltimaSemanaUso();

    void setNombre(string nuevoNombre);
    void setNivelIntensidad(string nuevoNivel);
    void setTiempoMinutos(int nuevoTiempo);
    void setDescripcion(string nuevaDescripcion);
    void setUltimaSemanaUso(int nuevaSemana);
};

#endif