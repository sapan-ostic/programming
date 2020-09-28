# include <iostream>

int add_numbers(int, int);
double add_numbers(double, double);

int main(){
	int a = 2;
    int b = 3;
    double m = 2.2, n = 3.5;
    
    std::cout<< add_numbers(a,b) << std::endl;
    std::cout<< add_numbers(m,n) << std::endl; 
    return 0;
}

int add_numbers(int a, int b){
	return a+b;
}

double add_numbers(double a, double b){
	return a+b;
}
