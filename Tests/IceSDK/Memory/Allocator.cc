#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Memory/Allocator.h"

#include "vector"

TEST(Allocator, Create)
{
    auto cleanMemory = IceSDK::Memory::Create(0x400);
    auto dirtyMemory = IceSDK::Memory::Create(0x400, true);

    ASSERT_FALSE(cleanMemory == nullptr);
    ASSERT_FALSE(dirtyMemory == nullptr);

    uint8_t empty[0x400];
    memset(empty, 0, 0x400);

    auto block = std::vector<uint8_t>((uint8_t *)cleanMemory, (uint8_t *)cleanMemory + 0x400);

    bool isDirty = false;
    for (size_t i = 0; i < IceSDK::Memory::GetBlockSize(dirtyMemory); i++)
    {
        if (dirtyMemory[i] != empty[i])
        {
            isDirty = true;
            break;
        }
    }

    ASSERT_TRUE(isDirty);
    ASSERT_THAT(block, testing::ElementsAreArray(empty));

    IceSDK::Memory::Delete(&cleanMemory);
    IceSDK::Memory::Delete(&dirtyMemory);
}

TEST(Allocator, GetBlockSize)
{
    auto cleanMemory = IceSDK::Memory::Create(0x400);
    ASSERT_FALSE(cleanMemory == nullptr);

    ASSERT_EQ(0x400, IceSDK::Memory::GetBlockSize(cleanMemory));

    IceSDK::Memory::Delete(&cleanMemory);
}
