#ifndef ROB_PARSE_ERROR_HPP_INCLUDED
#define ROB_PARSE_ERROR_HPP_INCLUDED

#include <stdexcept>
#include <sstream>

namespace bf { namespace detail {

template<typename T>
constexpr auto to_str(T&& x) {
    std::ostringstream ss;
    ss << x;
    return ss.str();
}

template<typename T, typename... Args>
constexpr auto to_str(T&& x, Args&&... args) {
    return to_str(std::forward<T>(x)) + to_str(std::forward<Args>(args)...);
}

}} // namespace bf::detail

namespace bf {

class parse_error : public std::runtime_error {
public:
    template<typename... Args>
    parse_error(Args&&... args) :
    std::runtime_error(detail::to_str(std::forward<Args>(args)...)) {}
};

} // namespace bf

#endif
