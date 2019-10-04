# Binary Algorithms
The programs are split into two parts. For main.cpp, inputting -1 ends the current Part.  
## C++ Part 1
Takes integer input and determines the ceil(sqrt(n)) in O(logn).  
## C++ Part 2
Takes integer input n and makes an array size n. Takes in n more inputs and sets the array to the input numbers. It then finds the smallest missing number in O(logn). Ex. [0,1,3,6] is missing 2.

---

## LUA Part 1
Takes in a string of 0s and 1s (ex. 000001111111) and find the position of the last 0 in O(logn) steps. Answer to example is 5.  
## LUA Part 2
Generates 2 sorted arrays of size 16 with random numbers ranging 0-1000. It returns the median of the array resulting from merging the 2 arrays in O(logn). The two arrays are never actually merged in the O(logn) algorithm. The answer is calculated again in O(nlogn) steps to show that first algorithm was indeed correct. Ex. [0,2,10,26,68] and [1,11,18,20,41], Answer: (11+18)/2 = 14.5 is the median if the two arrays were combined.
