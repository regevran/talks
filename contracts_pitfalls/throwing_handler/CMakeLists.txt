

add_executable(
    ex_leak
    leak.cpp
    throwing_contract_violation_handler.cpp
)


add_executable(
    ex_compiler_bug
    test.cpp
    throwing_contract_violation_handler.cpp
)
