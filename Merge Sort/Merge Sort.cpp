#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;

	int* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0,
		indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

			indexOfSubArrayOne++;
		}
		else
		{
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne)
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo)
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];

		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int array[], int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

int main()
{
	int arr[] = { 3,4,5,6,1,2,7 };
	mergeSort(arr, 0, 6);

	for (int i = 0; i < 7; i++)
		cout << arr[i];
}