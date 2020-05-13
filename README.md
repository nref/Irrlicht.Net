# Irrlicht.NetCore

[Irrlicht.NetCore](https://github.com/slater1/Irrlicht.NetCore) targets .NET Core 3.1 and is a fork of [Irrlicht Lime](https://github.com/greenya/irrlichtlime) (.NET Framework).

## Architecture

These are two NuGet packages supporting `x86` and `x64` build. See [Irrlicht.NetCore.x64](https://www.nuget.org/packages/Irrlicht.NetCore.x64) and [Irrlicht.NetCore.x86](https://www.nuget.org/packages/Irrlicht.NetCore.x86).

## Dependencies

Please note that only Windows is supported because C++/CLI on .NET Core 3.1 is only supported on Windows.

The packages depend on `Ijwhost.dll` and `Irrlicht.dll` which are included and automatically copied to the build output directory.

## Example 

For an example WPF app, see https://github.com/slater1/GraphicsTemplate/.

## Another Example

```
public void Run()
{
    var p = new IrrlichtCreationParameters
    {
        DriverType = DriverType.Direct3D9,
        AntiAliasing = 8
    };

    var device = IrrlichtDevice.CreateDevice(p);

    while (_device.Run())
    {
        device.VideoDriver.BeginScene();
        device.SceneManager.DrawAll();
        device.GUIEnvironment.DrawAll();
        device.VideoDriver.EndScene();
    }

    device.Drop();
}

```

## Supporting Multiple Architectures

```
<Project Sdk="Microsoft.NET.Sdk.WindowsDesktop">

  ...
  <ItemGroup>
    <PackageReference Condition="'$(Configuration)|$(Platform)' == 'Debug|x64'" Include="Irrlicht.NetCore.x64" Version="3.1.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)' == 'Release|x64'" Include="Irrlicht.NetCore.x64" Version="3.1.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)' == 'Debug|x86'" Include="Irrlicht.NetCore.x86" Version="3.1.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)' == 'Release|x86'" Include="Irrlicht.NetCore.x86" Version="3.1.0" />
  </ItemGroup>

</Project>
```