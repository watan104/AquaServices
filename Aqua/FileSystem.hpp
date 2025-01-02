#pragma once
#include <cstdint>
#include <string>
#include "StreamInstance.hpp"

class StreamInstance;
class FileSystem
{
public:
	FileSystem();
	virtual ~FileSystem();

	virtual uint8_t* Get(std::string fileName, int* pSizeOut) = 0;
	virtual StreamInstance* GetStreaming(std::string fileName, int* pSizeOut) = 0;
	virtual bool FileExists(std::string fileName) = 0;
	virtual int GetFileSize(std::string fileName) = 0;
};