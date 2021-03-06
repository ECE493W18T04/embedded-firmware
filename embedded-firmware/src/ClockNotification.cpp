#include "ClockNotification.h"
#include "StateManager.h"

ClockNotification::ClockNotification(StateManager& _stateMgr) : DefaultState(_stateMgr) {
    setActive(false);
}

bool ClockNotification::tick() {
    char buffer[32];
    time_t seconds = time(NULL);
    strftime(buffer, 32, "%I:%M", localtime(&seconds));
    GraphicsManager& gfx = this->getManager().getGfxManager();
    gfx.erase();
    gfx.placeText(buffer, 1);
    gfx.drawBuffer();
    return DefaultState::tick();
}

void ClockNotification::update(uint32_t time) {
    setActive(true);
    getManager().updateStates();
    set_time(time);
}
