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

###vector

Fixed but custom maximum capacity. No memory reallocations once constructed.

| Member Function | Time Complexity |
|-----------------|-----------------|
| push_back       | O(1)            |
| pop_back        | O(1)            |
| operator[]      | O(1)            |
| front           | O(1)            |
| back            | O(1)            |
| begin           | O(1)            |
| cbegin          | O(1)            |
| end             | O(1)            |
| cend            | O(1)            |
| empty           | O(1)            |
| size            | O(1)            |

###stack

Fixed but custom maximum capacity. No memory reallocations once constructed.

| Member Function | Time Complexity |
|-----------------|-----------------|
| push            | O(1)            |
| pop             | O(1)            |
| top             | O(1)            |
| empty           | O(1)            |
| size            | O(1)            |

###queue

Fixed but custom maximum capacity. No memory reallocations once constructed.

| Member Function | Time Complexity |
|-----------------|-----------------|
| push            | O(1)            |
| pop             | O(1)            |
| front           | O(1)            |
| empty           | O(1)            |
| size            | O(1)            |

###graph

Fixed but custom maximum amount of vertices and maximum vertex degree. No memory reallocations once constructed.

| Member Function       | Time Complexity |
|-----------------------|-----------------|
| add_directed_edge     | O(1)            |
| add_not_directed_edge | O(1)            |
| get_adjacency_list    | O(1)            |
| size                  | O(1)            |

###depth_first_search

Recursive version.

| Member Function | Time Complexity | Space Complexity |
|-----------------|-----------------|------------------|
| run             | O(E)            | O(V)             |
