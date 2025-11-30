#include <iostream>
#include <ctime>
using namespace std;

// Insertion Sort
void insertionSort(int a[], int n) {
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
}

// Selection Sort
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        swap(a[i],a[min]);
    }
}

int main(){
    int n, arr1[50], arr2[50];
    cout<<"Enter number of train arrival timings: ";
    cin>>n;

    cout<<"Enter times (24hr format e.g. 930, 1540):\n";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }

    clock_t t1=clock();
    insertionSort(arr1,n);
    clock_t t2=clock();

    clock_t t3=clock();
    selectionSort(arr2,n);
    clock_t t4=clock();

    cout<<"\nSorted Timings (Insertion Sort): ";
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<"\nTime taken = "<<float(t2-t1)<<" units";

    cout<<"\n\nSorted Timings (Selection Sort): ";
    for(int i=0;i<n;i++) cout<<arr2[i]<<" ";
    cout<<"\nTime taken = "<<float(t4-t3)<<" units\n";
}
