#include<string>
#include<iostream>
#include<vector>

std::vector<std::string> SplitBySpace(std::string str){
	const char* string = &str[0];
	std::string temp = "";
	std::vector<std::string> result;
	while(*string){
		if(*string == ' '){
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

int partition(int integers[], int start, int end){
	int pivot = integers[start];
	int count = 0;
	for(int i = start + 1; i <= end; ++i){
		if(integers[i] <= pivot){
			++count;
		}
	}

	int pivot_index = start + count;
	std::swap(integers[pivot_index], integers[start]);

	int i = start, j = end;

	while(i < pivot_index && j < pivot_index){
		while(integers[i] <= pivot){
			++i;
		}
		while(integers[j] > pivot){
			--j;
		}
		if(i < pivot_index && j > pivot_index){
			std::swap(integers[i++], integers[j--]);
		}
	}
	return pivot_index;
}

void quickSort(int integers[], int start, int end){
	if(start >= end){
		return;
	}
	int p = partition(integers, start, end);
	quickSort(integers, start, p - 1);
	quickSort(integers, p + 1, end);
}


int main(){
	std::vector<std::vector<std::string>> lines; 
	while(true){
		std::string line;
		std::getline(std::cin, line);
		if(line == "exit"){
			break;
		}
		if(line != "" && line != "\t" && line != " "){
			lines.push_back(SplitBySpace(line));
		}
	}
	std::vector<int> totals;
	for(std::vector<std::string> line : lines){
		totals.push_back(GetTotal(line));
		printf("\n");
	}
	int* arr = &totals[0];
	quickSort(arr, 0, totals.size() - 1);
	std::cout << totals[totals.size() - 1];
	return 0;
}