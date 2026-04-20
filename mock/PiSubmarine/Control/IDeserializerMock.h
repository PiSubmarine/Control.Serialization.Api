#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/IDeserializer.h"

namespace PiSubmarine::Control
{
    class IDeserializerMock : public IDeserializer
    {
    public:
        using ByteView = std::span<const std::byte>;

        MOCK_METHOD(
            (Error::Api::Result<Api::Input::OperatorCommand>),
            Deserialize,
            ((ByteView bytes)),
            (const, override));
    };
}
