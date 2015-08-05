#ifndef ROB_SOUNDS_HPP_INCLUDED
#define ROB_SOUNDS_HPP_INCLUDED

#include <cmath>
#include <windows.h> // TODO: GET RID OF THIS SIN!
#include <cstdint>

namespace sound {

enum class note {
    C_1, Cs_1, D_1, Ds_1, E_1, F_1, Fs_1, G_1, Gs_1, A_1, As_1, B_1,
    C0, Cs0, D0, Ds0, E0, F0, Fs0, G0, Gs0, A0, As0, B0,
    C1, Cs1, D1, Ds1, E1, F1, Fs1, G1, Gs1, A1, As1, B1,
    C2, Cs2, D2, Ds2, E2, F2, Fs2, G2, Gs2, A2, As2, B2,
    C3, Cs3, D3, Ds3, E3, F3, Fs3, G3, Gs3, A3, As3, B3,
    C4, Cs4, D4, Ds4, E4, F4, Fs4, G4, Gs4, A4, As4, B4,
    C5, Cs5, D5, Ds5, E5, F5, Fs5, G5, Gs5, A5, As5, B5,
    C6, Cs6, D6, Ds6, E6, F6, Fs6, G6, Gs6, A6, As6, B6,
    C7, Cs7, D7, Ds7, E7, F7, Fs7, G7, Gs7, A7, As7, B7,
    C8, Cs8, D8, Ds8, E8, F8, Fs8, G8, Gs8, A8, As8, B8,
    C9, Cs9, D9, Ds9, E9, F9, Fs9, G9
};

template<typename T>
constexpr auto frequency(const T& n) {
    return 440.0 * std::pow(2.0, (n - 69.0) / 12.0);
    // return 440.0 * std::exp2((n - 69.0) / 12.0);
}

} // namespace sound


namespace sound {

enum class mode {
    SOUND = 128, PRINT, VOLUME, DURATION
};

} // namespace sound


namespace sound {

class Engine {
public:
    Engine() :
    current_mode{mode::SOUND},
    duration{100},
    volume{0.8} {}
    
    template<typename T>
    auto operator()(T&& x) {
        if(static_cast<mode>(x) > mode::SOUND) set_mode(static_cast<mode>(x));
        else parse(std::forward<T>(x));
    }
    
private:
    mode current_mode;
    uint_fast16_t duration;
    float volume;
    
    auto set_mode(const mode& x) {
        current_mode = x;
    }
    
    template<typename T>
    auto parse(T&& x) {
        switch(current_mode) {
            default: throw std::runtime_error("Error: Invalid sound engine mode."); break;
            case mode::SOUND: play_sound(std::forward<T>(x)); break;
            case mode::PRINT: print_character(std::forward<T>(x)); break;
            case mode::VOLUME: set_volume(std::forward<T>(x)); break;
            case mode::DURATION: set_duration(std::forward<T>(x)); break;
        }
    }
    
    template<typename T>
    auto play_sound(T&& x) {
        print_character(x);
        Beep(frequency(x), duration);
    }
    
    template<typename T>
    auto print_character(T&& x) {
        std::cout << x << std::flush;
    }
    
    template<typename T>
    auto set_volume(T&& x) {
        volume = x / 127.0;
        set_mode(mode::SOUND);
    }
    
    template<typename T>
    auto set_duration(T&& x) {
        duration = x * 10;
        set_mode(mode::SOUND);
    }
};

} // namespace sound

#endif
