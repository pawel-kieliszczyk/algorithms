compiler = ARGUMENTS.get('compiler', 'clang++')
enable_gcov = ARGUMENTS.get('enable_gcov', False)


env = Environment(CXX = compiler)
env.Append(CXXFLAGS = ["-Wall", "-Werror", "-pthread"])

if enable_gcov:
	env.Append(CXXFLAGS = ["-fprofile-arcs", "-ftest-coverage"])
	env.Append(LINKFLAGS = "-fprofile-arcs")


env.Append(CPPPATH = ["libraries/googletest/gtest-1.7.0"])
env.Append(CPPPATH = ["libraries/googletest/gtest-1.7.0/include"])


VariantDir('bin/libraries/googletest/src', 'libraries/googletest/gtest-1.7.0/src', duplicate=0)


source_files = ["bin/libraries/googletest/src/gtest-all.cc"]

env.StaticLibrary('bin/libraries/gtest', source_files)



env.Append(CPPPATH = ["source"])

env.Append(LIBPATH = ["bin/libraries"])


#VariantDir('bin/source', 'source', duplicate=0)
VariantDir('bin/tests', 'tests', duplicate=0)


env.Append(LIBS = ["gtest", "pthread"])


source_files = ["bin/tests/main.cpp"]

source_files += ["bin/tests/depth_first_search_tester.cpp"]
source_files += ["bin/tests/graph_tester.cpp"]
source_files += ["bin/tests/queue_tester.cpp"]
source_files += ["bin/tests/stack_tester.cpp"]
source_files += ["bin/tests/vector_tester.cpp"]


env.Program('run_tests', source_files)
