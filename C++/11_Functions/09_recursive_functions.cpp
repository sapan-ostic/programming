#include <iostream>

long int fact(long int n){
	if (n == 0){
	return 1;
}

else{
	return n*fact(n-1);
}
}

int main(){
	std::cout<< " Factorial(3) = "  << fact(3)<< std::endl;
	return 0;
}