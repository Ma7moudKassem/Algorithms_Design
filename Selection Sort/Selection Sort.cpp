#include <iostream>
#include <vector>
using namespace std;

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

vector<int> selection_sort(vector<int> arr) // { 64, 25, 12, 22, 11 }
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
		}

		if (min_index != i)
			swap(arr[i], arr[min_index]);
	}
	return arr;
}

void print_array(vector<int> arr)
{
	int i;
	for (i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	vector<int> arr = { 64, 25, 12, 22, 11 };
	cout << "Sorted array: \n";
	print_array(selection_sort(arr));
	return 0;
}