#include <torch/torch.h>
#include <torch/script.h>
#include <torchvision/vision.h>
#include <iostream>

int main()
{
  std::cout << "Loading Neural Network..." << std::endl;
  torch::jit::script::Module module;
  module = torch::jit::load("../innovation/vision-Detectron2/data/models/model_traced.ts");

  std::cout << "Generating random input..." << std::endl;
  std::vector<torch::jit::IValue> inputs;
  inputs.push_back(torch::randint(1, 254, {1080, 1920, 3}));

  std::cout << "Feed forward thru the network..." << std::endl;
  auto output = module.forward(inputs);

  std::cout << "Splitting data..." << std::endl;
  torch::Tensor bboxes = output.toTuple()->elements()[0].toTensor();
  torch::Tensor masks = output.toTuple()->elements()[1].toTensor();

  std::cout << "Output:" << std::endl;
  std::cout << bboxes << std::endl;
  std::cout << masks << std::endl;
}
