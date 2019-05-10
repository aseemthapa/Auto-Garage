#include "axt3178_Wheel_Tire_Combo.h"

Wheel_Tire_Combo::Wheel_Tire_Combo(){
	Auto_Part();
	Wheel();
	Tire();
}
std::ostream& operator<<(std::ostream& ost,const Wheel_Tire_Combo& wtc){
	
}		
std::string Wheel_Tire_Combo::to_string(){
	std::string WWC;
	WWC = " " + type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + "\n" + " " + category + " "+ color + " "+ std::to_string(Wheel::diameter) + " " + std::to_string(Wheel::width) + " " + bolt_pattern + " " + tire_type+ " " + std::to_string(Tire::width) + " " + std::to_string(ratio) + " " + std::to_string(Tire::diameter) + " " + speed_rating + " " + load_range;
	return WWC;
}
