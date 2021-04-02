#include "upgradefunc.hpp"
#include <iostream>

struct TestUpgradeItem
{
	long long GetUplevelNeedExp() const { return uplevel_need_exp; }

	int level = 0;
	long long uplevel_need_exp = 0;
};

void test_upgrade_func()
{
	TestUpgradeItem item0;
	item0.level = 0;
	item0.uplevel_need_exp = 100;

	TestUpgradeItem item1;
	item1.level = 1;
	item1.uplevel_need_exp = 200;

	TestUpgradeItem item2;
	item2.level = 2;
	item2.uplevel_need_exp = 300;

	TestUpgradeItem item3;
	item3.level = 3;
	item3.uplevel_need_exp = 400;

	std::vector<TestUpgradeItem> upgrade_exp_list;
	upgrade_exp_list.push_back(item0);
	upgrade_exp_list.push_back(item1);
	upgrade_exp_list.push_back(item2);
	upgrade_exp_list.push_back(item3);

	long long cur_exp = 0;
	int cur_level = 0;

	UpgradeResult res = Upgrade(cur_exp, cur_level, 300, upgrade_exp_list);
	std::cout << res.is_succ << " " << res.to_exp << " " << res.to_level << std::endl;
	if (res.is_succ)
	{
		cur_exp = res.to_exp;
		cur_level = res.to_level;
	}

	res = Upgrade(res.to_exp, res.to_level, 150, upgrade_exp_list);
	if (res.is_succ)
	{
		cur_exp = res.to_exp;
		cur_level = res.to_level;
	}
	std::cout << res.is_succ << " " << cur_exp << " " << cur_level << std::endl;

	res = Upgrade(cur_exp, cur_level, 150, upgrade_exp_list);
	if (res.is_succ)
	{
		cur_exp = res.to_exp;
		cur_level = res.to_level;
	}
	std::cout << res.is_succ << " " << cur_exp << " " << cur_level << std::endl;

	res = Upgrade(cur_exp, cur_level, 150, upgrade_exp_list);
	if (res.is_succ)
	{
		cur_exp = res.to_exp;
		cur_level = res.to_level;
	}
	std::cout << res.is_succ << " " << cur_exp << " " << cur_level << std::endl;

	res = Upgrade(cur_exp, cur_level, 150, upgrade_exp_list);
	if (res.is_succ)
	{
		cur_exp = res.to_exp;
		cur_level = res.to_level;
	}
	std::cout << res.is_succ << " " << cur_exp << " " << cur_level << std::endl;
}