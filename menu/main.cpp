#include "../stack/stackUnitTests.h"
#include "../queue/queueUnitTests.h"
#include "../deque/dequeUnitTests.h"
#include "../segmentedDeque/segmentedDequeTest.h"
#include "../menu/menu.h"

int main() {
//    startStackUnitTests();
//    startQueueUnitTests();
//    startDequeUnitTests();
//    segmentedDequeUnitTests();
    TUI session;
    TUI::sayHello();
    session.mainScreen();
    return 0;
}