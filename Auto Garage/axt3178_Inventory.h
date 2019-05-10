#include "axt3178_Auto_Part.h"
#include "axt3178_Order.h"
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
class Inventory{

public:
	Inventory();
	void add_part(Auto_Part*);
	void add_parts(Auto_Part*, int);
	std::map<Auto_Part*, int> get_inventory();
	int get_num_parts(Auto_Part*);
	void remove_part(int);
	//void remove_parts(Auto_Part*, int);
	void remove_parts(int,int);
	int size();
	friend std::ostream& operator<<(std::ostream&, const Inventory&);
	std::string make_order(Order,int ,int);
	std::string make_orders();
private:
	std::map<Auto_Part*, int> inventory;
};
