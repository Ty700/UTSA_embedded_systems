clean:
	@rm -rf ./bin/* 
	@rm -rf ./build/*

prepare:
	@cd build && cmake .. && cmake --build .
	@cd bin && ./Executable

verbose:
	@cd build && cmake .. -DDEBUG=ON && cmake --build .
	@cd bin && ./Executable

test:
	@cd build && cmake .. -DCOMPILE_TEST=ON -DDEBUG=ON && cmake --build .
	@cd bin && ./test 
