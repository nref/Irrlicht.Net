#pragma once

#include "stdafx.h"
#include "ReferenceCounted.h"

using namespace irr;
using namespace System;
using namespace Irrlicht::Core;

namespace Irrlicht {
namespace GUI {

public ref class GUISpriteBank : ReferenceCounted
{
public:

    //...

internal:

    static GUISpriteBank^ Wrap(gui::IGUISpriteBank* ref);
    GUISpriteBank(gui::IGUISpriteBank* ref);

    gui::IGUISpriteBank* m_GUISpriteBank;
};

} // end namespace GUI
} // end namespace Irrlicht
