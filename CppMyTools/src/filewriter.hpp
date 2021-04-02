#include <cstdio>

class FileWriter
{
public:
	FileWriter() : m_fp(nullptr)
	{

	}
	~FileWriter()
	{
		if (m_fp)
		{
			fclose(m_fp);
			m_fp = nullptr;
		}
	}

	FileWriter(const FileWriter&) = delete;
	FileWriter& operator=(const FileWriter&) = delete;

	bool OpenFile(const char* filepath)
	{
		if (m_fp) return false;

		m_fp = fopen(filepath, "wb");
		if (!m_fp)
		{
			return false;
		}
		return true;
	}

	bool Write(const char* data, size_t len)
	{
		if (!m_fp) return false;
		size_t nwrite = fwrite(data, len, 1, m_fp);
		return 1 == nwrite;
	}

private:
	FILE *m_fp;
};