/*
Methods that allow useres to insertAter, insertBefore and delete nodes. 
*/
#include "Node.h"

Node::Node(void)
{
	next_ = this;
	prev_ = next_;
}
/*
@param next next spot in the list
@param prev previous spot in the list
@param window a rectangle
*/
Node::Node(Node* next, Node* prev, Window* window)
{
	next_ = next;
	prev_ = prev;
	window_ = window;
}
/*
@param nodeAt the node you want to insert after
@param newWindow the new rectangle to be placed after the nodeAt
*/
void Node::insertAfter(Node* nodeAt, Window* newWindow)
{
	Node* nextNode = nodeAt->next_;
	Node* tmp = new Node(nextNode, nodeAt, newWindow);
	nodeAt->next_ = tmp;
	nextNode->prev_ = tmp;
}
/*
@param node the node you want to insert in front of
@param newWindow the new rectangle to be placed before the node
*/
void Node::insertBefore(Node* node, Window* newWindow)
{
	Node* previousNode = node->prev_;
	Node* tmp = new Node(node, previousNode, newWindow);
	node->prev_ = tmp;
	previousNode->next_ = tmp;
}
/*
@param remove_here removes the given node from the list
*/
void Node::remove(Node* remove_here) 
{
	delete remove_here;
}

/*
This method reverses the order of the nodes in the list.
@param sentinel the decode node in the list
*/
void Node::reverse(Node* sentinel)
{
	Node* tmp;
	Node* cur = sentinel;
	do
	{
		tmp = cur->next_;
		cur->next_ = cur->prev_;
		cur->prev_ = tmp;
		
		// go to next node in list
		cur = cur->prev_;
	} while(cur != sentinel);
}

