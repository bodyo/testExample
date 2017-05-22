#include "gmock/gmock.h"
#include "gtest/gtest.h"

/*!
 * \brief This modified main with QApplication is required for correct CHIP, PIN_CLASS (and others)
 *  creation, because they all depend on QWidget or QGraphics(...) stuff. GUI-related classes
 *  require QApplication to be run before their initialization (exec() call)
 *  But if you call exec() before Google Test execution exec() will block main thread with its own
 *  event processing loop.
 *  Here is a workaround for it: create QApplication instance and run its exec() just after test
 *  runner invocation.
 *  WARNING: DO NOT USE EVENT LOOP RELATED STUFF IN TESTS (drawing, Qt event system,
 *  signal/slot mechanisms (not sure about them) etc.) BECAUSE SUCH exec() USAGE IS UNDEFINED
 *  BEHAVIOR
 */
int main(int argc, char *argv[])
{
    testing::InitGoogleMock(&argc, argv);
//    a.exec();
    return RUN_ALL_TESTS();
}
