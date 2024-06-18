//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "AList.h"
#include "Node.h"
#include "FileList.h"

// --------------------------------
// -->    MODIFY This FILE    <----
// --------------------------------

FileList::FileList()
: pHead(nullptr),
NumNodes(0)
{
	// Hint you might need to rework this...
	// if you add data to FileList class
}

FileList::~FileList()
{
	// Hint you might need to rework this...
	Node* curr = this->pHead;
	while (curr != nullptr)
	{
		Node* tmp = curr->pNext;
		delete curr;
		curr = tmp;
	}
}


void FileList::WriteToFile(const char * const pFileName, AList *pAList)
{
	// Do your magic

	// Make sure you close the file after you fill it
	// Use fopen,fwrite,ftell,...,fclose

	// Hint: Open the file, write the nodes into the file 

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method

	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your destructor.

	// Quick sample code... remove this code and replace with your own


	FILE *pFileHandle = nullptr;

	assert(pFileName);
	errno_t status;
	status = fopen_s(&pFileHandle, pFileName, "wb");
	assert(pFileHandle);
	assert(status == 0);

	Node* curr = pAList->GetHead();

	// TODO: maybe write list metadata (num nodes, cutoff, head)
	
	const size_t bufSize = sizeof(unsigned int) * 100000; 
	unsigned int* buf = new unsigned int[bufSize];
	size_t ind = 0;
	size_t numNodes = 0;

	while (curr != nullptr)
	{
		buf[ind++] = curr->x;
		buf[ind++] = curr->y;
		buf[ind++] = curr->z;
		buf[ind++] = curr->key;

		curr = curr->getNext();
		numNodes++;
	}

	if (ind > 0)
	{
		//Trace::out("ind: %i\n", ind);
		fwrite(buf, sizeof(unsigned int), bufSize / sizeof(unsigned int), pFileHandle);
	}
	//Trace::out("Nodes written: %i\n", numNodes);
	delete[] buf;
	fclose(pFileHandle);

	assert(numNodes == 25000); // Ensure that 25000 nodes were written
}

FileList::FileList(const char * const pFileName, int numNodes)
{
	// Do your magic here:

	// Create the Linked List... You cannot use the original code
	// The input file, and numNodes is all you need to recreate the FileList
	
	// Hint: Open the file, read and create new nodes, 
	//       fill them with the data from the file

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method
	     
	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your destructor.

	// Quick sample code... remove this code and replace with your own

	this->NumNodes = 0;

	FILE *pFileHandle;

	errno_t status;
	assert(pFileName);
	status = fopen_s(&pFileHandle, pFileName, "rb");
	assert(pFileHandle);
	assert(status == 0);

	Node* prev = nullptr;
	Node* curr = nullptr;

	const size_t bufSize = sizeof(unsigned int)*numNodes*4;
	//Trace::out("Size of buf: %d\n", bufSize);
	unsigned int* buf = new unsigned int[bufSize];

	size_t bytesRead = fread(buf, sizeof(unsigned int), static_cast<size_t>(numNodes*4), pFileHandle);
	fclose(pFileHandle);
	//Trace::out("Ints read: %d\n", bytesRead);
	unsigned int ct = 0;

	while (ct < bytesRead)
	{
		//Trace::out("%i\tct: %i\n", buf[ct], ct);
		curr = new Node();
		curr->x = buf[ct++];
		curr->y = buf[ct++];
		curr->z = buf[ct++];
		curr->key = buf[ct++];
		curr->pPrev = prev;
		if (prev != nullptr) prev->pNext = curr;
		else this->pHead = curr;
		prev = curr;
		this->NumNodes++;
	}
	//Trace::out("num nodes: %i\n", this->NumNodes);
	delete[] buf;

}

// ---  End of File ---
