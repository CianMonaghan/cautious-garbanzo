#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

int main(int argc, char *argv[])
{
	Employee A[MAX_EMPLOYEES];

	for(int i=0; i<MAX_EMPLOYEES; i++){
		scanf("%s", A[i].name);
		scanf("%d", &A[i].salary);
	}

	for (int i=0; i<MAX_EMPLOYEES; i++){
		printf("Name: %s\n", A[i].name);
		printf("Salary: %d\n", A[i].salary);
		printf("\n");
	}

	heapSort(A, MAX_EMPLOYEES);
	printList(A, MAX_EMPLOYEES); //now sorted list
	
	return 0;
}
