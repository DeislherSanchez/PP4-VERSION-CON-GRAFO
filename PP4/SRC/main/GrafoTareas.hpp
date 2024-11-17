/*****Datos administrativos************************
 * Nombre del archivo: GrafoDeTareas.hpp
 * Tipo de archivo: Encabezado
 * Proyecto: Gestión de Tareas y Proyectos
 * Autor: Deislher Sánchez, Yeremi Calvo, Sidney Salazar
 * Empresa: Tecnológico de Costa Rica
 *****Descripción**********************************
 * Clase que representa un grafo de tareas, donde 
 * cada nodo es una tarea y puede tener dependencias.
 *****Versión**************************************
 * 1.0 | [17-11-2024 11:22] | [Deislher Sánchez]
 **************************************************/

#ifndef GRAFODETAREAS_HPP
#define GRAFODETAREAS_HPP

#include "Nodo.hpp"
#include <iostream>

/*****Nombre***************************************
 * GrafoDeTareas
 *****Descripción**********************************
 * Clase que implementa un grafo dinámico para la 
 * gestión de tareas - Proyectos y sus dependencias.
 *****Atributos************************************
 * - apNodos: Arreglo dinámico de nodos.
 * - aCantidadNodos: Número actual de nodos.
 * - aCapacidad: Capacidad máxima del arreglo.
 *****Métodos**************************************
 * - agregarTarea: Agrega una tarea al grafo.
 * - agregarDependencia: Crea una relación de dependencia 
 *   entre dos tareas.
 * - eliminarDependencia: Elimina una relación de 
 *   dependencia entre dos tareas.
 * - obtenerNodo: Obtiene un nodo del grafo.
 * - eliminarNodo: Elimina un nodo del grafo.
 * - mostrarGrafo: Muestra en consola el contenido del grafo.
 **************************************************/
class GrafoDeTareas {
private:
    Nodo** apNodos;          // Arreglo dinámico de nodos
    int aCantidadNodos;      // Número de nodos actuales
    int aCapacidad;          // Capacidad máxima del arreglo

    /*****Nombre***************************************
     * redimensionar
     *****Descripción**********************************
     * Duplica la capacidad del arreglo dinámico de nodos.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    void redimensionar() {
        int nuevaCapacidad = aCapacidad * 2;
        Nodo** nuevoArreglo = new Nodo*[nuevaCapacidad];

        for (int i = 0; i < aCantidadNodos; i++) {
            nuevoArreglo[i] = apNodos[i];
        }

        delete[] apNodos;
        apNodos = nuevoArreglo;
        aCapacidad = nuevaCapacidad;
    }

public:
    /*****Nombre***************************************
     * GrafoDeTareas (constructor)
     *****Descripción**********************************
     * Inicializa el grafo con una capacidad predeterminada.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - capacidadInicial: Capacidad inicial del grafo.
     **************************************************/
    GrafoDeTareas(int capacidadInicial = 10)
        : apNodos(new Nodo*[capacidadInicial]), aCantidadNodos(0), aCapacidad(capacidadInicial) {}

    /*****Nombre***************************************
     * ~GrafoDeTareas (destructor)
     *****Descripción**********************************
     * Libera la memoria utilizada por los nodos del grafo.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    ~GrafoDeTareas() {
        for (int i = 0; i < aCantidadNodos; i++) {
            delete apNodos[i];
        }
        delete[] apNodos;
    }

    /*****Nombre***************************************
     * agregarTarea
     *****Descripción**********************************
     * Agrega una nueva tarea al grafo.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - pTarea: Puntero a la tarea a agregar.
     **************************************************/
    void agregarTarea(Tarea* pTarea) {
        if (aCantidadNodos == aCapacidad) {
            redimensionar();
        }
        apNodos[aCantidadNodos++] = new Nodo(pTarea);
    }

    /*****Nombre***************************************
     * agregarDependencia
     *****Descripción**********************************
     * Crea una relación de dependencia entre dos tareas.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - idOrigen: ID del nodo origen.
     * - idDestino: ID del nodo destino.
     **************************************************/
    void agregarDependencia(int idOrigen, int idDestino) {
        if (idOrigen < 0 || idOrigen >= aCantidadNodos || idDestino < 0 || idDestino >= aCantidadNodos) {
            std::cerr << "Error: ID de tarea fuera de rango.\n";
            return;
        }
        apNodos[idOrigen]->agregarDependencia(apNodos[idDestino]);
    }

    /*****Nombre***************************************
     * eliminarDependencia
     *****Descripción**********************************
     * Elimina una relación de dependencia entre dos tareas.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - idOrigen: ID del nodo origen.
     * - idDestino: ID del nodo destino.
     **************************************************/
    void eliminarDependencia(int idOrigen, int idDestino) {
        if (idOrigen < 0 || idOrigen >= aCantidadNodos || idDestino < 0 || idDestino >= aCantidadNodos) {
            std::cerr << "Error: ID de tarea fuera de rango.\n";
            return;
        }

        Nodo* nodoOrigen = apNodos[idOrigen];
        Nodo** dependencias = nodoOrigen->getDependencias();
        int cantidadDependencias = nodoOrigen->getCantidadDependencias();
        Nodo** nuevasDependencias = new Nodo*[cantidadDependencias - 1];
        int nuevasCantidad = 0;

        for (int i = 0; i < cantidadDependencias; i++) {
            if (dependencias[i] != apNodos[idDestino]) {
                nuevasDependencias[nuevasCantidad++] = dependencias[i];
            }
        }

        if (nuevasCantidad == cantidadDependencias) {
            std::cerr << "Error: La dependencia especificada no existe.\n";
            delete[] nuevasDependencias;
            return;
        }

        nodoOrigen->setDependencias(nuevasDependencias, nuevasCantidad);
    }

    /*****Nombre***************************************
     * obtenerNodo
     *****Descripción**********************************
     * Devuelve el nodo correspondiente al ID especificado.
     *****Retorno**************************************
     * Puntero al nodo.
     *****Entradas*************************************
     * - id: ID del nodo a obtener.
     **************************************************/
    Nodo* obtenerNodo(int id) {
        if (id < 0 || id >= aCantidadNodos) {
            std::cerr << "Error: ID fuera de rango.\n";
            return nullptr;
        }
        return apNodos[id];
    }

    /*****Nombre***************************************
     * eliminarNodo
     *****Descripción**********************************
     * Elimina un nodo y ajusta el grafo.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * - id: ID del nodo a eliminar.
     **************************************************/
    void eliminarNodo(int id) {
        if (id < 0 || id >= aCantidadNodos) {
            std::cerr << "Error: ID fuera de rango.\n";
            return;
        }

        delete apNodos[id];

        for (int i = id; i < aCantidadNodos - 1; i++) {
            apNodos[i] = apNodos[i + 1];
        }
        aCantidadNodos--;

        for (int i = 0; i < aCantidadNodos; i++) {
            Nodo** dependencias = apNodos[i]->getDependencias();
            int cantidadDependencias = apNodos[i]->getCantidadDependencias();
            Nodo** nuevasDependencias = new Nodo*[cantidadDependencias];
            int nuevasCantidad = 0;

            for (int j = 0; j < cantidadDependencias; j++) {
                if (dependencias[j] != apNodos[id]) {
                    nuevasDependencias[nuevasCantidad++] = dependencias[j];
                }
            }

            delete[] dependencias;
            apNodos[i]->setDependencias(nuevasDependencias, nuevasCantidad);
        }
    }

    /*****Nombre***************************************
     * mostrarGrafo
     *****Descripción**********************************
     * Muestra en consola las tareas y sus dependencias.
     *****Retorno**************************************
     * Ninguno.
     *****Entradas*************************************
     * Ninguna.
     **************************************************/
    void mostrarGrafo() {
        for (int i = 0; i < aCantidadNodos; i++) {
            Nodo* nodo = apNodos[i];
            std::cout << "Tarea ID: " << i << " - Nombre: " 
                      << nodo->getTarea()->getNombre().mostrarCadena() << "\n";

            for (int j = 0; j < nodo->getCantidadDependencias(); j++) {
                std::cout << "  -> Depende de: " 
                          << nodo->getDependencias()[j]->getTarea()->getNombre().mostrarCadena() << "\n";
            }
        }
    }
};

#endif // GRAFODETAREAS_HPP
