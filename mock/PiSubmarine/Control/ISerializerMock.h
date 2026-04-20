#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Control/ISerializer.h"

namespace PiSubmarine::Control
{
    class ISerializerMock : public ISerializer
    {
    public:
        MOCK_METHOD(
            (Error::Api::Result<std::vector<std::byte>>),
            Serialize,
            ((const Api::Input::OperatorCommand& command)),
            (const, override));
    };
}
