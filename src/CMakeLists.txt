add_executable(${PROJECT_NAME}Float mainFloat.cpp
		vicsekStep.cpp
)

add_executable(${PROJECT_NAME}Double mainDouble.cpp
		vicsekStep.cpp
)

target_include_directories(${PROJECT_NAME}Float PUBLIC
		${CMAKE_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}Double PUBLIC
	${CMAKE_SOURCE_DIR}/include
)