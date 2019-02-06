#include "./testsuit.h"

#include <service/property.hpp>




TEST_CASE("Testing properties for simple types"){

    using namespace cppproperties;

    SUBCASE("Testing rw property"){
    
        property<int> prop_int;

        prop_int = 11;

        CHECK(prop_int.get() == 11);
        CHECK(11 == prop_int);
        CHECK(prop_int == 11);

        int val = 42;
        prop_int.set(val);

        CHECK(prop_int.get() == val);
        CHECK(val == prop_int);
        CHECK(prop_int == val);
    }

    SUBCASE("Testing const rw property"){

        const property<int> prop_int(42);

        CHECK(prop_int.get() == 42);
        CHECK(42 == prop_int);
        CHECK(prop_int == 42);
    }

    SUBCASE("Testing ro property of const"){

        property<const int> prop_int(42);

        CHECK(prop_int.get() == 42);
        CHECK(42 == prop_int);
        CHECK(prop_int == 42);
    }

    SUBCASE("Testing ro property"){

        property<int, property<>::ro> prop_int(42);

        CHECK(prop_int.get() == 42);
        CHECK(42 == prop_int);
        CHECK(prop_int == 42);

        property<const int> 
            prop_cint(42),
            prop_cint2(prop_int + 1);

        CHECK(prop_cint == prop_int);
        CHECK(prop_int == prop_cint);
        CHECK_FALSE(prop_int > prop_cint);

        CHECK(prop_cint2 > prop_int);
        CHECK(prop_cint2 != prop_int);
        CHECK(prop_int != prop_cint2);
    }
}