#include "pair.h"
#include <assert.h>

pair_t pair_new(int x, int y){
    pair_t new;
    new.fst = x;
    new.snd = y;

    assert((new.fst == x) && (new.snd == y));
    return new;
}

int pair_first(pair_t p){
    int first = p.fst;

    assert(p.fst = first);
    return first;
}

int pair_second(pair_t p){
    int second = p.snd;

    assert(p.snd = second);
    return second;
}

pair_t pair_swapped(pair_t p){
    pair_t swapped;
    swapped.fst = p.snd;
    swapped.snd = p.fst;

    assert((pair_first(p) == pair_second(swapped)) && (pair_second(p) == pair_first(swapped)));
    return swapped;
}

pair_t pair_destroy(pair_t p){
    return p;
}

