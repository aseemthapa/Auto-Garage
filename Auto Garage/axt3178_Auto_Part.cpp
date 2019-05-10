#include "axt3178_Auto_Part.h"

Auto_Part::Auto_Part(){
        type = "";
	name = "";
	part_number = 0;
	price = 0;
}

Auto_Part::Auto_Part(std::string t,std::string n,int pn,double p){
	type = t;
	name = n;
	part_number = pn;
	price = p;
}

std::string Auto_Part::get_type(){
	return type;
}
std::string Auto_Part::get_name(){
	return name;
}
int Auto_Part::get_part_number(){
	return part_number;
}
double Auto_Part::get_price(){
	return price;
}
void Auto_Part::set_type(std::string t){
	type = t;
}
void Auto_Part::set_name(std::string n){
        name = n;
}
void Auto_Part::set_part_number(int pn){
        part_number = pn;
}
void Auto_Part::set_price(double p){
 	price = p;
}
std::ostream& operator<<(std::ostream& ost, const Auto_Part& Auto){
	ost<<"Type: "<<Auto.type<<", Name: "<<Auto.name<<", Part Number: "<<Auto.part_number<<", Price: $"<<Auto.price;
}
bool Auto_Part::operator<(const Auto_Part& rhs) const{
	if(this->part_number < rhs.part_number)
	return true;
	return false;
}
std::string Auto_Part::to_string(){
	
}

