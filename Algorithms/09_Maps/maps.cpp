//
// Created by agrsapan on 9/27/20.
//

/**
* std::map
* std::unordered_map
* std::multi_map
* std::unordered_multimap
 */

#include <map>
#include <iostream>

using namespace std;

void display(const map<string, int> &m){
    cout  << "[ ";
    for (const auto &it:m)
        cout<< it.first << ": " << it.second << " ";
    cout  << "]"<< endl;
}

int main(){
    // Define map
    map<string, int> students;

    // Insertion method 1
    pair<string, int> s1 {"Anne", 20}; //1
    students.insert(s1);

    students.insert(std::make_pair("John", 22)); //2
    students.insert(std::make_pair("Steve", 21)); //3

    // Insertion method 2 & Update method 1
    students["Smith"] = 19; //4

    display(students);

    // Update method 2
    students.at("Smith") = 20; // 4

    // Erase/deletion
    students.erase("Smith"); //3
    cout << "Removing Smith from Class!" << endl;

    auto it = students.find("John");
    if (it != students.end()) {
        cout <<  it->first <<" found with age " << it->second <<endl;
        cout << "Removing John from Class!" << endl;
        students.erase(it); //2
    }
    // Useful functions
    cout << "class size: " << students.size() << endl; //2
    display(students);
    cout << "max size: " << students.max_size() << endl; // big number

    cout << "Class empty? " << students.empty() << endl;

    cout << "Anne there? " << students.count("Anne") << endl; // 1
    cout << "Steve's Age? " << students["Steve"] << endl; // 21
    cout << "Smith there? " << students.count("Smith") << endl; // 0
    cout << "John's Age? " << students["John"] << endl; // 0

    // Clear Map
    students.clear();
    cout << "Class empty after clear()? " << students.empty() << endl;

    return 0;
}