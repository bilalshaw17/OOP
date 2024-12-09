#ifndef String_H
#define String_H
#include <iostream>
using namespace std;
class String
{
  
  char* name;
    int size;
    int getlen(const char* )const;
    void copystring(const char* , char*);
    public:
    String():name(nullptr),size(0){}
    String(const char*);
    String(const String&);
    ~String();
     char& operator[](int);
     char* getname()const;
    void setname(const char*);
    String & operator=(const String& );
    void push_back(char);
    String operator+(const String&);
    void IncreaseArray();
    bool ends_with(const  char*);
    bool substring(const char*);
 friend ostream & operator<<(ostream &, const String&);
 friend istream& operator>>(istream& ,String &);
  
};


#endif