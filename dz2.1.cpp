
#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <signal_number> <PID>" << std::endl;
        return 1;
    }

    int signal = std::atoi(argv[1]);
    pid_t pid = std::atoi(argv[2]);

    if (kill(pid, signal) == -1) {
        perror("Error sending signal");
        return 1;
    }

    std::cout << "Signal " << signal << " sent to process " << pid << std::endl;
    return 0;
}
