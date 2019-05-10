#ifndef AXT3178_AUTO_PART_H
#define AXT3178_AUTO_PART_H
#include <iostream>
#include <string>

class Auto_Part{
public:
	Auto_Part();
	Auto_Part(std::string,std::string,int,double);
	std::string get_type();
	std::string get_name();
	int get_part_number();
	double get_price();
	void set_type(std::string);
	void set_name(std::string);
	void set_part_number(int);
	void set_price(double);
	friend std::ostream& operator<<(std::ostream&, const Auto_Part&);
	bool operator<(const Auto_Part&) const;
	virtual std::string to_string(); 
protected:
 	std::string type;
	std::string name;
	int part_number;
	double price; 
};
#endif
