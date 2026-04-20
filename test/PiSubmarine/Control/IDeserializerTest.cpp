#include <type_traits>

#include <gtest/gtest.h>

#include "PiSubmarine/Control/IDeserializer.h"

namespace PiSubmarine::Control
{
    TEST(IDeserializerTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<IDeserializer>);
    }
}
