#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "axt3178_Battery.h"
#include "axt3178_Wheel_Tire_Combo.h"
#include "axt3178_Windshield_Wiper.h"
#include "axt3178_Frame.h"
#include "axt3178_Engine.h"
#include "axt3178_Inventory.h"
#include "axt3178_dialog.h"

class Main_window : public Gtk::Window {
    public:
        Main_window();
        virtual ~Main_window();
    protected:
        void on_save_click();      
        void on_load_click();
        void on_quit_click();   
        void on_add_click(); 
        void on_remove_click(); 
        void on_view_click(); 
        void on_make_order_click();
        void on_make_orders_click();
    private:
        Inventory inventory;
};
#endif