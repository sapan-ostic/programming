# std::array <T, size>

### References:
1. [https://en.cppreference.com/w/cpp/container/array](https://en.cppreference.com/w/cpp/container/array)
2. [Fredosaurus: Dynamic allocation of Arrays](http://www.fredosaurus.com/notes-cpp/newdelete/50dynamalloc.html)


## Notes:
1. overhead-free random access
2. fast traversal; good for linear searches
3. `size` has to be a constant expression (= known at compile time)
4. does not support size-changing operations (resize, insert, erase, …)
5. potentially slow if element type has high copy/assignment cost (reordering elements requires copying/moving them)

```C++
#include <array>
std::array<int,6> a {4,8,15,16,23,42};
cout << a.size();    // 6
cout << a[0];        // 4
cout << a[3];        // 16
cout << a.front();   // 4
cout << a.back();    // 42

array<int,3> b {7,8,9};
a = b;  //  COMPILER ERROR: types don't match!
```
## Member Functions
`std::array<int, 6> array {1, 2, 3, 4, 5, 6};`
### Iterators
1. `begin`: Return iterator to beginning, `// *it = 1` O(1)
2. `end`: Return iterator to end (memory next to last element) `// it = it[6]+1` O(1)
3. `rbegin`: Return reverse iterator to reverse beginning `// *it = 6` O(1)
4. `rend`: Return reverse iterator to reverse end `// *it = 1` O(1)
5. `cbegin`: Return const_iterator to beginning, iterator itself can change but not the value O(1)
6. `cend`: Return const_iterator to end O(1)
7. `crbegin`: Return const_reverse_iterator to reverse beginning O(1)
8. `crend`: Return const_reverse_iterator to reverse end O(1)

### Capacity
1. `size`: Return size `// 6` O(1)
2. `max_size`: Return maximum size `// 6` (same as size for array as space is already allocated and cannot be changed now) O(1)
3. `empty`: Tests whether array is empty `// false` O(1)

### Element Access
1. `operator[]`: Access element `//a[2] = 3` O(1)
2. `at`: Access element at index `//a.at(2) = 3` O(1)
3. `front`: Access first element `//a.front() = 1`
4. `back`: Access last element `//a.back() = 6` O(1)
5. `data`: Get the pointer to  `//a.back() = 6` O(1)

## Modifiers
1. `fill`: fill array with value `// a.fill(5) == [5,5,5,5,5,5]` O(n)
2. `swap`: swap content (same type and size) O(n)

## Non-member overloads
1. `(a!=b) OR !(a==b)` O(n)
2. `(a<b) OR (a>b)` O(n)
3. `(a<=b) OR !(b<a)` O(n)
4. `(a>=b) OR !(a<b)` O(n)

## Non-member operations complexity
1. access: direct access `a[1] or a.at()` O(1)
2. append: direct append `a[2] = 8`: O(1)
3. insert: make space by scooting over (shifting) and append O(n)
4. delete: fill gap by scooting over (shifting) O(n)

## Passing the container to a function
Because the array is a fixed sized container, you cannot directly pass the
array. You have to create a template size_t.
```C++
template <typename T, std::size_t size>
void Print(const std::array<T>, size> &list) {
  for (auto a : list) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
}
```

## Dynamic Array
There are two problems with `int a[1000]`:
1. Exceeding maximum: choosing maximum is difficult and waste of memory if not utilized.
2. No Expansion: cant reallocate more memory if required.

So, we use dynamic arrays. This is done by declaring the array as a pointer.

```C++
int* list = NULL; // no memory is allocated yet 
list = new int[10]; // allocate memory to store 10 integers

// do something here

delete [] list; // when done free memory
list = NULL; // not required but good practice
```

Example:
```C++
int max = 10;           // no longer const
int* a = new int[max];  // allocated on heap
int n = 0;

//--- Read into the array
while (cin >> a[n]) {
    n++;
    if (n >= max) {
        max = max * 2;            // double the previous size
        int* temp = new int[max]; // create new bigger array.
        for (int i=0; i<n; i++) {
            temp[i] = a[i];       // copy values to new array.
        }
        delete [] a;              // free old array memory.
        a = temp;                 // now a points to new array.
    } // temp variable which stores the address to the array is cleared after it goes out of scope
}
//--- Write out the array etc.
```

### Amortized cost of appending
Say the array is initialized with size of n. So we append n elements to the array, total n operations. Now, to add more elements to the array, we would have to allocate new memory of larger size, say 2n. So, we allocate the memory to store 2n elements, copy the n elements from previous memory to new momory location, so n operations, summing up to 2n operations. Now, we start filling the remaining n spaces of the new memory. So, another n operations, totalling 3n operations to fill a 2n sized array.

So, the net or amortized time complexity of appending elements into dynamic array is (3n/2n = 1.5) = constant O(1).

### Moore's algorithm



