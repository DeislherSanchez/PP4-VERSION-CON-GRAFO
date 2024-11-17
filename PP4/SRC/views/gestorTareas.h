#ifndef VENTANA_PRINCIPAL_H
#define VENTANA_PRINCIPAL_H

#include "/home/jahir/Downloads/PP4/SRC/main/String.hpp"
#include "/home/jahir/Downloads/PP4/SRC/main/Tareas.hpp"
#include "/home/jahir/Downloads/PP4/SRC/main/GrafoTareas.hpp"
#include <regex>
#include <gtkmm.h>

class VentanaPrincipal : public Gtk::Window {
private:
    
    GrafoDeTareas grafo;
    Tarea** tareas;
    int cantidadTareas;
  
    bool validar_datos_tarea(const Glib::ustring& nombre_tarea, 
                             const Glib::ustring& duracion_tarea, 
                             const Glib::ustring& recursos_tarea, 
                             std::string& mensaje_error);
    bool validar_nombre(const Glib::ustring& nombre_tarea, std::string& mensaje_error);
    bool validar_duracion(const Glib::ustring& duracion_tarea, std::string& mensaje_error);
    bool validar_recursos(const Glib::ustring& recursos_tarea, std::string& mensaje_error);

    String convertir_a_String(const Glib::ustring& entrada) {
        return String(entrada.raw().c_str());
    }



    void mostrarDatosTarea(Tarea* tarea);


    bool existeTarea(const Glib::ustring& nombre_tarea) {
        String nombre = convertir_a_String(nombre_tarea);
        for (int i = 0; i < cantidadTareas; ++i) {
            if (tareas[i]->getNombre() == nombre) {
                return true;
            }
        }
        return false;
    }

public:
    // Constructor y destructor
    VentanaPrincipal();
    virtual ~VentanaPrincipal();

protected:
    // Métodos relacionados con la navegación de frames
    void crear_frame_tarea();
    void regresar_frame_tarea();
    void crear_frame_eliminar_tarea();
    void regresar_frame_eliminar_tarea();
    void crear_frame_editar_tarea();
    void regresar_frame_editar_tarea();
    void crear_frame_edicion_tarea();
    void regresar_frame_edicion_tarea();
    void crear_frame_editar_nombre_tarea();
    void regresar_frame_editar_nombre_tarea();
    void crear_frame_editar_duracion_tarea();
    void regresar_frame_editar_duracion_tarea();
    void crear_frame_editar_recursos_tarea();
    void regresar_frame_editar_recursos_tarea();
    void crear_frame_add_recursos_tarea();
    void regresar_frame_add_recursos_tarea();
    void crear_frame_dependencias_tarea();
    void regresar_frame_dependencias_tareas();
    void crear_frame_ver_tareas();
    void regresar_frame_ver_tareas();
    void terminar_programa();

    // Métodos relacionados con la manipulación de tareas
    void agregar_tarea();
    void eliminar_tarea();

    void editar_nombre();
    void editar_duracion();
    void editar_recursos();
    void add_recursos();


    // Widgets principales
    Gtk::Frame frame_principal;
    Gtk::Fixed contenedor_principal;
    Gtk::Label etiqueta_bienvenida;
    Gtk::Button boton_crear_frame_tarea;
    Gtk::Button boton_crear_frame_editar_tarea;
    Gtk::Button boton_crear_frame_eliminar_tarea;
    Gtk::Button boton_crear_frame_dependencias_tareas;
    Gtk::Button boton_crear_frame_ver_tareas;
    Gtk::Button boton_terminar_programa;

    // Widgets relacionados con agregar tareas
    Gtk::Frame frame_tarea;
    Gtk::Fixed contenedor_frame_tarea;
    Gtk::Button boton_agregar_tarea;
    Gtk::Button boton_regresar_de_tarea;
    Gtk::Entry entrada_nombre_tarea;
    Gtk::Entry entrada_duracion_tarea;
    Gtk::Entry entrada_recursos_tarea;

    // Widgets relacionados con eliminar tareas
    Gtk::Frame frame_eliminar_tarea;
    Gtk::Fixed contenedor_frame_eliminar_tarea;
    Gtk::Button boton_eliminar_tarea;
    Gtk::Button boton_regresar_de_eliminar_tarea;
    Gtk::Entry entrada_nombre_tarea_a_eliminar;

    // Widgets relacionados con editar tareas
    Gtk::Frame frame_editar_tarea;
    Gtk::Fixed contenedor_editar_tarea;
    Gtk::Entry entrada_tarea_a_editar;
    Gtk::Button boton_editar_tarea;
    Gtk::Button boton_regresar_de_editar;

    // Widgets relacionados con edición de tareas (opciones)
    Gtk::Frame frame_edicion_tarea;
    Gtk::Fixed contenedor_edicion_tarea;
    Gtk::Button boton_editar_nombre;
    Gtk::Button boton_editar_duracion;
    Gtk::Button boton_editar_recursos;
    Gtk::Button boton_add_recursos;
    Gtk::Button boton_regresar_de_edicion_tarea;

    // Widgets relacionados con editar nombre
    Gtk::Frame frame_editar_nombre_tarea;
    Gtk::Fixed contenedor_frame_editar_nombre_tarea;
    Gtk::Entry entrada_nuevo_nombre_tarea;
    Gtk::Button boton_actualizar_nombre_tarea;
    Gtk::Button boton_regresar_de_editar_nombre_tarea;

    // Widgets relacionados con editar duración
    Gtk::Frame frame_editar_duracion_tarea;
    Gtk::Fixed contenedor_frame_editar_duracion_tarea;
    Gtk::Entry entrada_nueva_duracion_tarea;
    Gtk::Button boton_actualizar_duracion_tarea;
    Gtk::Button boton_regresar_de_editar_duracion_tarea;

    // Widgets relacionados con editar recursos
    Gtk::Frame frame_editar_recursos_tarea;
    Gtk::Fixed contenedor_frame_editar_recursos_tarea;
    Gtk::Entry entrada_nuevos_recursos_tarea;
    Gtk::Button boton_actualizar_nuevos_recursos_tarea;
    Gtk::Button boton_regresar_de_editar_recursos_tarea;

    // Widgets relacionados con añadir recursos
    Gtk::Frame frame_add_recursos_tarea;
    Gtk::Fixed contenedor_frame_add_recursos_tarea;
    Gtk::Entry entrada_add_recursos_tareas;
    Gtk::Button boton_add_recursos_tarea;
    Gtk::Button boton_regresar_de_add_recursos_tarea;

    // Widgets relacionados con dependencias
    Gtk::Frame frame_dependencias;
    Gtk::Fixed contenedor_dependencias;
    Gtk::Entry entrada_origen_dependencia;
    Gtk::Entry entrada_destino_dependencia;
    Gtk::Button boton_agregar_dependencias;
    Gtk::Button boton_eliminar_dependencias;
    Gtk::Button boton_regresar_de_dependencias;

    // Widgets relacionados con ver tareas
    Gtk::Frame frame_ver_tareas;
    Gtk::Fixed contenedor_ver_tarea;
    Gtk::Button boton_regresar_de_ver;
};


VentanaPrincipal::VentanaPrincipal() : tareas(nullptr), cantidadTareas(0) {
    set_title("Gestor de Tareas y Proyectos");
    set_default_size(1000, 800);
    set_resizable(false);
    frame_principal.set_label("Gestor de Tareas");
    frame_principal.set_margin(20);
    etiqueta_bienvenida.set_text("Bienvenido al Gestor de Tareas y Proyectos");
    etiqueta_bienvenida.set_size_request(800, 50);
    boton_crear_frame_tarea.set_label("Agregar tarea");
    boton_crear_frame_eliminar_tarea.set_label("Eliminar Tarea");
    boton_crear_frame_editar_tarea.set_label("Editar tarea");
    boton_crear_frame_dependencias_tareas.set_label("Crear dependencias");
    boton_crear_frame_ver_tareas.set_label("Ver tareas");
    boton_terminar_programa.set_label("Salir");
    boton_crear_frame_tarea.set_size_request(800, 50);
    boton_crear_frame_editar_tarea.set_size_request(800, 50);
    boton_crear_frame_eliminar_tarea.set_size_request(800,50);
    boton_crear_frame_dependencias_tareas.set_size_request(800,50);
    boton_crear_frame_ver_tareas.set_size_request(800, 50);
    boton_terminar_programa.set_size_request(800, 50);
    contenedor_principal.put(etiqueta_bienvenida, 100, 50);
    contenedor_principal.put(boton_crear_frame_tarea, 100, 125);
    contenedor_principal.put(boton_crear_frame_eliminar_tarea, 100, 225);
    contenedor_principal.put(boton_crear_frame_editar_tarea, 100, 325);
    contenedor_principal.put(boton_crear_frame_dependencias_tareas,100,425);
    contenedor_principal.put(boton_crear_frame_ver_tareas, 100, 525);
    contenedor_principal.put(boton_terminar_programa, 100, 625);
    boton_crear_frame_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_tarea));
    boton_crear_frame_eliminar_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_eliminar_tarea));
    boton_crear_frame_editar_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_editar_tarea));
    boton_crear_frame_dependencias_tareas.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_dependencias_tarea));
    boton_crear_frame_ver_tareas.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_ver_tareas));
    boton_terminar_programa.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::terminar_programa));
    frame_principal.set_child(contenedor_principal);
    set_child(frame_principal);



    frame_tarea.set_label("Agregar Tarea");
    frame_tarea.set_margin(20);
    entrada_nombre_tarea.set_placeholder_text("Ingrese el nombre de la tarea");
    entrada_nombre_tarea.set_size_request(800, 50);
    entrada_duracion_tarea.set_placeholder_text("Ingrese la duración de la tarea");
    entrada_duracion_tarea.set_size_request(800, 50);
    entrada_recursos_tarea.set_placeholder_text("Ingrese los recursos necesarios para la tarea");
    entrada_recursos_tarea.set_size_request(800, 50);
    boton_agregar_tarea.set_label("Agregar tarea");
    boton_agregar_tarea.set_size_request(800, 50);
    boton_regresar_de_tarea.set_label("Regresar");
    boton_regresar_de_tarea.set_size_request(800, 50);
    contenedor_frame_tarea.put(entrada_nombre_tarea, 100, 100);
    contenedor_frame_tarea.put(entrada_duracion_tarea, 100, 200);
    contenedor_frame_tarea.put(entrada_recursos_tarea, 100, 300);
    contenedor_frame_tarea.put(boton_agregar_tarea, 100, 400);
    contenedor_frame_tarea.put(boton_regresar_de_tarea, 100, 500);
    boton_agregar_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::agregar_tarea));
    boton_regresar_de_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_tarea));
    frame_tarea.set_child(contenedor_frame_tarea);
    frame_tarea.hide();


    frame_eliminar_tarea.set_label("Eliminar Tarea");
    frame_eliminar_tarea.set_margin(20);
    entrada_nombre_tarea_a_eliminar.set_placeholder_text("Ingrese el nombre de la tarea que desea eliminar");
    entrada_nombre_tarea_a_eliminar.set_size_request(800,50);
    boton_eliminar_tarea.set_label("Eliminar tarea");
    boton_eliminar_tarea.set_size_request(800,50);
    boton_regresar_de_eliminar_tarea.set_label("Regresar");
    boton_regresar_de_eliminar_tarea.set_size_request(800,50);
    contenedor_frame_eliminar_tarea.put(entrada_nombre_tarea_a_eliminar, 100, 100);
    contenedor_frame_eliminar_tarea.put(boton_eliminar_tarea,100,200);
    contenedor_frame_eliminar_tarea.put(boton_regresar_de_eliminar_tarea,100,300);
    boton_eliminar_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::eliminar_tarea));
    boton_regresar_de_eliminar_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_eliminar_tarea));
    frame_eliminar_tarea.set_child(contenedor_frame_eliminar_tarea);
    frame_eliminar_tarea.hide();


    frame_editar_tarea.set_label("Editar Tarea");
    frame_editar_tarea.set_margin(20);
    entrada_tarea_a_editar.set_placeholder_text("Ingrese el nombre de la tarea que desea editar");
    entrada_tarea_a_editar.set_size_request(800,50);
    boton_editar_tarea.set_label("Empezar a editar");
    boton_editar_tarea.set_size_request(800,50);
    boton_regresar_de_editar.set_label("Regresar");
    boton_regresar_de_editar.set_size_request(800, 50);
    contenedor_editar_tarea.put(entrada_tarea_a_editar, 100, 100);
    contenedor_editar_tarea.put(boton_editar_tarea, 100, 200);
    contenedor_editar_tarea.put(boton_regresar_de_editar, 100, 300);
    boton_editar_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_edicion_tarea));
    boton_regresar_de_editar.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_editar_tarea));
    frame_editar_tarea.set_child(contenedor_editar_tarea);
    frame_editar_tarea.hide();



    frame_edicion_tarea.set_label("Editar tarea");
    frame_editar_tarea.set_margin(20);
    boton_editar_nombre.set_label("Editar nombre");
    boton_editar_nombre.set_size_request(800, 50);
    boton_editar_duracion.set_label("Editar duracion");
    boton_editar_duracion.set_size_request(800, 50);
    boton_editar_recursos.set_label("Editar recursos");
    boton_editar_recursos.set_size_request(800, 50);
    boton_add_recursos.set_label("Añadir recursos");
    boton_add_recursos.set_size_request(800,50);
    boton_regresar_de_edicion_tarea.set_label("Regresar");
    boton_regresar_de_edicion_tarea.set_size_request(800,50);
    contenedor_edicion_tarea.put(boton_editar_nombre,100,100);
    contenedor_edicion_tarea.put(boton_editar_duracion,100,200);
    contenedor_edicion_tarea.put(boton_editar_recursos,100,300);
    contenedor_edicion_tarea.put(boton_add_recursos,100,400);
    contenedor_edicion_tarea.put(boton_regresar_de_edicion_tarea,100,500);
    boton_editar_nombre.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_editar_nombre_tarea));
    boton_editar_duracion.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_editar_duracion_tarea));
    boton_editar_recursos.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_editar_recursos_tarea));
    boton_add_recursos.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::crear_frame_add_recursos_tarea));
    boton_regresar_de_edicion_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_edicion_tarea));
    frame_edicion_tarea.set_child(contenedor_edicion_tarea);
    frame_edicion_tarea.hide();

    // Frame para editar el nombre de la tarea
    frame_editar_nombre_tarea.set_label("Editar Nombre de Tarea");
    frame_editar_nombre_tarea.set_margin(20);
    entrada_nuevo_nombre_tarea.set_placeholder_text("Ingrese el nuevo nombre de la tarea");
    entrada_nuevo_nombre_tarea.set_size_request(800, 50);
    boton_actualizar_nombre_tarea.set_label("Actualizar Nombre");
    boton_actualizar_nombre_tarea.set_size_request(800, 50);
    boton_regresar_de_editar_nombre_tarea.set_label("Regresar");
    boton_regresar_de_editar_nombre_tarea.set_size_request(800, 50);
    contenedor_frame_editar_nombre_tarea.put(entrada_nuevo_nombre_tarea, 100, 100);
    contenedor_frame_editar_nombre_tarea.put(boton_actualizar_nombre_tarea, 100, 200);
    contenedor_frame_editar_nombre_tarea.put(boton_regresar_de_editar_nombre_tarea, 100, 300);
    boton_actualizar_nombre_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::editar_nombre));
    boton_regresar_de_editar_nombre_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_editar_nombre_tarea));
    frame_editar_nombre_tarea.set_child(contenedor_frame_editar_nombre_tarea);
    frame_editar_nombre_tarea.hide();

    // Frame para editar la duración de la tarea
    frame_editar_duracion_tarea.set_label("Editar Duración de Tarea");
    frame_editar_duracion_tarea.set_margin(20);
    entrada_nueva_duracion_tarea.set_placeholder_text("Ingrese la nueva duración de la tarea");
    entrada_nueva_duracion_tarea.set_size_request(800, 50);
    boton_actualizar_duracion_tarea.set_label("Actualizar Duración");
    boton_actualizar_duracion_tarea.set_size_request(800, 50);
    boton_regresar_de_editar_duracion_tarea.set_label("Regresar");
    boton_regresar_de_editar_duracion_tarea.set_size_request(800, 50);
    contenedor_frame_editar_duracion_tarea.put(entrada_nueva_duracion_tarea, 100, 100);
    contenedor_frame_editar_duracion_tarea.put(boton_actualizar_duracion_tarea, 100, 200);
    contenedor_frame_editar_duracion_tarea.put(boton_regresar_de_editar_duracion_tarea, 100, 300);
    boton_actualizar_duracion_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::editar_duracion));
    boton_regresar_de_editar_duracion_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_editar_duracion_tarea));
    frame_editar_duracion_tarea.set_child(contenedor_frame_editar_duracion_tarea);
    frame_editar_duracion_tarea.hide();

    // Frame para editar los recursos de la tarea
    frame_editar_recursos_tarea.set_label("Editar Recursos de Tarea");
    frame_editar_recursos_tarea.set_margin(20);
    entrada_nuevos_recursos_tarea.set_placeholder_text("Ingrese los nuevos recursos");
    entrada_nuevos_recursos_tarea.set_size_request(800, 50);
    boton_actualizar_nuevos_recursos_tarea.set_label("Actualizar Recursos");
    boton_actualizar_nuevos_recursos_tarea.set_size_request(800, 50);
    boton_regresar_de_editar_recursos_tarea.set_label("Regresar");
    boton_regresar_de_editar_recursos_tarea.set_size_request(800, 50);
    contenedor_frame_editar_recursos_tarea.put(entrada_nuevos_recursos_tarea, 100, 100);
    contenedor_frame_editar_recursos_tarea.put(boton_actualizar_nuevos_recursos_tarea, 100, 200);
    contenedor_frame_editar_recursos_tarea.put(boton_regresar_de_editar_recursos_tarea, 100, 300);
    boton_actualizar_nuevos_recursos_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::editar_recursos));
    boton_regresar_de_editar_recursos_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_editar_recursos_tarea));
    frame_editar_recursos_tarea.set_child(contenedor_frame_editar_recursos_tarea);
    frame_editar_recursos_tarea.hide();

    // Frame para añadir recursos a la tarea
    frame_add_recursos_tarea.set_label("Añadir Recursos a Tarea");
    frame_add_recursos_tarea.set_margin(20);
    entrada_add_recursos_tareas.set_placeholder_text("Ingrese los recursos adicionales");
    entrada_add_recursos_tareas.set_size_request(800, 50);
    boton_add_recursos_tarea.set_label("Añadir Recursos");
    boton_add_recursos_tarea.set_size_request(800, 50);
    boton_regresar_de_add_recursos_tarea.set_label("Regresar");
    boton_regresar_de_add_recursos_tarea.set_size_request(800, 50);
    contenedor_frame_add_recursos_tarea.put(entrada_add_recursos_tareas, 100, 100);
    contenedor_frame_add_recursos_tarea.put(boton_add_recursos_tarea, 100, 200);
    contenedor_frame_add_recursos_tarea.put(boton_regresar_de_add_recursos_tarea, 100, 300);
    boton_add_recursos_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::add_recursos));
    boton_regresar_de_add_recursos_tarea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_add_recursos_tarea));
    frame_add_recursos_tarea.set_child(contenedor_frame_add_recursos_tarea);
    frame_add_recursos_tarea.hide();

    //Frame dependencias
    frame_dependencias.set_label("Agregar dependencias");
    frame_dependencias.set_margin(20);
    entrada_origen_dependencia.set_placeholder_text("Ingrese la tarea de origen");
    entrada_origen_dependencia.set_size_request(800,50);
    entrada_destino_dependencia.set_placeholder_text("Ingrese la tarea de destino");
    entrada_destino_dependencia.set_size_request(800,50);
    boton_agregar_dependencias.set_label("Crear dependencias");
    boton_agregar_dependencias.set_size_request(800,50);
    boton_eliminar_dependencias.set_label("Eliminar dependencias");
    boton_eliminar_dependencias.set_size_request(800,50);
    boton_regresar_de_dependencias.set_label("Regresar");
    boton_regresar_de_dependencias.set_size_request(800,50);
    contenedor_dependencias.put(entrada_origen_dependencia,100,100);
    contenedor_dependencias.put(entrada_destino_dependencia,100,200);
    contenedor_dependencias.put(boton_agregar_dependencias,100,300);
    contenedor_dependencias.put(boton_eliminar_dependencias,100,400);
    contenedor_dependencias.put(boton_regresar_de_dependencias,100,500);
    boton_regresar_de_dependencias.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_dependencias_tareas));
    frame_dependencias.set_child(contenedor_dependencias);
    frame_dependencias.hide();

    frame_ver_tareas.set_label("Ver Tareas");
    frame_ver_tareas.set_margin(20);
    boton_regresar_de_ver.set_label("Regresar");
    boton_regresar_de_ver.set_size_request(800, 50);
    contenedor_ver_tarea.put(boton_regresar_de_ver, 100, 200);
    boton_regresar_de_ver.signal_clicked().connect(sigc::mem_fun(*this, &VentanaPrincipal::regresar_frame_ver_tareas));
    frame_ver_tareas.set_child(contenedor_ver_tarea);
    frame_ver_tareas.hide();
}

VentanaPrincipal::~VentanaPrincipal() {
    for (int i = 0; i < cantidadTareas; i++) {
        delete tareas[i];
    }
    delete[] tareas;
}



//------------------------------------FRAMES-----------------------------------------------------------------//





void VentanaPrincipal::crear_frame_tarea() {
    std::cout << "Entrando a crear_frame_tarea" << std::endl;
    grafo.mostrarGrafo(); // Llamada a mostrarGrafo
    std::cout << "Terminó mostrarGrafo" << std::endl;
    frame_principal.hide();
    set_child(frame_tarea);
    frame_tarea.show();
}


void VentanaPrincipal::regresar_frame_tarea() {
    frame_tarea.hide();
    set_child(frame_principal);
    frame_principal.show();
}

void VentanaPrincipal::crear_frame_eliminar_tarea() {
    frame_principal.hide();
    set_child(frame_eliminar_tarea);
    frame_eliminar_tarea.show();
}

void VentanaPrincipal::regresar_frame_eliminar_tarea() {
    frame_eliminar_tarea.hide();
    set_child(frame_principal);
    frame_principal.show();
}

void VentanaPrincipal::crear_frame_editar_tarea() {
    frame_principal.hide();
    set_child(frame_editar_tarea);
    frame_editar_tarea.show();
}

void VentanaPrincipal::regresar_frame_editar_tarea() {
    frame_editar_tarea.hide();
    set_child(frame_principal);
    frame_principal.show();
}

void VentanaPrincipal::crear_frame_edicion_tarea() {
    Glib::ustring nombre_tarea_a_editar = entrada_tarea_a_editar.get_text();
    if (nombre_tarea_a_editar.empty()) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: Nombre de tarea vacío");
        dialog->set_secondary_text("Por favor, ingrese el nombre de la tarea que desea editar.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    if (!existeTarea(nombre_tarea_a_editar)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: Tarea no encontrada");
        dialog->set_secondary_text("No se encontró ninguna tarea con el nombre ingresado.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    frame_editar_tarea.hide();
    set_child(frame_edicion_tarea);
    frame_edicion_tarea.show();
}

void VentanaPrincipal::regresar_frame_edicion_tarea() {
    frame_edicion_tarea.hide();
    set_child(frame_editar_tarea);
    frame_editar_tarea.show();
}

void VentanaPrincipal::crear_frame_editar_nombre_tarea() {
    frame_edicion_tarea.hide();
    set_child(frame_editar_nombre_tarea);
    frame_editar_nombre_tarea.show();
}

void VentanaPrincipal::regresar_frame_editar_nombre_tarea() {
    frame_editar_nombre_tarea.hide();
    set_child(frame_edicion_tarea);
    frame_edicion_tarea.show();
}

void VentanaPrincipal::crear_frame_editar_duracion_tarea() {
    frame_edicion_tarea.hide();
    set_child(frame_editar_duracion_tarea);
    frame_editar_duracion_tarea.show();
}

void VentanaPrincipal::regresar_frame_editar_duracion_tarea() {
    frame_editar_duracion_tarea.hide();
    set_child(frame_edicion_tarea);
    frame_edicion_tarea.show();
}

void VentanaPrincipal::crear_frame_editar_recursos_tarea() {
    frame_edicion_tarea.hide();
    set_child(frame_editar_recursos_tarea);
    frame_editar_recursos_tarea.show();
}

void VentanaPrincipal::regresar_frame_editar_recursos_tarea() {
    frame_editar_recursos_tarea.hide();
    set_child(frame_edicion_tarea);
    frame_edicion_tarea.show();
}

void VentanaPrincipal::crear_frame_add_recursos_tarea() {
    frame_edicion_tarea.hide();
    set_child(frame_add_recursos_tarea);
    frame_add_recursos_tarea.show();
}

void VentanaPrincipal::regresar_frame_add_recursos_tarea() {
    frame_add_recursos_tarea.hide();
    set_child(frame_edicion_tarea);
    frame_edicion_tarea.show();
}

void VentanaPrincipal::crear_frame_dependencias_tarea() {
    frame_principal.hide();
    set_child(frame_dependencias);
    frame_dependencias.show();
}

void VentanaPrincipal::regresar_frame_dependencias_tareas() {
    frame_dependencias.hide();
    set_child(frame_principal);
    frame_principal.show();
}

void VentanaPrincipal::crear_frame_ver_tareas() {
    frame_principal.hide();
    set_child(frame_ver_tareas);
    frame_ver_tareas.show();
}

void VentanaPrincipal::regresar_frame_ver_tareas() {
    frame_ver_tareas.hide();
    set_child(frame_principal);
    frame_principal.show();
}

void VentanaPrincipal::terminar_programa() {
    close();
}


//-----------------------------------------------------FRAMES----------------------------------------------//

//---------------------------------------------VALIDACIONES------------------------------------------------//
bool VentanaPrincipal::validar_nombre(const Glib::ustring& nombre_tarea, std::string& mensaje_error) {
    if (std::regex_search(nombre_tarea.raw(), std::regex("[0-9]"))) {
        mensaje_error = "El campo nuevo nombre no debe contener números.";
        return false;
    }
    return true;
}

bool VentanaPrincipal::validar_duracion(const Glib::ustring& duracion_tarea, std::string& mensaje_error) {
    if (std::regex_search(duracion_tarea.raw(), std::regex("[^0-9]"))) {
        mensaje_error = "La duración no debe contener letras.";
        return false;
    }
    try {
        int duracion = std::stoi(duracion_tarea);
        if (duracion <= 0) {
            mensaje_error = "La duración debe ser un número positivo.";
            return false;
        }
    } catch (const std::invalid_argument& e) {
        mensaje_error = "Formato de duración inválido.";
        return false;
    } catch (const std::out_of_range& e) {
        mensaje_error = "Duración fuera de rango.";
        return false;
    }
    return true;
}

bool VentanaPrincipal::validar_datos_tarea(const Glib::ustring& nombre_tarea, 
                                           const Glib::ustring& duracion_tarea, 
                                           const Glib::ustring& recursos_tarea, 
                                           std::string& mensaje_error) {
    if (nombre_tarea.empty() || recursos_tarea.empty()) {
        mensaje_error = "Por favor, complete todos los campos obligatorios.";
        return false;
    }
    if (std::regex_search(nombre_tarea.raw(), std::regex("[0-9]")) || 
        std::regex_search(recursos_tarea.raw(), std::regex("[0-9]"))) {
        mensaje_error = "Los campos 'Nombre' y 'Recursos' no deben contener números.";
        return false;
    }
    return validar_duracion(duracion_tarea, mensaje_error);
}

bool VentanaPrincipal::validar_recursos(const Glib::ustring& recursos_tarea, std::string& mensaje_error) {
    if (recursos_tarea.empty()) {
        mensaje_error = "Por favor, complete el campo con los nuevos recursos";
        return false;
    }
    if (std::regex_search(recursos_tarea.raw(), std::regex("[0-9]"))) {
        mensaje_error = "Los recursos no deben contener números";
        return false;
    }

    return true;
}

//---------------------------------------------VALIDACIONES------------------------------------------------//



//----------------------------------------------Funciones escenciales--------------------------------------//

void VentanaPrincipal::agregar_tarea() {
    Glib::ustring nombre_tarea = entrada_nombre_tarea.get_text();
    Glib::ustring duracion_tarea = entrada_duracion_tarea.get_text();
    Glib::ustring recursos_tarea = entrada_recursos_tarea.get_text();

    std::string mensaje_error;
    if (!validar_datos_tarea(nombre_tarea, duracion_tarea, recursos_tarea, mensaje_error)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error al agregar tarea");
        dialog->set_secondary_text(mensaje_error);
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    try {
        String nombre = convertir_a_String(nombre_tarea);
        int duracion = std::stoi(duracion_tarea.raw());
        Tarea* nuevaTarea = new Tarea(nombre, duracion);

        String recursos = convertir_a_String(recursos_tarea);
        String** lista_recursos = recursos.split(',');
        int i = 0;
        while (lista_recursos[i] != nullptr) {
            nuevaTarea->agregarRecurso(lista_recursos[i]);
            i++;
        }
        delete[] lista_recursos;

        grafo.agregarTarea(nuevaTarea);
        grafo.mostrarGrafo(); // Llamada a mostrarGrafo
        Tarea** nuevasTareas = new Tarea*[cantidadTareas + 1];
        for (int i = 0; i < cantidadTareas; i++) {
            nuevasTareas[i] = tareas[i];
        }
        nuevasTareas[cantidadTareas] = nuevaTarea;
        delete[] tareas;
        tareas = nuevasTareas;
        cantidadTareas++;

        std::cout << "Tarea agregada con éxito:" << std::endl;
        std::cout << "Nombre de la tarea: " << nombre.mostrarCadena() << std::endl;
        std::cout << "Duración: " << duracion << " horas" << std::endl;
        std::cout << "Recursos: ";
        for (int j = 0; j < nuevaTarea->getCantidadRecursos(); j++) {
            std::cout << nuevaTarea->getRecursos()[j]->mostrarCadena();
            if (j < nuevaTarea->getCantidadRecursos() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        auto dialog = new Gtk::MessageDialog(*this, "¡Tarea agregada con éxito!");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();

        entrada_nombre_tarea.set_text("");
        entrada_duracion_tarea.set_text("");
        entrada_recursos_tarea.set_text("");
    } catch (const std::exception& e) {
        auto dialog = new Gtk::MessageDialog(*this, mensaje_error);
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
    }
}



void VentanaPrincipal::editar_nombre() {
    Glib::ustring nuevo_nombre_tarea = entrada_nuevo_nombre_tarea.get_text();
    Glib::ustring nombre_tarea_original = entrada_tarea_a_editar.get_text();
    std::string mensaje_error;
    if (nuevo_nombre_tarea.empty()) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: El nuevo nombre está vacío");
        dialog->set_secondary_text("Por favor, asegúrese de ingresar el nuevo nombre");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }

    if (existeTarea(nuevo_nombre_tarea)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: Nombre ya existente");
        dialog->set_secondary_text("Ya existe una tarea con el nuevo nombre proporcionado. Intente con otro nombre.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }

    if (!validar_nombre(nuevo_nombre_tarea, mensaje_error)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error al cambiar el nombre de la tarea");
        dialog->set_secondary_text(mensaje_error);
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }

    try {
        String nombre_original = convertir_a_String(nombre_tarea_original);
        String nuevo_nombre = convertir_a_String(nuevo_nombre_tarea);
        for (int i = 0; i < cantidadTareas; ++i) {
            if (tareas[i]->getNombre() == nombre_original) {
                tareas[i]->setNombre(nuevo_nombre);
                grafo.obtenerNodo(i)->getTarea()->setNombre(nuevo_nombre);
                mostrarDatosTarea(tareas[i]);
                auto dialog = new Gtk::MessageDialog(*this, "¡Nombre actualizado con éxito!");
                dialog->set_secondary_text("El nombre de la tarea ha sido actualizado correctamente.");
                dialog->set_modal(true);
                dialog->signal_response().connect([dialog](int response_id) {
                    dialog->hide();
                    delete dialog;
                });
                dialog->show();
                entrada_tarea_a_editar.set_text(nuevo_nombre_tarea);
                entrada_nuevo_nombre_tarea.set_text("");
                return;
            }
        }
    } catch (const std::exception& e) {
        auto dialog = new Gtk::MessageDialog(*this, "Error al actualizar el nombre");
        dialog->set_secondary_text(e.what());
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
    }
}


void VentanaPrincipal::editar_duracion() {
    Glib::ustring nueva_duracion = entrada_nueva_duracion_tarea.get_text();
    Glib::ustring nombre_tarea = entrada_tarea_a_editar.get_text();
    if (nueva_duracion.empty()) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: La nueva duración está vacía");
        dialog->set_secondary_text("Por favor, asegúrese de ingresar la nueva duración.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    std::string mensaje_error;
    if (!validar_duracion(nueva_duracion, mensaje_error)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error al cambiar la duración de la tarea");
        dialog->set_secondary_text(mensaje_error);
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    int nueva_duracion_int;
    try {
        nueva_duracion_int = std::stoi(nueva_duracion.raw());
    } catch (const std::exception& e) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: Duración inválida");
        dialog->set_secondary_text("Por favor, asegúrese de ingresar una duración válida.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }

    String nombre_tarea_a_editar = convertir_a_String(nombre_tarea);
    for (int i = 0; i < cantidadTareas; ++i) {
        if (tareas[i]->getNombre() == nombre_tarea_a_editar) {
            tareas[i]->setDuracion(nueva_duracion_int);
            grafo.obtenerNodo(i)->getTarea()->setDuracion(nueva_duracion_int);
            mostrarDatosTarea(tareas[i]);
            auto dialog = new Gtk::MessageDialog(*this, "¡Duración actualizada con éxito!");
            dialog->set_secondary_text("La duración de la tarea ha sido actualizada correctamente.");
            dialog->set_modal(true);
            dialog->signal_response().connect([dialog](int response_id) {
                dialog->hide();
                delete dialog;
            });
            dialog->show();

            entrada_nueva_duracion_tarea.set_text("");
            return;
        }
    }
}


void VentanaPrincipal::editar_recursos() {
    Glib::ustring nuevos_recursos = entrada_nuevos_recursos_tarea.get_text();
    Glib::ustring nombre_tarea = entrada_tarea_a_editar.get_text();
    std::string mensaje_error;
    if (!validar_recursos(nuevos_recursos, mensaje_error)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error al cambiar los recursos de la tarea");
        dialog->set_secondary_text(mensaje_error);
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    String nombre_tarea_a_editar = convertir_a_String(nombre_tarea);
    String recursos = convertir_a_String(nuevos_recursos);
    String** lista_nuevos_recursos = recursos.split(',');
    for (int i = 0; i < cantidadTareas; i++) {
        if (tareas[i]->getNombre() == nombre_tarea_a_editar) {
            tareas[i]->setRecursos(lista_nuevos_recursos);
            grafo.obtenerNodo(i)->getTarea()->setRecursos(lista_nuevos_recursos);
            mostrarDatosTarea(tareas[i]);
            auto dialog = new Gtk::MessageDialog(*this, "¡Recursos actualizados con éxito!");
            dialog->set_secondary_text("Los recursos de la tarea han sido actualizados correctamente.");
            dialog->set_modal(true);
            dialog->signal_response().connect([dialog](int response_id) {
                dialog->hide();
                delete dialog;
            });
            dialog->show();
            entrada_nuevos_recursos_tarea.set_text("");
            break;
        }
    }
    int indice = 0;
    while (lista_nuevos_recursos[indice] != nullptr) {
        delete lista_nuevos_recursos[indice];
        indice++;
    }
    delete[] lista_nuevos_recursos;
}


void VentanaPrincipal::add_recursos() {
    Glib::ustring nuevo_recurso = entrada_add_recursos_tareas.get_text();
    Glib::ustring nombre_tarea = entrada_tarea_a_editar.get_text();
    std::string mensaje_error;

    if (!validar_recursos(nuevo_recurso, mensaje_error)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error al añadir el recurso a la tarea");
        dialog->set_secondary_text(mensaje_error);
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }

    String nombre_tarea_a_editar = convertir_a_String(nombre_tarea);
    String recursos = convertir_a_String(nuevo_recurso);
    String** lista_add_recursos = recursos.split(',');

    for (int i = 0; i < cantidadTareas; i++) {
        if (tareas[i]->getNombre() == nombre_tarea_a_editar) {
            int cantidadActual = tareas[i]->getCantidadRecursos();
            int cantidadNuevos = 0;
            while (lista_add_recursos[cantidadNuevos] != nullptr) {
                cantidadNuevos++;
            }
            String** nuevaLista = new String*[cantidadActual + cantidadNuevos + 1];
            for (int j = 0; j < cantidadActual; j++) {
                nuevaLista[j] = new String(*tareas[i]->getRecursos()[j]);
            }

            for (int j = 0; j < cantidadNuevos; j++) {
                nuevaLista[cantidadActual + j] = new String(*lista_add_recursos[j]);
            }
            nuevaLista[cantidadActual + cantidadNuevos] = nullptr;

            // Actualizar los recursos en la tarea
            tareas[i]->setRecursos(nuevaLista);

            // Actualizar los recursos en el grafo
            grafo.obtenerNodo(i)->getTarea()->setRecursos(nuevaLista);

            for (int j = 0; j < cantidadActual + cantidadNuevos; j++) {
                delete nuevaLista[j];
            }
            delete[] nuevaLista;

            mostrarDatosTarea(tareas[i]);

            auto dialog = new Gtk::MessageDialog(*this, "¡Recurso agregado con éxito!");
            dialog->set_secondary_text("El nuevo recurso de la tarea ha sido agregado con éxito.");
            dialog->set_modal(true);
            dialog->signal_response().connect([dialog](int response_id) {
                dialog->hide();
                delete dialog;
            });
            dialog->show();

            entrada_add_recursos_tareas.set_text("");
            break;
        }
    }

    // Liberar memoria de la lista temporal de nuevos recursos
    int indice = 0;
    while (lista_add_recursos[indice] != nullptr) {
        delete lista_add_recursos[indice];
        indice++;
    }
    delete[] lista_add_recursos;
}


void VentanaPrincipal::eliminar_tarea() {
    Glib::ustring nombre_tarea = entrada_nombre_tarea_a_eliminar.get_text();

    if (nombre_tarea.empty()) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: Nombre de tarea vacío");
        dialog->set_secondary_text("Por favor, ingrese el nombre de la tarea que desea eliminar.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }

    if (!existeTarea(nombre_tarea)) {
        auto dialog = new Gtk::MessageDialog(*this, "Error: Tarea no encontrada");
        dialog->set_secondary_text("No se encontró ninguna tarea con el nombre ingresado.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        return;
    }
    String nombre_a_eliminar = convertir_a_String(nombre_tarea);
    int indice = -1;
    for (int i = 0; i < cantidadTareas; ++i) {
        if (tareas[i]->getNombre() == nombre_a_eliminar) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        delete tareas[indice];
        grafo.eliminarNodo(indice); 
        for (int i = indice; i < cantidadTareas - 1; ++i) {
            tareas[i] = tareas[i + 1];
        }
        cantidadTareas--;
        Tarea** nuevasTareas = new Tarea*[cantidadTareas];
        for (int i = 0; i < cantidadTareas; ++i) {
            nuevasTareas[i] = tareas[i];
        }
        delete[] tareas;
        tareas = nuevasTareas;
        auto dialog = new Gtk::MessageDialog(*this, "¡Tarea eliminada con éxito!");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
        entrada_nombre_tarea_a_eliminar.set_text("");
    } else {
        auto dialog = new Gtk::MessageDialog(*this, "Error: No se pudo eliminar la tarea");
        dialog->set_secondary_text("Hubo un problema al intentar eliminar la tarea. Inténtelo nuevamente.");
        dialog->set_modal(true);
        dialog->signal_response().connect([dialog](int response_id) {
            dialog->hide();
            delete dialog;
        });
        dialog->show();
    }
}

//----------------------------------------------Funciones escenciales--------------------------------------//



//------------------------------------------------------------------Auxiliar----------------------------//
    void VentanaPrincipal::mostrarDatosTarea(Tarea* tarea) {
        std::cout << "Información de la tarea:" << std::endl;
        std::cout << "Nombre: " << tarea->getNombre().mostrarCadena() << std::endl;
        std::cout << "Duración: " << tarea->getDuracion() << " horas" << std::endl;
        std::cout << "Recursos: ";
        for (int j = 0; j < tarea->getCantidadRecursos(); j++) {
            std::cout << tarea->getRecursos()[j]->mostrarCadena();
            if (j < tarea->getCantidadRecursos() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

//------------------------------------------------------------------Auxiliar----------------------------//


//Para compilar g++ -o gestion_tareas main.cpp `pkg-config gtkmm-4.0 --cflags --libs`
// ./gestion_tareas

#endif // VENTANA_PRINCIPAL_H
