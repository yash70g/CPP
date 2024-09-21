#include<iostream>
#include<vector>
using namespace std;
void selectsort(vector<int> a){
   int n=a.size();
   for(int i=0;i<n-1;i++){
    int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            int t=a[min];
            a[min]=a[j];
            a[j]=t;
        }
       }}
       void bubble(vector<int> a){
        int n=a.size();
        int count=0;
        while(count<n){
            int r=0;
            for(int i=0;i<n-count;i++){
                if(a[i]>a[i+1]){
                    r=1;
                    int t=a[i];
                    a[i]=a[i+1];
                    a[i+1]=t;
                    }
            }
            if(r==0)
            break;
            count++;
        }
       }
    void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    }
    void mergesort(vector<int> a,int low,int high){
        if(low<=high){
            return ;}
               int mid=(low+high)/2;
               mergesort(a,low,mid);
               mergesort(a,mid+1,high);
        }