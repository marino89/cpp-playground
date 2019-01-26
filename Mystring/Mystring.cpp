#include <cstring>
#include <iostream>
#include "Mystring.h"

Mystring::Mystring()
    :str(nullptr) {
        str = new char[1];
        *str = '\0';
}

Mystring::Mystring(const char *s)
    :str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';                           
    }
    else {
        str = new char[std::strlen(s) + 1];  // allocate characters
        std::strcpy(str, s);
    } // copies s to str
}

Mystring::Mystring(const Mystring& source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
}
    
Mystring::Mystring(Mystring &&source)
    : str(source.str) { // pointer copy this->str sucks source's str pointer address
        source.str = nullptr;  // null out the source's pointer
        std::cout << "Move constructor used" << std::endl;
    }
    
    
Mystring::~Mystring()
{
    delete [] str;
}

    
void Mystring::display() const {
    std::cout << str << ":" << getLength() << std::endl;
}

int Mystring::getLength() const {
    return std::strlen(str);
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignement" << std::endl;
    
    if (this == &rhs)
        return *this;
    
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];  //+! because of the null terminator
    std::strcpy(this->str, rhs.str);
    
    return *this;  // return the lhs
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    
    std::cout << "Using move assignement" << std::endl;
    
    if (this == &rhs)
        return *this;
    
    delete [] this->str;  // delete this str pointer
    str = rhs.str;  // still rhs pointer
    rhs.str = nullptr; // nullify rhs pointer

    return *this;
}


bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}


bool Mystring::operator!=(const Mystring &rhs) const {
    return (!(this->operator==(rhs)));
}

Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(this->str) + 1];
    std::strcpy(buff, this->str);
    for (size_t i = 0; i < std::strlen(buff); ++i) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t buff_size = std::strlen(this->str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];
    std::strcat(buff, this->str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    
    return temp;
}

Mystring Mystring::operator+=(const Mystring& rhs) {
    *this = *this + rhs;
    return *this;
    
}


Mystring Mystring::operator*(int n) {
    Mystring result;
    for (int i = 1; i < n; ++i) 
        result = result + *this;
    
    return result;
}


Mystring &Mystring::operator++() {
    for (size_t i = 0; i < std::strlen(this->str); i++) 
        this->str[i] = std::toupper(this->str[i]);
    return *this;
}

// equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// make lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i = 0; i < std::strlen(buff); ++i) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    
    return temp;
}


// concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    size_t buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    
    return temp;
}


