#pragma once

#include <string>
#include <vector>

namespace IceSDK
{
	namespace FileSystem
	{
		void MkDir(const std::string &pPath);
		std::string JoinPath(const std::string &p1, const std::string &p2);
		bool Exists(const std::string &pPath);
		bool IsDirectory(const std::string &pPath);
		std::vector<std::string> ReadDirectory(const std::string &pPath, bool pRecursive = false);
		std::string ResolveFullPath(const std::string &pPath);
		std::vector<uint8_t> ReadBinaryFile(const std::string &pPath);
		void WriteBinaryFile(const std::string &pPath, std::vector<uint8_t> pData);
		bool HasExtension(const std::string &pPath, const std::string &pExt);
		std::string GetFileName(const std::string &pPath);
		void Touch(const std::string &pPath);
		void Delete(const std::string &pPath);
	} // namespace FileSystem
} // namespace IceSDK
