#include <iostream>
#include <vector>
#include <string>

void pass_by_ref(int &num);
void pass_by_ref(std::string &s);
void pass_by_ref(std::vector<int> &v);

int main(){
	int num = 0;
	std::string s = "Whatsup";
	std::vector<int> v;
	v.push_back(100);
    v.push_back(101);
    v.push_back(102);

    pass_by_ref(num);
    pass_by_ref(s);
    pass_by_ref(v);

    std::cout<<"num: "<< num<< std::endl;
    std::cout<<"string: "<< s << std::endl;
    std::cout<<"vector: "<< v.at(0) << " " << v.at(1) << " " << v.at(2); 

    return 0;
} 

void pass_by_ref(int &num){
	num = 100;
}

void pass_by_ref(std::string &s){
	s = "Nothing";
}

void pass_by_ref(std::vector<int> &v){

    for (int i = 0; i < v.size(); i++){         
        v[i] = 1;         
    } 
}
