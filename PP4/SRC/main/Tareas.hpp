#ifndef TAREAS_HPP
#define TAREAS_HPP

#include "String.hpp"
#include <iostream>

class Tarea {
private:
    int aId;
    String aNombre;
    int aDuracion;
    String** apRecursos;

public:
    Tarea(String nombre, int duracion)
        : aNombre(nombre), aDuracion(duracion), apRecursos(nullptr) {}

    ~Tarea() {
        int i = 0;
        while (apRecursos && apRecursos[i] != nullptr) {
            delete apRecursos[i];
            i++;
        }
        delete[] apRecursos;
    }

    String getNombre() { return aNombre; }
    int getDuracion() { return aDuracion; }
    String** getRecursos() { return apRecursos; }

    // Nuevo método para contar el número de recursos
    int getCantidadRecursos() const {
        int cantidad = 0;
        if (apRecursos != nullptr) {
            while (apRecursos[cantidad] != nullptr) {
                cantidad++;
            }
        }
        return cantidad;
    }

    void setNombre(String nuevoNombre) {
        aNombre = nuevoNombre;
    }

    void setDuracion(int nuevaDuracion) {
        aDuracion = nuevaDuracion;
    }

    void setRecursos(String** nuevosRecursos) {
        if (apRecursos != nullptr) {
            int i = 0;
            while (apRecursos[i] != nullptr) {
                delete apRecursos[i];
                i++;
            }
            delete[] apRecursos;
        }
        int cantidad = 0;
        while (nuevosRecursos[cantidad] != nullptr) {
            cantidad++;
        }
        apRecursos = new String*[cantidad + 1];
        for (int i = 0; i < cantidad; i++) {
            apRecursos[i] = new String(*nuevosRecursos[i]); 
        }
        apRecursos[cantidad] = nullptr; 

        
    }


    void agregarRecurso(String* nuevoRecurso) {
        int cantidad = getCantidadRecursos(); 
        String** nuevaLista = new String*[cantidad + 2];
        for (int i = 0; i < cantidad; i++) {
            nuevaLista[i] = apRecursos[i];
        }
        // Agregar el nuevo recurso
        nuevaLista[cantidad] = nuevoRecurso;
        nuevaLista[cantidad + 1] = nullptr;
        delete[] apRecursos;
        apRecursos = nuevaLista;
    }
};

#endif // TAREAS_HPP
