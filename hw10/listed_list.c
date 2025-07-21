#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) {
  struct list_node *node = malloc(sizeof(struct list_node));
  if (node == NULL) {
    return NULL;
  }
  node->value = value;
  node->next = NULL;
  return node;
}

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node *node = new_node(value);
  if (node == NULL) return;
  node->next = list->head;
  list->head = node;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node *node = new_node(value);
  if (node == NULL) return;
  if (list->head == NULL) {
    list->head = node;
    return;
  }
  struct list_node *cur = list->head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = node;
}

size_t remove_from_head(struct linked_list *list) {
  if (list->head == NULL) {
    return 0;
  }
  struct list_node *node = list->head;
  size_t value = node->value;
  list->head = node->next;
  free(node);
  return value;
}

size_t remove_from_tail(struct linked_list *list) {
  if (list->head == NULL) {
    return 0;
  }
  struct list_node *cur = list->head;
  if (cur->next == NULL) {
    size_t value = cur->value;
    free(cur);
    list->head = NULL;
    return value;
  }
  // Find second to last node
  while (cur->next->next != NULL) {
    cur = cur->next;
  }
  struct list_node *tail = cur->next;
  size_t value = tail->value;
  cur->next = NULL;
  free(tail);
  return value;
}

void free_list(struct linked_list list) {
  struct list_node *cur = list.head;
  while (cur != NULL) {
    struct list_node *next = cur->next;
    free(cur);
    cur = next;
  }
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
