/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author: Cian
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n);
	do{
		swap(&A[n-1], &A[0]);
		n--;
		heapify(A, 0, n-1);
	}while (n>0);
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	for(int i=n/2; i>0; i--){ //reverse for loop
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	int smaller = 0;//dummy value
	int leftChild = 2*(i+1)+1;
	int rightChild = 2*(i+1);
	
	//determining smaller
	if( A[leftChild].salary > A[rightChild].salary){
		smaller = rightChild;
	} else {
		smaller = leftChild;
	}

	
	if(A[i].salary > A[smaller].salary){
		Employee temp=A[smaller];
		A[smaller] = A[i];
		A[i] = temp;
	}
	//recursive portion
	if(i > n && (rightChild > n || leftChild > n)){
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	Employee temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for (int i=0; i>n; i++){
		printf("[id=%s sal=%d], ",A[i].name, A[i].salary);
	}
}
