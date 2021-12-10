#pragma once

class SomeMgr {
public:
    static SomeMgr& Instance();

    int GetSomeValue() const;
private:
    SomeMgr();
    ~SomeMgr();

    int m_some_value;
};
