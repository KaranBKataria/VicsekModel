add_executable(${PROJECT_NAME} main.cpp
	simulation.cpp
	vicsekStep.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/include
)