#include<iostream>

using namespace std;

void merge(int arr[], int sorted[], int left, int mid, int right){
    int i,j,k,l;
    i = left;
    j = mid + 1;
    k = left;

    while(i<=mid && j<=right){
        if(arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if(i>mid){
        for(l=j; l<=right; l++)
            sorted[k++] = arr[l];
    }
    else{
        for(l=i; l<=mid; l++)
            sorted[k++] = arr[l];
    }

    for(l=left; l<=right; l++){
        arr[l] = sorted[l];
    }
}

void mergeSort(int arr[], int sorted[], int left, int right){
    int mid;

    if(left<right){
        mid = (left + right) / 2;
        mergeSort(arr, sorted, left, mid);
        mergeSort(arr, sorted, mid + 1, right);
        merge(arr, sorted, left, mid, right);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, i=0;
    int arr[1000001];
    int sorted[1000001];

    cin >> n;
    while(i<n)
        cin >> arr[i++];
    
    mergeSort(arr, sorted, 0, n-1);
    
    i = 0;
    while(i<n)
        cout << arr[i++] << '\n';

    return 0;
}