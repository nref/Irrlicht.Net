# Copy all Irrlicht include, .dll, .lib, and .pdb files.

# Execute the given command using iex and echo what is executed
function Echo-Iex {
  param(
    [String] $command
  )
  
  write-host $command -ForegroundColor Green
  iex $command
}

$in = Resolve-Path -path "$PsScriptRoot\..\irrlicht"
$out = Resolve-Path -path "$PsScriptRoot\irrlicht"

$filter = [regex] "^*\.(dll|lib|pdb)"

$dirs = @{}
$dirs["$in\bin\x64\Release"]="$out\bin\x64\Release"
$dirs["$in\bin\x64\Debug"]="$out\bin\x64\Debug"
$dirs["$in\bin\Win32\Release"]="$out\bin\x86\Release"
$dirs["$in\bin\Win32\Debug"]="$out\bin\x86\Debug"

foreach ($e in $dirs.GetEnumerator()) {
    $bin = Get-ChildItem -Path $($e.Name) | Where-Object {$_.Name -match $filter} 

    foreach ($item in $bin) {
        Echo-Iex "Copy-Item -Path $item -Destination $($e.Value)"
    }
}

Echo-Iex "Copy-Item $in\include -Destination $out -Recurse -Force"