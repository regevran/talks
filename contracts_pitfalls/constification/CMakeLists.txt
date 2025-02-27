

set(
    EXAMPLE
    ex_constification
)


add_executable(
    ${EXAMPLE}
    main.cpp
    non_const_iteration.cpp
    deep_const.cpp
    contract_violation_handler.cpp
)

