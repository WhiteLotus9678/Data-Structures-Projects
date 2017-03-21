#pragma once
#ifndef SORTING_H
#define SORTING_H

template <class T>
class sorting
{
public:

	//Swap Function
	void swap(int list[], int first, int last);

	//Initializing an Array with Random Integers
	//Generates an array based on the variable size
	void initializeArray(int list[], int size);

	//Insertion Sort Algorithm
	void insertionSort(int list[], int size);

	//Partitioning Algorithm for Middle Element
	int partitionA(int list[], int first, int last);

	//Quick Sort Algorithm for for Middle Element
	void recQuickSortA(int list[], int first, int last);

	//Partitioning Algorithm for Median Element
	int partitionB(int list[], int first, int last);

	//Quick Sort Algorithm for for Median Element
	void recQuickSortB(int list[], int first, int last);

	//Quick Sort Algorithm for for Middle Element and Insertion Sort
	void recQuickSortC(int list[], int first, int last);

	//Quick Sort Algorithm for for Median Element and Insertion Sort
	void recQuickSortD(int list[], int first, int last);
};

#endif