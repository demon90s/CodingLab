#include "instance.hpp"

SomeMgr& SomeMgr::Instance()
{
    static SomeMgr inst;
    return inst;
}

int SomeMgr::GetSomeValue() const { return m_some_value; }

SomeMgr::SomeMgr() : 
    m_some_value(42)
{

}

SomeMgr::~SomeMgr()
{
    
}
