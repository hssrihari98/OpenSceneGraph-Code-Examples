
# OpenSceneGraph-Code-Examples
Provides CPP files of OSG topics following various sources.

Run these steps to setup your Visual Studio Environment after installing OpenSceneGraph. 

Use the Project Properties dialog to tell the compiler where to find OSG header files.
By default, OpenSceneGraph installs to C:\Program Files, so add the following path to
the Additional Include Directories property of the C/C++ options.

C:\Program Files\OpenSceneGraph\include

Similarly, you need to tell the linker where to find the OSG libraries. Add the following
directory to the Additional Library Directories property of the Linker options.

C:\Program Files\OpenSceneGraph\lib

Finally, tell the linker which OSG libraries to link with. Add the library file names as
Additional Dependencies in the Project Property dialog Linker options. On Microsoft
Windows, OSG builds debug and release libraries with different names. Do this with, Linker -> Input -> Additional Depedancies.

-For a release build, using the osgViewer, osgDB, osgUtil, and osg libraries, add the following library
file names.

osgViewer.lib osgDB.lib osgUtil.lib osg.lib

-For a debug build, insert ‘d’ before the file extension.

osgViewerd.lib osgDBd.lib osgUtild.lib osgd.lib

These libraries are an example, and the actual libraries your application links with
depend on what OSG functionality your applications use. You might need to link with
other libraries, such as the osgText, osgShadow, and osgGA libraries.
