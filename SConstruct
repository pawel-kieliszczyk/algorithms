compiler = ARGUMENTS.get('compiler', 'clang++')
enable_gcov = ARGUMENTS.get('enable_gcov', False)


env = Environment(CXX = compiler)
env.Append(CXXFLAGS = ["-std=c++0x", "-Wall", "-Werror", "-pthread"])

if enable_gcov:
	env.Append(CXXFLAGS = ["-fprofile-arcs", "-ftest-coverage"])
	env.Append(LINKFLAGS = "-fprofile-arcs")


# BUILD GOOGLETEST
env.Append(CPPPATH = ["libraries/googletest/gtest-1.7.0"])
env.Append(CPPPATH = ["libraries/googletest/gtest-1.7.0/include"])

VariantDir('bin/libraries/googletest/src', 'libraries/googletest/gtest-1.7.0/src', duplicate=0)

source_files = ["bin/libraries/googletest/src/gtest-all.cc"]

env.StaticLibrary('bin/libraries/gtest', source_files)


# BUILD GOOGLEMOCK
env.Append(CPPPATH = ["libraries/googlemock/gmock-1.7.0"])
env.Append(CPPPATH = ["libraries/googlemock/gmock-1.7.0/include"])

VariantDir('bin/libraries/googlemock/src', 'libraries/googlemock/gmock-1.7.0/src', duplicate=0)

source_files = ["bin/libraries/googlemock/src/gmock-all.cc"]

env.StaticLibrary('bin/libraries/gmock', source_files)


# BUILD TESTS
env.Append(CPPPATH = ["source"])
env.Append(LIBPATH = ["bin/libraries"])
env.Append(LIBS = ["gtest", "gmock", "pthread"])

VariantDir('bin/tests', 'tests', duplicate=0)

source_files = ["bin/tests/main.cpp"]

source_files += ["bin/tests/depth_first_search_tester.cpp"]
source_files += ["bin/tests/graph_tester.cpp"]
source_files += ["bin/tests/queue_tester.cpp"]
source_files += ["bin/tests/stack_tester.cpp"]
source_files += ["bin/tests/vector_tester.cpp"]


env.Program('run_tests', source_files)
