include_directories("C:\\TFO\\CIVA_DK\\CIVA_DK_64_dev_003\\outilsExternes\\Boost\\boost_1_64_0a")
include_directories("C:\\TFO\\CIVA_DK\\CIVA_DK_64_dev_003\\outilsExternes\\tbb_2018_1\\include")
link_directories("C:\\TFO\\CIVA_DK\\CIVA_DK_64_dev_003\\outilsExternes\\tbb_2018_1\\lib\\intel64")

add_library (Test test.cpp test.h)
add_library (IO io.cpp io.h)

add_executable (Day01 day01.cpp)
target_link_libraries (Day01 IO Test)

add_executable (Day02 day02.cpp)
target_link_libraries (Day02 IO Test)

add_executable (Day25 day25.cpp)
target_link_libraries (Day25 IO Test)