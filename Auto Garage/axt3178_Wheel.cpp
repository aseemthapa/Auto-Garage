#include "axt3178_Wheel.h"

Wheel::Wheel(){
	Auto_Part();
	category = "";
	color = "";
	diameter = 0;
	width = 0;
	bolt_pattern = "";
}
std::string Wheel::get_category(){
	return category;
}
std::string Wheel::get_color(){
	return color;
}
int Wheel::get_diameter(){
	return diameter;
}
int Wheel::get_width(){
	return width;
}
std::string Wheel::get_bolt_pattern(){
	return bolt_pattern;
}
void Wheel::set_category(std::string cat){
	category = cat;
}
void Wheel::set_color(std::string c){
	color = c;
}
void Wheel::set_diameter(int dia){
	diameter = dia;
}
void Wheel::set_width(int w){
	width = w;
}
void Wheel::set_bolt_pattern(std::string bp){
	bolt_pattern = bp;
}
std::ostream& operator<<(std::ostream& ost,const Wheel& wheel){
	
}	
std::string Wheel::to_string(){
	std::string W;
	W = type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + category + " "+ color + " "+ std::to_string(diameter) + " " + std::to_string(width) + " " + bolt_pattern;
	return W;
}
