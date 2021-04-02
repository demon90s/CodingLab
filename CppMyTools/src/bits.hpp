#pragma once

// 设置、判断、清除标记位，bit取值范围：[0, 64)
#define SET_BIT(flag, bit) ((flag) |= 1ULL << (bit))
#define IS_BIT_SET(flag, bit) (((flag) & 1ULL << (bit))) != 0)
#define CLEAR_BIT(flag, bit) ((flag) &= ~(1ULL << (bit)))