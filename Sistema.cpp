#include "Sistema.h"

void Sistema::menu() {
    int opcion;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Crear ejercicio" << endl;
        cout << "2. Listar ejercicios" << endl;
        cout << "3. Buscar por intensidad" << endl;
        cout << "4. Eliminar ejercicio" << endl;
        cout << "5. Actualizar ejercicio" << endl;
        cout << "6. Consultar ejercicio por codigo" << endl;
        cout << "7. Generar rutina" << endl;
        cout << "0. Salir" << endl;
        cout << "\n===========" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida." << endl;
            opcion = -1;
            continue;
        }

        cin.ignore(10000, '\n');
        cout << "\n===========" << endl;

        switch(opcion) {
            case 1:
                crearEjercicio();
                break;
            case 2:
                listarEjercicios();
                break;
            case 3:
                buscarPorIntensidad();
                break;
            case 4:
                eliminarEjercicio();
                break;
            case 5:
                actualizarEjercicio();
                break;
            case 6:
                consultarEjercicio();
                break;
            case 7:
                generarRutina();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }

    } while(opcion != 0);
}

void Sistema::crearEjercicio() {
    int codigo, tiempo, tipo, opcionIntensidad;
    string nombre, intensidad, descripcion;
    bool codigoRepetido;

    cout << "\n=== CREAR EJERCICIO ===" << endl;

    // Validar codigo entero y que no se repita
    while (true) {
        cout << "Codigo (numero entero): ";
        cin >> codigo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        codigoRepetido = false;
        for (int i = 0; i < ejercicios.size(); i++) {
            if (ejercicios[i]->getCodigo() == codigo) {
                codigoRepetido = true;
                break;
            }
        }

        if (codigoRepetido) {
            cout << "Error: ya existe un ejercicio con ese codigo. Intente con otro." << endl;
        } else {
            break;
        }
    }

    // Validar nombre no vacio
    do {
        cout << "Nombre: ";
        getline(cin, nombre);

        if (nombre.empty()) {
            cout << "El nombre no puede estar vacio." << endl;
        }
    } while (nombre.empty());

    // Validar intensidad con menu
    while (true) {
        cout << "Nivel de intensidad:" << endl;
        cout << "1. Basico" << endl;
        cout << "2. Intermedio" << endl;
        cout << "3. Avanzado" << endl;
        cout << "4. Alto rendimiento" << endl;
        cout << "Opcion: ";
        cin >> opcionIntensidad;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar 1, 2, 3 o 4." << endl;
            continue;
        }

        cin.ignore(10000, '\n');
        cout << endl;

        if (opcionIntensidad == 1) {
            intensidad = "Basico";
            break;
        } else if (opcionIntensidad == 2) {
            intensidad = "Intermedio";
            break;
        } else if (opcionIntensidad == 3) {
            intensidad = "Avanzado";
            break;
        } else if (opcionIntensidad == 4) {
            intensidad = "Alto rendimiento";
            break;
        } else {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }

    // Validar tiempo entero positivo
    while (true) {
        cout << "Tiempo estimado (en minutos): ";
        cin >> tiempo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (tiempo <= 0) {
            cout << "El tiempo debe ser mayor a 0." << endl;
        } else {
            break;
        }
    }

    // Validar descripcion no vacia
    do {
        cout << "Descripcion: ";
        getline(cin, descripcion);

        if (descripcion.empty()) {
            cout << "La descripcion no puede estar vacia." << endl;
        }
    } while (descripcion.empty());

    // Validar tipo con menu
    while (true) {
        cout << "Tipo de ejercicio:" << endl;
        cout << "1. Cardiovascular" << endl;
        cout << "2. Fuerza" << endl;
        cout << "Opcion: ";
        cin >> tipo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar 1 o 2." << endl;
            continue;
        }

        cin.ignore(10000, '\n');
        cout << endl;

        if (tipo == 1 || tipo == 2) {
            break;
        } else {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }

    // -1 significa "nunca usado"
    if (tipo == 1) {
        ejercicios.push_back(new EjercicioCardiovascular(codigo, nombre, intensidad, tiempo, descripcion, -1));
    } else {
        ejercicios.push_back(new EjercicioFuerza(codigo, nombre, intensidad, tiempo, descripcion, -1));
    }

    cout << "Ejercicio creado correctamente!" << endl;
}

void Sistema::listarEjercicios() {
    if (ejercicios.size() == 0) {
        cout << "No hay ejercicios registrados." << endl;
        return;
    }

    for(int i = 0; i < ejercicios.size(); i++) {
        ejercicios[i]->mostrarInformacion();
        cout << "----------------" << endl;
    }
}

void Sistema::buscarPorIntensidad() {
    string intensidad;
    int opcionIntensidad;
    bool encontrado = false;

    cout << "\n=== BUSCAR POR INTENSIDAD ===" << endl;
    cout << "1. Basico" << endl;
    cout << "2. Intermedio" << endl;
    cout << "3. Avanzado" << endl;
    cout << "4. Alto rendimiento" << endl;
    cout << "Opcion: ";
    cin >> opcionIntensidad;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida." << endl;
        return;
    }

    cin.ignore(10000, '\n');
    cout << endl;

    if (opcionIntensidad == 1) {
        intensidad = "Basico";
    } else if (opcionIntensidad == 2) {
        intensidad = "Intermedio";
    } else if (opcionIntensidad == 3) {
        intensidad = "Avanzado";
    } else if (opcionIntensidad == 4) {
        intensidad = "Alto rendimiento";
    } else {
        cout << "Opcion invalida." << endl;
        return;
    }

    for (int i = 0; i < ejercicios.size(); i++) {
        if (ejercicios[i]->getNivelIntensidad() == intensidad) {
            ejercicios[i]->mostrarInformacion();
            cout << "----------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron ejercicios con intensidad " << intensidad << "." << endl;
    }
}

void Sistema::eliminarEjercicio() {
    int codigo;

    while (true) {
        cout << "Codigo a eliminar: ";
        cin >> codigo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }

    for(int i = 0; i < ejercicios.size(); i++) {
        if(ejercicios[i]->getCodigo() == codigo) {
            delete ejercicios[i];
            ejercicios.erase(ejercicios.begin() + i);
            cout << "Eliminado!" << endl;
            return;
        }
    }

    cout << "No encontrado" << endl;
}

void Sistema::actualizarEjercicio() {
    int codigo;
    bool encontrado = false;

    while (true) {
        cout << "Codigo del ejercicio a actualizar: ";
        cin >> codigo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }

    for (int i = 0; i < ejercicios.size(); i++) {
        if (ejercicios[i]->getCodigo() == codigo) {
            string nuevoNombre, nuevaIntensidad, nuevaDescripcion;
            int nuevoTiempo, nuevaSemana, opcionIntensidad;

            cout << "\n=== ACTUALIZAR EJERCICIO ===" << endl;

            do {
                cout << "Nuevo nombre: ";
                getline(cin, nuevoNombre);

                if (nuevoNombre.empty()) {
                    cout << "El nombre no puede estar vacio." << endl;
                }
            } while (nuevoNombre.empty());

            while (true) {
                cout << "Nuevo nivel de intensidad:" << endl;
                cout << "1. Basico" << endl;
                cout << "2. Intermedio" << endl;
                cout << "3. Avanzado" << endl;
                cout << "4. Alto rendimiento" << endl;
                cout << "Opcion: ";
                cin >> opcionIntensidad;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Entrada invalida. Debe ingresar 1, 2, 3 o 4." << endl;
                    continue;
                }

                cin.ignore(10000, '\n');
                cout << endl;

                if (opcionIntensidad == 1) {
                    nuevaIntensidad = "Basico";
                    break;
                } else if (opcionIntensidad == 2) {
                    nuevaIntensidad = "Intermedio";
                    break;
                } else if (opcionIntensidad == 3) {
                    nuevaIntensidad = "Avanzado";
                    break;
                } else if (opcionIntensidad == 4) {
                    nuevaIntensidad = "Alto rendimiento";
                    break;
                } else {
                    cout << "Opcion invalida. Intente nuevamente." << endl;
                }
            }

            while (true) {
                cout << "Nuevo tiempo estimado (en minutos): ";
                cin >> nuevoTiempo;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
                    continue;
                }

                cin.ignore(10000, '\n');

                if (nuevoTiempo <= 0) {
                    cout << "El tiempo debe ser mayor a 0." << endl;
                } else {
                    break;
                }
            }

            do {
                cout << "Nueva descripcion: ";
                getline(cin, nuevaDescripcion);

                if (nuevaDescripcion.empty()) {
                    cout << "La descripcion no puede estar vacia." << endl;
                }
            } while (nuevaDescripcion.empty());

            while (true) {
                cout << "Nueva ultima semana de uso: ";
                cin >> nuevaSemana;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
                    continue;
                }

                cin.ignore(10000, '\n');

                if (nuevaSemana < 0) {
                    cout << "La semana no puede ser negativa." << endl;
                } else {
                    break;
                }
            }

            ejercicios[i]->setNombre(nuevoNombre);
            ejercicios[i]->setNivelIntensidad(nuevaIntensidad);
            ejercicios[i]->setTiempoMinutos(nuevoTiempo);
            ejercicios[i]->setDescripcion(nuevaDescripcion);
            ejercicios[i]->setUltimaSemanaUso(nuevaSemana);

            cout << "Ejercicio actualizado correctamente!" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro un ejercicio con ese codigo." << endl;
    }
}

void Sistema::consultarEjercicio() {
    int codigo;
    bool encontrado = false;

    while (true) {
        cout << "Codigo del ejercicio a consultar: ";
        cin >> codigo;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }

    for (int i = 0; i < ejercicios.size(); i++) {
        if (ejercicios[i]->getCodigo() == codigo) {
            cout << "\n=== EJERCICIO ENCONTRADO ===" << endl;
            ejercicios[i]->mostrarInformacion();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro un ejercicio con ese codigo." << endl;
    }
}

void Sistema::generarRutina() {
    string nombreCliente, objetivo, intensidad;
    int semana, cantidad, opcionIntensidad;
    int contador = 0;

    if (ejercicios.size() == 0) {
        cout << "No hay ejercicios registrados para generar una rutina." << endl;
        return;
    }

    cout << "\n=== GENERAR RUTINA ===" << endl;

    do {
        cout << "Nombre del cliente: ";
        getline(cin, nombreCliente);

        if (nombreCliente.empty()) {
            cout << "El nombre del cliente no puede estar vacio." << endl;
        }
    } while (nombreCliente.empty());

    do {
        cout << "Objetivo de la rutina: ";
        getline(cin, objetivo);

        if (objetivo.empty()) {
            cout << "El objetivo no puede estar vacio." << endl;
        }
    } while (objetivo.empty());

    while (true) {
        cout << "Semana de la rutina: ";
        cin >> semana;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (semana < 0) {
            cout << "La semana no puede ser negativa." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Cantidad de ejercicios: ";
        cin >> cantidad;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar un numero entero." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        if (cantidad <= 0) {
            cout << "La cantidad debe ser mayor a 0." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Nivel de intensidad:" << endl;
        cout << "1. Basico" << endl;
        cout << "2. Intermedio" << endl;
        cout << "3. Avanzado" << endl;
        cout << "4. Alto rendimiento" << endl;
        cout << "Opcion: ";
        cin >> opcionIntensidad;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada invalida. Debe ingresar 1, 2, 3 o 4." << endl;
            continue;
        }

        cin.ignore(10000, '\n');
        cout << endl;

        if (opcionIntensidad == 1) {
            intensidad = "Basico";
            break;
        } else if (opcionIntensidad == 2) {
            intensidad = "Intermedio";
            break;
        } else if (opcionIntensidad == 3) {
            intensidad = "Avanzado";
            break;
        } else if (opcionIntensidad == 4) {
            intensidad = "Alto rendimiento";
            break;
        } else {
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }

    Rutina r(nombreCliente, objetivo, semana);

    for (int i = 0; i < ejercicios.size() && contador < cantidad; i++) {
        if (ejercicios[i]->getNivelIntensidad() == intensidad &&
            (ejercicios[i]->getUltimaSemanaUso() == -1 || ejercicios[i]->getUltimaSemanaUso() != semana - 1)) {

            r.agregarEjercicio(ejercicios[i]);
            ejercicios[i]->setUltimaSemanaUso(semana);
            contador++;
        }
    }

    if (contador == 0) {
        cout << "No se pudieron agregar ejercicios para esa rutina." << endl;
        cout << "Puede que no existan ejercicios con esa intensidad o que fueron usados la semana anterior." << endl;
        return;
    }

    if (contador < cantidad) {
        cout << "Solo se pudieron agregar " << contador
             << " ejercicios de los " << cantidad << " solicitados." << endl;
    }

    r.mostrarRutina();
}