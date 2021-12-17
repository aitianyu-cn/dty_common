#include "./thread.hpp"
#include <thread>

// init current thread
dty::Property<dty::thread::Thread __POINTER__> __VARIABLE__ dty::thread::Thread::CurrentThread = null;