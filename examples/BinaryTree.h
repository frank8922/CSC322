#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct tree_node
{
	char *Word;
	int Count;
	struct tree_node *Left;
	struct tree_node *Right;
}TreeNodeType;

typedef TreeNodeType *TREENODE;

TREENODE AddToTree(TREENODE Root, char *Word);

void PrintTree(TREENODE Root);
#endif
