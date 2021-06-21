# PyTorch C++ with torchvision C++

Follow the steps outlined here https://pytorch.org/tutorials/advanced/cpp_frontend.html

Make sure Libtorch is version 1.8 and Torchvision is version 0.9.

## Install libtorch

```bash
cd ~
wget https://download.pytorch.org/libtorch/cpu/libtorch-win-shared-with-deps-1.8.1%2Bcpu.zip
unzip libtorch-win-shared-with-deps-1.8.1%2Bcpu.zip
```

## Install TorchVision

```bash
cd ~
git clone https://github.com/pytorch/vision.git
git checkout release/0.9

mkdir build
cd build
sudo cmake .. -DCMAKE_PREFIX_PATH=~/libtorch

// Need to update cmake?
// Follow: https://askubuntu.com/a/829311

make
sudo make install
```

## Build this repository

```bash
cmake -DCMAKE_PREFIX_PATH=~/libtorch
cmake -DCMAKE_PREFIX_PATH=~/libtorch  // Run this command twice
cmake --build . --config Release
./ImportNetwork
```

References:
* https://pytorch.org/blog/pytorch-1-dot-5-released-with-new-and-updated-apis/
* Justin Johnson. Learning PyTorch with Examples.
* Using the PyTorch C++ Frontend
* https://github.com/venkatacrc/PyTorchCppFrontEnd
* https://medium.com/pytorch/a-taste-of-pytorch-c-frontend-api-8ec5209823ca
