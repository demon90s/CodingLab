#pragma once

#include <string.h>
#include <stdexcept>
#include <functional>

// �������У�Tֻ�ܷŻ������ͣ����ܷ�ָ��
// ��������齱��־֮��Ķ���
template<typename T, int LEN>
class FixLenQueue
{
private:
	int m_len;
	T m_q[LEN];

public:
	FixLenQueue() { this->Reset(); }
	void Reset()
	{
		m_len = 0;
		for (auto &v : m_q)
		{
			v = T{};
		}
	}

	bool IsValidIndex(int index) const
	{
		return index >= 0 && index < m_len;
	}

	void Push(const T &v)
	{
		memmove(m_q + 1, m_q, sizeof(m_q) - sizeof(m_q[0]));
		m_q[0] = v;

		if (m_len < LEN)
			m_len++;
	}

	// -1��ʾ��ͷpopһ��Ԫ�أ�������Դ��м�popһ��Ԫ�أ������Ԫ����ǰ�ƶ�
	T Pop(int index = -1)
	{
		if (index == -1)
		{
			index = 0;
		}
		if (!this->IsValidIndex(index))
		{
			throw std::logic_error("FixLenQueue::Pop out of range");
		}
		T v = m_q[index];

		for (int i = index; i < LEN - 1; i++)
		{
			m_q[i] = m_q[i + 1];
		}
		m_len--;

		return v;
	}

	int Size() const
	{
		return m_len;
	}

	bool IsFull() const
	{
		return m_len == LEN;
	}

	const T& operator[](int index) const
	{
		if (!this->IsValidIndex(index))
		{
			throw std::out_of_range("FixLenQueue::operator[] out of range");
		}
		return m_q[index];
	}

	void GetQueue(T *q, int len) const
	{
		int cp_len = m_len > len ? len : m_len;
		memcpy(q, m_q, cp_len * sizeof(T));
	}

	template<typename M>
	void GetQueueByCopyFunc(M *q, int len, std::function<void(const T&, decltype(*q))> copy_item_func) const
	{
		for (int i = 0; i < m_len && i < len; i++)
		{
			copy_item_func(m_q[i], q[i]);
		}
	}
};
