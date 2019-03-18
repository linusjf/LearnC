#include <stdio.h>
#include <stdlib.h>
typedef struct empNode{
  int x;
  struct empNode *next;
  struct empNode *prev;
} EMPNODE;

int main() {
  int empIdValues[] = {2000, 1000, 5000, 8000, 7500};
  int count = sizeof(empIdValues) /
              sizeof(empIdValues[0]);
              // the root emp is the first emp
              EMPNODE * root,*last;
  // current emp and a new emp
  EMPNODE *currNode, *aNode;
  root = malloc(sizeof(EMPNODE));
  root->x = empIdValues[0];
  root->prev = NULL;
  root->next = NULL;
  currNode = root;
  for (int i = 1; i < count; i++) {
    aNode = malloc(sizeof(EMPNODE));
    aNode->x = empIdValues[i];
    aNode->next = NULL;
    aNode->prev = currNode;
    currNode->next = aNode;
    currNode = aNode;
  }
  last = currNode;
  currNode = root;

  if (currNode != 0) {
    int idx = 1;
    while (currNode) {
      printf("Employee %d has id: %d\n", idx, currNode->x);
      currNode = currNode->next;
      ++idx;
    }
  }
  currNode = last;
   if (currNode != 0) {
    int idx = 5;
    while (currNode) {
      printf("Employee %d has id: %d\n", idx, currNode->x);
      currNode = currNode->prev;
      --idx;
    }
  }
return 0;
}
