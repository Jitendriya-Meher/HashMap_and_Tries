#include<iostream>
using namespace std;

#include<unordered_map>     // header file for unordered_map

int main(){
    // creation of unordered_map
    unordered_map< string, int> m ; 

    // insertion in unordered_map
    // here the map contain a pair value of string and int
    // so we can insert a pair value
    pair<string , int> p1 = make_pair("Audi", 101);
    m.insert(p1);

    pair<string, int> p2("BMW",789);
    m.insert(p2);

    m["RR"]=1234;

    // access to unordered_map
    cout<<"value at BMW is : "<< m.at("BMW") << endl;
    cout<<"value at Audi is : "<< m.at("Audi") << endl;
    // cout<<"value at audi is : "<< m.at("audi") << endl;
    // error -> compiler dependent error
    cout<<"value at RR is : "<< m["RR"] << endl<<endl;


    // search in unordered map
    // by count function
    cout<<" count of BMW is : "<<m.count("BMW")<<endl;
    // by find function
    if( m.find("BMW") != m.end()){
        cout<<"BMW is present in unordered map"<<endl;
    }else{
        cout<<"BMW is not present in unordered map"<<endl;
    }


    // size of unordered map
    cout<<endl<<"Size of unordered map is :"<<m.size()<<endl;
    cout<<"value of Mercidies is : "<<m["Mercidies"]<<endl;
    // it will create a entry in the unordered map even if to try to access the value if it is not present in the map
    cout<<"Size of unordered map is :"<<m.size()<<endl;


    // iteration in the unordered map
    cout<<endl<<" iteration in unordered map is : "<<endl;
    for( auto it : m){
        cout<<it.first<<" -> "<<it.second<<endl;
    }


    // remove a value from the unordered map
    m.erase("RR");

    cout<<endl<<" iteration in unordered map is : "<<endl;
    for( auto it : m){
        cout<<it.first<<" -> "<<it.second<<endl;
    }

    // delete the unordered map
    m.clear();

    cout<<endl<<" iteration in unordered map is : "<<endl;
    for( auto it : m){
        cout<<it.first<<" -> "<<it.second<<endl;
    }

}

