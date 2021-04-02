#pragma once

#include <memory>

class Buffer
{
    static const int INIT_SZ = 1024;
public:
    explicit Buffer(int sz = INIT_SZ) {
        if (sz > INIT_SZ)
        {
            buffer = std::unique_ptr<char[]>(new char[sz]{});
            m_size = sz;
        }
    }
    char *Data()
    {
        return const_cast<char*>(static_cast<const Buffer*>(this)->Data());
    }
    const char *Data() const
    {
        return buffer ? buffer.get() : rawbuffer;
    }

    int Size() const { return m_size; }

    void Reallocate()
    {
        char *new_buffer = new char[2 * m_size]{};
		memcpy(new_buffer, Data(), m_size);
        buffer.reset(new_buffer);
		m_size *= 2;
    }

private:
    char rawbuffer[INIT_SZ] {};
    std::unique_ptr<char[]> buffer;
    int m_size = INIT_SZ;
};