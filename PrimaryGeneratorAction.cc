#include "PrimaryGeneratorAction.hh" // methods and vars here
#include "G4ParticleGun.hh"
#include "G4Proton.hh"
#include "G4SystemOfUnits.hh"

PrimaryGeneratorAction :: PrimaryGeneratorAction(){
    // how many particles should i fire 
    // well...
    G4int particlesNo = 100;
    fParticleGun = new G4ParticleGun( particlesNo );
    // creating an object instance of particle setting it to proton
    G4ParticleDefinition* proton = G4Proton :: ProtonDefinition();
    fParticleGun -> SetParticleDefinition( proton );
    //  set proton energy
    fParticleGun -> SetParticleEnergy( 200*MeV );
    // set momentum direction --- where to shoot basically
    fParticleGun -> SetParticleMomentumDirection( G4ThreeVector( 0. , 0. , 1. ) );  // wanting it along z axis
    // from where do i shoot
    fParticleGun -> SetParticlePosition( G4ThreeVector( 0. , 0. , -4.*m ) ); // shooting form - 4m along z direction
}

PrimaryGeneratorAction :: ~PrimaryGeneratorAction(){
    delete fParticleGun; // cleanup 
}

void PrimaryGeneratorAction :: GeneratePrimaries( G4Event* anEvent ){
    fParticleGun -> GeneratePrimaryVertex( anEvent );
}

// summary i m shooting 100 protons from same point at -4 m on z axis with an energy of 200 mevs 
