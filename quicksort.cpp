#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int low, int high) {
	int pivot = vec[high];
	int x = low-1;

	for(int i=low; i<high; i++) {
		if(vec[i] < pivot) {
			x++;
			swap(vec[x], vec[i]);
		}
	}

	swap(vec[high], vec[x+1]);
	return x+1;
}

void quickSort(vector<int> &vec, int low, int high) {
	if(low < high) {
		int p = partition(vec, low, high);

		quickSort(vec, low, p-1);
		quickSort(vec, p+1, high);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Array size : "; cin >> n;
	vector<int> vec(n);
	for(int i=0; i<n; i++) cin >> vec[i];

	quickSort(vec, 0, vec.size());

	for(int i=0; i<n; i++) cout << vec[i] << " ";

	return 0;
}



// int partition(int arr[], int low, int high)
// {
// 	int pivot = arr[high];
// 	int i = (low - 1); 

// 	for (int j = low; j < high; j++) {
// 		if (arr[j] < pivot) {
// 			i++; 
// 			swap(arr[i], arr[j]);
// 		}
// 	}
// 	swap(arr[i + 1], arr[high]);
// 	return (i + 1);
// }

// void quickSort(int arr[], int low, int high)
// {
// 	if (low < high) {
// 		int pi = partition(arr, low, high);

// 		quickSort(arr, low, pi - 1);
// 		quickSort(arr, pi + 1, high);
// 	}
// }


// int main()
// {
// 	int arr[] = { 10, 7, 8, 9, 1, 5 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	quickSort(arr, 0, n - 1);
// 	cout << "Sorted array: \n";
// 	for(int i=0; i<n; i++) cout << arr[i] << " ";
// 	return 0;
// }

