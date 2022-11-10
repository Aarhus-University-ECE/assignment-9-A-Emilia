#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include "dfs.h"


void DFT(node *root) {
  stack *n_stack = malloc(sizeof(stack));                      // Initialises stack
  n_stack->next = NULL;
  push(n_stack, root);

  while (!isEmpty(n_stack)) {
    node *curr = pop(n_stack)->node;                           // Traverses the stack
    print_node(curr);                                          // Prints current node

    if (curr->rchild != NULL) { push(n_stack, curr->rchild); } // Pushes any right children found to the stack
    if (curr->lchild != NULL) { push(n_stack, curr->lchild); } // Pushes any left children found to the stack
  }
}

node *make_node(int num, node *left, node *right) {
  node *n_node = malloc(sizeof(node));                         // Allocates memory
  n_node->num = num;                                           // Sets the various variables
  n_node->lchild = left;
  n_node->rchild = right;
  n_node->visited = false;

  return n_node;
}

void free_node(node *p) {}

void print_node(node *p) {
  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d\t", p->num);
}

void print_tree(node *p, int depth) {
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild) {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node) {
  stack *n_stack = malloc(sizeof(stack));
  n_stack->node = node;
  n_stack->next = topp->next;
  topp->next = n_stack;

  return n_stack;
}

bool isEmpty(stack *topp) { return topp->next == NULL; }

node *top(stack *topp) { return 0; }

stack *pop(stack *topp) {
  assert(!isEmpty(topp));
  stack *temp = topp->next;
  topp->next = topp->next->next;

  return temp;
}

void print_stack(stack *topp) {
  struct stack *temp = topp;

  while (temp != NULL) {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}