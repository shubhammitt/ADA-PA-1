
make report :input.txt
	
huffman : input.txt
	g++ huffman.cpp -o huffman
	./huffman
Shanon : input.txt
	g++ Shanon.cpp -o Shanon
	./Shanon
decode :
	g++ decode.cpp -o decode
	./decode
clean:
	rm -rf decoded.txt encoded.txt mapping.txt decode Shanon huffman