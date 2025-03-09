#ifndef ECS_EXPORT_HPP_
#define ECS_EXPORT_HPP_

#if defined(_MSC_VER)
    #if defined(RTYPE_BUILDING_SHARED)
        #define RTYPE_API __declspec(dllexport)
    #else
        #define RTYPE_API __declspec(dllimport)
    #endif
#else
    #define RTYPE_API __attribute__((visibility("default")))
#endif

#endif /* !ECS_EXPORT_HPP_ */