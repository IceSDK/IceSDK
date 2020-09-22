#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Memory/GarbageCollector.h"

#include "Utils/Logger.h"

TEST(GarbageCollector, Collect)
{
    IceSDK::Log::Init();

    IceSDK::Memory::GarbageCollector GC{};

    {
        auto testPtr = GC.Allocate<uint64_t>();

        (*testPtr) = 0x1337;

        ASSERT_EQ(*testPtr, 0x1337);
    } // Ptr goes out of scope

    auto collected = GC.Collect(); // Ptr should be collected by this call...
    ASSERT_EQ(collected, 1);
}