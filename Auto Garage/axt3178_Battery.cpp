#include "axt3178_Battery.h"

Battery::Battery(){
	Auto_Part();
	cranking_amps = 0;
	cold_cranking_amps = 0;
	voltage = 0;
	reserve_capacity_minutes = 0;
}
int Battery::get_cranking_amps(){
	return cranking_amps;
}
int Battery::get_cold_cranking_amps(){
	return cold_cranking_amps;
}
int Battery::get_voltage(){
	return voltage;
}
int Battery::get_reserve_capacity_minutes(){
	return reserve_capacity_minutes;
}
void Battery::set_cranking_amps(int ca){
	cranking_amps = ca;
}
void Battery::set_cold_cranking_amps(int cca){
	cold_cranking_amps = cca;
}
void Battery::set_voltage(int v){
	voltage = v;
}
void Battery::set_reserve_capacity_minutes(int rcm){
	reserve_capacity_minutes = rcm;
}
std::ostream& operator<<(std::ostream& ost,const Battery& battery){
	
}
std::string Battery::to_string(){
	std::string B;
	B =type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + std::to_string(cranking_amps)+" " + std::to_string(cold_cranking_amps) + " "+ std::to_string(voltage) + " "+ std::to_string(reserve_capacity_minutes);
	return B;
}
