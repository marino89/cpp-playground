#include <stdio.h>
#include <iostream>
#include <vector>
#include "Mystring.h"

int main(int argc, char **argv)
{
	Mystring a{"Hello"};
    Mystring b;
    b = a;
    
    // with move assignement
    a = Mystring{"Hola"};  // this is r-value as the object as to be created first
    a = "Bonjour";
    
    Mystring larry {"LARRY"};
    larry.display();
    larry = -larry;
    larry.display();
    
    std::cout << "Creating Francis" << std::endl;
    Mystring francis {"Francis"};
    Mystring together = larry + francis;
    std::cout << together.getString() << std::endl;
    
    francis += larry;
    std::cout << "New francis: " << francis.getString() << std::endl;
    
    std::vector<Mystring> words = {Mystring("Hello"), Mystring("Buongiorno"), Mystring("Bonjour")};
    Mystring sum;
    for (const auto &w: words)
        sum += w;
    std::cout << "Sum is " << sum.getString() << std::endl;
    
    Mystring multi = a * 5;
    std::cout << "mutli is " << multi.getString() << std::endl;
    
    
    
    return 0;
}
