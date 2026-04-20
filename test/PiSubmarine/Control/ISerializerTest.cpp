#include <type_traits>

#include <gtest/gtest.h>

#include "PiSubmarine/Control/ISerializer.h"

namespace PiSubmarine::Control
{
    TEST(ISerializerTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<ISerializer>);
    }
}
