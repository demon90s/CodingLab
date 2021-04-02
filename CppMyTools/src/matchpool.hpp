#pragma once

#include <map>
#include <list>
#include <vector>
#include <functional>
#include <ctime>
#include <iostream>

#define CUR_TIME() time(NULL)

template<typename UnitKey, typename Unit>
class MatchPool
{
    struct TmpMatchSide
    {
        UnitKey lhs;
        UnitKey rhs;
    };
public:
    struct MatchUnit
    {
        UnitKey key{};
        time_t start_match_time = 0;
        Unit unit{};
        bool matched_flag = false;
    };

    using MatchFunction = std::function<bool(const MatchUnit *lhs, const MatchUnit *rhs)>;
    using SortFunction = std::function<bool(const MatchUnit *lhs, const MatchUnit *rhs)>;

    MatchPool()
    {
        this->SetMatchFunction(DefaultMatchFunction);
        this->SetSortFunction(DefaultSortFunction);
    }

    // 设置匹配函数
    void SetMatchFunction(MatchFunction func)
    {
        if (nullptr == func)
        {
            return;
        }

        m_match_function = func;
    }

    // 设置优先级排序函数
    void SetSortFunction(SortFunction func)
    {
        if (nullptr == func)
        {
            return;
        }

        m_sort_function = func;
    }

    // 放入匹配池
    void Put(const UnitKey &key, const Unit &unit)
    {
        auto it = m_pool.find(key);
        if (it != m_pool.end())
        {
            std::cerr << "[ERROR] MatchPool::Put, repeate key\n";
            return;
        }

        MatchUnit mu;
        mu.key = key;
        mu.start_match_time = CUR_TIME();
        mu.unit = unit;

        m_pool[key] = mu;
    }

    // 从匹配池中移除
    void Erase(const UnitKey &key)
    {
        m_pool.erase(key);
    }

    // 是否正在匹配
    bool IsMatching(const UnitKey &key) const
    {
        return m_pool.find(key) != m_pool.end();
    }

    // 获取上一次的匹配结果
    const std::list<TmpMatchSide> &GetMatchResult() const
    {
        return m_match_result;
    }

    // 执行一次匹配
    void Match()
    {
        m_match_result.clear();

        for (auto it = m_pool.begin(); it != m_pool.end();)
        {
            if (it->second.matched_flag)
            {
                it = m_pool.erase(it);
            }
            else
            {
                ++it;
            }
        }

        for (auto cur_it = m_pool.begin(); cur_it != m_pool.end(); ++cur_it)
        {
            MatchUnit &cur_mu = cur_it->second;
            if (cur_mu.matched_flag)
            {
                continue;
            }

            std::vector<MatchUnit *> selected_unit_list;

            for (auto next_it = cur_it; ++next_it, next_it != m_pool.end();)
            {
                MatchUnit &next_mu = next_it->second;
                if (next_mu.matched_flag)
                {
                    continue;
                }

                if (m_match_function(&cur_mu, &next_mu))
                {
                    selected_unit_list.push_back(&next_mu);
                }
            }

            if (selected_unit_list.size() > 0)
            {
                std::sort(selected_unit_list.begin(), selected_unit_list.end(), m_sort_function);
            }

            MatchUnit *tmp_matched_unit = selected_unit_list.front();
            TmpMatchSide tms;
            tms.lhs = cur_mu.key;
            tms.rhs = tmp_matched_unit->key;
            m_match_result.push_back(tms);

            tmp_matched_unit->matched_flag = true;
            cur_mu.matched_flag = true;
        }
    }

private:
    static bool DefaultMatchFunction(const MatchUnit *lhs, const MatchUnit *rhs)
    {
        return true;
    }

    static bool DefaultSortFunction(const MatchUnit *lhs, const MatchUnit *rhs)
    {
        return lhs < rhs;
    }

    std::map<UnitKey, MatchUnit> m_pool;
    MatchFunction m_match_function;
    SortFunction m_sort_function;
    std::list<TmpMatchSide> m_match_result;
};