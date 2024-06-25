#pragma once
#include <iostream>

namespace Color {
    enum Code {
        FG_RED     = 31,
        FG_GREEN   = 32,
        FG_BLUE    = 34,
        FG_GRAY    = 97,
        FG_YELLOW  = 33,
        FG_DEFAULT = 39,
    };

    class Modifier {
        Code code;

      public:
        Modifier (Code pCode) : code (pCode) {}
        friend std::ostream& operator<< (std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
} // namespace Color


namespace Log {
    inline Color::Modifier red (Color::FG_RED);
    inline Color::Modifier yellow (Color::FG_YELLOW);
    inline Color::Modifier green (Color::FG_GREEN);
    inline Color::Modifier gray (Color::FG_GRAY);
    inline Color::Modifier normal (Color::FG_DEFAULT);

    inline void Print (std::string string) {
        std::cout << gray << "  [LOG] " << normal << string << std::endl;
    }

    inline void Ok (std::string string) {
        std::cout << green << "   [OK] " << normal << string << std::endl;
    }

    inline void Warn (std::string string) {
        std::cout << yellow << " [WARN] " << normal << string << std::endl;
    }

    inline void Error (std::string string) {
        std::cout << red << "[ERROR] " << normal << string << std::endl;
    }
} // namespace Log
