#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

[assembly:AssemblyTitleAttribute("Irrlicht.Net")];

#if _DEBUG
#if WIN64
[assembly:AssemblyDescriptionAttribute("The ubiquitous Irrlicht graphics engine for .NET. (Debug-x64)")];
#else
[assembly:AssemblyDescriptionAttribute("The ubiquitous Irrlicht graphics engine for .NET. (Debug-x86)")];
#endif
#else
#if WIN64
[assembly:AssemblyDescriptionAttribute("The ubiquitous Irrlicht graphics engine for .NET. (Release-x64)")];
#else
[assembly:AssemblyDescriptionAttribute("The ubiquitous Irrlicht graphics engine for .NET. (Release-x86)")];
#endif
#endif

[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("")];
[assembly:AssemblyProductAttribute("Irrlicht.Net")];
[assembly:AssemblyCopyrightAttribute("Copyright (c) Doug Slater 2020")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

[assembly:AssemblyVersionAttribute("1.6.1.0")];

[assembly:ComVisible(false)];
[assembly:CLSCompliantAttribute(true)];
