#include "axt3178_Auto_Part.h"

class Tire : public virtual Auto_Part
{
public:
	Tire();
	Tire(std::string t, std::string n, int pn, double p, std::string tt, int w, int r, int dia, std::string sr, std::string lr) : tire_type(tt),width(w),ratio(r),diameter(dia),speed_rating(sr),load_range(lr),Auto_Part(t,n,pn,p) {};
	std::string get_tire_type();
	int get_width();
	int get_ratio();
	int get_diameter();
	std::string get_speed_rating();
	std::string get_load_range();
	void set_tire_type(std::string);
	void set_width(int);
	void set_ratio(int);
	void set_diameter(int);
	void set_speed_rating(std::string);
	void set_load_range(std::string);
	friend std::ostream& operator<<(std::ostream&,const Tire&);	
	std::string to_string();
protected:
	std::string tire_type;
	int width;
	int ratio;
	int diameter;
	std::string speed_rating;
	std::string load_range;	
}; 
