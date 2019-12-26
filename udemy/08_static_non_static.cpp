# include <iostream>

int* static_local(int x){
	static int num = x;
	std::cout<<"num_local_before = "<< num<< std::endl;
	num = num*2;
    std::cout<<"num_local_after = "<< num<< std::endl;
    return &num;
}

int* local(int x){
	int num = x;
	std::cout<<"num_local_before = "<< num<< std::endl;
	num = num*2;
    std::cout<<"num_local_after = "<< num<< std::endl;
    std::cout<< "test_ptr: " << &num << std::endl;
    return &num;
}

int main(){
    int *ptr;
    ptr = static_local(10); //10 20
    std::cout<< "test_ptr: " << *ptr << std::endl;  
    static_local(10);
    
    ptr = local(10);
    std::cout<< "test_ptr: " << ptr << std::endl;
    
    return 0;
}