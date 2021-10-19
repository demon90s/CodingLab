#include <cstdlib>
#include <chrono>
#include <iostream>
#include <functional>

// 测试内存访问速度
// 访问距离相近的内存速度要快，距离远的会慢

template<typename RATIO = std::chrono::milliseconds>
class BenchMarking
{
public:
    BenchMarking(std::function<void(std::size_t)> ouput_func = nullptr)
    {
        m_start_tp = std::chrono::high_resolution_clock::now();

        m_ouput_func = ouput_func;
    }

    ~BenchMarking()
    {
        auto end_tp = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<RATIO>(m_start_tp);
        auto end = std::chrono::time_point_cast<RATIO>(end_tp);

        auto diff = end - start;

        std::size_t dur = diff.count();

        if (m_ouput_func == nullptr)
            std::cout << "BenchMarking duration: " << dur << std::endl;
        else
            m_ouput_func(dur);
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_tp;
    std::function<void(std::size_t)> m_ouput_func;
};

static const int NUM_ARR_ROW = 10000;
static const int NUM_ARR_COL = 10000;
static int num_arr[NUM_ARR_ROW][NUM_ARR_COL];

static void init_num_arr()
{
    for (int i = 0; i < NUM_ARR_ROW; ++i)
    {
        for (int j = 0; j < NUM_ARR_COL; ++j)
        {
            num_arr[i][j] = rand();
        }
    }
}

// 访问相邻元素为主，速度最快
static void access_1()
{
    long long sum = 0;
    for (int i = 0; i < NUM_ARR_ROW; ++i)
    {
        for (int j = 0; j < NUM_ARR_COL; ++j)
        {
            sum += num_arr[i][j];
        }
    }
}

// 访问不相邻的元素为主，结果会慢很多
static void access_2()
{
    long long sum = 0;
    for (int j = 0; j < NUM_ARR_COL; ++j)
    {
        for (int i = 0; i < NUM_ARR_ROW; ++i)
        {
            sum += num_arr[i][j];
        }
    }
}

int main()
{
    init_num_arr();
    std::cout << "init num arr finish" << std::endl;

    {
        BenchMarking<> bm([](std::size_t dur) { std::cout << "access_1 dur: " << dur << std::endl; });
        access_1();
    }

    {
        BenchMarking<> bm([](std::size_t dur) { std::cout << "access_2 dur: " << dur << std::endl; });
        access_2();
    }
}