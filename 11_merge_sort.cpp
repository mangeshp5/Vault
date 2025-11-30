#include <iostream>
using namespace std;

// Merge two sorted halves
void merge(int books[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data
    for(int i=0; i<n1; i++) L[i] = books[left + i];
    for(int i=0; i<n2; i++) R[i] = books[mid + 1 + i];

    int i=0, j=0, k=left;

    // Merge sorted arrays
    while(i<n1 && j<n2) {
        if(L[i] < R[j]) books[k++] = L[i++];
        else books[k++] = R[j++];
    }

    // copy remaining
    while(i<n1) books[k++] = L[i++];
    while(j<n2) books[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int books[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(books, left, mid);        // left half
        mergeSort(books, mid + 1, right);   // right half
        merge(books, left, mid, right);     // merge
    }
}

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    int books[n];
    cout << "Enter book IDs:\n";
    for(int i=0;i<n;i++) cin >> books[i];

    mergeSort(books, 0, n-1);

    cout << "\nBooks arranged by robot (sorted IDs):\n";
    for(int i=0;i<n;i++) cout << books[i] << " ";

    return 0;
}
