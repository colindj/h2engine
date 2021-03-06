#ifndef _FF_GAME_EVENT_H_
#define _FF_GAME_EVENT_H_

#include "base/event_bus.h"
#include "common/entity.h"

namespace ff{
class MapObj;
class EnterMapCheckEvent:public Event<EnterMapCheckEvent>
{
public:
    EnterMapCheckEvent(EntityPtr e, MapObj& m, int x, int y):isOk(true), entity(e), destMap(m), destX(x), destY(y){}
    
    bool      isOk;
    EntityPtr entity;
    MapObj&   destMap;
    int       destX;
    int       destY;
};

class EnterMapEvent:public Event<EnterMapEvent>
{
public:
    EnterMapEvent(EntityPtr e):entity(e){}
    EntityPtr entity;
    std::vector<EntityPtr> AOIEnter;
};
class LeaveMapEvent:public Event<LeaveMapEvent>
{
public:
    LeaveMapEvent(EntityPtr e):entity(e){}
    EntityPtr entity;
    std::vector<EntityPtr> AOILeave;
};
class MoveMapCheckEvent:public Event<MoveMapCheckEvent>
{
public:
    MoveMapCheckEvent(EntityPtr e, int x2, int y2):isOk(true), entity(e), newX(x2), newY(y2){}
    
    bool isOk;
    EntityPtr entity;
    int newX;
    int newY;
};
class MoveMapEvent:public Event<MoveMapEvent>
{
public:
    MoveMapEvent(EntityPtr e, int x1, int y1):entity(e), oldX(x1), oldY(y1){}

    EntityPtr entity;
    int oldX;
    int oldY;
    std::vector<EntityPtr> AOIEnter;
    std::vector<EntityPtr> AOILeave;
    std::vector<EntityPtr> AOIMove;
};

class CreateEntityEvent:public Event<CreateEntityEvent>
{
public:
    CreateEntityEvent(EntityPtr e):entity(e){}
    EntityPtr entity;
};
class UpdateEntityEvent:public Event<UpdateEntityEvent>
{
public:
    UpdateEntityEvent(EntityPtr e):entity(e){}
    EntityPtr entity;
};
class DelEntityEvent:public Event<DelEntityEvent>
{
public:
    DelEntityEvent(EntityPtr e):entity(e){}
    EntityPtr entity;
};

}
#endif
