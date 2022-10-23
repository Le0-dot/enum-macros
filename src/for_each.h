#pragma once

#include "expand.h"

#define PARENS ()


// FOR_EACH macro that allows execution of macros on variable amount of arguments

#define FOR_EACH(macro, ...)                                     \
  __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))

#define FOR_EACH_HELPER(macro, arg, ...)                         \
  macro(arg)                                                     \
  __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))

#define FOR_EACH_AGAIN() FOR_EACH_HELPER


// Same as FOR_EACH, but macro that is executed take 2 arguments

#define FOR_EACH_2(macro, ...)                                   \
  __VA_OPT__(EXPAND(FOR_EACH_2_HELPER(macro, __VA_ARGS__)))

#define FOR_EACH_2_HELPER(macro, arg1, arg2, ...)                \
  macro(arg1, arg2)       \
  __VA_OPT__(FOR_EACH_2_AGAIN PARENS (macro, __VA_ARGS__))

#define FOR_EACH_2_AGAIN() FOR_EACH_2_HELPER
