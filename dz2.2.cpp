
#include <iostream>
#include <csignal>
#include <unistd.h>

int sigusr2_count = 0;

void handle_sigint(int) {
    std::cout << "\nReceived SIGINT. Total SIGUSR2 signals received: " << sigusr2_count << std::endl;
    exit(0);
}

void handle_sigusr1(int) {
    std::cout << "Ignoring SIGUSR1" << std::endl;
}

void handle_sigusr2(int) {
    sigusr2_count++;
}

int main() {
    signal(SIGINT, handle_sigint);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    while (true) {
        std::cout << "I am still alive!!" << std::endl;
        sleep(5);
    }

    return 0;
}
