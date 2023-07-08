# Heap 3

Implement a max/min heap and the following operations:

- **+ v** (add a number v to the heap)
- **-** (remove the maximum from the max heap or the minimum from the min heap and write it on the screen)
- **p** (write all elements of the heap in the order in which they are stored in an array)
- **r n v1 ... vn** (remove all elements from the heap and create a heap out of n new elements with the values given by v1 ... vn)
- **s** (change the orientation of the heap from max to min or from min to max; the s operation can be requested multiple times)
- **q** (exit the program)

Additional remarks:

- Operation 'r' is not the same as a sequence of '+' operations.
- If both children are equal, the child with the lesser index is swapped.
- Using the `std::vector` class in your solution will result in a reduction of score by 20%.

## Tests

- One test only contains operations: '+' and 'p' (Test 8).
- Some tests only contain operations: '+', 'p', and '-' (Tests 2 and 3).
- Some tests only contain operations: '+', 'p', 'r', and '-' (Tests 4 and 5).

## Input

A sequence of instructions in the format presented above. The last instruction is 'q'.

## Output

The results of instructions '-' and 'p'.


## Compilation and Execution

To compile the program, follow these steps:

1. Use a C++ compiler (such as g++) to compile the code:

   ```shell
   g++ -o Heap3 Heap3.cpp
   ```

2. Run the program using the following command:

   ```shell
   ./Heap3
   ```

   The program will start running and wait for user input.


## Example

Input:
```
+ 1
+ 2
+ 3
+ 4
+ 5
+ 6
+ 7
+ 8
p
-
-
-
-
-
-
-
-
p
r 8 1 2 3 4 5 6 7 8
p
-
-
-
-
-
-
-
-
p
r 8 1 2 3 4 5 6 7 8
s
p
-
-
-
-
-
-
-
-
p
q
```

Output:
```
8 7 6 4 3 2 5 1
8
7
6
5
4
3
2
1

8 5 7 4 1 6 3 2
8
7
6
5
4
3
2
1

1 2 3 4 5 6 7 8
1
2
3
4
5
6
7
8
```

**Note:** The output represents the elements of the heap after each operation. The 'p' operation outputs all the elements in the order they are stored in the heap. The '-' operation outputs the removed element (maximum from the max heap or minimum from the min heap).



