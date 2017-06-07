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

double avg_price() const;
{
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
	
}

int main() {
  Sales_data total;
  double price;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.set_revenue(price);
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      trans.revenue = set_revenue(price);
      if (total.bookNo == trans.bookNo) {
          total.combine(trans);
      } else {
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << std::endl;
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    std::cout << total.bookNo << " "
              << total.units_sold << " "
              << total.revenue << std::endl;
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }

  return 0;
}