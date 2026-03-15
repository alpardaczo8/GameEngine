add_library(engine STATIC)

target_sources(engine
    PRIVATE
        Platform/SDL/SDLWindow.cpp
        Core/Application.cpp
        Core/Logger.cpp
        Renderer/Renderer.cpp
        Renderer/Shader.cpp
        Renderer/VertexArray.cpp
        Renderer/VertexBuffer.cpp
        Renderer/IndexBuffer.cpp
        Renderer/VertexBufferLayout.cpp
        Renderer/Mesh.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(engine
    PUBLIC
        SDL3::SDL3
        GLAD
)