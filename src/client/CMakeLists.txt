add_executable(r-type_client
    main.cpp
    src/Menu/Menu.cpp
    src/Gameoverlay/Gameoverlay.cpp
    src/GameApp/componantInitialisation.cpp
    src/Error/Error.cpp
    src/network/NetworkClient.cpp
    ../Parsing/Parsing.cpp
    src/protocol/ProtocolClient.cpp
    src/Displayable/Displayable.cpp
    src/AnimateSprite/AnimateSprite.cpp
    src/AnimateShoot/AnimateShoot.cpp
    src/ServerCom/ServerCom.cpp
    src/GameApp/GameApp.cpp
    src/MusicHandler/MusicHandler.cpp
    src/VideoComponent/Clock/Clock.cpp
    src/VideoComponent/Stack/Stack.cpp
    src/VideoComponent/Video/Video.cpp
    src/VideoComponent/Frame/Frame.cpp
    src/TCP/CRoomClient.cpp
    src/TCP/ParsingTcp.cpp
)

set_target_properties(r-type_client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

target_include_directories(r-type_client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Error
    ${CMAKE_CURRENT_SOURCE_DIR}/src/network
    ${CPM_SOURCE_CACHE}/asio/*/asio/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/protocol
    ${CPM_SOURCE_CACHE}/sfml/*/src/SFML/*
    ${CMAKE_CURRENT_SOURCE_DIR}/../Parsing
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Menu
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ClientGameState
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Gameoverlay
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Displayable
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimateSprite
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AnimateShoot
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TextureHandler
    ${CMAKE_CURRENT_SOURCE_DIR}/../ecs/network
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ServerCom
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MusicHandler
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameApp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoComponent/Clock
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoComponent/Stack
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoComponent/Vector
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoComponent/Video
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoComponent/Queue
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VideoComponent/Frame
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCP
)

target_link_libraries(r-type_client PRIVATE sfml-graphics sfml-window sfml-system sfml-audio asio)

if(WIN32)
    add_custom_command(TARGET r-type_client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE:rtype_ecs>
            ${CMAKE_SOURCE_DIR}
    )
endif()