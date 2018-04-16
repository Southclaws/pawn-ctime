# -
# Setup test requirements
# -

test-setup:
	cd test && sampctl server ensure
	sampctl package ensure

# -
# Run Tests
# -

test-windows:
	-cp test/plugins/Debug/ctime.dll test/plugins/ctime.dll
	sampctl package build
	cd test && sampctl server run

test-linux:
	sampctl package build
	cd test && sampctl server run --container

# -
# Build (Linux)
# -

build-linux:
	rm -rf build
	docker build -t southclaws/ctime-build .
	docker run -v $(shell pwd)/test/plugins:/root/test/plugins southclaws/ctime-build

build-inside:
	cd build && cmake .. && make
