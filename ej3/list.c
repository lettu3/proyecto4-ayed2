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
  struct s_node new;
  new.value = e;
  new.next = l; 
  l = malloc(sizeof(struct s_node));
  (*l) = new;

  return l;
}
/*
 * adds and element at the beginning of the list;
*/

/*DESTRUCTOR*/

list destroy(list l){
  struct s_node * a;
  struct s_node * b;
  
  if (!is_empty(l)){
    a = l;
    b = a->next;
    l = b; 
    free(a);
    l = destroy(l);
  }

  return l;
}
/*
 *  free memory;
*/

/*OPERATIONS*/

bool is_empty(list l){
  bool res = l == NULL;
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
  struct s_node * a = l;
  if (l != NULL){
    l = a->next;
    a = destroy(a);
  }
  return l;
}
/*
 * returns the list without the first element;
*/

list addr(list l, elem e){
  struct s_node * a = l;
  struct s_node * b = NULL;
  struct s_node new;
  new.value = e;
  new.next = empty();

  if (is_empty(l)){
    l = malloc(sizeof(struct s_node));
    (*l) = new;
  }

  else{
    while (a ->next != NULL){     //busca el ultimo elemento de la lista
      a = a->next;  
    }
    a ->next = b;
    b = malloc(sizeof(struct s_node));    //agrega el elemento al final de la lista
    (*b) = new;
  }
  return l;
}
/*
 * adds the elem e at the end of the list;
*/

unsigned int length(list l){
  unsigned int length = 0u;
  struct s_node * a = l;
  while (a != NULL){
    l++;
    a = a -> next;
  }
  return length;
}
/*
 * returns the number of elements of the list l;
*/


list concat (list l1, list l2){

  while (!is_empty(l2)){
    addr(l1, head(l2));
    l2 = tail(l2);
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
  struct s_node * a = l1;
  while (a != NULL){
    addr(l2, a->value);
    a = a->next;
  } 
  return l2;
}
/*
 * returns a copy of the l1 list;
*/
