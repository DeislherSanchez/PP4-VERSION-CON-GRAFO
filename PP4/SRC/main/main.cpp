/*****Datos administrativos************************
 * Nombre del archivo: main.cpp
 * Tipo de archivo: Código fuente
 * Proyecto: Gestión de Tareas y Proyectos
 * Autor: Deislher Sánchez, Yeremi Calvo, Sidney Salazar
 * Empresa: Tecnológico de Costa Rica
 *****Descripción**********************************
 * Archivo principal que inicializa la aplicación 
 * gráfica de gestión de tareas utilizando Gtkmm.
 *****Versión**************************************
 * 1.0 | [17-11-2024 12:15] | [Deislher Sánchez]
 **************************************************/

#include <gtkmm.h>
#include "/home/jahir/Downloads/PP4/SRC/views/gestorTareas.h"

/*****Nombre***************************************
 * main
 *****Descripción**********************************
 * Función principal que ejecuta la aplicación 
 * gráfica de gestión de tareas.
 *****Retorno**************************************
 * Código de salida del programa (0 si se ejecuta correctamente).
 *****Entradas*************************************
 * - argc: Número de argumentos de línea de comandos.
 * - argv: Vector de argumentos de línea de comandos.
 **************************************************/
int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.gestortareas");

    return app->make_window_and_run<VentanaPrincipal>(argc, argv);
}
