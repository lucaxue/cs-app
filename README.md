# CMU 15-213: Intro to Computer Systems

This repository is used to track my progress through the [CMU 15-213: Intro to Computer Systems, Fall 2017](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f17/www/schedule.html) course. The course goes hand in hand with the famous "Computer Systems A Programmer's Perspective" book, otherwise known as CS:APP.

## Labs

The lab materials are from the [student website](http://csapp.cs.cmu.edu/3e/labs.html).

- [x] L0: c programming lab
- [ ] L1: data lab
- [ ] L2: bomb lab
- [ ] L3: attack lab
- [ ] L4: cache lab
- [ ] L5: shell lab
- [ ] L6: malloc lab
- [ ] L7: proxy lab

## Developing with Docker

In order to avoid environment issues, docker images (credit to https://github.com/Yansongsongsong/CSAPP-Experiments), as well as
some utility bash scripts have been provided to quickly start off your docker environment.

### Usage

* Builds image and spins container with the source code bind mounted in the container, ready for development.

    ```bash
    docker/scripts/up [lab name | e.g datalab]
    ```

* Stops and removes the container and the image.
    ```bash
    docker/scripts/down [lab name | e.g datalab]
    ```
