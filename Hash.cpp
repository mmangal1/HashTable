#include "Hash.h"
#include <iostream>

using namespace std;

Hash::Hash(unsigned int size){
	table.resize(size);
}

bool Hash::insert(string key, string value){

	int original = hasher(key);
	int current = original;
	
	while(table.at(current).first != ""){
		if(current == table.size()-1){
			current = 0;
		}else{
			current++;
		}
		if(current == original){
			return false;
		}
	}

	table.at(current) = make_pair(key, value);
	return true;
}

string Hash::find(string key){
	int original = hasher(key);
	int current = original;

	while(table.at(current).first != key){
		if(current == table.size()-1){
			current = 0;
		}else{
			current++;
		}
		if(current == original){
			return "";
		}
	}
	return table.at(current).second;
		
}

bool Hash::remove(string key){
	
	int original = hasher(key);
	int current = original;

	while(table.at(current).first != key){
		if(current == table.size()-1){
			current = 0;
		}else{
			current++;
		}
		if(current == original){
			return false;
		}
	}

//	vector<pair<string, string>>::iterator it = table.begin();	
//	table.erase(it+current);
	table.at(current) = make_pair("", "");
	return true;
}

int Hash::size(){
	return table.size();
}

bool Hash::empty(){
//	if(table.size() == 0)
//		return true;
//	return false;
	
	for(int x = 0; x < table.size(); x++){
		if(table.at(x).first != "")
			return false;
	}
	return true;
}
void Hash::printHash(){
	cout <<" ========== Hash Table =========== "<< endl; 
	for(int x = 0; x < table.size(); x++){
		printf("Index: %-15d \t Key: %-15s \t Value: %-15s \n", x, table.at(x).first.c_str(), table.at(x).second.c_str());
	}
}

int Hash::hasher(string key){

	int hash = 0;
	int index;

	for(int x = 0; x < key.length(); x++){
		hash += (int)key[x];
	}
	
	index = hash % (table.size());
	return index;
}

