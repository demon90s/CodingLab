#pragma once

template<typename T>
inline double GetDiffPer(T v1, T v2)
{
	// min + min * diff_per = max -> diff_per = (max - min) / min
	v1 > v2 ? std::swap(v1, v2) : 0;
	return (v2 - v1) * 1.0 / v1;
}
