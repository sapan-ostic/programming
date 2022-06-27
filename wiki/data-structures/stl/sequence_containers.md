# Sequence Containers

![SequenceContainers](/wiki/media/sequence_containers.png)
1. `array<T,size>`: fixed-size contiguous array
2. `vector<T>`: dynamic contiguous array, amortized O(1) growth stategy,; C++'s default container
3. 'deque<T>': double-ended queue; fast insert/erase at both ends
4. `list<T>`: doubly-linked list; O(1) insert, erase & splicing; in practice often slower than vector.
5. `forward_list<T>`: singly-linked list; O(1) insert, erase & splicing; needs less memory than list; in practice often slower than vector

## Common Features:

### 1. Regularity: Copy, Assign, Compare
All standard sequence containers are regular types:

1. **deeply copyable**: copying creates a new container object and copies all contained values
2. **deeply assignable**: all contained objects are copied from source to assignment target
3. **deeply comparable**: comparing two containers compares the contained objects
4. **deep ownership**: destroying the container destroys all contained objects

```C++
std::vector<int> a {1,2,3};
std::vector<int> b {4,5,6,7};

bool equal1 = (a==b); // false
a = b;
bool equal2 = (a==b); // true
a[0] = 3;
bool equal3 = (a==b); // false

// different ways of making the exact copies,
// i.e. copy-constructing new containers:
std::vector<int> a2 {a};
std::vector<int> a3 (a);
std::vector<int> a4 = a;
auto a5 {a};
auto a6 (a);
auto a7 = a;
```

### 2. Type Argument Deduction [C++17]
As of C++17 the element type can be deduced from constructor calls.
```C++
std::vector v {1, 2, 3, 4};       // std::vector<int>
std::vector v {1.f, 2.3f, 4.5f};  // std::vector<float>
std::vector v {1., 2.3, 4.6};     // std::vector<double>

struct p2 { int x; int y; };
std::vector v {p2{1,2}};          // std::vector<p2>
```
### 3. Common Interface Parts

1. **Iterators for forward traversal**: can be obtained from all standard sequence containers either with member functions
```C++
container.begin(); // @first_element
container.end();   // @one_behind_last_element

// or with free standing functions [C++11]
std::begin(container); // @first_element
std::end(container);   // @one_behind_last_element
```
2. **Const Iterators for forward traversal**: can be obtained from all standard sequence containers either with member functions
```C++
container.cbegin(); // const@first_element
container.cend();   // const@one_behind_last_element

// or with free standing functions [C++11]
std::cbegin(container); // const@first_element
std::cend(container);   // const@one_behind_last_element
```
3. **Emptiness Query**:
```C++
// either with member function
container.empty(); // true, if container has no elements 

// or with free-standing function [C++11]
std::empty(container) // true, if container has no elements 
```
4. **Type Interface**
```C++
// container::value_type
// container::size_type
// container::iterator
// container::const_iterator
// ...

using con_t = std::vector<double>;
con_t::size_type i = 0;         // std::size_t of vector is 0
auto x = con_t::value_type{0};  // vector stores double
```

Sequence Containers in more details: 
1. [array<T, size_t>](/wiki/stl/std%3A%3Aarray.md)
2. [vector\<T>](/wiki/stl/std%3A%3Avector.md)
3. [deque\<T>](/wiki/stl/std%3A%3Adeque.md)
4. [list\<T>](/wiki/stl/std%3A%3Alist.md)
5. [forward_list\<T>](/wiki/stl/std%3A%3Aforward_list.md)
