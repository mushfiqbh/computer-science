#include<bits/stdc++.h>  // Including all standard libraries
using namespace std;

int arr[] = {8,5,4,7,2,1,10};  // Input array to be sorted
int temp[6];  // Temporary array for merging

// Function to merge two sorted subarrays
void Merge(int L, int Mid, int H) {
    int i = L;       // Starting index of left subarray
    int j = Mid + 1; // Starting index of right subarray
    int k = L;       // Index for temporary array

    // Merging both subarrays in sorted order
    while(i <= Mid && j <= H) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copying remaining elements of right subarray (if any)
    for(j; j <= H; j++) {
        temp[k] = arr[j];
        k++;
    }

    // Copying remaining elements of left subarray (if any)
    for(i; i <= Mid; i++) {
        temp[k] = arr[i];
        k++;
    }

    // Copying merged elements back to original array
    for(int m = L; m <= H; m++) {
        arr[m] = temp[m];
    }
}

// Recursive function to implement Merge Sort
void Mergesort(int L, int H) {
    if(L < H) {
        int Mid = (L + H) / 2;  // Finding the middle index
        Mergesort(L, Mid);      // Sorting the left half
        Mergesort(Mid + 1, H);  // Sorting the right half
        Merge(L, Mid, H);       // Merging the sorted halves
    }
}

int main() {
    Mergesort(0, 6);  // Sorting the entire array

    // Printing the sorted array
    for(int i = 0; i <= 6; i++) 
        cout << temp[i] << " ";

    return 0;
}


