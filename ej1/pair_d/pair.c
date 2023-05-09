#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(elem x, elem y){
    pair_t new = NULL;
    new = malloc(sizeof(struct s_pair_t));
    (*new).fst = x;
    (*new).snd = y;
    return new;
}


elem pair_first(pair_t p){
    elem first = (*p).fst;

    assert(first == (*p).fst);
    return first;
}

elem pair_second(pair_t p){
    elem second = (*p).snd;

    assert(second == (*p).snd);
    return second;
}

pair_t pair_swapped(pair_t p){
    pair_t swapped = NULL;
    swapped = malloc(sizeof(struct s_pair_t));
    (*swapped).fst = (*p).snd;
    (*swapped).snd = (*p).fst;

    assert((pair_first(swapped) == pair_second(p)) && (pair_second(swapped) == pair_first(p)));
    return swapped;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return p;
}

