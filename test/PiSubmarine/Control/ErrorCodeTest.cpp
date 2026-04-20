#include <gtest/gtest.h>

#include "PiSubmarine/Control/ErrorCode.h"

namespace PiSubmarine::Control
{
    TEST(ErrorCodeTest, ReportsReadableMessageForKnownError)
    {
        EXPECT_EQ(make_error_code(ErrorCode::InvalidPayload).message(), "invalid control payload");
    }
}
