/***
 * Function Templates
 * - acts as blueprint
 * - allow any data plugin
 * - meta programming => generic function
 * - error messages might be difficult to understand
 * @return
 */

// Defining the Template function
template <typename T> // or template <class T>

T max(T a, T b){
    return (a>b)?a:b;
}

# include <iostream>
int main(){
    std::cout << "Hello to Templates" << std::endl;
    std::cout << "=> Max(4,5) is " << max<int>(4,5) << std::endl;
    std::cout << "=> Max(4.5, -5.2) is " << max<int>(4.5,-5.2) << std::endl;
    std::cout << "=> Max(4.5, -5.2) is " << max<double>(4.5,-5.2) << std::endl;
    std::cout << "=> Max('a', 'b') is " << max('a','b') << std::endl;
    return 0;
}


