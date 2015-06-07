

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    string str1="1234567891011121314151617181920", str2="1234567891011121314151617181920" ;
           
    string rev_str1, rev_str2;
    string final;              //Final product string
    int carry = 0;
    
    rev_str1 = string(str1.rbegin(), str1.rend());
    rev_str2 = string(str2.rbegin(), str2.rend());
     
    for (int i = 0; i <rev_str1.length() ; i++)
    {
    	
    	int x=rev_str1[i]-'0';  //converting into integer
       	int y=rev_str2[i]-'0';
    	int z=x+y+carry;
    	
       	final+=('0'+z%10);     //converting into character
    	carry=z/10;	       
    }

    if(carry>0)            //final carry
    final+='0'+carry;
    
    
    final = string(final.rbegin(), final.rend());

    cout << "final = " << final << endl;
    

}
