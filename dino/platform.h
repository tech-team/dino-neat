#ifndef PLATFORM
#define PLATFORM

#ifndef DINO_PRETTY_FUNCTION

#  if defined(__clang__)
#    define DINO_PRETTY_FUNCTION __PRETTY_FUNCTION__
#  elif defined(__GNUC__) || defined(__GNUG__)
#    define DINO_PRETTY_FUNCTION __PRETTY_FUNCTION__
#  elif defined(_MSC_VER)
#    define DINO_PRETTY_FUNCTION __FUNCSIG__
#  else
#    define DINO_PRETTY_FUNCTION __FUNCTION__
#  endif

#endif

#endif // PLATFORM

