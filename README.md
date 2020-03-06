# C URL Shortener

![C/C++ CI](https://github.com/RafaelC457ro/c_url_shortener/workflows/C/C++%20CI/badge.svg)

Just a command line url shorter.

## Install

```sh
sudo apt install build-essential cmake libcmocka-dev
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
make
ctest -V
```

## Usage

```sh
./bin/shortener

SET www.url.com

xjsikxzns

GET xjsikxzns

www.url.com

```

type `exit` to exit.

## License

[MIT License](LICENSE.md) © [Rafael Castro](https://twitter.com/rafaelc457ro)
