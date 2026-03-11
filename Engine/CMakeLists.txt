add_library(engine STATIC)

target_sources(engine
    PRIVATE
        Platform/SDL/SDLWindow.cpp
        Core/Application.cpp
        Renderer/Renderer.cpp
        Renderer/Shader.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(engine
    PUBLIC
        SDL3::SDL3
        GLAD
)