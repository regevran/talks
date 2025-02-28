
cmake_minimum_required(VERSION 3.30)


set(
    CMAKE_CXX_COMPILER 
    "$ENV{HOME}/bin/compilers/gcc-contracts/bin/g++"
    #"$ENV{HOME}/bin/compilers/clang-contracts/clang-ericwf-contracts-trunk/bin/clang++"
)

set(
    CMAKE_C_COMPILER 
    "$ENV{HOME}/bin/compilers/gcc-contracts/bin/gcc"
    #"$ENV{HOME}/bin/compilers/clang-contracts/clang-ericwf-contracts-trunk/bin/clang"
)

add_compile_options(
    -fcontracts 
    -fcontracts-nonattr
    -std=c++26
    #-v 
)

set (
    PROJ_NAME
    contracts_pitfalls
)

project(${PROJ_NAME})

subdirs(constification)


