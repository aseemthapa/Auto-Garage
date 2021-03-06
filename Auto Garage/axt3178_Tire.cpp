#include "axt3178_Tire.h"

Tire::Tire(){
	Auto_Part();
	tire_type = "";
	width = 0;
	ratio = 0;
	diameter = 0;
	speed_rating = "";
	load_range = "";
}
std::string Tire::get_tire_type(){
	return tire_type;
}
int Tire::get_width(){
	return width;
}
int Tire::get_ratio(){
	return ratio;
}
int Tire::get_diameter(){
	return diameter;
}
std::string Tire::get_speed_rating(){
	return speed_rating;
}
std::string Tire::get_load_range(){
	return load_range;
}
void Tire::set_tire_type(std::string tt){
	tire_type = tt;
}
void Tire::set_width(int w){
	width = w;
}
void Tire::set_ratio(int r){
	ratio = r;
}
void Tire::set_diameter(int dia){
	diameter = dia;
}
void Tire::set_speed_rating(std::string sr){
	speed_rating = sr;
}
void Tire::set_load_range(std::string lr){
	load_range = lr;
}
std::ostream& operator<<(std::ostream& ost,const Tire& tire){
	
}	
std::string Tire::to_string(){
	std::string T;
	T = type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + tire_type+ " " + std::to_string(width) + " " + std::to_string(ratio) + " " + std::to_string(diameter) + " " + speed_rating + " " + load_range;
	return T;
}
