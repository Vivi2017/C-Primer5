#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename Tw, typename Th> class Screen;

template <typename Tw , typename Th>
class Screen
{
	public:
		Screen():Width(0), Height(0){};
		Screen(Tw w,  Th h):Width(w), Height(h){  
			//cout<<"Screen w *h = ( " <<Width <<" )*( "<<Height <<" )" <<endl;
			};
	
			ostream &  print_screen(ostream &os);
	private:
		Tw   Width;
		Th   Height;
};
template <typename Tw , typename Th>
ostream & Screen<Tw, Th>::print_screen(ostream &os)
{
 	    os<<"Screen w *h = " <<Width <<" * "<<Height;
 	    return os;
}
int main(){
     Screen<int,int>  screen_de;
    //print_screen(cout, screen_de)<<endl;
    screen_de.print_screen(cout)<<endl;
     
    Screen<int,int>  screen_int ={5,6};
    screen_int.print_screen(cout)<<endl;
      
     Screen<float, float>  screen_f ={5.5, 6.6};
    screen_f.print_screen(cout)<<endl;
           
}