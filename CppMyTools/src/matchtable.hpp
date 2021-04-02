#pragma once

#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>

// 淘汰赛对阵表，可决出冠亚军 34名
/*

0                               4
    1                     4
1                               5
        1   冠亚军   4   
        2   3 4名    6
2                               6
    2                     6
3                               7

*/

template<typename MatchItem>
class MatchTable
{
public:
    MatchTable() :
        m_round(0),
        m_max_round(0),
        m_3vs4_winner(-1),
        m_3vs4_loser(-1)
    {
    }

    void Reset()
    {
        m_round = 0;
        m_max_round = 0;
        m_matchitem_list.clear();
        m_cur_matches.clear();

        m_3vs4_winner = -1;
        m_3vs4_loser = -1;
    }

    int GetRound() const
    {
        return m_round;
    }

    int GetMaxRount() const
    {
        return m_max_round;
    }

    MatchItem *GetMatchItem(int index)
    {
        return const_cast<MatchItem *>(static_cast<const MatchTable *>(this)->GetMatchItem(index));
    }

    const MatchItem *GetMatchItem(int index) const
    {
        if (index < 0 || index >= static_cast<int>(m_matchitem_list.size()))
        {
            return nullptr;
        }

        return &m_matchitem_list[index];
    }

    std::vector<std::pair<int, int>> GetPKList() const
    {
        if (m_round <= 0 || m_round > m_max_round)
        {
            return {};
        }

        auto it = m_cur_matches.find(m_round);
        if (it == m_cur_matches.end())
        {
            return {};
        }

        std::vector<std::pair<int, int>> pk_list;

        const auto &items = it->second;
        for (auto it = items.cbegin(); it != items.cend();)
        {
            int left_item = *it;
            int right_item = -1;

            ++it;
            if (it != items.end())
            {
                right_item = *it;
                ++it;
            }

            pk_list.push_back({left_item, right_item});
        }

        return pk_list;
    }

    // 获取三四名对决的item，倒数第二轮调用
    std::pair<int, int> Get3VS4PKItem() const
    {
        auto it_4_to_2 = m_cur_matches.find(m_max_round - 2);
        if (it_4_to_2 == m_cur_matches.end())
        {
            return {-1, -1};
        }

        auto it_2_to_1 = m_cur_matches.find(m_max_round - 1);
        if (it_2_to_1 == m_cur_matches.end())
        {
            return {-1, -1};
        }

        auto item_4_to_2 = it_4_to_2->second;
        auto item_2_to_1 = it_2_to_1->second;

        if (item_2_to_1.size() != 2)
        {
            return {-1, -1};
        }

        for (int index : item_2_to_1)
        {
            item_4_to_2.erase(index);
        }

        if (item_4_to_2.size() != 2)
        {
            return {-1, -1};
        }

        auto it_3 = item_4_to_2.begin();
        auto it_4 = ++item_4_to_2.begin();

        return {*it_3, *it_4};
    }

    int GetWinnerIndex() const
    {
        auto it = m_cur_matches.find(m_max_round);
        if (it == m_cur_matches.cend())
        {
            return -1;
        }

        auto pk_it = it->second.begin();

        if (pk_it == it->second.end())
        {
            return -1;
        }

        return *pk_it;
    }

    // 获取前四名队伍
    std::vector<int> GetRank4Item() const
    {
        if (m_round != m_max_round)
        {
            return {};
        }

        auto it = m_cur_matches.find(m_round - 1);
        if (it == m_cur_matches.end())
        {
            return {};
        }

        std::vector<int> rank;

        const int winner_index = this->GetWinnerIndex();
        rank.push_back(winner_index);

        auto item_2_to_1 = it->second;
        item_2_to_1.erase(winner_index);
        auto second_it = item_2_to_1.begin();
        if (second_it != item_2_to_1.end())
        {
            rank.push_back(*second_it);
        }

        rank.push_back(m_3vs4_winner);
        rank.push_back(m_3vs4_loser);

        return rank;
    }

    void AddMatchItem(int index, const MatchItem &mt)
    {
        if (index < 0)
        {
            return;
        }

        if (m_round > 0)
        {
            fprintf(stderr, "[ERROR] MatchTable::AddMatchItem fail because match already start\n");
            return;
        }

        int resize_sz = index + 1;
        if (resize_sz % 2 != 0)
        {
            resize_sz += 1;
        }

        if (resize_sz > static_cast<int>(m_matchitem_list.size()))
        {
            m_matchitem_list.resize(resize_sz);
        }

        m_matchitem_list[index] = mt;
    }

    void StartNextRound()
    {
        if (m_round == 0)
        {
            const int item_count = static_cast<int>(m_matchitem_list.size());

            for (int i = 0; i < item_count; i++)
            {
                this->SetWinner(i);
            }

            {
                int max_round = 0;
                int item_count_tmp = item_count;
                while (item_count_tmp > 0)
                {
                    item_count_tmp /= 2;
                    max_round++;
                }

                m_max_round = max_round;
            }

        }

        m_round++;
    }

    void SetWinner(int index)
    {
        if (index < 0 || index >= static_cast<int>(m_matchitem_list.size()))
        {
            return;
        }

        int next_round = m_round + 1;

        int winner_count_limit = static_cast<int>(m_matchitem_list.size());
        for (int i = 1; i < next_round; i++)
        {
            winner_count_limit /= 2;
        }

        auto &matches = m_cur_matches[next_round];
        if (static_cast<int>(matches.size()) >= winner_count_limit)
        {
            return;
        }
        matches.insert(index);
    }

    void Set3VS4WinnerAndLoser(int winner_index, int loser_index)
    {
        if (m_round != m_max_round - 1)
        {
            return;
        }

        m_3vs4_winner = winner_index;
        m_3vs4_loser = loser_index;
    }

private:
    int m_round;
    int m_max_round;
    std::vector<MatchItem> m_matchitem_list;					// 参赛队伍

    std::map<int, std::set<int>> m_cur_matches;					// 比赛进度 round -> 队伍index

    int m_3vs4_winner; 											// 3,4名胜者
    int m_3vs4_loser;											// 3,4名败者
};
