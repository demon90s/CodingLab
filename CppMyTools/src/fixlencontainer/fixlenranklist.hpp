#pragma once

/*
    �����������б�
    Ҫ�� T ��������ʵ�� operator< , operator== �����
*/

#include <vector>
#include <algorithm>
#include <cstring>

template<typename T, int LEN>
class FixLenRankList
{
private:
	int m_need_sort_flag;
	T m_rank_list[LEN];

public:
	FixLenRankList() :
		m_need_sort_flag(0),
		m_rank_list {}
	{
		static_assert(LEN > 0, "LEN MUST > 0");
	}

	void Reset()
	{
		m_need_sort_flag = 0;
		for (auto &item : m_rank_list)
		{
			item = T {};
		}
	}

	// ��һ����С���滻��Push��������
	void Push(const T &item)
	{
		// �����б��У�����
		auto it = std::find(std::begin(m_rank_list), std::end(m_rank_list), item);
		if (it != std::end(m_rank_list))
		{
			*it = item;
			m_need_sort_flag = 1;
			return;
		}

		// ����С�Ļ�С������
		auto min_it = std::min_element(std::begin(m_rank_list), std::end(m_rank_list));
		if (item < *min_it)
		{
			return;
		}

		// �滻��С��
		*min_it = item;

		// ���¼������ֵ
		m_need_sort_flag = 1;
	}

	// ��ȡ��һ����һ�������µ�
	const T &GetTop() const
	{
		if (m_need_sort_flag)
		{
			const_cast<FixLenRankList *>(this)->Sort();
		}
		return m_rank_list[0];
	}

	// ��֤������
	std::vector<T> GetTopList(int count = LEN) const
	{
		if (m_need_sort_flag)
		{
			const_cast<FixLenRankList *>(this)->Sort();
		}

		std::vector<T> top;
		top.reserve(count);
		for (int i = 0; i < count && i < LEN; i++)
		{
			top.push_back(m_rank_list[i]);
		}
		return top;
	}

private:
	// ����
	void Sort()
	{
		std::stable_sort(std::begin(m_rank_list), std::end(m_rank_list),
		                 [](const T &lhs, const T &rhs)
		{
			return rhs < lhs;
		});

		m_need_sort_flag = 0;
	}
};
