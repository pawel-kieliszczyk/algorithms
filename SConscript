Import('env')
local_env = env.Clone()


local_env.AppendUnique(CPPPATH = ['libraries/googletest/gtest-1.7.0/include'])
local_env.AppendUnique(CPPPATH = ['libraries/googlemock/gmock-1.7.0/include'])
local_env.AppendUnique(CPPPATH = ['../source'])

local_env.AppendUnique(LIBPATH = ['libraries/googletest', 'libraries/googlemock'])

local_env.AppendUnique(LIBS = ['gtest', 'gmock', 'pthread'])


enable_gcov = ARGUMENTS.get('enable_gcov', False)
if enable_gcov:
	local_env.AppendUnique(CXXFLAGS = ['-fprofile-arcs', '-ftest-coverage'])
	local_env.AppendUnique(LINKFLAGS = '-fprofile-arcs')


source_files = ['tests/main.cpp']

source_files += ['tests/breadth_first_search_tester.cpp']
source_files += ['tests/cyclic_array_tester.cpp']
source_files += ['tests/depth_first_search_tester.cpp']
source_files += ['tests/graph_tester.cpp']
source_files += ['tests/greatest_common_divisor_tester.cpp']
source_files += ['tests/heap_tester.cpp']
source_files += ['tests/least_common_multiple_tester.cpp']
source_files += ['tests/minimum_spanning_tree_prim_tester.cpp']
source_files += ['tests/queue_tester.cpp']
source_files += ['tests/shortest_paths_dijkstra_tester.cpp']
source_files += ['tests/stack_tester.cpp']
source_files += ['tests/vector_tester.cpp']
source_files += ['tests/weighted_graph_tester.cpp']


target = 'test'

program = local_env.Program(target, source_files)
Default(program)
env.Alias(target, '.')


local_env.Depends(program, env.Alias('gtest'))
local_env.Depends(program, env.Alias('gmock'))
