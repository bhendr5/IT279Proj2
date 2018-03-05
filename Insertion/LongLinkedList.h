/*
 * LongLinkedList.h
 *
 *  Created on: Jan 28, 2018
 *      Author: Ben
 */

#ifndef LONGLINKEDLIST_H_
#define LONGLINKEDLIST_H_
#include "LongNode.h"

class LongLinkedList{
public:
	long size = 0;
	LongNode *head = new LongNode(nullptr, nullptr);
	LongNode *tail = new LongNode(nullptr, nullptr);
	LongLinkedList();
	void addEnd(long data);
	void addBefore(long data, LongNode *prevNode);
};



#endif /* LONGLINKEDLIST_H_ */
