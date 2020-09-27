#pragma once

#include <string>
#include <vector>

namespace IceSDK
{
    namespace FileSystem
    {
        void MkDir(std::string_view pPath);
        std::string JoinPath(std::string_view p1, std::string_view p2);
        bool Exists(std::string_view pPath);
        bool IsDirectory(std::string_view pPath);
        std::vector<std::string> ReadDirectory(std::string_view pPath,
                                               bool pRecursive = false);
        std::string ResolveFullPath(std::string_view pPath);
        std::vector<uint8_t> ReadBinaryFile(std::string_view pPath);
        void WriteBinaryFile(std::string_view pPath,
                             const std::vector<uint8_t>& pData);
        bool HasExtension(std::string_view pPath, std::string_view pExt);
        std::string_view GetFileName(std::string_view pPath);
        void Touch(std::string_view pPath);
        void Delete(std::string_view pPath);
    }  // namespace FileSystem
}  // namespace IceSDK
