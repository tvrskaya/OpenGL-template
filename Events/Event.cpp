#include "Event.h"

Event::Event()
    : isHandled(false)
{
}

bool Event::IsHandled() const
{
    return isHandled;
}

void Event::Handle()
{
    if (isHandled == false)
        isHandled = true;
}

EventTypes Event::GetEventType() const
{
    return EventType;
}

