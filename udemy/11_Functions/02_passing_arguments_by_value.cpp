# include <iostream>
# include <vector>

void pass_by_value(std::vector<std::string> any_names); // prototype or
// void pass_by_value(std::vector<std::string> );       // use this

int main(){
	std::vector<std::string> student_names;
	student_names.push_back("Joe");
	student_names.push_back("Amily");
	student_names.push_back("Smith");

	pass_by_value(student_names);
	return 0;
}

void pass_by_value(std::vector<std::string> names){
	for(std::vector<std::string>::iterator i = names.begin(); i != names.end(); i++){
		std::cout<< *i <<std::endl;
	}
}
