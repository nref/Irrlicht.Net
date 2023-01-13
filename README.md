# Irrlicht.Net

This is a fork of [Irrlicht Lime](https://github.com/greenya/irrlichtlime).

## Supported Architectures and Target Frameworks

Four permutations are supported:

Architecture | Target Framework | NuGet Package
-------------|------------------|--------------------------------
`x86`        | net48            | [Irrlicht.NetFramework.x86](https://www.nuget.org/packages/Irrlicht.NetFramework.x86)
`x64`        | net48            | [Irrlicht.NetFramework.x64](https://www.nuget.org/packages/Irrlicht.NetFramework.x64)
`x86`        | netcoreapp31     | [Irrlicht.NetCore.x86](https://www.nuget.org/packages/Irrlicht.NetCore.x86)
`x64`        | netcoreapp31     | [Irrlicht.NetCore.x64](https://www.nuget.org/packages/Irrlicht.NetCore.x64)
`x64`        | net6.0-iwnodw    | (not published)

## Dependencies

On .NET Core 3.1 and on, only Windows is supported because C++/CLI .NET Core 3.1 is only supported on Windows.

The .NET Core 3.1 and later packages depend on `Ijwhost.dll` and `Irrlicht.dll`. The .NET Framework packages only depend on `Irrlicht.dll`. These DLLs are included and automatically copied to the build output directory. 

## Example 

For an example WPF app, see https://github.com/slater1/GraphicsTemplate/.

## Another Example

``` cs
public void Run()
{
    var p = new IrrlichtCreationParameters
    {
        DriverType = DriverType.Direct3D9,
        AntiAliasing = 8
    };

    var device = IrrlichtDevice.CreateDevice(p);

    while (device.Run())
    {
        device.VideoDriver.BeginScene();
        device.SceneManager.DrawAll();
        device.GUIEnvironment.DrawAll();
        device.VideoDriver.EndScene();
    }

    device.Drop();
}

```

## Supporting Multiple Architectures and Target Frameworks

``` csproj
<Project Sdk="Microsoft.NET.Sdk.WindowsDesktop">

  <PropertyGroup>
    <TargetFrameworks>netcoreapp3.1;net48</TargetFrameworks>
    <Platforms>x64;x86</Platforms>
    ...
  </PropertyGroup>
  ...
  
  <ItemGroup>
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Debug|x64|netcoreapp3.1'" Include="Irrlicht.NetCore.x64" Version="3.1.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Release|x64|netcoreapp3.1'" Include="Irrlicht.NetCore.x64" Version="3.1.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Debug|x86|netcoreapp3.1'" Include="Irrlicht.NetCore.x86" Version="3.1.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Release|x86|netcoreapp3.1'" Include="Irrlicht.NetCore.x86" Version="3.1.0" />
      
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Debug|x64|net48'" Include="Irrlicht.NetFramework.x64" Version="4.8.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Release|x64|net48'" Include="Irrlicht.NetFramework.x64" Version="4.8.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Debug|x86|net48'" Include="Irrlicht.NetFramework.x86" Version="4.8.0" />
    <PackageReference Condition="'$(Configuration)|$(Platform)|$(TargetFramework)' == 'Release|x86|net48'" Include="Irrlicht.NetFramework.x86" Version="4.8.0" />
        
  </ItemGroup>

</Project>
```
