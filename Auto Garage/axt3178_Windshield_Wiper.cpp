#include "axt3178_Windshield_Wiper.h"

Windshield_Wiper::Windshield_Wiper(){
	Auto_Part();
	length = 0;
	frame_type = "";
}
int Windshield_Wiper::get_length(){
	return length;
}
std::string Windshield_Wiper::get_frame_type(){
	return frame_type;
}
void Windshield_Wiper::set_length(int l){
	length = l;
}
void Windshield_Wiper::set_frame_type(std::string ft){
	frame_type = ft;
}
std::ostream& operator<<(std::ostream& ost,const Windshield_Wiper& ww){
	
}	
std::string Windshield_Wiper::to_string(){
	std::string WW;
	WW = type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + std::to_string (length) + " "+ frame_type;
	return WW;
}
