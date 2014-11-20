env = Environment(CXX = 'clang++')
env.Append(CXXFLAGS = ["-Wall", "-Werror", "-pthread"])


env.Append(CPPPATH = ["libraries/googletest/gtest-1.7.0"])
env.Append(CPPPATH = ["libraries/googletest/gtest-1.7.0/include"])


VariantDir('bin/libraries/googletest/src', 'libraries/googletest/gtest-1.7.0/src', duplicate=0)


source_files = ["bin/libraries/googletest/src/gtest-all.cc"]

env.StaticLibrary('bin/libraries/gtest', source_files)



env.Append(LIBPATH = ["bin/libraries"])


#VariantDir('bin/source', 'source', duplicate=0)
VariantDir('bin/tests', 'tests', duplicate=0)


env.Append(LIBS = ["gtest"])


source_files += []

source_files += ["bin/tests/main.cpp"]


env.Program('run_tests', source_files)
