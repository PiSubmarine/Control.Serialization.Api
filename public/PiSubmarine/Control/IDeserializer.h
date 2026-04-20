#pragma once

#include <cstddef>
#include <span>

#include "PiSubmarine/Control/Api/Input/OperatorCommand.h"
#include "PiSubmarine/Error/Api/Result.h"

namespace PiSubmarine::Control
{
    class IDeserializer
    {
    public:
        virtual ~IDeserializer() = default;

        [[nodiscard]] virtual Error::Api::Result<Api::Input::OperatorCommand> Deserialize(
            std::span<const std::byte> bytes) const = 0;
    };
}
