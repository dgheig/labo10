cmake_minimum_required(VERSION 3.10)
# make_minimum_required(VERSION 3.5)

project(Labo10)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(geometry_library STATIC
    src/geometry.cpp
)

target_include_directories(geometry_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(labo10
    labo_10_comte_emmanuelle_gallay_david.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( labo10
    PRIVATE
        geometry_library
)