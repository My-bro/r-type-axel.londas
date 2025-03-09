add_executable(flappy_bird
    Main.cpp
    GameState.cpp
    components/Pipe.cpp
    components/Drawable.cpp
    components/Position.cpp
    components/Velocity.cpp
    components/HitBox.cpp
    systems/background_render_system.cpp
    systems/clear_render_system.cpp
    systems/display_render_system.cpp
    systems/pipes_mouvement_system.cpp
    systems/pipes_render_system.cpp
    systems/player_control_system.cpp
    systems/player_mouvement_system.cpp
    systems/player_pipes_collision_system.cpp
    systems/player_render_system.cpp
    systems/score_system.cpp
    systems/score_render_system.cpp
    systems/spawn_pipes_system.cpp
    systems/spawn_player_system.cpp
)

set_target_properties(flappy_bird PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

message(CPM_SOURCE_CACHE="${CPM_SOURCE_CACHE}")

target_include_directories(flappy_bird PRIVATE
    ${CPM_SOURCE_CACHE}/asio/*/asio/include
    ${CPM_SOURCE_CACHE}/sfml/*/src/SFML/*
    ${CPM_SOURCE_CACHE}/yaml-cpp/*/include
)

target_link_libraries(flappy_bird
    PRIVATE
        rtype_ecs
        sfml-graphics
        sfml-window
        sfml-system
        asio
        yaml-cpp
)
