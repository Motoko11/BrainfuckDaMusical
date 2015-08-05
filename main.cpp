#include <iostream>
#include "interpreter.hpp"
#include "sounds.hpp"
#include "generator.hpp"

auto main(int argc, char** argv) -> int {
    try {
        bf::run_program(
            "+[--->++<]>+++.[->+++++++<]>.++++++.---.[-->+++++<]>+++.---[->++++<]>-.++++[->+++<]>.+++++++.------.[--->+<]>--.+[->+++<]>.++++++++++++.-.++++++.--.---.---.[++>---<]>--.+[----->+<]>.------------.++++++++++.------.[--->+<]>----.+[---->+<]>+++.+[----->+<]>.--------.--[--->+<]>-.++[->+++<]>.-..+++++++.[++>---<]>--.[->+++<]>+.+++++++++++.+++.-.---------.>++++++++++.++[++++>---<]>.+[-->+<]>++.[->+++<]>+.+[->+++<]>.--[--->+<]>-.---[->++++<]>.--.---------.----.-.-[--->+<]>-.+[->+++<]>.++++++++++++.-.--------.+++.-----.+.+++++++++.-----------.++.-[->+++<]>.------------.-[--->++<]>--.-------.+++.-[--->+<]>-.-[--->++<]>-.+++++++++++.[---->+<]>+++.++[->+++<]>.+++++++++.+++.[-->+++++<]>+++.[->+++<]>++.[--->+<]>----.-------------.----.++++++++++.-----.-----.--[--->+<]>--.+.[---->+<]>+++.---[->++++<]>.-----.-----------.---.+[--->+<]>+++.>++++++++++.++[++++>---<]>.+[-->+<]>++.[->+++<]>+.+[->+++<]>.--[--->+<]>-.++[--->++<]>.+++.++++.+.[---->+<]>+++.---[->++++<]>.------------.---.--[--->+<]>-.[-->+++++++<]>.-----------.+++++++++++++.------------.-.--.-[--->+<]>--.-----------.++++++.-.[----->++<]>.------------.[->+++<]>+.-[->+++<]>.+[----->+<]>.--------.[--->+<]>----..+[---->+<]>+++.--[->++++<]>-.+[->+++<]>+.+++++++++++.------------.+++++++.++++++.-.[---->+<]>+++.--[->++++<]>-.--------.+++.--------------.--[--->+<]>---.>++++++++++.[->++++<]>.-[--->+++++<]>.[--->+<]>+++.----------.-[->+++<]>.---------.[->++<]>+.--[----->+<]>.+[---->+<]>+++.---[->++++<]>.------------.---.--[--->+<]>-.---[->++++<]>-.++++[->+++<]>.----.--[--->+<]>--.----.-.+++++.+[---->+<]>+++.+[->+++<]>.+++++.-------.+++++++++++++.-------.--.--[--->+<]>-.++++[->++<]>+.+[-->+<]>++.---[->+++<]>..[++>---<]>--.+[->+++<]>.++++++++++++.-.++++++.-----------.+++++.+++++++.++[->+++<]>.--[--->+<]>-.---[->++++<]>.-----.[--->+<]>-----.-[--->++<]>-.--.+++++++.+.+++.-------------.>++++++++++.>-[--->+<]>-.[---->+++++<]>-.---.--[--->+<]>-.-[--->++<]>-.++++.------------.++++++.--.--[--->+<]>-.++++[->++<]>+.-[->++++<]>.[-->+++++++<]>.++.---.-----.-----.--.-[--->+<]>--.[---->+<]>+++.--[-->+++<]>.[--->++<]>++.+[----->+<]>.--------.--[--->+<]>-.--[->++++<]>-.+[->+++<]>+.+++++++++++.------------.+++++++.++++++.-.[---->+<]>+++.+[----->+<]>.--------.>++++++++++.>-[--->+<]>-.[---->+++++<]>-.---.--[--->+<]>-.[-->+++++++<]>.-------.------.-[--->+<]>--.+.---.-------------.--[--->+<]>-.---[->++++<]>.------------.-------.--[--->+<]>-.[---->+<]>+++.++++[->++<]>+.-[->++++<]>.---[->++++<]>-.+++[->+++<]>+.--.+++++++++++++..---------.-.-[--->+<]>-.-[--->++<]>-.++++++++++.+[---->+<]>+++.[->+++<]>++.+++++++++++++.+++..---.++++++++.[->+++<]>.-.>++++++++++..+++[->+++++<]>.+++[-->+++<]>.-[--->+<]>---.+++[->+++<]>.+++++++++++++.[-->+++++<]>+++.---[->++++<]>.------------.---.--[--->+<]>-.+[->+++<]>++.-.--[--->+<]>-.+[->+++<]>+.--.--[--->+<]>-.-----------.++++++.-.-[->+++++<]>-.--[->++++<]>+.----------.++++++.-[---->+<]>+++.---[->++++<]>-.+.-----.+..-----------.-.-[--->+<]>-.+[----->+<]>.------------.++++++++++.--.+++++.-------.-[--->+<]>--.---[->++++<]>-.++++[->+++<]>.+++++++++.+++++.++++[->+++<]>.--[--->+<]>-.---[->++++<]>.-----.[--->+<]>-----.+[----->+<]>.--------.>++++++++++.>-[--->+<]>--.[----->+++<]>..++++++++.++++++.+[---->+<]>+++.---[->++++<]>.-----.[--->+<]>-----.+[----->+<]>.--------.--[--->+<]>-.---[->++++<]>.------------.-------.--[--->+<]>-.[---->+<]>+++.-[--->++<]>-.+++++++++++.+[--->+<]>.-[->+++<]>+.+[---->+<]>+++.[->+++<]>+.+++++++++++..[++>---<]>--.---[->++++<]>.------------.---.--[--->+<]>-.---[->++++<]>-.++[->+++<]>++.++++++++++++.--------.-[->+++<]>.------------.---[->++++<]>.-----------.++++.--------.--[--->+<]>-.[->+++<]>+.+++++++++++++.----------.-[--->+<]>-.---[->++++<]>.-----------.++++.--------.--[--->+<]>-.[->+++<]>+.++++++.------.++++++++.+++++.>++++++++++.>-[--->+<]>--.--[--->++++<]>.+++.++++++++.-----------.-[--->+<]>.-[-->+++++<]>.------------.[->+++<]>+.+++++++++++..[++>---<]>--.---[->++++<]>.------------.-------.--[--->+<]>-.[---->+<]>+++.++++[->++<]>+.-[->++++<]>.[->+++<]>++.+++.+++++++.---.----.[--->+<]>-.+[->+++<]>.-.-[--->+<]>-.-[--->++<]>-.+++++.[----->++<]>.------------.---[->++++<]>.+.---.----.-----.+++++.-------.-[--->+<]>--.-[--->++<]>-.+++++.++++++.-----.[--->+<]>-----.[->+++<]>+.-[->+++<]>.++[--->++<]>.---.----.>++++++++++.>-[--->+<]>-.-[--->+<]>--.[--->+<]>-----.[->+++<]>+.++++++++.++++.[->+++++<]>-.[->+++<]>+.+++++++++++++.----------.-[--->+<]>-.+[----->+<]>.----.++++++++++..-[++>---<]>+.------------.+[----->+<]>.--[--->+<]>.-[---->+<]>++.---[->++++<]>-.++.-----.-----------.+++++++++++++.----.-------------.--[--->+<]>-.+.---.+++[->+++<]>++.+++++++++++.[++>---<]>--.[->+++<]>+.--[--->+<]>---.++.>++++++++++.>-[--->+<]>--.[--->+<]>-.-----------.+++++++++.----------.+++++.+++++.-------.-[--->+<]>--.---[->++++<]>.-----.[--->+<]>-----.+[----->+<]>.++++++++.+[->+++<]>+.+++++.--[--->+<]>--.---[->++++<]>.-----------.++++.--------.--[--->+<]>-.--[->++++<]>-.+[->+++<]>+.+++++++++++.------------.--[--->+<]>--.+[----->+<]>.--[--->+<]>.------.++++[->+++<]>.+++++++.------.>++++++++++.>-[--->+<]>-.-[--->+<]>+.+++++++.[->+++<]>--.+++++.-------.-[--->+<]>--.---[->++++<]>.-----.[--->+<]>-----.+[->+++<]>++.[--->+<]>+.--------.----.-----------.++++++++.+++++.-----.+++++.-------.-[--->+<]>--.--[->++++<]>-.+[->+++<]>.+++++++.[--->+<]>-----.++++[->++<]>+.-[->++++<]>.[->+++<]>+.++++++++++++.>++++++++++..++[->++++++<]>.-[--->+<]>++.++++++++.+[---->+<]>++.+[->+++<]>.++++++++++++.--.--------.--[--->+<]>-.-[--->++<]>-.+++++++++++.+[--->+<]>.-[->+++<]>+.+[---->+<]>+++.[-->+++++++<]>.-.++++..----------.-------.++++++++++.-------.>++++++++++.++[++++>---<]>.-[->++++<]>.--[->++++<]>-.+[->+++<]>+.++++++++++.-----------.--[--->+<]>--.---[->++++<]>.------------.---.+++++++++++++.-------------.--[--->+<]>-.--[->++++<]>-.-[->+++<]>-.--[--->+<]>--.+[---->+<]>+++.[->+++<]>+.-[->+++<]>.--[->++++<]>-.-[->+++<]>-.+[--->+<]>+++.>++++++++++.[->++++<]>.+[->++<]>+.[--->+<]>++++.+[->+++<]>++..+.+++++++++.--.-[--->+<]>.-[--->+<]>+.---------.++++[->++<]>+.-[->++++<]>.++[->+++<]>.-..+++++++.[++>---<]>--.---[->++++<]>-.----.[--->+<]>-----.-[--->++<]>-.+++++.++++++++.[------>+<]>.+++++.-----------.++++++.-------.++++++++++.-------.>++++++++++.++[++++>---<]>.+[-->+<]>++.---[->+++<]>+.[->+++++<]>-.---[->++++<]>.------------.---.--[--->+<]>-.---[->++++<]>-.+++[->+++<]>+.-[--->+<]>-.---------.++++.++++.+.---.-------------.--[--->+<]>-.+[----->+<]>.------------.+++.+.--[--->+<]>-.+++++[->+++<]>.++++++.-.[---->+<]>+++.+++++[->+++<]>.---------.[--->+<]>--.+[->+++<]>.+++++++++.-----------.+[--->+<]>+++.>++++++++++..++[++++>---<]>.-[->++++<]>.+[----->+<]>+.---------..-.-[--->+<]>-.---[->++++<]>-.----.--.--------.++++++++++.-.---------.--[--->+<]>-.---[->++++<]>.-----.[--->+<]>-----.[->+++<]>++.[--->+<]>----.-------------.----.++++++++++.-[++>---<]>+.---[->++++<]>.------------.---.--[--->+<]>-.---[->++++<]>-.----------.+++.-------.+++++++++.-----------.++.>++++++++++.+[--->++++<]>--.+++.+.+++++++++.+++.-------------.--[--->+<]>-.-[--->++<]>-.+++++++++++.[---->+<]>+++.[->+++<]>+.+++++++++++..[++>---<]>--.++[->+++<]>.-----.+++++++++++..+++++++.+[---->+<]>+++.[->+++<]>+.-[++>-----<]>.[----->++<]>+.--[--->+<]>---.++.>++++++++++.++[++++>---<]>.-[->++++<]>.+[----->+<]>+.---------..-.-[--->+<]>-.---[->++++<]>-.----.--.--------.[--->+<]>---.------------.+.+++++.-------.-[--->+<]>--.---[->++++<]>.-----.[--->+<]>-----.+[->+++<]>.+++++++++.---.+++++.-------.-[--->+<]>--.+++++[->+++<]>.-.++++++.-----.>++++++++++.+[--->++++<]>--.+++.+.+++++++++.+++.-------------.--[--->+<]>-.++++[->++<]>+.-[->++++<]>.[->+++<]>++.[--->+<]>----.-------------.----.++++++++++.-[++>---<]>+.--[->++++<]>+.----------.++++++.-[---->+<]>+++.-[--->++<]>-.+++++.-[->+++++<]>-.[-->+++++++<]>.[----->++<]>+.--[--->+<]>---.++.-.>++++++++++..>-[--->+<]>--.[--->+<]>--.[--->+<]>-----.[->+++<]>+.+++++.++++++++++++.+++[->+++<]>++.++++++++.-----.-[--->+<]>-.+++++[->+++<]>.---------.[--->+<]>--.--[->++++<]>-.+[->+++<]>.-------.--[--->+<]>-.[---->+<]>+++.--[->++++<]>+.----------.++++++.-[---->+<]>+++.+[----->+<]>.------------.+[--->+<]>+++.-[---->+<]>++.---[->++++<]>.------------.+.+++++.---.>++++++++++.+++[->+++++<]>.[--->+<]>+++.----------.-[--->+<]>-.[->+++<]>+.+++++++++++..[++>---<]>--.---[->++++<]>.------------.---.--[--->+<]>-.[-->+++++++<]>.----.-----------.--[--->+<]>--.+.-----------.------.[--->+<]>-.[-->+++++++<]>.-----------.++++++++++.+.----.-------.--[--->+<]>-.---[->++++<]>.------------.-------.--[--->+<]>-.[---->+<]>+++.---[->++++<]>-.++.---..---.++++++.-------.----------.--[--->+<]>---.+[---->+<]>+++.+[----->+<]>.--------.>++++++++++.++[++++>---<]>.-[->++++<]>.-[--->++<]>--.-------.+[--->+<]>.+[->+++<]>.--[--->+<]>-.---[->++++<]>.-----.[--->+<]>-----.++[->+++<]>.+++.+++++.----------.-[--->+<]>-.---[->++++<]>.------------.---.--[--->+<]>-.[-->+++++++<]>.[----->++<]>+.--[--->+<]>-.------------.--[--->+<]>--.---[->++++<]>.-----.[--->+<]>-----.--[->++++<]>-.+[->+++<]>.---.+++++++++++++.-------------.--[--->+<]>-.-[--->++<]>-.+++++++++++.[---->+<]>+++.[->+++<]>+.+++++++++++..[++>---<]>--.[->+++<]>++.+++.++.++.+++++.+++++.>++++++++++.>-[--->+<]>-.-[--->+<]>--.[--->+<]>-----.---[->++++<]>.+++[->+++<]>.----.++.+++++.--[--->+<]>--.---[->++++<]>.------------.---.--[--->+<]>-.--[->++++<]>-.--------.+++.------.--------.-[--->+<]>-.+[----->+<]>.--[--->+<]>.-[---->+<]>++.---[->++++<]>-.++.-----.-----------.+++++++++++++.----.-------------.--[--->+<]>-.+.---.+++[->+++<]>++.+++++++++++.[++>---<]>--.[->+++<]>+.--[--->+<]>---.++.",
            sound::Engine{}
        );
        std::cout << std::endl;
    }
    catch(std::exception& ex) {
        std::cout << "\n\n" << ex.what() << std::endl;
    }
}