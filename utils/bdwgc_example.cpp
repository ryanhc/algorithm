// g++ bdwgc_example.cpp -Ithird_party/bdwgc/include third_party/bdwgc/lib/libgc.a -lpthread

#include "gc_cpp.h"
#include "gc/gc_allocator.h"
#include <cassert>
#include <cstdio>
#include <vector>

#ifdef DEBUG
#  define debug(x) x
#else
#  define debug(x) do {} while(0)
#endif

namespace Test {

class Node : public gc {
public:
    Node() {}
    //private:
    std::vector<Node*, gc_allocator<Node*> > m_nodes;
};

}

using namespace Test;

int main() {
    GC_INIT();
    Node* n = new Node();
    for(unsigned i=0; i < 10000; i++) {
        Node* c = new Node();
        n->m_nodes.push_back(c);
    }

    debug(printf("asdf\n"));
}
