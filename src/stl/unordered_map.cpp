/**
 * @file maps.cpp
 * Benefits: Random Access for associated data
 *
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

struct City {
  std::string name;
  int population;
  int latitude;
  int longitude;

  // equal_to function overloaded
  bool operator==(const City &other) const {
    return (this->latitude == other.latitude &&
            this->longitude == other.longitude);
  }
};

// Method 1: specializing the std::hash template for City
// Hash function, this must be accompanied with the overloaded equal_to operator
namespace std {
template <> struct hash<City> {
  std::size_t operator()(const City &key) const {
    // we return the hash using method same as for strings
    return std::hash<std::string>()(key.name);
  }
};
} // namespace std

// Method 2: passing the function object with structure
struct KeyHasher {
  std::size_t operator()(const City &key) const {
    return std::hash<std::string>()(key.name);
  }
};

// Generate map with n elements <key, value>
std::unordered_map<City, int> *GenerateMap(int n = 10);

// visualize map
void PrintMap(const std::unordered_map<City, int> &table);
void PrintMap(const std::unordered_map<City, int, KeyHasher> &table);

int main() {
  // 1. Custom data type hashing
  std::unordered_map<City, int> *table = GenerateMap(5);
  PrintMap(*table);

  std::unordered_map<City, int, KeyHasher> table_with_hasher;
  table_with_hasher.insert({{"A"}, 1});
  table_with_hasher.insert({{"B"}, 2});
  PrintMap(table_with_hasher);
  return 0;
}

std::unordered_map<City, int> *GenerateMap(int n) {
  printf("Generating map ... \n");
  std::unordered_map<City, int> *table = new std::unordered_map<City, int>;
  for (int i = n; i > 0; --i) {
    table->insert({{"City" + std::to_string(i)}, i * 10});
  }
  return table;
}

void PrintMap(const std::unordered_map<City, int> &table) {
  for (auto it : table) {
    std::cout << it.first.name << ", " << it.second << "\n";
  }
  std::cout << "\n";
}

void PrintMap(const std::unordered_map<City, int, KeyHasher> &table) {
  for (auto it : table) {
    std::cout << it.first.name << ", " << it.second << "\n";
  }
  std::cout << "\n";
}
