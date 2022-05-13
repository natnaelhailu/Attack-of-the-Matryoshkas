# Attack of the Matryoshkas

<p align="center">
  <img src="https://user-images.githubusercontent.com/98181344/168383128-2ed8f136-0361-459a-8547-77e276a23055.png" width="100" />
</p>

## Description

Ah the Matryoshka, the toy that models recursion perfectly by having identical dolls within each doll of
smaller size until you reach the smallest doll that cannot be opened any further. The traditional doll
contains exactly one sub-doll within each doll which contains a sub-doll and etc. For this problem, there
can be cases where each sub-doll could contain 2 sub-dolls and the sum of the sizes of the two sub-dolls cannot
exceed the size of the doll that contains them. We can denote this as an augmented Matryoshka.

You will be given a set of lines from an input file that contains a single test case, you need to verify each
test case if it is a valid augmented Matryoshka or not. Every doll in the input is represented by (-k...k) (a
negative integer matching with its absolute value positive integer), and no dolls within -k to k can be larger
or contain two sub-dolls whose sum is larger than k. For example

```
-7 -5 -3 -2 2 3 5 7
```
Would be an example of a valid Matryoshka, the doll with size 7 contains a doll with size 5 which contains a
doll with size 3 that contains a doll with size 2 and the size 2 doll cannot be broken apart any further. And
each sub-doll's size is not larger than the doll that is contained within it. For the example below

```
-9 -7 -2 2 -3 -2 -1 1 2 3 7 9
```
The doll with size 9 contains a doll with size 7, the doll with size 7 contains a doll with size 2 and 3 (their
sum is 5 which is less than 7 thus this works), the doll with size 2 contains no sub-dolls while the doll with
size 3 contains a doll with size 2 which contains a doll with size 1 and that doll contains no more sub-dolls.
The next example shows an invalid case

```
-9 -7 -2 2 -3 -1 -2 2 1 3 7 9
```
The doll with size 9 contains a doll with size 7, that contains two dolls: one with size 2 and the other with
size 3 (their sum does not exceed 7), the doll with size 2 contains no sub-dolls, and the doll with size 3
contains a doll with size 1 that contains a doll with size 2 which would make this invalid since the a size 1
doll cannot contain a size 2 doll.

## Contents of main

In main, you need to prompt for an input file from which your program reads the test cases, each line is a
single test case with integers separated by a space, each line is terminated by an end of line. You may use a
vector of type `int` to store the numbers for each test case. You must then use a recursive function to verify
each doll/subdoll, you can use a loop to match a negative number with a positive one within the recursive
function. For each case output whether the input sequence is valid or invalid, refer to the sample output.

## Specifications

- Comment your code and functions
- You must have a recursive function to verify if each test case (augmented matryoshka doll) is valid

## Sample Run

```
$ g++ aotm.cpp
$ ./a.out

Enter filename: file.txt
Enter filename: data.dat
Enter filename: DollInput.txt

:-) matryoshka!
:-( Try again.
:-( Try again.
:-) matryoshka!
:-( Try again.
:-) matryoshka!
:-( Try again.
:-) matryoshka!
:-( Try again.
```
## References

- Link to the top image can be found at https://pngimg.com/image/49502
