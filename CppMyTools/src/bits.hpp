#pragma once

// ���á��жϡ�������λ��bitȡֵ��Χ��[0, 64)
#define SET_BIT(flag, bit) ((flag) |= 1ULL << (bit))
#define IS_BIT_SET(flag, bit) (((flag) & 1ULL << (bit))) != 0)
#define CLEAR_BIT(flag, bit) ((flag) &= ~(1ULL << (bit)))