#pragma once

#include <cstdint>

namespace IceSDK::Memory
{
    // 64 flags should be enough
    enum BlockFlags : uint64_t
    {
        None = 0,
        NoGC = 1 << 0, // Disable GC for this block of memory
    };

    /*
    MemoryBlock: {
        Data = [0..]

        # Allocate further 64 bytes for meta data
        Size           = 0x00
        Flags          = 0x08
        End            = 0x40
    }
    */
    union BlockMetaData
    {
        /* 0x00 */ uint64_t Begin; // End can be calculated using Begin + Size
        /* 0x08 */ uint64_t Flags;

        // Make sure MemoryBlockMetaData is always 64 Bytes big
        uint8_t _[0x30];
    };

    typedef uint8_t *Block;

    /*
        if pDirty is true, we don't set it's memory to 0
    */
    Block Create(
        size_t pBlockSize,
        BlockFlags pBlockFlags = BlockFlags::None,
        bool pDirty = false);

    inline Block Create(
        size_t pBlockSize,
        bool pDirty)
    {
        return Create(pBlockSize, BlockFlags::None, pDirty);
    }

    inline size_t GetBlockSize(Block block)
    {
        uintptr_t blockPtr = (uintptr_t)block;
        uintptr_t blockSizePtr = blockPtr - sizeof(size_t);

        return *((size_t *)(blockSizePtr));
    }

    inline BlockMetaData *GetMetaData(Block block)
    {
        auto blockSize = GetBlockSize(block);

        return (BlockMetaData *)(block + blockSize);
    }

    void Delete(Block *ppMemory);
} // namespace IceSDK::Memory
