#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h> // for ntohl

uint32_t read_network_order_integer(const char* file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    uint32_t num;
    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        perror("Failed to read data from file");
        exit(1);
    }

    fclose(file);

    return ntohl(num); // convert from network byte order to host byte order
}

int main() {
    const char* file_path1 = "a.bin"; // replace with your actual file paths
    const char* file_path2 = "b.bin";

    uint32_t number1 = read_network_order_integer(file_path1);
    uint32_t number2 = read_network_order_integer(file_path2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", number1, number1, number2, number2, number1 + number2, number1 + number2);

    return 0;
}

