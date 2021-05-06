#include <iostream>
using namespace std;

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = { 0 }; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixsort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 

int main() {
  int T;
  cin >> T;

  while(T--){ //for every test case
    int n;
    int total_weight=0;
    cin >> n; //pork chops
    int porkchops[n];

    for(int i=0; i<n; i++){ //for each pork chops
      int w;
      cin >> w;
      porkchops[i] = w;
      total_weight = total_weight + w;
    }

    // Function Call to sort the array porkchops
    radixsort(porkchops, n);

    bool final_ans = false;
    for(int i=0; i<n; i++){
      int sum = 0;
      sum = sum + porkchops[i];
      if(sum==(total_weight/2)){
          final_ans = true;
      }
      for(int j=i+1; j<n; j++){
        sum = sum + porkchops[j];
        if(sum==(total_weight/2)){
          final_ans = true;
        }
        else if(sum > (total_weight/2)){
          break;
        }
      }
    }

    if(final_ans == 0)
      cout << "QAQ\n";
    else
      cout << "Yes\n";
  }
}

/*
2
4
3 5 1 7
4
2 10 4 2
*/