#include <iostream>
#include <string_view>

#define MAKE_CONVERTION_FUNCTION 1 // Unless defined convertion function will not be created

#include "enum.h"
#include "valued_enum.h"

MAKE_ENUM(en, uint32_t, A, B, C);
MAKE_VALUED_ENUM(ven, int, A, 3, B, -13, C, 32);

int main(int argc, char** argv)
{
    using namespace std::literals;

    constexpr en en_val = en::B;
    constexpr std::string_view en_sv = en_to_sv(en_val);
    constexpr ven ven_val = ven::C;
    constexpr std::string_view ven_sv = ven_to_sv(ven_val);
    
    static_assert(static_cast<uint32_t>(en_val) == 1);
    static_assert(en_sv == "B"sv);
    static_assert(static_cast<int>(ven_val) == 32);
    static_assert(ven_sv == "C = 32"sv);

    std::cout 
	<< static_cast<uint32_t>(en_val) << ' '
    	<< en_sv << ' '
    	<< static_cast<int>(ven_val) << ' '
    	<< ven_sv << std::endl;
    return 0;
}
