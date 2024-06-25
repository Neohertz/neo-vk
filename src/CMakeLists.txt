file (GLOB SRCS CONFIGURE_DEPENDS GLOB
	*.cpp
	*/*.cpp
	*/*/*.cpp
	*/*/*/*.cpp
)

add_library(engine ${SRCS})
target_include_directories(engine PUBLIC ${SRCS})