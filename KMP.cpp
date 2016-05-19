#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;
void func(string str, int* vec){
	int size = str.size();
	vec[0] = -1;
	int j = 0;
	for (int i = 1; i < size;){
		if (str[i] == str[j]){
			vec[i] = j;
			j++; i++;
		}
		else if (str[i] != str[j] && j != 0){
			j = 0;
		}
		else if (str[i] != str[j] && j == 0){
			vec[i++] = -1;
		}
	}
}

int main()
{
	string Input_file, Output_file; // create variable for input nad output files
	cin >> Input_file >> Output_file; // intput the input output file name
	ifstream ifs(Input_file);
	ofstream ofs(Output_file);
	clock_t begin = clock();// clock starts
	string pat; ifs >> pat; // get the first word in the file as the patern
	size_t patsize = pat.size();
	int function[patsize];
	func(pat ,function); //create a function 
	int count = 1; // use an integer to store the number of word
	string str; //get a line store in str
	vector<int> ans;
	while(getline(ifs, str)){
		stringstream ss(str); //using string stream to process input
		string word;

		while(ss >> word){
			count++ ;
			size_t j = 0;
			for (size_t i = 0; i < word.length(); i++){
				while (word[i] != pat[j] && j > 0){
					j = function[j - 1] + 1;
				}
				if (word[i] == pat[j]){
					j++; 
					if (j == pat.length()){
						ans.push_back(count); // if pat occurs, store count in array
						j = function[j - 1] + 1; 
					}
				}
			}
		}
	}
	ofs << clock() - begin << "ms" << endl << "1";// every starts with 1
	for (size_t i = 0; i < ans.size(); i++)
		ofs	<< ans[i] ;
	ifs.close();
	ofs.close();
	//cout << CLOCKS_PER_SEC << endl;
	return 0;
}
