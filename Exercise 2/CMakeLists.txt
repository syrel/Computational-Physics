cmake_minimum_required(VERSION 3.2)
project(Exercise_2)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra -Wwrite-strings -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(PROGRAM_FILES src/linear.c src/stone.c src/sinus.c src/comparison.c src/bank_account_float.c src/bank_account_integer.c)
set(SOURCE_FILES src/input.c)

foreach( programfile ${PROGRAM_FILES} )
    string( REPLACE ".c" "" name ${programfile} )
    string( REPLACE "src/" "" name ${name} )
    add_executable( ${name} ${programfile} ${SOURCE_FILES})
    target_link_libraries(${name} m)
endforeach( programfile ${PROGRAM_FILES} )