file(GLOB_RECURSE src ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

add_executable(helloworld_app)

target_sources(helloworld_app PRIVATE ${src})

target_include_directories(
  helloworld_app
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(
  helloworld_app
  
  PUBLIC dl
  
  PRIVATE aimrt::runtime::core
          helloworld::helloworld_module)

