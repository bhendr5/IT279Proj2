/*
 * InsertionSort.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: Ben
 */

#define __USE_MINGW_ANSI_STDIO 0
#include "LongLinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Builds linkedlist from input file
void parseFile(LongLinkedList *list, char* argv[]){
	long num;
	ifstream inputFile;
	inputFile.open(argv[1]);

	//Loops until no more entries in file
	while (inputFile >> num){
		list->addEnd(num);
	}
	inputFile.close();
}

void outputFile(LongLinkedList *list,  char* argv[]){
	ofstream outputFile(argv[2]);
	long out = NULL;
	LongNode *current = list->head->next;

	while (current->data >> out){
		outputFile << current->data << endl;
		current = current->next;
	}

	outputFile.close();
}



//sorts linkedlist using insertion sort
void sortList(LongLinkedList *list, char* argv[]){

	//selects first node after null head
	LongNode *inputNode = list->head->next;
	LongLinkedList *sortedList = new LongLinkedList();

	// Loop to go through original linked list from file until null tail is encountered
	while(inputNode->next != nullptr){
		LongNode *prevNode  = sortedList->tail->prev;

		//adds data to end if condition is already met
		if(inputNode->data >= prevNode->data){
			sortedList->addEnd(inputNode->data);
		}


		else{
			while(inputNode->data <= prevNode->data){
				prevNode = prevNode->prev;
			}
			sortedList->addBefore(inputNode->data, prevNode);
		}

		//switches to next node in inputList
		inputNode = inputNode->next;
	}

	outputFile(sortedList, argv);
}



int main(int argc, char* argv[]){
	LongLinkedList *list= new LongLinkedList();
	parseFile(list,argv);

	sortList(list,argv);

	return 0;
}
