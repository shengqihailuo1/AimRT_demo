include(FetchContent)

FetchContent_Declare(
  aimrt
  GIT_REPOSITORY https://github.com/AimRT/aimrt.git
  GIT_TAG v0.8.1)

FetchContent_GetProperties(aimrt)

if(NOT aimrt_POPULATED)
  FetchContent_MakeAvailable(aimrt)
endif()
