
cmake_minimum_required(VERSION 3.30)


set(
    CMAKE_CXX_COMPILER 
    "$ENV{HOME}/bin/compilers/clang-contracts/clang-ericwf-contracts-trunk/bin/clang++"
)

set(
    CMAKE_C_COMPILER 
    "$ENV{HOME}/bin/compilers/clang-contracts/clang-ericwf-contracts-trunk/bin/clang"
)

add_compile_options(
    -fcontracts 
    -fcontract-evaluation-semantic=enforce
)

set (
    PROJ_NAME
    contracts_pitfalls
)

project(${PROJ_NAME})

subdirs(constification)


