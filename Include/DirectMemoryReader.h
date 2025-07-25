/*
Author: The Iron Wolf (vleonavicius@hotmail.com)
Website: thecrewchief.org
*/

#pragma once

class DirectMemoryReader
{
public:
  DirectMemoryReader() {}

  bool Initialize();
  bool Read(LMU_Extended& extended, int mID);
  bool ReadOnNewSession(LMU_Extended& extended);
  //bool ReadOnLSIVisible(LMU_Extended& extended);

  bool IsSCRPluginEnabled() const { return mSCRPluginEnabled; }
  long GetSCRPluginDoubleFileType() const { return mSCRPluginDoubleFileType; }
  //void ClearLSIValues(LMU_Extended& extended);
  void DirectMemoryReader::ResetFounds();

private:
  void ReadSCRPluginConfig();
  void ReadSCRPluginConfigValues(char* const pluginConfig);
  

private:
  
  const unsigned long long  mCutsPointsOffset = 0x4055E50uLL; // mCutsMaxOffset ofsett 0x1557718uLL  
  const unsigned long long  mPenaltyCountOffset = 0x4069F7CuLL; // Byte mPenaltyCountOffset ofsett 0x156B468uLL           //step 0x11608uLL  79A38   40321E0
  const unsigned long long  mPenaltyLeftLapsOffset =  0x4069F84uLL; // Byte mPenaltyLeftLapsOffset ofsett 0x156B470uLL
  const unsigned long long  mPenaltyTypeCurrentOffset = 0x4069F88uLL; //Byte mPenaltyTypeCurrent 0x156B474uLL
  const unsigned long long  mPenaltyType1Offset = 0x4069F8CuLL; //Byte mPenaltyType1 0x  156B478uLL
  const unsigned long long  mCutsOffset = 0x406A188uLL; //  2 mCutsOffset 0x156B678uLL
  
  const unsigned long long mFuelAndEnergyOffset = 0x1A16718uLL;
  const unsigned long long mFuelLastLapOffset = 0x1A1CC14uLL;
  //const unsigned long long mEnergyLastLapOffset = 0x1A1CC14uLL;

  const unsigned long long mMotorMapOffset = 0x1A06BC0uLL; //41DBEE8 offset +0x48
  const unsigned long long mChangedParamTypeOffset = 0x1A06880uLL;  // = mChangedParamValueOffset -0x10
  const unsigned long long mChangedParamValueOffset = 0x1A06890uLL; //0x19FA1A0uLL; //0x19F80A0uLL; //0x19F75E0uLL; //0x19ED440uLL; //0x19ED440uLL; offset 0x00
  const unsigned long long mChangeParamSlotStep = 0x1EED8uLL; //0x11DB8uLL;  1CCDD38 2C7568
  const unsigned long long mChangeParamSlotStepInt = 0x7BB6uLL;
  const unsigned long long mChangeParamSlotStepDouble = 0x3DDBuLL;
  const unsigned long long mFront_ABR_Offset = 0x1A0BCC4uLL; 
  const unsigned long long mRear_ABR_Offset = 0x1A0BD54uLL; // mFront_ABR_Offset + 0x90 
  
  
 
  int* mCutsPoints = nullptr;
 
  int* mPenaltyCount = nullptr;
  bool mPenaltyCountFound = false;
  bool SeesionLive = false;
  
  unsigned long long mPenaltyCountFoundOffset = 0uLL;
 /* int* mPenaltyLeftLaps = nullptr;
  int* mPenaltyTypeCurrent = nullptr;
  int* mPenaltyType1 = nullptr;*/

  char* mMotorMap = nullptr;
  int* mChangedParamType = nullptr;
  int* mFront_ABR = nullptr;
  int* mRear_ABR = nullptr;
  char* mChangedParamValue = nullptr;
  double* mFuelAndEnergy = nullptr;
  float* mFuelLastLap = nullptr;
  char* mRegenLevel = nullptr;
  float* mCuts = nullptr;
  bool mCutsFound = false;
  unsigned long long mCutsFoundOffset = 0uLL;
  char* mpTC = nullptr;
  char* mpBR = nullptr;
  char* mpStatusMessage = nullptr;
  char** mppMessageCenterMessages = nullptr;
  float* mpCurrPitSpeedLimit = nullptr;
  char* mpLSIMessages = nullptr;

  bool mSCRPluginEnabled = false;
  long mSCRPluginDoubleFileType = -1L;
};