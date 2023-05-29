#include<iostream>
using namespace std;

#include<unordered_map>

int main(){
    
    string s;
    cout<<" s : ";
    cin>>s;

    unordered_map<char ,int> cnt;

    // traverse the string a increase the freq of each character
    for( auto ch : s){
        cnt[ch]++;
    }

    // printng the frequencies of character
    for( auto it : cnt){
        cout<<it.first<<" "<<it.second<<endl;
    }
}