#include "axt3178_Engine.h"

Engine::Engine(){
	Auto_Part();
	num_cylinders = 0;
	fuel_type = "";
}
std::string Engine::get_fuel_type(){
	return fuel_type;
}
int Engine::get_num_cylinders(){
	return num_cylinders;
}
void Engine::set_num_cylinders(int nc){
	num_cylinders = nc;
}
void Engine::set_fuel_type(std::string ft){
	fuel_type = ft;
}
std::ostream& operator<<(std::ostream& ost,const Engine& e){
	
}
std::string Engine::to_string(){
	std::string E;
	E = type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + fuel_type+ " " + std::to_string(num_cylinders);
	return E;
}
