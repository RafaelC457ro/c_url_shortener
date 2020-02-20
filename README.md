# C URL Shortener

Just a command line url shorter.

## install

```sh
sudo apt install build-essential cmake cmocka
```

## build

```sh
mkdir build
cd build
cmake ..
make
```

## test

```sh
cd build\
make
ctest -V
```

# usage

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
