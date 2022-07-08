//inbuilt header files
#include <iostream>
#include<string>

//user defined header file
#include "BigInteger.h"

using namespace std;

int main(){

    
    string a = "1534312486213483512315484532154864531548415843215";
    string b = "9343124862134835123545462446564564564564565655";
    
    
    //finding the sum of two big integers

    cout<<add(a,b)<<endl<<endl;


    //finding the difference between two big integers

    cout<<sub(a,b)<<endl<<endl;


    //finding the maximum of two big integers

    cout<<maxInteger(a,b)<<endl;

    return 0;
    
     
}



