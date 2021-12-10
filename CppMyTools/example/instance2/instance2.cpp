#include "instance2.hpp"

static SomeMgr *some_mgr = nullptr;

SomeMgr::SomeMgr() : m_some_value(0)
{

}

SomeMgr::~SomeMgr()
{

}

SomeMgr* SomeMgr::Instance()
{
    if (nullptr == some_mgr)
    {
        some_mgr = new SomeMgr();
    }

    return some_mgr;
}

bool SomeMgr::ReInit()
{
    SomeMgr *temp = new SomeMgr();
    if (!temp->Init())
    {
        delete temp;
        return false;
    }

    if (some_mgr != nullptr)
        delete some_mgr;

    some_mgr = temp;
    return true;
}

bool SomeMgr::Init()
{
    m_some_value = 100;
    return true;
}

int SomeMgr::GetSomeValue() const { return m_some_value; }