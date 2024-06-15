
#include "../stack/stackUnitTests.h"
#include "../queue/queueUnitTests.h"
#include "../deque/dequeUnitTests.h"
#include "../segmentedDeque/segmentedDequeTest.h"

int main() {
    startStackUnitTests();
    startQueueUnitTests();
    startDequeUnitTests();
    segmentedDequeUnitTests();

    return 0;
}