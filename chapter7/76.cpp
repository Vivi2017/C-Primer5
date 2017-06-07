#include <string>
#include <iostream>
using namespace std;

struct Sales_data {
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    void set_revenue(double price){revenue = units_sold * price;}
  	
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

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

std::istream &read(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue <<endl;
  return os;
}

int main() {
  Sales_data total;
  
  
  if (read(cin,total)) {
   
    Sales_data trans;
    
    while (read(cin,trans)) {
      if (total.bookNo == trans.bookNo) {
          total = add(total, trans);
      } else {
        print(cout, total);
        
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    print(cout, total);
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }

  return 0;
}