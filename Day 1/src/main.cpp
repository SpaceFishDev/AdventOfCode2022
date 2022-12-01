#include<string>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include<fstream>




std::vector<std::string> SplitByNLine(std::string str){
	const char* string = &str[0];
	std::string temp = "";
	std::vector<std::string> result;
	while(*string){
		if(*string == '\n'){
			result.push_back(temp);
			temp = "";
		}
		else{
			temp += *string;
		}
		++string;
	}
	result.push_back(temp);
	return result;
}

int GetTotal(std::vector<std::string> strs){
	int num = 0;
	for(std::string str : strs){
		num += std::atoi(&str[0]);
	}
	return num;
}


int main(){
	std::vector<std::vector<std::string>> lines; 
	std::string temp = "";
	std::ifstream infile("input.txt");
	std::string line;
	while(	std::getline(infile, line)){
		if(line == "exit"){
			break;
		}
		if(line == "" || line == "\t" || line == " "){
			lines.push_back(SplitByNLine(temp));
			temp = "";
		}else
		{
			temp += line + "\n";
		}
	}
	lines.push_back(SplitByNLine(temp));
	std::vector<int> totals;
	for(std::vector<std::string> line : lines){
		totals.push_back(GetTotal(line));
	}
	std::sort(totals.begin(), totals.end());
	for(int total : totals){
		std::cout << total << "\n";
	}
	std::cout<< "Largest = " << totals[totals.size() - 1] << "\n";
	int i = totals.size() - 3;
	int n = 0;
	for(; i != totals.size(); ++i){
		n += totals[i];
		printf("Here\n");
	}
	std::cout << "Top 3 = " << n << "\n"; 
	return 0;
}