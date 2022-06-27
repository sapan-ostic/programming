# std::map

![std::map](/wiki/media/map.png)

### How to iterate through maps
```C++
std::map<char,int> table;
PopulateMap(&table);

// While loop
auto iter = table.begin();
while(iter != table.end()){
    // Do something
    std::cout << iter->first << ": " << iter->second << "\n"; 
    ++iter;
}

// for loop
for (auto iter=table.begin(); iter!=table.end();++iter){
    // Do something
    std::cout << iter->first << ": " << iter->second << "\n"; 
}

// Use range-based for loop to iterate over std::map elements
for (const auto &iter : table) {
    cout << "[" << iter.first << "," << iter.second << "]\n";
}

// Use range-based for loop to iterate over std::map key-value pairs
for (const auto &[key, value] : table) {
    cout << "[" << key << "," << value << "]\n";
}

```

### What if the key is non-hashable ?
```C++
struct City{
    std::string name;
    int population;
    int latitude;  
    int longitude;
};

std::unordered_map<City, int> tour_plan; // Errors
std::unordered_map<City*, int> tour_plan; // workaround
```
The above code will error out as the hash function is trying to hash the key. But city is custom type and C++ doesn't know how to hash it. A workaround is to use the pointer as its an `int` and C++ has knows how to hash it. But let's see how to provide a hash function for a custom data type.

![std::map](/wiki/media/hashing.png)
[Hashing](https://en.wikipedia.org/wiki/Hash_function) is the process of mapping the keys to the values through a hash function. For a custom data type, we want to define how we can uniquely identify the key and map to the corresponding value when requested. For example, for every city lats & longs are unique.

There are essentially two components:
1. **hash function**: this must be a class that overrides operator() and calculates the hash value given an object of the key-type. One particularly straight-forward way of doing this is to specialize the std::hash template for your key-type. E.g. for int, we can simply return the int value as the hash.

2. **`==` functionality**: this is required because the hash cannot rely on the fact that the hash function will always provide a unique hash value for every distinct key (i.e., it needs to be able to deal with collisions), so it needs a way to compare two given keys for an exact match. You can implement this either as a class that overrides operator(), or as a specialization of std::equal, or – easiest of all – by overloading operator==() for your key type.

```C++
namespace std {
  template <>
  struct hash<City> {
    std::size_t operator()(const City& key) const {
      return std::hash<std::string>()(key.name);
    }
  };
}
```

### Notes
1. Access in `std:map<>` is NOT O(1)! It's O(logn). `std::map` implements a balanced binary tree and sorts the elements. So, to find any key, we would have to iterate over the binary tree and find it.

2. `std::unordered_map` uses a hash table to store and retrieve the value corresponding to a key. So, accessing is O(1).


### References: 
1. [Maps in C++ (std::map and std::unordered_map), The Cherno](!https://www.youtube.com/watch?v=KiB0vRi2wlc)
2. [HackingCpp]()
3. [cpp-custom-hash, Ian Pan](https://ianyepan.github.io/posts/cpp-custom-hash/)