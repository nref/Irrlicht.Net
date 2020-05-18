#pragma once

#include "stdafx.h"
#include "ParticleEmitter.h"

using namespace irr;
using namespace System;
using namespace Irrlicht::Core;

namespace Irrlicht {
namespace Scene {

public ref class ParticleSphereEmitter : ParticleEmitter
{
public:

    property Vector3Df^ Center { Vector3Df^ get(); void set(Vector3Df^ value); }
    property float Radius { float get(); void set(float value); }

internal:

    static ParticleSphereEmitter^ Wrap(scene::IParticleSphereEmitter* ref);
    ParticleSphereEmitter(scene::IParticleSphereEmitter* ref);

    scene::IParticleSphereEmitter* m_ParticleSphereEmitter;
};

} // end namespace Scene
} // end namespace Irrlicht
