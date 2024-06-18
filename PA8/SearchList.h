//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef SEARCH_LIST_H
#define SEARCH_LIST_H

#include "Node.h"

class AList;

class SearchList
{
public:
	// Big four
	SearchList() = delete;
	~SearchList();
	SearchList(const SearchList &) = delete;
	SearchList &operator = (const SearchList &) = delete;

	SearchList(AList *pList);

	// Accessors
	Node *GetHead() const;
	void SetHead(Node *pNode);
	int GetNumNodes() const;

	// Class methods
	int GetCutoffLength(); 

	//---------------------------------------------------------------------------------------
	// Please implement(rework) these methods (add additional methods to help if you want)
	//---------------------------------------------------------------------------------------
	void InsertionSort();
	void InsertHelper(Node*, Node*&);
	Node* InsertionSort(Node*); 
	void MergeSort();
	Node* MergeSort(Node* _head);
	Node* merge(Node*, Node*);
	Node* getMiddle(Node*);
	void MergeComboSort(int CutoffLength);
	Node* MergeComboSort(Node* _head, int CutoffLength);
	int size(Node* _head);

private:
	// ------------------------------------------------------
	// Data - YOU CANNOT add or change data in this class
	// ------------------------------------------------------

	Node *pHead;
	int  NumNodes;
	int  mCutoffLength;
};

#endif 

// ---  End of File ---
