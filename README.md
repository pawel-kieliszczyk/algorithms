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


###Containers

All containers have fixed but custom maximum capacity. No memory reallocations once they are constructed.

| Member Function    | Time Complexity | Space Complexity |
|--------------------|-----------------|------------------|
| vector::push_back  | O(1)            | O(1)             |
| vector::pop_back   | O(1)            | O(1)             |
| vector::operator[] | O(1)            | O(1)             |
| vector::front      | O(1)            | O(1)             |
| vector::back       | O(1)            | O(1)             |
| vector::begin      | O(1)            | O(1)             |
| vector::cbegin     | O(1)            | O(1)             |
| vector::end        | O(1)            | O(1)             |
| vector::cend       | O(1)            | O(1)             |
| vector::reset      | O(1)            | O(1)             |
| vector::empty      | O(1)            | O(1)             |
| vector::size       | O(1)            | O(1)             |
| stack::push        | O(1)            | O(1)             |
| stack::pop         | O(1)            | O(1)             |
| stack::top         | O(1)            | O(1)             |
| stack::empty       | O(1)            | O(1)             |
| stack::size        | O(1)            | O(1)             |
| queue::push        | O(1)            | O(1)             |
| queue::pop         | O(1)            | O(1)             |
| queue::front       | O(1)            | O(1)             |
| queue::empty       | O(1)            | O(1)             |
| queue::size        | O(1)            | O(1)             |


###Graphs

Graph class has fixed but custom maximum amount of vertices and maximum vertex degree. No memory reallocations once it's constructed.

| Member Function              | Time Complexity | Space Complexity | Notes                 |
|------------------------------|-----------------|------------------|-----------------------|
| graph::add_directed_edge     | O(1)            | O(1)             |                       |
| graph::add_not_directed_edge | O(1)            | O(1)             |                       |
| graph::get_adjacency_list    | O(1)            | O(1)             |                       |
| graph::reset                 | O(V)            | O(1)             |                       |
| graph::size                  | O(1)            | O(1)             |                       |
| depth_first_search::run      | O(V + E)        | O(V)             | Recursive version     |
| breadth_first_search::run    | O(V + E)        | O(V)             | Non-recursive version |
