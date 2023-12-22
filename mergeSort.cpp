#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){
    int n1 = mid-l+1;       //mid included
    int n2 = r-mid;         //after mid

    int a[n1];
    int b[n2];

    for (int i = 0; i< n1; i++){        //mid is added in a
        a[i] = arr[l+i];
    }
    for (int i = 0; i< n2; i++){        //b starts after mid
        b[i] = arr[mid+i+1];
    }

    int i =0;
    int j = 0;
    int k = l;
    while (i<n1 && j < n2){
        if (a[i] < b[j]){
            arr[k] = a[i];
            k++; i++;
        }else{
            arr[k] = b[j];
            k++; j++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        k++; i++;
    }
    while(j< n2){
        arr[k] = b[j];
            k++; j++;
    }

}
void mergeSort(int arr[],int l,int r){
    if(l < r){
        int mid = (l+r)/2 ;
        //recurrsively dividing array into half
        mergeSort(arr,l,mid);        
        mergeSort(arr,mid+1,r);
    
        //merging the divided arrays
        merge(arr,l,mid,r);
    }
}
int main(){
    int array[] = {5,4,3,2,1};    
    mergeSort(array,0,4);       //left and right indices of array
    cout << "\nSorted array elements: ";
    for(int i =0; i<5; i++){        
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}