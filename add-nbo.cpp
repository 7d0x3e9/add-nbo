#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h> // for ntohl

uint32_t read_network_order_integer(const char* file_path) {
    FILE *file = fopen(file_path, "rb"); // 파일 오픈
    if (file == NULL) {
        perror("file open failed"); // 파일 오픈 실패 시
        exit(1);
    }

    uint32_t num; // 16진수 계산
    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        perror("Failed to read data from file");
        exit(1);
    }

    fclose(file);

    return ntohl(num); // N to H, Network byte order 를 host by order로 변환
}

int main() {
    const char* file_path1 = "a.bin"; // 계산할 파일 설정
    const char* file_path2 = "b.bin"; // 계산할 파일 설정

    uint32_t number1 = read_network_order_integer(file_path1); // 파일 내용 불러오기
    uint32_t number2 = read_network_order_integer(file_path2); // 파일 내용 불러오기

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", number1, number1, number2, number2, number1 + number2, number1 + number2); // 최종 결과 출력

    return 0;
}

