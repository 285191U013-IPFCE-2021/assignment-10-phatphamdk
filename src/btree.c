#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t
  struct tree_node * new_node = malloc(sizeof(struct tree_node));
  new_node->item = x;
  new_node->left = NULL;
  new_node->right = NULL;

  if (t==NULL){
    return new_node;
  }

  else if (x>t->item){
    t->right = Insert(x, t->right);
  }
  else if (x<=t->item){
    t->left  = Insert(x, t->left);
  }
  return t;
}

int minValue(struct tree_node* t) {
  struct tree_node* current = t;
 
  while (current->left != NULL) {
    current = current->left;
  }
  return(current->item);
}

struct tree_node * Remove (int x, struct tree_node *t) // ikke færdig
{
 // Remove one item from the tree t
  if (t== NULL){
    return t;
  }
  if (x<t->item){
    t->left = Remove(x, t->left);
  }
  else if (x>t->item){
    t->right = Remove(x, t->right);
  }
  
  else{
  if (t -> left == NULL && t -> right == NULL)
    {
      free(t);
      return NULL;
    }

    
  else if (t -> left == NULL || t -> right == NULL)
    {
      struct tree_node * temp = NULL; 
      if (t -> right == NULL)
        temp = t -> left;
     
      else
        temp = t -> right;
      
      free(t);
      return temp;
   }
  

  else {
    int minval = minValue(t->right);
    t->item = minval;
    t->right = Remove(minval, t->right);
   }
  }

  return t;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.
    if (t==NULL){
      return false;
    }
    else if (t->item==x){
      return true;
    }
    else if (x>t->item){
      return Contains(x, t->right);
    }
    else if (x<t->item){
      return Contains(x, t->left);
    }

  
   
}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree ??

  return t = NULL;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  if (t==NULL){
    return 1;
  }
  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    return 0;
}
