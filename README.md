# add-nbo

## 1.makefile 작성
make 명령어를 위한 makefile 작성


## 2.a.bin, c.bin 작성
10진수 1999를 4바이트 16진수로 변환한 후, a.bin에 씌운다.
10진수 0211을 4바이트 16진수로 변환한 후, b.bin에 씌운다.


## 3.add-nbo.cpp 작성
16진수가 각각 담겨있는 a.bin 파일과 b.bin 파일을 합 계산할 add-nbo.cpp를 작성한다.


## 4.make
make 명령어로 컴파일한다.


## 5. a.bin + b.bin 실행
./add-nbo a.bin b.bin을 통해 덧셈을 수행한다.


## 6. 결과 확인
1991(0x7c7) + 211(0xd3) = 2202(0x89a)
![image](https://github.com/7d0x3e9/add-nbo/assets/121916836/653d1734-d026-48dd-aa39-a49d3aee43dc)


## 7. git push
