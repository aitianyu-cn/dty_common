#include "../thread.hpp"
#include <thread>

// init current thread
dty::Property<dty::threading::Thread __POINTER__> __VARIABLE__ dty::threading::Thread::CurrentThread = ::null;