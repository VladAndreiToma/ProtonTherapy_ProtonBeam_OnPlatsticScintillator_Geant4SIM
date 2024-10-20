// developed to tie everything together in terms of actioning
// that means events and their derivative 
// primary generator action ,event action , stepping action

#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialization :: ActionInitialization() : G4VUserActionInitialization(){
    // constructor has initialization list inheriting in constructor from G4VUAI
}
ActionInitialization :: ~ActionInitialization(){}

void ActionInitialization :: Build() const{
    SetUserAction( new PrimaryGeneratorAction() );
    // starting the particle gun 
    EventAction* eventAction = new EventAction();
    SetUserAction( eventAction ); // setting a shooting and then following events
    SetUserAction( new SteppingAction( eventAction ) );
}