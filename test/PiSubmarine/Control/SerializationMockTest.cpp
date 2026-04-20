#include <array>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "PiSubmarine/Control/IDeserializerMock.h"
#include "PiSubmarine/Control/ISerializerMock.h"

namespace PiSubmarine::Control
{
    TEST(SerializationMockTest, SerializerMockCanReturnBytes)
    {
        ISerializerMock serializer;
        Api::Input::OperatorCommand command{};
        const std::vector<std::byte> payload{std::byte{0x01}, std::byte{0x02}};

        EXPECT_CALL(serializer, Serialize(testing::Eq(command)))
            .WillOnce(testing::Return(Error::Api::Result<std::vector<std::byte>>(payload)));

        const auto result = serializer.Serialize(command);
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(*result, payload);
    }

    TEST(SerializationMockTest, DeserializerMockCanReturnCommand)
    {
        IDeserializerMock deserializer;
        const std::array<std::byte, 2> payload{std::byte{0xAA}, std::byte{0xBB}};
        Api::Input::OperatorCommand command{};

        EXPECT_CALL(deserializer, Deserialize(testing::ElementsAreArray(payload)))
            .WillOnce(testing::Return(Error::Api::Result<Api::Input::OperatorCommand>(command)));

        const auto result = deserializer.Deserialize(std::span<const std::byte>(payload));
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(*result, command);
    }
}
