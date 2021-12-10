#pragma once

class SomeMgr
{
public:
    static SomeMgr* Instance();
    bool ReInit();
    
    bool Init();
    int GetSomeValue() const;

private:
    SomeMgr();
    ~SomeMgr();

    int m_some_value;
};
