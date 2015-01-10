# Algorithms and data structures


##Overview

C++ library of algorithms and data structures focused on high performance. Might be useful in algorithmic competitions such as TopCoder or Sphere Online Judge. This is a header only library compatible with C++03 standard.


##Continuous integration status

[![Build Status](https://travis-ci.org/pawel-kieliszczyk/algorithms.svg)](https://travis-ci.org/pawel-kieliszczyk/algorithms)
[![Coverage Status](https://img.shields.io/coveralls/pawel-kieliszczyk/algorithms.svg)](https://coveralls.io/r/pawel-kieliszczyk/algorithms?branch=master)


##Features

 + STL-like containers
 + graph library


##Performance

The library focuses on high performance both minimizing computational complexity of all algorithms and maximizing possibility of efficient CPU caching.


###Data structures

All containers have fixed but custom maximum capacity. No memory reallocations once they are constructed.

| Member Function                          | Time Complexity | Space Complexity | Notes                                            |
|------------------------------------------|-----------------|------------------|--------------------------------------------------|
| vector::push_back                        | O(1)            | O(1)             |                                                  |
| vector::pop_back                         | O(1)            | O(1)             |                                                  |
| vector::operator[]                       | O(1)            | O(1)             |                                                  |
| vector::front                            | O(1)            | O(1)             |                                                  |
| vector::back                             | O(1)            | O(1)             |                                                  |
| vector::begin                            | O(1)            | O(1)             |                                                  |
| vector::cbegin                           | O(1)            | O(1)             |                                                  |
| vector::end                              | O(1)            | O(1)             |                                                  |
| vector::cend                             | O(1)            | O(1)             |                                                  |
| vector::reset                            | O(1)            | O(1)             |                                                  |
| vector::empty                            | O(1)            | O(1)             |                                                  |
| vector::size                             | O(1)            | O(1)             |                                                  |
| stack::push                              | O(1)            | O(1)             |                                                  |
| stack::pop                               | O(1)            | O(1)             |                                                  |
| stack::top                               | O(1)            | O(1)             |                                                  |
| stack::empty                             | O(1)            | O(1)             |                                                  |
| stack::size                              | O(1)            | O(1)             |                                                  |
| queue::push                              | O(1)            | O(1)             |                                                  |
| queue::pop                               | O(1)            | O(1)             |                                                  |
| queue::front                             | O(1)            | O(1)             |                                                  |
| queue::empty                             | O(1)            | O(1)             |                                                  |
| queue::size                              | O(1)            | O(1)             |                                                  |
| priority_queue::push                     | O(log(n))       | O(1)             |                                                  |
| priority_queue::pop                      | O(log(n))       | O(1)             |                                                  |
| priority_queue::top                      | O(1)            | O(1)             |                                                  |
| priority_queue::empty                    | O(1)            | O(1)             |                                                  |
| priority_queue::size                     | O(1)            | O(1)             |                                                  |
| cyclic_array::operator[]                 | O(1)            | O(1)             |                                                  |
| cyclic_array::shift_left                 | O(1)            | O(1)             |                                                  |
| cyclic_array::shift_right                | O(1)            | O(1)             |                                                  |
| disjoint_sets::union_sets                | O(m*a(m,n)      | O(1)             | m - number of operations, a - Ackermann function |
| disjoint_sets::get_set_id                | O(m*a(m,n)      | O(1)             | m - number of operations, a - Ackermann function |
| interval_tree::insert                    | O(log^d(n))     | O(1)             | d - number of dimensions                         |
| interval_tree::count                     | O(log^d(n))     | O(1)             | d - number of dimensions                         |
| binary_indexed_tree::increase            | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree::count_less_equal    | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree::count_in_range      | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree_2d::increase         | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree_2d::count_less_equal | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree_2d::count_in_range   | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree_3d::increase         | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree_3d::count_less_equal | O(log(n))       | O(1)             |                                                  |
| binary_indexed_tree_3d::count_in_range   | O(log(n))       | O(1)             |                                                  |
| binary_search_tree::insert               | O(n)            | O(1)             |                                                  |
| binary_search_tree::remove               | O(n)            | O(1)             |                                                  |
| binary_search_tree::exists               | O(n)            | O(1)             |                                                  |
| binary_search_tree::min                  | O(n)            | O(1)             |                                                  |
| binary_search_tree::max                  | O(n)            | O(1)             |                                                  |
| binary_search_tree::empty                | O(1)            | O(1)             |                                                  |
| binary_search_tree::size                 | O(1)            | O(1)             |                                                  |


###Algorithms

| Algorithm                                          | Time Complexity | Space Complexity | Notes |
|----------------------------------------------------|-----------------|------------------|-------|
| longest_monotonic_subsequence::strictly_decreasing | O(n*log(n))     | O(n)             |       |
| longest_monotonic_subsequence::strictly_increasing | O(n*log(n))     | O(n)             |       |
| longest_monotonic_subsequence::weakly_decreasing   | O(n*log(n))     | O(n)             |       |
| longest_monotonic_subsequence::weakly_increasing   | O(n*log(n))     | O(n)             |       |
| nth_fibonacci_number                               | O(log(n))       | O(1)             |       |
| prefix_function::run                               | O(n)            | O(1)             |       |
| prefix_function::get_prefix_suffix_table           | O(1)            | O(1)             |       |
| shortest_text_template::run                        | O(n)            | O(1)             |       |


###Graphs

Graph class has fixed but custom maximum amount of vertices and maximum vertex degree. No memory reallocations once it's constructed.

| Member Function                    | Time Complexity | Space Complexity | Notes                 |
|------------------------------------|-----------------|------------------|-----------------------|
| graph::add_directed_edge           | O(1)            | O(1)             |                       |
| graph::add_not_directed_edge       | O(1)            | O(1)             |                       |
| graph::get_adjacency_list          | O(1)            | O(1)             |                       |
| graph::reset                       | O(V)            | O(1)             |                       |
| graph::size                        | O(1)            | O(1)             |                       |
| depth_first_search::run            | O(V+E)          | O(V+E)           | Non-recursive version |
| breadth_first_search::run          | O(V+E)          | O(V)             | Non-recursive version |
| minimum_spanning_tree_kruskal::run | O(E*log(V))     | O(V+E)           |                       |
| minimum_spanning_tree_prim::run    | O(E*log(V))     | O(V+E)           | Will be improved soon |
| shortest_paths_dijkstra::run       | O(E*log(V))     | O(V)             |                       |
| shortest_paths_floyd_warshall::run | O(V^3)          | O(1)             |                       |
