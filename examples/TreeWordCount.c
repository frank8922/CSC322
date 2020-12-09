#include "BinaryTree.c"

int main(void)
{

    TREENODE Root;
    String Word;

 //----Initialise the tree to empty.
   Root = NULL;

//----Read words and others until EOF. If a word is read put it in the tree.
 while (scanf("%s",Word) != EOF) {
    Root = AddToTree(Root,Word);
   }

//----Print the tree generated.
  PrintTree(Root);

 return(EXIT_SUCCESS);	

}
