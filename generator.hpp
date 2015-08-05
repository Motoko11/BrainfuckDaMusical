#ifndef ROB_GENERATOR_HPP_INCLUDED
#define ROB_GENERATOR_HPP_INCLUDED

#include <cstdint>
#include <string>

namespace bf {

template<typename T>
auto to_bf_code(const T& x) {
    return std::string(x, '+');
}

template<typename T = uint8_t, typename Range>
auto generate(const Range& desired_output) {
    auto program = std::string{};
    
    for(auto&& c : desired_output)
        program += to_bf_code(static_cast<T>(c)) + ".>";
    
    return program;
}

} // namespace bf

#endif
