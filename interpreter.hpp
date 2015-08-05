#ifndef ROB_INTERPRETER_HPP_INCLUDED
#define ROB_INTERPRETER_HPP_INCLUDED

#include <cstdint>
#include <deque>
#include <algorithm>
#include <iostream>
#include "memory.hpp"
#include "parse_error.hpp"


namespace bf { namespace detail {

template<typename Memory, typename Stack, typename It, typename Range>
auto left_bracket(It it, Memory const& memory, Stack& loop_stack, Range const& program) {
    using std::end;
    
    if(memory.get() == 0) {
        auto count = 0u;
        it = std::find_if(++it, end(program), [&count](auto&& x) {
            if(x == '[') count++;
            else if(x == ']') {
                if(count == 0) return true;
                else count--;
            }
            return false;
        });
        
        if(it == end(program)) throw parse_error("Parse error: Unmatched '['");
    }
    else loop_stack.emplace_back(it);
    
    return it;
}

template<typename It, typename Memory, typename Stack>
auto right_bracket(It it, Memory const& memory, Stack& loop_stack) {
    if(loop_stack.empty()) throw parse_error("Parse error: Unmatched ']'");
    else if(memory.get() == 0) loop_stack.pop_back();
    else it = loop_stack.back();
    
    return it;
}

template <typename It, typename Memory, typename Stack,
          typename Range, typename Func1, typename Func2>
auto handle_instruction(It it, Memory& memory, Stack& loop_stack,
                        Range const& program, Func1&& out_func, Func2&& in_func) {
    switch(*it) {
        case '+':
            memory.inc();
        break;
        case '-':
            memory.dec();
        break;
        case '<':
            memory.dec_ptr();
        break;
        case '>':
            memory.inc_ptr();
        break;
        case '[':
            it = left_bracket(it, memory, loop_stack, program);
        break;
        case ']':
            it = right_bracket(it, memory, loop_stack);
        break;
        case '.':
            out_func(memory.get());
        break;
        case ',':
            in_func(memory.get());
        break;
    }
    return ++it;
}

}} // namespace bf::detail


namespace bf {

template<typename T = uint8_t, typename Range, typename Func1, typename Func2>
auto run_program(Range const& program, Func1&& out_func, Func2&& in_func) {
    using std::begin;
    using std::end;
    using iterator_type = decltype(begin(program));
    
    auto memory = Memory<T>{};
    auto loop_stack = std::deque<iterator_type>{};
    auto next_instruction = begin(program);
    
    while(next_instruction != end(program)) {
        next_instruction = detail::handle_instruction(
            next_instruction, memory, loop_stack, program,
            std::forward<Func1>(out_func), std::forward<Func2>(in_func)
        );
    }
}

template<typename T = uint8_t, typename Range, typename Func1>
auto run_program(Range&& program, Func1&& out_func) {
    run_program<T>(
        std::forward<Range>(program),
        std::forward<Func1>(out_func),
        [](auto&& x) { std::cin >> x; }
    );
}

template<typename T = uint8_t, typename Range>
auto run_program(Range&& program) {
    run_program<T>(
        std::forward<Range>(program),
        [](auto&& x) { std::cout << x; }
    );
}

} // namespace bf

#endif
