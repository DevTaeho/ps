#include <iostream>

using namespace std;

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int l, int r) {
	int pivot = arr[l];

	int i = l + 1, j = r;
	while (i <= j) {
		while (arr[i] <= pivot) i++;
		while (arr[j] > pivot) j--;
		if (i < j) swap(arr[i], arr[j]);
	}

	swap(arr[l], arr[j]);
	return j;
}

void quickSort(int *arr, int left, int right) {
	if (left < right) {
		int s = partition(arr, left, right);
		quickSort(arr, left, s - 1);
		quickSort(arr, s + 1, right);
	}
}

void print_array(int *arr, int size){
  for(int i = 0; i < size; i++){
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

int main() {
	int N, *arr;
	cin >> N;

	arr = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << "Before Sorting...\n";
	print_array(arr, N);

	quickSort(arr, 0, N - 1);

	cout << "After Sorting...\n";
	print_array(arr, N);

	return 0;
}
