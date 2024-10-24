#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

int main(void) {
    queue q;

    initialize(&q);
    //test 1: After iniziatlizing the queue q must be empty.
    assert(empty(&q));

    //test 2: enqueue x, dequeue y, q must = x, queue must be same as before which is empty.
    enqueue(&q, 1);
    int y = dequeue(&q);
    assert(y == 1);
    assert(empty(&q));

    // test 3: 
    enqueue(&q, 2); //x0
    enqueue(&q, 3); //x1
    int y0 = dequeue(&q);
    int y1 = dequeue(&q);
    assert(y0 == 2); //y0 = x0?
    assert(y1 == 3); //y1 = x1?

printf("lortet virkede");
return 0;
}
