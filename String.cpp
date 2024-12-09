#include "String.h"
#include <iostream>
using namespace std;

int String::getlen(const char* str)const
{
  int i=0;
  for(; str[i]!='\0'; ++i);

  return i;
}
void String::copystring(const char* src,char * dest)
{
    cout<<"copysttin \n";
    int length=getlen(src);
    for(int i=0; i<length; ++i)
    {
        dest[i]=src[i];

    }
    dest[length]='\0';
}
String::String(const char* str)
{
    cout<<"overloaded constructor is running\n";
    name=new char[getlen(str)+1];
    size=getlen(str);
    copystring(str,name);

}
String::String(const String& obj)
{
    cout<<"copy constructor is running\n";
    name=new char[(obj.size)+1];
    copystring(obj.name, name);
}
char& String::operator[](int idx)
{
    return name[idx];
}
void String::setname(const char* str)
{
    if(name==nullptr)
    {  
    name=new char[getlen(str)+1];
    copystring(str,name);
    } 
    else if(name!=nullptr)
    {
        delete [] name;
        name=new char[getlen(str)+1];
        copystring(str,name);
    }
    
}
char* String::getname()const
{
    cout<<" getname is runing\n";
    return name;
}
String String::operator+(const String& obj)
{
    cout<<"+ operator is running\n";
    String str2;cout<<getlen(name)<<endl; 
    str2.name=new char[obj.size+getlen(name)+1];
    copystring(name,str2.name);
    copystring(obj.name,str2.name+getlen(name));
    return str2;
}
String& String::operator=(const String& str)
{
    cout<<"=operator\n";
    if(this!=&str){ 
    // delete [] name;
    name=new char[str.size+1];
    copystring(str.name,name);}
    return *this;
}
ostream & operator<<(ostream& os ,const String& obj)
{
    cout<<"cout is running\n";
    os<<obj.name;
    return os;
}
istream& operator>>(istream& is,String& obj)
{
    cout<<"cin stream is running\n";
    char arr[50]{};
    is>>arr;
    obj.setname(arr);
    return is;
}
void String::push_back(char ch)
{
    cout<<"push back is running\n";
    if(size==0)
    {
       name=new char[1];

    }
     else
     IncreaseArray();

     name[size++]=ch;
}
void String::IncreaseArray()
{
    size*=2;
    char* arr=new char[size];
    for(int i=0; i<=size/2; ++i)
    {
        arr[i]=name[i];

    }
    delete [ ] name;
    name=arr;
}
bool String::ends_with(const char* str)
{
    int patlen=getlen(str);
    if(patlen<size)
    {
        for(int i{size-1},j{patlen-1}; i>=size-patlen; --i,--j)
        {
            if(str[j]!=name[i])
            {
                return false;
            }
        }
        return true;

    }
    return false;
}
bool String::substring(const char* str)
{
    int patlen=getlen(str);
    for(int i=0; name[i]!='\0'; ++i)
    {
        int j=0;
        for(;str[j]!='\0'; ++j)
        {
            if(str[j]!=name[i])
            {
                break;
            }

        }
        if(j==patlen)
        {
            return 1;
        }
    }
    return -1;
}
String::~String()
{
    delete []  name;
}

