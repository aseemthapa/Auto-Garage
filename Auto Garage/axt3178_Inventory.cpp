#include "axt3178_Inventory.h"
using namespace std;

std::mutex m;

Inventory::Inventory(){}

void Inventory:: add_part(Auto_Part* part){
	bool check = (inventory.insert(std::pair <Auto_Part*,int>(part,1))).second;
	if(!(check)){
		(inventory.at(part))++;	
	}	
}

void Inventory:: add_parts (Auto_Part* part, int n){
	bool check = (inventory.insert(std::pair <Auto_Part*,int>(part,n))).second;
	if(!(check)){
		(inventory.at(part))+=n;	
	}
}

int Inventory:: get_num_parts(Auto_Part* part){
	int x = (inventory.at(part));
	return x;
}

std::map<Auto_Part*, int> Inventory:: get_inventory(){
	return inventory;
}

void Inventory:: remove_part(int pn){
	//inventory.erase(part);
	Auto_Part* r;
	for (auto x : inventory){
		if(((*(x.first)).get_part_number())==pn){
			r = x.first;		
		}
	}
	inventory.erase(r);	
}

/*void Inventory:: remove_parts(Auto_Part* part, int n){
	(inventory.at(part)) = (inventory.at(part)) - n;
	if ((inventory.at(part)) <= 0){
		inventory.erase(part);	
	}
	
}*/
void Inventory::remove_parts(int pn, int n){
	Auto_Part* r;
	for (auto x : inventory){
		if(((*(x.first)).get_part_number())==pn){
			r = x.first;		
		}
	}
	(inventory.at(r)) = (inventory.at(r)) - n;
	if ((inventory.at(r)) <= 0){
		inventory.erase(r);	
	}	
}

int Inventory:: size(){
	return inventory.size();
}

std::string Inventory::make_order(Order x, int pn, int n){
	//m.lock;
	Auto_Part* r;
	int k = 0;
	for (auto x : inventory){
		if(((*(x.first)).get_part_number())==pn){
			r = x.first;	
			k = 1;	
		}
	}
	if (k==0){
		//m.unlock;
		return "rejected : Invalid Part Number";
	}
	if((inventory.at(r))<n){
		//m.unlock;
		return "rejected : Don't have enough parts";	
	}
	(inventory.at(r)) = (inventory.at(r)) - n;
	if ((inventory.at(r)) <= 0){
		inventory.erase(r);	
	}
	//m.unlock;
	return "Order Accepted";
}

std::string make_orders(){
	std::string fname = "orders.txt";
	std::vector<Order> order_vector;
	std::ifstream myfile(fname);
	if(myfile.is_open()){
		std::string cn,ad,bi,status;
		int pn,n,on;
		int count = 0;
		//std::vector<std::thread> t;
		while(myfile>>cn){
			myfile>>ad>>bi>>on>>status>>pn>>n;
			Order x (cn,ad,bi,on,status);
			//t[count] = std::thread(Inventory::make_order,x,pn,n);
			//count++;
		}
		/*for (int i = 0; i < count; i++){
			t[i].join();
		}*/
	}
	else{
		std::ostringstream oss;
	    std::string y;
	    oss<<"Could not open file";
	    y = oss.str();
	    return y;
	}

}
std::ostream& operator<<(std::ostream& ost, const Inventory& Inv){
	for (auto x : Inv.inventory){
		ost<<(*(x.first)).to_string()<<"  "<<x.second<<std::endl;	
	}
	}



