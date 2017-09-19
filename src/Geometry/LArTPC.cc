/**
 *  @file   PandoraSDK/src/Geometry/LArTPC.cc
 *
 *  @brief  Implementation of the lar tpc class.
 *
 *  $Log: $
 */

#include "Geometry/LArTPC.h"

namespace pandora
{

LArTPC::LArTPC(const object_creation::Geometry::LArTPC::Parameters &inputParameters) :
    m_larTPCName(inputParameters.m_larTPCName.Get()),
    m_centerX(inputParameters.m_centerX.Get()),
    m_centerY(inputParameters.m_centerY.Get()),
    m_centerZ(inputParameters.m_centerZ.Get()),
    m_widthX(inputParameters.m_widthX.Get()),
    m_widthY(inputParameters.m_widthY.Get()),
    m_widthZ(inputParameters.m_widthZ.Get()),
    m_wirePitchU(inputParameters.m_wirePitchU.Get()),
    m_wirePitchV(inputParameters.m_wirePitchV.Get()),
    m_wirePitchW(inputParameters.m_wirePitchW.Get()),
    m_thetaU(inputParameters.m_thetaU.Get()),
    m_thetaV(inputParameters.m_thetaV.Get()),
    m_sigmaUVW(inputParameters.m_sigmaUVW.Get()),
    m_isDriftInPositiveX(inputParameters.m_isDriftInPositiveX.Get())
{
}

//------------------------------------------------------------------------------------------------------------------------------------------

LArTPC::~LArTPC()
{
}

} // namespace pandora