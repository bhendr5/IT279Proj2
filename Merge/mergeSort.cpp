//Team Patata - Jiasui Ding, Ben Hendrix, Jacob Levin
//IT 279

#include <algorithm>
#define NOMINMAX
#include "mergeSort.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <vector>
using namespace std;


mergeSort::mergeSort() {
}

void mergeSort::BottomUpMerge(int indexLeft, int indexMid, int lastindex)
{
	int x = 0;
	int i = indexLeft;
	int k = indexLeft;
	int j = indexMid;
	
	
	//Sort methodology
	while ((i < indexMid) || (j < lastindex))
	{
		if ((i < indexMid) && (j < lastindex))
		{
			if (temp2[i] < temp2[j])
				temp1[k++] = temp2[i++];
			else
				temp1[k++] = temp2[j++];
		}
		
		else if (i == indexMid)
			temp1[k++] = temp2[j++];
		
		else if (j == lastindex)
			temp1[k++] = temp2[i++];
	}
}


void mergeSort::BottomUpSort(vector<long> arr1, vector<long> arr2)
{
	temp2 = arr1;
	temp1 = arr2;
	int width;
	
	
	//Determines the increments for merge 
	for (width = 1; width < (int)temp2.size(); width = 2 * width)
	{
		int i;
		
		
		//Iterates vector with increments from above
		for (i = 0; i < (int)temp2.size(); i = i + 2 * width)
		{
			BottomUpMerge(i, min((i+width),(int)arr1.size()) ,min((i+2*width),(int)arr1.size()));
		}
		copy(temp1.begin(), temp1.end(), temp2.begin());
	}
	int x = 0;
	
}

mergeSort::~mergeSort()
{
	
}