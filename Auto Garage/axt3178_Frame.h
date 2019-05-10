#include "axt3178_Auto_Part.h"

class Frame : public Auto_Part
{
public:
	Frame();
	Frame(std::string t, std::string n, int pn, double p, std::string ft) : frame_type(ft), Auto_Part(t,n,pn,p) {};
	std::string get_frame_type();
	void set_frame_type(std::string);
	friend std::ostream& operator<<(std::ostream&,const Frame&);	
	std::string to_string();
private:
	std::string frame_type;
}; 
