#include <csignal>
#include <iostream>

#include "core/aimrt_core.h"
#include "helloworld_module/helloworld_module.h"

using namespace aimrt::runtime::core;

AimRTCore *global_core_ptr_ = nullptr;

void SignalHandler(int sig) {
  if (global_core_ptr_ && (sig == SIGINT || sig == SIGTERM)) {
    global_core_ptr_->Shutdown();
    return;
  }
  raise(sig);
};

int32_t main(int32_t argc, char **argv) {
  signal(SIGINT, SignalHandler);
  signal(SIGTERM, SignalHandler);

  std::cout << "AimRT start." << std::endl;

  try {
    AimRTCore core;
    global_core_ptr_ = &core;

    // register module
    HelloWorldModule helloworld_module;
    core.GetModuleManager().RegisterModule(helloworld_module.NativeHandle());

    AimRTCore::Options options;
    options.cfg_file_path = argv[1];
    core.Initialize(options);

    core.Start();

    core.Shutdown();

    global_core_ptr_ = nullptr;
  } catch (const std::exception &e) {
    std::cout << "AimRT run with exception and exit. " << e.what() << std::endl;
    return -1;
  }

  std::cout << "AimRT exit." << std::endl;
  return 0;
}
