#pragma once
// Defines often used and unchanged header files such that they don't need to be recompiled every time I build my project
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <list>
#include <ctime>
#include <cmath>

#include <string>
#include <sstream>
#include <vector>

#include <array>

// look into adding logger to this later.

#ifdef FU_PLATFORM_WINDOWS // makes sure to only include windows if we are on windows
    #include <Windows.h>
#endif
