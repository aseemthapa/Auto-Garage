#include "axt3178_Auto_Part.h"

class Engine : public Auto_Part
{
public:
	Engine();
	Engine(std::string t, std::string n, int pn, double p, int nc, std::string ft) : num_cylinders(nc),fuel_type(ft), Auto_Part(t,n,pn,p) {};
	std::string get_fuel_type();
	int get_num_cylinders();
	void set_num_cylinders(int);
	void set_fuel_type(std::string);
	friend std::ostream& operator<<(std::ostream&,const Engine&);	
	std::string to_string();
private:
	int num_cylinders;
	std::string fuel_type;
};
