# Build Instructions

## Getting the Code

To retrieve the code from GitHub:

```cmd
git clone https://github.com/TimZoet/dot.git source
```

## Exporting to Conan

To export the `dot` package to your local Conan cache:

```cmd
conan export --user timzoet --channel v1.0.0 source
```

Make sure to update the channel when the version is different.

## Including the Package

To include the package from your `conanfile.py`:

```py
def requirements(self):
    self.requires("dot/1.0.0@timzoet/v1.0.0")
```

To find the package and link it in one of your `CMakeLists.txt`:

```cmake
find_package(dot REQUIRED)
target_link_libraries(<target> dot::dot)
```
