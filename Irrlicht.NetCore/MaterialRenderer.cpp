#include "stdafx.h"
#include "ReferenceCounted.h"
#include "MaterialRenderer.h"

using namespace irr;
using namespace System;
using namespace IrrlichtNetCore::Core;

namespace IrrlichtNetCore {
namespace Video {

MaterialRenderer^ MaterialRenderer::Wrap(video::IMaterialRenderer* ref)
{
    if (ref == nullptr)
        return nullptr;

    return gcnew MaterialRenderer(ref);
}

MaterialRenderer::MaterialRenderer(video::IMaterialRenderer* ref)
    : ReferenceCounted(ref)
{
    LIME_ASSERT(ref != nullptr);
    m_MaterialRenderer = ref;
}

int MaterialRenderer::Capability::get()
{
    return m_MaterialRenderer->getRenderCapability();
}

bool MaterialRenderer::Transparent::get()
{
    return m_MaterialRenderer->isTransparent();
}

String^ MaterialRenderer::ToString()
{
    return String::Format("MaterialRenderer: Capability={0}", Capability);
}

} // end namespace Video
} // end namespace IrrlichtNetCore
