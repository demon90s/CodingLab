#pragma once

#include <cstring>
#include <stdexcept>

class Serializer
{
	static const int DEFAULT_LEN = 1024;

public:
	Serializer() :
		m_len(DEFAULT_LEN),
		m_rawbuffer{},
		m_userbuffer(nullptr),
		m_buffer(nullptr),
		m_cur_pos(m_rawbuffer)
	{
	}
	~Serializer()
	{
		if (m_buffer) delete []m_buffer;
	}

	void ResetPos()
	{
		m_cur_pos = CurBuffer();
	}

	void SetUserBuffer(char *userbuffer, int len)
	{
		m_userbuffer = userbuffer;
		m_len = len;
		m_cur_pos = m_userbuffer;
	}

	// 当前序列化缓冲区中的数据长度
	int Size() const
	{
		return static_cast<int>(m_cur_pos - CurBuffer());
	}

	// 缓冲区地址
	const char *Ptr() const
	{
		return CurBuffer();
	}

	// 写位置
	const char *WritePos() const
	{
		return m_cur_pos;
	}

	template<typename T>
	void Write(const T &v)
	{
		WriteData((const char *)&v, sizeof(v));
	}

	template<typename T, typename... Args>
	void Write(const T &v, const Args &... rest)
	{
		Write(v);
		Write(rest...);
	}

	void WriteData(const char *data, int len)
	{
		while (m_cur_pos - CurBuffer() + len > m_len)
		{
			ReAllocate();
		}
		memcpy(m_cur_pos, data, len);
		m_cur_pos += len;
	}

private:
	// 拒绝拷贝
	Serializer(const Serializer &) = delete;
	Serializer &operator=(const Serializer &) = delete;

	const char *CurBuffer() const
	{
		if (m_userbuffer) return m_userbuffer;
		else if (m_buffer) return m_buffer;
		else return m_rawbuffer;
	}
	char *CurBuffer()
	{
		return const_cast<char *>(static_cast<const Serializer *>(this)->CurBuffer());
	}

	void ReAllocate()
	{
		if (m_userbuffer)
		{
			throw std::runtime_error("userbuffer out of memory");
		}
		char *new_buffer = new char[2 * m_len] {};
		memcpy(new_buffer, CurBuffer(), m_len);
		m_cur_pos = new_buffer + Size();
		delete[]m_buffer;
		m_buffer = new_buffer;
		m_len *= 2;
	}

	int m_len;						// buffer长度
	char m_rawbuffer[DEFAULT_LEN];	// 初始buffer，用完才用heap memory
	char *m_userbuffer;				// 用户提供的buffer
	char *m_buffer;					// 用于存储序列化数据的缓冲区，自动增长
	char *m_cur_pos;				// 当前序列化的位置
};

class DeSerializer
{
public:
	enum class State { Fail = 0, Eof = 1, };
	enum class FetchResult { Succ = 0, Fail = 1, Eof = 2, Overflow = 3, };

	DeSerializer(const char *buffer, int len) :
		m_max_len(len),
		m_buffer(buffer),
		m_cur_pos(m_buffer),
		m_state_flag(0) {}

	explicit operator bool() const
	{
		return m_state_flag == 0;
	}

	template<typename T>
	void Read(T &v)
	{
		ReadData((char *)&v, sizeof(v));
	}

	template<typename T, typename... Args>
	void Read(T &v, Args &... rest)
	{
		Read(v);
		Read(rest...);
	}

	void Jump(int offset)
	{
		m_cur_pos += offset;
	}

	const char *ReadPos() const
	{
		return m_cur_pos;
	}

	// 抓取但不读取数据
	FetchResult FetchData(char *data, int len)
	{
		if (m_state_flag != 0)
		{
			return FetchResult::Fail;
		}

		if (m_cur_pos - m_buffer == m_max_len)
		{
			return FetchResult::Eof;
		}

		if (m_cur_pos - m_buffer + len > m_max_len)
		{
			return FetchResult::Overflow;
		}

		memcpy(data, m_cur_pos, len);
		return FetchResult::Succ;
	}

	void ReadData(char *data, int len)
	{
		FetchResult res = this->FetchData(data, len);

		switch (res)
		{
		case FetchResult::Fail:
		{
		}
		break;

		case FetchResult::Eof:
		{
			m_state_flag |= (1 << static_cast<int>(State::Eof));
		}
		break;

		case FetchResult::Overflow:
		{
			this->SetFailState();
			throw std::overflow_error("DeSerializer::ReadData failed: no more data to read");
		}
		break;

		case FetchResult::Succ:
		{
			m_cur_pos += len;
		}
		break;
		}
	}

	bool Fail() const
	{
		return m_state_flag & (1 << static_cast<int>(State::Fail));
	}

	bool Eof() const
	{
		return m_state_flag & (1 << static_cast<int>(State::Eof));
	}

	void SetFailState()
	{
		m_state_flag |= (1 << static_cast<int>(State::Fail));
	}

private:
	DeSerializer(const DeSerializer &) = delete;
	DeSerializer &operator=(const DeSerializer &) = delete;

	const int m_max_len;			// buffer最大长度
	const char *const m_buffer;		// 用于反序列化数据的缓冲区
	const char *m_cur_pos;			// 当前反序列化的位置
	unsigned int m_state_flag;		// 状态标记
};

inline Serializer &operator<<(Serializer &s, signed char v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, signed char &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, unsigned char v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, unsigned char &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, short v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, short &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, unsigned short v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, unsigned short &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, int v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, int &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, unsigned int v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, unsigned int &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, long long v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, long long &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, unsigned long long v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, unsigned long long &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, float v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, float &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, double v)
{
	s.Write(v);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, double &v)
{
	d.Read(v);
	return d;
}

inline Serializer &operator<<(Serializer &s, const char *v)
{
	int len = static_cast<int>(strlen(v));
	s << len;
	s.WriteData(v, len);
	return s;
}
inline DeSerializer &operator>>(DeSerializer &d, char *v)
{
	int len = 0;
	d.Read(len);
	d.ReadData(v, len);
	return d;
}

#include <string>
Serializer &operator<<(Serializer &s, const std::string &v);
DeSerializer &operator>>(DeSerializer &d, std::string &v);

#include <vector>
template<typename T>
Serializer &operator<<(Serializer &s, const std::vector<T> &v)
{
	int len = static_cast<int>(v.size());
	s << len;
	for (const auto &item : v)
	{
		s << item;
	}
	return s;
}

template<typename T>
DeSerializer &operator>>(DeSerializer &d, std::vector<T> &v)
{
	int len = 0;
	d >> len;
	for (int i = 0; i < len; i++)
	{
		T item {};
		if (d >> item)
			v.push_back(item);
	}
	return d;
}

#include <list>
template<typename T>
Serializer &operator<<(Serializer &s, const std::list<T> &v)
{
	int len = static_cast<int>(v.size());
	s << len;
	for (const auto &item : v)
	{
		s << item;
	}
	return s;
}

template<typename T>
DeSerializer &operator>>(DeSerializer &d, std::list<T> &v)
{
	int len = 0;
	d >> len;
	for (int i = 0; i < len; i++)
	{
		T item {};
		if (d >> item)
			v.push_back(item);
	}
	return d;
}

#include <map>
template<typename K, typename V>
Serializer &operator<<(Serializer &s, const std::map<K, V> &v)
{
	int len = static_cast<int>(v.size());
	s << len;
	for (const auto &p : v)
	{
		s << p.first << p.second;
	}
	return s;
}

template<typename K, typename V>
DeSerializer &operator>>(DeSerializer &d, std::map<K, V> &v)
{
	int len = 0;
	d >> len;
	for (int i = 0; i < len; i++)
	{
		K key;
		V value;
		d >> key >> value;
		v[key] = value;
	}
	return d;
}

#include <set>
template<typename K>
Serializer &operator<<(Serializer &s, const std::set<K> &v)
{
	int len = static_cast<int>(v.size());
	s << len;
	for (const auto &item : v)
	{
		s << item;
	}
	return s;
}

template<typename K>
DeSerializer &operator>>(DeSerializer &d, std::set<K> &v)
{
	int len = 0;
	d >> len;
	for (int i = 0; i < len; i++)
	{
		K item {};
		d >> item;
		v.insert(item);
	}
	return d;
}