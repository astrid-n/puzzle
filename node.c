/*Queue implementation, copied from https://stackoverflow.com/questions/4184954/are-there-standard-queue-implementations-for-c*/
#include "node.h"

void enqueue(node_t **head, puzzlePiece* piece) {
   node_t *new_node = malloc(sizeof(node_t));
   if (!new_node) return;

   new_node->piece = piece;
   new_node->next = *head;

   *head = new_node;
}

puzzlePiece* dequeue(node_t **head) {
   node_t *current, *prev = NULL;
   puzzlePiece* retval = NULL;

   if (*head == NULL) return NULL;

   current = *head;
   while (current->next != NULL) {
      prev = current;
      current = current->next;
   }

   retval = current->piece;
   free(current);

   if (prev)
      prev->next = NULL;
   else
      *head = NULL;

   return retval;
}