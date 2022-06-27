/**
 * @file maps.cpp
 * Benefits: Random Access for associated data
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

// Generate map with n elements <key, value>
std::map<int, int> *GenerateMap(int n = 10);

// visualize map
void PrintMap(const std::map<int, int> &table);

bool cmp_value_less_than(std::pair<int, int> &a, std::pair<int, int> &b) {
  return a.second < b.second;
}

// Typically, std::map is implemented using a Balanced Binary Tree (e.g Red
// Black Tree), where the elements are sorted.
template <typename key_type_, typename value_type_>
std::vector<std::pair<key_type_, value_type_>>
SortMapByValue(const std::map<key_type_, value_type_> &table) {

  // declare a vector of pair<key, value>
  std::vector<std::pair<key_type_, value_type_>> sorted_list;

  // append all elements in the vector
  for (auto &it : table) {
    sorted_list.push_back(it);
  }

  std::sort(sorted_list.begin(), sorted_list.end(), cmp_value_less_than);
  return sorted_list;
}

int main() {
  // 1. Note: std::<map> is a sorted map
  std::map<int, int> *table = GenerateMap(5);
  PrintMap(*table);

  printf("map is sorted based on key\n");

  std::map<int, int> table2{{-100, 1}, {100, -1}};
  PrintMap(table2);

  table2 = std::map<int, int>({{100, -1}, {-100, 1}});
  PrintMap(table2);

  // 2. Sorting by value
  printf("Sorting map by value: \n");
  // To sort using value, use custom lambda in the std::sort
  // Nope ! std::sort doesn't like associative containers.
  // std::sort(table->begin(), table->end(), cmp);

  auto sorted_list = SortMapByValue(table2);
  for (auto pair : sorted_list) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }
  std::cout << "\n";
  return 0;
}

std::map<int, int> *GenerateMap(int n) {
  printf("Generating map ... \n");
  std::map<int, int> *table = new std::map<int, int>;
  for (int i = n; i > 0; --i) {
    table->insert({i * 100, i});
  }
  return table;
}

void PrintMap(const std::map<int, int> &table) {
  for (auto it : table) {
    std::cout << it.first << ", " << it.second << "\n";
  }
  std::cout << "\n";
}
