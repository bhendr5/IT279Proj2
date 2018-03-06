/*
 * ShellSort.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Ben
 */

// C++ implementation of Shell Sort
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;
 
/* function to sort arr using shellSort */
int shellSort(long arr[], int n)
{
    // Find smallest exponent so that 2^exp - 1 < size, then decrement
    for (int exp = log(n+1)/log(2); exp > 0; exp--)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
		long gap = pow(2,exp) - 1;
        for (long i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            long temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            long j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 
/*reads input data to a vector so we do not need to know the size in advance*/
void readfile(char* argv[], vector<long> &vect, int &size){
	//open a file in read mode.
	cout<<"reading"<<endl;
	ifstream infile;
	infile.open("d10.rand.txt");

	//store data into vector
	string line;
	while (getline(infile,line)) {
		istringstream iss(line);
		int n;
		iss >> n;
		vect.push_back(n);
	}

	size = vect.size();

	//close and return
	infile.close();
}

/* writes sorted list to  ShellSortedList.txt*/
void writeFile(char* argv[], long arr[], int n) {
	//open a file in write mode
	cout<<"writing"<<endl;
	ofstream outfile;
	outfile.open("output.txt");
	
	//write array to file
	for (int i = 0; i < n; i++) {
		outfile << arr[i] << endl;
	}

	//finish and close
	outfile.close();
}

/*converts the vector to an array so that it is easier to sort with random access*/
void convert(vector<long> vect, long arr[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		arr[i] = vect.back();
		vect.pop_back();
	}
}

int main(int argc, char*filename[])
{
	//store data into vector
	vector<long> vect;
	int size = 0;
	readfile(filename, vect, size);
	
	//convert vector to array
	long arr[size];
	convert(vect, arr, size);
 
	//sort array
    shellSort(arr, size);
 
    //writes sorted list to output file
	writeFile(filename, arr, size);
    return 0;
}


