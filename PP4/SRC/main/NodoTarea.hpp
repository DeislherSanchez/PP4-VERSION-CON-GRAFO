#ifndef NODOTAREA_HPP
#define NODOTAREA_HPP

#include "Tareas.hpp"
#include "Dependencia.hpp"
#include <iostream>

class NodoTarea {
private:
    Tarea aTarea;               
    Dependencia* apDependencias;

public:
  
    NodoTarea(const Tarea& tarea) : aTarea(tarea), apDependencias(nullptr) {}
    ~NodoTarea() {
        while (apDependencias) {
            Dependencia* temp = apDependencias;
            apDependencias = apDependencias->getSiguiente();
            delete temp;
        }
    }

    Tarea getTarea() const { return aTarea; }
    void setTarea(const Tarea& nuevaTarea) { aTarea = nuevaTarea; }

    void agregarDependencia(int idDestino, int peso) {
        Dependencia* nueva = new Dependencia(idDestino, peso);
        nueva->setSiguiente(apDependencias);
        apDependencias = nueva;
    }


    void eliminarDependencia(int idDestino) {
        Dependencia** actual = &apDependencias;
        while (*actual) {
            if ((*actual)->getIdDestino() == idDestino) {
                Dependencia* temp = *actual;
                *actual = (*actual)->getSiguiente();
                delete temp;
                return;
            }
            actual = &(*actual)->getSiguiente();
        }
    }


    void imprimirNodo() const {
        std::cout << "Tarea: " << aTarea.getNombre().mostrarCadena()
                  << " (Duración: " << aTarea.getDuracion() << ")\n";
        std::cout << "Dependencias:\n";
        Dependencia* actual = apDependencias;
        while (actual) {
            std::cout << "  -> Nodo ID: " << actual->getIdDestino()
                      << ", Peso: " << actual->getPeso() << "\n";
            actual = actual->getSiguiente();
        }
    }
};

#endif // NODOTAREA_HPP
