#include "StreamInstance.hpp"

class StreamInstanceFile : public StreamInstance
{
public:
	StreamInstanceFile();
	virtual ~StreamInstanceFile();

	virtual bool Open(std::string fName);
	virtual bool IsFinished();
	virtual int Read(uint8_t* pBufferOut, int maxBytesToRead);
	virtual void Close();
	virtual void SeekFromStart(int byteCount);
protected:


private:
	FILE* m_fp;
};