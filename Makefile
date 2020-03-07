#do make -s report to suppress extra messages
make report :input.txt
	g++ report.cpp -o report	
	./report
huffman : input.txt
	@g++ huffman.cpp -o huffman
	./huffman
Shanon : input.txt
	@g++ Shanon.cpp -o Shanon
	./Shanon
decode :
	g++ decode.cpp -o decode
	./decode
clean:
	rm -rf decoded.txt encoded.txt mapping.txt decode Shanon huffman report