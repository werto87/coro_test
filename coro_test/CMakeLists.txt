##
## Copyright (c) 2024 Waldemar Schneider (w-schneider1987 at web dot de)
##
## Distributed under the Boost Software License, Version 1.0.
## (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


add_library(coro_test hello.cxx)


add_library(myproject::coro_test ALIAS coro_test)


find_package(Boost)
find_package(spdlog)
target_link_libraries(coro_test PUBLIC
        Boost::headers
        spdlog::spdlog
        myproject_options
        myproject_warnings
)

target_include_directories(coro_test
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        )

target_compile_features(coro_test PUBLIC cxx_std_20)

set_target_properties(
        coro_test
        PROPERTIES VERSION ${PROJECT_VERSION}
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN YES)

install(FILES
        hello.hxx
        DESTINATION include/coro_test
        )
install(TARGETS coro_test DESTINATION lib)
