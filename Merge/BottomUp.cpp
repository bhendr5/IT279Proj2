//Team Patata - Jiasui Ding, Ben Hendrix, Jacob Levin
//IT 279

#include "mergeSort.h"
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <iterator>
using namespace std;



int main(int argc, char* argv[]) {
	//Input/variables
	string line;
	int value;
	ifstream myfile(argv[1]);
	
	
	//Vector for input data
	vector<long> vect1;
	while (getline(myfile, line))
	{
		istringstream iss(line);
		int n;
		iss >> n;
		vect1.push_back(n);
	}
	
	
	//Sorting array
	vector<long> vect2(vect1.size());
	mergeSort *arraySorter = new mergeSort;
	
	
	//Sort the vector
	arraySorter->BottomUpSort(vect1, vect2);
	
	
	cout<<"Operation completed Successfully \n";
	ofstream output_file(argv[2]);
	ostream_iterator<long> output_iterator(output_file, "\n");
	copy(arraySorter->temp1.begin(), arraySorter->temp1.end(), output_iterator);


}
