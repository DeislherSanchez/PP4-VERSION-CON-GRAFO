#include <gtkmm.h>
#include "/home/jahir/Downloads/PP4/SRC/views/gestorTareas.h"

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("org.gtkmm.gestortareas");

    return app->make_window_and_run<VentanaPrincipal>(argc, argv);
}
