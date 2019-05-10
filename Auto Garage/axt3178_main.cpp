#include "axt3178_main_window.h"

int main(int argc, char* argv[]){
/*Gtk::Main kit(argc, argv);
Inventory inv;
View view{inv};
Controller controller{inv,view};
controller.gui();*/
 auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim");
  // Instance a Window
  Main_window win;

  // Set the window title
  win.set_title("Win");

  //Show the window and returns when it is closed or hidden
  return app->run(win);
}
