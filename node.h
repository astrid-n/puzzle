/*Queue implementation, adapted from https://stackoverflow.com/questions/4184954/are-there-standard-queue-implementations-for-c*/
#include <stdio.h>
#include "puzzle.h"

typedef struct node {
   puzzlePiece* piece;
   struct node *next;
} node_t;

void enqueue(node_t **head, puzzlePiece* piece);

puzzlePiece* dequeue(node_t **head);