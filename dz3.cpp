
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        sleep(2);
        std::cout << "Child process attempting to kill parent..." << std::endl;
        if (kill(getppid(), SIGKILL) == -1) {
            perror("Failed to kill parent process");
        } else {
            std::cout << "Parent process killed." << std::endl;
        }
        exit(0);
    } else {
        std::cout << "Parent process waiting..." << std::endl;
        wait(NULL);
        std::cout << "Parent process continues or was terminated." << std::endl;
    }

    return 0;
}
