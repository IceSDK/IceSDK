#include "pch.h"

#include "Memory/Allocator.h"

using namespace IceSDK;
using namespace IceSDK::Memory;

static std::vector<Block> _blocks{}; // to keep track of all blocks

Block Memory::Create(size_t pBlockSize, BlockFlags pBlockFlags, bool pDirty)
{
    if (pBlockSize == 0)
        return nullptr; // Invalid memory block

    uintptr_t block = sizeof(size_t) + (uintptr_t)malloc(sizeof(size_t) + pBlockSize + 0x40);
    size_t *blockSize = (size_t *)(block - sizeof(size_t));
    BlockMetaData *metaData = (BlockMetaData *)(block + pBlockSize);

    (*blockSize) = pBlockSize;

    metaData->Begin = block;
    metaData->Flags = pBlockFlags;
    memset(metaData->_, NULL, 0x30);

    if (pDirty == false)
        memset((Block)block, NULL, pBlockSize);

    return (Block)block;
}

void Memory::Delete(Block *ppMemory)
{
    if (ppMemory == nullptr)
        return;
    if (*ppMemory == nullptr)
        return;

    free((*ppMemory) - sizeof(size_t));

    *ppMemory = nullptr; // Make sure we unset it's pointer
}
