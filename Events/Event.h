#ifndef EVENT_H
#define EVENT_H

enum EventTypes
{
    mousePosEvent, mouseButtonClickEvent, mouseScrollEvent,
    keyEvent
};

class Event
{
public:
    virtual bool IsHandled() const;
    virtual void Handle();
    virtual EventTypes GetEventType() const;
protected:
    EventTypes EventType;
    Event();
    bool isHandled;
};

#endif