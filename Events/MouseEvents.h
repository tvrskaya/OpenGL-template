#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H

#include "Event.h"

class MousePosEvent : Event
{
public:
    MousePosEvent(float xpos, float ypos)
                : Event(), m_MouseX(xpos), m_MouseY(ypos)
    {
        EventType = mousePosEvent;
    }
    float GetX() const { return m_MouseX; }
    float GetY() const { return m_MouseY; }
private:
    float m_MouseX;
    float m_MouseY;
};

class MouseButtonEvent : Event 
{
public:
    MouseButtonEvent(int button, int state)
        : Event(), m_Button(button), m_State(state)
    {
        EventType = mouseButtonClickEvent;
    }

    int GetButton() const { return m_Button; }
    int GetState() const { return m_State; }

private:
    int m_Button;
    int m_State;
};

class MouseScrollEvent : Event 
{
public:
    MouseScrollEvent(float offsetx, float offsety)
        : Event(), m_OffsetX(offsetx), m_OffsetY(offsety)
    {
        EventType = mouseScrollEvent;
    }
    float GetOffsetX() const { return m_OffsetX; }
    float GetOffsetY() const { return m_OffsetY; }
private:
    float m_OffsetX;
    float m_OffsetY;
};

#endif