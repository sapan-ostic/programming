/** C-Style Strings 
 * Sequence of char in "" 
 * Terminated by Null char  
 * constant
**/

#include <iostream>
#include <cctype> // contains functions isalpha(c), isalnum(c), isdigit(c), tolower(c), toupper(c) ...
#include <cstring> // operations 
using namespace std;

int main(){

    // Definition 1: const char*
    const char* str1 = "paris";
    cout << str1 << endl; // paris
    cout << str1[0] << endl; // p

    // Definition 2: char []    
    char str2[] {"NewYork"}; // modifiable
    cout << str2[7] << endl; // garbage
    str2[0] = 'n';  
    cout << str2 << endl;

    // Operations
    char str3[20];
    cout << strcpy(str3, "Hello") << endl;    
    
    // Convert to Numbers
    char str4[] {"10.5"};
    float i = atof(str4);
    cout << i << endl;
    return 0;
}

