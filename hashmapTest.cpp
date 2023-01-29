#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<map>
using namespace std;

void inputKeys(map<string,int>&mp, int n){
    cout<<"Enter the Keys"<<endl;
    for(int i = 0; i<n; i++){
        string str;
        cin>>str;
        mp[str]++;
    }
}

bool compare(pair<string,int> &mp1, pair<string,int> &mp2){
    return mp1.first > mp2.first;
}

void sorter(vector<pair<string,int>> &lis){
    int n = lis.size();
    for(int i = 1; i<n; i++){
        pair<string,int>key = lis[i];
        
        int j = i - 1;
        while(j>=0 && compare(lis[j], key)){
            lis[j+1] = lis[j];
            j = j - 1;
        }
        lis[j + 1] = key;
        
    }
}

void printResult(vector<pair<string,int>> &result){
    for(auto i: result){
        cout << i.first << " " << i.second << endl; 
    }
}


// void outputValues(map<string,int>&mp, int n){
//     for (auto i : mp) {
//         cout << '\t' << i.first << '\t' << i.second << '\n';
//     }
// }

void printList(vector<map<string,int>> &l){
    for (auto & map : l ) { 
    for (auto & i : map) { 
        cout << i.first << " " << i.second << endl; 
    } 
} 
}


int main(){
    int n;
    cout<<"Enter the number of elements in map:"<<endl;
    cin>>n;
    map<string,int> mp1, mp2, mp3;
    vector<map<string,int>> mapsList;
    vector<pair<string,int>>temp;
    inputKeys(mp1,n);
    inputKeys(mp2,n);
    inputKeys(mp3,n);
    mapsList.push_back(mp1);
    mapsList.push_back(mp2);
    mapsList.push_back(mp3);
    cout<<"List formed :"<<endl;
    printList(mapsList);

    for(auto & map:mapsList){
        
        for(auto & i : map){
            temp.push_back(i);
        } 
    }

    sorter(temp);


    cout<<"Sorted List :"<<endl;
    printResult(temp);

    // outputValues(mp1,n);
    // outputValues(mp2,n);
    // outputValues(mp3,n);
}