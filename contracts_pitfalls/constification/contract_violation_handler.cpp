
#include <contracts>
#include <iostream>

void handle_contract_violation(const std::contracts::contract_violation& violation)
{
    std::cerr 
          << "violation: ";

    switch (violation.kind()){
        case std::contracts::assertion_kind::pre:    { std::cerr << "pre("; break; }
        case std::contracts::assertion_kind::post:   { std::cerr << "post("; break; }
        case std::contracts::assertion_kind::assert: { std::cerr << "constract_assert("; break; }
    }

    std::cerr << violation.comment() << ")\n";

    const auto& location = violation.location();
    std::cerr 
          << "at:        "
          << location.file_name() << '\n'
          << "line:      "
          << location.line()  << '\n'
          << "function:  "
          << location.function_name() << '\n';

}
