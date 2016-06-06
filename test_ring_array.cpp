/*#include <iostream>
#include "ring_array.h"

#include <cassert>
#include <cmath>

// -----------------------------------------------------------------------------
// advanced assert
// -----------------------------------------------------------------------------

#define EXPECT_EQ( X , Y )                            \
{                                                     \
    auto x = X;                                       \
    auto y = Y;                                       \
    if ( !(x == y) ) {                                \
        std::cerr << std::boolalpha                   \
        << "! assertion failed in line " << __LINE__  \
        << ": expected " << x                         \
        << ", got " << y << std::endl;                \
    }                                                 \
    else                                              \
        std::cout << "test passed:  "                 \
                  << #X " == " << #Y << std::endl;    \
}                                                     \

int main()
{
    ring_array<int> ring(5);

    EXPECT_EQ( 5 , ring.size() );

    ring.push(1337);
    ring.push(  42);
    ring.push( 042);
    ring.push(9876);
    ring.push(1234);

    EXPECT_EQ( 5 , ring.size() );

    EXPECT_EQ( 1337 , ring[0]  );
    EXPECT_EQ(   42 , ring[1]  );
    EXPECT_EQ(  042 , ring[2]  );
    EXPECT_EQ(  042 , ring[-3] );
    EXPECT_EQ( 9876 , ring[-2] );
    EXPECT_EQ( 1234 , ring[-1] );

    auto ring2 = ring;

    ring2.push(10101);

    EXPECT_EQ( 1337 , ring[0]  );
    EXPECT_EQ(   42 , ring[1]  );
    EXPECT_EQ(  042 , ring[2]  );

    auto const & cring2 = ring2;

    EXPECT_EQ(   42 , cring2[0]  );
    EXPECT_EQ(  042 , cring2[1]  );
    EXPECT_EQ( 9876 , cring2[2]  );
    EXPECT_EQ( 9876 , cring2[-3] );
    EXPECT_EQ( 1234 , cring2[-2] );
    EXPECT_EQ(10101 , cring2[-1] );

    std::cout << " ---- " << std::endl;

    ring.resize(3);
    EXPECT_EQ( 3 , ring.size() );

    EXPECT_EQ(  042 , ring[0]  );
    EXPECT_EQ( 9876 , ring[1]  );
    EXPECT_EQ( 1234 , ring[2]  );
    EXPECT_EQ(  042 , ring[-3] );
    EXPECT_EQ( 9876 , ring[-2] );
    EXPECT_EQ( 1234 , ring[-1] );

    ring.resize(17);
    EXPECT_EQ( 17 , ring.size() );

    EXPECT_EQ(  042 , ring[-3] );
    EXPECT_EQ( 9876 , ring[-2] );
    EXPECT_EQ( 1234 , ring[-1] );

    std::cout << "End of tests --------------------" << std::endl;

    return 0;
}*/