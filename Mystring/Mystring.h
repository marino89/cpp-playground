#ifndef MYSTRING_H
#define MYSTRING_H


class Mystring
{
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    
private:
    char *str;
public:
    Mystring(); // default constructor
    Mystring(const char *s);  // overloaded constructor
    Mystring(const Mystring& source);  // copy constructor
    Mystring(Mystring &&source); // move constructor
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);  // copy assignement
    Mystring &operator=(Mystring &&rhs); // Move assignement 
    Mystring operator-() const;  // unary operator
    Mystring operator+(const Mystring &rhs) const;
    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    Mystring operator+=(const Mystring &rhs);
    Mystring operator*(int n);
    Mystring &operator++();
    
    void display() const;
    int getLength() const;
    const char* getString() const {return str;};
    
};

#endif // MYSTRING_H
