#pragma once

#include "stdafx.h"
#include "ReferenceCounted.h"

using namespace irr;
using namespace System;
using namespace Irrlicht::Core;

namespace Irrlicht {
namespace IO {

ref class FileList;
ref class ReadFile;

public ref class FileArchive : ReferenceCounted
{
public:

    ReadFile^ CreateAndOpenFile(int index);
    ReadFile^ CreateAndOpenFile(String^ filename);

    property Irrlicht::IO::FileList^ FileList { Irrlicht::IO::FileList^ get(); }
    property String^ Password { String^ get(); void set(String^ value); }
    property FileArchiveType Type { FileArchiveType get(); }

internal:

    static FileArchive^ Wrap(io::IFileArchive* ref);
    FileArchive(io::IFileArchive* ref);

    io::IFileArchive* m_FileArchive;
};

} // end namespace IO
} // end namespace Irrlicht
