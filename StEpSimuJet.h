// Test of Jet Used with StForwardDijetEvent

#ifndef StEpSimuJet_def
#define StEpSimuJet_def

#include "TObject.h"
#include "TLorentzVector.h"
#include "TRef.h"
#include "TRefArray.h"

#include "StEpSimuJetParticle.h"
#include "StEpSimuSubJet.h"

class StEpSimuJetEvent;
class StEpSimuJetDef;
class StEpSimuJetParticle;
class StEpSimuSubJet;

class StEpSimuJet : public TObject {
 public:
  StEpSimuJet()
    : mPt(0)
    , mEta(0)
    , mPhi(0)
    , mE(0)
    {
    }

  StEpSimuJet(Double_t pt, Double_t eta, Double_t phi, Double_t energy);

  //StEpSimuJet(const TLorentzVector& fourMomentum);

  TVector3 momentum() const;
  TLorentzVector fourMomentum() const;
  
  // Declare Setters
  void setArea(Double_t area);
  void setAreaError(Double_t error);
  
  // Declare and Implement Getters
  Double_t pt()         const { return mPt; }
  Double_t eta()        const { return mEta; }
  Double_t phi()        const { return mPhi; }
  Double_t E()          const { return mE; }
  Double_t area()       const { return mArea; }
  Double_t areaError()  const { return mAreaError; }
  
  Double_t rap();
  
  // Declare Utility Functions
  Double_t sumParticlePt() const;
  Double_t sumParticlePt(Double_t radius) const;
  //float sumTowerPt() const;
  //float sumTowerPt(float radius) const;
  //float sumPt() const { return sumTrackPt() + sumTowerPt(); }
  //float sumPt(float radius) const { return sumTrackPt(radius)+sumTowerPt(radius); }
  Double_t profile(Double_t radius) const { return sumParticlePt(radius)/sumParticlePt(); }
  //float psi(float radius) const { return profile(radius); }
  //float deltaR(const StEpSimuJetParticle* part) const { return momentum().DeltaR(part->momentum()); }
  Double_t deltaR(const StEpSimuJetParticle* part) const;
  //float deltaR(const StForwardTower* tower) const { return momentum().DeltaR(tower->momentum()); }
  
  
  // Set Parent Jet Def
  void setJetDef(const StEpSimuJetDef* jetDef); //{ mDijet = (TObject*)dijet; }
  
  // Get Number of Particles
  int numberOfJetParticles() const; // { return mTracks.GetEntriesFast(); }
  
  // Get Number of Subjets
  int numberOfSubJets() const;
  
  // Get Particle
  StEpSimuJetParticle* jetParticle(int i) const; // { return (StForwardTrack*)mTracks.At(i); }
  
  // Get Subjet
  StEpSimuSubJet* subJet(int i) const;
  
  // Add Particle to Jet
  StEpSimuJetParticle* addJetParticle(StEpSimuJetParticle* particle); 
  
  // Add Subjet to Jet
  StEpSimuSubJet* addSubJet(StEpSimuSubJet* subjet);
  
  
 private:

  TRef mJetDefs;
  
  Double_t mPt;
  Double_t mEta;
  Double_t mPhi;
  Double_t mE;
  Double_t mArea;
  Double_t mAreaError;
  
  TRefArray mJetParticles;
  TRefArray mSubJets;
  
  ClassDef(StEpSimuJet,3);
};


inline TVector3 StEpSimuJet::momentum() const
{
  TVector3 mom;
  mom.SetPtEtaPhi(mPt,mEta,mPhi);
  return mom;
}

inline TLorentzVector StEpSimuJet::fourMomentum() const
{
  TLorentzVector fourMom;
  fourMom.SetPtEtaPhiE(mPt,mEta,mPhi,mE);
  return fourMom;
}

#endif
