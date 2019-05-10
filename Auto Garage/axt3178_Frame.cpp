#include "axt3178_Frame.h"

Frame::Frame(){
	Auto_Part();
	frame_type = "";
}

std::string Frame::get_frame_type(){
	return frame_type;
}
void Frame::set_frame_type(std::string ft){
	frame_type = ft;
}
std::ostream& operator<<(std::ostream& ost,const Frame& F){
	
}	
std::string Frame::to_string(){
	std::string F;
	F = type + " " + name + " " + std::to_string(part_number) + " " + std::to_string(price) + " " + frame_type;
	return F;
}
