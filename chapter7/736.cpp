class x
{
    
   X(int i, int j):base(i),rem(base%j){};
   
   int rem,base;
    
 };
 
 The order that class members initialization is same as sequence in defination.
 when rem is initializing , base is still not exisited. so rem(base%j) is wrong.
 
 It can change to :
    
   -->  X(int i, int j):base(i),rem(i%j){};
    
    or
    --> int base, rem;
   