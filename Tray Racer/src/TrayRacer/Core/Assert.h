#pragma once

#include "TrayRacer/Core/Base.h"
#include "TrayRacer/Core/Log.h"
#include <filesystem>

#ifdef HZ_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define HZ_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { HZ##type##ERROR(msg, __VA_ARGS__); HZ_DEBUGBREAK(); } }
#define HZ_INTERNAL_ASSERT_WITH_MSG(type, check, ...) HZ_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define HZ_INTERNAL_ASSERT_NO_MSG(type, check) HZ_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", HZ_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define HZ_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define HZ_INTERNAL_ASSERT_GET_MACRO(...) HZ_EXPAND_MACRO( HZ_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, HZ_INTERNAL_ASSERT_WITH_MSG, HZ_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define HZ_ASSERT(...) HZ_EXPAND_MACRO( HZ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define HZ_CORE_ASSERT(...) HZ_EXPAND_MACRO( HZ_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define HZ_ASSERT(...)
#define HZ_CORE_ASSERT(...)
#endif

#ifdef HZ_ENABLE_VERIFYS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define HZ_INTERNAL_VERIFY_IMPL(type, check, msg, ...) { if(!(check)) { HZ##type##ERROR(msg, __VA_ARGS__); HZ_DEBUGBREAK(); } }
#define HZ_INTERNAL_VERIFY_WITH_MSG(type, check, ...) HZ_INTERNAL_VERIFY_IMPL(type, check, "VERIFYion failed: {0}", __VA_ARGS__)
#define HZ_INTERNAL_VERIFY_NO_MSG(type, check) HZ_INTERNAL_VERIFY_IMPL(type, check, "VERIFYion '{0}' failed at {1}:{2}", HZ_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define HZ_INTERNAL_VERIFY_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define HZ_INTERNAL_VERIFY_GET_MACRO(...) HZ_EXPAND_MACRO( HZ_INTERNAL_VERIFY_GET_MACRO_NAME(__VA_ARGS__, HZ_INTERNAL_VERIFY_WITH_MSG, HZ_INTERNAL_VERIFY_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define HZ_VERIFY(...) HZ_EXPAND_MACRO( HZ_INTERNAL_VERIFY_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define HZ_CORE_VERIFY(...) HZ_EXPAND_MACRO( HZ_INTERNAL_VERIFY_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define HZ_VERIFY(...)
#define HZ_CORE_VERIFY(...)
#endif

