# GameEngine

A modular C++ game engine built with SDL3 and OpenGL.

The goal of the project is to explore modern engine architecture and eventually support large-scale RTS simulations.

## Current Features

- SDL3 window and OpenGL context
- Renderer abstraction layer
- Vertex Buffer / Index Buffer
- Vertex Array abstraction
- Shader system
- Mesh abstraction

## Planned Features

Rendering
- Material system
- Texture support
- Camera system
- Lighting
- Model loading

Engine
- ECS (Entity Component System)
- Resource management
- Scene system
- Logging system

Simulation (long-term goal)
- RTS scale unit simulation
- Squad-based AI
- Morale and suppression systems

## Architecture

The engine is structured into modular subsystems.

engine/
 ├─ core/        Core utilities (logging, assertions)
 ├─ renderer/    Rendering abstraction over OpenGL
 ├─ math/        Vector and matrix math (planned)
 ├─ ecs/         Entity component system (planned)
 ├─ resources/   Asset management (planned)

sandbox/
 └─ Example application used for testing the engine

## Build

Requirements

- C++17 compatible compiler
- CMake
- SDL3
- OpenGL

Build steps

git clone https://github.com/alpardaczo8/GameEngine.git
cd GameEngine
mkdir build
cd build
cmake ..
cmake --build .