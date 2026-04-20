#pragma once

#include <cstddef>
#include <vector>

#include "PiSubmarine/Control/Api/Input/OperatorCommand.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Control
{
    class ISerializer
    {
    public:
        virtual ~ISerializer() = default;

        [[nodiscard]] virtual Error::Api::Result<std::vector<std::byte>> Serialize(
            const Api::Input::OperatorCommand& command) const = 0;
    };
}
