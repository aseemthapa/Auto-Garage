#include <map>
class Order{

public:
    Order();
    Order(std::string cn, std::string ad, std::string bi, int on, std::string st) : customer_name(cn), address(ad), billing_info(bi), order_num(on), status(st) {};
private:
    std::string customer_name;
    std::string address;
    std::string billing_info;
    int order_num;
    std::map<int, int> order_details;
    std::string status;
};