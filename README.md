# C URL Shortener

![C/C++ CI](https://github.com/RafaelC457ro/c_url_shortener/workflows/C/C++%20CI/badge.svg?branch=master)

Just a command line trivial url shortener. I not implemented a real hash table yet, so probably it will not work with a lot of urls.

# Goals

- [x] Shorten urls
- [ ] implement a real hash table

## Install

## Linux

```sh
sudo apt install build-essential cmake
```

## Mac

```sh
xcode-select --install
brew install cmake
```

## Build

```sh
mkdir build
cd build
cmake ..
make
```

## Test

```sh
cd build\
make test
```

## Usage

```sh
./bin/shortener

PUT www.url.com

xjsikxzns

GET xjsikxzns

www.url.com

```

type `quit` to exit.

## License

[MIT License](LICENSE.md) © [Rafael Castro](https://twitter.com/rafaelc457ro)
