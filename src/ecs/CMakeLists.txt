add_library(rtype_ecs SHARED
    src/ECSError.cpp
    src/Entity.cpp
    src/Registry.cpp
)

set_target_properties(rtype_ecs PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "include/ecs/Registry.hpp"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_include_directories(rtype_ecs
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(rtype_ecs
    PRIVATE
        RTYPE_BUILDING_SHARED
)

if(UNIX)
    target_compile_options(rtype_ecs PRIVATE -fvisibility=hidden)
endif()

install(TARGETS rtype_ecs
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include/ecs
)

install(DIRECTORY include/ecs
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.tpp"
)