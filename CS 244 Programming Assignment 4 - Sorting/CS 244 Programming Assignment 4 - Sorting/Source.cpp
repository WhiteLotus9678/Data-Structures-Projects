/*
-----------------------
William Yang
CS-244 Data Structures
Secion-001
Instructor: Mark
Programming Assignment 4
12/12/16
-----------------------
*/
#include <iostream>
#include <ctime>
#include "Sorting.h"

clock_t startTime, endTime;

using namespace std;

template <class T>
void sorting<T>::swap(int list[], int first, int last)
{	
	int temp = list[first];
	list[first] = list[last];
	list[last] = temp;
}

template <class T>
void sorting<T>::initializeArray(int list[], int size)
{
	for (int i = 0; i < size; i++)
	{
		list[i] = (rand() + time(0)) % size;
	}
}

template <class T>
void sorting<T>::insertionSort(int list[], int size)
{
	int firstOutOfOrder, temp;

	for (int i = 0; i <= size; i++)
	{
		firstOutOfOrder = i;
		while (firstOutOfOrder > 0 && list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			temp = list[firstOutOfOrder];
			list[firstOutOfOrder] = list[firstOutOfOrder - 1];
			list[firstOutOfOrder - 1] = temp;
			firstOutOfOrder--;
		}
	}
}

//----------A----------

//Partition Function
template <class T>
int sorting<T>::partitionA(int list[], int first, int last)
{
	int mid = (first + last) / 2;
	int pivot = list[mid];
	swap(list, first, mid);
	int smallIndex = first;
	for (int index = first + 1; index <= last; index++)
	{
		if (list[index] < pivot)
		{
			smallIndex++;
			swap(list, smallIndex, index);
		}
	}
	swap(list, first, smallIndex);
	return smallIndex;
}

//Recursive Quick Sorting Algorithm
template <class T>
void sorting<T>::recQuickSortA(int list[], int first, int last)
{
	if (first < last)
	{
		int pivot = partitionA(list, first, last);
		recQuickSortA(list, first, pivot - 1);
		recQuickSortA(list, pivot + 1, last);
	}
}

//----------B----------

//Partition Function
template <class T>
int sorting<T>::partitionB(int list[], int first, int last)
{
	int median = 0;
	int mid = (first + last) / 2;

	//Finding the median
	//If first is larger than mid and less than last
	if (list[first] > list[mid] && list[first] < list[last])
	{
		median = first;
	}
	//If first is larger than last and less than mid
	else if (list[first] < list[mid] && list[first] > list[last])
	{
		median = first;
	}
	//If mid is larger than first and less than last
	else if (list[mid] > list[first] && list[mid] < list[last])
	{
		median = mid;
	}
	//If mid is larger than last and less than first
	else if (list[mid] < list[first] && list[mid] > list[last])
	{
		median = mid;
	}
	//If last is larger than mid and less than first
	else if (list[last] > list[mid] && list[last] < list[first])
	{
		median = last;
	}
	//If last is larger than mid and less than first
	else if (list[last] < list[mid] && list[last] > list[first])
	{
		median = last;
	}
	//If two values are equal to each other but first is less than both
	else if (list[first] < list[mid] && list[mid] == list[last])
	{
		median = first;
	}
	//If two values are equal to each other but first is more than both
	else if (list[first] > list[mid] && list[mid] == list[last])
	{
		median = mid;
	}
	//If two values are equal to each other but mid is less than both
	else if (list[mid] < list[first] && list[first] == list[last])
	{
		median = mid;
	}
	//If two values are equal to each other but mid is more than both
	else if (list[mid] > list[first] && list[first] == list[last])
	{
		median = first;
	}
	//If two values are equal to each other but last is less than both
	else if (list[last] < list[first] && list[first] == list[mid])
	{
		median = last;
	}
	//If two values are equal to each other but last is more than both
	else if (list[last] > list[first] && list[first] == list[mid])
	{
		median = first;
	}
	//If all of the values are equal to each other
	else if (list[last] == list[mid] && list[last] == list[first] && list[first] == list[mid])
	{
		median = first;
	}

	int pivot = list[median];
	swap(list, first, median);
	int smallIndex = first;
	for (int index = first + 1; index <= last; index++)
	{
		if (list[index] < pivot)
		{
			smallIndex++;
			swap(list, smallIndex, index);
		}
	}
	swap(list, first, smallIndex);
	return smallIndex;
}

//Recursive Quick Sorting Algorithm
template <class T>
void sorting<T>::recQuickSortB(int list[], int first, int last)
{
	if (first < last)
	{
		int pivot = partitionB(list, first, last);
		recQuickSortB(list, first, pivot - 1);
		recQuickSortB(list, pivot + 1, last);
	}
}

//-----------C----------

//Recursive Quick Sorting Algorithm
template <class T>
void sorting<T>::recQuickSortC(int list[], int first, int last)
{
	if (last < 20)
	{
		insertionSort(list, last);
	}
	else if (first < last)
	{
		int pivot = partitionB(list, first, last);
		recQuickSortC(list, first, pivot - 1);
		recQuickSortC(list, pivot + 1, last);
	}
}

//-----------D----------

//Recursive Quick Sorting Algorithm
template <class T>
void sorting<T>::recQuickSortD(int list[], int first, int last)
{
	if (last < 20)
	{
		insertionSort(list, last);
	}
	else if (first < last)
	{
		int pivot = partitionB(list, first, last);
		recQuickSortD(list, first, pivot - 1);
		recQuickSortD(list, pivot + 1, last);
	}
}

int main()
{
	srand(time(NULL)); //A new seed is generated
	
	const int size = 5000000;
	int *List = new int[size];

	sorting<int> list;

	list.initializeArray(List, size);

	// 1 - Sort array using the middle element of the array as the pivot

	startTime = clock(); //startTime starts keeping track of the time the upcoming functions take to run

	list.recQuickSortA(List, 0, size - 1);

	endTime = clock(); //endTime stops keeping track of the time and holds its quantity

	cout << "Quick sort time with pivot middle element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

	// 2 - Sort array using the median of the first, middle and last elements

	startTime = clock();

	list.recQuickSortB(List, 0, size - 1);

	endTime = clock();

	cout << "Quick sort time with pivot median element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

	// 3 - Sort array using the middle element of the array as the pivot
	//	   However, when the size of the subarrays reduces to less than 20
	//	   Use insertion Sort

	startTime = clock();

	list.recQuickSortC(List, 0, size - 1);

	endTime = clock();

	cout << "Quick sort time and insertion sort time, with pivot middle element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

	// 4 - Sort array using the the median of the first, middle and last elements
	//	   However, when the size of the subarrays reduces to less than 20
	//	   Use insertion Sort

	startTime = clock();

	list.recQuickSortD(List, 0, size - 1);

	endTime = clock();

	cout << "Quick sort time and insertion sort time, with pivot median element: " << (endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;

	delete List;

	system("pause");

	return 0;

}