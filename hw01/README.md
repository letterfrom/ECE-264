[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/p2JQtSlA)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19823851&assignment_repo_type=AssignmentRepo)
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/bak22dDf)
# Who Gets the Cake

Learning Goals 
==============

This assignment asks you to keep track of information using an array.

Rules
=====

Imagine that there is a piece of cake and several people want it.
They decide who can have it by playing a game: They form a circle and
choose an integer k greater than one. They count 1, 2, 3, ..., k. The
k-th person is eliminated.  They restart from 1 and count to k again
to eliminate the next person whose number is k.  They keep counting
until only one person is left. This person gets the cake.

Please notice that there are different definitions of this
problem. Your solution **must follow the definition here**.  More
precisely, this is how the method works: There are n people,
represented by n elements in an array. Please be aware that in C, an
array's index starts from 0. Thus, the indexes will be 0, 1, 2, ..., n
- 1.  The elements are counted as 1, 2, 3, ... When the value k is
counted, this element is removed in future counting and the next
element starts as 1 again. When reaching the end of the array, the
counting *wraps around* to the beginning of the array.  If an element
has already been eliminated, this element is skipped during counting.
Please notice that in C arrays, indexes *always* start at zero but in
this problem counting starts at one. Both n and k have to be greater
than one.  It is possible that k is greater than n.

The following is an example when the array has 6 (n is 6) elements and
k is 3.  The eliminated elements in each round are mared by `X`.  The
elements eliminated earlier are marked by `Y`.


array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 1 | 2 | X | 1 | 2 | X 

Go to the beginning. Since index 2 has already been eliminated, it is
skipped.  Index 3 is eliminated this time.


array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 1 | 2 | Y | X | 1 | Y 

Index 5 has already been eliminated and it is skipped.  Index 1 is eliminated this time.

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 2 | X | Y | Y | 1 | Y

Index 4 is eliminated this  time.

array index | 0 | 1 | 2 | 3 | 4 | 5
------------|---|---|---|---|---|---
count       | 2 | Y | Y | Y | X | Y

The element of index 0 is left.

This is another example. The array has 6 elements and k is 4.

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 1 | 2 | 3 | X | 1 | 2 

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 3 | X | 1 | Y | 2 | 3 

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | X | Y | 1 | Y | 2 | 3

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | Y | Y | X | Y | 1 | 2

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | Y | Y | Y | Y | 3 | X

The element of index 4 is left.

This is the third example. The array has 25 elements and k is 7.

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 1 | 2 | 3 | 4 | 5 | 6 | X | 1 | 2 | 3 | 4  | 5  | 6  | X  |  1 | 2  |  3 |  4 | 5  | 6  | X  |  1 | 2  |  3 |  4 


array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 5 | 6 | X | 1 | 2 | 3 | Y | 4 | 5 | 6 | X  |  1 | 2  | Y  |  3 | 4  | 5  | 6  |  X |  1 | Y  |  2 | 3  | 4  |  5

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 6 | X | Y | 1 | 2 | 3 | Y | 4 | 5 | 6 | Y  | X  | 1  | Y  | 2  | 3  | 4  | 5  |  Y |  6 | Y  |  X | 1  | 2  |  3

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 4 | Y | Y | 5 | 6 | X | Y | 1 | 2 | 3 | Y  | Y  | 4  | Y  | 5  | 6  | X  | 1  | Y  |  2 | Y  |  Y | 3  | 4  |  5

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 6 | Y | Y | X | 1 | Y | Y | 2 | 3 | 4 | Y  | Y  | 5  | Y  | 6  | X  | Y  | 1  | Y  |  2 | Y  |  Y | 3  | 4  |  5

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 6 | Y | Y | Y | X | Y | Y | 1 | 2 | 3 | Y  | Y  | 4  | Y  | 5  | Y  | Y  | 6  | Y  | X  | Y  |  Y | 1  | 2  |  3

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 4 | Y | Y | Y | Y | Y | Y | 5 | 6 | X | Y  | Y  | 1  | Y  | 2  | Y  | Y  | 3  | Y  | Y  | Y  |  Y | 4  | 5  |  6

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | X | Y | Y | Y | Y | Y | Y | 1 | 2 | Y | Y  | Y  | 3  | Y  | 4  | Y  | Y  | 5  | Y  | Y  | Y  |  Y | 6  | X  |  1

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 2 | 3 | Y | Y  | Y  | 4  | Y  | 5  | Y  | Y  | 6  | Y  | Y  | Y  |  Y | X  | Y  |  1

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 2 | 3 | Y | Y  | Y  | 4  | Y  | 5  | Y  | Y  | 6  | Y  | Y  | Y  |  Y | Y  | Y  |  X

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 1 | 2 | Y | Y  | Y  | 3  | Y  | 4  | Y  | Y  | 5  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 6 | X | Y | Y  | Y  | 1  | Y  | 2  | Y  | Y  | 3  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 4 | Y | Y | Y  | Y  | 5  | Y  | 6  | Y  | Y  | X  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 1 | Y | Y | Y  | Y  | 2  | Y  | 3  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 4 | Y | Y | Y  | Y  | 5  | Y  | 6  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | X | Y | Y | Y  | Y  | 1  | Y  | 2  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y  | Y  | 3  | Y  | 4  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y  | Y  | 5  | Y  | 6  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y  | Y  | X  | Y  | 6  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

The element of index 14 is left.

The table uses `X` and `Y` for clarity.  Your program may use only `X`.

What Do You Need to Do
======================

Write the `eliminate` function and print the index of the eliminated elements.

In the first example (n is 6 and k is 3), the output is
```
2
5
3
1
4
0
```

In the second example (n is 6 and k is 4), the output is

```
3
1
0
2
5
4
```

In the third example (n is 25 and k is 7), the output is

```
6
13
20
2
10
18
1
11
21
5
16
3
15
4
19
9
0
23
22
24
8
17
7
12
14
```

The function is called `eliminate`, not `select` because `select` is a
C function for network communication. If you want to know the
definition of the `select` function, search `Linux manual select`.


Submission
==========

```
zip hw01.zip eliminate.c
```

Upload hw01.zip to Gradescope

Additional Reading
==================

A mathematical question is to determine which element is left
*without* counting 1, 2, ...  If you are interested in this topic,
please read the book Concrete Mathematics by Ronald L. Graham, Donald
E. Knuth, and Oren Patashnik.

Is this a real problem? Is there any real application? Yes. In
distributed systems (such as the Internet), sometimes different
machines need to agree on something. For example, a group of machines
want to find one representative for external communication. It is
better to take turns as the representative. The process of finding a
representative can be achieved in methods similar to this one.


History
=======

This problem is inspired by the "Josephus problem".  History (based on
Wikipedia): Flavius Josephus and 40 soldiers were trapped in a cave by
Roman soldiers. They chose suicide over capture, and decided the order
is determined by the following method: they form a circle and set an
integer k greater than one.  Then, the group starts with 1, 2, ... The
person that counts k is eliminated.  The process continues until all
are eliminated.  The question is where Josephus should stand at the
beginning so that he is the last remaining person.  

