cmake_minimum_required(VERSION 2.8)

project("bicron" CXX)

set(GNUCXX_MINIMUM_VERSION "4.9")
set(CLANG_MINIMUM_VERSION "3.5")

set(CMAKE_CXX_FLAGS "-std=c++14")

set (SOURCES
	src/bicron/bicron.cc
	src/bicron/config.cc
	src/bicron/json_config_builder.cc
	src/bicron/rule.cc
	src/bicron/time_point.cc
)

### Test #######################################################################

set (SOURCES_TEST
	tests/bicron_test.cc
	tests/dummy_test.cc
	tests/rule_test.cc
	tests/time_point_test.cc
	tests/main.cc
)

add_executable(bicron-test
	${SOURCES}
	${SOURCES_TEST}
)

target_include_directories(bicron-test
	PUBLIC src/bicron
	PUBLIC third_party/
	PUBLIC tests/
)
