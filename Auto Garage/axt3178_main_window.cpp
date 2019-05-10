#include "axt3178_main_window.h"

Main_window::Main_window() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox); //Window.add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

//     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
     
     //         save  file
  // Append New to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save to file", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
    filemenu->append(*menuitem_save);

     //         load  file
  // Append New to the File menu
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load From file", true));
    menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_load_click));
    filemenu->append(*menuitem_load);

//     ORDER
    // Create an Order
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*ordermenu);
// Make order
    Gtk::MenuItem *menuitem_make_order = Gtk::manage(new Gtk::MenuItem("_Make Order", true));
    menuitem_make_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_make_order_click));
    ordermenu->append(*menuitem_make_order);
// Make orders
    Gtk::MenuItem *menuitem_make_orders = Gtk::manage(new Gtk::MenuItem("_Make multiple Orders", true));
    menuitem_make_orders->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_make_orders_click));
    ordermenu->append(*menuitem_make_orders);
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     Parts
    // Create a parts menu
    Gtk::MenuItem *menuitem_parts = Gtk::manage(new Gtk::MenuItem("_Parts", true));
    menubar->append(*menuitem_parts);
    Gtk::Menu *partmenu = Gtk::manage(new Gtk::Menu());
    menuitem_parts->set_submenu(*partmenu);

    //ADD
    Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add Parts", true));
    menuitem_add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_click));
    partmenu->append(*menuitem_add);

      //Remove
    Gtk::MenuItem *menuitem_remove = Gtk::manage(new Gtk::MenuItem("_Remove Parts", true));
    menuitem_remove->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_remove_click));
    partmenu->append(*menuitem_remove);

    //View
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View Parts", true));
    menuitem_view->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_view_click));
    partmenu->append(*menuitem_view);

    vbox->show_all();
}

Main_window::~Main_window()
{
}


void Main_window::on_save_click() {
    //controller->save_file();
    std::string fname = "axt3178_save_file.txt";
	std::ofstream myfile(fname, std::ios_base::app);
	if(myfile.is_open()){
		myfile<<(inventory);
		std::string x = "Saved to file: " + fname;
		Dialog::message(x,"Success!");
	}
	else{
	 std::ostringstream oss;
	    std::string y;
	    oss<<"Could not open file";
	    y = oss.str();
	    Dialog::message(y,"Error!");
	}	
}

void Main_window::on_load_click() {
    //controller->load_file();
    std::string fname = "axt3178_save_file.txt";
	std::ifstream myfile(fname);
	if(myfile.is_open()){
		std::string t,n;
		int pn,q;
		double p;
	while(myfile>>t){
		myfile>>n>>pn>>p;
		if(t=="Battery"){
			int ca,cca,v,rm;
			myfile>>ca>>cca>>v>>rm>>q;
			Auto_Part* B = new Battery(t,n,pn,p,ca,cca,v,rm);
			inventory.add_parts(B,q);	
		}
		else if(t=="Tire"){
			std::string tt,sr,lr;
			int w,r,d;
			myfile>>tt>>w>>r>>d>>sr>>lr>>q;
			Auto_Part* T = new Tire (t,n,pn,p,tt,w,r,d,sr,lr);
			inventory.add_parts(T,q);	
		}
		else if(t=="Wheel"){
			std::string c,co,bp;
			int d,w;
			myfile>>c>>co>>d>>w>>bp>>q;
			Auto_Part* W = new Wheel (t,n,pn,p,c,co,d,w,bp); 
			inventory.add_parts(W,q);
		}
		else if(t=="Combo"){	
			std::string tt,sr,lr;
			int wt,r,dt;
			std::cin>>tt>>wt>>r>>dt>>sr>>lr;
			std::string c,co,bp;
			int dw,ww;
			myfile>>c>>co>>dw>>ww>>bp>>q;		
			Auto_Part* C = new Wheel_Tire_Combo (t,n,pn,p,c,co,dw,ww,bp,tt,wt,r,dt,sr,lr);
			inventory.add_parts(C,q);
		}
		else if(t=="Wiper"){
			std::string ft;
			int l;
			myfile>>l>>ft>>q;
			Auto_Part* WW = new Windshield_Wiper (t,n,pn,p,l,ft); 
			inventory.add_parts(WW,q);	
		}
		else if(t=="Engine"){	
			std::string ft;
			int nc;
			//view.prompt_for_engine();
			myfile>>nc>>ft>>q;
			Auto_Part* E = new Engine (t,n,pn,p,nc,ft); 
			inventory.add_parts(E,q);
		}
		else if(t=="Frame"){
			std::string ft;
			//view.prompt_for_frame();
			myfile>>ft>>q;
			Auto_Part* F = new Frame (t,n,pn,p,ft); 
			inventory.add_parts(F,q);
		}
 	}
	}
	else{
		//view.file_error();
        std::ostringstream oss;
	    std::string y;
	    oss<<"Could not open file";
	    y = oss.str();
	    Dialog::message(y,"Error!");	
	}
}

void Main_window::on_quit_click() {
    hide();
}

void Main_window::on_make_order_click(){
	int check = 0;
	std::string header = "Parts We have:(Type,Name,Part Number,Price,Specifications,Quantity)\n";
	if(inventory.size() == 0){
		header += "No objects to display\n";
		check = 1;
	}
	else{
		std::ostringstream oss;	
		std::string y;
		oss<<(inventory);
		y = oss.str();
		header += y;
	}
	if(check == 0){
		std::string spn  = Dialog::input(header,"Enter part number","","");
		std::istringstream iss(spn);
		int pn;
		iss>>pn;
		std::string sn = Dialog::input(header,"Enter number of parts","","");
		std::istringstream iss2(sn);
		int n;
		iss2>>n;
		std::string cn  = Dialog::input(header,"Enter your name","","");
		std::string ad  = Dialog::input(header,"Enter your address","","");
		std::string bi = Dialog::input(header,"Enter your billing info","","");
		Order x (cn,ad,bi,1,"recieved");
		//std::cout<< "No error till";
		std::string status = inventory.make_order(x,pn,n);
		Dialog::message(status,"Order");
	}
	else{
		Dialog::message("We currently don't have anything in our inventory","Sorry!");
	}
	
}

void Main_window::on_make_orders_click(){
	//std::string result = inventory.make_orders();
	std::string fname = "orders.txt";
	std::vector<Order> order_vector;
	std::ifstream myfile(fname);
	if(myfile.is_open()){
		std::string cn,ad,bi,status;
		int pn,n,on;
		int count = 0;
		//std::vector<std::thread> t;
		while(myfile>>cn){
			myfile>>ad>>bi>>on>>status>>pn>>n;
			Order x (cn,ad,bi,on,status);
			std::string status = inventory.make_order(x,pn,n);
			Dialog::message(status,"Order");
			//t[count] = std::thread(Inventory::make_order,x,pn,n);
			//count++;
		}
		/*for (int i = 0; i < count; i++){
			t[i].join();
		}*/
	}
	else{
		std::ostringstream oss;
	    std::string y;
	    oss<<"Could not open file";
	    y = oss.str();
	    //return y;
		Dialog::message(y,"Order");
	}
	
}

void Main_window::on_add_click() {
    //controller->add_parts();
    std::string parts = R"(
===============================
Menu for part types(Choose one)
===============================

1)Tires
2)Wheels
3)Wheel Tire Combo
4)Windshield Wiper
5)Frame
6)Engine
7)Battery

)";

std::string result = Dialog::input(parts, "Main Menu", "", "0");
	std::istringstream iss(result);
	int ch;
	iss >> ch;	
	switch(ch){
	case 1:
		{
			//view.prompt_for_tire();
	std::string n,t;
	t = "Tire";
	int pn,q;
	double p;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,type,width,ratio,diameter,speed_rating,load_range: ","Tire's Specifications:","","");
	std::istringstream iss(result);
	std::string tt,sr,lr;	
	int w,r,d;
	iss>>n>>pn>>p>>tt>>w>>r>>d>>sr>>lr;
	Auto_Part* AP = new Tire(t,n,pn,p,tt,w,r,d,sr,lr); 
	//q = prompt_for_quantity();
	 result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	iss2 >> q;
	inventory.add_parts(AP,q);
		}
		break;
	case 2:
		{	
			//view.prompt_for_wheel();
		/*Wheel W = view.prompt_for_wheel();
		q = view.prompt_for_quantity();
		Auto_Part* AP = &W;
		inventory.add_parts(AP,q);*/
        std::string n,t;
	int pn,q;
	double p;
	t = "Wheel";
	std::string c,co,bp;
	int d,w;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,category,color,diameter,width,bolt pattern: ","Wheel's Specification","","");
	std::istringstream iss(result);
	iss>>n>>pn>>p>>c>>co>>d>>w>>bp;
	Auto_Part* AP = new Wheel (t,n,pn,p,c,co,d,w,bp);
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	iss2 >> q;
	inventory.add_parts(AP,q);
		}
		break;
	case 3:
		{
			//view.prompt_for_combo();
            std::string n,t;
	int pn,q;
	double p;
	t = "Combo";
	std::string tt,sr,lr;	
	int tw,r,td;
	std::string c,co,bp;
	int wd,ww;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,Tire type,Tire width,Tire ratio,Tire diameter,Tire speed_rating,Tire load_range,Wheel category,Wheel color,Wheel diameter,Wheel width,Wheel bolt pattern:: ","Combo's Specifications:","","");
	std::istringstream iss(result);
	iss>>n>>pn>>p>>tt>>tw>>r>>td>>sr>>lr>>c>>co>>wd>>ww>>bp;
	Auto_Part* AP = new  Wheel_Tire_Combo(t,n,pn,p,c,co,wd,ww,bp,tt,tw,r,td,sr,lr);
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	//int q;
	iss2 >> q;
	inventory.add_parts(AP,q);
		}
		break;
	case 4:
		{
			//view.prompt_for_wiper();
		/*Windshield_Wiper WW = view.prompt_for_wiper();
		q = view.prompt_for_quantity();
		Auto_Part* AP = &WW;
		inventory.add_parts(AP,q);*/
        std::string n,t;
	int pn,q;
	double p;
	t = "Wiper";
	std::string ft;
	int l;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,length, frame type: ","Wiper's Specifications","","");
	std::istringstream iss(result);
	iss>>n>>pn>>p>>l>>ft;
	Auto_Part* AP = new Windshield_Wiper (t,n,pn,p,l,ft);
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	//int q;
	iss2 >> q;
	inventory.add_parts(AP,q);
		}
		break;
	case 5:
		{
			//view.prompt_for_frame();
		/*Frame F = view.prompt_for_frame();
		q = view.prompt_for_quantity();
		Auto_Part* AP = &F;
		inventory.add_parts(AP,q);*/
        std::string n,t;
	int pn,q;
	double p;
	t = "Frame";
	std::string ft;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,frame type: ","Frame's Specifications","","");
	std::istringstream iss(result);
	iss>>n>>pn>>p>>ft;
	Auto_Part* AP = new Frame(t,n,pn,p,ft);
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	//int q;
	iss2 >> q;
	inventory.add_parts(AP,q);	
		}
		break;
	case 6:
		{
			//view.prompt_for_engine();
		/*t = "Engine";
		Engine E = view.prompt_for_engine();
		q = view.prompt_for_quantity();
		Auto_Part* AP = &E;
		inventory.add_parts(AP,q);*/
        std::string n,t;
	int pn,q;
	double p;
	t = "Engine";
	std::string ft;
	int nc;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,number of cylinders, fuel type: ","Engine Specifications","","");
	std::istringstream iss(result);
	iss>>n>>pn>>p>>nc>>ft;
	Auto_Part* AP = new Engine(t,n,pn,p,nc,ft);	
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	//int q;
	iss2 >> q;
	inventory.add_parts(AP,q);
		}
		break;
  	case 7:
		{
			//view.prompt_for_battery();
		/*t = "Battery";
		Battery B = view.prompt_for_battery();
		q = view.prompt_for_quantity();
		Auto_Part* AP = &B;
		inventory.add_parts(AP,q);*/
        std::string n,t;
	int pn,q;
	double p;
	t = "Battery";
	int ca,cca,v,rcm;
	std::string result = Dialog::input("Enter in correct order: name,part number,price,cranking amps, cold cranking amps, voltage, reserve capacity minutes: ","Battery Specifications","","");
	std::istringstream iss(result);
	iss>>n>>pn>>p>>ca>>cca>>v>>rcm;
	Auto_Part* AP = new Battery(t,n,pn,p,ca,cca,v,rcm);
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	//int q;
	iss2 >> q;
	inventory.add_parts(AP,q);
		}
		break;
	default:
		std::ostringstream oss;
	std::string y;
	oss<<"Input error-> Please choose a valid option from menu"<<std::endl;
	y = oss.str();
	Dialog::message(y,"Error!");
	}
}

void Main_window::on_remove_click() {
    std::string header;
	if(inventory.size() == 0)
		header += "No objects to display\n";
	else{
		std::ostringstream oss;	
		std::string y;
		oss<<(inventory);
		y = oss.str();
		header += y;
	}		
	Dialog::message(header, "All Objects (Type,name,part number,price,part specifications");
    if(inventory.size() != 0){
	std::string result = Dialog::input("Enter part number: ","Part Number?", "", "0");
	std::istringstream iss(result);
	int pn;
	iss >> pn;
	result = Dialog::input("Enter quantity of parts to be added/removed: ","How many?", "", "0");
	std::istringstream iss2(result);
	int q;
	iss2 >> q;
	inventory.remove_parts(pn,q);
    }
}

void Main_window::on_view_click() {
    std::string header;
	if(inventory.size() == 0)
		header += "No objects to display\n";
	else{
		std::ostringstream oss;	
		std::string y;
		oss<<(inventory);
		y = oss.str();
		header += y;
	}		
	Dialog::message(header, "All Objects (Type,name,part number,price,part specifications)");
}