#pragma once

#include "Memory/Allocator.h"

#include "Utils/Logger.h"

namespace IceSDK::Memory
{
    template <typename T>
    class sPtr
    {
    public:
        sPtr(Block block)
        {
            this->_block = block;

            if (this->_block != nullptr)
            {
                this->_blockMeta = GetMetaData(this->_block);
                this->_blockMeta->RefCount += 1;
            }
        }

        ~sPtr()
        {
            if (_block == nullptr)
                return;

            _blockMeta->RefCount -= 1;
        }

        T *operator->() const
        {
            return (T)_block;
        }

        T &operator*() const
        {
            return *((T *)_block);
        }

        T *get()
        {
            return (T *)_block;
        }

    private:
        Block _block;
        BlockMetaData *_blockMeta;
    };

    class GarbageCollector
    {
    public:
        GarbageCollector() = default;
        ~GarbageCollector()
        {
            this->Collect();
        }

        template <typename T>
        sPtr<T> Allocate(bool pDirty = false)
        {
            auto block = Memory::Create(sizeof(T), pDirty);
            auto ptr = sPtr<T>(block);

            this->_blocks.push_back(block);

            return ptr;
        }

        // Collects the unused garbage
        size_t Collect()
        {
            std::vector<std::tuple<size_t, Block>> ToDelete;

            size_t i = 0;
            for (auto &&block : this->_blocks)
            {
                auto meta = Memory::GetMetaData(block);
                if (meta->RefCount == 0)
                    ToDelete.push_back({i, block});

                i += 1;
            }

            // We gotta go backwards now.
            // so we don't fuck up our indices.
            for (int i = ToDelete.size() - 1; i >= 0; i--)
            {
                auto [index, block] = ToDelete.at(i);

                this->_blocks.erase(this->_blocks.begin() + index);

                Memory::Delete(&block);
            }

            ICESDK_CORE_TRACE("Collected {} Blocks", ToDelete.size());

            return ToDelete.size();
        }

    private:
        std::vector<Block> _blocks{};
    };

} // namespace IceSDK::Memory
