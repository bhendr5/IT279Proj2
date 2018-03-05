/*
 * LongNode.h
 *
 *  Created on: Jan 28, 2018
 *      Author: Ben
 */

#ifndef LONGNODE_H_
#define LONGNODE_H_

class LongNode{

public:
	long data;
	LongNode *next = nullptr;
	LongNode *prev = nullptr;
	LongNode(long data, LongNode *prev, LongNode *next);
	LongNode(LongNode *prev, LongNode *next);
};



#endif /* LONGNODE_H_ */
