#include "axt3178_Wheel.h"
#include "axt3178_Tire.h"

class Wheel_Tire_Combo : public Wheel, public Tire
{
public:
	Wheel_Tire_Combo();
	Wheel_Tire_Combo(std::string t, std::string n, int pn, double p, std::string cat, std::string c, int w_dia, int w_w, std::string bp, std::string tt, int w, int r, int dia, std::string sr, std::string lr) : Auto_Part(t,n,pn,p), Wheel(t,n,pn,p,cat,c,w_dia,w_w,bp), Tire(t,n,pn,p,tt,w,r,dia,sr,lr) {};
	friend std::ostream& operator<<(std::ostream&,const Wheel_Tire_Combo&);	
	std::string to_string();
}; 
