#include "axt3178_Auto_Part.h"

class Windshield_Wiper : public Auto_Part
{
public:
	Windshield_Wiper();
	Windshield_Wiper(std::string t, std::string n, int pn, double p, int l, std::string ft) : length(l),frame_type(ft),Auto_Part(t,n,pn,p) {};
	int get_length();
	std::string get_frame_type();
	void set_length(int);
	void set_frame_type(std::string);
	friend std::ostream& operator<<(std::ostream&,const Windshield_Wiper&);	
	std::string to_string();
private:
	int length;
	std::string frame_type;
}; 
