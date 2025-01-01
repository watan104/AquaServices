#include "StreamInstanceFile.hpp"
#pragma warning(disable : 4996)

StreamInstanceFile::StreamInstanceFile() : m_fp(NULL)
{
	//
}

StreamInstanceFile::~StreamInstanceFile()
{
	Close();
}

void StreamInstanceFile::Close()
{
	if (!m_fp)
	{
		return;
	}

	fclose(m_fp);
	m_fp = NULL;
}

bool StreamInstanceFile::Open(std::string fName)
{
	Close();
	m_fp = fopen(fName.c_str(), "rb");

	return m_fp != NULL;
}

int StreamInstanceFile::Read(uint8_t* pBufferOut, int maxBytesToRead)
{
	if (!m_fp)
	{
		return 0;
	}

	int bytesRead = (int)fread(pBufferOut, 1, maxBytesToRead, m_fp);
	return bytesRead;
}

bool StreamInstanceFile::IsFinished()
{
	if (!m_fp)
	{
		return true;
	}

	return feof(m_fp) != 0;
}

void StreamInstanceFile::SeekFromStart(int byteCount)
{
	if (!m_fp)
	{
		return;
	}

	fseek(m_fp, byteCount, SEEK_SET);
}