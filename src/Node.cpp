/*
Creates a doubly linked list. 
*/
#include "Node.h"

Node::Node(void)
{
	next_ = this;
	prev_ = next_;
}

Node::Node(Node* next, Node* prev, Window* window)
{
	next_ = next;
	prev_ = prev;
	window_ = window;
}

void Node::insertAfter(Node* nodeAt, Window* newWindow)
{
	Node* nextNode = nodeAt->next_;
	Node* tmp = new Node(nextNode, nodeAt, newWindow);
	nodeAt->next_ = tmp;
	nextNode->prev_ = tmp;
}

void Node::insertBefore(Node* node, Window* newWindow)
{
	Node* previousNode = node->prev_;
	Node* tmp = new Node(node, previousNode, newWindow);
	node->prev_ = tmp;
	previousNode->next_ = tmp;
}

void Node::remove(Node* remove_here) 
{
	delete remove_here;
}


void Node::reverse(Node* the_sentinel)
{
	Node* tmp;
	Node* cur = the_sentinel;
	do
	{
		tmp = cur->next_;
		cur->next_ = cur->prev_;
		cur->prev_ = tmp;
		
		// go to next node in list
		cur = cur->prev_;
	} while(cur != the_sentinel);
}

