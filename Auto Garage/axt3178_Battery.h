#include "axt3178_Auto_Part.h"

class Battery : public Auto_Part
{
public:
	Battery();
	Battery(std::string t, std::string n, int pn, double p, int ca, int cca, int v, int rcm) : cranking_amps(ca), cold_cranking_amps(cca), voltage(v), reserve_capacity_minutes(rcm),Auto_Part(t,n,pn,p) {};
	int get_cranking_amps();
	int get_cold_cranking_amps();
	int get_voltage();
	int get_reserve_capacity_minutes();
	void set_cranking_amps(int);
	void set_cold_cranking_amps(int);
	void set_voltage(int);
	void set_reserve_capacity_minutes(int);
	friend std::ostream& operator<<(std::ostream&,const Battery&);	
	std::string to_string();
private:
	int cranking_amps;
	int cold_cranking_amps;
	int voltage;
	int reserve_capacity_minutes;
}; 
