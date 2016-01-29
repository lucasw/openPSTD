#------------------------------------
# Kernel library
SET(SOURCE_FILES_LIB kernel/PSTDKernel.cpp
        kernel/core/kernel_functions.cpp kernel/core/Domain.cpp kernel/core/Speaker.cpp kernel/core/Scene.cpp
        kernel/core/Receiver.cpp kernel/core/Boundary.cpp kernel/Solver.cpp kernel/core/Geometry.cpp
        kernel/core/wave_numbers.cpp kernel/KernelInterface.cpp kernel/MockKernel.cpp)
add_library(OpenPSTD SHARED ${SOURCE_FILES_LIB})

target_link_libraries(OpenPSTD ${Boost_LIBRARIES})
target_link_libraries(OpenPSTD ${Qt5_LIBRARIES})
target_link_libraries(OpenPSTD ${FFTWF_LIBRARY})