#pragma once

#include "stdafx.h"
#include "GUIElement.h"

using namespace irr;
using namespace System;

namespace IrrlichtLime {
namespace GUI {

public ref class GUIColorSelectDialog : GUIElement
{
public:

	property Video::Color^ Color { Video::Color^ get(); }
	property Video::ColorHSL^ ColorHSL { Video::ColorHSL^ get(); }

internal:

	static GUIColorSelectDialog^ Wrap(gui::IGUIColorSelectDialog* ref);
	GUIColorSelectDialog(gui::IGUIColorSelectDialog* ref);

	gui::IGUIColorSelectDialog* m_GUIColorSelectDialog;
};

} // end namespace GUI
} // end namespace IrrlichtLime