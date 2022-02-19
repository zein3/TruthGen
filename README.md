# TruthGen - A truth table generator written in C++


## Installation
On Linux:
```bash
git clone https://github.com/zein3/TruthGen.git && cd TruthGen
mkdir build && cd build
cmake ../
make
```
And then:
```
sudo make install
```


## Usage
You can generate truth table from expression with:
```bash
$ truthgen {expression}
```
Example:
```bash
$ truthgen !(A ^ B)
A   B   !(A ^ B)
T   T   F
T   F   T
F   T   T
F   F   T
```


### Note on variables
A variable must be an upper or lower case letter and cannot be uppercase T or uppercase F.
