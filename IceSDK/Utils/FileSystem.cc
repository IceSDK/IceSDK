#include "pch.h"

#include "Utils/FileSystem.h"

#include <fstream>
#include <iterator>
#include <iostream>

#ifdef ICESDK_WIN32
#include <Windows.h>
#elif defined(ICESDK_LINUX) || defined(ICESDK_ANDROID)
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#elif defined(ICESDK_EMSCRIPTEN)
#include <emscripten.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#else
#error "Platform not implemented!"
#endif

using namespace IceSDK;

std::string FileSystem::JoinPath(const std::string &p1, const std::string &p2)
{
	if (p1.length() <= 0)
		return p2;

	if (p2.length() <= 0)
		return p1;

	if (p1[p1.length() - 1] == '/' ||
		p1[p1.length() - 1] == '\\')
		return p1 + p2;

	return p1 + "/" + p2;
}

bool FileSystem::Exists(const std::string &pPath)
{
#ifdef ICESDK_WIN32
	const auto dir_type = GetFileAttributesA(pPath.c_str());

	return dir_type != INVALID_FILE_ATTRIBUTES;
#elif defined(ICESDK_LINUX) || defined(ICESDK_EMSCRIPTEN) || defined(ICESDK_ANDROID)
	return (access(pPath.c_str(), F_OK) != -1);
#else
#error "Platform not implemented!"
#endif
	return false;
}

bool FileSystem::IsDirectory(const std::string &pPath)
{
	if (!Exists(pPath))
		return false;

#ifdef ICESDK_WIN32
	return GetFileAttributes(pPath.c_str()) & FILE_ATTRIBUTE_DIRECTORY;
#elif defined(ICESDK_LINUX) || defined(ICESDK_EMSCRIPTEN) || defined(ICESDK_ANDROID)
	struct stat st;
	stat(pPath.c_str(), &st);
	return S_ISDIR(st.st_mode);
#else
#error "Platform not implemented!"
#endif
	return false;
}

std::vector<std::string> FileSystem::ReadDirectory(const std::string &pPath, bool pRecursive /*= false */)
{
	std::vector<std::string> directories;

#if defined(ICESDK_WIN32)
	HANDLE hFind;
	WIN32_FIND_DATA FindFileData;

	// Requires a * wildcard for some reason
	if ((hFind = FindFirstFile(FileSystem::JoinPath(pPath.c_str(), "./*").c_str(), &FindFileData)) != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (std::string(FindFileData.cFileName) == "." ||
				std::string(FindFileData.cFileName) == "..")
				continue;

			directories.push_back(FileSystem::JoinPath(pPath, FindFileData.cFileName));
		} while (FindNextFile(hFind, &FindFileData));
		FindClose(hFind);
	}
#elif defined(ICESDK_LINUX) || defined(ICESDK_EMSCRIPTEN) || defined(ICESDK_ANDROID)
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(pPath.c_str())) != nullptr)
	{
		while ((ent = readdir(dir)) != nullptr)
		{
			if (std::string(ent->d_name) == "." ||
				std::string(ent->d_name) == "..")
				continue;

			directories.push_back(FileSystem::JoinPath(pPath, ent->d_name));
		}
		closedir(dir);
	}
#else
#error "Platform not implemented!"
#endif

	if (pRecursive && !directories.empty())
	{
		for (const auto &_dir : directories)
		{
			if (FileSystem::IsDirectory(_dir))
			{
				for (const auto &__dir : ReadDirectory(_dir, true))
				{
					directories.push_back(__dir);
				}
			}
		}
	}

	return directories;
}

std::string FileSystem::ResolveFullPath(const std::string &pPath)
{
#ifdef ICESDK_WIN32
	char buffer[4096];
	if (
		IS_ERROR(GetFullPathNameA(pPath.c_str(),
								  4096,
								  buffer,
								  nullptr)))
		return "";

	return buffer;
#elif defined(ICESDK_LINUX) || defined(ICESDK_EMSCRIPTEN) || defined(ICESDK_ANDROID)
	char buffer[PATH_MAX + 1];

	realpath(pPath.c_str(), buffer);

	return std::string(buffer);
#else
#error "Platform not implemented!"
#endif
	return "";
}

std::vector<uint8_t> FileSystem::ReadBinaryFile(const std::string &pPath)
{
	std::ifstream file(pPath, std::ios::binary | std::ios::in);
	if (file.fail())
		return {};

	file.unsetf(std::ios::skipws); // Read the file properly!

	file.seekg(0, std::ios::end);
	const auto fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	if (fileSize <= 0)
		return {};

	std::vector<uint8_t> data;
	data.reserve(fileSize);

	data.insert(data.begin(),
				std::istream_iterator<uint8_t>(file),
				std::istream_iterator<uint8_t>());

	return data;
}

void FileSystem::WriteBinaryFile(const std::string &pPath, std::vector<uint8_t> pData)
{
	std::ofstream file(pPath, std::ios::binary | std::ios::out);
	if (!file)
		std::cout << "Failed to open " << pPath << std::endl;

	file.unsetf(std::ios::skipws);

	file.write(reinterpret_cast<const char *>(&pData[0]), pData.size());
	file.close();

#if defined(ICESDK_LINUX) || defined(ICESDK_EMSCRIPTEN) || defined(ICESDK_ANDROID)
	chmod(pPath.c_str(), umask(0755)); // set the correct permissions cause it's wrong
#endif
}

bool FileSystem::HasExtension(const std::string &pPath, const std::string &pExt)
{
	if (pPath.length() < pExt.length())
		return false;

	return (0 == pPath.compare(pPath.length() - pExt.length(), pExt.length(), pExt));
}

void FileSystem::MkDir(const std::string &pPath)
{
#ifdef ICESDK_WIN32
	CreateDirectory(pPath.c_str(), NULL);
#elif defined(ICESDK_LINUX) || defined(ICESDK_EMSCRIPTEN) || defined(ICESDK_ANDROID)
	if (mkdir(pPath.c_str(), umask(0755)))
	{
		std::cout << "Failed to create Directory! " << pPath << std::endl;
	}

	chmod(pPath.c_str(), umask(0755)); // set the correct permissions cause it's wrong for some reason
#else
#error "Platform not implemented!"
#endif
}

#include <iostream>

std::string FileSystem::GetFileName(const std::string &pPath)
{
	for (auto i = pPath.size(); i > 0; --i)
		if (pPath[i] == '/' || pPath[i] == '\\')
			return std::string(pPath.begin() + (i + 1), pPath.end());

	return pPath; // Not found...
}

void FileSystem::Touch(const std::string &pPath)
{
	WriteBinaryFile(pPath, {});
}
