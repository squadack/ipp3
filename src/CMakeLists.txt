set (SOURCES
	Ipp3Window.cpp
	Test.cpp
	GraphicsView.cpp
	main.cpp
)

add_executable (Ipp3 ${SOURCES})
target_link_libraries (Ipp3 ${QT_LIBRARIES})
