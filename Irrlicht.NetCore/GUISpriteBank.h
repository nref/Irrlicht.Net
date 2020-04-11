#pragma once

#include "stdafx.h"
#include "ReferenceCounted.h"

using namespace irr;
using namespace System;
using namespace IrrlichtNetCore::Core;

namespace IrrlichtNetCore {
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
} // end namespace IrrlichtNetCore
