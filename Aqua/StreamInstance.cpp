#include "StreamInstance.hpp"

StreamInstance::StreamInstance()
{
	//
}

StreamInstance::~StreamInstance()
{
	//
}

bool StreamInstance::ReadLineOfText(std::string& textOut)
{
	textOut.clear();

	if (IsFinished())
	{
		return false;
	}

	char buffer[4048];
	int cur = 0;

	while (1)
	{
		if (!Read((uint8_t*)&buffer[cur], 1))
		{
			buffer[cur] = 0;
			textOut = buffer;
			if (cur == 0) return false;
			return true;
		}
		if (buffer[cur] == '\r')
		{
			continue;
		}
		if (buffer[cur] == '\n')
		{
			buffer[cur] = 0;
			textOut = buffer;
			return true;
		}

		cur++;
	}

}


bool StreamInstance::ReadLineOfText(char* buffer, int bufferSize)
{

	if (IsFinished())
	{
		return false;
	}

	int cur = 0;

	while (1)
	{
		if (!Read((uint8_t*)&buffer[cur], 1))
		{
			buffer[cur] = 0;

			if (cur == 0)
			{
				return false;
			}

			return true;
		}

		if (buffer[cur] == '\r')
		{
			continue;
		}

		if (buffer[cur] == '\n')
		{
			buffer[cur] = 0;
			return true;
		}

		cur++;
		if (bufferSize <= cur)
		{
			buffer[cur] = 0;
			return true;
		}

	}

}

void StreamInstance::SeekFromStart(int byteCount)
{
}

int32_t StreamInstance::ReadInt32()
{
	int tmp;
	Read((uint8_t*)&tmp, sizeof(int32_t));
	return tmp;
}

float StreamInstance::ReadFloat32()
{
	float tmp;
	Read((uint8_t*)&tmp, sizeof(int32_t));
	return tmp;
}
