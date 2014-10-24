BUILD notes
============


If you intend to use GYP in any fashion, you will want to set the following:
export GYP_DEFINES="disable_nacl=1 use_system_libjpeg=1 use_system_libevent use_system_openssl use_system_zlib use_system_expat use_system_libxml"
export GYP_GENERATORS=ninja

However, my current goal is to skip gyp, and try to build gn.
I already have a ninja (v1.4) binary, which will be archived in the binaries dir here.
I also have a hand-tweaked build.ninja file, for tools/gn

So, current stage of development, is mostly just

PATH=/usr/gnu/bin:$PATH
cd $TOP/tools/gn
ninja
