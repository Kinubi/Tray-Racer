#pragma once

#include "TrayRacer/Core/PlatformDetection.h"

#ifdef HZ_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>


#include "TrayRacer/Core/Base.h"

#include "TrayRacer/Core/Log.h"

#ifdef HZ_PLATFORM_WINDOWS
	#include <TrayRacer/Core/Window.h>
#endif
