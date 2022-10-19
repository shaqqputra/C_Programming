#include <stdio.h>

int size;

void display(int arr[]){
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	puts("");
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	
	int i = low-1;
	
	for(int j = low; j < high; j++){
		printf("Index-J: %d\n", j);
			display(arr);
		if(arr[j] <= pivot){
			i++;
			printf("%d: %d < %d\n", j, arr[j], pivot);
			swap(&arr[j], &arr[i]);
			puts("");
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		//Step 1 -> cari pivot
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot + 1, high);
	}
}

int main(){
	
	int arr[] = {1,7,2,9,3,5,8};
	size = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, size - 1);
	display(arr);
	
	
	return 0;
}
