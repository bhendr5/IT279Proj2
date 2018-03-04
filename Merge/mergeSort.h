//Team Patata - Jiasui Ding, Ben Hendrix, Jacob Levin
//IT 279

#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
class mergeSort
{
  
public:
	//mergeSort Constructor
	mergeSort();
	
	//Stores sorted vector
	vector<long> temp1;
	
	//Stores full unsorted vector
	vector<long> temp2;
	
	//Merges increments
	void BottomUpSort(vector<long> arr1,vector<long> arr2);
	
	//Sorting method 
	void BottomUpMerge(int indexLeft, int indexRight, int indexEnd);
	
	//mergeSort destructor
	virtual ~mergeSort();
};