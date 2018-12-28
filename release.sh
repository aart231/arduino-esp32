#!/bin/bash
set -e
rm -r release || true
rm arduino-husarnet-esp32-v1.zip || true
mkdir release
names="$(git ls-files) $(find ./libraries/BLE/*)"
for name in $names; do
    mkdir -p release/$(dirname $name)
    if [ -d $name ]; then continue; fi
    cp $name release/$name
done
zip -r arduino-husarnet-esp32-v1.zip release
