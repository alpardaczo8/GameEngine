add_library(engine STATIC)

target_sources(engine
    PRIVATE
        Platform/SDL/SDLWindow.cpp
        Core/Application.cpp
        Core/Logger.cpp
        Core/Timer.cpp
        Renderer/Renderer.cpp
        Renderer/RenderCommand.cpp
        Renderer/Shader.cpp
        Renderer/VertexArray.cpp
        Renderer/VertexBuffer.cpp
        Renderer/IndexBuffer.cpp
        Renderer/VertexBufferLayout.cpp
        Renderer/Mesh.cpp
        Renderer/Material.cpp
        Renderer/Camera.cpp
        Renderer/CameraController.cpp
        Renderer/Texture.cpp
        Renderer/RTSCameraController.cpp
)

include(FetchContent)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.3
)

FetchContent_MakeAvailable(glm)

FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb
)

FetchContent_MakeAvailable(stb)

target_include_directories(engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${stb_SOURCE_DIR}    
)
target_link_libraries(engine
    PUBLIC
        SDL3::SDL3
        GLAD
        glm
)