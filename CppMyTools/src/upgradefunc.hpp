#pragma once

#include <vector>

struct UpgradeResult
{
    bool is_succ = false;
    long long to_exp = 0;
    int to_level = 0;
};

// UpgradeExpItem 提供一个方法 long long GetUplevelNeedExp() const ，表示升到下一级所需要的经验
template<typename UpgradeExpItem>
UpgradeResult Upgrade(long long cur_exp, int cur_level, long long inc_exp,
    const std::vector<UpgradeExpItem> &upgrade_exp_list)
{
    UpgradeResult result;
    result.is_succ = false;

    if (inc_exp <= 0 || cur_level < 0)
    {
        return result;
    }

    if (upgrade_exp_list.size() < 1)
    {
        return result;
    }

    const int MAX_LEVEL = static_cast<int>(upgrade_exp_list.size()) - 1;

    if (cur_level >= MAX_LEVEL)
    {
        return result;
    }

    cur_exp += inc_exp;

    while (cur_level < MAX_LEVEL &&
        cur_exp >= upgrade_exp_list[cur_level].GetUplevelNeedExp())
    {
        cur_exp -= upgrade_exp_list[cur_level].GetUplevelNeedExp();
        cur_level++;
    }

    result.is_succ = true;
    result.to_exp = cur_exp;
    result.to_level = cur_level;

    return result;
}
