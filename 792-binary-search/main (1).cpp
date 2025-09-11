
// Exponential Search Algorithm

#include<iostream>
using namespace std;

int binarySearch(int arr[],int lo,int hi,int target){
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) lo=mid+1;
        else hi=mid-1; // arr[mid]>target
    }
    return -1;
}

int ExpoSearch(int arr[],int n,int target){
    if(arr[0]==target) return 0;
    int i=1;
    while(i<n && arr[i]<=target){
        i*=2;
    }
    return binarySearch(arr,i/2,min(i,n-1),target);
}
int main(){
    int arr[]={2,3,5,9,19,35,39,45,48,60,70,101,110,120,150,187,200,201,210,237};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=120;
    int ans=ExpoSearch(arr,n,target);
    cout<<"Ans at index: "<<ans<<endl;
}