cmake_minimum_required(VERSION 3.15)


# --------------- SETUP ----------------- #
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
project(
    raytracer
    VERSION 1.0.0
    LANGUAGES CXX
)

# --------------- FILES ------------------ #
add_executable(raytracer
    src/main.cpp
    )

# ----------------- FLAGS ----------------- #
set(CMAKE_CXX_FLAGS "-g3")

# ----------------- LIBRAIRY ------------------#
target_link_libraries(raytracer PRIVATE
    sfml-system
    sfml-window
    sfml-network
    sfml-graphics
    sfml-audio
    config++
)

# ------------------- CMAKE ---------------- #


# ------------------- INCLUDE --------------- #
target_include_directories(raytracer PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# ------------------- EXECUTABLE ----------- #
add_custom_command(TARGET raytracer POST_BUILD
    COMMAND mv raytracer ${PROJECT_SOURCE_DIR}
)
