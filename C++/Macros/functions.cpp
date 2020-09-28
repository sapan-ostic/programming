#include <iostream>
/***
 * Generic functions using preprocessing Macros
 */

#define MAX(a,b) ((a>b) ? a:b)
#define BadSquare(a) a*a
#define GoodSquare(a) (a*a)

int main() {
    std::cout << "Hello to Macros!" << std::endl;

    int a {5};
    int b {1};
    std::cout << "Max number: " << MAX(a,b) << std::endl;
    std::cout << "Bad Square: " << 100/BadSquare(a) << std::endl; // Expected 4, Get 100
    std::cout << "Good Square: " << 100/GoodSquare(a) << std::endl; // Expected 4, Get 100

    return 0;
}
