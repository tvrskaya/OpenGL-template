#ifndef KEYEVENTS_H
#define KEYEVENTS_H

#include "Event.h"

class KeyEvent : Event
{
public:
    KeyEvent(int key, int state)
        : Event(), m_Key(key), m_State(state)
    {
        EventType = keyEvent;
    }
    int GetKey() const { return m_Key; }
    int GetState() const { return m_State; }

private:
    int m_Key;
    int m_State;
};

#endif