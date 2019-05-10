#include "axt3178_Auto_Part.h"

class Wheel : public virtual Auto_Part
{
public:
	Wheel();
	Wheel(std::string t, std::string n, int pn, double p, std::string cat, std::string c, int dia, int w, std::string bp) : category(cat),color(c),diameter(dia),width(w),bolt_pattern(bp),Auto_Part(t,n,pn,p) {};
	std::string get_category();
	std::string get_color();
	int get_diameter();
	int get_width();
	std::string get_bolt_pattern();
	void set_category(std::string);
	void set_color(std::string);
	void set_diameter(int);
	void set_width(int);
	void set_bolt_pattern(std::string);
	friend std::ostream& operator<<(std::ostream&,const Wheel&);	
	std::string to_string();
protected:
	std::string category;
	std::string color;
	int diameter;
	int width;
	std::string bolt_pattern;
}; 
