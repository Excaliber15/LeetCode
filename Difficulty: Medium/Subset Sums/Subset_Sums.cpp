// Subset Sums

#include<iostream>
#include<vector>
using namespace std;

void printAllSums(vector<int>&arr,int sum,int i,vector<int>&ans){
    // base case
    if(i>=arr.size()){
        ans.push_back(sum);
        return;
    }
    // include ans
    printAllSums(arr,sum+arr[i],i+1,ans);
    // exclude ans
    printAllSums(arr,sum,i+1,ans);
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    int index=0;
    vector<int>ans;
    printAllSums(arr,sum,index,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    cout<<"Size is: "<<ans.size()<<endl;
}