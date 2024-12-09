#include <iostream>
#include "String.h"
using namespace std;
int main()
{
    String str1[10]{"Akhuwat","College","Kasure"};
    String str4;
    str4=str1[0]+str1[1]+str1[2];
    cout<<endl;
    str4[9]='Z';
    str1[1][0]='L';
    cout<<str4<<endl;
    cout<<"this0"<<endl;
    char ch;
    while(ch!='9')
    {
        str1[1].push_back(ch);
    }
    cout<<str1[0];
    
    return 0;
}