// PYTHIA Info

#include "StEpSimuParticle.h"

ClassImp(StEpSimuParticle);

// Setters
StEpSimuParticle::StEpSimuParticle()
{
}

void StEpSimuParticle::setFourMom(Double_t px, Double_t py, Double_t pz, Double_t e) 
{ 
  mPx = px;
  mPy = py;
  mPz = pz;
  mE = e; 
}
void StEpSimuParticle::setFourMom_hb(Double_t px, Double_t py, Double_t pz, Double_t e) 
{ 
  mPx_hb = px;
  mPy_hb = py;
  mPz_hb = pz;
  mE_hb = e; 
}
void StEpSimuParticle::setFourMom_breit(Double_t px, Double_t py, Double_t pz, Double_t e) 
{ 
  mPx_breit = px;
  mPy_breit = py;
  mPz_breit = pz;
  mE_breit = e; 
}
void StEpSimuParticle::setIndex(int id) { mIndex = id; }
void StEpSimuParticle::setStatus(int status) { mStatus = status; }
void StEpSimuParticle::setPdgCode(int code) { mPDG = code; }
void StEpSimuParticle::setParentIndex(int id) { mParentIndex = id; }
void StEpSimuParticle::setNChildren(int n) { mNChildren = n; }
void StEpSimuParticle::setChild1Index(int n) { mFirstChild = n; }
void StEpSimuParticle::setChildNIndex(int n) { mLastChild = n; }
void StEpSimuParticle::setZ(Double_t z) { mZ = z; }
void StEpSimuParticle::setXF(Double_t xf) { mXF = xf; }
void StEpSimuParticle::setThetaVsGamma(Double_t theta) { mThetaVsGamma = theta; }
void StEpSimuParticle::setPtVsGamma(Double_t pt) { mPtVsGamma = pt; }
void StEpSimuParticle::setVertex(Double_t x, Double_t y, Double_t z) 
{ 
  mVx = x; 
  mVy = y;
  mVz = z;
}
void StEpSimuParticle::setMass(Double_t mass)
{
  mMass = mass;
}

// Getters
Double_t StEpSimuParticle::pt()
{
  return StEpSimuParticle::fourMomentum().Pt();
}
Double_t StEpSimuParticle::eta()
{
  return StEpSimuParticle::fourMomentum().Eta();
}
Double_t StEpSimuParticle::phi()
{
  return StEpSimuParticle::fourMomentum().Phi();
}
Double_t StEpSimuParticle::rap()
{
  return StEpSimuParticle::fourMomentum().Rapidity();
}

Double_t StEpSimuParticle::pt_hb()
{
  return StEpSimuParticle::fourMomentum_hb().Pt();
}
Double_t StEpSimuParticle::eta_hb()
{
  return StEpSimuParticle::fourMomentum_hb().Eta();
}
Double_t StEpSimuParticle::phi_hb()
{
  return StEpSimuParticle::fourMomentum_hb().Phi();
}
Double_t StEpSimuParticle::rap_hb()
{
  return StEpSimuParticle::fourMomentum_hb().Rapidity();
}

Double_t StEpSimuParticle::pt_breit()
{
  return StEpSimuParticle::fourMomentum_breit().Pt();
}
Double_t StEpSimuParticle::eta_breit()
{
  return StEpSimuParticle::fourMomentum_breit().Eta();
}
Double_t StEpSimuParticle::phi_breit()
{
  return StEpSimuParticle::fourMomentum_breit().Phi();
}
Double_t StEpSimuParticle::rap_breit()
{
  return StEpSimuParticle::fourMomentum_breit().Rapidity();
}


