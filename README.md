# Sorting algorithms

Emplementation of different sorting algorithm

Data Structure and Functions

print_array.c: C function that prints an array of integers
print_list.c: C function that prints a listint_t doubly-linked list.

Tasks

0. Bubble sort

0-bubble_sort.c: C function that sorts an array of integers in ascending order using the Bubble Sort algorithm.

1. Insertion sort

1-insertion_sort_list.c: C function that sorts a listint_t doubly-linked list of integers in ascending order using the Insertion Sort algorithm.
Prints the list after each swap.
1-O: Text file containing the best, average, and worst case time complexities of the Insertion Sort algorithm, one per line

2. a function that sorts an array of integers in ascending order using the Selection sort algorithm

a function that sorts an array of integers in ascending order using the Selection sort algorithm

Prototype: void selection_sort(int *array, size_t size);
You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 2-O, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case

3 a function that sorts an array of integers in ascending order using the Quick sort algorithm

Prototype: void quick_sort(int *array, size_t size);
You must implement the Lomuto partition scheme.
The pivot should always be the last element of the partition being sorted.
You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 3-O, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
3 a function that sorts an array of integers in ascending order using the Quick sort algorithm

Prototype: void quick_sort(int *array, size_t size);
You must implement the Lomuto partition scheme.
The pivot should always be the last element of the partition being sorted.
You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 3-O, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
3 a function that sorts an array of integers in ascending order using the Quick sort algorithm

Prototype: void quick_sort(int *array, size_t size);
You must implement the Lomuto partition scheme.
The pivot should always be the last element of the partition being sorted.
You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 3-O, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst casie



4.  Shell sort - Knuth Sequence

a function that sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence

Prototype: void shell_sort(int *array, size_t size);
You must use the following sequence of intervals (a.k.a the Knuth sequence):
n+1 = n * 3 + 1
1, 4, 13, 40, 121, ...
You’re expected to print the array each time you decrease the interval (See example below).
