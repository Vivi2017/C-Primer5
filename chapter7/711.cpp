#include <string>
#include <iostream>
using namespace std;

class Sales_data;
std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
    
    
class Sales_data {
    public:
    Sales_data()= default;
    Sales_data(string bNo):bookNo(bNo){};
    Sales_data(string bNo, unsigned usold, double p):bookNo(bNo),units_sold(usold),revenue(usold*p){};
    Sales_data(istream &is) 
    {
        read(is,*this);
    }
    
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    void set_revenue(double price){revenue = units_sold * price;}
  	
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &read(std::istream& is, Sales_data& item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue <<endl;
  return os;
}


Sales_data& Sales_data::combine(const Sales_data& rhs) {
	
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
	
}

Sales_data add(const Sales_data& rha, const Sales_data& rhb)
{
    Sales_data sum = rha;
    return sum.combine(rhb);
}



int main() {
    Sales_data defaultObj;
    print(cout,defaultObj);
    
    Sales_data bookNoObj = Sales_data(string("1212"));
    print(cout,bookNoObj);
    
    Sales_data threeObj = Sales_data(string("1213"), unsigned(5), double(10.0));
    print(cout,threeObj);
    
    Sales_data isObj = Sales_data(cin);
    print(cout,isObj);
    
    
    return 0;
}