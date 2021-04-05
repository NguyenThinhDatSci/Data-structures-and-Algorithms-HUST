#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

// import 1 dimensional array

void inputArray(int* a, int n);

// display 1 dimensional array

void showArray(int* a, int n);

// Liner Search - return index

int linerSearch(int x, int n, int* a);

// swap 2 elements

void swap(int* a, int* b);

// swap fist min and last max

void swapFirstMinLastMax(int* a, int n);

// the number of the element have the value x - return amount

int numberOf_x_value(int* a, int n, int x);

// Binary Search - return index

int binarySearch(int* a, int n, int x);

// The fixed sum of a series of numbers is sum - return series of consecutive numbers

bool sumOfConsecutiveArrElements(int* a, int n, int sum);

// show array from top to end

void printFromTo(int* a, int top, int end);

// print elements is odd number and is at even index

void oddValueEvenIndex(int* a, int n);
