#include <iostream>
using namespace std;
#include "Drib.h"
int main()
{
    Drib F;
  
    cout << F.getChis() << endl;
    cout << F.getZnam() << endl;
    F.print();

    F.addF(2, 4, 4, 8);
    
    F.addNum(2, 6, 6);
    
    F.subF(8, 2, 5, 15);

    F.multNum(10, 20, 30);
    
    F.multF(12, 24, 4, 8);
    
    F.divF(3, 6, 9, 3);

    F.equals(2, 2, 4, 2);
   
    
   
}
