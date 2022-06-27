STL provides standard library for most useful entities in c++. The main components are:
1. **Containers**: vector, stacks, queues, ...
2. **Algorithms**: sort, reverse, accumulate ... 
3. **Iterators**: access elements inside containers

### Types of containers: 
1. **Sequence containers**: `array`, `vector`, `list`, `forward_list`, `deque`
2. **Associative containers**: `set` (and multiset), `map`(and multimap)
3. **Unordered Associative containers**: `unordered_set` (and unordered_multiset), `unordered_map`(and unordered_multimap)
4. **Container Adapters**: stack, queue, priority queue

Note: Adapters dont support the STL algorithms

### Types of Iterators:
1. **Input Iterator**: from the container to the program
2. **Output Iterator**: from the program to the container
3. **Forward Iterator**: navigate one item at a time in one direction
4. **Bi-directional iterators**: navigate one item at a time both directions
5. **Random Access iterators**: directly access a container item 

### Algorithms
There are around 60 algorithms in two categories:
1. **Modifying**: algorithms that modify containers. E.g. sort
2. **Non-Modifying**: algorithms that don't modify containers. E.g. accumulate


[[Home]](https://github.com/sapan-ostic/programming/wiki) [[Next: Generic Programming]](https://github.com/sapan-ostic/programming/wiki/STL:-Generic-Programming)