#include<iostream>
using namespace std;

long long int sqrtX(int n){
    int lo=0,hi=n-1,ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid*mid==n) return mid;
        else if(mid*mid<n){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}

double morePrecision(int n,int precision,int tempSol){
    double factor=1;
    double ans=tempSol;
    
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
    int tempSol=sqrtX(n);
    cout<<"Ans is: "<<morePrecision(n,3,tempSol)<<endl;
}