#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>

using namespace std; 


/*

	Given an input string , write an efficient program that returns 
	the run length encoded string for the input string.

For Eg: 
		Input: wwwwwwaaadexxxxxxx
		output: w5a3d1e1x7

	#prepbyte #microsoft

*/


string RunLenEncode(string s){
	string res= ""; 
	int count = 1;
	string ccount; 	
	char prev = s[0];

	for(int i= 1; i< s.length(); i++){
		if(s[i] == prev)
			count++; 
		else{	
			ccount = char(count + 48); 
			res += (prev + ccount); 
			count= 1; 
		}

		prev = s[i]; 
	} 
	ccount = char(count + 48); 
	res += (prev + ccount); 

	
	return res; 
	
}


int main(){

	string s; 
	cin>> s; 

	cout<< RunLenEncode(s);

	return 0; 
}
