cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(TCC_ECA2025)

# Usa padrão C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Encontrar o OpenCV
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    message(STATUS "OpenCV found: ${OpenCV_VERSION}")
else()
    message(FATAL_ERROR "OpenCV not found")
endif()

# Adiciona diretório de headers
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

# Adiciona os arquivos fonte
add_executable(TCC_ECA2025
    main.cpp
)

# Vincula bibliotecas do OpenCV
target_link_libraries(TCC_ECA2025 ${OpenCV_LIBS})
