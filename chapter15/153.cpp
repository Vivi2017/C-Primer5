#include <iostream>
#include <string>

class Quote;
class Bulk_quote;
class Limited_quote;

class Quote{
public:
    Quote() = default;
    Quote(const  std::string &book, double sales_price):
                   bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const
    	{ return n*price;}
    	
    virtual ~Quote() = default;
    
private:
    std::string bookNo;
protected:
	   double price = 0.0;
};

class Bulk_quote:public Quote{//派生类必须通过类派生列表 class derivation list明确指出它是从哪个（哪些）基类来的
public:
	Bulk_quote() = default;
	Bulk_quote(const  std::string &book, double sales_price, double disc, std::size_t qty )
		:Quote(book, sales_price), 
			discount(disc), 
			min_qty(qty)
			{}
		//C++ 11 允许继承的类使用override ecplicit的表明要重载基类的某个虚函数
	double net_price(std::size_t n) const override{
        if(n < min_qty)
  	        return n*price;
        else
  	 	      return n*price*(1 - discount);
  }
    	
 private:
 	double discount = 0.0;
 	std::size_t min_qty = 0;
};



class Limited_quote:public Quote{//派生类必须通过类派生列表 class derivation list明确指出它是从哪个（哪些）基类来的
public:
	Limited_quote() = default;
	Limited_quote(const  std::string &book, double sales_price, double disc, std::size_t qty )
		:Quote(book, sales_price), 
			discount(disc), 
			max_qty(qty)
			{}
		//C++ 11 允许继承的类使用override ecplicit的表明要重载基类的某个虚函数
	double net_price(std::size_t n) const override{
        if(n <= max_qty)
  	        return  n*price*(1 - discount);
        else
  	 	      return (n - max_qty)*price + max_qty*price*(1 - discount);
  }
    	
 private:
 	double discount = 0.0;
 	std::size_t max_qty = 0;
};

 std::ostream & print_total(std::ostream & os, const Quote & qt,  std::size_t n){
      os<<"ISBN :" <<qt.isbn() <<"  total price of "<< n << " is "<<qt.net_price(n);
      return os;
}

int main(){
     Quote qt1(std::string("What's up"), 10.0);
     Bulk_quote bqt2(std::string("Destination"), 10.0, 0.5, 2);
     Limited_quote lqt(std::string("Max quantity"), 10.0, 0.5, 5);
     print_total(std::cout, qt1, 2) <<std::endl;
     print_total(std::cout, bqt2, 5) <<std::endl;
     print_total(std::cout, lqt, 5) <<std::endl;
     	print_total(std::cout, lqt, 7) <<std::endl;
}