#ifndef ActionInitialization_h
#define ActionInitialization_h 1 

#include "G4VUserActionInitialization.hh"
#include "globals.hh"

class ActionInitialization : public G4VUserActionInitialization{
    public:
        ActionInitialization();
        virtual ~ActionInitialization();
        virtual void Build() const;  // fucntion that is responsible with the start of simulation processes
        // doesnt modify parent constructor
        // and thus it will just overwrite the constructor
};

#endif