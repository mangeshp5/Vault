#include <iostream>
using namespace std;

// Quick Sort function to sort room prices
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element taken as pivot
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int main() {
    int n;

    cout << "Enter number of rooms: ";
    cin >> n;

    int price[n];
    cout << "Enter room prices:\n";
    for(int i=0;i<n;i++)
        cin >> price[i];

    // sorting using quick sort
    quickSort(price, 0, n-1);

    cout << "\nSorted room prices: ";
    for(int i=0;i<n;i++)
        cout << price[i] << " ";
}
