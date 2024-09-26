#pragma once

#include "aimrt_module_cpp_interface/module_base.h"

class HelloWorldModule : public aimrt::ModuleBase {
public:
  HelloWorldModule() = default;
  ~HelloWorldModule() override = default;

  aimrt::ModuleInfo Info() const override {
    return aimrt::ModuleInfo{.name = "HelloWorldModule"};
  }

  bool Initialize(aimrt::CoreRef core) override;
  bool Start() override;
  void Shutdown() override;

private:
  aimrt::CoreRef core_;
};

