cmake_minimum_required(VERSION 3.19)
project(Library_system LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Library_system
    WIN32 MACOSX_BUNDLE
    main.cpp
    Library.cpp
    Library.h
    Library.ui


    Student.h
    Student.cpp
    Dialog.h Dialog.cpp Dialog.ui
)

target_link_libraries(Library_system
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Library_system
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Library_system
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
