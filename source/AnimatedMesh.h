#pragma once

#include "stdafx.h"
#include "Mesh.h"

using namespace irr;
using namespace System;

namespace IrrlichtLime {
namespace Scene {

public ref class AnimatedMesh : Mesh
{
public:

internal:

	AnimatedMesh(scene::IAnimatedMesh* animatedMesh);

	scene::IAnimatedMesh* m_AnimatedMesh;
};

} // end namespace Scene
} // end namespace IrrlichtLime