#include "list.h"
#include <stdlib.h>
#include <assert.h>

struct s_node{
    elem value;
    struct s_node * next;
};

/*CONSTRUCTORS*/

list empty (){
  list l = NULL;
  return l;
}
/*
 * returns an empty list;
*/

list addl(list l, elem e){
  list new = malloc(sizeof(struct s_node));
  new->value = e;
  new->next = l;
  l = new;
  return l;
}
/*
 * adds and element at the beginning of the list;
*/

/*DESTRUCTOR*/

list destroy(list l){
  list aux = empty();
  while (!is_empty(l)){
    aux = l;
    l = l->next;
    free(aux);
  }
  return l;
}
/*
 *  free memory;
*/

/*OPERATIONS*/

bool is_empty(list l){
  bool res = (l == NULL);
  return res;
}
/*
 * verify is the list is empty;
*/

elem head (list l){
  assert(!is_empty(l));
  elem output = l->value;
  return output;
}
/*
 * returns the first elem of the list
*/

list tail(list l){
  assert(!is_empty(l));
  list aux = l;
  l = l->next;
  free(aux);
  return l;
}
/*
 * returns the list without the first element;
*/

list addr(list l, elem e){
  list new = malloc(sizeof(struct s_node));
  list aux = empty();
  new->value = e;
  new->next = NULL;
  if (is_empty(l)){
    l = new;
  }
  else{
    aux = l;
    while (aux->next != NULL){
      aux = aux->next;
    }
    aux->next = new;
  }
  return l;
}
/*
 * adds the elem e at the end of the list;
*/

unsigned int length(list l){
  unsigned int length = 0u;
  list a = l;
  while (!is_empty(a)){
    a = a->next;
    length = length + 1;
  }
  return length;
}
/*
 * returns the number of elements of the list l;
*/


list concat (list l1, list l2){
  if (is_empty(l1)){
    l1 = l2;
  }
  else{
    list a = l1;
    while (a->next != NULL){
      a = a->next;
    }
    a->next = l2;
  }
  return l1;
}
/*
 * concats the list l2 at the end of the list l1;
*/

elem index(list l, unsigned int i){
  assert(length(l) > i);

  elem output;
  struct s_node * a = l;
  unsigned int j = 0u;
  while (j < i){
    j++;
    a = a->next;
  }
  output = a->value;
  return output;
}
/*
 * returns the elem in the i position of the list;
*/

list take(list l, unsigned int n){
  assert(length(l) >= n);
  struct s_node * a = l;
  struct s_node * b = NULL;

  unsigned int j = 0u;
  while (j>n){
     a = a ->next; 
  }
  b = a->next;
  b = destroy(b);
  return l;
}
/*
 * returns the list with only the first n elemnts of the list l;
*/

list drop(list l, unsigned int n){
  unsigned int j = 0u;
  while (j < n){
    l = tail(l);
  }

  return l;
}
/*
 * returns the list without the first n elements of the list l;
*/

list copy_list(list l1){
  list l2 = empty();
  list a = l1;
  while (a != NULL){
    l2 = addr(l2, a->value);
    a = a->next;
  } 
  return l2;
}
/*
 * returns a copy of the l1 list;
*/
