#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4Step.hh"
#include "G4LogicalVolume.hh"

SteppingAction::SteppingAction(EventAction* eventAction) : G4UserSteppingAction(), fEventAction(eventAction){
    // constructor to do stuff or just instantiate a step
}
SteppingAction :: ~SteppingAction(){
    // destructor what happens when step finishes
}
void SteppingAction::UserSteppingAction( const G4Step* step ){
     G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    // with the above instruction i get the name of the volume in which i am currently in
    // i look to see if the step is inside the target volume
    if( volume -> GetName() == "Target" ){
        // i m in my target
        G4double edep = step -> GetTotalEnergyDeposit();
        // add it
        fEventAction -> AddEnergyDeposition( edep ); // here i modify stuff in event
    }
}