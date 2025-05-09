rm -rf build && mkdir build && cd build

cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=./

cmake --build .

cp raytracer ../raytracer

cd ..
