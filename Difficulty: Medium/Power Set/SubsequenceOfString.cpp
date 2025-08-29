// Subsequences of a String

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printAllSubsequences(string str,int i,string output,vector<string>&ans){
    // base case
    if(i>=str.length()){
        ans.push_back(output);
        return;
    }
    char ch=str[i];
    // include ans
    printAllSubsequences(str,i+1,output+ch,ans);
    // exclude ans
    printAllSubsequences(str,i+1,output,ans);
}
int main(){
    string str;
    cout<<"Enter the String: ";
    cin>>str;
    string output="";
    int index=0;
    vector<string>ans;
    printAllSubsequences(str,index,output,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    cout<<"Number of Subsequences: "<<ans.size()<<endl;
}