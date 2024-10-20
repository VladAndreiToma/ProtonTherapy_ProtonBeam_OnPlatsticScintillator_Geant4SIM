#ifndef STEPPINGACTION_H
#define STEPPINGACTION_H 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"  // for global constants and their units

class EventAction;

class SteppingAction : public G4UserSteppingAction {
    public:
        SteppingAction(EventAction* eventAction);
        ~SteppingAction() override;
        void UserSteppingAction(const G4Step* step) override;
    private:
        EventAction* fEventAction;
};

#endif  // STEPPINGACTION_H
