#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef node * list;
typedef int elem;

/*CONSTRUCTORS*/

list empty ();
/*
 * returns an empty list;
*/

list addl(list l, elem e);
/*
 * adds and element at the beginning of the list;
*/

/*DESTROY*/

list destroy(list l);
/*
 *  free memory;
*/

/*OPERATIONS*/

bool is_empty(list l);
/*
 * verify is the list is empty;
*/

elem head(list l);
/*
 * returns the first elem of the list
*/

list tail(list l);
/*
 * returns a list without the first element;
*/

list addr(list l, elem e);
/*
 * adds the elem e at the end of the list;
*/

unsigned int length(list l);
/*
 * returns the number of elements of the list l;
*/

list concat (list l1, list l2);
/*
 * concats the list l2 at the end of the list l1;
*/

elem index(list l, unsigned int i);
/*
 * returns the elem in the i position of the list;
*/

list take(list l, unsigned int n);
/*
 * returns a list with only the first n elemnts of the list l;
*/

list drop(list l, unsigned int n);
/*
 * returns a list without the first n elements of the list l;
*/

list copy_list(list l1);
/*
 * returns a copy of the l1 list;
*/


#endif