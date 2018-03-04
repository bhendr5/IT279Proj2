/*
 * ShellSort.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Ben
 */

// C++ implementation of Shell Sort
#include  <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
 
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Find smallest exponent so that 2^exp - 1 < size, then decrement
    for (int exp = log(n+1)/log(2); exp > 0; exp--)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
		int gap = pow(2,exp) - 1;
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
	}
}
 
int readfile(string inFilename, int arr[]){
	//open a file in read mode.
	cout<<"reading from: "<<inFilename<<endl;
	ifstream infile;
	infile.open(inFilename);
	
	//store data into array
	int count = 0, i;
	string inputLine;
	while(!infile.eof()) {
		getline(infile, inputLine);
		stringstream token(inputLine);
		while (token >> i) {
			arr[count] = i;
			count++;
		}
	}
	
	//close and return
	infile.close();
	return count;
}

void writeFile(string outFilename, int arr[], int n) {
	//open a file in write mode
	cout<<"writing to: "<<outFilename<<endl;
	ofstream outfile;
	outfile.open(outFilename);
	
	//write array to file
	for (int i = 0; i < n; i++) {
		outfile << arr[i] << " ";
	}

	//finish and close
	outfile<<endl;
	outfile.close();
}

int main(string inFilename, string outFilename)
{
	int n = 999999999, arr[n];	
	int size = readfile(inFilename, arr);
	
    cout << "Array before sorting: \n";
    printArray(arr, size);
 
    shellSort(arr, size);
 
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
 
	writeFile(outFilename, arr, size);
    return 0;
}


