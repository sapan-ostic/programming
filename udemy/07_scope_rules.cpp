# include <iostream>

void local_variable(int x){
	int num = 10;
	std::cout<<"num_local_before = "<< num<< std::endl;
	num = x;
    std::cout<<"num_local_after = "<< num<< std::endl;
}

void static_local(int x){
	static int num = x;
	std::cout<<"num_local_before = "<< num<< std::endl;
	num = num*2;
    std::cout<<"num_local_after = "<< num<< std::endl;
}


int num_global = 123;
void global_variable(){
	std::cout<<"num_global_before = "<< num_global<< std::endl;
	int num_global = 20;
    std::cout<<"num_global_after = "<< num_global<< std::endl;
}

int main(){
	int num1 = 100;
	int num2 = 500;

	{ // new scope
		int num1 = 50;
		std::cout<<"num1 = "<< num1<< std::endl; //50
        std::cout<<"num2 = "<< num2<< std::endl; //500 
    }
	
	std::cout<<"num1 = "<< num1<< std::endl; //100
	// scope can see what’s outside but others can’t. 
		
	local_variable(20);
	global_variable();
	static_local(1); // once initialized, static variable preserves the value within the local scope.
    static_local(1);

return 0;
}
