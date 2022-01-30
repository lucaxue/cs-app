# Docker Scripts

Utility script to quickly start off your docker environment.

## Usage

* Builds image, and spins container with the source code bind mounted in the container, ready for development.

    ```bash
    docker/scripts/up [lab name | e.g datalab]
    ```

* Stops and removes the container, and the image.
    ```bash
    docker/scripts/down [lab name | e.g datalab]
    ```
