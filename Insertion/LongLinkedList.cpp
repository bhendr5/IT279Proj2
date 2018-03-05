/*
 * LongLinkedList.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: Ben
 */

#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <string>
#include "LongNode.h"
#include "LongLinkedList.h"
using namespace std;

LongNode::LongNode(long data, LongNode *prev, LongNode *next){
	this->data = data;
	this->next = next;
	this->prev = prev;
}

LongNode::LongNode(LongNode *prev, LongNode *next){
	this->data = NULL;
	this->next = next;
	this->prev = prev;
}


LongLinkedList::LongLinkedList(){
	head->next = tail;
	tail->prev = head;
}


void LongLinkedList::addEnd(long data) {
	LongNode *temp = new LongNode(data,tail->prev,tail);
	tail->prev->next = temp;
	tail->prev = temp;
	size++;
}

void LongLinkedList::addBefore(long data, LongNode *prevNode) {
	LongNode *temp = new LongNode(data,prevNode,prevNode->next);
	prevNode->next = temp;
	prevNode->next->next->prev = temp;
	size++;
}
