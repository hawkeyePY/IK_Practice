#include <iostream>
using namespace std;

typedef struct _heap_t_ {
        int val;
        struct _heap_t_* left;
        struct _heap_t_* right;
} heapNode;


class minHeap {
        int capacity;
        int heap_size;
        public:
        minHeap();

};

int main ()
{

        return 0;
}
