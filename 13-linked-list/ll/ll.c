//
// Created by hfwei on 2023/12/29.
//

#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

// functions on linked list (implementations)
void Init(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

// TODO
void Free(LinkedList *list) {

}

bool IsEmpty(const LinkedList *list) {
  return list->head == NULL;
}

bool IsSingleton(const LinkedList *list) {
  return !IsEmpty(list) && list->head == list->tail;
}

int GetHeadVal(const LinkedList *list) {
  if (IsEmpty(list)) {
    return -1;
  }

  return list->head->index;
}

void Print(const LinkedList *list) {
  if (IsEmpty(list)) {
    return;
  }

  Node *node = list->head;

  do {
    printf("%d ", node->index);
    node = node->next;
  } while (node != list->head);
}

void Append(LinkedList *list, int index) {
  Node *node = malloc(sizeof *node);
  if (node == NULL) {
    return;
  }
  node->index = index;

  if (IsEmpty(list)) {
    list->head = node;
  } else{
    list->tail->next = node;
  }

  list->tail = node;
  list->tail->next = list->head;
}

void Delete(LinkedList *list, Node *prev) {
  if (IsEmpty(list)) {
    return;
  }

  if (IsSingleton(list)) {
    free(list->head);
    Init(list);
    return;
  }

  Node *cur = prev->next;
  Node *next = cur->next;

  prev->next = next;

  if (cur == list->head) {
    list->head = next;
  }

  if (cur == list->tail) {
    list->tail = prev;
  }

  free(cur);
}