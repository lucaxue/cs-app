/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    if (! q) { return NULL; }

    q->head = NULL;
    q->tail = NULL;
    q->count = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (! q) { return; }

    list_ele_t* tmp;

    while (q->head)
    {
        tmp = q->head;
        q->head = q->head->next;
        free(tmp);
    }

    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    if (! q) { return false; }

    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (! newh) { return false; }

    newh->value = v;
    newh->next = q->head;

    if (! q->head) { q->tail = newh; }

    q->head = newh;
    q->count++;
    return true;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    if (! q) { return false; }

    list_ele_t *newt;
    newt = malloc(sizeof(list_ele_t));
    if (! newt) { return false; }

    newt->value = v;
    newt->next = NULL;

    q->tail->next = newt;
    q->tail = newt;
    q->count++;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (! q || ! q->head) { return false; }

    list_ele_t *tmp = q->head;
    q->head = q->head->next;

    if (vp) { *vp = tmp->value; }

    free(tmp);
    q->count--;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    return q ? q->count : 0;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (! q) { return; }

    list_ele_t *current = q->head;
    list_ele_t *prev = NULL, *next = NULL;

    while (current)
    {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    q->tail = q->head;
    q->head = prev;
}
