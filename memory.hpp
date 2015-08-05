#ifndef ROB_MEMORY_HPP_INCLUDED
#define ROB_MEMORY_HPP_INCLUDED

#include <iterator>
#include <vector>
#include <algorithm>
#include <type_traits>

namespace bf {

template<typename T, size_t grow_size = 32>
class Memory {
public:
    using value_type = std::decay_t<T>;
    using container_type = std::vector<value_type>;
    using size_type = typename container_type::size_type;
    
    Memory() :
    memory(grow_size, value_type{}),
    index{size_type{}} {}
    
    auto inc() {
        memory[index]++;
    }
    
    auto dec() {
        memory[index]--;
    }
    
    auto inc_ptr() {
        if(++index == memory.size())
            memory.resize(memory.size() + grow_size, value_type{});
    }
    
    auto dec_ptr() {
        using std::begin;
        using std::end;
        
        if(index == 0) {
            auto old_size = memory.size();
            memory.resize(old_size + grow_size, value_type{});
            auto split = begin(memory);
            std::advance(split, old_size);
            std::rotate(begin(memory), split, end(memory));
            index = grow_size - 1;
        }
        else index--;
    }
    
    auto get() -> value_type& {
        return memory[index];
    }
    auto get() const -> value_type const& {
        return memory[index];
    }
    
private:
    container_type memory;
    size_type index;
};

} // namespace bf

#endif
