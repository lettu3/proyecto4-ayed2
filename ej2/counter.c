#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = NULL;
    c = malloc(sizeof(struct _counter));
    (*c).count = 0u;
    return c;
}

void counter_inc(counter c) {
    (*c).count = (*c).count + 1;
    return;
}

bool counter_is_init(counter c) {
    bool res;
    res = (*c).count == 0u;
    return res;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    (*c).count = (*c).count - 1;
    return;
}

counter counter_copy(counter c) {
    counter copy = NULL;
    copy = malloc(sizeof(struct _counter));
    (*copy).count = (*c).count;

    return copy;
}

void counter_destroy(counter c) {
    free(c);
    return;
}
