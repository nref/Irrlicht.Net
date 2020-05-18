#pragma once

#include "stdafx.h"
#include "SceneNode.h"

using namespace irr;
using namespace System;

namespace Irrlicht {
namespace Scene {

public ref class DummyTransformationSceneNode : SceneNode
{
public:

    property Matrix^ RelativeTransformationMatrix { Matrix^ get(); }

internal:

    static DummyTransformationSceneNode^ Wrap(scene::IDummyTransformationSceneNode* ref);
    DummyTransformationSceneNode(scene::IDummyTransformationSceneNode* ref);

    scene::IDummyTransformationSceneNode* m_DummyTransformationSceneNode;
};

} // end namespace Scene
} // end namespace Irrlicht
