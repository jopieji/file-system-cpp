//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "SearchList.h"
#include "Node.h"
#include "AList.h"

// --------------------------------
// -->    MODIFY This FILE    <----
// --------------------------------

void SearchList::MergeSort()
{
	// add your magic here
	pHead = MergeSort(pHead);
}

Node* SearchList::MergeSort(Node* _head)
{
	if (_head == nullptr || _head->pNext == nullptr)
	{
		return _head;
	}

	Node* right = getMiddle(_head);
	Node* left = MergeSort(_head);
	right = MergeSort(right);
	return merge(left, right);
}

Node* SearchList::getMiddle(Node* _n) 
{
	if (!_n || !_n->pNext) {
		return _n;
	}

	Node* slow = _n;
	Node* fast = _n->pNext;

	while (fast && fast->pNext) {
		slow = slow->pNext;
		fast = fast->pNext->pNext;
	}

	Node* mid = slow->pNext;
	slow->pNext = nullptr;
	mid->pPrev = nullptr;
	return mid;
}

Node* SearchList::merge(Node* left, Node* right)
{
	Node* dummy = new Node();
	Node* tail = dummy;

	while (left && right) {
		if (left->key < right->key) {
			tail->pNext = left;
			left->pPrev = tail;
			left = left->pNext;
		}
		else {
			tail->pNext = right;
			right->pPrev = tail;
			right = right->pNext;
		}
		tail = tail->pNext;
	}

	if (left) {
		tail->pNext = left;
		left->pPrev = tail;
	}
	else {
		tail->pNext = right;
		right->pPrev = tail;
	}

	Node* head = dummy->pNext;
	head->pPrev = nullptr;
	delete dummy;
	return head;
}

void SearchList::InsertionSort()
{
	// add your magic here	
	// insertion sort pseudo code
	// first element sorted; start at second; compare the two, swap if needed
	// with third element, compare to second, first if needed, and put in place; repeat
	Node* sortedHead = nullptr;
	Node *curr = pHead;
	while (curr != nullptr)
	{
		Node* next = curr->pNext;
		InsertHelper(curr, sortedHead);
		curr = next;
	}
	pHead = sortedHead;
}

void SearchList::InsertHelper(Node* _n, Node*& _s)
{
	// front of list case
	if (_s == nullptr || _s->key >= _n->key)
	{
		_n->pNext = _s;
		if (_s != nullptr) _s->pPrev = _n;
		_n->pPrev = nullptr;
		_s = _n;
	}
	// else case: iterate and insert into sorted end
	else
	{
		Node* c = _s;
		Node* p = nullptr;
		while (c != nullptr && c->key < _n->key)
		{
			p = c;
			c = c->pNext;
		}
		if (p == nullptr)
		{
			_n->pNext = _s;
			_s->pPrev = _n;
			_s = _n;
		}
		else
		{
			_n->pPrev = p;
			_n->pNext = c;
			p->pNext = _n;
			if (c != nullptr) c->pPrev = _n;
		}
	}
}

Node* SearchList::InsertionSort(Node* head)
{
	// Use insertion sort to sort the segment of the list starting from head
	Node* sortedHead = nullptr;
	Node* curr = head;
	while (curr != nullptr)
	{
		Node* next = curr->pNext;
		InsertHelper(curr, sortedHead);
		curr = next;
	}
	return sortedHead;
}

int SearchList::size(Node* head)
{
	int length = 1;
	while (head != nullptr)
	{
		length++;
		head = head->pNext;
	}
	return length;
}


Node* SearchList::MergeComboSort(Node* _head, int CutoffLength)
{
	if (_head == nullptr || _head->pNext == nullptr)
	{
		return _head;
	}

	int length = size(_head); // gets switch threshold
	if (length <= CutoffLength)
	{
		return InsertionSort(_head); // return sorted list (using insertion) early
	}

	Node* right = getMiddle(_head);
	Node* left = MergeSort(_head);
	right = MergeSort(right);	
	return merge(left, right);	// normal merge for larger lists
} 

void SearchList::MergeComboSort(int CutoffLength)
{
	pHead = MergeComboSort(pHead, CutoffLength);
}
// ---  End of File ---
